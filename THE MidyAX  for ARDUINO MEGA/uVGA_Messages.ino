/////////////////////////////////////////////////////////////////////////////////////////////////
// PROGRAM:     MidyAX - BCR2000 to AXE-FX MIDI communication orchestrator
// AIM:         Provide enhanced usability of the AXE-FX by making it possible to set the 
//              AXE-FX parameters with a hardware interface (knobs/switches of the BCR2000) 
// HARDWARE:    ARDUINO MEGA 128, 4 MIDI ports with a MIDI-IN and MIDI-OUT for each port.
// CREATOR:     Eric FEUILLEAUBOIS
// LICENSE:     GNU license v3 - That means OPEN SOFWARE, COPYLEFT and hope it's useful to you
/////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
//// Function to send a message to the uVGA  ////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////
//   HANDLE COMMUNICATIONS WITH uVGA TO DISPLAY THE SELECTED CONTROL PAGE //
//   Sends : Current_Param_ID, THE_Parameter.unit, THE_Parameter.idListVal, THE_Parameter.label
//   Does not sends the values of the parameters
////////////////////////////////////////////////////////////////////////////
void send_uVGA___Control_Page_Parameters_Infos( void )  
{
  char str[130];
  int addr;
  byte Current_Param_ID, Current_Effect_Type_ID, Current_Effect_Block_ID, Param_State;
  boolean found_Effect_Block_in_CP;
  
  struct DYN_Parameter THE_Parameter;
  struct DYN_EffectType *TEMPO_EffectType;
  struct DYN_EffectType THE_EffectType; 
        
  // SENDs messagess C ==> Parameters infos and labels
  for(int i=0; i < BCR2000_NumberOf_Controls_DEFINE ; i++)
  {
      if ( QUICKACCESS_STATE == 0 )
      {
      	addr = (CS_Preset_Number * BCR2000_NumberOf_Controls_DEFINE) +  i;
	Current_Param_ID = EEPROM.read(addr); // Get the number of the parameter mapped to the control
        Current_Effect_Block_ID = CS_Effect_Block_ID;
        Current_Effect_Type_ID = CS_Effect_Type_ID;
      }
      else {
	addr = EEPROM_START_QUICKACCESS_PAGE + ( ((QUICKACCESS_STATE - 1) * BCR2000_NumberOf_Controls_DEFINE) +  i ) * 2;
	Current_Param_ID = EEPROM.read(addr); // Get the number of the parameter mapped to the control
	addr++;
	Current_Effect_Block_ID = EEPROM.read(addr);
        Current_Effect_Type_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID_NEW + (Current_Effect_Block_ID - 100));
        //Current_Effect_Type_ID = EffectType_of_EffectBlock(Current_Effect_Block_ID );
//        for(int k=0;    k < MAX_NUMBER_EFFECTS_BLOCK    ;k++)
//        {
//          if ( Current_Effect_Block_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + k ) )
//          {
//           Current_Effect_Type_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID + k );
//           break;
//          }
//        }	      	
      }

        #ifdef DEBUG11

          sprintf(str, "i=%i, Current_Effect_Block_ID=%i, Current_Effect_Type_ID=%i, Current_Param_ID=%i", i, Current_Effect_Block_ID, Current_Effect_Type_ID, Current_Param_ID);
          Serial.println (str);
        #endif 
      
      // For QA pages determine if the effect block of the param is in the Curren Preset (CP)
      if ( QUICKACCESS_STATE != 0 )
      {
        found_Effect_Block_in_CP = false;
        for( int k=0;  k < CP_Number_Effect_Blocks; k++)
        {
          if( CP_Effect_Block_ID[k] == Current_Effect_Block_ID )
          {
            found_Effect_Block_in_CP = true;
            break;
          }
        }
      } else { found_Effect_Block_in_CP = true; }
      
      // Process only if the Current_Param_ID and Current_Effect_ID are present in the preset 
      //if ( Current_Param_ID != 254 && found_Effect_Block_in_CP)  // 0xFE
      //{
        
        // Load the proper Effect Type infos
        if ( QUICKACCESS_STATE == 0 )
        {
          TEMPO_EffectType = &CurrentControlPage_EffectType;
        }
        else {
          Read_EffectType_FromFLASH( Current_Effect_Type_ID - 2, &THE_EffectType);
          TEMPO_EffectType = &THE_EffectType;
        }
        
        Read_Parameter_FromFLASH(  Current_Effect_Type_ID - 2, Current_Param_ID, &THE_Parameter );
        
        // Determine the Param active state
        Param_State = PARAMETER_ACTIVE;
        if ( Current_Param_ID == 254 ) { Param_State =  NO_PARAMETER; }
        if( !found_Effect_Block_in_CP) { Param_State = PARAMETER_NOT_ACTIVE; } 
        
        // Sends infos on (all) the parameters of the Control Page - Effect Type or QuickAccess
        if( Current_Param_ID == TEMPO_EffectType->subTypeParamID && TEMPO_EffectType->subTypeParamID != -1)
        {
          // CASE where the param is the Sub-Type of the EFFECT TYPE ==> Sends the "EFEECT TYPE" label
          send_uVGA_C___Param_Infos( i, Current_Effect_Block_ID, Current_Effect_Type_ID - 2, Current_Param_ID, THE_Parameter.unit,
                                    THE_Parameter.idListVal, Param_State, "EFFECT TYPE" );        
        }
        else {
          // Normal CASE
          //Serial.println ("THE_Parameter.idListVal = ");Serial.print(THE_Parameter.idListVal, DEC);Serial.println ();        
          send_uVGA_C___Param_Infos( i, Current_Effect_Block_ID, Current_Effect_Type_ID - 2, Current_Param_ID, THE_Parameter.unit,
                                    THE_Parameter.idListVal, Param_State, THE_Parameter.label );
        }
        delay(3);
 
        #ifdef DEBUG11
          sprintf(str, "i=%i, CS_Effect_Type=%i, Param number=%i, THE_Parameter.name=%s, THE_Parameter.label=%s", i, Current_Effect_Type_ID, Current_Param_ID, THE_Parameter.name, THE_Parameter.label);
          Serial.println (str);Serial.println ();Serial.println ();
        #endif
      //}
  }
  //send_uVGA_C___Param_Infos( BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER + 1, 0, 0, 0, -1, -1, "41" ); // STOP sending param label messages
} //  END OF Display_Control_Page() 




