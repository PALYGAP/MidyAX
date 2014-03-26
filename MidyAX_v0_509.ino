////////////////////////////////////////////////////////////////////////////////////////////
// PROGRAM:     PROTOTYPE of MidyAX - BCR2000 to AXE-FX MIDI orchestrator
// HARDWARE:    ARDUINO MEGA, 4 MIDI ports with a MIDI-IN and MIDI-OUT for each port.
// CREATOR:     Eric FEUILLEAUBOIS
// COMPANY:     LeafONICs
// COPYRIGHTS:  LGNU
////////////////////////////////////////////////////////////////////////////////////////////

///////////////
//  DEFINES  //
///////////////
//#define DEBUG
//#define DEBUG2
//#define DEBUG3
//#define DEBUG4
//#define DEBUG5
//#define DEBUG6

//#define AXE_FX_II
//#define POD_XT_LIVE
//#define DEBUG_TEST  // Debug for MidyAX test function 
#define ELECTRONIE_PROTO
#define LCD_PRESENT

//////////////  INCLUDES ///////////////////////
#include "AXE_FX.h"
#include "BCR2000.h"
#include "MidyAX.h"
#include "SPI_FLASH_MEMORY.h"
//MIDI
#include <MIDI_AXE.h>
#include <MIDI_BCR2000.h>
#include <MIDI_OTHER.h>
#include <MIDI_FOOTPEDAL.h>
#include <avr/pgmspace.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <MidyAX_Structs.h>
#include <MidyAX_Structs_dyn.h>
#include <MidyAX_Flash_Addresses.h>
#include <MidyAX_Writing_FLASH.h>
#include <MemoryFree.h>                  // Free Memory Size calulation
#include <SoftwareSerial.h>
// Integration of the SPI FLASH MEMORY //
#include <SPI.h>


#ifdef ELECTRONIE_PROTO
  #include <SPI_FLASH_AL25L80_ELECTRONIE.h>
#else
  #include <SPI_FLASH_AL25L80.h>
#endif

//////////////////////////////////////////////////////////////
// Communication with the uVGA done with SoftwareSerial lib //
#ifdef ELECTRONIE_PROTO
  #define SoftwareSerial_RXPIN 12 // Changed from 11 
  #define SoftwareSerial_TXPIN 13 // Changed from 12
  #define UVGA_RESETPIN 11 // Changed from 8
  #define PIN0_ROUTING_UART0 29
  #define PIN1_ROUTING_UART0 30
#else
  #define SoftwareSerial_RXPIN 11
  #define SoftwareSerial_TXPIN 12
  #define UVGA_RESETPIN 8
#endif
SoftwareSerial sSerial(SoftwareSerial_RXPIN, SoftwareSerial_TXPIN);

// SPI FLASH MEMORY 
unsigned long startAddresseOfParameterAddresses;
unsigned long startAddresseOfModalListAddresses;
byte sizeOf_MEM_EffectType = sizeof( MEM_EffectType );
byte sizeOf_MEM_EffectBlock = sizeof( MEM_EffectBlock);
byte sizeOf_MEM_Parameter = sizeof( MEM_Parameter );


// Initializes the LCD display
//#ifdef ELECTRONIE_PROTO
LiquidCrystal lcd(27, /* RS */
                  23, /* E */
                  22, /* DB4 */
                  24, /* DB5 */
                  26, /* DB6 */
                  28); /* DB7 */
//#else
//  LiquidCrystal lcd(32, 30, 28, 26, 24, 22);
//#endif

////////////////////
//  MIDI SETUP    //
////////////////////
#define ArrayContainsBoundaries false

//////////////////////
//  BCR2000 SETUP  // 
//////////////////////
short CS_Preset_Number, CS_Effect_Type, CS_Current_Effect_Number_In_CP, CS_Effect_NumSel_State;
boolean CS_Effect_OBState, CS_Effect_XYState;
byte CS_Effect_ID;
boolean CS_Loaded = false;
int CS_Number_Active_Encoder = 0, CS_BCR2000_ACTIVE_BUTTON = 0;
boolean PB16_state;
//byte *BCR2000_SysEx;
byte BCR2000_SysEx[200];
int SYSEX_counter;

boolean typeDelay_millisElapsed = false, typeDelay_typeEvent = false; 
byte typeDelay_CC_channel, typeDelay_CC_number,typeDelay_CC_value;
int typeDelay_lastType;
unsigned long typeDelay_lastTime;




////////////////////
//  AXE-FX SETUP  // 
////////////////////
#define CurentPreset_Max_NumberOf_EffectBlocks_DEFINE 24

byte Axe_Fx_Type, Axe_Fx_Version, Axe_Fx_Sub_Version;
int CP_Number_Effects;
byte CP_Effect_ID [ CurentPreset_Max_NumberOf_EffectBlocks_DEFINE ];  //Current Preset list of all the Effect Blocks ID of the preset
byte CP_Effect_CC [ CurentPreset_Max_NumberOf_EffectBlocks_DEFINE ];
boolean CP_Effect_OBState [ CurentPreset_Max_NumberOf_EffectBlocks_DEFINE ];
boolean CP_Effect_XYState [ CurentPreset_Max_NumberOf_EffectBlocks_DEFINE ];
byte CP_Effect_Type [ CurentPreset_Max_NumberOf_EffectBlocks_DEFINE ];
byte CP_Effect_BCR_Preset [ CurentPreset_Max_NumberOf_EffectBlocks_DEFINE ];
boolean CP_Initial_Param_Value_received[ BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER ];

struct DYN_EffectType CurrentControlPage_EffectType;



#define SIZE_OF_SISEX_FOR_PARAM 12 
byte sysex_mes[SIZE_OF_SISEX_FOR_PARAM+2]; // +1 for the CheckSum byte in AXE-FX 2 +1 for extra parameter byte


// LED showing value of changed param
#ifdef ELECTRONIE_PROTO
  #define parValueLedPin 4 //Changed from 6
  #define sysExLedPin 5 //Changed from 7
#else
  #define parValueLedPin 6 //Changed from 11
  #define sysExLedPin 7 //Changed from 12
#endif





//////////////////////
//  FOOTPEDAL SETUP  // 
//////////////////////
//#define FOOTPEDAL_CHANNEL 12
//#define BCR2000_MIDI_CHANNEL 1
//#define AXE_FX_CHANNEL 12
byte FOOTPEDAL_CHANNEL = 12;
byte BCR2000_MIDI_CHANNEL = 1;
byte AXE_FX_CHANNEL = 12;
byte OTHER_MIDI_CHANNEL = 1;


