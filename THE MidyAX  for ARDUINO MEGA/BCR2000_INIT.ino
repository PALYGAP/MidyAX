////////////////////////////////////////////////////////////////////////////////////////////
// PROGRAM:     PROTOTYPE of MidyAX - BCR2000 to AXE-FX MIDI orchestrator
// HARDWARE:    ARDUINO MEGA, 4 MIDI ports with a MIDI-IN and MIDI-OUT for each port.
// CREATOR:     Eric FEUILLEAUBOIS
// COPYRIGHTS:  LGNU
////////////////////////////////////////////////////////////////////////////////////////////

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
  //BCR2000_send_SYSEX( "$rev R1" );

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
    int addr;
    byte Btempo;
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

    // TOP 8 encoder buttons   - Button n° 1 to 8  - CC n° 33 to 40
    for(int j=1; j <= 16 ; j++)
    {
      // Btempo not right for 9 to 16 till the 2 rows are in the Control Page Def !!!
      addr = (i-1) * (BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER) + (32+j-1);
      Btempo = EEPROM.read(addr);

      sprintf( messageStr,"$button %i", j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", "  .easypar CC", BCR2000_MIDI_CHANNEL, 32+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      if( Btempo != 254 )
      { BCR2000_send_SYSEX( ".showvalue on" );}
      else { BCR2000_send_SYSEX( ".showvalue off" ); }
    }
    
    // 16 Control Pages encoder buttons  - Button n° 33 to 48  - CC n° 41 to 56
    for(int j=1; j <= 16 ; j++)
    {
      sprintf( messageStr,"$button %i", 32 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 40+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }

    // 2  group keys (1, 2, 3 and 4) - Button n° 57 to 60  - CC n° 57 to 60
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 56 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 56+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }


    // 4  function keys (53 to 56) - Button n° 53 to 56  - CC n° 61 to 64
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 52 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 60+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }

    // 2  preset +/- keys - Button n° 63 to 64  - CC n° 65 to 66
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


    // 4 User Button (bottom right - 49 to 52) - Button n° 49 to 52  - CC n° 67 to 70
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 48 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 66+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }

    // 2 Foot Switch (61 to 62) - Button n° 61 to 62  - CC n° 67 to 70
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 48 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 66+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }


     // Count the number of "active" parameters with label (in AXE-EDIT) of the Current Effect Type 
     byte CS_Effect_Type_used = CS_Effect_Type-2;
     byte nbActifParam = 0;
     for(int i = 0 ; i <  CurrentControlPage_EffectType.numOfParameters ; i++)
     {
       Read_Parameter_FromFLASH( (byte) CS_Effect_Type_used, i , &THE_Parameter ); 
       if( strcmp( THE_Parameter.label, "") != 0)
       {
         nbActifParam ++;
       }
     }


#ifdef DEBUG4
  Serial.println(F("STARTED 8 top encoder INIT"));
#endif
    
    //TOP 8 encoders - Encoder n° 1 to 8  - CC n° 1 to 8
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
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, j, 0, nbActifParam-1, "absolute");

      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" ); BCR2000_send_SYSEX( ".mode bar" ); 
      BCR2000_send_SYSEX( ".resolution 100" );
    }



#ifdef DEBUG4
  Serial.println(F("STARTED 24 bottom encoders INIT"));
#endif
        
    //Bottom 24 encoders    //TOP 16 encoders - Encoder n° 33 to 56 - CC n° 9 to 32
    for(int j=1; j <= 24 ; j++)
    {

      sprintf( messageStr,"$encoder %i", 32+j);
      BCR2000_send_SYSEX( messageStr );

        sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 8+j, 0, nbActifParam-1, "absolute");

      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" ); BCR2000_send_SYSEX( ".mode 1dot" ); 
      BCR2000_send_SYSEX( ".resolution 100" );
 
      sprintf( messageStr,".default %i", j);
      BCR2000_send_SYSEX( messageStr );
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
  
  //BCR2000_send_SYSEX( "" );


#ifdef DEBUG4
  Serial.println(F("STARTED Preset Init"));
  //Serial.print("RAM: "); Serial.println(availableMemory(), DEC);
#endif

  //////////////////////////////// 
  // PRESETs initializations  
  ////////////////////////////////
  
  char messageStr[150];
  for(byte i = START_Preset_Number ; i <= END_Preset_Number ; i++)
  {    
    int addr;
    byte Btempo;
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

//    BCR2000_send_SYSEX( "  .fkeys on" );
//    BCR2000_send_SYSEX( "  .lock off" );

//    BCR2000_send_SYSEX( "  .fkeys off" );
    BCR2000_send_SYSEX( "  .lock on" );

#ifdef DEBUG4
  Serial.println(F("STARTED 8 encoder buttons INIT"));
#endif

    // TOP 8 encoder buttons   - Button n° 1 to 8  - CC n° 33 to 40
    for(int j=1; j <= 16 ; j++)
    {
      // Btempo not right for 9 to 16 till the 2 rows are in the Control Page Def !!!
      addr = (i-1) * (BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER) + (32+j-1);
      Btempo = EEPROM.read(addr);

      sprintf( messageStr,"$button %i", j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", "  .easypar CC", BCR2000_MIDI_CHANNEL, 32+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      if( Btempo != 254 )
      { BCR2000_send_SYSEX( ".showvalue on" );}
      else { BCR2000_send_SYSEX( ".showvalue off" ); }
    }
    
    // 16 Control Pages encoder buttons  - Button n° 33 to 48  - CC n° 41 to 56
    for(int j=1; j <= 16 ; j++)
    {
      sprintf( messageStr,"$button %i", 32 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 40+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }

    // 2  group keys (1, 2, 3 and 4) - Button n° 57 to 60  - CC n° 57 to 60
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 56 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 56+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }


    // 4  function keys (53 to 56) - Button n° 53 to 56  - CC n° 61 to 64
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 52 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 60+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }

    // 2  preset +/- keys - Button n° 63 to 64  - CC n° 65 to 66
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


    // 4 User Button (bottom right - 49 to 52) - Button n° 49 to 52  - CC n° 67 to 70
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 48 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 66+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }

    // 2 Foot Switch (61 to 62) - Button n° 61 to 62  - CC n° 67 to 70
    for(int j=1; j <= 4 ; j++)
    {
      sprintf( messageStr,"$button %i", 48 + j);
      BCR2000_send_SYSEX( messageStr );
      sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 66+j, 127, 0, "toggleon");
      BCR2000_send_SYSEX( messageStr );
      BCR2000_send_SYSEX( ".showvalue on" );
    }




