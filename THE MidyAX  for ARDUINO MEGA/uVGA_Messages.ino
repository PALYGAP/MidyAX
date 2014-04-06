/////////////////////////////////////////////////////////////////////////////////////////////////
// PROGRAM:     MidyAX - BCR2000 to AXE-FX MIDI communication orchestrator
// AIM:         Provide enhanced usability of the AXE-FX by making it possible to set the 
//              AXE-FX parameters with a hardware interface (knobs/switches of the BCR2000) 
// HARDWARE:    ARDUINO MEGA 128, 4 MIDI ports with a MIDI-IN and MIDI-OUT for each port.
// CREATOR:     Eric FEUILLEAUBOIS
// LICENSE:     GNU license v3 - That means OPEN SOFWARE, COPYLEFT and hope it's useful to you
// IMPORTANT Softwares/documents from other people : 
//              - ARDUINO MIDI LIBRARY by François Best
//              - the BC MIDI Implementation.pdf by Mark van den Berg
//              - and quite a few others
/////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
//   HANDLE COMMUNICATIONS WITH uVGA TO DISPLAY THE SELECTED CONTROL PAGE //
////////////////////////////////////////////////////////////////////////////
void Display_Control_Page()  
{
  char sz[24], szDebug[24];
  int ii = 0, jj, Index_On_Screen;
  char str[130], part1[11], part2[11];
  byte CS_Preset_Number_used = CS_Preset_Number;
  byte CS_Effect_Type_used = CS_Effect_Type-2; //BCR2000_Preset_Effect_Type_ID[CS_Preset_Number_used];
  int addr;
  byte Btempo;
  struct DYN_Parameter THE_Parameter;

  // SEND
  // message A: MODE 1 SCREEN (Screen Mode = Control Pages)
  // message B: EFFECT TYPE  
  send_uvga_A( 1 ); // 
  send_uvga_B( ); // value from 1 to MaxNumEffectType not 0 to MaxNumEffectType-1 


  for(int i=0; i < BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER ; i++)
  {
    part1[0] ='\0'; part2[0]='\0';
     
      addr = CS_Preset_Number_used * (BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER) + (byte) i;
      byte Btempo = EEPROM.read(addr); // Get the number of the parameter mapped to the control
      if (Btempo != 254 )
      {
        #ifdef DEBUG2
          //Serial.print("freeMemory()="); Serial.println(freeMemory());
          sprintf(str, "ii=%i, Index_On_Screen = %i, CS_Preset_Number=%i, CS_Effect_Type=%i, Param number=%i", ii, Index_On_Screen, CS_Preset_Number_used, CS_Effect_Type_used, Btempo);
          Serial.println (str);
        #endif      
 
        if( Btempo == CurrentControlPage_EffectType.subTypeParamID && CurrentControlPage_EffectType.subTypeParamID != -1)
        {
          // CASE where the param is the Sub-Type of the EFFECT TYPE
          Read_Parameter_FromFLASH( (byte) CS_Effect_Type_used, Btempo, &THE_Parameter );
          send_uvga_C( i, CS_Effect_Type_used, Btempo, "EFFECT TYPE", THE_Parameter.idListVal, THE_Parameter.unit );        
        }
        else {
          // Normal CASE
          Read_Parameter_FromFLASH( (byte) CS_Effect_Type_used, Btempo, &THE_Parameter );
          //Serial.println ("THE_Parameter.idListVal = ");Serial.print(THE_Parameter.idListVal, DEC);Serial.println ();        
          send_uvga_C( i, CS_Effect_Type_used, Btempo, THE_Parameter.label, THE_Parameter.idListVal, THE_Parameter.unit );
        }
        delay(3);
 
        #ifdef DEBUG
          sprintf(str, "ii=%i, CS_Effect_Type=%i, Param number=%i, THE_Parameter.name=%s, THE_Parameter.label=%s", ii, CS_Effect_Type_used, Btempo, THE_Parameter.name, THE_Parameter.label);
          Serial.println (str);Serial.println ();Serial.println ();
        #endif
      }
      ii++;  
  }
  send_uvga_C( BCR2000_ENCODER_NUMBER+BCR2000_PUSH_BUT_NUMBER+1, CS_Effect_Type_used, 0, "41", -1, -1 ); // STOP sending param label messages
}  //  END OF Display_Control_Page() 













