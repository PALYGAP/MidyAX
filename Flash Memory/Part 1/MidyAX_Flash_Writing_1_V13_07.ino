
#define ELECTRONIE_PROTO
#define DEBUG
//#define DEBUG_BUFFER_FUNCTION
//#define DEBUG_LEVEL2


#include <MidyAX_Flash_Addresses.h>
#include <MidyAX_Structs.h>
#include <SPI.h>
#include <MidyAX_Writing_FLASH.h>
#include "MidyAX_Flash_Data_1.h"

#include <SPI_FLASH_AL25L80_ELECTRONIE.h>


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



void WriteVarAndMemoryAddresses ()
{
  ///////////////////////////////////////////////////////////
  /////// WRITING MainParam_MemBlock  --> FIRST MEMBLOCK
  ///////////////////////////////////////////////////////////
  WRITING_currentMemAddresse = D_MainParam_MemBlock;
  
  startTime = millis();
#ifdef DEBUG
  sprintf(str, "D_MainParam_MemBlock = %i", WRITING_currentMemAddresse );
  Serial.println(str);
  sprintf(str, "START erasing block");
  Serial.println(str);
  unsigned long deb = millis();
#endif

  blockEraseFLASH( D_MainParam_MemBlock ); // Currently Erase Block 1 --> No need to erase anymore in this function

#ifdef DEBUG
  int temps = millis() - deb;
  sprintf(str, "END erase block. Took %i milliseconds", temps);
  Serial.println(str);
#endif
 
  // Writing Essential DATA value
  write_Int_InByteBuffer( MaxNumberOfControlPages );
  write_Int_InByteBuffer( MaxNumberOfParameters );
  write_Int_InByteBuffer( NumOfEffectTypes );
  write_Int_InByteBuffer( TotalNumOfParameters );
  write_Int_InByteBuffer( NumOfEffectBlocks );
  write_Int_InByteBuffer( NumOfModalList );
  flushByteBuffer(); /////////////////////////////////////// FLUSH OF BYTE BUFFER
  
  ///////////////////////////////////////////////////////////////
  /////// WRITING ListOfAddresses_MemBlock  --> THIRD MEMBLOCK
  ///////////////////////////////////////////////////////////////
  byte Stempo;
  unsigned long paramAddresse; 
  int Itempo;
  
  
  // Calculate addresse for the Param Array
  paramAddresse = D_EffectAndParam_MemBlock;
  paramAddresse += NumOfEffectTypes * sizeof(MEM_EffectType);

#ifdef DEBUG
  Itempo = sizeof(MEM_Parameter);
  Serial.println();Serial.println();
  Serial.println("/////// WRITING ListOfAddresses_MemBlock  --> THIRD MEMBLOCK");
  sprintf(str,"paramAddresse = %li sizeof MEM_Parameter = %i", paramAddresse, Itempo );
  Serial.println(str);
  //Serial.println(D_EffectAndParam_MemBlock, BIN);
  Serial.println(paramAddresse, BIN);
  Serial.println(sizeof(MEM_EffectType), BIN);
#endif  

  /////////////////////////////////////////////////////////////////////////////////////////////////////
  // Writing the array that contains the starting addresses of the Parameter structs for an Effect Type
  WRITING_currentMemAddresse = D_ListOfAddresses_MemBlock;
  startAddresseOfParameterAddresses = D_ListOfAddresses_MemBlock;
  for(int i = 0; i < NumOfEffectTypes; i++)
  {
    Stempo = byte( pgm_read_word( &( EffectType__numOfParameters[ i ] ) ) ); 
    write_UnsignedLong_InByteBuffer( paramAddresse );  // Addresse of the Parameter list 
    write_Byte_InByteBuffer( Stempo );                 // Number of parameters
    paramAddresse += sizeof(MEM_Parameter) * (unsigned long) Stempo;
    
#ifdef DEBUG
    sprintf(str,"Addresse[%i] = %i", i, Stempo); 
    Serial.println(str);
#endif    
  }

#ifdef DEBUG_LEVEL2
    elapsedTime = millis() - startTime;
    sprintf(str,"First Elaped Time = %i", elapsedTime); 
    Serial.println(str);
    Serial.flush();
#endif  

  
  //END of the list of array of addresses
  flushByteBuffer();  /////////////////////////////////////// FLUSH OF BYTE BUFFER
 
  ///////////////////////////////////////////////////////////////
  /////// WRITING AddresseOfList_MemBlock  --> SECOND MEMBLOCK
  /////////////////////////////////////////////////////////////// 
#ifdef DEBUG
  Serial.println();Serial.println();
  Serial.println("/////// WRITING ListOfAddresses_MemBlock  --> THIRD MEMBLOCK");
#endif
  WRITING_currentMemAddresse = D_AddresseOfList_MemBlock;
  startAddresseOfParameterAddresses = D_ListOfAddresses_MemBlock;
  write_UnsignedLong_InByteBuffer( startAddresseOfParameterAddresses );
  startAddresseOfModalListAddresses = D_ListOfAddresses_MemBlock + 5 * NumOfEffectTypes; 
  write_UnsignedLong_InByteBuffer( startAddresseOfModalListAddresses ); 

  ///////////////////////////////////////////////////////
  // DEBUG  
  // Read all the bytes written to memory
  int toread = 0; //bytesFiled + (numOfWrittenBuffer * 256);
  ///////////////////////////////////////////////////////

  flushByteBuffer();  /////////////////////////////////////// FLUSH OF BYTE BUFFER
  
  

  
#ifdef DEBUG
  WRITING_currentMemAddresse = D_ListOfAddresses_MemBlock;
  byte tempoBYTE = B11111111;
  Serial.println();
  for(int i=0; i <  toread; i++)
  {
    Serial.print( i, DEC);
    Serial.print(",  ");
    Serial.print( byteBuffer[i], BIN);
    Serial.print(",  ");
    Serial.print( byteBuffer[i], DEC);
    Serial.println();
    sprintf(str,"%i, address %i, ", i,WRITING_currentMemAddresse); 
    Serial.print(str);   
    Serial.print("READ = ");
    read_DataBytes_FLASH(WRITING_currentMemAddresse, &tempoBYTE, 1);
    WRITING_currentMemAddresse++;
    Serial.println( tempoBYTE, BIN);
    Serial.println();
   }
#endif     

#ifdef DEBUG_LEVEL2
  startTime = millis();
  //byte tempoBYTE = B11111111;
  for(int i=0; i <  toread; i++)
  {
    read_DataBytes_FLASH(WRITING_currentMemAddresse, &tempoBYTE, 1);
    WRITING_currentMemAddresse++;
  }    
  elapsedTime = millis() - startTime;
  sprintf(str,"Second Elaped Time = %i", elapsedTime); 
  Serial.println(str);
  Serial.flush();
#endif

}  // END OF WriteVarAndMemoryAddresses ()


