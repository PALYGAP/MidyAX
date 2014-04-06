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

// Defines the SPI functions of the FLASH SPI memory A25L080

//  !!!!!!!!!!!!!! This files needs to be updated with the proper values !!!!!!!!!!!!!!


#ifndef SPI_FLASH_A25L080_H_
#define SPI_FLASH_A25L080_H_

#include "arduino.h"

#define CHIP_SELECT 53
#define HOLD 49
#define WRITE_PROTECT 48




// AT25DF041A EEPROM commands

// reading
#define ReadDataBytesAtHigherSpeed  0x0B
#define ReadDataBytes               0x03

// programming
#define SectorErase         0x20
#define BlockErase          0xD8
#define ChipErase           0xC7

#define PageProgram         0x02
//#define SequentialProgram   0xAD

// protection
#define WriteEnable           0x06
#define WriteDisable          0x04
#define ProtectSector         0x36
#define UnProtectSector       0x39
#define ReadSectorProtection  0x3C

// status
#define ReadStatus 0x05
#define WriteStatus 0x01

// miscellaneous
#define ReadManufacturer     0x9F
#define DeepPowerDown        0xB9
#define ResumeFromPowerDown  0xAB


void notBusy ();// wait until chip not busy
void writeEnable ();// enable writing
byte readStatus (void);// read device status
void writeStatus (const byte status);// write status register
void sendCommandAndAddress (const byte command, const unsigned long addr);// send a command to the EEPROM followed by a 3-byte address
// Note that if writing multiple bytes the address plus
//  length must not cross a 256-byte boundary or it will "wrap"
void writeEEPROM (const unsigned long addr, byte * data, int len); // write len (max 256) bytes to device
void writeEEPROM (unsigned long addr, byte data); // write one byte to device
void read_DataBytes_FLASH (const unsigned long addr, byte * data, unsigned int len); // read len bytes from device
void read_Int_FLASH (const unsigned long addr, int * data);
void read_UnsignedInt_FLASH (const unsigned long addr, unsigned int * data);
void read_String_FLASH (const unsigned long addr, char *theString, byte *size);
void read_SizedString_FLASH (const unsigned long addr, char *theString, byte strSize);
void read_UnsignedLong_FLASH (const unsigned long addr, unsigned long * data); 

void sectorEraseFLASH (const unsigned long addr);
void blockEraseFLASH (const unsigned long addr);
void chipEraseFLASH ();
byte info (); // show device info and status















#endif // A25L080_H_
