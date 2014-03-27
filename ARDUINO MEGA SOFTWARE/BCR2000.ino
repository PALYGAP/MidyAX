void Change_BCR2000_Preset ( int Preset_Number, boolean init)
{
  byte buf[71];
  buf[0] = 0xF0;
  buf[1] = 0x00;
  buf[2] = 0x20;
  buf[3] = 0x32;
  buf[4] = 0x00;
  buf[5] = 0x15;
  buf[6] = 0x22;
  buf[7] = byte( Preset_Number-1 );
  buf[8] = 0xF7;

  MIDI_BCR2000.sendSysEx( byte(9), buf, false );

  if (init == true ) { BCR2000_Init_Current_Preset_Controls_Values(); }


  if( PB16_state == true)
  {  MIDI_BCR2000.sendControlChange( byte(59), byte(127), byte(1) ); }
  else { MIDI_BCR2000.sendControlChange( byte(59), byte(0), byte(1) ); }


  if( LOOPER_STATE == true) { MIDI_BCR2000.sendControlChange( byte(63), byte(127), byte(1) ); }
  else { MIDI_BCR2000.sendControlChange( byte(63), byte(0), byte(1) ); }
  
  if( LOOPER_STATE_RECORD == true) { MIDI_BCR2000.sendControlChange( byte(61), byte(127), byte(1) ); }
  else { MIDI_BCR2000.sendControlChange( byte(61), byte(0), byte(1) ); }

  if( LOOPER_STATE_PLAY == true) { MIDI_BCR2000.sendControlChange( byte(62), byte(127), byte(1) ); }
  else { MIDI_BCR2000.sendControlChange( byte(62), byte(0), byte(1) ); }

  MIDI_BCR2000.sendControlChange( byte(57), byte(0), byte(1) );
  MIDI_BCR2000.sendControlChange( byte(58), byte(0), byte(1) );
  MIDI_BCR2000.sendControlChange( byte(60), byte(0), byte(1) );
  MIDI_BCR2000.sendControlChange( byte(64), byte(0), byte(1) );
  MIDI_BCR2000.sendControlChange( byte(65), byte(0), byte(1) );
  MIDI_BCR2000.sendControlChange( byte(66), byte(0), byte(1) );
  return;
}




void BCR2000_Init_Current_Preset_Controls_Values ( )
{
    ///////////////////////////////////////
    //   INITIALISATION OF THE BCR2000   //
    ///////////////////////////////////////

    // All 32 encoders + 8 push Buttons on top encoders 
    for(int i=1; i <= 40 ; i++) { MIDI_BCR2000.sendControlChange( byte(i), byte(0), byte(1) ); }

    // 4 user buttons (Bottom right)
    for(int i=1; i <= 4 ; i++)  { MIDI_BCR2000.sendControlChange( byte(66+i), byte(0), byte(1) ); }
}



