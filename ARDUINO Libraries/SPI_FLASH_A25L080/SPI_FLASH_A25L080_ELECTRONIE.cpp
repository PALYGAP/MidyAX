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

#include "SPI_FLASH_AL25L80_ELECTRONIE.h";
#include <SPI.h>
#include <Arduino.h>

//#define DEBUG_READ_STR

// wait until chip not busy
void notBusy ()
{
  digitalWrite (CHIP_SELECT, LOW);
#ifdef DEBUG
  Serial.println ("After notBusy -- digitalWrite (CHIP_SELECT, LOW)");
#endif


  SPI.transfer (ReadStatus);     
#ifdef DEBUG
  Serial.println ("After notBusy -- SPI.transfer (ReadStatus)");   
#endif
  // wait until busy bit cleared
  while (SPI.transfer (0) & 1) {}
  
#ifdef DEBUG
  Serial.println ("After notBusy -- while (SPI.transfer (0) & 1)"); 
#endif
  digitalWrite (CHIP_SELECT, HIGH);  
#ifdef DEBUG
  Serial.println ("After notBusy -- digitalWrite (CHIP_SELECT, HIGH)"); 
#endif 
}  // end notBusy

// enable writing
void writeEnable ()
{
 notBusy ();
 
 digitalWrite (CHIP_SELECT, LOW);
 SPI.transfer (WriteEnable);       
 digitalWrite (CHIP_SELECT, HIGH);  
}  // end of writeEnable

// read device status
byte readStatus (void)
{
 digitalWrite (CHIP_SELECT, LOW);
 SPI.transfer (ReadStatus);       
 byte status = SPI.transfer (status);       
 digitalWrite (CHIP_SELECT, HIGH);  
  
 return status;
}  // end of readStatus

// write status register
void writeStatus (const byte status)
{
   writeEnable ();
   //Serial.println ("After writeStatus -- writeEnable"); 
   notBusy ();  // wait until ready
   //Serial.println ("After writeStatus -- notBusy"); 
   
   digitalWrite (CHIP_SELECT, LOW);
   //Serial.println ("After writeStatus -- digitalWrite (CHIP_SELECT, LOW)"); 
   SPI.transfer (WriteStatus);       
   //Serial.println ("After writeStatus -- SPI.transfer (WriteStatus)");
   SPI.transfer (status);       
   //Serial.println ("After writeStatus -- SPI.transfer (status)");
   digitalWrite (CHIP_SELECT, HIGH);  
   //Serial.println ("After writeStatus -- digitalWrite (CHIP_SELECT, HIGH)");
   
}  // end of writeStatus

// send a command to the EEPROM followed by a 3-byte address
void sendCommandAndAddress (const byte command, const unsigned long addr)
{
  SPI.transfer (command);       
  SPI.transfer ((addr >> 16) & 0xFF);       
  SPI.transfer ((addr >> 8) & 0xFF);       
  SPI.transfer (addr & 0xFF);       
}  // end of sendCommandAndAddress

// write len (max 256) bytes to device

// Note that if writing multiple bytes the address plus
//  length must not cross a 256-byte boundary or it will "wrap"
void writeEEPROM (const unsigned long addr, byte * data, int len) 
{
  // now write to it
  writeEnable ();
  
  notBusy ();  // wait until ready
  digitalWrite (CHIP_SELECT, LOW);
  sendCommandAndAddress (PageProgram, addr);
  for ( ; len ; --len)
    SPI.transfer (*data++);       
  digitalWrite (CHIP_SELECT, HIGH);  
  notBusy (); 
} // end of writeEEPROM

// write one byte to device
void writeEEPROM (unsigned long addr, byte data) 
{
  writeEEPROM (addr, &data, 1);
} // end of writeEEPROM