void send_uVGA_E___Screen_Type( byte ScreenType)
{
  byte XY_value, ONBYPASS_value;
  
  // MESSAGE HEADER
  sSerial.print( F( "$" ) );
  sSerial.print( F( "E" ) );

  // SCREEN B state
  // 1 ==> Effect Type Control Page
  // 2 ==> QuickAccess Control Page
  sSerial.print(ScreenType, DEC);
  sSerial.print( F( " " ) );
  
  sSerial.println();
}


// Sends the description of the Effect Blocks contained in the Current Preset
void send_uVGA_A___Current_Preset( void )
{
  // MESSAGE HEADER
  sSerial.print( F( "$" ) );
  sSerial.print( F( "A" ) );
  //sSerial.print( F( " " ) );

  // Number of Effect Block in the Current Preset of the AXE-FX
  sSerial.print(CP_Number_Effect_Blocks, DEC);
  sSerial.print( F( " " ) ); 

#ifdef DEBUG5
  Serial.print(F("CP_Number_Effects = "));Serial.println(CP_Number_Effects, DEC);
#endif

  byte XY_value, ONBYPASS_value;

  // List of the EFFECT TYPE in the AXE-FX PRESET and their current ON/BYPASS state
  for(int i=0; i< CP_Number_Effect_Blocks; i++)
  {
    // Number in the PRESET
    sSerial.print(i, DEC);
    sSerial.print( F( " " ) );
    
    // EFFECT TYPE of the EFFECT BLOCK ID
    sSerial.print( CP_Effect_Block_ID[i] , DEC );
    sSerial.print( F( " " ) );

    // EFFECT TYPE of the EFFECT TYPE ID
    sSerial.print( CP_Effect_Type_ID[i] - 2 , DEC );
    sSerial.print( F( " " ) );

    // EFFECT BLOCK ON/BYPASS STATE
    if( CP_Effect_OBState[i] == false ) {ONBYPASS_value = 0;} else {ONBYPASS_value = 1;}
    sSerial.print( ONBYPASS_value, DEC);
    sSerial.print( F( " " ) );
  
    // EFFECT BLOCK X/Y state
    if( CP_Effect_XYState[i] == false ) {XY_value = 0;} else {XY_value = 1;}
    sSerial.print( XY_value, DEC );
    sSerial.print( F( " " ) );

    #ifdef DEBUG5
      Serial.print(F("i = "));Serial.println(i, DEC);
      Serial.print(F("CP_Effect_ID[i] = "));Serial.println(CP_Effect_ID[i] -2, DEC);
      Serial.print(F("CP_Effect_Type[i] -2 = "));Serial.println(CP_Effect_Type [i] -2, DEC);
      Serial.print(F("CP_Effect_OBState[i] = "));Serial.println(CP_Effect_OBState[i], DEC);
      Serial.print(F("CP_Effect_XYState[i] = "));Serial.println(CP_Effect_XYState[i], DEC);
    #endif
  }  
  delay(50);

  // PRESET NAME
  sSerial.print( CurentPreset_AXEFX_Preset_Name );

  // AXE-FX PRESET NUMBER
  // TODO: ADD CODE , use SYSEX_PATCHNUM 

  // Return character at the end of the message
  sSerial.println();
}