void WriteEffectAndParam ()
{
  int Itempo, toread;
  byte Btempo;
  unsigned int UItempo;
  char buff20 [20] = { 0 };
  char buff50 [50] = { 0 };
  
  startTime = millis();
  WRITING_currentMemAddresse = D_EffectAndParam_MemBlock;

  // Erase memory block n° 2 and 3
  blockEraseFLASH( D_EffectAndParam_MemBlock );
  blockEraseFLASH( D_EffectAndParam_MemBlock + 0x10000);
 
#ifdef DEBUG
  Serial.println();Serial.println();
  Serial.println("/////// WRITING EFFECT TYPE array");
#endif  
 
  // WRITE Effect Type ARRAY
  for(int i=0; i < NumOfEffectTypes; i++)
  {
    Btempo = byte( pgm_read_word_near( &( EffectType__ID[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);

    strcpy_P( buff20, (char*)pgm_read_word( &( EffectType__name[i] ) ) ); // Necessary casts and dereferencing, just copy. 
    write_String_InByteBuffer( buff20, 20 );

    Btempo = char( pgm_read_word_near( &( EffectType__subTypeParamID[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);
    
    Btempo = byte( pgm_read_word_near( &( EffectType__onBypassParamID[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);
    
    Btempo = byte( pgm_read_word_near( &( EffectType__numOfParameters[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);
    
  } //Loop on the Effect Type


#ifdef DEBUG
  Serial.println();Serial.println();
  Serial.println("/////// WRITING PARAMETER array");
#endif
  
  // WRITE Parameter ARRAY
  for(int i=0; i < TotalNumOfParameters; i++)
  {
    Btempo = byte( pgm_read_word_near( &( Parameter__ID[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);

    strcpy_P( buff20, (char*)pgm_read_word( &( Parameter__name[i] ) ) );
    write_String_InByteBuffer( buff20, 20);

    strcpy_P( buff20, (char*)pgm_read_word( &( Parameter__label[i] ) ) );
    write_String_InByteBuffer( buff20, 20);

    Btempo = byte( pgm_read_word_near( &( Parameter__modifierID[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);
    
    Btempo = byte( pgm_read_word_near( &( Parameter__displayType[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);
    
    Btempo = byte( pgm_read_word_near( &( Parameter__type[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);

    UItempo = (unsigned int)( pgm_read_word_near( &( Parameter__defaultValue[ i ] ) ) );          
    write_Int_InByteBuffer( UItempo); // CHECK THAT IT IS OK !!! to use function to write in to write unsigned int !!!
    
    Itempo = (int)( pgm_read_word_near( &( Parameter__minDispValue[ i ] ) ) );          
    write_Int_InByteBuffer( Itempo);
    
    UItempo = (unsigned int)( pgm_read_word_near( &( Parameter__maxDispValue[ i ] ) ) );          
    write_Int_InByteBuffer( UItempo); // CHECK THAT IT IS OK !!! to use function to write in to write unsigned int !!!
    
    Btempo = byte( pgm_read_word_near( &( Parameter__precision[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);

    Btempo = byte( pgm_read_word_near( &( Parameter__unit[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);

    UItempo = (unsigned int)( pgm_read_word_near( &( Parameter__numVals[ i ] ) ) );          
    write_Int_InByteBuffer( UItempo); // CHEXK THAT IT IS OK !!!   

    Itempo = (int)( pgm_read_word_near( &( Parameter__idListVal[ i ] ) ) );          
    write_Int_InByteBuffer( Itempo); 
    
  } //Loop on the Effect Blocks
  
#ifdef DEBUG
  Serial.println();Serial.println();
  Serial.println("/////// WRITING EFFECT BLOCK array");
#endif

  // WRITE Effect Block ARRAY
  for(int i=0; i < NumOfEffectBlocks; i++)
  {
    Btempo = byte( pgm_read_word_near( &( EffectBlock__ID[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);

    strcpy_P( buff20, (char*)pgm_read_word( &( EffectBlock__name[i] ) ) ); // Necessary casts and dereferencing, just copy. 
    write_String_InByteBuffer( buff20, 20);

    Btempo = byte( pgm_read_word_near( &( EffectBlock__effectTypeID[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);
    
    Btempo = byte( pgm_read_word_near( &( EffectBlock__ONByPass_CC[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);
    
    Btempo = byte( pgm_read_word_near( &( EffectBlock__XY_CC[ i ] ) ) );          
    write_Byte_InByteBuffer( Btempo);
  } //Loop on the Effect Blocks

  toread = numOfWrittenBuffer + 2;
  flushByteBuffer();

  ///////////////////////////////////////////////////
  // Read all the bytes written to memory
#ifdef DEBUG
  unsigned long readMemAddresse1 = D_EffectAndParam_MemBlock;
  byte tempoBYTE1[256];
  Serial.print("Number of Buffer Written =");
  Serial.println(toread, DEC);
  for(int i=0; i < toread; i++)
  {
    read_DataBytes_FLASH(readMemAddresse1, tempoBYTE1, 256);
    sprintf(str,"Read at addr %lu, C=%s  ", readMemAddresse1, (char *) tempoBYTE1);
    Serial.println(str);
    sprintf(str," ADDR=%lu, ", readMemAddresse1 ); Serial.print(str);
    Serial.println(readMemAddresse1, BIN );
    for(int j=0; j <  256; j++)
    { 
      //Serial.print("Position ");Serial.print(j, DEC);Serial.print(", BYTE = ");
      //Serial.print(tempoBYTE[j], BIN);Serial.print(", DEC = ");Serial.println(tempoBYTE[j], DEC);   
      //Serial.print("P=");Serial.print(j, DEC);Serial.print(", B=");
      //Serial.print(tempoBYTE1[j], BIN);
      sprintf(str,"I=%i C=%c", (int) tempoBYTE1[j], (char) tempoBYTE1[j] ); Serial.println(str);      
    }
    readMemAddresse1 = readMemAddresse1 + (unsigned long) 256;
   }
#endif

  toread = numOfWrittenBuffer + 2;
  flushByteBuffer();



#ifdef DEBUG_LEVEL2
  startTime = millis();
  //byte tempoBYTE = B11111111;
  for(int i=0; i <  toread; i++)
  {
    read_DataBytes_FLASH(WRITING_currentMemAddresse, &tempoBYTE, 1);
    WRITING_currentMemAddresse++;
  }    
  elapsedTime = millis() - startTime;
  sprintf(str,"Fourth Elaped Time = %i", elapsedTime); 
  Serial.println(str);
  Serial.flush();
#endif
  
}






void setup()
{

  #ifdef ELECTRONIE_PROTO
    pinMode(HOLD, OUTPUT);           // Set pin connected to SPI HOLD chip select as output  
    pinMode(WRITE_PROTECT, OUTPUT);  // Set pin connected to SPI WRITE_PROTECT select as output  
    digitalWrite(HOLD, HIGH);  // NO HOLMD
    digitalWrite(WRITE_PROTECT, HIGH); // NO WRITE PROTECT
  #endif
  
  
  //Serial.begin(28800);
  Serial.begin(115200);
  Serial.println("STARTED");
  Serial.flush();
  

  SPI.begin ();
  SPI.setClockDivider(SPI_CLOCK_DIV4);

  info ();  
  
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
#endif

  WriteVarAndMemoryAddresses ();
  WriteEffectAndParam();

}




void loop()  {  }


