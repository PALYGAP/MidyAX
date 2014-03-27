#define ELECTRONIE_PROTO

#include <MidyAX_Flash_Addresses.h>
#include "MidyAX_Writing_FLASH.h"
#include "MidyAX_Flash_Data_2.h"
#include <MidyAX_Structs.h>
#include <SPI.h>
#include <SPI_FLASH_AL25L80_ELECTRONIE.h>
//#define DEBUG_BUFFER_FUNCTION


#define DEBUG
#define DEBUG_LEVEL2



    #define CHIP_SELECT 53
    #define HOLD 49
    #define WRITE_PROTECT 48


char str[100];
unsigned int startTime, elapsedTime;

//#define lowByte(w) ((uint8_t) ((w) & 0xff))
//#define highByte(w) ((uint8_t) ((w) >> 8))

extern unsigned long WRITING_currentMemAddresse;
extern byte MSB, LSB ;
extern byte byteBuffer[256];
extern int bytesFiled;
extern int numOfWrittenBuffer;


// To store addresse of the array of addresses
unsigned long startAddresseOfParameterAddresses;
unsigned long startAddresseOfModalListAddresses;



void WriteModalLists ()
{
  int Itempo, toread;
  byte Btempo;
  unsigned int UItempo;
  char buff20 [20] = { 0 };
  char buff50 [50] = { 0 };
  
  startTime = millis();

  WRITING_currentMemAddresse = D_ModalLists_MemBlock;
  byte THEbyteBuffer[256];
  
  byte Fstatus; 
  Fstatus = readStatus();
  Serial.print("Read Status Bits = ");
  Serial.println(Fstatus, BIN);Serial.println();

  Serial.println("START erasing BLOCK D_ModalLists_MemBlock 1");
  blockEraseFLASH( WRITING_currentMemAddresse );
  Serial.println("END erasing D_ModalLists_MemBlock 1");
  elapsedTime = millis() - startTime;
  sprintf(str,"Third Elaped Time = %i", elapsedTime); 
  Serial.println(str);Serial.println();

  Serial.println("START erasing D_ModalLists_MemBlock 2");
  blockEraseFLASH( WRITING_currentMemAddresse +  0x10000 );
  Serial.println("END erasing D_ModalLists_MemBlock 2");
  elapsedTime = millis() - startTime;
  sprintf(str,"Third Elaped Time = %i", elapsedTime); 
  Serial.println(str);
  
#ifdef DEBUG_LEVEL2
    elapsedTime = millis() - startTime;
    sprintf(str,"Third Elaped Time = %i", elapsedTime); 
    Serial.println(str);
    Serial.flush();
#endif  


  ////////////////////////////////////////////////////////////////// 
  // WRITE Modal Lists
 
#ifdef DEBUG
  Serial.println();Serial.println();
  Serial.println("/////// WRITING MODAL lists");
#endif  
  for(int i=0; i < NumOfModalList; i++)
  {
    char **strOfStr;
    Btempo = byte( pgm_read_word_near( &( ModalList_size[ i ] ) ) );    
    strOfStr = (char**) pgm_read_word( &( ModalList_list[i] ) );
    for(int j = 0; j < Btempo; j++)
    {
      strcpy_P( buff50, (char*)pgm_read_word( &( strOfStr[j] ) ) ); // Necessary casts and dereferencing, just copy. 
      // Stockage de la taille de la chaine de charactère
      write_Byte_InByteBuffer( (byte) strlen( buff50 ) );
      // Stockage de la chaine de charactères
      write_String_InByteBuffer(  buff50, strlen( buff50 ) ); //
#ifdef DEBUG
    sprintf(str,"Modal list %i element %i, string = %s, size = %i  ", i, j, buff50, strlen( buff50 ) ); 
    Serial.println(str);   
#endif     
    }  
  } //Loop on the Modal List

  // No Need for correspondance table ???

  toread = numOfWrittenBuffer + 1;
    int toread1 = numOfWrittenBuffer *256 + bytesFiled;
  flushByteBuffer();

#ifdef DEBUG
  unsigned long readMemAddresse = D_ModalLists_MemBlock; // 0x11000
  byte tempoBYTE1 = B11111111;
  Serial.println();
  for(int i=0; i <  toread1; i++)
  {
    sprintf(str,"%i, address=%lu ", i,readMemAddresse); Serial.print(str);   
    read_DataBytes_FLASH(readMemAddresse, &tempoBYTE1, 1);
    Serial.print("BYTE= ");Serial.print( tempoBYTE1, BIN);
    Serial.print(" INT= ");Serial.print( tempoBYTE1, DEC);
    sprintf(str," C=%c", (char) tempoBYTE1 ); Serial.println(str);
    //Serial.println();
    readMemAddresse++;
   }
   Serial.println();Serial.println();
#endif

/*
  ///////////////////////////////////////////////////
  // Read all the bytes written to memory
#ifdef DEBUG
  unsigned long readMemAddresse = D_ModalLists_MemBlock;
  byte tempoBYTE[256];
  Serial.println();
  for(int i=0; i < toread; i++)
  {
    read_DataBytes_FLASH(readMemAddresse, tempoBYTE, 256);
    sprintf(str,"Read at add %li, I= %i, C=%s  ", readMemAddresse, tempoBYTE, (char *) tempoBYTE);
    Serial.println(str);
    sprintf(str," ADDR=%li,  ", readMemAddresse ); Serial.print(str);
    Serial.println(readMemAddresse, BIN );
    for(int j=0; j <  256; j++)
    { 
      //Serial.print("Position ");Serial.print(j, DEC);Serial.print(", BYTE = ");
      //Serial.print(tempoBYTE[j], BIN);Serial.print(", DEC = ");Serial.println(tempoBYTE[j], DEC);   
      Serial.print("P=");Serial.print(j, DEC);Serial.print(", B="); Serial.print(tempoBYTE[j], BIN);
      sprintf(str," I=%i, C=%c", (int) tempoBYTE[j], (char) tempoBYTE[j] ); Serial.println(str);      
    }
    readMemAddresse = readMemAddresse + (unsigned long) 256;
   }
#endif


#ifdef DEBUG_LEVEL2
  startTime = millis();
  byte tempoBYTE1 = B11111111;
  for(int i=0; i <  toread; i++)
  {
    read_DataBytes_FLASH(currentMemAddresse, &tempoBYTE1, 1);
    currentMemAddresse++;
  }    
  elapsedTime = millis() - startTime;
  sprintf(str,"Fourth Elaped Time = %i", elapsedTime); 
  Serial.println(str);
  Serial.flush();
#endif
*/
  
}