void send_uVGA_B___Current_EffectType_ControlPage( )
{
  byte XY_value, ONBYPASS_value;
  
  // MESSAGE HEADER
  sSerial.print( F( "$" ) );
  sSerial.print( F( "B" ) );

  // EFFECT BLOCK ID
  sSerial.print( CS_Effect_Block_ID, DEC);
  sSerial.print( F( " " ) );

  // EFFECT TYPE ID
  sSerial.print( CS_Effect_Type_ID -2, DEC);
  sSerial.print( F( " " ) );

  // EFFECT BLOCK ON/BYPASS STATE
  if( CS_Effect_OBState == false ) {ONBYPASS_value = 0;} else {ONBYPASS_value = 1;}
  sSerial.print( ONBYPASS_value, DEC);
  sSerial.print( F( " " ) );

  // EFFECT BLOCK X/Y state
  if( CS_Effect_XYState == false ) {XY_value = 0;} else {XY_value = 1;}
  sSerial.print( XY_value, DEC );
  sSerial.print( F( " " ) );
  
  // CURRENT SCENE
  sSerial.print( CurentPreset_CurrentSCENE_Number, DEC);
  sSerial.print( F( " " ) );

  //NUMBER OF ACTIVE CONTROLS in the CONTROL PAGE
  sSerial.print( CS_NumberOf_Active_Controls );
  sSerial.print( F( " " ) );
  
  // Number of active block for the EFFECT TYPE
  // TODO: ADD CODE 

  //EFFECT TYPE LABEL  
  sSerial.print( CurrentControlPage_EffectType.name );
  sSerial.println();

  delay(50);
}



// Sends the label of each param - OLD NAME = send_uvga_param_label()
void send_uVGA_C___Param_Infos( int controlNumber, int effectBlock_ID, int effectType_ID, int parameter_ID,
                                int unit, int ID_ModValList, byte Param_State, char *param_label )
{
  sSerial.print( F( "$" ) );
  sSerial.print( F( "C" ) );
  sSerial.print( controlNumber, DEC );
  sSerial.print( F( " " ) );
  sSerial.print( effectBlock_ID, DEC );
  sSerial.print( F( " " ) );  
  sSerial.print( effectType_ID, DEC );
  sSerial.print( F( " " ) );
  sSerial.print( parameter_ID, DEC );
  sSerial.print( F( " " ) );
  sSerial.print( unit, DEC );
  sSerial.print( F( " " ) );
  sSerial.print( ID_ModValList, DEC );
  sSerial.print( F( " " ) );
  sSerial.print( Param_State, DEC );
  sSerial.print( F( " " ) );
  sSerial.print(param_label);
  sSerial.println();
}


void send_uVGA_D___Init_Value( int controlNumber, int MIDIValue, long rawValue )
{
  //SENDS the parameters current values
  sSerial.print( F( "$" ) );
  sSerial.print( F( "D") );
  sSerial.print(controlNumber, DEC);
  sSerial.print( F( " " ) );  
  sSerial.print(MIDIValue, DEC);
  sSerial.print( F( " " ) );  
  sSerial.print(rawValue, DEC);
  sSerial.println();
}

void send_uVGA_Z___Changing_Value( int controlNumber, int MIDIValue, long rawValue )
{
  // SENDS changing value of a parameter 
  sSerial.print( F( "$" ) );
  sSerial.print( F( "Z" ) );
  sSerial.print(controlNumber, DEC);
  sSerial.print( F( " " ) );
  sSerial.print(MIDIValue, DEC);
  sSerial.print( F( " " ) );
  sSerial.print(rawValue, DEC);
  sSerial.println();
}

void send_uVGA_Y___Custom_Value( int controlNumber, int MIDIValue )
{
  // Only used in customization mode
  // SENDS changing value of a the parameter ID
  sSerial.print( F( "$" ) );
  sSerial.print( F( "Y" ) );
  sSerial.print(controlNumber, DEC);
  sSerial.print( F( " " ) );
  sSerial.print(MIDIValue, DEC);
  sSerial.println();
}


void send_uvga_1( )
{
  // SENDS changing value of a parameter 
  sSerial.print( F( "$" ) );
  sSerial.print( F( "1111111111" ) );

  sSerial.println();
}

int send_uvga_2( char *message)
{
  if( strlen(message) > 256 ) return -1;

  sSerial.print( F( "$" ) );
  sSerial.print( F( "2" ) );

  sSerial.print(message);
  sSerial.println();
}