////////////////////
//  VAR INIT      //
////////////////////
byte LB, MB, HB;
float ratio;
int CountReceivedParam = 0;




///////////////////////////////////////////////////////
// TEST of the MIDI ports during the Test program --> to be improved !!!
///////////////////////////////////////////////////////
byte FOOTPEDAL_Received_CC_Value = 0;
byte AXEFX_Received_CC_Value = 0;
byte BCR2000_Received_CC_Value = 0;
byte OTHER_Received_CC_Value = 0;
#define MIDI_TEST_CC_SENT 50


//////////////////////////
////  TEST FLASH WRITING
//////////////////////////
extern unsigned long WRITING_currentMemAddresse;
extern byte MSB, LSB ;
extern byte byteBuffer[256];
extern int bytesFiled;
extern int numOfWrittenBuffer;

#ifdef ELECTRONIE_PROTO
    #define CHIP_SELECT 53
    #define HOLD 49
    #define WRITE_PROTECT 48
#else
    #define CHIP_SELECT 13
#endif






/////////////////////////////////////////////////
//////////      ARDUINO SETUP FONCTION       ////
/////////////////////////////////////////////////
void setup()
{
  int nberror;  

  
  //////////////////////////
  //  ARDUINO PINS SETUP  //
  //////////////////////////
  // Initializes the value of the LED showing the param value and sysex reception
  pinMode(parValueLedPin, OUTPUT);
  pinMode(sysExLedPin, OUTPUT);
  // Initilizes E_LCD of the LCD
  pinMode(25, OUTPUT);
  digitalWrite(25, LOW);

  // Flash the two control LED for 0.1 Second
  digitalWrite(parValueLedPin, HIGH);
  digitalWrite(sysExLedPin, HIGH);
  delay(100);
  digitalWrite(parValueLedPin, LOW);
  digitalWrite(sysExLedPin, LOW);
  delay(100);

  // Starts the LCD if there should be one 
  #if ( !defined(ELECTRONIE_PROTO)  || defined(LCD_PRESENT) )
    // Initializes the LCD display --- LiquidCrystal lcd(32, 30, 28, 26, 24, 22);
    lcd.begin(16, 2); // set up the LCD's number of columns and rows: 
    lcd.setCursor(0, 0);
    lcd.print(F("MidyAX: STARTING"));
  #endif


  // IF in DEBUG mode SERIAL UART-0 BEGINS
  #if (defined(DEBUG) || defined(DEBUG2) || defined(DEBUG3) || defined(DEBUG4) || defined(DEBUG5) || defined(DEBUG6) || defined(DEBUG_TEST) )
    Serial.begin(115200);
    Serial.println(); Serial.println();  
    Serial.print(F("RAM: freeMemory ")); Serial.println(freeMemory(), DEC);
    Serial.print(F("Started SETUP"));Serial.println("");
    Serial.flush(); 
  #endif


  // INITIALIZE the uVGA-II or III card
  pinMode(UVGA_RESETPIN, OUTPUT);
  digitalWrite(UVGA_RESETPIN, HIGH);
  delay(10);                  
  digitalWrite(UVGA_RESETPIN, LOW);
  
  // Way for the uVGA to be initialized --> Then it can receive display messages
  delay(4000);


  // Start the SoftwareSerial communication on pins
  sSerial.begin(115200);
//  send_uvga_A( 0); //Display init screen
//  send_uvga_2( "start" );
//  send_uvga_1( );
//  send_uvga_Z(4, 127, 1);

 
  //////////////////////////
  //  START MIDI 
  //////////////////////////
  //MIDI set-up
  MIDI_AXE.begin( AXE_FX_CHANNEL );
  MIDI_BCR2000.begin( BCR2000_MIDI_CHANNEL );
  MIDI_FOOTPEDAL.begin( FOOTPEDAL_CHANNEL );
  //MEMORY SPACE TESTs
  MIDI_OTHER.begin(OTHER_MIDI_CHANNEL);
  
  // Set-up callback functions
  MIDI_AXE.setHandleSystemExclusive(ManageSystemExclusiveMessage);
  MIDI_AXE.setHandleControlChange(AXE_ManageCC);
  MIDI_BCR2000.setHandleControlChange(BCR2000_ManageCC);
  MIDI_FOOTPEDAL.setHandleControlChange(FOOTPEDAL_ManageCC);
  MIDI_FOOTPEDAL.setHandleProgramChange(FOOTPEDAL_ManagePC);
  //MEMORY SPACE TESTs
  MIDI_OTHER.setHandleControlChange(OTHER_ManageCC);



  ////////////////////////
  //  AXE-FX SPECIFICS  // 
  ////////////////////////

  // Default part of the AXE-FX sysex message
  sysex_mes[0]= 0x00;
  sysex_mes[1]= 0x01; // Manufacturer ID MSB - Fractal Audio Manufacturer ID Most Significant Byte
  sysex_mes[2]= 0x74; // Manufacturer ID LSB - Fractal Audio Manufacturer ID Least Significant Byte
  sysex_mes[3]= 0x03; // Model ID Byte - Specific byte assigned to the Fractal Audio product - AXE-FX II by default
  for (int i=4; i < SIZE_OF_SISEX_FOR_PARAM+2 ; i++) { sysex_mes[i] = 0x00; }
  // +1 for the CheckSum byte in AXE-FX 2


  ///////////////////////////////////////////////////
  // DETECTION OF AXE-FX TYPE (STANDARD/ULTRA/II) ///
  ///////////////////////////////////////////////////
  Axe_Fx_Type = 0xFF; 
  Axe_Fx_Version = 0x00;
  int count = 0;
  do {
    // SEND AXE-FX STANDARD/ULTRA specific version query SYSEX
    sysex_mes[3]= 0x00;  // MODEL NUMBER NOT SPECIFIED
    sysex_mes[4]= 0x08;  // ID od MIDI_GET_FIRMWARE_VERSION function
    sysex_mes[5]= 0x00;  // Version
    sysex_mes[6]= 0x00;  // sub version
    MIDI_AXE.sendSysEx( byte( 7 ), sysex_mes, false ); 
    for( int k=0 ; k < 10000 ; k++) { MIDI_AXE.read(AXE_FX_CHANNEL); }

    // SEND AXE-FX II specific version query SYSEX
    if(Axe_Fx_Type == 0xFF || Axe_Fx_Version == 0x00)
    {
      sysex_mes[3]= 0x03;  // AXE II - must be set to 3 to work
      sysex_mes[4]= 0x08;  // ID od MIDI_GET_FIRMWARE_VERSION function
      sysex_mes[5]= 0x00;  // Version
      sysex_mes[6]= 0x00;  // sub version
      sysex_mes[7]= 0x00;
      sysex_mes[8]= Calculate_CheckSum( sysex_mes, 8);  
      MIDI_AXE.sendSysEx( byte( 9 ), sysex_mes, false ); 
    }
    int count2 = 0;
    do  { MIDI_AXE.read(AXE_FX_CHANNEL); count2++; } while ( Axe_Fx_Type == 0xFF && count2 < 100 );
    count++;

  } while (Axe_Fx_Version == 0x00 && count <100);


  if( Axe_Fx_Type == 0xFF ) 
  {
    //TODO// SEND a warning message and allow for rescan of a AXE-FX device
  }



#ifdef DEBUG3
  if( Axe_Fx_Type == 0xFF ) 
  {
    Serial.println("No AXE-FX at the end of the line or very problem !!! ");
  }
  else {
      Serial.print(F("Axe_Fx_Type: "));
      Serial.println(Axe_Fx_Type, DEC);
      Serial.print(F("Axe_Fx_Version: "));
      Serial.println(Axe_Fx_Version, DEC);
      Serial.print(F("Axe_Fx_Sub_Version: "));
      Serial.println(Axe_Fx_Sub_Version, DEC);
  }
#endif


  ////////////////////////////////////////////////////////////////
  // Starts SPI bus for communication with SPI FLASH
  ////////////////////////////////////////////////////////////////
  SPI.begin ();
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  pinMode(CHIP_SELECT, OUTPUT);    // Set pin connected to SPI FLASH chip select as output  
  #ifdef ELECTRONIE_PROTO
    pinMode(HOLD, OUTPUT);           // Set pin connected to SPI HOLD chip select as output  
    pinMode(WRITE_PROTECT, OUTPUT);  // Set pin connected to SPI WRITE_PROTECT select as output  
    digitalWrite(HOLD, HIGH);  // NO HOLMD
    digitalWrite(WRITE_PROTECT, HIGH); // NO WRITE PROTECT
  #endif
  
  #ifdef DEBUG_TEST
    Serial.println(F("After SPI begin"));
    writeStatus (0);
    Serial.println(F("After writeStatus")); 
    info ();
    Serial.println(F("After info"));  
  #endif


  ////////////////////////////////////////////////////////////////
  ///// NO AXE-FX detected ==> ENTERING TEST MODE 
  ////////////////////////////////////////////////////////////////
  //if ( Axe_Fx_Version == 0x00) { test(); }      //&& Axe_Fx_Type == 0xFF )  
  
  

  /////////////////////////
  //  BCR2000 SPECIFICS  // 
  /////////////////////////
  // Must be after SPI start-up
  
  //BCR2000_Init_Device (1, 32);
  ////////////////BCR2000_Init_Device(1, 1); // Only configure preset #1 of the BCR2000. For test only
  //Serial2.end();
  //MIDI_BCR2000.begin( BCR2000_MIDI_CHANNEL );

  
  #if (defined(DEBUG) || defined(DEBUG2) || defined(DEBUG3) || defined(DEBUG4) || defined(DEBUG5) || defined(DEBUG6) || defined(DEBUG_TEST) )
    Serial.println(); Serial.println();  
    Serial.print(F("END OF SETUP"));Serial.println("");
    Serial.print(F("RAM: freeMemory ")); Serial.println(freeMemory(), DEC);
    Serial.flush(); 
  #endif


  // Display on LCD : MidyAX by LeafONICs
  #if ( !defined(ELECTRONIE_PROTO)  || defined(LCD_PRESENT) )
    // Initializes the LCD display --- LiquidCrystal lcd(32, 30, 28, 26, 24, 22);
    lcd.begin(16, 2); // set up the LCD's number of columns and rows: 
    lcd.setCursor(0, 0);
    lcd.print(F("The MidyAX"));
    lcd.setCursor(0, 1);
    lcd.print(F("by LeafONICS"));
  #endif

  ///////////////////////////////
  // GET EFFECT LIST AND STATE //
  ///////////////////////////////
  delay(4000);  //TODO// Check if necessary
  if ( Axe_Fx_Version != 0x00 )
  {
    //AXE-FX 2 specific
    sysex_mes[0]= 0x00;
    sysex_mes[1]= 0x01; // Manufacturer ID MSB - Fractal Audio Manufacturer ID Most Significant Byte
    sysex_mes[2]= 0x74; // Manufacturer ID LSB - Fractal Audio Manufacturer ID Least Significant Byte
    sysex_mes[3]= 0x03; // Model ID Byte - Specific byte assigned to the Fractal Audio product - AXE-FX II by default
    sysex_mes[4]= 0x0E;  
    sysex_mes[5] = Calculate_CheckSum( sysex_mes, 5); 
    if ( Axe_Fx_Type != 0x03 ) { MIDI_AXE.sendSysEx( byte(5), sysex_mes, false ); }
    else { MIDI_AXE.sendSysEx( byte( 6 ), sysex_mes, false ); }
  }

}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////        LOOP            ////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{

  if( typeDelay_typeEvent == true)
  {
    if(  millis() - typeDelay_lastTime  > 1000 )
    {
      if( typeDelay_lastType == CurrentControlPage_EffectType.ID)
      {
        typeDelay_millisElapsed = true;
        BCR2000_ManageCC ( typeDelay_CC_channel, typeDelay_CC_number, typeDelay_CC_value );
        typeDelay_typeEvent = false;
      }
      else {
        typeDelay_millisElapsed = false;
        typeDelay_typeEvent = false;
      }
    }
  }

  if(    !MIDI_BCR2000.read(BCR2000_MIDI_CHANNEL) )  
  {
    if(  !MIDI_AXE.read(AXE_FX_CHANNEL) )
    {
          MIDI_FOOTPEDAL.read(FOOTPEDAL_CHANNEL);
    }
  }

} // END OF LOOP function










