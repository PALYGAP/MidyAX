/////////////////////////////////////////////////////////////////////////////////////////////////
// PROGRAM:     MidyAX - BCR2000 to AXE-FX MIDI communication orchestrator
// AIM:         Provide enhanced usability of the AXE-FX by making it possible to set the 
//              AXE-FX parameters with a hardware interface (knobs/switches of the BCR2000) 
// HARDWARE:    ARDUINO MEGA 128, 4 MIDI ports with a MIDI-IN and MIDI-OUT for each port.
// CREATOR:     Eric FEUILLEAUBOIS
// LICENSE:     GNU license v3 - That means OPEN SOFWARE, COPYLEFT and hope it's useful to you
/////////////////////////////////////////////////////////////////////////////////////////////////

//#include "DEBUG.h"

void BCR2000_Customize_Conf( byte BCR2000_Preset_Number )
{
  //BCR2000_SysEx = (byte *) malloc( 200 * sizeof(byte));

#ifdef DEBUG4
  Serial.println(F("STARTED BCR2000_Init_Device function"));
#endif

  BCR2000_SysEx[0] = 0x00;  // Manufacturer's ID
  BCR2000_SysEx[1] = 0x20;  // Manufacturer's ID
  BCR2000_SysEx[2] = 0x32;  // Manufacturer's ID
  BCR2000_SysEx[3] = 0x7F;  // Device's ID - 0x7F = any devices
  BCR2000_SysEx[4] = 0x15;  // BCR2000 ID
  BCR2000_SysEx[5] = 0x20;  // BCL Message Command
  BCR2000_SysEx[6] = 0x00;  // Index MSB
  BCR2000_SysEx[7] = 0x00;  // Index LSB

  SYSEX_counter = 0;
/*  BCR2000_send_SYSEX( "$rev R1" );
  BCR2000_send_SYSEX( "$global" );
  BCR2000_send_SYSEX( ".midimode S-4" );
  BCR2000_send_SYSEX( ".startup last" );
  BCR2000_send_SYSEX( ".footsw auto" );  
  BCR2000_send_SYSEX( ".rxch 1" );
  BCR2000_send_SYSEX( ".deviceid 1" );
  BCR2000_send_SYSEX( ".txinterval 50" );
  BCR2000_send_SYSEX( ".deadtime 0" );
  BCR2000_send_SYSEX( "$end" );
*/  

#ifdef DEBUG4
  Serial.println(F("STARTED Preset Init"));
  //Serial.print("RAM: "); Serial.println(availableMemory(), DEC);
#endif

  //////////////////////////////// 
  // PRESETs initializations  
  ////////////////////////////////
  
  char messageStr[150];
 
   
  // BLOCK with only 1 iteration
  int i = BCR2000_Preset_Number;
  {    
    struct DYN_Parameter THE_Parameter;
    
    SYSEX_counter = 0;
    BCR2000_send_SYSEX( "$rev R1" );
    sprintf( messageStr,"%s %i", "$recall", i);
    BCR2000_send_SYSEX( messageStr );
    
    BCR2000_send_SYSEX( "$preset" );
    BCR2000_send_SYSEX( ".init" );
    sprintf( messageStr, "%s 'Preset %i'", ".name", i);
    BCR2000_send_SYSEX( messageStr );
    BCR2000_send_SYSEX( "  .snapshot off" );
    BCR2000_send_SYSEX( "  .request off" );
    BCR2000_send_SYSEX( "  .egroups 1" );
    BCR2000_send_SYSEX( "  .lock on" );

#ifdef DEBUG4
  Serial.println(F("STARTED 8 encoder buttons INIT"));
#endif

    // TOP 8 encoder buttons   - Button n 1 to 8  - CC n 33 to 40
    for(int j=1; j <= 8 ; j++)
    {
      sprintf( messageStr,"$button %i", j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", "  .easypar CC", BCR2000_MIDI_CHANNEL, 32+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %s", "  .mode", "toggle");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }
    
    // 16 Control Pages encoder buttons  - Button n 33 to 48  - CC n 41 to 56
    for(int j=1; j <= 16 ; j++)
    {
      sprintf( messageStr,"$button %i", 32 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 40+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }

    // 2  group keys (1, 2, 3 and 4) - Button n 57 to 60  - CC n 57 to 60
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 56 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 56+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }


    // 4  function keys (53 to 56) - Button n 53 to 56  - CC n 61 to 64
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 52 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 60+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }

    // 2  preset +/- keys - Button n 63 to 64  - CC n 65 to 66
    sprintf( messageStr,"$button %i", 63);
    BCR2000_send_SYSEX( messageStr );
    sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 65, 0, 0, "toggleon");
    BCR2000_send_SYSEX( messageStr );
    BCR2000_send_SYSEX( ".default 0" );
    BCR2000_send_SYSEX( ".showvalue on" );
    sprintf( messageStr,"$button %i", 64);
    BCR2000_send_SYSEX( messageStr );
    sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 66, 127, 127, "toggleon");
    BCR2000_send_SYSEX( messageStr );
    BCR2000_send_SYSEX( ".default 0" );
    BCR2000_send_SYSEX( ".showvalue on" );


    // 4 User Button (bottom right - 49 to 52) - Button n 49 to 52  - CC n 67 to 70
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 48 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 66+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }

    // 2 Foot Switch (61 to 62) - Button n 61 to 62  - CC n 67 to 70
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 48 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 66+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }


