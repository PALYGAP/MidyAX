void FOOTPEDAL_ManageCC ( byte CC_channel, byte CC_number, byte CC_value )
{

#ifdef DEBUG_TEST
  // PRINT OUT CC VALUES RECEIVED FROM FOOT CONTROLLER
  Serial.print(F("FOOTPEDAL - CONTROL change message --- Channel: ")); Serial.print(CC_channel, DEC);
  Serial.print(F("  Received CC:  Number: ")); Serial.print(CC_number, HEX); Serial.print(" (");Serial.print(CC_number, DEC); Serial.print(")");
  Serial.print(F("  Value: "));  Serial.print(CC_value, HEX);Serial.print(" (");Serial.print(CC_value, DEC); Serial.print(")");
  Serial.println();  //line feed
/*  if ( CC_number != byte(7) )
  {
    lcd.clear();
    lcd.print( "FOOTPEDAL - CONTROL change" );
    lcd.setCursor(0, 1);
    lcd.print( "CC=" ); lcd.print( CC_number, DEC ); lcd.print( "  " );
    lcd.print( "VALUE=" ); lcd.print( CC_value, DEC );
  }*/
#endif

  // RECEIVING TEST CCs
  if( CC_channel == FOOTPEDAL_CHANNEL && CC_number == MIDI_TEST_CC_SENT)
  {
    FOOTPEDAL_Received_CC_Value = CC_value;
    //Serial.print("Message : "); Serial.print(CC_value, DEC); Serial.print(" received");
   }
  return;
}  

void FOOTPEDAL_ManagePC ( byte PC_channel, byte PC_number )
{
#ifdef DEBUG
  // PRINT OUT PC VALUES RECEIVED FROM CONTROLLER 
  Serial.print(F("FOOTPEDAL - PROGRAM change message --- Channel: ")); Serial.print(PC_channel, DEC);
  Serial.print(F("  Received PC:  Number: ")); Serial.print(PC_number, HEX); Serial.print(F(" ("));Serial.print(PC_number, DEC); Serial.print(F(")"));
  Serial.println();  //line feed
  lcd.clear();
  lcd.print(F("FOOTPEDAL - PROGRAM change" ));
  lcd.setCursor(0, 1);
  lcd.print(F("PC=")); lcd.print( PC_number, DEC );
#endif    
  
  return;
} 

