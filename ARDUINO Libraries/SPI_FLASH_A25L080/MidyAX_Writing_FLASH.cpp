#include "Arduino.h"
#include <SPI_FLASH_AL25L80_ELECTRONIE.h>


unsigned long WRITING_currentMemAddresse;
byte MSB, LSB ;
byte byteBuffer[256];
int bytesFiled = 0;
int numOfWrittenBuffer = 0;

// To include in the "main" file 
/*
extern unsigned long WRITING_currentMemAddresse;
extern byte MSB, LSB ;
extern byte byteBuffer[256];
extern int bytesFiled;
extern int numOfWrittenBuffer;
*/


void testIfWriteNeeded()
{
  if( bytesFiled == 256)
  {
    writeEEPROM ( (const unsigned long) WRITING_currentMemAddresse, byteBuffer, 256);
    WRITING_currentMemAddresse += 256;
    bytesFiled = 0;
    numOfWrittenBuffer++;
#ifdef DEBUG_BUFFER_FUNCTION  
    //sprintf(str,"######## Buffer %i written %s", numOfWrittenBuffer, byteBuffer); 
    //Serial.println(str); 
    Serial.println( (char *) byteBuffer);
    for(int i=0; i < 256 ; i++)
    {
      Serial.print("Pos=");Serial.print(i, DEC);Serial.print(", BYTE = ");
      Serial.print(byteBuffer[i], BIN);//Serial.print(", CHAR = ");Serial.println(byteBuffer[i], DEC);
      sprintf(str," INT = %i, CHAR = %c", (int) byteBuffer[i], (char) byteBuffer[i] ); Serial.println(str);
    }
#endif
  }
}

int flushByteBuffer()
{
   if( bytesFiled <= 256)
    {
      writeEEPROM ( (const unsigned long) WRITING_currentMemAddresse, byteBuffer, bytesFiled);
      WRITING_currentMemAddresse += 256;
      bytesFiled = 0;
      numOfWrittenBuffer = 0;
#ifdef DEBUG_BUFFER_FUNCTION  
    //sprintf(str,"######## Buffer %i written %s", numOfWrittenBuffer, byteBuffer); 
    //Serial.println(str); 
    Serial.println( (char *) byteBuffer);
    for(int i=0; i < 256 ; i++)
    {
      Serial.print("Pos=");Serial.print(i, DEC);Serial.print(", BYTE = ");
      Serial.print(byteBuffer[i], BIN);//Serial.print(", CHAR = ");Serial.println(byteBuffer[i], DEC);
      sprintf(str," INT = %i, CHAR = %c", (int) byteBuffer[i], (char) byteBuffer[i] ); Serial.println(str);
    }
#endif
    }
    else return -1;
}

  
void write_Byte_InByteBuffer(  byte theBYTE)
{
  byteBuffer[bytesFiled] = theBYTE;
  bytesFiled++;
  testIfWriteNeeded( );
#ifdef DEBUG_BUFFER_FUNCTION  
    sprintf(str,"Written BYTE in position %i of byteBuffer for buffer n = %i", bytesFiled-1, numOfWrittenBuffer); 
    Serial.print(str);    
    sprintf(str,"  BYTE = %i  ", theBYTE);
    Serial.println(str); 
#endif
}

void write_Int_InByteBuffer( int theINT)
{
  byteBuffer[bytesFiled] = (theINT >> 8) & 0xFF;
  bytesFiled++;
  testIfWriteNeeded();
  
  byteBuffer[bytesFiled] = theINT & 0xFF;
  bytesFiled++;
  testIfWriteNeeded( );
  
#ifdef DEBUG_BUFFER_FUNCTION  
    sprintf(str,"Written INT in positions %i and %i of byteBuffer for buffer num = %i", bytesFiled-2, bytesFiled-1, numOfWrittenBuffer); 
    Serial.println(str);    
    sprintf(str,"MSB = %i, LSB = %i, value = %i", (theINT >> 8) & 0xFF, theINT & 0xFF, theINT); 
    Serial.println(str);
    Serial.println( (theINT >> 8) & 0xFF, BIN);
    Serial.println( theINT & 0xFF, BIN);
    Serial.println( theINT, BIN);
#endif
}

void write_UnsignedLong_InByteBuffer( unsigned long theUnsignedLong)
{
  byteBuffer[bytesFiled] = (theUnsignedLong >> 24) & 0xFF;
  bytesFiled++;
  testIfWriteNeeded();

  byteBuffer[bytesFiled] = (theUnsignedLong >> 16) & 0xFF;
  bytesFiled++;
  testIfWriteNeeded();
  
  byteBuffer[bytesFiled] = (theUnsignedLong >> 8) & 0xFF;
  bytesFiled++;
  testIfWriteNeeded();
  
  byteBuffer[bytesFiled] = theUnsignedLong & 0xFF;
  bytesFiled++;
  testIfWriteNeeded();
  
#ifdef DEBUG_BUFFER_FUNCTION  
    //sprintf(str,"Pos4 = %i, Pos3= %i, Pos2 = %i, Pos1= %i, value = %li", (theUnsignedLong >> 24) & 0xFF, (theUnsignedLong >> 16) & 0xFF,(theUnsignedLong >> 8) & 0xFF, theUnsignedLong & 0xFF, theUnsignedLong); 
    //Serial.println(str);
    sprintf(str,"Written LONG in positions %i, %i, %i and %i of byteBuffer for buffer num = %i", bytesFiled-4, bytesFiled-3, bytesFiled-2, bytesFiled-1, numOfWrittenBuffer); 
    Serial.println(str);    
    Serial.print( byteBuffer[bytesFiled-4], BIN);Serial.print("  ");
    Serial.print( byteBuffer[bytesFiled-3], BIN);Serial.print("  ");
    Serial.print( byteBuffer[bytesFiled-2], BIN);Serial.print("  ");
    Serial.println( byteBuffer[bytesFiled-1], BIN);Serial.print("  ");
    //Serial.println( (theUnsignedLong >> 24) & 0xFF, BIN);
    //Serial.println( (theUnsignedLong >> 18) & 0xFF, BIN);
    //Serial.println( (theUnsignedLong >> 8) & 0xFF, BIN);
    //Serial.println( theUnsignedLong & 0xFF, BIN);
    Serial.print( theUnsignedLong, BIN);Serial.print("  ");Serial.println( theUnsignedLong, DEC);
#endif
}


void write_String_InByteBuffer( char * theSTRING, int strSize)
{
  boolean endOfStringReached = false;
  for(int i= 0; i< strSize; i++)
  {
    if( !endOfStringReached) {byteBuffer[bytesFiled] = theSTRING[i];} else {byteBuffer[bytesFiled] = '\0';}
    if( theSTRING[i] == '\0') endOfStringReached = true;
    bytesFiled++;
    testIfWriteNeeded();
#ifdef DEBUG_BUFFER_FUNCTION  
    sprintf(str,"written STRING at position %i of byteBuffer for buffer n = %i", bytesFiled-1, numOfWrittenBuffer); 
    Serial.print(str);    
    sprintf(str,"  char = %c  ", byteBuffer[bytesFiled-1]);
    Serial.println(str); 
#endif
  }
}

