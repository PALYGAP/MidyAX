/////////////////////////////////////////////////////////////////////////////////////////////////
// PROGRAM:     MidyAX - BCR2000 to AXE-FX MIDI communication orchestrator
// AIM:         Provide enhanced usability of the AXE-FX by making it possible to set the 
//              AXE-FX parameters with a hardware interface (knobs/switches of the BCR2000) 
// HARDWARE:    ARDUINO MEGA 128, 4 MIDI ports with a MIDI-IN and MIDI-OUT for each port.
// CREATOR:     Eric FEUILLEAUBOIS
// LICENSE:     GNU license v3 - That means OPEN SOFWARE, COPYLEFT and hope it's useful to you
/////////////////////////////////////////////////////////////////////////////////////////////////


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

  // Maintains the state of the SHIFT, RECORD and PLAY buttons
  if( SHIFT_PB__state == true)
  {  MIDI_BCR2000.sendControlChange( byte(BCR2000_SHIFT_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
  else { MIDI_BCR2000.sendControlChange( byte(BCR2000_SHIFT_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); }

  // TODO : Reactivate LOOPER page
  //if( LOOPER_STATE == true) { MIDI_BCR2000.sendControlChange( byte(BCR2000_CUSTOMIZE_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
  //else { MIDI_BCR2000.sendControlChange( byte(BCR2000_CUSTOMIZE_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); }
  
  if( LOOPER_STATE_RECORD == true) { MIDI_BCR2000.sendControlChange( byte(BCR2000_RECORD_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
  else { MIDI_BCR2000.sendControlChange( byte(BCR2000_RECORD_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); }

  if( LOOPER_STATE_PLAY == true) { MIDI_BCR2000.sendControlChange( byte(BCR2000_PLAY_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
  else { MIDI_BCR2000.sendControlChange( byte(BCR2000_PLAY_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); }

  // BCR2000 preset change --> these buttons go off 
  MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE1_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
  MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE2_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
  MIDI_BCR2000.sendControlChange( byte(BCR2000_VOLPAN_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
  MIDI_BCR2000.sendControlChange( byte(BCR2000_LOOPER_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
  MIDI_BCR2000.sendControlChange( byte(BCR2000_CUSTOMIZE_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
  MIDI_BCR2000.sendControlChange( byte(BCR2000_SPEC_FUNC_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
  return;
}




void BCR2000_Init_Current_Preset_Controls_Values ( void )
{
    ///////////////////////////////////////
    //   INITIALISATION OF THE BCR2000   //
    ///////////////////////////////////////

    // All 32 encoders + 8 push Buttons on top encoders 
    for(int i=1; i <= 40 ; i++) { MIDI_BCR2000.sendControlChange( byte(i), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); }

    // 4 user buttons (Bottom right)
	MIDI_BCR2000.sendControlChange( byte(BCR2000_XY_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
	MIDI_BCR2000.sendControlChange( byte(BCR2000_ONBYPASS_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
	MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect1_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
	MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect2_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
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
  
#if defined(DEBUG3) || defined(DEBUG8)
  // PRINT OUT CC VALUES RECEIVED FROM THE BCR2000 
  Serial.print(F("CHANNEL: ")); Serial.print(CC_channel, DEC);
  Serial.print(F("  Received CC:  Number: ")); Serial.print(CC_number, HEX); Serial.print(F(" ("));Serial.print(CC_number_dec, DEC); Serial.print(F(")"));
  Serial.print(F("  Value: "));  Serial.print(CC_value, HEX);Serial.print(F(" ("));Serial.print(CC_value_dec, DEC); Serial.print(F(")"));
  Serial.println();
#endif    

  if ( CC_channel == BCR2000_MIDI_CHANNEL ) 
  {
    int BCR2000_Preset_Index = CC_number_dec - 40;
    boolean SHIFT_PB__state_change = false;

    //////////////////////////////////////////////////////////
    // SPECIFIC TO MY BCR2000 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    /*if ( CC_number != 0x11) // ENCORER n¬¨‚àû41 sending CC message 17 does not work
    {
       Last_Index_In_Mapping = CC_number_dec;
    }
    else {
      Index_In_Mapping = Last_Index_In_Mapping;
    }*/
    Last_Index_In_Mapping = CC_number_dec;


    ////////////////////////////////////////////////////////////////////////////////////
    // HANDLE PARAMETER VALUE CHANGE ASK BY BCR2000 (USER)
    ////////////////////////////////////////////////////////////////////////////////////
#ifdef DEBUG
    Serial.print(F("Before Handle PARAMETER VALUE CHANGE")); 
    Serial.println();
#endif    

    if( CUSTOMIZE_STATE == true )
    {
    	if (    !(CC_number_dec >= 1 && CC_number_dec <= 40) 
             && CC_number_dec != BCR2000_CUSTOMIZE_CC_DEFINE && CC_number_dec != BCR2000_SPEC_FUNC_CC_DEFINE) 
        {
          // no other button press than CUSTOMIZE or SPEC FUNC
          MIDI_BCR2000.sendControlChange( byte(BCR2000_SHIFT_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );        
          MIDI_BCR2000.sendControlChange( byte(BCR2000_RECORD_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_PLAY_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); 
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE1_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE2_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_VOLPAN_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_LOOPER_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );

          MIDI_BCR2000.sendControlChange( byte(BCR2000_XY_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_ONBYPASS_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect1_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect2_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );          

          // Set all Control Page push buttons to off
          for(int i=1; i <= 15 ; i++) { MIDI_BCR2000.sendControlChange( byte(40+i), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); }
         
          return;
        }
 
        if (  CC_number_dec >= 1  && CC_number_dec <= 32 )
        {
	  // Process customization of the 32 encoders for the Effect Control Page
          
          // Build the list of "active" parameters (with label in AXE-EDIT) and store their Param_ID and count how many param for that Effect Type
          byte nbActifParam = 0;
          byte ID[200];
          byte Current_Effect_Block_ID, Current_Effect_Type_ID;
          int addr;
          struct DYN_Parameter THE_Parameter;
  
          if ( QUICKACCESS_STATE == 0 )
          {
            //addr = (i-1) * BCR2000_NumberOf_Controls_DEFINE + (encoder_number-1);
            //Current_Param_ID = EEPROM.read(addr);
            Current_Effect_Type_ID = CS_Effect_Type_ID;
            for(int i = 0 ; i <  CurrentControlPage_EffectType.numOfParameters ; i++)
            {
              Read_Parameter_FromFLASH( (byte) Current_Effect_Type_ID - 2, i , &THE_Parameter ); 
              if( strcmp( THE_Parameter.label, "") != 0)
              {
                ID[nbActifParam] = THE_Parameter.ID;
                nbActifParam ++;
              }
   	    }
          }
          else {
            
            if( CUSTOMIZE_EFFECT_BLOCK_STATE == false )
            {
              addr = EEPROM_START_QUICKACCESS_PAGE + ( (QUICKACCESS_STATE-1) * BCR2000_NumberOf_Controls_DEFINE + (CC_number_dec-1) ) *2 + 1;
              Current_Effect_Block_ID = EEPROM.read(addr);
              Current_Effect_Type_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID_NEW + (Current_Effect_Block_ID - 100));
  
              struct DYN_EffectType THE_Current_Effect_Type;
              Read_EffectType_FromFLASH( Current_Effect_Type_ID - 2 , &THE_Current_Effect_Type);
              
              for(int i = 0 ; i <  THE_Current_Effect_Type.numOfParameters ; i++)
              {
                Read_Parameter_FromFLASH( (byte) Current_Effect_Type_ID - 2, i , &THE_Parameter ); 
                if( strcmp( THE_Parameter.label, "") != 0)
                {
                  ID[nbActifParam] = THE_Parameter.ID;
                  nbActifParam ++;
                }
     	      }
            }
            else{
              // If in CUSTOMIZE_EFFECT_BLOCK_STATE the choice should be between the 71 effect blocks
              nbActifParam = AXEFX_NumberOf_EffectBlocks_DEFINE;
            }
          }

#ifdef DEBUG_8
          Serial.print(F("nbActifParam = ")); Serial.println(nbActifParam, DEC);
          for(int i = 0 ; i <  nbActifParam ; i++)
          {
            Serial.print(F("ID[i] = ")); Serial.println( ID[i], DEC );
 	  }
          Serial.print(F("ID[CC_value_dec] = ")); Serial.println( ID[CC_value_dec], DEC );
          Serial.println();
#endif          
          // BCR2000 should sends back a CC_number_dec value from 0 to nbActifParam - 1 (but it is tested here)
          // Change the mapping of the controlled perameter, or Effect Block for QA
          if( CC_value_dec < nbActifParam )
          {
            if ( QUICKACCESS_STATE == 0 )
            {
              addr = CS_Preset_Number * BCR2000_NumberOf_Controls_DEFINE + CC_number_dec - 1;
              EEPROM.write(addr, byte( ID[CC_value_dec] ) );
              #ifdef DEBUG8
                        Serial.print(F("QUICKACCESS_STATE = ")); Serial.println(QUICKACCESS_STATE, DEC);
                        Serial.print(F("CUSTOMIZE_EFFECT_BLOCK_STATE = ")); Serial.println(CUSTOMIZE_EFFECT_BLOCK_STATE, DEC);
                        Serial.print(F("addr = ")); Serial.println(addr, DEC);
                        Serial.print(F("ID[CC_value_dec] ")); Serial.println( ID[CC_value_dec], DEC );
                        Serial.println();
              #endif
            }
            else {
              // QUICKACCESS_STATE == 1 ou 2
              if( CUSTOMIZE_EFFECT_BLOCK_STATE == false )
              {
                addr = EEPROM_START_QUICKACCESS_PAGE + ( (QUICKACCESS_STATE-1) * BCR2000_NumberOf_Controls_DEFINE + (CC_number_dec-1) ) *2;
                EEPROM.write(addr, byte( ID[CC_value_dec] ) );              
                #ifdef DEBUG8
                          Serial.print(F("QUICKACCESS_STATE = ")); Serial.println(QUICKACCESS_STATE, DEC);
                          Serial.print(F("CUSTOMIZE_EFFECT_BLOCK_STATE = ")); Serial.println(CUSTOMIZE_EFFECT_BLOCK_STATE, DEC);
                          Serial.print(F("addr = ")); Serial.println(addr, DEC);
                          Serial.print(F("ID[CC_value_dec] ")); Serial.println( ID[CC_value_dec], DEC );
                          Serial.println();
                #endif
              }
              else {
                // CUSTOMIZE_EFFECT_BLOCK_STATE == true
                addr = EEPROM_START_QUICKACCESS_PAGE + ( (QUICKACCESS_STATE-1) * BCR2000_NumberOf_Controls_DEFINE + (CC_number_dec-1) ) *2 + 1;
                EEPROM.write(addr, byte( 100 + CC_value_dec ) );                          
                #ifdef DEBUG8
                          Serial.print(F("QUICKACCESS_STATE = ")); Serial.println(QUICKACCESS_STATE, DEC);
                          Serial.print(F("CUSTOMIZE_EFFECT_BLOCK_STATE = ")); Serial.println(CUSTOMIZE_EFFECT_BLOCK_STATE, DEC);
                          Serial.print(F("addr = ")); Serial.println(addr, DEC);
                          Serial.print(F("ID[CC_value_dec] ")); Serial.println( ID[CC_value_dec], DEC );
                          Serial.println();
                #endif
              }
            }
          }
          //Send message to the uVGA
          #ifdef DEBUG8
                    Serial.print(F("Last_Index_In_Mapping -1 = ")); Serial.println(Last_Index_In_Mapping -1, DEC);
                    Serial.print(F("ID[CC_value_dec] ")); Serial.println( ID[CC_value_dec], DEC );
                    Serial.println();
          #endif
          
          if( CUSTOMIZE_EFFECT_BLOCK_STATE == false )
          { send_uVGA_Y___Custom_Value( Last_Index_In_Mapping -1, ID[CC_value_dec] ); }
          else { send_uVGA_Y___Custom_Value( Last_Index_In_Mapping -1, CC_value_dec ); }
          //Received CC range from 1 to 40 where Index range from 0 to 39
          //TODO : Check Why do that ???
          return;
        }

	// TODO : Finish this funcionality        
        if (  CC_number_dec >= 33  && CC_number_dec <= 40 )
        {
          // Process the customization of the 8 top encoder Buttons
          // Build the list of parameter with label (in AXE-EDIT) and store their Param_ID and count how many param for that Effect Type
          byte nbActifParam = 0;
          byte ID[200];
          struct DYN_Parameter THE_Parameter;
          byte CS_Effect_Type_used = CS_Effect_Type_ID - 2;
          
          // Manage the button press and the possition in the param list of each button
          
          // Move to entering custom mode ???
          for(int i = 0 ; i <  CurrentControlPage_EffectType.numOfParameters ; i++)
          {
            Read_Parameter_FromFLASH( (byte) CS_Effect_Type_used, i , &THE_Parameter ); 
            if( strcmp( THE_Parameter.label, "") != 0 && THE_Parameter.displayType != 1 && THE_Parameter.displayType != 6)
            {
              ID[i] = THE_Parameter.ID;
              nbActifParam ++;
            }
 	  }
          //TODO : Check Why do that ???
          CC_number_dec = CC_number_dec - 1; //Received CC range from 1 to 40 where Index range from 0 to 39

        return;
        }
    }


    // CUSTOMIZE button has been presed
    if (  CC_number_dec == BCR2000_CUSTOMIZE_CC_DEFINE )
    {
      static int CurrentBCR2000Preset;
      if( CUSTOMIZE_STATE == false )
      { 
      	CUSTOMIZE_EFFECT_BLOCK_STATE = false; // Only useful for QA pages
 	// Make sure that the current page is an Effect Control Page or Quick Access pages
        // and the BCR2000 is not RECORD or PLAY state
        if ( LOOPER_STATE_RECORD == false && LOOPER_STATE_PLAY == false)
        { 
          CUSTOMIZE_STATE = true;
          
          CurrentBCR2000Preset = CS_Preset_Number;
          // CALLL current BCR2000 preset reconfigure
          BCR2000_Customize_Conf( CurrentBCR2000Preset + 1);
          Serial2.flush();
          Serial2.end();
          MIDI_BCR2000.begin( BCR2000_MIDI_CHANNEL );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_CUSTOMIZE_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
          if( QUICKACCESS_STATE == 0 ) { send_uVGA_E___Screen_Type( CUSTOM_EFFECT_TYPE_CONTROL_PAGE );}
          else { send_uVGA_E___Screen_Type( CUSTOM_QUICKACCESS_CONTROL_PAGE );}
        }
        else {
          CUSTOMIZE_STATE = false;
          MIDI_BCR2000.sendControlChange( byte(BCR2000_CUSTOMIZE_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
        }
      }
      else 
      { 
      	CUSTOMIZE_STATE = false;  
        CUSTOMIZE_EFFECT_BLOCK_STATE = false;
      	MIDI_BCR2000.sendControlChange( byte(BCR2000_CUSTOMIZE_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
        // Only when CUSTOMIZE_STATE goes from TRUE to FALSE
        BCR2000_Init_Device( CurrentBCR2000Preset + 1, CurrentBCR2000Preset + 1);
        Serial2.flush();
        Serial2.end();
        MIDI_BCR2000.begin( BCR2000_MIDI_CHANNEL );

        //StartParamLoading( CS_Current_Effect_Number_In_CP );
        // Refreshes BCR2000 state and Refreshes the uVGA display
        if( QUICKACCESS_STATE == 1 ) { Change_BCR2000_Preset( BCR2000_PRESET_NUMBER_QUICKACCESS_PAGE_1_DEFINE, false);}
        if( QUICKACCESS_STATE == 2 ) { Change_BCR2000_Preset( BCR2000_PRESET_NUMBER_QUICKACCESS_PAGE_2_DEFINE, false); }
        for( int k=0;    k < BCR2000_NumberOf_Controls_DEFINE    ;k++) { CP_Initial_Param_Value_received[k] = 0; }
        CS_Loaded = false; CountReceivedParam = 0;
        Get_Send_Param_Values();
        BCR2000_Manage4ButtonsState( );
        send_uVGA_B___Current_EffectType_ControlPage( );
        send_uVGA___Control_Page_Parameters_Infos( );
        
        if( QUICKACCESS_STATE == 0 ) { send_uVGA_E___Screen_Type( EFFECT_TYPE_CONTROL_PAGE );}
        else { send_uVGA_E___Screen_Type( QUICKACCESS_CONTROL_PAGE );}
        //send_uVGA_D___Init_Value( BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER + 1, 0, 0 );
      }
      
      if( QUICKACCESS_STATE == 0 )  // allows for 15 buttons ON + 4 effect block butoon ON
      {
        byte OffSet;
        if ( SHIFT_PB__state == true ) { OffSet = 16;} else { OffSet = 0;}
        MIDI_BCR2000.sendControlChange( 40 + CS_Preset_Number+1 - OffSet, byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );

        // Manage the state of the shift button
        if( SHIFT_PB__state == true)
        {  MIDI_BCR2000.sendControlChange( byte(BCR2000_SHIFT_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
        else { MIDI_BCR2000.sendControlChange( byte(BCR2000_SHIFT_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); }

        return;
      }
    }


    if(  CC_number_dec == BCR2000_SPEC_FUNC_CC_DEFINE )
    {
      if( QUICKACCESS_STATE == 0)
      {
	// Normal SPEC FUNC treatments
      }
      else{ 
     	if ( CC_value_dec == MIDI_ON )
        { 
          CUSTOMIZE_EFFECT_BLOCK_STATE = true;
          
          // Case where coming from QA param customization
          //TODO : Improve with direct param change storing on the uVGA during QA param customization --> avoid Get_Send_Param_Values()
          //send_uVGA_B___Current_EffectType_ControlPage( );
          send_uVGA___Control_Page_Parameters_Infos( );
          
          send_uVGA_E___Screen_Type( CUSTOM_QUICKACCESS_CONTROL_PAGE_EFFECTBLOCK );
        }
     	else {
          CUSTOMIZE_EFFECT_BLOCK_STATE = false;
          
          for( int k=0;    k < BCR2000_NumberOf_Controls_DEFINE    ;k++) { CP_Initial_Param_Value_received[k] = 0; }
          CS_Loaded = false; CountReceivedParam = 0;
          Get_Send_Param_Values();
          //send_uVGA_B___Current_EffectType_ControlPage( );
          send_uVGA___Control_Page_Parameters_Infos( );
          
          send_uVGA_E___Screen_Type( CUSTOM_QUICKACCESS_CONTROL_PAGE );
        }
      }
     	
      // Manage the displayed state of the button on the BCR2000
      if( CUSTOMIZE_EFFECT_BLOCK_STATE == true)
      { MIDI_BCR2000.sendControlChange( byte(BCR2000_SPEC_FUNC_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
      else { MIDI_BCR2000.sendControlChange( byte(BCR2000_SPEC_FUNC_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );}     
    }




    // Temporary // TODO : To be put in special function menu
    // CONFIGURE THE BCR2000
    if (  CC_number_dec == BCR2000_LOOPER_CC_DEFINE )
    {
      // Must be after SPI start-up
      BCR2000_Init_Device (1, 32);
  
      //BCR2000_Init_Device (1, 32);
      ////////////////BCR2000_Init_Device(1, 1); // Only configure preset #1 of the BCR2000. For test only
      Serial2.flush();
      Serial2.end();
      MIDI_BCR2000.begin( BCR2000_MIDI_CHANNEL );
      Change_BCR2000_Preset( CS_Preset_Number+1, false);
      SetLoad_CurrentControlPage( CS_Current_Effect_Number_In_CP );
      
      return;
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////
    ////   Process modification of a parammeter on the BCR2000 and send new param value to AXE-FX
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    // Check CC number in range 1 to 40 (32 encoders + 8 switchs on the encoders)
    if (  CC_number_dec >= 1  && CC_number_dec <= 40 )
    {
      CC_number_dec = CC_number_dec - 1; //Received CC range from 1 to 40 where Index range from 0 to 39
      Index_In_Mapping = CC_number_dec ;
 

#ifdef DEBUG
            Serial.print("Index_In_Mapping = "); Serial.print( Index_In_Mapping, DEC);
            Serial.println(";");  
#endif

      // FLASH ON LED to mark message being processed
      digitalWrite(parValueLedPin, HIGH);


      ////////////////////////////////////////////
      // CALCULATE VALUE TO BE SENT TO THE AXE-FX
      ////////////////////////////////////////////
        int addr;
        byte Current_Param_ID, Current_Effect_Block_ID, Current_Effect_Type_ID;
        struct DYN_Parameter THE_Parameter;
        
        if ( QUICKACCESS_STATE == 0 )
        {
          addr = CS_Preset_Number * BCR2000_NumberOf_Controls_DEFINE + Index_In_Mapping;
          Current_Param_ID = EEPROM.read(addr);
          Current_Effect_Type_ID = CS_Effect_Type_ID;
        }
        else {
          addr = EEPROM_START_QUICKACCESS_PAGE + ( (QUICKACCESS_STATE-1) * BCR2000_NumberOf_Controls_DEFINE + Index_In_Mapping ) * 2;
	  Current_Param_ID = EEPROM.read(addr);
	  addr ++;
          // Get the Effect Block ID  
	  Current_Effect_Block_ID = EEPROM.read(addr);
          // Get the Effect Type ID of the Effect Block
          Current_Effect_Type_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID_NEW + (Current_Effect_Block_ID - 100));
        }
        Read_Parameter_FromFLASH( Current_Effect_Type_ID - 2, Current_Param_ID, &THE_Parameter );

#ifdef DEBUG11
            Serial.print("PROGMEM ACCESS: CS_Preset_Number = "); Serial.print( CS_Preset_Number, DEC);
            Serial.print(",  THE_Parameter.type = "); Serial.print( THE_Parameter.type, DEC);
            Serial.println(";");
#endif

       // TEST IF THE PARAMETER id the SubType PARAM of the Effect Type
       // If YES log event and "wait" for 200 ms
       // if 200 ms lasted do what subtype change
       if(  Current_Param_ID == CurrentControlPage_EffectType.subTypeParamID && CurrentControlPage_EffectType.subTypeParamID != -1 )
       {
          if( typeDelay_millisElapsed == false)
          {
            //Serial.println("START EVENT EFFET TYPE CHANGE");
            typeDelay_CC_channel = CC_channel;
            typeDelay_CC_number = CC_number;
            typeDelay_CC_value = CC_value;
            typeDelay_lastType = CS_Effect_Type_ID;

            typeDelay_lastTime = millis();
            typeDelay_typeEvent = true;
            send_uVGA_Z___Changing_Value( Index_In_Mapping, CC_value, CC_value );
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
        byte Current_Param_ID, Current_Effect_BLock_ID, Current_Effect_Type_ID;
        int addr;
        
        if ( QUICKACCESS_STATE == 0 )
        {
          addr = CS_Preset_Number * BCR2000_NumberOf_Controls_DEFINE + Index_In_Mapping;
          Current_Param_ID = EEPROM.read(addr);
          Current_Effect_BLock_ID = CS_Effect_Block_ID;
          Current_Effect_Type_ID = CS_Effect_Type_ID;
        }
        else {
          addr = EEPROM_START_QUICKACCESS_PAGE + ( (QUICKACCESS_STATE-1) * BCR2000_NumberOf_Controls_DEFINE + Index_In_Mapping ) * 2;
	  Current_Param_ID = EEPROM.read(addr);
	  addr ++;
          // Get the Effect Block ID  
	  Current_Effect_BLock_ID = EEPROM.read(addr);
          // Get the Effect Type ID of the Effect Block
	  Current_Effect_Type_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID_NEW + (Current_Effect_BLock_ID - 100) );
        }
             
        
        
        // AXE-FX 2
        sysex_mes[3]= 0x03;
        sysex_mes[ 4 ] = AXEFX_SYSEX_PARAM_SET;  //0x02 // ID od MIDI_SET_PARMETER function
        if ( Current_Effect_BLock_ID < 0x80 )
        {
          sysex_mes[5] = Current_Effect_BLock_ID;
          sysex_mes[6] = 0x00;
        }
        else {
          sysex_mes[5] = Current_Effect_BLock_ID - 0x80;
          sysex_mes[6] = 0x01;
        } 

        sysex_mes[7]= Current_Param_ID;
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
        
        struct DYN_Parameter THE_Parameter;
        float DisplayValue;
        
        Read_Parameter_FromFLASH( Current_Effect_Type_ID - 2, Current_Param_ID, &THE_Parameter );
        if(    THE_Parameter.type != AXEFX_INT_Parameter_Type_DEFINE
            && THE_Parameter.type != AXEFX_INTXL_Parameter_Type_DEFINE  ) // test not type = INT --> Modal
        {
          byte factor = 1;
          if( THE_Parameter.unit == 5 && THE_Parameter.maxDispValue == 1) {factor = 100;}  // percentage
          else { 
            if (THE_Parameter.maxDispValue == 1 ) {factor = 10;}
          }
          DisplayValue = THE_Parameter.minDispValue + ( (THE_Parameter.maxDispValue * factor) - THE_Parameter.minDispValue) * (ratio);
        }
        else {
          DisplayValue = LB;
        }
        send_uVGA_Z___Changing_Value( Index_In_Mapping, CC_value, DisplayValue );
#ifdef DEBUG11        
        Serial.println(F("Sending Z message"));
        Serial.print(F("Index_In_Mapping = "));Serial.println(Index_In_Mapping, DEC);
        Serial.print(F("CC_value = "));Serial.println(CC_value, DEC);
        Serial.print(F("DisplayValue = "));Serial.println(DisplayValue, DEC);
#endif


        // If the modified parameter corresponds to the EFFECT TYPE param (send_uVGA___Control_Page_Parameters) of the Effect Type
        // --> refresh param value from AXE
        if( Current_Param_ID == CurrentControlPage_EffectType.subTypeParamID && CurrentControlPage_EffectType.subTypeParamID != -1 )
        {
          CS_Loaded = false;
          CountReceivedParam = 0;
          
          for(int k=0 ; k < BCR2000_NumberOf_Controls_DEFINE ; k++) { CP_Initial_Param_Value_received[k] = 0; }
          
          Get_Send_Param_Values();
          send_uVGA___Control_Page_Parameters_Infos();
          send_uVGA_E___Screen_Type( EFFECT_TYPE_CONTROL_PAGE );
          //send_uVGA_D___Init_Value( BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER + 1 , 0, 0 );
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
    
    return;  
    }  // ENDofIF in range


    

    if(  CC_number_dec == BCR2000_LOOPER_CC_DEFINE  )
    {
      // TODO : ADD the fonctions
      MIDI_BCR2000.sendControlChange( byte(BCR2000_LOOPER_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
     
      #ifdef DEBUG10
            if( CC_number_dec == BCR2000_LOOPER_CC_DEFINE )
            {
              Serial.println(F("send_uvga_1 message sent"));
              send_uvga_1();
            }
      #endif 
      
      return;
    }

    // NOT ACTIVE for now : TODO put it in special functions
    /*

    // LOOPER MODE EXIT
    if( CC_number_dec == BCR2000_CUSTOMIZE_CC_DEFINE && LOOPER_STATE == true)
    {
      LOOPER_STATE = false;
      Change_BCR2000_Preset( CS_Preset_Number +1, false);
      MIDI_BCR2000.sendControlChange( byte(41), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
      MIDI_BCR2000.sendControlChange( byte(40+CS_BCR2000_ACTIVE_BUTTON), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
#ifdef DEBUG4
      Serial.println();Serial.println();
      Serial.println(F("LOOPER EXIT"));
      Serial.print(F("CS_BCR2000_ACTIVE_BUTTON = "));Serial.println(CS_BCR2000_ACTIVE_BUTTON, DEC);  //line feed
      Serial.println();Serial.println();  //line feed
#endif 
      return;
    }
    
    ///////////////////////////// GOTO LOOPER page ////////////////////////////////
    if (  CC_number_dec == BCR2000_CUSTOMIZE_CC_DEFINE && LOOPER_STATE == false)
    {
      LOOPER_STATE = true;

      // BCR2000 preset change
      //Change_BCR2000_Preset( 0x1F, false); // go to preset number 31

      // Set all push buttons to off apart from the one that has been pressed by the user - DOes not apply if button 16 has been pressed
      for(int i=1 ; i < 16 ; i++)
      {
        MIDI_BCR2000.sendControlChange( byte(40+i), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );  //les num‚àö¬©ros change un fois sur le preset 
      }
      // THE FIRST BUTTON IN THE FIRST ROW STAYS ON
      MIDI_BCR2000.sendControlChange( byte(41), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
#ifdef DEBUG4
  Serial.println();Serial.println();
  Serial.print(F("ENTERING LOOPER"));
  Serial.println();Serial.println();  //line feed
#endif 
      return;
    }

    ///////////////////////////// HANDLE CC OF LOOPER PAGE ////////////////////////////////
    if ( LOOPER_STATE == true || CC_number_dec == BCR2000_RECORD_DEFINE || CC_number_dec == BCR2000_PLAY_DEFINE)
    {
#ifdef DEBUG4
  Serial.println();Serial.println();
  Serial.print(F("HANDLING LOOPER EVENTS"));
  Serial.println();Serial.println();  //line feed
#endif 

   //if (LOOPER_STATE == false && ( (CC_number_dec >= 49 && CC_number_dec <= 56) || CC_number_dec >= 41  ) )
   //   {
   //       if (LOOPER_STATE_RECORD == false) { MIDI_BCR2000.sendControlChange( byte(BCR2000_RECORD_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); } 
   //       else { MIDI_BCR2000.sendControlChange( byte(BCR2000_RECORD_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
   //       if (LOOPER_STATE_PLAY == false) { MIDI_BCR2000.sendControlChange( byte(BCR2000_PLAY_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); } 
   //       else { MIDI_BCR2000.sendControlChange( byte(BCR2000_PLAY_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
   //   }
   //   else {
  
        // Check if the button/encoder received is active
        if( CC_number_dec >= 41 || CC_number_dec == BCR2000_RECORD_DEFINE || CC_number_dec == BCR2000_PLAY_DEFINE ||
            ( CC_number_dec >= 49 && CC_number_dec <= 56 ) )
        {
          //  BUTTON 1 stays ON
          if ( CC_number_dec == 41) 
          {
            MIDI_BCR2000.sendControlChange( byte(41), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
          }
          //RECORD pressed
          if ( CC_number_dec == 49 || CC_number_dec == BCR2000_RECORD_DEFINE ) 
          {
            // CC 28 is the default mapping CC for LOOPER RECORD
            if (LOOPER_STATE_RECORD == false) 
            {
              LOOPER_STATE_RECORD = true; 
              MIDI_AXE.sendControlChange( byte(28) , byte(MIDI_ON), byte(AXEFX_MIDI_Channel) );
              if( LOOPER_STATE_PLAY == true)
              {
                LOOPER_STATE_PLAY = false;
                if (CC_number_dec == 49) { MIDI_BCR2000.sendControlChange( byte(50), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); }
                if (CC_number_dec == BCR2000_RECORD_DEFINE) { MIDI_BCR2000.sendControlChange( byte(BCR2000_PLAY_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); }              
              }
            }
            else {
              LOOPER_STATE_RECORD = false;
              MIDI_AXE.sendControlChange( byte(28) , byte(MIDI_OFF), byte(AXEFX_MIDI_Channel) );
              if (CC_number_dec == 49) { MIDI_BCR2000.sendControlChange( byte(50), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
              if (CC_number_dec == BCR2000_RECORD_DEFINE) { MIDI_BCR2000.sendControlChange( byte(BCR2000_PLAY_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
              LOOPER_STATE_PLAY = true;
            }
          }
          //PLAY pressed
          if ( CC_number_dec == 50 || CC_number_dec == BCR2000_PLAY_DEFINE ) 
          {
            // CC 29 is the default mapping CC for LOOPER PLAY
            if (LOOPER_STATE_PLAY == false) 
            { 
              LOOPER_STATE_PLAY = true;
              LOOPER_STATE_RECORD = false;
              MIDI_AXE.sendControlChange( byte(29) , byte(MIDI_ON), byte(AXEFX_MIDI_Channel) );
              if (CC_number_dec == 50) { MIDI_BCR2000.sendControlChange( byte(49), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); } // OFF the RECORD button if on
              if (CC_number_dec == BCR2000_PLAY_DEFINE) { MIDI_BCR2000.sendControlChange( byte(BCR2000_RECORD_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); } // OFF the RECORD button if on
            }
            else {
              LOOPER_STATE_PLAY = false;
              MIDI_AXE.sendControlChange( byte(29) , byte(MIDI_OFF), byte(AXEFX_MIDI_Channel) ); 
              MIDI_BCR2000.sendControlChange( byte(BCR2000_PLAY_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); // OFF the PLAY button
            } 
          }        
          //ONCE pressed
          if ( CC_number_dec == 51) 
          {
            // CC 30 is the default mapping CC for LOOPER ONCE
            if (LOOPER_STATE_ONCE == false) 
            { MIDI_AXE.sendControlChange( byte(30) , byte(MIDI_ON), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_ONCE = true;}
            else {MIDI_AXE.sendControlChange( byte(30) , byte(MIDI_OFF), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_ONCE = false;}      
          }
          //DUB pressed
          if ( CC_number_dec == 52) 
          {
            // CC 28 is the default mapping CC for LOOPER RECORD
            if (LOOPER_STATE_DUB == false) 
            { MIDI_AXE.sendControlChange( byte(31) , byte(MIDI_ON), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_DUB = true;}
            else {MIDI_AXE.sendControlChange( byte(31) , byte(MIDI_OFF), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_DUB = false;}    
          }
          //REVERSE pressed
          if ( CC_number_dec == 53) 
          {
            // CC 121 is the default mapping CC for LOOPER UNDO
            if (LOOPER_STATE_REVERSE == false) 
            { MIDI_AXE.sendControlChange( byte(32) , byte(MIDI_ON), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_REVERSE = true;}
            else {MIDI_AXE.sendControlChange( byte(32) , byte(MIDI_OFF), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_REVERSE = false;}     
          }        
          //UNDO pressed
          if ( CC_number_dec == 54) 
          {
            // CC 121 is the default mapping CC for LOOPER UNDO
            if (LOOPER_STATE_UNDO == false) 
            { MIDI_AXE.sendControlChange( byte(121) , byte(MIDI_ON), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_UNDO = true;}
            else {MIDI_AXE.sendControlChange( byte(121) , byte(MIDI_OFF), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_UNDO = false;}          
          } 
          //HALF pressed
          if ( CC_number_dec == 55) 
          {
            // CC 120 is the default mapping CC for HALF
            if (LOOPER_STATE_UNDO == false) 
            { MIDI_AXE.sendControlChange( byte(120) , byte(MIDI_ON), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_UNDO = true;}
            else {MIDI_AXE.sendControlChange( byte(120) , byte(MIDI_OFF), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_UNDO = false;}          
          } 
          //METRO pressed
          if ( CC_number_dec == 56) 
          {
            // CC 122 is the default mapping CC for METRO (Metronome)
            if (LOOPER_STATE_UNDO == false) 
            { MIDI_AXE.sendControlChange( byte(122) , byte(MIDI_ON), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_UNDO = true;}
            else {MIDI_AXE.sendControlChange( byte(122) , byte(MIDI_OFF), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_UNDO = false;}          
          } 
          
//          NO CC for these for now  --> TODO use SYSEX 
//          //QUANTIZE pressed
//          if ( CC_number_dec == 112) 
//          {
//            // CC 121 is the default mapping CC for LOOPER UNDO
//            if (LOOPER_STATE_UNDO == false) 
//            { MIDI_AXE.sendControlChange( byte(121) , byte(MIDI_ON), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_UNDO = true}
//            else {MIDI_AXE.sendControlChange( byte(121) , byte(MIDI_OFF), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_UNDO = false}          
//          } 
//          //THRESH pressed
//          if ( CC_number_dec == 113) 
//          {
//            // CC 121 is the default mapping CC for LOOPER UNDO
//            if (LOOPER_STATE_UNDO == false) 
//            { MIDI_AXE.sendControlChange( byte(121) , byte(MIDI_ON), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_UNDO = true}
//            else {MIDI_AXE.sendControlChange( byte(MIDI_ON) , byte(MIDI_OFF), byte(AXEFX_MIDI_Channel) ); LOOPER_STATE_UNDO = false}          
//          }    
          
          // MANAGE ON-BYPASS STATE
        }
      //}
      return;  
    }
    */

    /////////////////////////////////// Push button VOL/PAN   ////////////////////////////////
    if ( CC_number_dec == BCR2000_VOLPAN_CC_DEFINE) 
    {
      // TODO : Not active for now
      MIDI_BCR2000.sendControlChange( byte(BCR2000_VOLPAN_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); 
    } 


    /////////////////////////////////// Push button SHIFT is managed on its own and its state memorised ////////////////////////////////
    if ( CC_number_dec == BCR2000_SHIFT_CC_DEFINE) 
    {
      SHIFT_PB__state_change = true; 
      if ( CC_value_dec == MIDI_ON )  { SHIFT_PB__state = true;} else { SHIFT_PB__state = false;}

      // Manage the state of the shift button
      if( SHIFT_PB__state == true)
      {  MIDI_BCR2000.sendControlChange( byte(BCR2000_SHIFT_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
      else { MIDI_BCR2000.sendControlChange( byte(BCR2000_SHIFT_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); }
    } 
 
#ifdef DEBUG3
    Serial.print(F("SHIFT_PB__state_change = "));Serial.print(SHIFT_PB__state_change, BIN); Serial.println("");
    Serial.print(F("SHIFT_PB__state = "));Serial.print(SHIFT_PB__state, BIN); Serial.println("");
    Serial.print(F("BCR2000_Preset_Index = CC_number_dec - 40 = "));Serial.print(BCR2000_Preset_Index, DEC); Serial.println();
    //Serial.print(F("Before Handle 16 PB state")); Serial.println();
     Serial.println();
#endif 


    ///////////////////////////////////////////////////////////////////////////	
    ///////////////////// Manage QUICKACCESS pages - change of page
    ///////////////////////////////////////////////////////////////////////////
    if(   (CC_number_dec == BCR2000_QUICKACCESS_PAGE1_CC_DEFINE 
        || CC_number_dec == BCR2000_QUICKACCESS_PAGE2_CC_DEFINE ) 
          &&   CUSTOMIZE_STATE == false   &&   LOOPER_STATE == false   )
    {
      // From 0   TO   1 or 2
      if ( QUICKACCESS_STATE == 0 )
      {
      	// The "SHIFT" button to switch from custom param to custom Effect_block is RESET
      	CUSTOMIZE_EFFECT_BLOCK_STATE = false;
      	
        if ( CC_number_dec == BCR2000_QUICKACCESS_PAGE1_CC_DEFINE ) 
        {
          QUICKACCESS_STATE = 1;
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE1_CC_DEFINE) , byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE2_CC_DEFINE) , byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); 
          Change_BCR2000_Preset( BCR2000_PRESET_NUMBER_QUICKACCESS_PAGE_1_DEFINE, false);
        }
        if ( CC_number_dec == BCR2000_QUICKACCESS_PAGE2_CC_DEFINE ) 
        { 
          QUICKACCESS_STATE = 2; 
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE1_CC_DEFINE) , byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE2_CC_DEFINE) , byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
          Change_BCR2000_Preset( BCR2000_PRESET_NUMBER_QUICKACCESS_PAGE_2_DEFINE, false);
        }
      } 
      
      // FROM 1   TO   0 OR 2
      if ( QUICKACCESS_STATE == 1 )
      {
        if ( CC_number_dec == BCR2000_QUICKACCESS_PAGE1_CC_DEFINE && CC_value_dec == MIDI_OFF ) 
        { 
          QUICKACCESS_STATE = 0;  
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE1_CC_DEFINE) , byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE2_CC_DEFINE) , byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
        }
        
        if ( CC_number_dec == BCR2000_QUICKACCESS_PAGE2_CC_DEFINE && CC_value_dec == MIDI_ON) 
        { 
          QUICKACCESS_STATE = 2; 
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE1_CC_DEFINE) , byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE2_CC_DEFINE) , byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
          Change_BCR2000_Preset( BCR2000_PRESET_NUMBER_QUICKACCESS_PAGE_2_DEFINE, false);
        }
      } 
      
      // FROM 2    TO    0 OR 1
      if ( QUICKACCESS_STATE == 2 )
      {
        if ( CC_number_dec == BCR2000_QUICKACCESS_PAGE2_CC_DEFINE && CC_value_dec == MIDI_OFF ) 
        { 
          QUICKACCESS_STATE = 0;  
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE1_CC_DEFINE) , byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE2_CC_DEFINE) , byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
        }
        
        if ( CC_number_dec == BCR2000_QUICKACCESS_PAGE1_CC_DEFINE && CC_value_dec == MIDI_ON) 
        { 
          QUICKACCESS_STATE = 1; 
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE1_CC_DEFINE) , byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE2_CC_DEFINE) , byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          Change_BCR2000_Preset( BCR2000_PRESET_NUMBER_QUICKACCESS_PAGE_1_DEFINE, false);
        }
      }
      
      // Only displays/refreshes the QuickAccess page if needed
      if (QUICKACCESS_STATE != 0 ) 
      {
        //ASK for the param value of the CS_Preset
        CS_Loaded = false;
        CountReceivedParam = 0;
        for( int k=0;    k < BCR2000_NumberOf_Controls_DEFINE    ;k++) { CP_Initial_Param_Value_received[k] = 0; }
                //    #ifdef DEBUG
                //        Serial.println("///////////////////////////////////////////////////////////////");
                //        Serial.print("CS_Effect_ID: "); Serial.print(CS_Effect_ID, HEX); Serial.print(";  "); 
                //        Serial.print("CS_Effect_Type: "); Serial.print(CS_Effect_Type, DEC); Serial.print(";  "); 
                //        Serial.print("CS_Preset_Number: "); Serial.print(CS_Preset_Number, DEC); Serial.print(";  "); 
                //        Serial.print("CS_Effect_OBState: "); Serial.print(CS_Effect_OBState, HEX); Serial.print(";  ");
                //        Serial.print("CS_Effect_XYState: "); Serial.print(CS_Effect_XYState, HEX); Serial.print(";  ");
                //        Serial.print("LB: "); Serial.print(LB, HEX); Serial.print(";  ");
                //        Serial.print("MB: "); Serial.print(MB, HEX); Serial.print(";  ");  
                //        Serial.print("HB: "); Serial.print(HB, HEX); Serial.println(";");
                //        Serial.println("///////////////////////////////////////////////////////////////");
                //    #endif 
     
        // Re-configure the current BCR2000 preset so that it is set with the parameter of the QuickAccess Page    
     
        for( int k=0;    k < BCR2000_NumberOf_Controls_DEFINE    ;k++) { CP_Initial_Param_Value_received[k] = 0; }
        CS_Loaded = false; CountReceivedParam = 0;        
        Get_Send_Param_Values();  
        // Manage 4 Effect state buttons
        //BCR2000_Manage4ButtonsState();  
        send_uVGA_B___Current_EffectType_ControlPage();
        send_uVGA___Control_Page_Parameters_Infos();
        send_uVGA_E___Screen_Type( QUICKACCESS_CONTROL_PAGE ); // ScreenSubType = 2 ==> QucickAccess Control Poges
      }
      else {
        // QUICKACCESS_STATE = 0  // Reload last loaded Effect Type Control Page
        
        //StartParamLoading( CS_Current_Effect_Number_In_CP );
        Get_Send_Param_Values();  
        BCR2000_Manage4ButtonsState();  
        send_uVGA_B___Current_EffectType_ControlPage();
        send_uVGA___Control_Page_Parameters_Infos();
        send_uVGA_E___Screen_Type( EFFECT_TYPE_CONTROL_PAGE );
        // Allow entering the code for  Reactivate 15 buttons access
        
        if( CS_Preset_Number < 16 ) 
        {
          BCR2000_Preset_Index = CS_Preset_Number+1;
          CC_number_dec = CS_Preset_Number+41;
          CC_number = CS_Preset_Number+41;
        } 
        else {
          BCR2000_Preset_Index = CS_Preset_Number+1 - 16;
          CC_number_dec = CS_Preset_Number+41 - 16;
          CC_number = CS_Preset_Number+41 - 16;
        }
        CC_value_dec = MIDI_ON;
      }
    }

    // Stops the processing of other CC messages if the BCR2000 is on one of the Quick Access pages
    if( QUICKACCESS_STATE != 0)
    {
      // Kepeps the displayed state on the BCR2000 in sync with the MidyAX states
      if ( QUICKACCESS_STATE == 1 )
      { 
        MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE1_CC_DEFINE) , byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
        MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE2_CC_DEFINE) , byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
      }
      if ( QUICKACCESS_STATE == 2 )
      { 
        MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE1_CC_DEFINE) , byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
        MIDI_BCR2000.sendControlChange( byte(BCR2000_QUICKACCESS_PAGE2_CC_DEFINE) , byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
      }
      
      // Set all buttons ON
      MIDI_BCR2000.sendControlChange( byte(BCR2000_XY_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
      MIDI_BCR2000.sendControlChange( byte(BCR2000_ONBYPASS_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
      MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect1_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
      MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect2_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );

      // Set all 15 Effect Type Control Page push buttons to ON
      for(int i=1; i <= 15 ; i++) { MIDI_BCR2000.sendControlChange( byte(40+i), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
      // If the QUICKACCESS_STATE state is not 0 the 15 Effect Type Control Page selection buttons are inactive
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////// HANDLE other 15 ON/OFF BUTTONS STATE //////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (     ( CC_number_dec >= 41 && CC_number_dec <= 55 )
         ||  SHIFT_PB__state_change == true 
         &&  QUICKACCESS_STATE == 0)
    {      
      int OffSet;
      int  Changeto_Effect_Index = 0;
      boolean Effet_Type_Present = false;

      // If the SHIFT button (16th is ON, add 16 have Preset selected by the user
      if ( SHIFT_PB__state == true ) { OffSet = 16;} else { OffSet = 0;}

      // BCR2000 preset change due to eiher SHIFT pressed or button 1 to 15 presset
      // BCR2000_Preset_Index = CC_number_dec - 40 at the beginning of the function
      if (SHIFT_PB__state_change == true )
      {
        if( CC_value_dec == MIDI_ON ) {
          BCR2000_Preset_Index = CS_Preset_Number+1 + OffSet;
        }
        else {
          BCR2000_Preset_Index = CS_Preset_Number+1 - 16;
        }
      }
      else {
        BCR2000_Preset_Index =  BCR2000_Preset_Index + OffSet;
      }

#ifdef DEBUG3
      Serial.print(F("CS_Preset_Number = "));Serial.print(CS_Preset_Number, DEC); Serial.println();
      Serial.print(F("BCR2000_Preset_Index preset before taking into account last action = "));Serial.print(BCR2000_Preset_Index, DEC); Serial.println();
      Serial.println();
#endif
      
      Change_BCR2000_Preset( BCR2000_Preset_Index, false);
      CS_Preset_Number = BCR2000_Preset_Index -1;
#ifdef DEBUG3
      Serial.print(F("CS_Preset_Number = "));Serial.print(CS_Preset_Number, DEC); Serial.println();
      Serial.print(F("Change to BCR2000_Preset_Index = "));Serial.print(BCR2000_Preset_Index, DEC); Serial.println();
      Serial.println();
#endif

      // Manage the state of the shift button. TODO : Check if useful
      if( SHIFT_PB__state == true)
      {  MIDI_BCR2000.sendControlChange( byte(BCR2000_SHIFT_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
      else { MIDI_BCR2000.sendControlChange( byte(BCR2000_SHIFT_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); }

      // Check that the target Control Page is associated to an effect present in the CurrentPreset of the AXE 
      if ( CC_value_dec == MIDI_ON || SHIFT_PB__state_change == true )
      {
        for(int i=0; i < CP_Number_Effect_Blocks ; i++)
        {
#ifdef DEBUG3
          Serial.print(F("Preset ")); Serial.print( BCR2000_Preset_Index - 1 , DEC);
          Serial.print(F("  Index_Effect_Type ")); Serial.print(i, DEC);
          Serial.print(F("  TYPE "));Serial.print(CP_Effect_Type_ID[ i ], DEC);
          Serial.println();  //line feed
#endif          
          if( CP_Effect_Type_ID[ i ] == ControlPages_USER_Mapping[ BCR2000_Preset_Index - 1 ])
          {
            Effet_Type_Present = true;
#ifdef DEBUG3
            Serial.print(F("Preset FOUND ")); Serial.print( BCR2000_Preset_Index - 1 , DEC);
            Serial.print(F("  Index_Effect_Type in the Ordered list of Effect Block of the Current Preset = ")); Serial.print(i, DEC);
            Serial.print(F("  TYPE = "));Serial.print(CP_Effect_Type_ID[ i ], DEC);
            Serial.println();  //line feed
#endif
            break;
          }      
        }
#ifdef DEBUG3
        Serial.print(F("Effet_Type_Present = "));Serial.print(Effet_Type_Present, DEC); Serial.println();
#endif
        // Set all push buttons to off
        for(int i=1; i <= 15 ; i++) { MIDI_BCR2000.sendControlChange( byte(40+i), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) ); }
     

        // Light on the button corresponding to the Current Control Page         
        if (  CC_number_dec >= 41 && CC_number_dec <= 55 || SHIFT_PB__state_change == true )
        {
          // Apart from the one that should be ON if any
          if ( SHIFT_PB__state_change == false )
          {
            if ( Effet_Type_Present == true || CC_number_dec == BCR2000_SHIFT_CC_DEFINE ) 
            {
              MIDI_BCR2000.sendControlChange( CC_number, byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
              if (SHIFT_PB__state == false) { CS_BCR2000_ACTIVE_BUTTON = BCR2000_Preset_Index;}
              else { CS_BCR2000_ACTIVE_BUTTON = BCR2000_Preset_Index - OffSet;}
            }
            else { CS_BCR2000_ACTIVE_BUTTON = 0; }
          }
          else {
            if( Effet_Type_Present == true || CC_number_dec == BCR2000_SHIFT_CC_DEFINE )
            { 
#ifdef DEBUG3
              Serial.print(F("3 CS_BCR2000_ACTIVE_BUTTON = ")); Serial.print(CS_BCR2000_ACTIVE_BUTTON, DEC); Serial.println();
#endif
              CS_BCR2000_ACTIVE_BUTTON = BCR2000_Preset_Index - OffSet;
              MIDI_BCR2000.sendControlChange( 40 + CS_BCR2000_ACTIVE_BUTTON, byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
            }
            else { CS_BCR2000_ACTIVE_BUTTON = 0; }
          }
          
         
          //////////////////////////////////////////
          // Load CP parameter value of the preset
          /////////////////////////////////////////
          // Retrieve index of first effect in the CP that matches the effect type of the selected BCR2000 preset
          for( int j=0; j < CP_Number_Effect_Blocks ; j++)
          {
#ifdef DEBUG3
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
            SetLoad_CurrentControlPage( Changeto_Effect_Index );
            //delay(50);      
            //Display_Control_Page();
          }
        } 
      }
      
      // For push button 1 to 15 refuse to turn off active button (preset) if pressed again by user
      if ( CC_value_dec == MIDI_OFF && CC_number_dec != BCR2000_SHIFT_CC_DEFINE ) 
      {  MIDI_BCR2000.sendControlChange( byte(CC_number_dec), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) ); }
      else{
        if( Effet_Type_Present == false ) { BCR2000_Init_Current_Preset_Controls_Values( ); }
      }
    }
    
    
    
    

    ////////////////////////////////////////////
    ////////////////////////////////////////////
    ////////////////////////////////////////////
    ////// HANDLE SCENE- and SCENNE + buttons
    ////////////////////////////////////////////
    ////////////////////////////////////////////
    ////////////////////////////////////////////

    if( (CC_number_dec == BCR2000_SCENE_DOWN_CC_DEFINE || CC_number_dec == BCR2000_SCENE_UP_CC_DEFINE) && Axe_Fx_Type == 0x03 && Axe_Fx_Version >= 9)
    {
      boolean SEND = false;
      if (CurentPreset_CurrentSCENE_Number == -1) 
      {
        //Serial.print("ERROR: SCENE number was not received");
        // TODO: SEND ERROR MESSAGE TO SCREEN
        return;
      }
      
      if( CC_number_dec == BCR2000_SCENE_DOWN_CC_DEFINE && CurentPreset_CurrentSCENE_Number > 0)    { CurentPreset_CurrentSCENE_Number--; SEND = true;}

      if( CC_number_dec == BCR2000_SCENE_UP_CC_DEFINE && CurentPreset_CurrentSCENE_Number < 7)    { CurentPreset_CurrentSCENE_Number++; SEND = true;}

      if( SEND == true)
      {
        // AXE-FX II specific
        Stop_Resync = 1;
        
        sysex_mes[4] = AXEFX_SYSEX_SET_SCENE;  //0x29  // SYSEX Function = Change SCENE  
        sysex_mes[5] = CurentPreset_CurrentSCENE_Number;
        sysex_mes[6] = Calculate_CheckSum( sysex_mes, 6);
        MIDI_AXE.sendSysEx( byte( 7 ), sysex_mes, false );
        
        for( int k=0 ; k < 100 ; k++) { MIDI_AXE.read(AXE_FX_CHANNEL); }
        
        //send_uVGA_A___Current_Preset( );
        //send_uVGA_B___Current_EffectType_ControlPage( ); // SENDs Current Effect Type infos // SubScreenType = 1 ==> Effect Type Control Page
        //send_uVGA___Control_Page_Parameters( );
        //SetLoad_CurrentControlPage( CS_Current_Effect_Number_In_CP );
        
        sysex_mes[4]= AXEFX_SYSEX_QUERY_STATES;  //0x0E  // SYSEX Function = Query state of current preset
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
    if (  ( CC_number_dec == BCR2000_XY_CC_DEFINE
         || CC_number_dec ==BCR2000_ONBYPASS_CC_DEFINE  
         || CC_number_dec == BCR2000_BlockSelect1_CC_DEFINE
         || CC_number_dec == BCR2000_BlockSelect2_CC_DEFINE )
         && QUICKACCESS_STATE == 0)
    {
/*#ifdef DEBUG
      Serial.print("ENTER Handle CC message from 4 PB"); 
      Serial.println("");
#endif*/

      // XYSTATE changes
      if ( CC_number_dec == BCR2000_XY_CC_DEFINE )
      {       
        for( int i=0; i < MAX_NUMBER_EFFECTS_BLOCK ;i++)
        {
          if(The_AXE_Effects [i].effect_id_hex == CS_Effect_Block_ID && The_AXE_Effects[i].effect_xy_cc != 0)
          {
            #ifdef DEBUG
                  Serial.print("XYSTATE ="); Serial.print(CS_Effect_XYState, DEC);
                  Serial.print("  CC = ");Serial.print(The_AXE_Effects[i].effect_xy_cc, DEC);
                  Serial.print("  CS_Current_Effect_Number_In_CP = ");Serial.print(CS_Current_Effect_Number_In_CP, DEC);
                  Serial.println("");
            #endif
            
            CS_Effect_XYState = ! CS_Effect_XYState;
            CP_Effect_XYState [ CS_Current_Effect_Number_In_CP ] = !CP_Effect_XYState [ CS_Current_Effect_Number_In_CP ];
            
            if ( CS_Effect_XYState == true )
                { MIDI_AXE.sendControlChange( The_AXE_Effects[i].effect_xy_cc, byte(MIDI_ON), byte(AXE_FX_CHANNEL) );}  // CASE X
            else{
              MIDI_AXE.sendControlChange( The_AXE_Effects[i].effect_xy_cc, byte(MIDI_OFF), byte(AXE_FX_CHANNEL) );}    // CASE Y
            
            //StartParamLoading( CS_Current_Effect_Number_In_CP ); // Reload parameters for the same effect but other case (X or Y)
            for( int k=0;    k < BCR2000_NumberOf_Controls_DEFINE    ;k++) { CP_Initial_Param_Value_received[k] = 0; }
            CS_Loaded = false; CountReceivedParam = 0;
            Get_Send_Param_Values();
            send_uVGA_B___Current_EffectType_ControlPage();
            send_uVGA___Control_Page_Parameters_Infos( );
            send_uVGA_E___Screen_Type( EFFECT_TYPE_CONTROL_PAGE );
            break;
          }
        }
        BCR2000_Manage4ButtonsState();
      }
      

      // OBSTATE change
      if ( CC_number_dec == BCR2000_ONBYPASS_CC_DEFINE )
      { 
        for( int i=0 ; i < MAX_NUMBER_EFFECTS_BLOCK ; i++)
        {
          if(The_AXE_Effects[i].effect_id_hex == CS_Effect_Block_ID && The_AXE_Effects[i].effect_onbypass_cc != 0)
          {
          #ifdef DEBUG14
                Serial.print("STATE ="); Serial.print(CS_Effect_OBState, DEC);
                Serial.print("ONBYPASS STATE");Serial.print(The_AXE_Effects[i].effect_onbypass_cc, DEC);
                Serial.println("");
          #endif    
          
          CS_Effect_OBState = ! CS_Effect_OBState;
          CP_Effect_OBState [ CS_Current_Effect_Number_In_CP ] = !CP_Effect_OBState [ CS_Current_Effect_Number_In_CP ];
          
          if ( CS_Effect_OBState == true )
                { MIDI_AXE.sendControlChange( The_AXE_Effects[i].effect_onbypass_cc, byte(MIDI_ON), byte(AXE_FX_CHANNEL) );}   // CASE ON
            else{ MIDI_AXE.sendControlChange( The_AXE_Effects[i].effect_onbypass_cc, byte(MIDI_OFF), byte(AXE_FX_CHANNEL) );}     // CASE OFF
          
          //StartParamLoading( CS_Current_Effect_Number_In_CP ); // Refresh screen
          // No need to get the parameter values. A screen refresh is needed to update the Effect chain on the screen.
          // The Current Control Page is not changed. The param info don't need to be reloaded.
          send_uVGA_A___Current_Preset();
          send_uVGA_B___Current_EffectType_ControlPage();
          send_uVGA___Control_Page_Parameters_Infos( );
          send_uVGA_E___Screen_Type( EFFECT_TYPE_CONTROL_PAGE );
          break;
          }
        }
        BCR2000_Manage4ButtonsState();
      }
      
      // Number in possible number of Effect type 
      if ( CC_number_dec == BCR2000_BlockSelect1_CC_DEFINE || CC_number_dec == BCR2000_BlockSelect2_CC_DEFINE)
      {
        switch ( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type_Number + CS_Effect_Type_ID ) )
        {
          case 1:
            BCR2000_Manage4ButtonsState( );
            break;
            
          case 2:
            #ifdef DEBUG
                  Serial.print(F("Case = 2"));
                  Serial.print(F("  CS_Effect_Type_ID =")); Serial.print(CS_Effect_Type_ID, DEC);
                  Serial.println(); Serial.println();
            #endif     
            // The BCR2000_BlockSelect1_CC_DEFINE BP has no effect in that case
            if ( CC_number_dec == BCR2000_BlockSelect1_CC_DEFINE) 
            {
              for( int i=0 ; i < MAX_NUMBER_EFFECTS_BLOCK ; i++ )
              {
                #ifdef DEBUG
                            Serial.print(F("CS_Effect_Type_ID = ")); Serial.print(CS_Effect_Type_ID, DEC);
                            Serial.print(F("  CS_Effect_Block_ID = ")); Serial.print(CS_Effect_Block_ID, DEC);
                            Serial.print(F("  i = ")); Serial.print(i, DEC);
                            Serial.print(F("   AXEFX_Effect_Type[ i ] = ")); Serial.print( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID + i ), DEC);
                            Serial.print(F("   AXEFX_Effect_Type[ i+1 ] = ")); Serial.print( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID + (i+1) ), DEC);           
                            Serial.print(F("   AXEFX_Effect_ID[ i ] = ")); Serial.print( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + i ), HEX);
                            Serial.println(); Serial.println();
                #endif
                if( CS_Effect_Type_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID + i ) )
                {        
                  // Update the CS with the new effect ID  
                  if(  CS_Effect_Block_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + i )
                     &&  CS_Effect_Type_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID + (i+1) ) )
                  {
                    // CASE 0 TO 1      
                    Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + (i+1) );
                    Target_CS_Effect_NumSel_State = 1;
                  }
                  else {
                    // CASE 1 TO 0
                    Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + i );
                    Target_CS_Effect_NumSel_State = 0;
                  }
    
                  #ifdef DEBUG
                              Serial.print(F("Target_Effect_ID = ")); Serial.print(Target_Effect_ID, HEX);
                              Serial.print(F("  Target_CS_Effect_NumSel_State = ")); Serial.print(Target_CS_Effect_NumSel_State, DEC);
                              Serial.println(); Serial.println();
                  #endif//*/               
                  // Search for target effect ID in the list of effect of the current preset
                  // If not found --> Do nothing
                  for( int j=0 ; j < CP_Number_Effect_Blocks ; j++ )
                  {
                    #ifdef DEBUG
                                Serial.print(F("CP_Effect_Block_ID[ j ] = ")); Serial.print(CP_Effect_Block_ID[ j ], HEX);
                                Serial.println(); Serial.println();
                    #endif//*/ 
                    if ( CP_Effect_Block_ID[ j ] == Target_Effect_ID )
                    {
                      CS_Effect_NumSel_State = Target_CS_Effect_NumSel_State;
                      //StartParamLoading( j );
                      SetLoad_CurrentControlPage( j );           
                      break;
                    }
                  } //ENDofFOR on j
                  break;
                }
              } // ENDofFOR on i
            } // ENDofIF(ELSE)
            
            // In case BCR2000_BlockSelect1_CC_DEFINE IS PRESSED THE state of the button on the BCR2000 needs to be set back to previous value
            BCR2000_Manage4ButtonsState();          
            break;
            
            
            
          case 4:
            for( int i=0 ; i < MAX_NUMBER_EFFECTS_BLOCK ; i++ )
            {
              if (  CS_Effect_Type_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID + i ) )
              {
                // SWITCH on the intial state of button 105 and 107
                switch(CS_Effect_NumSel_State)
                {
                  case 0 : // BCR2000_XY_CC_DEFINE = OFF and BCR2000_BlockSelect1_CC_DEFINE OFF
                    if ( CC_number_dec == BCR2000_XY_CC_DEFINE)  // CASE 0 to 1 !!!
                    {
                      Target_CS_Effect_NumSel_State = 1;
                      Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + (i+1) ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                    }
                    if ( CC_number_dec == BCR2000_BlockSelect1_CC_DEFINE)  // CASE 0 to 2 !!!
                    {
                      Target_CS_Effect_NumSel_State = 2;
                      Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + (i+2) ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                    }
                    break;
  
                  case 1 : // BCR2000_XY_CC_DEFINE = ON and BCR2000_BlockSelect1_CC_DEFINE OFF
                    if ( CC_number_dec == BCR2000_XY_CC_DEFINE)  // CASE 1 to 0 !!!
                    {
                      Target_CS_Effect_NumSel_State = 0;
                      Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + i ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                    }
                    if ( CC_number_dec == BCR2000_BlockSelect1_CC_DEFINE)  // CASE 1 to 3 !!!
                    {
                      Target_CS_Effect_NumSel_State = 3;
                      Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + (i+3) ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                    }
                    break;
                
                  case 2 : // BCR2000_XY_CC_DEFINE = OFF and BCR2000_BlockSelect1_CC_DEFINE ON
                    if ( CC_number_dec == BCR2000_XY_CC_DEFINE)  // CASE 2 to 3 !!!
                    {
                      Target_CS_Effect_NumSel_State = 3;
                      Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + (i+3) ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                    }
                    if ( CC_number_dec == BCR2000_BlockSelect1_CC_DEFINE)  // CASE 2 to 0 !!!
                    {
                      Target_CS_Effect_NumSel_State = 0;
                      Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + i ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                    }
                    break;
                    
                  case 3 : // BCR2000_XY_CC_DEFINE = ON and BCR2000_BlockSelect1_CC_DEFINE ON
                    if ( CC_number_dec == BCR2000_XY_CC_DEFINE)  // CASE 3 to 2 !!!
                    {
                      Target_CS_Effect_NumSel_State = 2;
                      Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + (i+2) ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                    }
                    if ( CC_number_dec == BCR2000_BlockSelect1_CC_DEFINE)  // CASE 3 to 1 !!!
                    {
                      Target_CS_Effect_NumSel_State = 1;
                      Target_Effect_ID = pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + (i+1) ); // Move from EFFECT 1 to EFFECT 2 in the same type of effect
                    }
                    break;
                } // ENDofSWITCH on CS_Effect_NumSel_State
   
                // Search for target effect ID in the list of effect of the current preset
                for(int j=0;   j < CP_Number_Effect_Blocks   ;j++)
                {
                  if ( CP_Effect_Block_ID[ j ] == Target_Effect_ID)
                  {
                    CS_Effect_NumSel_State = Target_CS_Effect_NumSel_State;
                    //StartParamLoading( j );
                    SetLoad_CurrentControlPage( j );
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
  } //END of IF MIDI channel = AXE-FX channel

  // RECEIVING TEST CCs
  if( CC_channel == BCR2000_MIDI_CHANNEL && CC_number == MIDI_TEST_CC_SENT)
  {
    BCR2000_Received_CC_Value = CC_value;
    //Serial.print("Message : "); Serial.print(CC_value, DEC); Serial.print(" received");
  }
}










void BCR2000_Manage4ButtonsState( void )
{
      ///////////////////////////////////
      //MANAGE 4 EFFECT STATE BUTTONS
      //////////////////////////////////

      // Set all buttons OFF before sending states
      MIDI_BCR2000.sendControlChange( byte(BCR2000_XY_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
      MIDI_BCR2000.sendControlChange( byte(BCR2000_ONBYPASS_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
      MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect1_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
      MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect2_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
      
      // Set On/Bypass indicator
      if ( CS_Effect_OBState == 1 )  //TEST IF EFFECT is ON 
      {MIDI_BCR2000.sendControlChange( byte(BCR2000_ONBYPASS_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );}   // ON --> lighted
      else {MIDI_BCR2000.sendControlChange( byte(BCR2000_ONBYPASS_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );}  // OFF --> not lighted
      // Set X/Y indicator
      if ( CS_Effect_XYState == 1 )  //TEST IF X IS SELECTED
      {MIDI_BCR2000.sendControlChange( byte(BCR2000_XY_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );}         // X --> not lighted
      else {MIDI_BCR2000.sendControlChange( byte(BCR2000_XY_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );}  // Y --> lighted   
      // Set Effect number for that type (AMP1 or AMP2)

#ifdef DEBUG
          Serial.print(F("CS_Effect_Type_ID = ")); Serial.print(CS_Effect_Type_ID, DEC);
          Serial.print(F("   AXEFX_Effect_Type_Number[CS_Effect_Type_ID] = ")); Serial.print( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type_Number + CS_Effect_Type_ID ), DEC);
          Serial.println();
#endif 
      switch ( pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Type_Number + CS_Effect_Type_ID ) )
      {
        case 1:
          MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect1_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect2_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
          CS_Effect_NumSel_State = 0;
          break;
          
        case 2:
          for( int k=0; k < MAX_NUMBER_EFFECTS_BLOCK ; k++)
          {
/*#ifdef DEBUG
            Serial.print("CS_Effect_Type = "); Serial.print(CS_Effect_Type, DEC);
            Serial.print("  CS_Effect_ID = "); Serial.print(CS_Effect_ID, DEC);
            Serial.print("  k"); Serial.print(k, DEC);
            Serial.print("   AXEFX_Effect_Type[ k ] = "); Serial.print( AXEFX_Effect_Type[ k ] , DEC);           
            Serial.print("   AXEFX_Effect_ID[k] = "); Serial.print( AXEFX_Effect_ID[k], DEC);
            Serial.println("");
#endif*/ 
            if( CS_Effect_Type_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_to_Effect_Type_ID + k ) )
            {             
              if( CS_Effect_Block_ID == pgm_read_byte_near( PROGMEM_BYTE___AXEFX_Effect_Block_ID + k ) )
              {
                // CASE 1 (displayed as 0)
                MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect1_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
                MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect2_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
                CS_Effect_NumSel_State = 0;
              }
              else {
                // CASE 2 (displayed as 1)
                MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect1_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
                MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect2_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
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
                MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect1_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
                MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect2_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
                break;

            case 1:
                // CASE 2 (displayed as 1)
                MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect1_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
                MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect2_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
                break;
  
            case 2:
                // CASE 3 (displayed as 2)
                MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect1_CC_DEFINE), byte(MIDI_OFF), byte(BCR2000_MIDI_Channel) );
                MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect2_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
                break;
  
            case 3:
                // CASE 4 (displayed as 3)
                MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect1_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
                MIDI_BCR2000.sendControlChange( byte(BCR2000_BlockSelect2_CC_DEFINE), byte(MIDI_ON), byte(BCR2000_MIDI_Channel) );
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