//     // Count the number of "active" parameters with label (in AXE-EDIT) of the Current Effect Type 
//     byte CS_Effect_Type_used = CS_Effect_Type_ID - 2;
//     
//     for(int i = 0 ; i <  CurrentControlPage_EffectType.numOfParameters ; i++)
//     {
//       Read_Parameter_FromFLASH( (byte) CS_Effect_Type_used, i , &THE_Parameter ); 
//       if( strcmp( THE_Parameter.label, "") != 0)
//       {
//         nbActifParam ++;
//       }
//     }


#ifdef DEBUG4
  Serial.println(F("STARTED 8 top encoder INIT"));
#endif
    
    byte nbActifParam;
    //TOP 8 encoders - Encoder n¬¨‚àû 1 to 8  - CC n¬¨‚àû 1 to 8
    for(int j=1; j <= 8 ; j++)
    {
#ifdef DEBUG4
      Serial.print(F("i = ")); Serial.println(i,DEC);
      Serial.print(F("ControlPages_USER_Mapping[i-1]-2 = ")); Serial.println(ControlPages_USER_Mapping[i-1]-2,DEC);
      Serial.print(F("THE_Parameter = ")); Serial.println((int)&THE_Parameter,DEC);
#endif     
      sprintf( messageStr,"$encoder %i", j);
      BCR2000_send_SYSEX( messageStr );
      // The max number of Parameter is supposed to always be inferior to 127
      if( QUICKACCESS_STATE == 0) 
      {
        Determine_NumberOf_ActiveParam(j);
      }
      else {
        nbActifParam = max( Determine_NumberOf_ActiveParam(j) , AXEFX_NumberOf_EffectBlocks_DEFINE);
      }
 
      #ifdef DEBUG4
        Serial.print(F("nbActifParam-1 = ")); Serial.println( nbActifParam-1, DEC);
      #endif      
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, j, 0, nbActifParam-1, "absolute");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" ); BCR2000_send_SYSEX( ".mode bar" ); 
      if( QUICKACCESS_STATE == 0)  
      { 
        BCR2000_send_SYSEX( ".resolution 100" ); 
      }
      else {
        sprintf( messageStr,".resolution %i", AXEFX_NumberOf_EffectBlocks_DEFINE);
        BCR2000_send_SYSEX( messageStr );
      }
    }



    #ifdef DEBUG4
      Serial.println(F("STARTED 24 bottom encoders INIT"));
    #endif
        
    //Bottom 24 encoders    //TOP 16 encoders - Encoder nÔøΩ 33 to 56 - CC nÔøΩ 9 to 32
    for(int j=1; j <= 24 ; j++)
    {
      sprintf( messageStr,"$encoder %i", 32+j);
      BCR2000_send_SYSEX( messageStr );
      // The max number of Parameter is supposed to always be inferior to 127
      if( QUICKACCESS_STATE == 0) 
      {
        Determine_NumberOf_ActiveParam(j);
      }
      else {
        nbActifParam = max( Determine_NumberOf_ActiveParam(j) , AXEFX_NumberOf_EffectBlocks_DEFINE);
      }
      #ifdef DEBUG4
        Serial.print(F("nbActifParam-1 = ")); Serial.println( nbActifParam-1, DEC);
      #endif 
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 8+j, 0, nbActifParam-1, "absolute");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" ); BCR2000_send_SYSEX( ".mode 1dot" ); 
      if( QUICKACCESS_STATE == 0)  
      { 
        BCR2000_send_SYSEX( ".resolution 100" ); 
      }
      else {
        sprintf( messageStr,".resolution %i", AXEFX_NumberOf_EffectBlocks_DEFINE);
        BCR2000_send_SYSEX( messageStr );
      }
    }