void BCR2000_ManageCC ( byte CC_channel, byte CC_number, byte CC_value )
{
  
  long OutputValue, OutputValue1, Target_Effect_ID = 0, Target_CS_Effect_NumSel_State =0;
  int CC_number_dec, CC_value_dec, tempo, Index_In_Mapping, Changeto_Effect_Index = 0;


  static int Last_Index_In_Mapping;

  // Fixed part of the SYSEX //AXE-FX 2 specific
  sysex_mes[0]= 0x00;
  sysex_mes[1]= 0x01; // Manufacturer ID MSB - Fractal Audio Manufacturer ID Most Significant Byte
  sysex_mes[2]= 0x74; // Manufacturer ID LSB - Fractal Audio Manufacturer ID Least Significant Byte
  sysex_mes[3]= 0x03; // Model ID Byte - Specific byte assigned to the Fractal Audio product - AXE-FX II by default

  CC_number_dec = (int) CC_number;
  CC_value_dec = (int) CC_value;
  
#ifdef DEBUG3
  // PRINT OUT CC VALUES RECEIVED FROM THE BCR2000 
  Serial.print(F("CHANNEL: ")); Serial.print(CC_channel, DEC);
  Serial.print(F("  Received CC:  Number: ")); Serial.print(CC_number, HEX); Serial.print(F(" ("));Serial.print(CC_number_dec, DEC); Serial.print(F(")"));
  Serial.print(F("  Value: "));  Serial.print(CC_value, HEX);Serial.print(F(" ("));Serial.print(CC_value_dec, DEC); Serial.print(F(")"));
  Serial.println();
#endif    

  if ( CC_channel == BCR2000_MIDI_CHANNEL ) 
  {
    int BCR2000_Preset_Index = CC_number_dec - 40;
    boolean PB16_state_change = false;





    ////////////////////////////////////////////////////////////////////////////////////
    // HANDLE PARAMETER VALUE CHANGE ASK BY BCR2000 (USER)
    ////////////////////////////////////////////////////////////////////////////////////
#ifdef DEBUG
    Serial.print(F("Before Handle PARAMETER VALUE CHANGE")); 
    Serial.println();
#endif    


    if( CUSTOMIZE_STATE == true )
    {
    	if (  !(CC_number_dec >= 1  && CC_number_dec <= 40) and CC_number_dec != BCR2000_CUSTOMIZE_CC_DEFINE ) 
        {return;}
        
	// Process customization of the 32 encoders/8 encoder buttons for the Effect Control Page
        
    }


    // CUSTOMIZE button has been preset
    if (  CC_number_dec == BCR2000_CUSTOMIZE_CC_DEFINE )
    {
      if( CUSTOMIZE_STATE == false )
      { 
      	// Make sure that the current page is an Effect Control Page or Quick Access pages
	
	if test OK
	CUSTOMIZE_STATE = true; 
	Light up the Button
	
	
	if not 
	CUSTOMIZE_STATE = false;
      	Light down the Button
      	endif	
      }
      else 
      { 
      	CUSTOMIZE_STATE = false;  
      	Light down the Button
      }
      
      return;
    }



    // Check CC number in range
    if (  CC_number_dec >= 1  && CC_number_dec <= 40 )
    {
      CC_number_dec = CC_number_dec - 1; //Received CC range from 1 to 40 where Index range from 0 to 39
     
      Index_In_Mapping = CC_number_dec ;
      if ( CC_number != 0x11) // ENCORER n°41 sending CC message 17 does not work
      {
         Last_Index_In_Mapping = CC_number_dec;
      }
      else {
        Index_In_Mapping = Last_Index_In_Mapping;
      }

#ifdef DEBUG
            Serial.print("Index_In_Mapping = "); Serial.print( Index_In_Mapping, DEC);
            Serial.println(";");  
#endif

      // FLASH ON LED to mark message being processed
      digitalWrite(parValueLedPin, HIGH);


      ////////////////////////////////////////////
      // CALCULATE VALUE TO BE SENT TO THE AXE-FX
      ////////////////////////////////////////////
      if ( Axe_Fx_Type != 0x03 )
      {
        // CASE AXE-FX STANDARD and ULTRA
        //Process value
        ratio = (float) CC_value /127;
        OutputValue = ratio*254;     
        HB = (byte) OutputValue / 16;
        LB = OutputValue - HB * 16; 
      }
      else {
        // CASE AXE-FX II
        int addr = CS_Preset_Number * (BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER) + Index_In_Mapping;
        byte Btempo = EEPROM.read(addr);
        struct DYN_Parameter THE_Parameter;
        byte CS_Effect_Type_used = CS_Effect_Type-2;
        Read_Parameter_FromFLASH( (byte) CS_Effect_Type_used, Btempo, &THE_Parameter );

#ifdef DEBUG
            Serial.print("PROGMEM ACCESS: CS_Preset_Number = "); Serial.print( CS_Preset_Number, DEC);
            Serial.print(",  THE_Parameter.type = "); Serial.print( THE_Parameter.type, DEC);
            Serial.println(";");
#endif

       // TEST IF THE PARAMETER id the subType PARAM 
       // If YES log event and "wait" for 200 ms
       // if 200 ms lasted do what subtype change
       if(  Btempo == CurrentControlPage_EffectType.subTypeParamID && CurrentControlPage_EffectType.subTypeParamID != -1 )
       {
          if( typeDelay_millisElapsed == false)
          {
            //Serial.println("START EVENT EFFET TYPE CHANGE");
            typeDelay_CC_channel = CC_channel;
            typeDelay_CC_number = CC_number;
            typeDelay_CC_value = CC_value;
            typeDelay_lastType = CS_Effect_Type;

            typeDelay_lastTime = millis();
            typeDelay_typeEvent = true;
            send_uvga_Z( Index_In_Mapping, CC_value, CC_value );
            return;
          }
          else {
            // ase typeDelay_millisElapsed == TRUE
            //Serial.println("END OF EVENT");
            typeDelay_millisElapsed = false;
            typeDelay_typeEvent = false;
          }
       }


        if(    THE_Parameter.type != AXEFX_INT_Parameter_Type_DEFINE
            && THE_Parameter.type != AXEFX_INTXL_Parameter_Type_DEFINE  ) // Test NOT type = INT or INTXL --> Modal
        {
          //Process value
          ratio = (float) CC_value /127;
          OutputValue = ratio*65536; 
          OutputValue1 = OutputValue;    
          tempo = OutputValue / (128 * 128);
          HB = byte( tempo );
          OutputValue = OutputValue - (HB * 128 * 128);
          tempo = OutputValue / 128;
          MB = byte( tempo );
          OutputValue = OutputValue - (MB * 128 );
          LB = OutputValue ;

        }
        else {
          // MODAL value
          HB = 0x00;
          MB = 0x00;
          LB = CC_value;  // Currently the BCR2000 is set to send CCs with values up to 127.
                          // TODO : allow higher values, useful for AMP TYPE param 
        }
        
        // WRITE to LCD
        char buffer [30];
        strcpy( buffer, THE_Parameter.label);
#ifdef DEBUG
          Serial.print("THE_Parameter.label = ");Serial.println( buffer );
#endif
        
#ifndef ELECTRONIE_PROTO
        lcd.clear();
        lcd.print( F("CP: ") );
        lcd.print( buffer );
        lcd.setCursor(0, 1);
          if(    THE_Parameter.type != AXEFX_INT_Parameter_Type_DEFINE
              && THE_Parameter.type != AXEFX_INTXL_Parameter_Type_DEFINE  )
               { lcd.print(CC_value, DEC);}
          else {
            /*if( THE_Parameter.idListVal != -1) 
            {
              char buffer[30];
              Read_ModalList_FromFLASH( THE_Parameter.idListVal, ????????)
              //strcpy( buffer, (char*) pgm_read_word( &(DISTORT_TYPE_MODALITIES[CC_value])  ) );
              lcd.print( buffer);
            }*/
          }
#endif
      } 


#ifdef DEBUG
      Serial.print(F("CC_value: ")); Serial.print(CC_value); Serial.print(F(";  ")); 
      Serial.print(F("Index_In_Mapping: ")); Serial.print(Index_In_Mapping); Serial.print(F(";  ")); 
      Serial.print(F("ratio: ")); Serial.print(ratio); Serial.print(F(";  ")); 
      Serial.print(F("OutputValue: ")); Serial.print(OutputValue1); Serial.print(F(";  "));
      Serial.print(F("LB: ")); Serial.print(LB, HEX); Serial.print(F(";  "));
      Serial.print(F("MB: ")); Serial.print(MB, HEX); Serial.print(F(";  "));  
      Serial.print(F("HB: ")); Serial.print(HB, HEX);
      Serial.println(F(";"));Serial.println();
#endif  
//*/

      //////////////////////////////////////////////
      // CONSTRUCTION DU SYSEX A ENVOYER A L'AXE-FX
      //////////////////////////////////////////////
      // TODO : PROGRAM AXE-FX ULTRA and STANDARD CASE
      if ( Axe_Fx_Type == 0x03 )
      {
        // AXE-FX 2
        sysex_mes[3]= 0x03;
        sysex_mes[ 4 ] = 0x02; // ID od MIDI_SET_PARMETER function
        if ( CS_Effect_ID < 0x80 )
        {
          sysex_mes[5] = CS_Effect_ID;
          sysex_mes[6] = 0x00;
        }
        else {
          sysex_mes[5] = CS_Effect_ID - 0x80;
          sysex_mes[6] = 0x01;
        } 
        //sysex_mes[5]= CS_Effect_ID; //0xdd effect ID LS nibble  --> AMP1
        //sysex_mes[6]= 0x00; //0xdd effect ID MS nibble  --> AMP1
        int addr = CS_Preset_Number * (BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER) + Index_In_Mapping;
        byte Btempo = EEPROM.read(addr);

        sysex_mes[7]= Btempo;
        sysex_mes[8]= 0x00; // 0xdd parameter ID MS nibble  --> DRIVE
        sysex_mes[9]= LB;      
        sysex_mes[10]= MB;
        sysex_mes[11]= HB;
        sysex_mes[12]= 0x01;  // 0xdd query(0) or set(1) value
        sysex_mes[13] =Calculate_CheckSum( sysex_mes, SIZE_OF_SISEX_FOR_PARAM+1);

        MIDI_AXE.sendSysEx( byte( SIZE_OF_SISEX_FOR_PARAM + 2 ), sysex_mes, false ); 

        //Send the untranslated value of the MIDI CC message
#ifdef DEBUG2
          Serial.print(F(" Index_In_Mapping = ")); Serial.println( Index_In_Mapping, DEC);
          Serial.print(F(" CC_value = ")); Serial.println( CC_value, DEC);
#endif
        
        byte CS_Effect_Type_used = CS_Effect_Type-2;
        struct DYN_Parameter THE_Parameter;
        float DisplayValue;
        
        Read_Parameter_FromFLASH( (byte) CS_Effect_Type_used, Btempo, &THE_Parameter );
        if(    THE_Parameter.type != AXEFX_INT_Parameter_Type_DEFINE
            && THE_Parameter.type != AXEFX_INTXL_Parameter_Type_DEFINE  ) // test not type = INT --> Modal
        {
          DisplayValue = THE_Parameter.minDispValue + (THE_Parameter.maxDispValue - THE_Parameter.minDispValue) * (ratio);
        }
        else {
          DisplayValue = LB;
        }
        send_uvga_Z( Index_In_Mapping, CC_value, DisplayValue );
#ifdef DEBUG3        
        Serial.println(F("Sending Z message"));
        Serial.print(F("Index_In_Mapping = "));Serial.println(Index_In_Mapping, DEC);
        Serial.print(F("CC_value = "));Serial.println(CC_value, DEC);
        Serial.print(F("DisplayValue = "));Serial.println(DisplayValue, DEC);
#endif

        if( Btempo == CurrentControlPage_EffectType.subTypeParamID && CurrentControlPage_EffectType.subTypeParamID != -1 )
        {
          CS_Loaded = false;
          CountReceivedParam = 0;
          for(int k=0 ; k < BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER ; k++) { CP_Initial_Param_Value_received[k] = 0; }
          Get_Send_Param_Values();
          Display_Control_Page();
          send_uvga_D( 41 , 41, 41 );
        }

      }
   
   
   
   
#ifdef DEBUG
      Serial.print(F("SYSEX MESSAGE    "));
      for ( int i=0 ; i< SIZE_OF_SISEX_FOR_PARAM + 2 ; i++ ) 
      {
        Serial.print(sysex_mes[i], HEX);
        Serial.print(F(" "));
      }
      Serial.println();
#endif
//*/
      // FLASH OFF LED to mark end of processing
      digitalWrite(parValueLedPin, LOW);
      
    }  //ENFofIF in range


/*    //Change the assignment of the last moved encoder
    if( CC_number_dec == 32)
    {
#ifdef DEBUG
    Serial.print("ENCODER ASSIGNEMENT CHANGE"); 
    Serial.println("");
#endif
      // TEMPORARY
      // Test if AMP block selected and if the last moved input is an encoder
      if( CS_Preset_Number == 4 && Last_Index_In_Mapping <= 32)
      {
        // Test if CC_Value is in the range
        if ( CC_value < 80 )
        {
          // Assign the value
          int addr = CS_Preset_Number * (BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER) + Last_Index_In_Mapping;
          EEPROM.write(addr, byte( CC_value ) );
          lcd.clear();
          lcd.print("Encoder n° "); 
          lcd.print(Last_Index_In_Mapping, DEC);
          lcd.print("--> ");
          lcd.setCursor(0, 1);
          char buffer[30];
          strcpy_P( buffer, (char*) pgm_read_word( &(DISTORT_PARAMETERS[CC_value])  ) );
          lcd.print( buffer);
          //lcd.print(CC_value, DEC);
        } 
      }
    }
*/




    if( CC_number_dec == 57 || CC_number_dec == 58 || CC_number_dec == 60 || CC_number_dec == 64 )
    {
      // TODO : ADD the fonctions
      MIDI_BCR2000.sendControlChange( byte(57), byte(0), byte(1) );
      MIDI_BCR2000.sendControlChange( byte(58), byte(0), byte(1) );
      MIDI_BCR2000.sendControlChange( byte(60), byte(0), byte(1) );
      MIDI_BCR2000.sendControlChange( byte(64), byte(0), byte(1) );
      
      if( CC_number_dec == 64 )
      {
#ifdef DEBUG6
      Serial.println(F("send_uvga_1 message sent"));
#endif 
        send_uvga_1();
      }

      
      return;
    }


    
    // LOOPER MODE EXIT
    if( CC_number_dec == 63 && LOOPER_STATE == true)
    {
      LOOPER_STATE = false;
      Change_BCR2000_Preset( CS_Preset_Number +1, false);
      MIDI_BCR2000.sendControlChange( byte(41), byte(0), byte(1) );
      MIDI_BCR2000.sendControlChange( byte(40+CS_BCR2000_ACTIVE_BUTTON), byte(127), byte(1) );
#ifdef DEBUG4
      Serial.println();Serial.println();
      Serial.println(F("LOOPER EXIT"));
      Serial.print(F("CS_BCR2000_ACTIVE_BUTTON = "));Serial.println(CS_BCR2000_ACTIVE_BUTTON, DEC);  //line feed
      Serial.println();Serial.println();  //line feed
#endif 
      return;
    }
    
    ///////////////////////////// GOTO LOOPER page ////////////////////////////////
    if (  CC_number_dec == 63 && LOOPER_STATE == false)
    {
      LOOPER_STATE = true;

      // BCR2000 preset change
      //Change_BCR2000_Preset( 0x1F, false); // go to preset number 31

      // Set all push buttons to off apart from the one that has been pressed by the user - DOes not apply if button 16 has been pressed
      for(int i=1 ; i < 16 ; i++)
      {
        MIDI_BCR2000.sendControlChange( byte(40+i), byte(0), byte(1) );  //les numéros change un fois sur le preset 
      }
      // THE FIRST BUTTON IN THE FIRST ROW STAYS ON
      MIDI_BCR2000.sendControlChange( byte(41), byte(127), byte(1) );
#ifdef DEBUG4
  Serial.println();Serial.println();
  Serial.print(F("ENTERING LOOPER"));
  Serial.println();Serial.println();  //line feed
#endif 
      return;
    }

    ///////////////////////////// HANDLE CC OF LOOPER PAGE ////////////////////////////////
    if ( LOOPER_STATE == true || CC_number_dec == 61 || CC_number_dec == 62)
    {
#ifdef DEBUG4
  Serial.println();Serial.println();
  Serial.print(F("HANDLING LOOPER EVENTS"));
  Serial.println();Serial.println();  //line feed
#endif 

/*      if (LOOPER_STATE == false && ( (CC_number_dec >= 49 && CC_number_dec <= 56) || CC_number_dec >= 41  ) )
      {
          if (LOOPER_STATE_RECORD == false) { MIDI_BCR2000.sendControlChange( byte(61), byte(0), byte(1) ); } 
          else { MIDI_BCR2000.sendControlChange( byte(61), byte(127), byte(1) ); }
          if (LOOPER_STATE_PLAY == false) { MIDI_BCR2000.sendControlChange( byte(62), byte(0), byte(1) ); } 
          else { MIDI_BCR2000.sendControlChange( byte(62), byte(127), byte(1) ); }
      }
      else {
*/  
        // Check if the button/encoder received is active
        if( CC_number_dec >= 41 || CC_number_dec == 61 || CC_number_dec == 62 ||
            ( CC_number_dec >= 49 && CC_number_dec <= 56 ) )
        {
          //  BUTTON 1 stays ON
          if ( CC_number_dec == 41) 
          {
            MIDI_BCR2000.sendControlChange( byte(41), byte(127), byte(1) );
          }
          //RECORD pressed
          if ( CC_number_dec == 49 || CC_number_dec == 61 ) 
          {
            // CC 28 is the default mapping CC for LOOPER RECORD
            if (LOOPER_STATE_RECORD == false) 
            {
              LOOPER_STATE_RECORD = true; 
              MIDI_AXE.sendControlChange( byte(28) , byte(127), byte(12) );
              if( LOOPER_STATE_PLAY == true)
              {
                LOOPER_STATE_PLAY = false;
                if (CC_number_dec == 49) { MIDI_BCR2000.sendControlChange( byte(50), byte(0), byte(1) ); }
                if (CC_number_dec == 61) { MIDI_BCR2000.sendControlChange( byte(62), byte(0), byte(1) ); }              
              }
            }
            else {
              LOOPER_STATE_RECORD = false;
              MIDI_AXE.sendControlChange( byte(28) , byte(0), byte(12) );
              if (CC_number_dec == 49) { MIDI_BCR2000.sendControlChange( byte(50), byte(127), byte(1) ); }
              if (CC_number_dec == 61) { MIDI_BCR2000.sendControlChange( byte(62), byte(127), byte(1) ); }
              LOOPER_STATE_PLAY = true;
            }
          }
          //PLAY pressed
          if ( CC_number_dec == 50 || CC_number_dec == 62 ) 
          {
            // CC 29 is the default mapping CC for LOOPER PLAY
            if (LOOPER_STATE_PLAY == false) 
            { 
              LOOPER_STATE_PLAY = true;
              LOOPER_STATE_RECORD = false;
              MIDI_AXE.sendControlChange( byte(29) , byte(127), byte(12) );
              if (CC_number_dec == 50) { MIDI_BCR2000.sendControlChange( byte(49), byte(0), byte(1) ); } // OFF the RECORD button if on
              if (CC_number_dec == 62) { MIDI_BCR2000.sendControlChange( byte(61), byte(0), byte(1) ); } // OFF the RECORD button if on
            }
            else {
              LOOPER_STATE_PLAY = false;
              MIDI_AXE.sendControlChange( byte(29) , byte(0), byte(12) ); 
              MIDI_BCR2000.sendControlChange( byte(62), byte(0), byte(1) ); // OFF the PLAY button
            } 
          }        
          //ONCE pressed
          if ( CC_number_dec == 51) 
          {
            // CC 30 is the default mapping CC for LOOPER ONCE
            if (LOOPER_STATE_ONCE == false) 
            { MIDI_AXE.sendControlChange( byte(30) , byte(127), byte(12) ); LOOPER_STATE_ONCE = true;}
            else {MIDI_AXE.sendControlChange( byte(30) , byte(0), byte(12) ); LOOPER_STATE_ONCE = false;}      
          }
          //DUB pressed
          if ( CC_number_dec == 52) 
          {
            // CC 28 is the default mapping CC for LOOPER RECORD
            if (LOOPER_STATE_DUB == false) 
            { MIDI_AXE.sendControlChange( byte(31) , byte(127), byte(12) ); LOOPER_STATE_DUB = true;}
            else {MIDI_AXE.sendControlChange( byte(31) , byte(0), byte(12) ); LOOPER_STATE_DUB = false;}    
          }
          //REVERSE pressed
          if ( CC_number_dec == 53) 
          {
            // CC 121 is the default mapping CC for LOOPER UNDO
            if (LOOPER_STATE_REVERSE == false) 
            { MIDI_AXE.sendControlChange( byte(32) , byte(127), byte(12) ); LOOPER_STATE_REVERSE = true;}
            else {MIDI_AXE.sendControlChange( byte(32) , byte(0), byte(12) ); LOOPER_STATE_REVERSE = false;}     
          }        
          //UNDO pressed
          if ( CC_number_dec == 54) 
          {
            // CC 121 is the default mapping CC for LOOPER UNDO
            if (LOOPER_STATE_UNDO == false) 
            { MIDI_AXE.sendControlChange( byte(121) , byte(127), byte(12) ); LOOPER_STATE_UNDO = true;}
            else {MIDI_AXE.sendControlChange( byte(121) , byte(0), byte(12) ); LOOPER_STATE_UNDO = false;}          
          } 
          //HALF pressed
          if ( CC_number_dec == 55) 
          {
            // CC 120 is the default mapping CC for HALF
            if (LOOPER_STATE_UNDO == false) 
            { MIDI_AXE.sendControlChange( byte(120) , byte(127), byte(12) ); LOOPER_STATE_UNDO = true;}
            else {MIDI_AXE.sendControlChange( byte(120) , byte(0), byte(12) ); LOOPER_STATE_UNDO = false;}          
          } 
          //METRO pressed
          if ( CC_number_dec == 56) 
          {
            // CC 122 is the default mapping CC for METRO (Metronome)
            if (LOOPER_STATE_UNDO == false) 
            { MIDI_AXE.sendControlChange( byte(122) , byte(127), byte(12) ); LOOPER_STATE_UNDO = true;}
            else {MIDI_AXE.sendControlChange( byte(122) , byte(0), byte(12) ); LOOPER_STATE_UNDO = false;}          
          } 
          
          /* NO CC for these for now  --> TODO use SYSEX 
          //QUANTIZE pressed
          if ( CC_number_dec == 112) 
          {
            // CC 121 is the default mapping CC for LOOPER UNDO
            if (LOOPER_STATE_UNDO == false) 
            { MIDI_AXE.sendControlChange( byte(121) , byte(127), byte(1) ); LOOPER_STATE_UNDO = true}
            else {MIDI_AXE.sendControlChange( byte(127) , byte(0), byte(1) ); LOOPER_STATE_UNDO = false}          
          } 
          //THRESH pressed
          if ( CC_number_dec == 113) 
          {
            // CC 121 is the default mapping CC for LOOPER UNDO
            if (LOOPER_STATE_UNDO == false) 
            { MIDI_AXE.sendControlChange( byte(121) , byte(127), byte(1) ); LOOPER_STATE_UNDO = true}
            else {MIDI_AXE.sendControlChange( byte(127) , byte(0), byte(1) ); LOOPER_STATE_UNDO = false}          
          } */   
          
          // MANAGE ON-BYPASS STATE
        }
      //}
      return;  
    }



    /////////////////////////////////// Push button SHIFT is managed on its own and its state memorised ////////////////////////////////
    if ( CC_number_dec == 59) 
    {
      PB16_state_change = true; 
      if ( CC_value_dec == 127 )  { PB16_state = true;} else { PB16_state = false;}
      // Push button 16 is state is maintained in between presets
    } 
 
#ifdef DEBUG3
    Serial.print(F("PB16_state_change = "));Serial.print(PB16_state_change, BIN); Serial.println("");
    Serial.print(F("PB16_state = "));Serial.print(PB16_state, BIN); Serial.println("");
    Serial.print(F("BCR2000_Preset_Index = CC_number_dec - 40 = "));Serial.print(BCR2000_Preset_Index, DEC); Serial.println();
    //Serial.print(F("Before Handle 16 PB state")); Serial.println();
     Serial.println();
#endif 

    //////////////////////////////////// HANDLE other 16 ON/OFF BUTTONS STATE //////////////////////////////////////////////////////
    if ( ( CC_number_dec >= 41 && CC_number_dec <= 56 ) ||  PB16_state_change == true )
    {
      int OffSet;
      int  Changeto_Effect_Index = 0;
      boolean Effet_Type_Present = false;
      
      // If the 16 button is ON add 16 have Preset selected by the user
      if ( PB16_state == true ) { OffSet = 16;}
      else { OffSet = 0;}

#ifdef DEBUG3
      Serial.print(F("CS_Preset_Number = "));Serial.print(CS_Preset_Number, DEC); Serial.println();
      Serial.print(F("BCR2000_Preset_Index preset before taking into account last action = "));Serial.print(BCR2000_Preset_Index, DEC); Serial.println();
      Serial.println();
#endif


      // BCR2000 preset change
      if (PB16_state_change == true ) {
          if( CC_value_dec == 127 ) { BCR2000_Preset_Index = CS_Preset_Number+1 + OffSet; }
          else { BCR2000_Preset_Index = CS_Preset_Number+1 - 16; }
      }
      else { BCR2000_Preset_Index =  BCR2000_Preset_Index + OffSet; }
      
      
      Change_BCR2000_Preset( BCR2000_Preset_Index, false);
      CS_Preset_Number = BCR2000_Preset_Index -1;
#ifdef DEBUG3
      Serial.print(F("CS_Preset_Number = "));Serial.print(CS_Preset_Number, DEC); Serial.println();
      Serial.print(F("Change to BCR2000_Preset_Index = "));Serial.print(BCR2000_Preset_Index, DEC); Serial.println();
      Serial.println();
#endif

      if( PB16_state == true)
      {  MIDI_BCR2000.sendControlChange( byte(59), byte(127), byte(1) ); }
      else { MIDI_BCR2000.sendControlChange( byte(59), byte(0), byte(1) ); }


      // Check that the target Control Page is associated to an effect present in the CurrentPreset of the AXE 
      if ( CC_value_dec == 127 || PB16_state_change == true )
      {
        for(int i=0; i < CP_Number_Effects ; i++)
        {
#ifdef DEBUG
          Serial.print(F("Preset ")); Serial.print( BCR2000_Preset_Index - 1 , DEC);
          Serial.print(F("  Index_Effect_Type ")); Serial.print(i, DEC);
          Serial.print(F("  TYPE "));Serial.print(CP_Effect_Type[ i ], DEC);
          Serial.println();  //line feed
#endif          
          if( CP_Effect_Type[ i ] == ControlPages_USER_Mapping[ BCR2000_Preset_Index - 1 ])
          {
            Effet_Type_Present = true;
#ifdef DEBUG3
            Serial.print(F("Preset FOUND ")); Serial.print( BCR2000_Preset_Index - 1 , DEC);
            Serial.print(F("  Index_Effect_Type in the Ordered list of Effect Block of the Current Preset = ")); Serial.print(i, DEC);
            Serial.print(F("  TYPE = "));Serial.print(CP_Effect_Type[ i ], DEC);
            Serial.println();  //line feed
#endif
            break;
          }      
        }
#ifdef DEBUG3
        Serial.print(F("Effet_Type_Present = "));Serial.print(Effet_Type_Present, DEC); Serial.println();
#endif
        // Set all push buttons to off
        for(int i=1; i <= 16 ; i++) { MIDI_BCR2000.sendControlChange( byte(40+i), byte(0), byte(1) ); }
     
        if (  CC_number_dec >= 41 && CC_number_dec <= 56 || PB16_state_change == true )
        {
          // Apart from the one that should be ON if any
          if ( PB16_state_change == false )
          {
            if ( Effet_Type_Present == true ) 
            {
              MIDI_BCR2000.sendControlChange( CC_number, byte(127), byte(1) );
              if (PB16_state == false) { CS_BCR2000_ACTIVE_BUTTON = BCR2000_Preset_Index;}
              else { CS_BCR2000_ACTIVE_BUTTON = BCR2000_Preset_Index - OffSet;}
            }
            else { CS_BCR2000_ACTIVE_BUTTON = 0; }
          }
          else {
            if( Effet_Type_Present == true )
            { 
#ifdef DEBUG3
              Serial.print(F("CS_BCR2000_ACTIVE_BUTTON = ")); Serial.print(CS_BCR2000_ACTIVE_BUTTON, DEC); Serial.println();
#endif
              CS_BCR2000_ACTIVE_BUTTON = BCR2000_Preset_Index - OffSet;
              MIDI_BCR2000.sendControlChange( 40 + CS_BCR2000_ACTIVE_BUTTON, byte(127), byte(1) );
              //CS_BCR2000_ACTIVE_BUTTON == CC_
              //if ( CC_value_dec == 127 )
              //{ CS_BCR2000_ACTIVE_BUTTON = CS_BCR2000_ACTIVE_BUTTON; }
              //else { CS_BCR2000_ACTIVE_BUTTON = CS_BCR2000_ACTIVE_BUTTON - OffSet; }
            }
            else { CS_BCR2000_ACTIVE_BUTTON = 0; }
          }
          //////////////////////////////////////////
          // Load CP parameter value of the preset
          /////////////////////////////////////////
          // Retrieve index of first effect in the CP that matches the effect type of the selected BCR2000 preset
          for( int j=0; j < CP_Number_Effects ; j++)
          {
#ifdef DEBUG
            Serial.print(F("j = "));Serial.print(j, DEC); Serial.println("");
            Serial.print(F("CP_Effect_BCR_Preset [ j ] = "));Serial.print(CP_Effect_BCR_Preset [ j ], DEC); Serial.println();
#endif
            if( CP_Effect_BCR_Preset [ j ] == BCR2000_Preset_Index -1 )
            {
              Changeto_Effect_Index = j;
#ifdef DEBUG3
              Serial.print(F("BCR2000_Preset_Index -1 = "));Serial.print(BCR2000_Preset_Index -1, DEC); Serial.println();            
              Serial.print(F("Changeto_Effect_Index = "));Serial.print(Changeto_Effect_Index, DEC); Serial.println();
              Serial.print(F("CP_Effect_BCR_Preset [ j ] = "));Serial.print(CP_Effect_BCR_Preset [ j ], DEC); Serial.println();
              Serial.print(F("CS_BCR2000_ACTIVE_BUTTON = "));Serial.print(CS_BCR2000_ACTIVE_BUTTON, DEC); Serial.println();
              Serial.println();
              Serial.println();
#endif
              break;
            }
          }

          // CURRENT STATE
          if (Effet_Type_Present == true )
          {
            StartParamLoading( Changeto_Effect_Index );
            //delay(50);      
            //Display_Control_Page();
          }
        } 
      }
      // For push button 1 to 15 refuse to turn off active button (preset) if pressed again by user
      if ( CC_value_dec == 0 && CC_number_dec != 59) { MIDI_BCR2000.sendControlChange( byte(CC_number_dec), byte(127), byte(1) ); }
      else{
        if( Effet_Type_Present == false) { BCR2000_Init_Current_Preset_Controls_Values( ); }
      }
    }
    
    
    
    

    ////////////////////////////////////////////
    ////////////////////////////////////////////
    ////////////////////////////////////////////
    ////// HANDLE SCENE- and SCENNE + buttons
    ////////////////////////////////////////////
    ////////////////////////////////////////////
    ////////////////////////////////////////////

    if( (CC_number_dec == 65 || CC_number_dec == 66) && Axe_Fx_Type == 0x03 && Axe_Fx_Version >= 9)
    {
      boolean SEND = false;
      if (CurentPreset_CurrentSCENE_Number == -1) 
      {
        //Serial.print("ERROR: SCENE number was not received");
        // TODO: SEND ERROR MESSAGE TO SCREEN
      }
      
      if( CC_number_dec == 65 && CurentPreset_CurrentSCENE_Number > 0)    { CurentPreset_CurrentSCENE_Number--; SEND = true;}

      if( CC_number_dec == 66 && CurentPreset_CurrentSCENE_Number < 7)    { CurentPreset_CurrentSCENE_Number++; SEND = true;}

      if( SEND == true)
      {
        // AXE-FX II specific
        
        sysex_mes[4] = 0x29;  // SYSEX Function = Change SCENE
        sysex_mes[5] = CurentPreset_CurrentSCENE_Number;
        sysex_mes[6] = Calculate_CheckSum( sysex_mes, 6);
        MIDI_AXE.sendSysEx( byte( 7 ), sysex_mes, false );
        
        sysex_mes[4]= 0x0E;  // SYSEX Function = Query state of current preset
        sysex_mes[5] = Calculate_CheckSum( sysex_mes, 5); 
        MIDI_AXE.sendSysEx( byte( 6 ), sysex_mes, false );
      }
        
    }









    ////////////////////////////////////////////
    ///////////////////////
    /////////////////////
    ////////////////////////////////////////////
    // HANDLE the 4 "Effect states" push buttons
    ////////////////////////////////////////////
    ////////////////////////////////////////////
    ////////////////////////////////////////////

#ifdef DEBUG
    Serial.print(F("Before Handle 4 PB state")); 
    Serial.println();
#endif     
    if ( CC_number_dec >= 67 && CC_number_dec <= 70 )
    {
/*#ifdef DEBUG
      Serial.print("ENTER Handle CC message from 4 PB"); 
      Serial.println("");
#endif*/

      // XYSTATE change
      if ( CC_number_dec == 68 )
      {       
        for( int i=0; i < MAX_NUMBER_EFFECTS ;i++)
        {
          if(The_AXE_Effects [i].effect_id_hex == CS_Effect_ID && The_AXE_Effects[i].effect_xy_cc != 0)
          {
/*#ifdef DEBUG
      Serial.print("XYSTATE ="); Serial.print(CS_Effect_XYState, DEC);
      Serial.print("  CC = ");Serial.print(The_AXE_Effects[i].effect_xy_cc, DEC);
      Serial.print("  CS_Current_Effect_Number_In_CP = ");Serial.print(CS_Current_Effect_Number_In_CP, DEC);
      Serial.println("");
#endif*/           
            CS_Effect_XYState = ! CS_Effect_XYState;
            CP_Effect_XYState [ CS_Current_Effect_Number_In_CP ] = !CP_Effect_XYState [ CS_Current_Effect_Number_In_CP ];
            if ( CS_Effect_XYState == true )
                { MIDI_AXE.sendControlChange( The_AXE_Effects[i].effect_xy_cc, byte(127), byte(AXE_FX_CHANNEL) );}  // CASE X
            else{ MIDI_AXE.sendControlChange( The_AXE_Effects[i].effect_xy_cc, byte(0), byte(AXE_FX_CHANNEL) );}    // CASE Y
            StartParamLoading( CS_Current_Effect_Number_In_CP ); // Reload parameters for the same effect but other case (X or Y)
          }
        }
      }
      

      // OBSTATE change
      if ( CC_number_dec == 70 )
      { 
        for( int i=0 ; i < MAX_NUMBER_EFFECTS ; i++)
        {
          if(The_AXE_Effects[i].effect_id_hex == CS_Effect_ID && The_AXE_Effects[i].effect_onbypass_cc != 0)
          {
/*#ifdef DEBUG
      Serial.print("STATE ="); Serial.print(CS_Effect_OBState, DEC);
      Serial.print("ONBYPASS STATE");Serial.print(The_AXE_Effects[i].effect_onbypass_cc, DEC);
      Serial.println("");
#endif*/     
          CS_Effect_OBState = ! CS_Effect_OBState;
          CP_Effect_OBState [ CS_Current_Effect_Number_In_CP ] = !CP_Effect_OBState [ CS_Current_Effect_Number_In_CP ];
          // no need to send CC to BCR2000 --> Button state handled by BCR2000
          if ( CS_Effect_OBState == true )
                { MIDI_AXE.sendControlChange( The_AXE_Effects[i].effect_onbypass_cc, byte(127), byte(AXE_FX_CHANNEL) );}   // CASE ON
            else{ MIDI_AXE.sendControlChange( The_AXE_Effects[i].effect_onbypass_cc, byte(0), byte(AXE_FX_CHANNEL) );}     // CASE OFF
          }
        }
      }
      
      // Number in possible number of Effect type 
      if ( CC_number_dec == 67 || CC_number_dec == 69)
      {
      switch ( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type_Number + CS_Effect_Type ) )
      {
        case 1:
          Manage4EffectStateButtons( );
          break;
          
        case 2:
#ifdef DEBUG
      Serial.print(F("Case = 2"));
      Serial.print(F("  CS_Effect_Type =")); Serial.print(CS_Effect_Type, DEC);
      Serial.println(); Serial.println();
#endif     
          // The 69 BP has no effect in that case
          if ( CC_number_dec == 67) 
          {
          for( int i=0 ; i < MAX_NUMBER_EFFECTS ; i++ )
          {
#ifdef DEBUG
            Serial.print(F("CS_Effect_Type = ")); Serial.print(CS_Effect_Type, DEC);
            Serial.print(F("  CS_Effect_ID = ")); Serial.print(CS_Effect_ID, DEC);
            Serial.print(F("  i = ")); Serial.print(i, DEC);
            Serial.print(F("   AXEFX_Effect_Type[ i ] = ")); Serial.print( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type + i ), DEC);
            Serial.print(F("   AXEFX_Effect_Type[ i+1 ] = ")); Serial.print( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type + (i+1) ), DEC);           
            Serial.print(F("   AXEFX_Effect_ID[ i ] = ")); Serial.print( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + i ), HEX);
            Serial.println(); Serial.println();
#endif
            if( CS_Effect_Type == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type + i ) )
            {        
              // Update the CS with the new effect ID  
              if(  CS_Effect_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + i )
                 &&  CS_Effect_Type == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type + (i+1) ) )
              {
                // CASE 0 TO 1      
                Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + (i+1) );
                Target_CS_Effect_NumSel_State = 1;
              }
              else {
                // CASE 1 TO 0
                Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + i );
                Target_CS_Effect_NumSel_State = 0;
              }