// read len bytes from device
void read_DataBytes_FLASH (const unsigned long addr, byte * data, unsigned int len) 
{
  notBusy ();  // wait until ready
  digitalWrite (CHIP_SELECT, LOW);
  sendCommandAndAddress (ReadDataBytes, addr);
  //SPI.transfer (0);  // clock in "don't care" byte
  for ( ; len ; --len)
   *data++ = SPI.transfer (0);       
  digitalWrite (CHIP_SELECT, HIGH);  
} 

void read_Int_FLASH (const unsigned long addr, int * data) 
{
    byte MSB, LSB ;
    notBusy ();  // wait until ready
    digitalWrite (CHIP_SELECT, LOW);
    sendCommandAndAddress (ReadDataBytes, addr);
    //SPI.transfer (0);  // clock in "don't care" byte
    MSB = SPI.transfer (0);   
    LSB = SPI.transfer (0);    
    *data = (int) ( (MSB) <<8 ) | (LSB );
    digitalWrite (CHIP_SELECT, HIGH);
}

//////// ANALYSER diff entre lecture int et unsigned int

void read_UnsignedInt_FLASH (const unsigned long addr, unsigned int * data) 
{
    byte MSB, LSB ;
    notBusy ();  // wait until ready
    digitalWrite (CHIP_SELECT, LOW);
    sendCommandAndAddress (ReadDataBytes, addr);
    //SPI.transfer (0);  // clock in "don't care" byte
    MSB = SPI.transfer (0);   
    LSB = SPI.transfer (0);    
    *data = (unsigned int) ( (MSB) <<8 ) | (LSB );
    digitalWrite (CHIP_SELECT, HIGH);
}

void read_String_FLASH (const unsigned long addr, char *theString, byte *strSize) 
{
    *strSize = 0;
    char str[50];
    byte theBYTE;
    //Serial.println("START read_String_FLASH");
    notBusy ();  // wait until ready
    digitalWrite (CHIP_SELECT, LOW);
    sendCommandAndAddress (ReadDataBytes, addr);
    //SPI.transfer (0);  // clock in "don't care" byte      
    do {
        theBYTE =  SPI.transfer (0);
        theString[ int(*strSize) ] =  (char) theBYTE;
#ifdef DEBUG_READ_STR        
        Serial.println( theBYTE, BIN );
        sprintf(str,"Character %i = %c", (int) *strSize, theString[ int(*strSize) ] );Serial.println(str);
        Serial.println( theString[ int(*strSize)], DEC );
        Serial.println( theString[ int(*strSize)], HEX );
#endif
		*strSize = *strSize + 1;
        if( *strSize > 20) break;
    } while ( theBYTE != B00000000 );
    digitalWrite (CHIP_SELECT, HIGH);
    //*strSize = *strSize - 1;
    //theString[ int(*strSize) ] = '\0';
} 

void read_SizedString_FLASH (const unsigned long addr, char *theString, byte strSize) 
{
    char str[50];
    byte theBYTE;
    //Serial.println("START read_SizedString_FLASH");
    notBusy ();  // wait until ready
    digitalWrite (CHIP_SELECT, LOW);
    sendCommandAndAddress (ReadDataBytes, addr);
    //SPI.transfer (0);  // clock in "don't care" byte      
    for (int i= 0; i < (int) strSize ; i++) 
    {
        theBYTE =  SPI.transfer (0);
        theString[ i ] =  (char) theBYTE;
#ifdef DEBUG_READ_STR        
        Serial.println( theBYTE, BIN );
        sprintf(str,"Character %i = %c", (int) i, theString[ i ] );Serial.println(str);
        Serial.println( theString[ int(i)], DEC );
        Serial.println( theString[ int(i)], HEX );
#endif
    }
    digitalWrite (CHIP_SELECT, HIGH);
    theString[ int(strSize) ] = '\0';
} 