void WriteArrayModalListAddresses ()
{
  unsigned long paramAddresse; 
 
  ///////////////////////////////////////////////////////////////////////////
  // Writing the array that contains the starting addresses of the Modal List
  // NumOfModalList is the number of unique Modal List.
  WRITING_currentMemAddresse = D_startAddresseOfModalListAddresses; // 0x11000

  sectorEraseFLASH(WRITING_currentMemAddresse);
  
  //Modal lists writing to memory starts after the EffectBlock 
  paramAddresse = D_ModalLists_MemBlock;
  byte numElem;
  char **strOfStr, buff[50];
  int lengthOfModalList;
  unsigned long paramAddresse2;
  
  for(int i = 0; i < NumOfModalList; i++)
  {
    lengthOfModalList = 0;
    numElem = byte( pgm_read_word( &( ModalList_size[ i ] ) ) );
    write_UnsignedLong_InByteBuffer( paramAddresse );  // Addresse of the Modal List
    write_Byte_InByteBuffer( numElem );                // Number of Modal Values

#ifdef DEBUG
      sprintf(str,"paramAddresse = %lu, numElem = %i", paramAddresse, numElem ); Serial.println(str);
#endif 

    paramAddresse2 = paramAddresse;
    // Add the sizes of all the string of the modal list
    strOfStr = (char**) pgm_read_word( &( ModalList_list[i] ) );
    for(int j = 0; j < numElem; j++)
    {
      strcpy_P( buff, (char*)pgm_read_word( &( strOfStr[j] ) ) );
      paramAddresse += strlen ( buff ) + 1; // +1 to store the length of the modal string
      lengthOfModalList += strlen ( buff ) + 1;
#ifdef DEBUG
      sprintf(str,"i = %i, j = %i, buff = %s, strlen ( buff ) = %i", i, j,  buff, strlen ( buff ) ); Serial.println(str);
#endif 
    }
   
#ifdef DEBUG
    sprintf(str,"Addresse[%i] = %lu, lengthOfModalList = %i", i, paramAddresse2, lengthOfModalList ); 
    Serial.println(str);
    Serial.println(paramAddresse2, BIN);
#endif    
  }


  int toread = numOfWrittenBuffer + 1;
  int toread1 = numOfWrittenBuffer *256 + bytesFiled;
  flushByteBuffer();  /////////////////////////////////////// FLUSH OF BYTE BUFFER
  

#ifdef DEBUG
  unsigned long readMemAddresse = D_startAddresseOfModalListAddresses; // 0x11000
  byte tempoBYTE1 = B11111111;
  Serial.println();
  for(int i=0; i <  toread1; i++)
  {
    sprintf(str,"%i, address=%lu ", i,readMemAddresse); Serial.print(str);   
    read_DataBytes_FLASH(readMemAddresse, &tempoBYTE1, 1);
    Serial.print("BYTE= ");Serial.print( tempoBYTE1, BIN);
    Serial.print(" INT= ");Serial.println( tempoBYTE1, DEC);
    //Serial.println();
    readMemAddresse++;
   }
   Serial.println();Serial.println();
#endif     

  ///////////////////////////////////////////////////
  // Read all the bytes written to memory
#ifdef DEBUG
  readMemAddresse = D_startAddresseOfModalListAddresses; // 0x11000
  byte tempoBYTE[256];
  Serial.println();
  for(int i=0; i < toread; i++)
  {
    read_DataBytes_FLASH(readMemAddresse, tempoBYTE, 256);
    sprintf(str,"Read at add %lu", readMemAddresse);Serial.println(str);
    sprintf(str," ADDR=%lu,  ", readMemAddresse ); Serial.print(str);
    Serial.println(readMemAddresse, BIN );
    for(int j=0; j <  256; j++)
    { 
      //Serial.print("Position ");Serial.print(j, DEC);Serial.print(", BYTE = ");
      //Serial.print(tempoBYTE[j], BIN);Serial.print(", DEC = ");Serial.println(tempoBYTE[j], DEC);   
      Serial.print("P=");Serial.print(j, DEC);Serial.print(", B="); Serial.print(tempoBYTE[j], BIN);
      sprintf(str," I=%i, C=%c", (int) tempoBYTE[j], (char) tempoBYTE[j] ); Serial.println(str);      
    }
    readMemAddresse = readMemAddresse + (unsigned long) 256;
   }
#endif

}