#ifdef DEBUG
            Serial.print(F("Target_Effect_ID = ")); Serial.print(Target_Effect_ID, HEX);
            Serial.print(F("  Target_CS_Effect_NumSel_State = ")); Serial.print(Target_CS_Effect_NumSel_State, DEC);
            Serial.println(); Serial.println();
#endif//*/               
              // Search for target effect ID in the list of effect of the current preset
              // If not found --> Do nothing
              for( int j=0 ; j < CP_Number_Effects ; j++ )
              {
#ifdef DEBUG
            Serial.print(F("CP_Effect_ID[ j ] = ")); Serial.print(CP_Effect_ID[ j ], HEX);
            Serial.println(); Serial.println();
#endif//*/ 
                if ( CP_Effect_ID[ j ] == Target_Effect_ID)
                {
                  CS_Effect_NumSel_State = Target_CS_Effect_NumSel_State;
                  StartParamLoading( j );           
                  break;
                }
              } //ENDofFOR on j
              break;
            }
          } // ENDofFOR on i
          } // ENDofIF(ELSE)
          
          // In case 69 IS PRESSED THE state of the button on the BCR2000 needs to be set back to previous value
          Manage4EffectStateButtons();          
          break;
          
          
          
        case 4:
          for( int i=0 ; i < MAX_NUMBER_EFFECTS ; i++ )
          {
            if (  CS_Effect_Type == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type + i ) )
            {
              // SWITCH on the intial state of button 105 and 107
              switch(CS_Effect_NumSel_State)
              {
                case 0 : // 67 = OFF and 69 OFF
                  if ( CC_number_dec == 67)  // CASE 0 to 1 !!!
                  {
                    Target_CS_Effect_NumSel_State = 1;
                    Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + (i+1) ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                  }
                  if ( CC_number_dec == 69)  // CASE 0 to 2 !!!
                  {
                    Target_CS_Effect_NumSel_State = 2;
                    Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + (i+2) ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                  }
                  break;

                case 1 : // 67 = ON and 69 OFF
                  if ( CC_number_dec == 67)  // CASE 1 to 0 !!!
                  {
                    Target_CS_Effect_NumSel_State = 0;
                    Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + i ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                  }
                  if ( CC_number_dec == 69)  // CASE 1 to 3 !!!
                  {
                    Target_CS_Effect_NumSel_State = 3;
                    Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + (i+3) ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                  }
                  break;
              
                case 2 : // 67 = OFF and 69 ON
                  if ( CC_number_dec == 67)  // CASE 2 to 3 !!!
                  {
                    Target_CS_Effect_NumSel_State = 3;
                    Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + (i+3) ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                  }
                  if ( CC_number_dec == 69)  // CASE 2 to 0 !!!
                  {
                    Target_CS_Effect_NumSel_State = 0;
                    Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + i ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                  }
                  break;
                  
                case 3 : // 67 = ON and 69 ON
                  if ( CC_number_dec == 67)  // CASE 3 to 2 !!!
                  {
                    Target_CS_Effect_NumSel_State = 2;
                    Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + (i+2) ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                  }
                  if ( CC_number_dec == 69)  // CASE 3 to 1 !!!
                  {
                    Target_CS_Effect_NumSel_State = 1;
                    Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + (i+1) ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                  }
                  break;
              } // ENDofSWITCH on CS_Effect_NumSel_State
 
              // Search for target effect ID in the list of effect of the current preset
              for(int j=0;   j < CP_Number_Effects   ;j++)
              {
                if ( CP_Effect_ID[ j ] == Target_Effect_ID)
                {
                  CS_Effect_NumSel_State = Target_CS_Effect_NumSel_State;
                  StartParamLoading( j );
                  break;
                }
              } //ENDofFOR on j 
              break;
            } // ENDofIF
          }  //ENDofFOR on i            
          break; // END of CASE 4
          
        default:
          break; 
      }  // ENDofSWITCH