/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
//// Function to send a message to the uVGA  ////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////

void send_uvga_A( int y)
{
  // SENDS the SCREEN STATE

  // MESSAGE HEADER
  sSerial.print( F( "$" ) );
  sSerial.print( F( "A" ) );
  sSerial.print( F( " " ) );

  // SCREEN STATE
  sSerial.print(y, DEC);
  sSerial.print( F( " " ) );

  sSerial.print(CP_Number_Effects, DEC);
  sSerial.print( F( " " ) ); 

  #ifdef DEBUG5
    Serial.print(F("CP_Number_Effects = "));Serial.println(CP_Number_Effects, DEC);
  #endif

  if ( y == 1 )
  { 
    byte XY_value, ONBYPASS_value;

    // AXE-FX PRESET NAME and NUMBER
    // TODO: ADD CODE

    // List of the EFFECT TYPE in the AXE-FX PRESET and their current ON/BYPASS state
    for(int i=0; i< CP_Number_Effects; i++)
    {
      // Number in the PRESET
      sSerial.print(i, DEC);
      sSerial.print( F( " " ) );
      
      // EFFECT TYPE of the EFFECT BLOCK ID
      sSerial.print( CP_Effect_ID[i] , DEC );
      sSerial.print( F( " " ) );

      // EFFECT TYPE of the EFFECT TYPE ID
      sSerial.print( CP_Effect_Type[i] -2 , DEC );
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
        Serial.print(F("CP_Effect_OBState[i] = "));Serial.println(CP_Effect_OBState[i], DEC);
        Serial.print(F("CP_Effect_XYState[i] = "));Serial.println(CP_Effect_XYState[i], DEC);
        Serial.print(F("CP_Effect_Type[i] -2 = "));Serial.println(CP_Effect_Type [i] -2, DEC);
        Serial.print(F("CP_Effect_ID[i] = "));Serial.println(CP_Effect_ID[i] -2, DEC);
      #endif
    }  
    delay(50);
  }

  // PRESET NAME
  sSerial.print( CurentPreset_AXEFX_Preset_Name );

  // Return charactère at the end of the message
  sSerial.println();
}

void send_uvga_B()
{
  byte XY_value, ONBYPASS_value;
  
  // MESSAGE HEADER
  sSerial.print( F( "$" ) );
  sSerial.print( F( "B" ) );

  // EFFECT BLOCK ID
  sSerial.print( CS_Effect_ID, DEC);
  sSerial.print( F( " " ) );

  // EFFECT TYPE ID
  sSerial.print( CS_Effect_Type -2, DEC);
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

  // Number of active block for the EFFECT TYPE
  // TODO: ADD CODE 
  
  //EFFECT TYPE LABEL  
  sSerial.print( CurrentControlPage_EffectType.name );
  sSerial.println();

  delay(50);
  //EFFECT BLOCK LABEL  
  //CS_Effect_NumSel_State
  //CS_Effect_ID 

}

// Sends the label of each param - OLD NAME = send_uvga_param_label()
void send_uvga_C( int controlNumber, int effectType_number, int param_number, char *param_label, int ID_ModValList, int unit )
{
  sSerial.print( F( "$" ) );
  sSerial.print( F( "C" ) );
  sSerial.print( controlNumber, DEC );
  sSerial.print( F( " " ) );
  sSerial.print( effectType_number, DEC );
  sSerial.print( F( " " ) );
  sSerial.print( param_number, DEC );
  sSerial.print( F( " " ) );
  sSerial.print( unit, DEC );
  sSerial.print( F( " " ) );
  sSerial.print( ID_ModValList, DEC );
  sSerial.print( F( " " ) );
  sSerial.print(param_label);
  sSerial.println();
}


void send_uvga_D( int controlNumber, int MIDIValue, long rawValue )
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

void send_uvga_Z( int controlNumber, int MIDIValue, long DisplayValue )
{
  // SENDS changing value of a parameter 
  sSerial.print( F( "$" ) );
  sSerial.print( F( "Z" ) );
  sSerial.print(controlNumber, DEC);
  sSerial.print( F( " " ) );
  sSerial.print(MIDIValue, DEC);
  sSerial.print( F( " " ) );
  sSerial.print(DisplayValue, DEC);
  sSerial.println();
}

void send_uvga_Y( int controlNumber, int MIDIValue )
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