void read_UnsignedLong_FLASH (const unsigned long addr, unsigned long * data) 
{
    byte pos4, pos3, pos2, pos1 ;
    char str[150];
    unsigned long data2, data3, data4;
    
    notBusy ();  // wait until ready
    digitalWrite (CHIP_SELECT, LOW);
    sendCommandAndAddress (ReadDataBytes, addr);
    //SPI.transfer (0);  // clock in "don't care" byte
    pos4 = SPI.transfer (0);
    //Serial.println( pos4, BIN );
    pos3 = SPI.transfer (0);
    //Serial.println( pos3, BIN );
    pos2 = SPI.transfer (0);
    //Serial.println( pos2, BIN );
    pos1 = SPI.transfer (0);
    //Serial.println( pos1, BIN );
    //*data = (unsigned long) ((pos4) <<24 ) | ((pos3) <<16 ) | ((pos2) <<8 ) | (pos1);
    
    //sprintf(str,"Read UNSIGNED LONG = %lu, %x", *data, *data );Serial.println(str);
    //Serial.println(*data, BIN);
    
    //data2 = (unsigned int) (pos1);
    //Serial.println(data2, BIN);
    data2 = (unsigned int) ((pos2) <<8 ) | (pos1);
    //Serial.println(data2, BIN);
    //data3 = (unsigned long) (pos3);
    //Serial.println(data3, BIN);
    data3 = (unsigned long)  ((pos4) <<8 ) | (pos3);
    //Serial.println(data3, BIN);
    //sprintf(str,"%lu, %lu", data2, data3 );Serial.println(str);
    
    data4 = (unsigned long)  ((data3) <<16 ) | (data2);
    //Serial.println(data4, BIN);
    
    *data = data4;

    //sprintf(str,"READ & RETURNED UNSIGNED LONG = %lu", *data );Serial.println(str);
    //Serial.println(*data, BIN);
    
    digitalWrite (CHIP_SELECT, HIGH);
}




// Erase a sector of bytes which contains addr
void sectorEraseFLASH (const unsigned long addr)
{
  writeEnable ();
  notBusy ();  // wait until ready
  digitalWrite (CHIP_SELECT, LOW);
  sendCommandAndAddress (SectorErase, addr);
  digitalWrite (CHIP_SELECT, HIGH);  
  notBusy ();  // wait until done
}

// Erase a block of bytes which contains addr
void blockEraseFLASH (const unsigned long addr)
{
  writeEnable ();
  notBusy ();  // wait until ready
  digitalWrite (CHIP_SELECT, LOW);
  sendCommandAndAddress (BlockErase, addr);
  digitalWrite (CHIP_SELECT, HIGH);  
  notBusy ();  // wait until done
}

// Erase the whole chip
void chipEraseFLASH ()
{
  writeEnable ();
  notBusy ();  // wait until ready
  digitalWrite (CHIP_SELECT, LOW);
  SPI.transfer (ChipErase); //No address is needed
  //sendCommandAndAddress (BlockErase, addr);
  digitalWrite (CHIP_SELECT, HIGH);  
  notBusy ();  // wait until done
}



// show device info and status
byte info ()
{
  byte ID;
  notBusy (); // wait until ready
  
  digitalWrite (CHIP_SELECT, LOW);
  SPI.transfer (ReadManufacturer);       

  #ifdef DEBUG 
    Serial.print ("Manufacturer: ");
    Serial.println (SPI.transfer (0), HEX);
    Serial.print ("Device ID Part 1: ");
    Serial.println (SPI.transfer (0), HEX);
    Serial.print ("Device ID Part 2: ");
    Serial.println (SPI.transfer (0), HEX);
    Serial.print ("Extended Information Length: ");
    Serial.println (SPI.transfer (0),HEX);
  #else
    ID = SPI.transfer(0);
  #endif
    
  digitalWrite (CHIP_SELECT, HIGH);

  #ifdef DEBUG  
    Serial.print ("Status: ");
    Serial.println (readStatus (), HEX);
  #endif

  return ID;
} // end of info

