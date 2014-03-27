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