void setup()
{
  
  //#ifdef ELECTRONIE_PROTO
    pinMode(HOLD, OUTPUT);           // Set pin connected to SPI HOLD chip select as output  
    pinMode(WRITE_PROTECT, OUTPUT);  // Set pin connected to SPI WRITE_PROTECT select as output  
    digitalWrite(HOLD, HIGH);  // NO HOLMD
    digitalWrite(WRITE_PROTECT, HIGH); // NO WRITE PROTECT
  //#endif
  
  Serial.begin(115200);
  Serial.println("STARTED");
  Serial.flush();
  SPI.begin ();
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  info ();  

#ifdef DEBUG
  int sizeEffectBlock = sizeof(MEM_EffectBlock);
  sprintf(str, "Size of EffectBlock = %i", sizeEffectBlock);
  Serial.println(str);
  int sizeParameter = sizeof(MEM_Parameter);
  sprintf(str, "Size of Parameter = %i", sizeParameter);
  Serial.println(str);
  int sizeEffectType = sizeof(MEM_EffectType);
  sprintf(str, "Size of EffectType = %i", sizeEffectType);
  Serial.println(str);
  sprintf(str, "NumOfModalList = %i", NumOfModalList);
  Serial.println(str);  
  
#endif

/*
  //ERASE FLASH CHIP !!!
#ifdef DEBUG
  sprintf(str, "START erasing chip");
  Serial.println(str);
  unsigned long deb = millis();
#endif 
  chipEraseFLASH();
#ifdef DEBUG
  unsigned long temps = millis() - deb;
  sprintf(str, "END erasing chip. Took %i milliseconds", temps);
  Serial.println(str);
#endif
 */

  WriteArrayModalListAddresses ();
  WriteModalLists();
}

void loop()
{
  
}