#ifdef DEBUG
      Serial.print("END OF SWITCH"); 
      Serial.println("");
#endif  
      }     
    }        
  } //END of IF channel


  // RECEIVING TEST CCs
  if( CC_channel == BCR2000_MIDI_CHANNEL && CC_number == MIDI_TEST_CC_SENT)
  {
    BCR2000_Received_CC_Value = CC_value;
    //Serial.print("Message : "); Serial.print(CC_value, DEC); Serial.print(" received");
  }

}










void Manage4EffectStateButtons( void )
{
      ///////////////////////////////////
      //MANAGE 4 EFFECT STATE BUTTONS
      //////////////////////////////////

      // Set all buttons OFF before sending states
      MIDI_BCR2000.sendControlChange( byte(67), byte(0), byte(1) );
      MIDI_BCR2000.sendControlChange( byte(68), byte(0), byte(1) );
      MIDI_BCR2000.sendControlChange( byte(69), byte(0), byte(1) );
      MIDI_BCR2000.sendControlChange( byte(70), byte(0), byte(1) );
      
      // Set On/Bypass indicator
      if ( CS_Effect_OBState == 1 )  //TEST IF EFFECT is ON 
      {MIDI_BCR2000.sendControlChange( byte(70), byte(127), byte(1) );}   // ON --> lighted
      else {MIDI_BCR2000.sendControlChange( byte(70), byte(0), byte(1) );}  // OFF --> not lighted
      // Set X/Y indicator
      if ( CS_Effect_XYState == 1 )  //TEST IF X IS SELECTED
      {MIDI_BCR2000.sendControlChange( byte(68), byte(0), byte(1) );}         // X --> not lighted
      else {MIDI_BCR2000.sendControlChange( byte(68), byte(127), byte(1) );}  // Y --> lighted   
      // Set Effect number for that type (AMP1 or AMP2)

#ifdef DEBUG
          Serial.print(F("CS_Effect_Type = ")); Serial.print(CS_Effect_Type, DEC);
          Serial.print(F("   AXEFX_Effect_Type_Number[CS_Effect_Type] = ")); Serial.print( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type_Number + CS_Effect_Type ), DEC);
          Serial.println();
