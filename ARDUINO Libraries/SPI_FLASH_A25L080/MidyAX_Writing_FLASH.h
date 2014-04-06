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

#ifndef MIDYAX_WRITING_FLASH_H_
#define MIDYAX_WRITING_FLASH_H_

#include "Arduino.h"

  void testIfWriteNeeded();
  
  int flushByteBuffer();
  
  void write_Byte_InByteBuffer(  byte theBYTE);
  
  void write_Int_InByteBuffer( int theINT);
  
  void write_UnsignedLong_InByteBuffer( unsigned long theUnsignedLong);
  
  void write_String_InByteBuffer( char * theSTRING, int strSize);

#endif