#ifdef DEBUG4
  Serial.println(F("STARTED STORE"));
#endif

    //STORE BCR2000 PRESET
    sprintf( messageStr,"%s %i", "$store", i);
    BCR2000_send_SYSEX( messageStr );

    BCR2000_send_SYSEX( "$end" );
    delay(500);
  }

  BCR2000_send_SYSEX( "$rev R1" );
  sprintf( messageStr,"%s %i", "$recall", i);
  BCR2000_send_SYSEX( "$end" );
  delay(500);
  
  //BCR2000_Init_Current_Preset_Controls_Values();
  
  Change_BCR2000_Preset( i+1, false);
  Change_BCR2000_Preset( i, false);
  
}


byte Determine_NumberOf_ActiveParam( byte encoder_number)
{
  byte Current_Effect_Block_ID, Current_Effect_Type_ID;
  int addr;
  struct DYN_Parameter THE_Parameter; 
  
  if (  QUICKACCESS_STATE == 0 )
  {
    //addr = (i-1) * BCR2000_NumberOf_Controls_DEFINE + (encoder_number-1);
    //Current_Param_ID = EEPROM.read(addr);
    Current_Effect_Type_ID = CS_Effect_Type_ID;
  }
  else {
    addr = EEPROM_START_QUICKACCESS_PAGE + ( (QUICKACCESS_STATE-1) * BCR2000_NumberOf_Controls_DEFINE + (encoder_number-1) ) *2 + 1;
    Current_Effect_Block_ID = EEPROM.read(addr);
    Current_Effect_Type_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID_NEW + (Current_Effect_Block_ID - 100));
  }

  // Count the number of "active" parameters with label (in AXE-EDIT) of the Current Effect Type 
  byte nbActifParam = 0;
  for(int i = 0 ; i <  CurrentControlPage_EffectType.numOfParameters ; i++)
  {
    Read_Parameter_FromFLASH( (byte) Current_Effect_Type_ID - 2, i , &THE_Parameter ); 
    if( strcmp( THE_Parameter.label, "") != 0)
    {
      nbActifParam ++;
    }
  }
  return nbActifParam;
}