//////////////////////////////////////////////////////////////////////////////
///////// PROCESS THE SYSEX RECEIVED FROM THE AXE_FX
//////////////////////////////////////////////////////////////////////////////
void  ManageSystemExclusiveMessage (byte *incoming_sysex, byte incoming_size)
{
  // SysEx message received
  long ReceivedValue, ReceivedValue1, div;
  float ratio, ftempo1, ftempo2, DisplayValue;
  
#ifdef DEBUG
  Serial.print(F("incoming_size   ")); Serial.print(incoming_size, HEX); 
  
      Serial.print(F("      SYSEX : "));
      for (int j=0;    j< incoming_size    ;j++)
      {
        Serial.print(incoming_sysex[j], HEX);
        Serial.print(F(" "));
      }
      Serial.println();
#endif

  //READ SYSEX according to FUNCTION TYPE
  switch ( incoming_sysex[5])     // The AXE-FX Message Type in in the 6th position of the SYSEX message
  {
    /////////////////////////////////////////
    // Message Type == SYSEX_STATUS_MSG
    case 0x64 :
      //TODO// Process Status/error messages
      break;
      
    /////////////////////////////////////////
    // Message Type == SYSEX_QUERY_VERSION
    case 0x08:
      if (Axe_Fx_Version == 0x00)
      {
        Axe_Fx_Type = incoming_sysex[4];
        Axe_Fx_Version = incoming_sysex[6];
        Axe_Fx_Sub_Version = incoming_sysex[7];
      }
      break;

    ///////////////////////////////////////
    // Message Type == SYSEX_QUERY_STATES 
    case 0x0E:
    {
      if(incoming_size < 10) break;
      int pos = 6;
      int i = int(incoming_size) - pos;
      byte effect_LS, effect_MS, CC_LS, CC_MS;
      
      // PROCESS THE CONTENT OF THE 0x0E SYSEX message
      CP_Number_Effects = 0;
      do {
        //Set CP OBState ans XYState
        if (incoming_sysex[pos] == 1 || incoming_sysex[pos] == 3)  // ON state if XY or NOT
        {
          CP_Effect_OBState[CP_Number_Effects] = 1;
        }
        else {
          CP_Effect_OBState[CP_Number_Effects] = 0;
        }
        if (incoming_sysex[pos] == 2 || incoming_sysex[pos] == 3)  // X always present even if no XY for that effect
        {
          CP_Effect_XYState[CP_Number_Effects] = 1;   // Case X --> State 1
        }
        else {
          CP_Effect_XYState[CP_Number_Effects] = 0;
        } 
        
        effect_LS = incoming_sysex[pos+3] >> 3;
        effect_MS = incoming_sysex[pos+4] << 4  & 0xff;  // & 0xff ??? to be removed ???
        CP_Effect_ID[CP_Number_Effects] = effect_MS ^ effect_LS;
        
        ///// CP_Effect_CC never used
        CC_LS = incoming_sysex[pos+1] >> 1;
        CC_MS = (incoming_sysex[pos+2] & 1) << 6;
        CP_Effect_CC[CP_Number_Effects] = int( CC_MS ^ CC_LS );
        
        CP_Number_Effects++;
        i = i - 5;
        pos = pos + 5;
      } while (i - 1 > 0 );  // Last byte of incoming sysex not used

      // Retrieve EFFECT TYPE of each EFFECT BLOCK in the Current Preset (CP) from the MidyAX memory
      for(int j=0;    j < CP_Number_Effects    ;j++)
      {
        for(int k=0;    k < MAX_NUMBER_EFFECTS    ;k++)
        {
          if ( CP_Effect_ID[j] == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + k ) )
          {
            CP_Effect_Type [j] = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type + k );
            break;
          }
        }
      }       

      // Retrieve the BCR preset associated to each effect from the MidyAX memory
      for(int j=0;    j < CP_Number_Effects    ;j++)
      {
        for(int k=0;    k <= BCR2000_Max_NumberOf_ControlPage_DEFINE    ; k++)
        {
          if( ControlPages_USER_Mapping[k] == CP_Effect_Type [j])
          {
            CP_Effect_BCR_Preset [j] = k;
            break;
          }       
        }
      }
      
#ifdef DEBUG3
      Serial.print(F("LIST OF EFFECTS: Total number = "));
      Serial.print(CP_Number_Effects, DEC);
      Serial.println();
      for (int j=0;    j < CP_Number_Effects    ;j++)
      {
        Serial.print(F("EFFECT "));
        Serial.print(j, DEC);
        Serial.print(F(":  ID = "));  Serial.print(CP_Effect_ID[j], HEX);
        Serial.print(F(":  CC="));  Serial.print(CP_Effect_CC[j], DEC);
        Serial.print(F(":  OBState = "));  Serial.print(CP_Effect_OBState[j], DEC);
        Serial.print(F(":  XYState = "));  Serial.print(CP_Effect_XYState[j], DEC);
        Serial.print(F(":  Type = "));  Serial.print(CP_Effect_Type[j], DEC);
        Serial.println();
      }
      Serial.println();
#endif

      CountReceivedParam = 0; // So that it counts up to CP_Number_Effects
      for(int k=0;    k < BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER    ;k++) { CP_Initial_Param_Value_received[i] = 0; }
      
       
      ////////////////////////////////////////
      // ASK FOR INITIAL VALUE OF CONTROLS  //
      ////////////////////////////////////////
      int  FirstOnIndex = 0;
      
      digitalWrite(parValueLedPin, HIGH);
      //TODO// FOR NOW: the case where an AXE-FX has no effect is not treated
      
      // Identify the first effect that is on - if any
      for (int j=0;    j < CP_Number_Effects    ;j++)
      {
        // 3 --> X on, 1 --> Y on
        if( CP_Effect_OBState[j] == 1  || CP_Effect_OBState[j] == 3)
        {
          FirstOnIndex = j;
          break;
        }
      }

      // Set BCR preset and state of 16th push buttons
      Change_BCR2000_Preset( CP_Effect_BCR_Preset [ FirstOnIndex ] + 1 , true);
          
      // Set all push buttons to off apart from the one that has been set on
      PB16_state = false;
      for(i=1; i <= 16 ; i++)
      {
        // Set al the buttons to OFF
        MIDI_BCR2000.sendControlChange( byte(40+i), byte(0), byte(1) );
      }
      // SET the active button to ON
      MIDI_BCR2000.sendControlChange( byte(41 + CP_Effect_BCR_Preset [ FirstOnIndex ] ), byte(127), byte(1) );
      CS_BCR2000_ACTIVE_BUTTON = CP_Effect_BCR_Preset [ FirstOnIndex ] + 1;


      // ASK for the PRESET name
      sysex_mes[4] = 0x0F;
      sysex_mes[5] = Calculate_CheckSum( sysex_mes, 5);
      MIDI_AXE.sendSysEx( byte( 6 ), sysex_mes, false );
      for( int k=0 ; k < 100 ; k++) 
      {
        if( MIDI_AXE.read(AXE_FX_CHANNEL) == true) break;
        delay(1);
      }  ////// RISK of autocall


      // After loding the Effects Chain description (LAYOUT)
      // starts loading parmeters for the first EFFECT BLOCK in the current preset
      StartParamLoading( FirstOnIndex);
      //StartParamLoading( FirstOnIndex); //TODO : REMOVE and imrpove Get_Send_Param_Values for first load !!
      //Display_Control_Page();

    } // End that switch case !!!
    break;
   
      
      
      
    // MIDI_SET_PARAMETER
    // Receives initial values of param after an effect (BCR2000 preset) change
    case 0x02:   
