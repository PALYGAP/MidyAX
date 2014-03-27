void OTHER_ManageCC ( byte CC_channel, byte CC_number, byte CC_value )
{
  // RECEIVING TEST CCs
  if( CC_channel == OTHER_MIDI_CHANNEL && CC_number == MIDI_TEST_CC_SENT)
  {
    OTHER_Received_CC_Value = CC_value;
    //Serial.print("Message : "); Serial.print(CC_value, DEC); Serial.print(" received");
  }
  return;
} 