void BCR2000_Init_Device( byte START_Preset_Number, byte END_Preset_Number )
{
  //BCR2000_SysEx = (byte *) malloc( 200 * sizeof(byte));

#ifdef DEBUG4
  Serial.println(F("STARTED BCR2000_Init_Device function"));
#endif

  BCR2000_SysEx[0] = 0x00;  // Manufacturer's ID
  BCR2000_SysEx[1] = 0x20;  // Manufacturer's ID
  BCR2000_SysEx[2] = 0x32;  // Manufacturer's ID
  BCR2000_SysEx[3] = 0x7F;  // Device's ID - 0x7F = any devices
  BCR2000_SysEx[4] = 0x15;  // BCR2000 ID
  BCR2000_SysEx[5] = 0x20;  // BCL Message Command
  BCR2000_SysEx[6] = 0x00;  // Index MSB
  BCR2000_SysEx[7] = 0x00;  // Index LSB

  SYSEX_counter = 0;
  BCR2000_send_SYSEX( "$rev R1" );
  BCR2000_send_SYSEX( "$global" );
  BCR2000_send_SYSEX( ".midimode S-4" );
  BCR2000_send_SYSEX( ".startup last" );
  BCR2000_send_SYSEX( ".footsw auto" );  
  BCR2000_send_SYSEX( ".rxch 1" );
  BCR2000_send_SYSEX( ".deviceid 1" );
  BCR2000_send_SYSEX( ".txinterval 50" );
  BCR2000_send_SYSEX( ".deadtime 0" );
  BCR2000_send_SYSEX( "$end" );
  
#ifdef DEBUG4
  Serial.println(F("STARTED Preset Init"));
  //Serial.print("RAM: "); Serial.println(availableMemory(), DEC);
#endif

  //////////////////////////////// 
  // PRESETs initializations  
  ////////////////////////////////

  char messageStr[150];
  int addr;
  //byte Btempo;
  struct DYN_Parameter THE_Parameter;
 
  byte Current_Param_ID, Current_Effect_Block_ID, Current_Effect_Type_ID;
 
 
  for(byte i = START_Preset_Number ; i <= END_Preset_Number ; i++)
  {    
    SYSEX_counter = 0;
    BCR2000_send_SYSEX( "$rev R1" );
    sprintf( messageStr,"%s %i", "$recall", i);
    BCR2000_send_SYSEX( messageStr );
 
#ifdef DEBUG7
  delay(3000);
#endif  
    
    BCR2000_send_SYSEX( "$preset" );
    BCR2000_send_SYSEX( ".init" );
    sprintf( messageStr, "%s 'Preset %i'", ".name", i);
    BCR2000_send_SYSEX( messageStr );
    BCR2000_send_SYSEX( "  .snapshot off" );
    BCR2000_send_SYSEX( "  .request off" );
    BCR2000_send_SYSEX( "  .egroups 1" );
    BCR2000_send_SYSEX( "  .lock on" );
    // BCR2000_send_SYSEX( "  .name '' " );
    // TODO : Add Effect Type name and copy to other init iterations

#ifdef DEBUG4
  Serial.println(F("STARTED 8 encoder buttons INIT"));
#endif

#ifdef DEBUG7
  delay(3000);
#endif  

    // TOP 8 encoder buttons   - Button n¬¨‚àû 1 to 8  - CC n¬¨‚àû 33 to 40
    for(int j=1; j <= 8 ; j++)
    {
      if (    i != BCR2000_PRESET_NUMBER_QUICKACCESS_PAGE_1_DEFINE
           && i != BCR2000_PRESET_NUMBER_QUICKACCESS_PAGE_2_DEFINE )
      {
        addr = (i-1) * BCR2000_NumberOf_Controls_DEFINE + (32+j-1);
        Current_Param_ID = EEPROM.read(addr);
      }
      else {
        addr = EEPROM_START_QUICKACCESS_PAGE + ( (QUICKACCESS_STATE-1) * BCR2000_NumberOf_Controls_DEFINE + (32+j-1) ) *2;
	Current_Param_ID = EEPROM.read(addr);
      }
      sprintf( messageStr,"$button %i", j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", "  .easypar CC", BCR2000_MIDI_CHANNEL, 32+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %s", "  .mode", "toggle");
      BCR2000_send_SYSEX( messageStr );
      if( Current_Param_ID != 254 )
      { BCR2000_send_SYSEX( ".showvalue on" );}
      else { BCR2000_send_SYSEX( ".showvalue off" ); }
    }
    
#ifdef DEBUG7
  delay(3000);
#endif    
    
    // 16 Control Pages encoder buttons  - Button n¬¨‚àû 33 to 48  - CC n¬¨‚àû 41 to 56
    for(int j=1; j <= 16 ; j++)
    {
      sprintf( messageStr,"$button %i", 32 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 40+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }

#ifdef DEBUG7
  delay(3000);
#endif

    // 2  group keys (1, 2, 3 and 4) - Button n¬¨‚àû 57 to 60  - CC n¬¨‚àû 57 to 60
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 56 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 56+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }

#ifdef DEBUG7
  delay(3000);
#endif

    // 4  function keys (53 to 56) - Button n¬¨‚àû 53 to 56  - CC n¬¨‚àû 61 to 64
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 52 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 60+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }

#ifdef DEBUG7
  delay(3000);
#endif

    // 2  preset +/- keys - Button n¬¨‚àû 63 to 64  - CC n¬¨‚àû 65 to 66
    sprintf( messageStr,"$button %i", 63);
    BCR2000_send_SYSEX( messageStr );
    sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 65, 0, 0, "toggleon");
    BCR2000_send_SYSEX( messageStr );
    BCR2000_send_SYSEX( ".default 0" );
    BCR2000_send_SYSEX( ".showvalue on" );
    sprintf( messageStr,"$button %i", 64);
    BCR2000_send_SYSEX( messageStr );
    sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 66, 127, 127, "toggleon");
    BCR2000_send_SYSEX( messageStr );
    BCR2000_send_SYSEX( ".default 0" );
    BCR2000_send_SYSEX( ".showvalue on" );