/* #ifdef DEBUG
          Serial.print("CS_Loaded   "); Serial.print(CS_Loaded, BIN); 
          Serial.print("  CountReceivedParam  "); Serial.print(CountReceivedParam, DEC);
          Serial.print("  CS_Number_Active_Encoder   "); Serial.print(CS_Number_Active_Encoder, DEC); 
          Serial.println("");Serial.println("");
#endif   */
    

      // IT LOOPER (0xA9, 169) --> no read from EEPROM
      /*if ( incoming_sysex[6] == 0x29 && incoming_sysex[7] == 0x01 )
      {
        if ( incoming_sysex[8] > byte(21) )  // 21 parameters for that effect
        {
          // RECORD
          if( incoming_sysex[8] == byte(13) )
          { 
            if(incoming_sysex[10] == byte(1) ) 
            { LOOPER_STATE_RECORD == true; MIDI_BCR2000.sendControlChange( byte(49), byte(127), byte(1) ); }
            else { LOOPER_STATE_RECORD == false; MIDI_BCR2000.sendControlChange( byte(49), byte(0), byte(1) ); }
          }
          
          // PLAY
          if( incoming_sysex[8] == byte(14) )  
          { if(incoming_sysex[10] == byte(1) ) 
            { LOOPER_STATE_PLAY == true; MIDI_BCR2000.sendControlChange( byte(50), byte(127), byte(1) );}
            else { LOOPER_STATE_PLAY == false; MIDI_BCR2000.sendControlChange( byte(50), byte(0), byte(1) );} 
          }
          
          // ONCE
          if( incoming_sysex[8] == byte(15) )
          {
            if(incoming_sysex[10] == byte(1) ) 
            { LOOPER_STATE_ONCE == true; MIDI_BCR2000.sendControlChange( byte(51), byte(127), byte(1) );}
            else { LOOPER_STATE_ONCE == false; MIDI_BCR2000.sendControlChange( byte(51), byte(0), byte(1) );}
          }
          
          // DUB
          if( incoming_sysex[8] == byte(16) )
          { if(incoming_sysex[10] == byte(1) ) 
            { LOOPER_STATE_DUB == true; MIDI_BCR2000.sendControlChange( byte(52), byte(127), byte(1) );}
            else { LOOPER_STATE_DUB == false; MIDI_BCR2000.sendControlChange( byte(52), byte(0), byte(1) );}
          }
          
          // REVERSE
          if( incoming_sysex[8] == byte(17) ) 
          { if(incoming_sysex[10] == byte(1) ) 
            { LOOPER_STATE_REVERSE == true; MIDI_BCR2000.sendControlChange( byte(53), byte(127), byte(1) );}
            else { LOOPER_STATE_REVERSE == false; MIDI_BCR2000.sendControlChange( byte(53), byte(0), byte(1) );}
          }
          
          // UNDO
          if( incoming_sysex[8] == byte(18) )  
          { if(incoming_sysex[10] == byte(1) ) 
            { LOOPER_STATE_UNDO == true; MIDI_BCR2000.sendControlChange( byte(54), byte(127), byte(1) );} 
            else { LOOPER_STATE_UNDO == false; MIDI_BCR2000.sendControlChange( byte(54), byte(0), byte(1) );}
          }
          
          // HALF
          if( incoming_sysex[8] == byte(19) )
          { if(incoming_sysex[10] == byte(1) ) 
            { LOOPER_STATE_HALF == true; MIDI_BCR2000.sendControlChange( byte(55), byte(127), byte(1) );} 
            else { LOOPER_STATE_HALF == false; MIDI_BCR2000.sendControlChange( byte(55), byte(0), byte(1) );}
          }
          
          // METRO
          if( incoming_sysex[8] == byte(20) )
          { if(incoming_sysex[10] == byte(1) ) 
            { LOOPER_STATE_METRO == true; MIDI_BCR2000.sendControlChange( byte(56), byte(127), byte(1) );} 
            else { LOOPER_STATE_METRO == false; MIDI_BCR2000.sendControlChange( byte(56), byte(0), byte(1) );} 
          }
          
          // No CC for these 2 for now
          // QUANTIZE
          //if( incoming_sysex[8] == byte(11) )
          //{ if(incoming_sysex[10] == byte(1) ) { LOOPER_STATE_QUANTIZE == true; }  else { LOOPER_STATE_QUANTIZE == false; } }
          
          // THRESH
          //if( incoming_sysex[8] == byte(6) )
          //{ if(incoming_sysex[10] == byte(1) ) { LOOPER_STATE_THRESH == true; } else { LOOPER_STATE_THRESH == false; } }          
        }
        return;
      }*/
        
      if( CS_Loaded == false && CountReceivedParam < CS_Number_Active_Encoder )
      {
        for(int i=0;    i < BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER    ;i++)
        {
          if( CP_Initial_Param_Value_received[i] == 0)
          { 
            byte CS_Effect_Type_used = CS_Effect_Type-2;
            struct DYN_Parameter THE_Parameter;

            int addr = CS_Preset_Number * (BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER) + i;
            byte Btempo = EEPROM.read(addr);
            Read_Parameter_FromFLASH( (byte) CS_Effect_Type_used, Btempo, &THE_Parameter ); 
            
       
            if( incoming_sysex[7] == 0x01 ) { incoming_sysex[6] = incoming_sysex[6] + 0x80;}  // TO BE IMPROVED !!!

            if( incoming_sysex[6] == CS_Effect_ID  && incoming_sysex[8] == Btempo && Axe_Fx_Type == 0x03)
            {
              CP_Initial_Param_Value_received[i] = 1;
               
              // Calculate value of control on the BCR2000
              if(    THE_Parameter.type != AXEFX_INT_Parameter_Type_DEFINE
                  && THE_Parameter.type != AXEFX_INTXL_Parameter_Type_DEFINE  ) // test not type = INT --> Modal
              {
                ReceivedValue1 = long(incoming_sysex[10]) + long(incoming_sysex[11]) * 128 + long(incoming_sysex[12]) * 16384;
                //if(ReceivedValue1 > numVals ) { ERROR };
                ftempo1 = float(ReceivedValue1);
                ftempo2 = THE_Parameter.numVals;
                ratio = ftempo1 / ftempo2;
                ReceivedValue = ratio * 127;
                DisplayValue = THE_Parameter.minDispValue + (THE_Parameter.maxDispValue - THE_Parameter.minDispValue) * (ratio);
              }
              else {
                ReceivedValue = incoming_sysex[10];
                DisplayValue = incoming_sysex[10];
              }
            }

            if (CP_Initial_Param_Value_received[i] == 1 )
            {          
              // Send initial param value to BCR2000
              MIDI_BCR2000.sendControlChange( byte( pgm_read_byte_near( PROGMEM_BYTE___BCR2000_Encoder_CC_Mapping + i) ), byte(ReceivedValue), byte(1) );
              send_uvga_D( i, ReceivedValue, DisplayValue );
              
#ifdef DEBUG2
                Serial.print(F("i = ")); Serial.print( i, DEC);
                Serial.print(F(" THE_Parameter.label = ")); Serial.print( THE_Parameter.label);
                Serial.print(F(" THE_Parameter.numVals = ")); Serial.print( THE_Parameter.numVals, DEC);
                Serial.print(F(" THE_Parameter.minDispValue = ")); Serial.print( THE_Parameter.minDispValue, DEC);
                Serial.print(F(" THE_Parameter.maxDispValue = ")); Serial.println( THE_Parameter.maxDispValue, DEC);
                Serial.print(F(" ReceivedValue1 = ")); Serial.print( ReceivedValue1, DEC);
                Serial.print(F(" DisplayValue = ")); Serial.print( DisplayValue, DEC);
                Serial.print(F(" ReceivedValue = ")); Serial.print( ReceivedValue, DEC);
                Serial.println(F(";"));
#endif
              
              CountReceivedParam++;
#ifdef DEBUG
              // PRINT OUT AXE-FX initial values              Serial.print("INIT VALUE for Control "); Serial.print(i,DEC);
/*              Serial.print("flash_index = "); Serial.print(flash_index, HEX);
              Serial.print("   i = "); Serial.print(i, DEC);
              Serial.print("   tempo = "); Serial.print(tempo, DEC);
              Serial.print("   flash_index + i = "); Serial.print(int(flash_index + i), DEC);
              Serial.print(" ;in HEX =  "); Serial.print(byte( tempo ), HEX);
              Serial.println();*/
              Serial.print(F("INIT VALUE for Control ")); Serial.print(i,DEC);
              Serial.print(F(" :   HB = ")); Serial.print(incoming_sysex[12], HEX);
              Serial.print(F("  MB = ")); Serial.print(incoming_sysex[11], HEX);
              Serial.print(F("  LB = ")); Serial.print(incoming_sysex[10], HEX);
              Serial.println();
              Serial.print(F("SENT TO BCR2000: "));Serial.print(" Channel= "); Serial.print( byte(1), HEX);
              Serial.print(F("  CC_Number= ")); Serial.print( byte( pgm_read_byte_near( PROGMEM_BYTE___BCR2000_Encoder_CC_Mapping + i) ), HEX);
              Serial.print(F("  ReceivedValue= ")); Serial.print( ReceivedValue1, DEC);
              Serial.print(F("  Ratio= ")); Serial.print( ratio, 8);
              Serial.print(F("  CC_VALUE= ")); Serial.print( ReceivedValue, DEC);
              Serial.println(); Serial.println(); //line feed
#endif
              break;
            }
          } // END of IF
        }  // END of FOR
      }  // END of IF   

