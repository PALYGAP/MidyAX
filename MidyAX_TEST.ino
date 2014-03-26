

////////////////////////////////////////////////////////////////
///// NO AXE-FX detected ==> ENTERING TEST MODE 
////////////////////////////////////////////////////////////////
void test( void )
{
    int nberror;  
    byte manuf_ID;
    
    digitalWrite(parValueLedPin, HIGH);
    digitalWrite(sysExLedPin, HIGH);
    delay(1000);
    digitalWrite(parValueLedPin, LOW);
    digitalWrite(sysExLedPin, LOW);
    delay(5000);

    Serial.end();
    Serial1.end();
    Serial2.end();
    Serial3.end();

   Serial.println("Started TEST "); 


    /////////////////
    // TEST FLASH
    /////////////////
    manuf_ID = info();
    if( manuf_ID == 0x37 ) { digitalWrite(sysExLedPin, HIGH); delay(2000); digitalWrite(sysExLedPin, LOW); delay(2000); }
    else { digitalWrite(parValueLedPin, HIGH); delay(2000); digitalWrite(parValueLedPin, LOW); delay(2000); }
  
    // TEST FLASH WRITING
    WRITING_currentMemAddresse = D_Upper_MemBlock; // 0x70000
    sectorEraseFLASH( WRITING_currentMemAddresse );
    for( byte i=0 ; i<128 ; i++) { write_Byte_InByteBuffer(i); }
    flushByteBuffer();
  
    nberror = 0;
    unsigned long readMemAddresse = D_Upper_MemBlock;
    byte tempoBYTE1 = B11111111; 
    for(byte i=0 ; i<128 ; i++)
    {
      read_DataBytes_FLASH(readMemAddresse, &tempoBYTE1, 1);
      if( tempoBYTE1 != i) { nberror++; }
      readMemAddresse++;
    }
    if( nberror == 0 ) { digitalWrite(sysExLedPin, HIGH); delay(2000); digitalWrite(sysExLedPin, LOW); delay(2000); }
    else { digitalWrite(parValueLedPin, HIGH); delay(2000); digitalWrite(parValueLedPin, LOW); delay(2000); }


    //////////////////////////////
    // TEST MIDI COMMUNICATION
    /////////////////////////////
    AXE_FX_CHANNEL = 1;
    BCR2000_MIDI_CHANNEL = 1;
    FOOTPEDAL_CHANNEL = 1;
    OTHER_MIDI_CHANNEL = 1;

    MIDI_AXE.begin( AXE_FX_CHANNEL );
    MIDI_BCR2000.begin( BCR2000_MIDI_CHANNEL );
    MIDI_FOOTPEDAL.begin( FOOTPEDAL_CHANNEL );
    MIDI_OTHER.begin( OTHER_MIDI_CHANNEL );

    MIDI_AXE.setHandleControlChange(AXE_ManageCC);
    MIDI_BCR2000.setHandleControlChange(BCR2000_ManageCC);
    MIDI_FOOTPEDAL.setHandleControlChange(FOOTPEDAL_ManageCC);
    MIDI_OTHER.setHandleControlChange(OTHER_ManageCC);
    
    //Display INIT screen on the uVGA
    //send_uvga_A(0);

    // Routing configuration 
    // D29 & D30 = 0 ==> UART0 connected to MIDI port PC/AXE-EDIT
    // D29 = 1 & D30 = 0 ==> UART0 connected to uVGA    
    #ifdef ELECTRONIE_PROTO
      // SET the ROUTING of the UART 0 to the PC/AXE-EDIT port
      pinMode( PIN0_ROUTING_UART0, OUTPUT);
      digitalWrite( PIN0_ROUTING_UART0, LOW);
      pinMode( PIN1_ROUTING_UART0, OUTPUT);
      digitalWrite( PIN1_ROUTING_UART0, LOW);
    #endif


    ///////////////////////////////////////////////////////////////////
    ///////// START testing the communication between MIDI ports
    ///////////////////////////////////////////////////////////////////
    
    // SEND test CCs:   AXE-FX port ---> FOOTPEDAL (MFC-101) port
    nberror = 0;
    for(int i=1 ; i <= 10 ; i++)
    {
      MIDI_AXE.sendControlChange( byte(MIDI_TEST_CC_SENT), byte(i), byte(FOOTPEDAL_CHANNEL) );
      for(int j=1 ; j <= 100 ; j++) 
      {
        if ( MIDI_FOOTPEDAL.read(FOOTPEDAL_CHANNEL) == true ) { break;}
      }
      #ifdef DEBUG_TEST
        Serial.print("Sent : "); Serial.print(i, DEC);
        Serial.print("    Received : "); Serial.println(FOOTPEDAL_Received_CC_Value, DEC);
      #endif
      if( FOOTPEDAL_Received_CC_Value != i)  { nberror++; }      
      delay(100);
    }
    if( nberror == 0 ) { digitalWrite(sysExLedPin, HIGH); delay(2000); digitalWrite(sysExLedPin, LOW); delay(2000); }
    else { digitalWrite(parValueLedPin, HIGH); delay(2000); digitalWrite(parValueLedPin, LOW); delay(2000); }

  
    //send_uvga_1( );
    //send_uvga_A(0);
    if( nberror == 0 ) { send_uvga_2( "Link from MIDI port AXE-FX to MIDI port MFC-101 is working" ); }
    else { send_uvga_2( "Link from MIDI port AXE-FX to MIDI port MFC-101 is not working" ); }
        

    // SEND test CCs:   FOOTPEDAL (MFC-101) port ---> AXE-FX port
    nberror = 0;
    for(int i=1 ; i <= 10 ; i++)
    {
      MIDI_FOOTPEDAL.sendControlChange( byte(MIDI_TEST_CC_SENT), byte(i), byte(AXE_FX_CHANNEL) );
      for(int j=1 ; j <= 100 ; j++) 
      {
        if ( MIDI_AXE.read(AXE_FX_CHANNEL) == true ) { break;}
      }
      #ifdef DEBUG_TEST
        Serial.print("Sent : "); Serial.print(i, DEC);
        Serial.print("    Received : "); Serial.println(AXEFX_Received_CC_Value, DEC);
      #endif     
      if( AXEFX_Received_CC_Value != i) { nberror++; }
      delay(100);
    }
    send_uvga_1( );
    send_uvga_A(0);
    if( nberror == 0 ) { digitalWrite(sysExLedPin, HIGH); delay(2000); digitalWrite(sysExLedPin, LOW); delay(2000); }
    else { digitalWrite(parValueLedPin, HIGH); delay(2000); digitalWrite(parValueLedPin, LOW); delay(2000); }

    if( nberror == 0 ) { send_uvga_2( "Link from MIDI port MFC-101 to MIDI port AXE-FX is working" ); }
    else { send_uvga_2( "Link from MIDI port MFC-101 to MIDI port AXE-FX is not working" ); }

    
    // SEND test CCs:   BCR2000 port ---> OTHER (PC/AXE-EDIT) port
    nberror = 0;
    for(int i=1 ; i <= 10 ; i++)
    {
      MIDI_BCR2000.sendControlChange( byte(MIDI_TEST_CC_SENT), byte(i), byte(OTHER_MIDI_CHANNEL) );
      for(int j=1 ; j <= 100 ; j++) 
      {
        if ( MIDI_OTHER.read(OTHER_MIDI_CHANNEL) == true ) { break;}
      }
      #ifdef DEBUG_TEST
        Serial.print("Sent : "); Serial.print(i, DEC);
        Serial.print("    Received : "); Serial.println(OTHER_Received_CC_Value, DEC);
      #endif  
      if( OTHER_Received_CC_Value != i) { nberror++; }
      delay(100);
    }
    if( nberror == 0 ) { digitalWrite(sysExLedPin, HIGH); delay(2000); digitalWrite(sysExLedPin, LOW); delay(2000); }
    else { digitalWrite(parValueLedPin, HIGH); delay(2000); digitalWrite(parValueLedPin, LOW); delay(2000); }

    if( nberror == 0 ) { send_uvga_2( "Link from MIDI port BCR2000 to MIDI port OTHER is working" ); }
    else { send_uvga_2( "Link from MIDI port BCR2000 to MIDI port OTHER is not working" ); }


    // SEND test CCs: OTHER (PC/AXE-EDIT) port --->  BCR2000 port 
    nberror = 0;
    for(int i=1 ; i <= 10 ; i++)
    {
      MIDI_OTHER.sendControlChange( byte(MIDI_TEST_CC_SENT), byte(i), byte(BCR2000_MIDI_CHANNEL) );
      for(int j=1 ; j <= 100 ; j++) 
      {
        if ( MIDI_BCR2000.read(BCR2000_MIDI_CHANNEL) == true ) { break;}
      }
      #ifdef DEBUG_TEST
        Serial.print("Sent : "); Serial.print(i, DEC);
        Serial.print("    Received : "); Serial.println(BCR2000_Received_CC_Value, DEC);
      #endif  
      if( BCR2000_Received_CC_Value != i) { nberror++; }
      delay(100);
    }
    if( nberror == 0 ) { digitalWrite(sysExLedPin, HIGH); delay(2000); digitalWrite(sysExLedPin, LOW); delay(2000); }
    else { digitalWrite(parValueLedPin, HIGH); delay(2000); digitalWrite(parValueLedPin, LOW); delay(2000); }

    if( nberror == 0 ) { send_uvga_2( "Link from MIDI port OTHER to MIDI port BCR2000 is working" ); }
    else { send_uvga_2( "Link from MIDI port OTHER to MIDI port BCR2000 is not working" ); }
  
} // END TEST MODE code