#ifdef DEBUG7
  delay(3000);
#endif

    // 4 User Button (bottom right - 49 to 52) - Button n¬¨‚àû 49 to 52  - CC n¬¨‚àû 67 to 70
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 48 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 66+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }

#ifdef DEBUG7
  delay(3000);
#endif

// 2 Foot Switch (61 to 62) - Button n¬¨‚àû 61 to 62  - CC n¬¨‚àû 67 to 70
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 48 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 66+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }


#ifdef DEBUG7
  delay(3000);
#endif

#ifdef DEBUG4
  Serial.println(F("STARTED 8 top encoder INIT"));
#endif
    
    //TOP 8 encoders - Encoder n√î√∏Œ© 1 to 8  - CC n√î√∏Œ© 1 to 8
    for(int j=1; j <= 8 ; j++)
    {


    if (    i != BCR2000_PRESET_NUMBER_QUICKACCESS_PAGE_1_DEFINE
         && i != BCR2000_PRESET_NUMBER_QUICKACCESS_PAGE_2_DEFINE)
      {
        addr = (i-1) * BCR2000_NumberOf_Controls_DEFINE + (j-1);
        Current_Param_ID = EEPROM.read(addr);
        Current_Effect_Type_ID = ControlPages_USER_Mapping[i-1];
      }
      else {
        addr = EEPROM_START_QUICKACCESS_PAGE + ( (QUICKACCESS_STATE-1) * BCR2000_NumberOf_Controls_DEFINE + (j-1) ) *2;
	Current_Effect_Block_ID = EEPROM.read(addr);
        Current_Effect_Type_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID_NEW + (Current_Effect_Block_ID - 100) );
      }

#ifdef DEBUG4
  Serial.print(F("Read EEPROM. Current_Param_ID = ")); Serial.println(Current_Param_ID, DEC);