/*#ifdef DEBUG
              Serial.print("CountReceivedParam = "); Serial.print( CountReceivedParam, DEC);
              Serial.print("  Ratio= "); Serial.print( ratio, 8);
              Serial.print("  CC_VALUE= "); Serial.print( ReceivedValue, DEC);
              Serial.println(); Serial.println(); //line feed
#endif*/

#ifdef DEBUG
      Serial.print(F("  CS_Loaded = ")); Serial.print( CS_Loaded, BIN);
      Serial.print(F("  CS_Number_Active_Encoder = ")); Serial.print( CS_Number_Active_Encoder, DEC);
      Serial.print(F("  CountReceivedParam = ")); Serial.print( CountReceivedParam, DEC);
      Serial.println(); //line feed
#endif

      //Tets if all the initial param value of the newly choosen effect have been received      
      if( CountReceivedParam == CS_Number_Active_Encoder && CS_Loaded == false) 
      {
        CS_Loaded = true;
        //send_uVGA_D( 41 , 41, 41 );    
      } 
#ifdef DEBUG4
      else {
        Serial.print(F("CountReceivedParam = ")); Serial.print(CountReceivedParam, DEC); Serial.println(); 
      }
#endif
      break;

    // Change of SCENE has occured on the AXE-FX 
    case 0x29:
        CurentPreset_CurrentSCENE_Number = incoming_sysex[6];
    break;

    // Reception of the name of the current preset on the AXE-FX (after querying it)
    case 0x0F:
        for(int i = 6; i < 38; i++)
        {
          CurentPreset_AXEFX_Preset_Name[i-6] =  incoming_sysex[i];
        }
        //Serial.println( CurentPreset_AXEFX_Preset_Name );
    break;
    
    //  A Change of current PRESET has occured on the AXE-FX
    case 0x14:
        //TODO// Store preset number
        //  =  incoming_sysex[6];
        // Start of parameter loading from the AXE-FX             
        sysex_mes[0]= 0x00;
        sysex_mes[1]= 0x01; // Manufacturer ID MSB - Fractal Audio Manufacturer ID Most Significant Byte
        sysex_mes[2]= 0x74;
        sysex_mes[3] = 0x03;  //MODEL 3 // AXE-FX II specific
        sysex_mes[4]= 0x0E;  // SYSEX Function = Query state of current preset
        sysex_mes[5] = Calculate_CheckSum( sysex_mes, 5); 
        MIDI_AXE.sendSysEx( byte( 6 ), sysex_mes, false );
    break; 
    
    
     
    default:
    break; 
  }  //END switch
      

}