#ifdef DEBUG4
  Serial.println(F("STARTED 8 top encoder INIT"));
#endif
    
    //TOP 8 encoders - Encoder n° 1 to 8  - CC n° 1 to 8
    for(int j=1; j <= 8 ; j++)
    {
      addr = (i-1) * (BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER) + (j-1);
      Btempo = EEPROM.read(addr);
#ifdef DEBUG4
  Serial.print(F("Read EEPROM. Btempo = ")); Serial.println(Btempo, DEC);
#endif
      if (Btempo != 254 )
      {
        
#ifdef DEBUG4
  Serial.print(F("i = ")); Serial.println(i,DEC);
  Serial.print(F("ControlPages_USER_Mapping[i-1]-2 = ")); Serial.println(ControlPages_USER_Mapping[i-1]-2,DEC);
  Serial.print(F("THE_Parameter = ")); Serial.println((int)&THE_Parameter,DEC);
#endif     
        
        Read_Parameter_FromFLASH( (byte) ControlPages_USER_Mapping[i-1]-2, Btempo, &THE_Parameter );        
        delay(3);
#ifdef DEBUG4
  Serial.println(F("Read FLASH"));
#endif
 
        #ifdef DEBUG4
          Serial.print(F("i = ")); Serial.print( i, DEC);
          Serial.print(F("  j = ")); Serial.println( j, DEC);
          Serial.print(F("  Btempo = ")); Serial.println( Btempo, DEC);          
          Serial.print(F("ControlPages_USER_Mapping[i-1]-2 = ")); Serial.println( ControlPages_USER_Mapping[i-1]-2, DEC);
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
      if(    THE_Parameter.type == AXEFX_INT_Parameter_Type_DEFINE
          || THE_Parameter.type == AXEFX_INTXL_Parameter_Type_DEFINE )   // INT case --> Modal values
      { 
        sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, j, 0, THE_Parameter.numVals-1, "absolute");
      }
      else {
        sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, j, 0, 127, "absolute");
      }
      BCR2000_send_SYSEX( messageStr );
      if( Btempo != 254 )
      { 
        BCR2000_send_SYSEX( ".showvalue on" ); BCR2000_send_SYSEX( ".mode bar" ); 
      }
      else {
        BCR2000_send_SYSEX( ".showvalue off" ); BCR2000_send_SYSEX( ".mode off" ); 
      }
      BCR2000_send_SYSEX( ".resolution 100" );
    }

#ifdef DEBUG4
  Serial.println(F("STARTED 24 bottom encoders INIT"));
#endif
        
    //BUTTOM 24 encoders    //TOP 16 encoders - Encoder n° 33 to 56 - CC n° 9 to 32
    for(int j=1; j <= 24 ; j++)
    {
      addr = (i-1) * (BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER) + (8+j-1);
      Btempo = EEPROM.read(addr);

      if (Btempo != 254 )
      {
        Read_Parameter_FromFLASH( (byte) ControlPages_USER_Mapping[i-1]-2, Btempo, &THE_Parameter );        
        delay(3);
 
        #ifdef DEBUG4
          Serial.print(F("i = ")); Serial.print( i, DEC);
          Serial.print(F("  j = ")); Serial.println( j, DEC);
          Serial.print(F("  Btempo = ")); Serial.println( Btempo, DEC);          
          Serial.print(F("ControlPages_USER_Mapping[i-1]-2 = ")); Serial.println( ControlPages_USER_Mapping[i-1]-2, DEC);
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
      if( THE_Parameter.type == AXEFX_INT_Parameter_Type_DEFINE 
          || THE_Parameter.type == AXEFX_INTXL_Parameter_Type_DEFINE) // INT case --> Modal values
      { 
        sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 8+j, 0, THE_Parameter.numVals-1, "absolute");
      }
      else {
        sprintf( messageStr,"%s %i %i %i %i %s", ".easypar CC", BCR2000_MIDI_CHANNEL, 8+j, 0, 127, "absolute");
      }
      BCR2000_send_SYSEX( messageStr );
      if( Btempo != 254 )
      { 
        BCR2000_send_SYSEX( ".showvalue on" ); BCR2000_send_SYSEX( ".mode 1dot" ); 
      }
      else {
        BCR2000_send_SYSEX( ".showvalue off" ); BCR2000_send_SYSEX( ".mode off" );
      }
      BCR2000_send_SYSEX( ".resolution 100" );
 
      sprintf( messageStr,".default %i", j);
      BCR2000_send_SYSEX( messageStr );
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


