#endif 
      switch ( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type_Number + CS_Effect_Type ) )
      {
        case 1:
          MIDI_BCR2000.sendControlChange( byte(67), byte(0), byte(1) );
          MIDI_BCR2000.sendControlChange( byte(69), byte(0), byte(1) );
          CS_Effect_NumSel_State = 0;
          break;
          
        case 2:
          for( int k=0; k < MAX_NUMBER_EFFECTS ; k++)
          {
/*#ifdef DEBUG
            Serial.print("CS_Effect_Type = "); Serial.print(CS_Effect_Type, DEC);
            Serial.print("  CS_Effect_ID = "); Serial.print(CS_Effect_ID, DEC);
            Serial.print("  k"); Serial.print(k, DEC);
            Serial.print("   AXEFX_Effect_Type[ k ] = "); Serial.print( AXEFX_Effect_Type[ k ] , DEC);           
            Serial.print("   AXEFX_Effect_ID[k] = "); Serial.print( AXEFX_Effect_ID[k], DEC);
            Serial.println("");
#endif*/ 
            if( CS_Effect_Type == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type + k ) )
            {             
              if( CS_Effect_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_ID + k ) )
              {
                // CASE 1 (displayed as 0)
                MIDI_BCR2000.sendControlChange( byte(67), byte(0), byte(1) );
                MIDI_BCR2000.sendControlChange( byte(69), byte(0), byte(1) );
                CS_Effect_NumSel_State = 0;
              }
              else {
                // CASE 2 (displayed as 1)
                MIDI_BCR2000.sendControlChange( byte(67), byte(127), byte(1) );
                MIDI_BCR2000.sendControlChange( byte(69), byte(0), byte(1) );
                CS_Effect_NumSel_State = 1;
              }
              break;
            }
          }            
          break;
          
        case 4:
          switch( CS_Effect_NumSel_State )
          {
            case 0:
                // CASE 1 (displayed as 0)
                MIDI_BCR2000.sendControlChange( byte(67), byte(0), byte(1) );
                MIDI_BCR2000.sendControlChange( byte(69), byte(0), byte(1) );
                break;

            case 1:
                // CASE 2 (displayed as 1)
                MIDI_BCR2000.sendControlChange( byte(67), byte(127), byte(1) );
                MIDI_BCR2000.sendControlChange( byte(69), byte(0), byte(1) );
                break;
  
            case 2:
                // CASE 3 (displayed as 2)
                MIDI_BCR2000.sendControlChange( byte(67), byte(0), byte(1) );
                MIDI_BCR2000.sendControlChange( byte(69), byte(127), byte(1) );
                break;
  
            case 3:
                // CASE 4 (displayed as 3)
                MIDI_BCR2000.sendControlChange( byte(67), byte(127), byte(1) );
                MIDI_BCR2000.sendControlChange( byte(69), byte(127), byte(1) );
              break;            
          }
          break;
          
          
        default:
          break; 
      }  // ENDofSWITCH

#ifdef DEBUG
      Serial.print("END OF SWITCH"); 
      Serial.println("");
#endif  
}