void Get_Send_Param_Values( void )
{
  int addr;
  byte Current_Param_ID, Btempo;
  
  CS_Number_Active_Encoder = 0;

  //Counts the number of param queries to be send and received
  for( int j=0;  j < BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER; j++)
  { 
    addr = CS_Preset_Number * (BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER) + j;
    Btempo = EEPROM.read(addr);
    if (Btempo != 0xFE)
    {
      CS_Number_Active_Encoder++;
    }
  }
  
  
  /////////
  ////////
  delay(100); // TEMPO -- CHECK WHY IT IS NEEDED TO MAKE SURE THAT ALL THE INIT VALUE ARE RECEIVED PROPERLY
  ////////
  ////////
  
  
  //Iterate on all the encoder and push buttons of the current BCR2000 preset. Ask for Current Parameter Values 
  for( int j=0;  j < BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER; j++)
  {
    //Btempo = byte(pgm_read_byte_near( BCR2000_Preset_Encoder_Mapping + (CS_Preset_Number * (BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER)) + j ) ); 
    addr = CS_Preset_Number * (BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER) + j;
    Btempo = EEPROM.read(addr);
    //Btempo = pgm_read_byte_near( &( BCR2000_Preset_Encoder_Mapping[ CS_Preset_Number ][ j ] ) );
#ifdef DEBUG
            int Itempo = (CS_Preset_Number * (BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER)) + j;
            Serial.print(F("PROGMEM ACCESS: CS_Preset_Number = ")); Serial.print( CS_Preset_Number, DEC);
            Serial.print(F(",  j =")); Serial.print( j, DEC);
            Serial.print(F(",  Itempo =")); Serial.print( Itempo, DEC);
            Serial.print(F(",  Btempo =")); Serial.print( Btempo, HEX);
            Serial.println(F(";"));
#endif
    //Current_Param_ID = BCR2000_Preset_Encoder_Mapping[ CS_Preset_Number ][ j ];
    Current_Param_ID = Btempo;
#ifdef DEBUG
    Serial.print(F("CS Preset Number = ")); Serial.print(CS_Preset_Number, DEC);
    Serial.print(F("  j = ")); Serial.print(j, DEC);
    Serial.print(F("   Current_Param_ID = ")); Serial.print(Current_Param_ID, HEX);
    Serial.println();
#endif        
    if (Current_Param_ID != 0xFE)
    {
        
      if ( Axe_Fx_Type != 0x03 ) 
      {
        // AXE-FX STANDARD or ULTRA
        MIDI_AXE.sendSysEx( byte(SIZE_OF_SISEX_FOR_PARAM), sysex_mes, false ); 
      }
      else {
        // AXE-FX II
        sysex_mes[3] = 0x03;  //MODEL 3
        sysex_mes[4] = 0x02;  // Function ID
        if ( CS_Effect_ID < 0x80 )
        {
          sysex_mes[5] = CS_Effect_ID;
          sysex_mes[6] = 0x00;
        }
        else {
          sysex_mes[5] = CS_Effect_ID - 0x80;
          sysex_mes[6] = 0x01;
        }          
        sysex_mes[7] = Current_Param_ID;
        sysex_mes[8] = 0x00;
        sysex_mes[9] = 0x00;
        sysex_mes[10] = 0x00;
        sysex_mes[11] = 0x00;
        sysex_mes[12] = 0x00;  // 0xdd query(0) or set(1) value
        sysex_mes[13] = Calculate_CheckSum( sysex_mes, 13);
        MIDI_AXE.sendSysEx( byte( SIZE_OF_SISEX_FOR_PARAM + 2 ), sysex_mes, false );
      }

      #ifdef DEBUG
        Serial.print(j, DEC);
        Serial.print(F(" PARAM QUERY SENT: "));
        for (int k=0 ; k< SIZE_OF_SISEX_FOR_PARAM + 2 ; k++)
        {
          Serial.print(sysex_mes[k], HEX);
          Serial.print(F(" "));
        }
        Serial.println();
        Serial.println();
      #endif   
      for( int k=0 ; k < 100 ; k++) 
      {
        if( MIDI_AXE.read(AXE_FX_CHANNEL) == true) break;
        delay(1);
      }  ////// RISK of autocall
    }  // END of IF testing Current_Param != 0xFE
  }  // END OF FOR iterating to BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER
  
}




 