#endif

      if (Current_Param_ID != 254 )
      {
        
#ifdef DEBUG4
  Serial.print(F("i = ")); Serial.println(i,DEC);
  Serial.print(F("ControlPages_USER_Mapping[i-1]-2 = ")); Serial.println(ControlPages_USER_Mapping[i-1]-2,DEC);
  Serial.print(F("THE_Parameter = ")); Serial.println((int)&THE_Parameter,DEC);
#endif     
        
        Read_Parameter_FromFLASH( Current_Effect_Type_ID - 2, Current_Param_ID, &THE_Parameter );        
        delay(3);

#ifdef DEBUG4
  Serial.println(F("Read FLASH"));
#endif
 
        #ifdef DEBUG4
          Serial.print(F("i = ")); Serial.print( i, DEC);
          Serial.print(F("  j = ")); Serial.println( j, DEC);
          Serial.print(F("Current_Param_ID = ")); Serial.println( Current_Param_ID, DEC);          
          Serial.print(F("Current_Effect_Block_ID = ")); Serial.println( Current_Effect_Block_ID, DEC);
          Serial.print(F("Current_Effect_Type_ID = ")); Serial.println( Current_Effect_Type_ID, DEC);
          Serial.print(F(" THE_Parameter.ID = ")); Serial.println( THE_Parameter.ID, DEC);
          Serial.print(F(" THE_Parameter.label = ")); Serial.println( THE_Parameter.label);
          Serial.print(F(" THE_Parameter.type = ")); Serial.println( THE_Parameter.type, DEC);
          Serial.print(F(" THE_Parameter.numVals = ")); Serial.println( THE_Parameter.numVals, DEC);
          Serial.print(F(" THE_Parameter.minDispValue = ")); Serial.println( THE_Parameter.minDispValue, DEC);
          Serial.print(F(" THE_Parameter.maxDispValue = ")); Serial.println( THE_Parameter.maxDispValue, DEC);
          Serial.print(F(" THE_Parameter.precision = ")); Serial.println( THE_Parameter.precision, DEC);
          Serial.print(F(" THE_Parameter.idListVal = ")); Serial.println( THE_Parameter.idListVal, DEC);
          Serial.println(F(";"));
        #endif
      }

      sprintf( messageStr,"$encoder %i", j);
      BCR2000_send_SYSEX( messageStr );
      if( (THE_Parameter.type == AXEFX_INT_Parameter_Type_DEFINE 
          || THE_Parameter.type == AXEFX_INTXL_Parameter_Type_DEFINE ) 
          && THE_Parameter.numVals-1 <= 127) // INT case --> Modal values
      { 
        sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, j, 0, THE_Parameter.numVals-1, "absolute");
      }
      else {
        sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, j, 0, 127, "absolute");
      }
      BCR2000_send_SYSEX( messageStr );
      if( Current_Param_ID != 254 )
      { 
        BCR2000_send_SYSEX( ".showvalue on" ); BCR2000_send_SYSEX( ".mode bar" ); 
      }
      else {
        BCR2000_send_SYSEX( ".showvalue off" ); BCR2000_send_SYSEX( ".mode off" ); 
      }
      BCR2000_send_SYSEX( ".resolution 100" );
    }

#ifdef DEBUG7
  delay(3000);
#endif

#ifdef DEBUG4
  Serial.println(F("STARTED 24 bottom encoders INIT"));