void AXE_ManageCC ( byte CC_channel, byte CC_number, byte CC_value )
{
/////////////////// CURRENTLY INCLUDED TO LOG ANY POTENTIAL CC MESSAGES coming from the AXE-FX or attached MFC-101 if present

  int CC_number_dec, CC_value_dec;
  byte buf[10];

  CC_number_dec = (int) CC_number;
  CC_value_dec = (int) CC_value;
  
#ifdef DEBUG_TEST
  // PRINT OUT CC VALUES RECEIVED FROM THE BCR2000 
  Serial.println(); Serial.println(); 
  Serial.print(F("CC RECEIVED FROM AXE:")); Serial.println(); 
  Serial.print(F("CHANNEL: ")); Serial.print(CC_channel, DEC);
  Serial.print(F("  Received CC:  Number: ")); Serial.print(CC_number, HEX); Serial.print(F(" ("));Serial.print(CC_number_dec, DEC); Serial.print(F(")"));
  Serial.print(F("  Value: "));  Serial.print(CC_value, HEX);Serial.print(F(" ("));Serial.print(CC_value_dec, DEC); Serial.print(F(")"));
  Serial.println();  //line feed
#endif

  if( CC_channel == AXE_FX_CHANNEL)
  {
    if( CC_number == 0x11)
    {
      BCR2000_ManageCC( BCR2000_MIDI_CHANNEL,  CC_number,  CC_value );
    }
  }

  // RECEIVING TEST CCs
  if( CC_channel == AXE_FX_CHANNEL && CC_number == MIDI_TEST_CC_SENT)
  {
    AXEFX_Received_CC_Value = CC_value;
    //Serial.print("Message : "); Serial.print(CC_value, DEC); Serial.print(" received");
   }
}






void StartParamLoading( byte Target_CP_Effect_Number )
{
  
  
      CS_Effect_ID = CP_Effect_ID[ Target_CP_Effect_Number ];
      CS_Effect_Type = CP_Effect_Type [ Target_CP_Effect_Number ];
      CS_Preset_Number = CP_Effect_BCR_Preset [ Target_CP_Effect_Number ];
//TODO :  CS_Preset_Number = Target_CP_Effect_Number ;
      CS_Effect_OBState = CP_Effect_OBState [ Target_CP_Effect_Number ];
      CS_Effect_XYState = CP_Effect_XYState [ Target_CP_Effect_Number ];
      CS_Current_Effect_Number_In_CP =  Target_CP_Effect_Number;

      Read_EffectType_FromFLASH( CS_Effect_Type-2, &CurrentControlPage_EffectType);


      /////////////////////////////////////////////////////////////////////////////////////
      ///////////  Change to the EDIT page of the EFFECT BLOCK on the AXE-FX    ///////////
      /////////////////////////////////////////////////////////////////////////////////////
      sysex_mes[3] = 0x03;  //MODEL 3
      sysex_mes[4] = 0x37;  // Function SYSEX_EDIT_EFFECT
      if ( CS_Effect_ID < 0x80 )
      {
        sysex_mes[5] = CS_Effect_ID;
        sysex_mes[6] = 0x00;
      }
      else {
        sysex_mes[5] = CS_Effect_ID - 0x80;
        sysex_mes[6] = 0x01;
      }          
      sysex_mes[7] = Calculate_CheckSum( sysex_mes, 7);
      MIDI_AXE.sendSysEx( byte( 8 ), sysex_mes, false );



      ///////////////////////////////////////////////////////////
      ///////////  INITIALISE  CS_Effect_NumSel_State ///////////
      ///////////////////////////////////////////////////////////

      switch ( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type_Number + CS_Effect_Type ) )
      {
        case 1:
          CS_Effect_NumSel_State = 0;
          break;
          
        case 2:
          for( int k=0;    k < MAX_NUMBER_EFFECTS    ;k++)
          {
#ifdef DEBUG
            Serial.print(F("CS_Effect_Type = ")); Serial.print(CS_Effect_Type, DEC);
            Serial.print(F("  CS_Effect_ID = ")); Serial.print(CS_Effect_ID, DEC);
            Serial.print(F("  k")); Serial.print(k, DEC);
            Serial.print(F("   AXEFX_Effect_Type[ k ] = ")); Serial.print( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type + k ) , DEC);           
            Serial.print(F("   AXEFX_Effect_ID[k] = ")); Serial.print( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + k), DEC);
            Serial.println();
#endif 
            if ( CS_Effect_Type == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type + k ) )
            {             
              if ( CS_Effect_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + k )
                  && CS_Effect_Type == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type + (k+1) ) )
              {
                // CASE 1 (displayed as 0)
                CS_Effect_NumSel_State = 0;
              }
              else {
                // CASE 2 (displayed as 1)
                CS_Effect_NumSel_State = 1;
              }
              break;
            }
          }            
          break;
          
        case 4:
          for( int k=0;    k < MAX_NUMBER_EFFECTS    ;k++)
          {
            if( CS_Effect_Type == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type + k ) )
            {
              if( CS_Effect_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + k ) )
              {
                // CASE 1 (displayed as 0)
                CS_Effect_NumSel_State = 0;
              }
              if( CS_Effect_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + (k+1) ) )
              {
                // CASE 2 (displayed as 1)
                CS_Effect_NumSel_State = 1;
              }
              if( CS_Effect_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + (k+2) ) )
              {
                // CASE 3 (displayed as 2)
                CS_Effect_NumSel_State = 2;
              }
              if( CS_Effect_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + (k+3) ) )
              {
                // CASE 4 (displayed as 3)
                CS_Effect_NumSel_State = 3;
              }
              break;
            }
          }   
          break;
          
        default:
          break; 
      }  // ENDofSWITCH

                  
  //ASK for the param value of the CS_Preset
  CS_Loaded = false;
  CountReceivedParam = 0;
  for( int k=0;    k < BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER    ;k++) { CP_Initial_Param_Value_received[k] = 0; }
/*#ifdef DEBUG
  Serial.println("///////////////////////////////////////////////////////////////");
  Serial.print("CS_Effect_ID: "); Serial.print(CS_Effect_ID, HEX); Serial.print(";  "); 
  Serial.print("CS_Effect_Type: "); Serial.print(CS_Effect_Type, DEC); Serial.print(";  "); 
  Serial.print("CS_Preset_Number: "); Serial.print(CS_Preset_Number, DEC); Serial.print(";  "); 
  Serial.print("CS_Effect_OBState: "); Serial.print(CS_Effect_OBState, HEX); Serial.print(";  ");
  Serial.print("CS_Effect_XYState: "); Serial.print(CS_Effect_XYState, HEX); Serial.print(";  ");
  Serial.print("LB: "); Serial.print(LB, HEX); Serial.print(";  ");
  Serial.print("MB: "); Serial.print(MB, HEX); Serial.print(";  ");  
  Serial.print("HB: "); Serial.print(HB, HEX); Serial.println(";");
  Serial.println("///////////////////////////////////////////////////////////////");
#endif*/            
  Get_Send_Param_Values();  
  // Manage 4 Effect state buttons
  Manage4EffectStateButtons();  
  Display_Control_Page();
  send_uvga_D( 41 , 41, 41 );
}








byte Calculate_CheckSum( byte  *cur_sysex, int cur_size)
{     
  byte result = 0xF0;
  for(int j=0;    j < cur_size    ;j++)
  {
    result = result ^ cur_sysex[j];
#ifdef DEBUG        
    Serial.print(F("Result: ")); Serial.print(result, HEX); Serial.print(F("   Sysex Byte: ")); Serial.print(cur_sysex[j], HEX);
    Serial.println();
#endif
  }
  result = result & 0x7F;          
  return result;
}






