#endif
        
    //BUTTOM 24 encoders    //TOP 16 encoders - Encoder n¬¨‚àû 33 to 56 - CC n¬¨‚àû 9 to 32
    for(int j=1; j <= 24 ; j++)
    {

    if (    i != BCR2000_PRESET_NUMBER_QUICKACCESS_PAGE_1_DEFINE
         && i != BCR2000_PRESET_NUMBER_QUICKACCESS_PAGE_2_DEFINE)
      {
        addr = (i-1) * BCR2000_NumberOf_Controls_DEFINE + (8+j-1);
        Current_Param_ID = EEPROM.read(addr);
        Current_Effect_Type_ID = ControlPages_USER_Mapping[i-1];
      }
      else {
        addr = EEPROM_START_QUICKACCESS_PAGE + ( (QUICKACCESS_STATE-1) * BCR2000_NumberOf_Controls_DEFINE + (8+j-1) ) *2;
	Current_Effect_Block_ID = EEPROM.read(addr);
        Current_Effect_Type_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID_NEW + (Current_Effect_Block_ID - 100) );
      }

      if (Current_Param_ID != 254 )
      {
        Read_Parameter_FromFLASH( Current_Effect_Type_ID -2, Current_Param_ID, &THE_Parameter );        
        delay(3);
 
        #ifdef DEBUG4
          Serial.print(F("i = ")); Serial.print( i, DEC);
          Serial.print(F("  j = ")); Serial.println( j, DEC);
          Serial.print(F("Current_Param_ID = ")); Serial.println( Current_Param_ID, DEC);          
          Serial.print(F("Current_Effect_Block_ID = ")); Serial.println( Current_Effect_Block_ID, DEC);
          Serial.print(F("Current_Effect_Type_ID = ")); Serial.println( Current_Effect_Type_ID, DEC);
          Serial.print(F(" THE_Parameter.ID = ")); Serial.println( THE_Parameter.ID, DEC);
          Serial.print(F(" THE_Parameter.label = ")); Serial.println( THE_Parameter.label);
          Serial.print(F(" THE_Parameter.type = ")); Serial.println( THE_Parameter.type, DEC);
          Serial.print(F(" THE_Parameter.numVals = ")); Serial.println( THE_Parameter.numVals, DEC);
          Serial.print(F(" THE_Parameter.minDispValue = ")); Serial.println( THE_Parameter.minDispValue, DEC);
          Serial.print(F(" THE_Parameter.maxDispValue = ")); Serial.println( THE_Parameter.maxDispValue, DEC);
          Serial.print(F(" THE_Parameter.precision = ")); Serial.println( THE_Parameter.precision, DEC);
          Serial.print(F(" THE_Parameter.idListVal = ")); Serial.println( THE_Parameter.idListVal, DEC);
          Serial.println(F(";"));
        #endif
      }

      sprintf( messageStr,"$encoder %i", 32+j);
      BCR2000_send_SYSEX( messageStr );
      if( (THE_Parameter.type == AXEFX_INT_Parameter_Type_DEFINE 
          || THE_Parameter.type == AXEFX_INTXL_Parameter_Type_DEFINE ) 
          && THE_Parameter.numVals-1 <= 127) // INT case --> Modal values
      { 
        sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 8+j, 0, THE_Parameter.numVals-1, "absolute");
      }
      else {
        sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 8+j, 0, 127, "absolute");
      }
      BCR2000_send_SYSEX( messageStr );
      if( Current_Param_ID != 254 )
      { 
        BCR2000_send_SYSEX( ".showvalue on" ); BCR2000_send_SYSEX( ".mode 1dot" ); 
      }
      else {
        BCR2000_send_SYSEX( ".showvalue off" ); BCR2000_send_SYSEX( ".mode off" );
      }
      BCR2000_send_SYSEX( ".resolution 100" );
 
      //sprintf( messageStr,".default %i", 0);
      //BCR2000_send_SYSEX( messageStr );
    }

#ifdef DEBUG4
  Serial.println(F("STARTED STORE"));
#endif

    //STORE BCR2000 PRESET
    sprintf( messageStr,"%s %i", "$store", i);
    BCR2000_send_SYSEX( messageStr );

    BCR2000_send_SYSEX( "$end" );

    delay(500);
  }

  
}









void BCR2000_send_SYSEX( char *message)
{
  int strSize;
  byte *SYSEX_var_content = BCR2000_SysEx + 8;

  BCR2000_SysEx[6] = SYSEX_counter / 128;
  BCR2000_SysEx[7] = SYSEX_counter - ( BCR2000_SysEx[6] * 128 );
  SYSEX_counter++;
  //Serial.print("SYSEX_counter = "); Serial.print(SYSEX_counter, DEC); Serial.println();
  //Serial.print("BCR2000_SysEx["); Serial.print(7, DEC);Serial.print("] = ");Serial.print(BCR2000_SysEx[7], HEX); Serial.println();
  //Serial.print("BCR2000_SysEx["); Serial.print(8, DEC);Serial.print("] = ");Serial.print(BCR2000_SysEx[8], HEX); Serial.println();

  strSize = sprintf( (char *) SYSEX_var_content ,"%s", message);
  //Serial.println(message);
  //LogSysEx( BCR2000_SysEx,  8 + strSize);
  //Serial.println();
  MIDI_BCR2000.sendSysEx( byte( 8 + strSize ), BCR2000_SysEx, false );
}









void LogSysEx( byte *BCR2000_SysEx, int Size)
{
  Serial.print( F( "Sizeof BCR2000_SysEx = " ) ); Serial.print(Size, DEC);Serial.println();
  for(int i=0;    i < Size    ;i++)
  {
    Serial.print( F( "BCR2000_SysEx[" ) ); Serial.print(i, DEC);Serial.print( F( "] = " ) );Serial.print(BCR2000_SysEx[i], HEX); Serial.println();
  }
  Serial.println();
}




















