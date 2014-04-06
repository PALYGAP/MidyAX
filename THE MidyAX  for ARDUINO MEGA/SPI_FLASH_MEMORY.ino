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

extern unsigned long WRITING_currentMemAddresse;
extern byte MSB, LSB ;
extern byte byteBuffer[256];
extern int bytesFiled;
extern int numOfWrittenBuffer;

#include "MidyAX_Writing_FLASH.h"



///////////////////////////////////////////////////////////////////////////////////
// Initializes the mappings of the MidyAX that are stored in the SPI FLASH MEMORY
///////////////////////////////////////////////////////////////////////////////////
// TODO : This function is not currently in use
byte Init_MAPPINGs( )
{

  
  // Erase before Writing
  WRITING_currentMemAddresse = SFMA_Mapping_FACTORY_EffectType; // 0x70000
  sectorEraseFLASH(WRITING_currentMemAddresse); // Erase from 0x70000 to 0x7FFFF  
  WRITING_currentMemAddresse = SFMA_Mapping_FACTORY_EffectType_Parameter_Mapping; // 0x80000
  sectorEraseFLASH(WRITING_currentMemAddresse); // Erase from 0x80000 to 0x8FFFF  
  WRITING_currentMemAddresse = SFMA_Mapping_FACTORY_QuickAccess_Parameters_Mapping; // 0x90000
  sectorEraseFLASH(WRITING_currentMemAddresse); // Erase from 0x90000 to 0x9FFFF  



  // FACTORY //
  // Writing Mapping_FACTORY_EffectType in Mapping_FACTORY_EffectType location 
  WRITING_currentMemAddresse = SFMA_Mapping_FACTORY_EffectType; // 0x70000
  for(int i=0; i < BCR2000_NumberOf_ControlPage_Buttons_DEFINE * 2; i++)
  {
    write_Byte_InByteBuffer( pgm_read_byte_near( Mapping_FACTORY_EffectType + i ) );
  }
  flushByteBuffer();

  // USER //
  // Writing Mapping_FACTORY_EffectType in Mapping_USER_EffectType location   
  WRITING_currentMemAddresse = SFMA_Mapping_USER_EffectType_Mapping; // 0x70100
  for(int i=0; i < BCR2000_NumberOf_ControlPage_Buttons_DEFINE * 2; i++)
  {
    write_Byte_InByteBuffer( pgm_read_byte_near( Mapping_FACTORY_EffectType + i ) );
  }
  flushByteBuffer();  




  // FACTORY //
  // Writing Mapping_FACTORY_EffectType_Parameter_Mapping in Mapping_FACTORY_EffectType_Parameter_Mapping location   
  for(int i=0; i < BCR2000_NumberOf_ControlPage_Buttons_DEFINE * 2; i++)
  {
    for(int j=0; j < ControlPages_NumberOf_Sub_Pages_DEFINE; j++)
    {
      WRITING_currentMemAddresse = SFMA_Mapping_FACTORY_EffectType_Parameter_Mapping + 256 * j * i;   // Start 0x80000
      for(int k=0; k < BCR2000_NumberOf_Controls_DEFINE; k++)
      {
        write_Byte_InByteBuffer( pgm_read_byte_near( Mapping_FACTORY_EffectType + i ) );    // EFFECT_TYPE ID
        
        write_Byte_InByteBuffer( pgm_read_byte_near(
                           Mapping_FACTORY_EffectType_Parameter_Mapping 
                           + (i * ControlPages_NumberOf_Sub_Pages_DEFINE * BCR2000_NumberOf_Controls_DEFINE )
                           + ( j * BCR2000_NumberOf_Controls_DEFINE )
                           + k
                           ) ); // PARAMETER ID
      }
      flushByteBuffer();  
    }
  }

 
  // USER //
  // Writing Mapping_FACTORY_EffectType_Parameter_Mapping in Mapping_USER_EffectType_Parameter_Mapping location   
  for(int i=0; i < BCR2000_NumberOf_ControlPage_Buttons_DEFINE * 2; i++)
  {
    for(int j=0; j < ControlPages_NumberOf_Sub_Pages_DEFINE; j++)
    {
      WRITING_currentMemAddresse = SFMA_Mapping_USER_EffectType_Parameter_Mapping + 256 * j * i;     // Start 0x90000
      for(int k=0; k < BCR2000_NumberOf_Controls_DEFINE; k++)
      {      
        write_Byte_InByteBuffer( pgm_read_byte_near( Mapping_FACTORY_EffectType + i ) );    // EFFECT_TYPE ID

        write_Byte_InByteBuffer( pgm_read_byte_near(
                           Mapping_FACTORY_EffectType_Parameter_Mapping 
                           + (i * ControlPages_NumberOf_Sub_Pages_DEFINE * BCR2000_NumberOf_Controls_DEFINE )
                           + ( j * BCR2000_NumberOf_Controls_DEFINE )
                           + k
                           ) ); // PARAMETER ID
      }
      flushByteBuffer(); 
    }
  }
 


  // FACTORY //
  // Writing Mapping_FACTORY_QuickAccess_Parameters_Mapping in Mapping_FACTORY_QuickAccess_Parameters_Mapping location   
  for(int i=0; i < ControlPages_NumberOf_QuickAccess_Page_DEFINE ; i++)
  {
    for(int j=0; j < ControlPages_NumberOf_Sub_Pages_DEFINE; j++)
    {
      WRITING_currentMemAddresse = SFMA_Mapping_FACTORY_QuickAccess_Parameters_Mapping + 256 * j * i;  // Start = 0x71000
      for(int k=0; k < BCR2000_NumberOf_Controls_DEFINE; k++)
      {
        write_Byte_InByteBuffer( pgm_read_byte_near(
                           Mapping_FACTORY_QuickAccess_Parameters_Mapping 
                           + ( i * ControlPages_NumberOf_Sub_Pages_DEFINE * BCR2000_NumberOf_Controls_DEFINE )
                           + ( j * BCR2000_NumberOf_Controls_DEFINE )
                           + ( k * 2 ) 
                           ) );   // EFFECT_TYPE ID
        
        write_Byte_InByteBuffer( pgm_read_byte_near( 
                           Mapping_FACTORY_QuickAccess_Parameters_Mapping 
                           + (i * ControlPages_NumberOf_Sub_Pages_DEFINE * BCR2000_NumberOf_Controls_DEFINE )
                           + ( j * BCR2000_NumberOf_Controls_DEFINE )
                           + ( k * 2)
                           + 1 
                           ) ); // PARAMETER ID
      }
    flushByteBuffer();
    }
  }
  

  // USER //
  // Writing Mapping_FACTORY_QuickAccess_Parameters_Mapping in Mapping_USER_QuickAccess_Parameters_Mapping location   
  for(int i=0; i < ControlPages_NumberOf_QuickAccess_Page_DEFINE ; i++)
  {
    for(int j=0; j < ControlPages_NumberOf_Sub_Pages_DEFINE; j++)
    {
      WRITING_currentMemAddresse = SFMA_Mapping_USER_QuickAccess_Parameters_Mapping + 256 * j * i;  // Start = 0x72000
      for(int k=0; k < BCR2000_NumberOf_Controls_DEFINE; k++)
      {
        write_Byte_InByteBuffer( pgm_read_byte_near(
                           Mapping_FACTORY_QuickAccess_Parameters_Mapping 
                           + ( i * ControlPages_NumberOf_Sub_Pages_DEFINE * BCR2000_NumberOf_Controls_DEFINE )
                           + ( j * BCR2000_NumberOf_Controls_DEFINE )
                           + ( k * 2 ) 
                           ) );   // EFFECT_TYPE ID
        
        write_Byte_InByteBuffer( pgm_read_byte_near( 
                           Mapping_FACTORY_QuickAccess_Parameters_Mapping 
                           + (i * ControlPages_NumberOf_Sub_Pages_DEFINE * BCR2000_NumberOf_Controls_DEFINE )
                           + ( j * BCR2000_NumberOf_Controls_DEFINE )
                           + ( k * 2)
                           + 1 
                           ) ); // PARAMETER ID
      }
      flushByteBuffer();
    }
  }





  // FACTORY //
  // Writing Mapping_FACTORY_ET_Page_BCR2000_Preset in Mapping_FACTORY_ET_Page_BCR2000_Preset location 
  WRITING_currentMemAddresse = SFMA_Mapping_FACTORY_ET_Page_BCR2000_Preset; // 0x73000
  for(int i=0; i < Mapping_NumberOf_ET_BCR2000_Preset_DEFINE; i++)
  {
    write_Byte_InByteBuffer( pgm_read_byte_near( Mapping_FACTORY_ET_Page_BCR2000_Preset + ( i * 2)  ) );
    write_Byte_InByteBuffer( pgm_read_byte_near( Mapping_FACTORY_ET_Page_BCR2000_Preset + ( i * 2) + 1  ));
  }
  flushByteBuffer();  
  
  // USER //
  // Writing Mapping_FACTORY_ET_Page_BCR2000_Preset in Mapping_USER_ET_Page_BCR2000_Preset location 
  WRITING_currentMemAddresse = SFMA_Mapping_USER_ET_Page_BCR2000_Preset; // 0x73100
  for(int i=0; i < Mapping_NumberOf_ET_BCR2000_Preset_DEFINE; i++)
  {
    write_Byte_InByteBuffer( pgm_read_byte_near( Mapping_FACTORY_ET_Page_BCR2000_Preset + ( i * 2)  ) );
    write_Byte_InByteBuffer( pgm_read_byte_near( Mapping_FACTORY_ET_Page_BCR2000_Preset + ( i * 2) + 1 ) );
  }
  flushByteBuffer(); 
  


  // Initializing Mapping_UsageStats_EF_ControlPages 
  WRITING_currentMemAddresse = SFMA_Mapping_UsageStats_EF_ControlPages; // 0x73200
  for(int i=0; i < ControlPages_NumberOf_ET_ControlPages_DEFINE; i++)
  {
      for(int j=0; j < ControlPages_NumberOf_Sub_Pages_DEFINE; j++)
      {
        write_UnsignedLong_InByteBuffer( 0x00 );
      }
  }
  flushByteBuffer(); 
  
  
}


/*
Read_Mapping_ControlPage( byte type, byte set, byte Page_number, byte SubPage_number, byte Control_number ) 
{
// Reads a full Control Page from the SPI FLASH and copy it to the CurrentControlPage_Parameter_Mapping

  //Checks that type is in the allowed values
  
  //Check that set is in the allowed values

  
}


Write_Mapping_ControlPage( byte type, byte set, byte Page_number, byte SubPage_number, byte Control_number ) 
{
// Write the CurrentControlPage_Parameter_Mapping to a full Control Page to the SPI FLASH
    
}
*/



////////////////////////////////////////////////////
// Reading the MidyAX structures
////////////////////////////////////////////////////
/*
int Read_EffectType_FromFLASH( byte effectTypeNumber, struct DYN_EffectType *theEffectType)
int Read_Parameter_FromFLASH( byte effectTypeNumber, byte parameterNumber , struct DYN_Parameter *theParameter) 
int Read_ModalList_FromFLASH( int ModalListNumber, char **The_Modal_List , int *The_Modal_List_size )
int Read_EffectBlock_FromFLASH( struct DYN_EffectBlock *theEffectBlockArray)   NOT ACTIVE, TO BE TESTED
*/

unsigned long currentMemAddresse, currentMemAddresse2, ParamListStartAddress;

// Set debug options that are local to this file
//#define DEBUG

#ifdef DEBUG
    char str1[100];
#endif

char buff_param[20];
char buff[20];

int Read_EffectType_FromFLASH( byte effectTypeNumber, struct DYN_EffectType *theEffectType) //, struct DYN_Parameter *theParametersArray) 
{
  byte strSize, effectTypeNumberReceived;
  effectTypeNumberReceived = effectTypeNumber;
  // Read Effect Type level attributes
  currentMemAddresse = D_EffectAndParam_MemBlock;

#ifdef DEBUG
  Serial.println("");Serial.println("");
  Serial.println(F("START Read_EffectType_FromFLASH"));
#endif

  //if( effectTypeNumber >=  NumOfEffectTypes ) return -1;

  currentMemAddresse += (unsigned long) ( sizeof( MEM_EffectType ) *  effectTypeNumber ); 

  //////////////////////////////////////////////////////////////////////
  //////// Reading EFFECT TYPE attributes   ////////////////////////////
  //////////////////////////////////////////////////////////////////////

  //Serial.println("START READING");
  read_DataBytes_FLASH( currentMemAddresse, &(          theEffectType->ID                    ), 1);
#ifdef DEBUG
    sprintf(str1,"currentMemAddresse = %lu", currentMemAddresse );Serial.println(str1);
#endif
  currentMemAddresse ++;
  //Serial.println("READ theEffectType->ID ");
  
  read_String_FLASH( currentMemAddresse,                buff                                 , &strSize);
  buff[19] = '\0';
  #ifdef DEBUG
    Serial.print(buff);Serial.println(strSize);
  #endif
  //Serial.println("after read_String_FLASH");
  /*if( theEffectType->name != NULL ) { free(   theEffectType->name   ); }
  Serial.println("after free");
  theEffectType->name = (char *) malloc ( sizeof(char) * strSize);
  Serial.println("after malloc");*/
  strncpy( theEffectType->name, buff, strSize);
  //strcpy( theEffectType->name, buff);
  //Serial.print(theEffectType->name);Serial.println( strlen(theEffectType->name) );
  //Serial.println("after strncpy");
  #ifdef DEBUG
    sprintf(str1,"currentMemAddresse = %lu", currentMemAddresse );Serial.println(str1);
  #endif
  currentMemAddresse += 20;
  //Serial.println("READ theEffectType->name ");
  
  read_DataBytes_FLASH( currentMemAddresse, (byte *) &(  theEffectType->subTypeParamID        ), 1);
  #ifdef DEBUG
    sprintf(str1,"currentMemAddresse = %lu", currentMemAddresse );Serial.println(str1);
  #endif
  currentMemAddresse ++;
  //Serial.println("READ theEffectType->subTypeParamID ");
  read_DataBytes_FLASH( currentMemAddresse, &(          theEffectType->onBypassParamID       ), 1);
  #ifdef DEBUG
    sprintf(str1,"currentMemAddresse = %lu", currentMemAddresse );Serial.println(str1);
  #endif
  currentMemAddresse ++;
  read_DataBytes_FLASH( currentMemAddresse, &(          theEffectType->numOfParameters       ), 1);
  #ifdef DEBUG
    sprintf(str1,"currentMemAddresse = %lu", currentMemAddresse );Serial.println(str1);
  #endif
  currentMemAddresse ++;

#ifdef DEBUG
  Serial.print(F("effectTypeNumber = ")); Serial.println(effectTypeNumber, DEC);
  Serial.print(F("theEffectType->ID = ")); Serial.println(theEffectType->ID, DEC);
  sprintf(str1,"theEffectType->name = %s", theEffectType->name );Serial.println(str1); 
  Serial.print(F("theEffectType->subTypeParamID = ")); Serial.println(theEffectType->subTypeParamID, DEC);
  Serial.print(F("theEffectType->onBypassParamID = ")); Serial.println(theEffectType->onBypassParamID, DEC);
  Serial.print(F("theEffectType->numOfParameters = ")); Serial.println(theEffectType->numOfParameters, DEC);
  Serial.println();
#endif


  //////////////////////////////////////////////////////////////////////
  //////// Reading the PARAMETERS of the Effect type  //////////////////
  //////////////////////////////////////////////////////////////////////

  currentMemAddresse = startAddresseOfParameterAddresses;

/*
  for(int i= 0; i < theEffectType->numOfParameters ; i++)
  //for(int i= 0; i < 4 ; i++)
  {
    Read_Parameter_FromFLASH( effectTypeNumberReceived, i, theParametersArray );
  }
*/ 
}



int Read_Parameter_FromFLASH( byte effectTypeNumber, byte parameterNumber , struct DYN_Parameter *theParameter) 
{
  byte strSize;

#ifdef DEBUG
  Serial.println(F("Start Read_Parameter_FromFLASH"));
#endif

  // Calculate Addresse where the PARAMETER struct starts (at an addresse) for that EFFECT TYPE  
  ParamListStartAddress = D_ListOfAddresses_MemBlock + (unsigned long) 5 * effectTypeNumber;
  // Get the addresse
  
#ifdef DEBUG
  Serial.print(F("ParamListStartAddress = ")); Serial.println(ParamListStartAddress, HEX);
  Serial.print(F("&currentMemAddresse2 = ")); Serial.println((int)&currentMemAddresse2, HEX);
#endif

  read_UnsignedLong_FLASH( ParamListStartAddress, &currentMemAddresse2 );
  
  //sprintf(str1,"currentMemAddresse2 = %lu", currentMemAddresse2 );Serial.println(str1);

#ifdef DEBUG
  Serial.println(F("After read_UnsignedLong_FLASH"));
#endif
  
  currentMemAddresse2 += sizeOf_MEM_Parameter * (unsigned long) parameterNumber; 

  //sprintf(str1,"currentMemAddresse2 = %lu", currentMemAddresse2 );Serial.println(str1);

#ifdef DEBUG
  sprintf(str1,"Reading PARAM ET= %i P= %i", effectTypeNumber, parameterNumber );Serial.println(str1);
  //sprintf(str1,"ParamListStartAddress  = %lu", ParamListStartAddress  );Serial.println(str1);
  sprintf(str1,"currentMemAddresse2  = %lu, numberOfElement = %i", currentMemAddresse2, parameterNumber  );Serial.println(str1);
#endif


  read_DataBytes_FLASH( currentMemAddresse2, &(     theParameter->ID            ), 1);
  currentMemAddresse2++;

  read_String_FLASH( currentMemAddresse2,           buff_param          , &strSize);  
  buff_param[19] = '\0';
  //if( theParameter->name != NULL ) { free(   theParameter->name   ); }
  //theParameter->name = (char *) malloc ( sizeof(char) * strSize);
  strncpy( theParameter->name, buff_param, strSize);
  currentMemAddresse2 += 20;
  
  read_String_FLASH( currentMemAddresse2,           buff_param         , &strSize);
  buff_param[19] = '\0';
  //if( theParameter->label != NULL ) { free(   theParameter->label   ); }
  //theParameter->label = (char *) malloc ( sizeof(char) * strSize);
  strncpy( theParameter->label, buff_param, strSize);
  currentMemAddresse2 += 20;
  
  read_DataBytes_FLASH( currentMemAddresse2, &(     theParameter->modifierID    ), 1);
  currentMemAddresse2++;
  read_DataBytes_FLASH( currentMemAddresse2, &(     theParameter->displayType   ), 1);
  currentMemAddresse2++;
  read_DataBytes_FLASH( currentMemAddresse2, &(     theParameter->type          ), 1);
  currentMemAddresse2++;
  read_UnsignedInt_FLASH( currentMemAddresse2, &(   theParameter->defaultValue  ) );
  currentMemAddresse2 += 2;
  read_Int_FLASH( currentMemAddresse2, &(           theParameter->minDispValue  ) );
  currentMemAddresse2 += 2;
  read_UnsignedInt_FLASH( currentMemAddresse2, &(   theParameter->maxDispValue  ) );
  currentMemAddresse2 += 2;
  read_DataBytes_FLASH( currentMemAddresse2, &(     theParameter->precision     ), 1 );
  currentMemAddresse2++;
  read_DataBytes_FLASH( currentMemAddresse2, &(     theParameter->unit          ), 1 );
  currentMemAddresse2++;
  read_UnsignedInt_FLASH( currentMemAddresse2, &(   theParameter->numVals       ) );
  currentMemAddresse2 += 2;
  read_Int_FLASH( currentMemAddresse2, &(           theParameter->idListVal     ) );
  currentMemAddresse2 += 2;

#ifdef DEBUG
  Serial.print(F("theParameter->ID = ")); Serial.println(theParameter->ID, DEC);
  sprintf(str1,"theParameter->name  = %s", theParameter->name  );Serial.println(str1);
  sprintf(str1,"theParameter->label  = %s", theParameter->label  );Serial.println(str1); 
  Serial.print(F("theParameter->modifierID = ")); Serial.println(theParameter->modifierID, DEC);
  Serial.print(F("theParameter->displayType = ")); Serial.println(theParameter->displayType, DEC);
  Serial.print(F("theParameter->type = ")); Serial.println(theParameter->type, DEC);
  Serial.print(F("theParameter->defaultValue = ")); Serial.println(theParameter->defaultValue, DEC);
  Serial.print(F("theParameter->minDispValue = ")); Serial.println(theParameter->minDispValue, DEC);
  Serial.print(F("theParameter->maxDispValue = ")); Serial.println(theParameter->maxDispValue, DEC);
  Serial.print(F("theParameter->precision = ")); Serial.println(theParameter->precision, DEC);
  Serial.print(F("theParameter->unit = ")); Serial.println(theParameter->unit, DEC);
  Serial.print(F("theParameter->numVals = ")); Serial.println(theParameter->numVals, DEC);
  Serial.print(F("theParameter->idListVal = ")); Serial.println(theParameter->idListVal, DEC);
  Serial.println();
#endif


  /*if( theParameter->idListVal != -1)
  {
    //Load associated modal list
    
  }*/
  
  return 0;
}

int Read_ModalList_FromFLASH( int ModalListNumber, char **The_Modal_List , int *The_Modal_List_size )
{
  unsigned long currentMemAddresse3, ModalListLISTStartAddress;
  byte numberOfElement, strSize;

  
  ModalListLISTStartAddress = D_startAddresseOfModalListAddresses + (unsigned int) 5 * ModalListNumber;
  read_UnsignedLong_FLASH( ModalListLISTStartAddress, &(   currentMemAddresse3  ) );
  ModalListLISTStartAddress +=4;
  read_DataBytes_FLASH( ModalListLISTStartAddress, &numberOfElement , 1 );
  ModalListLISTStartAddress ++;

#ifdef DEBUG
  sprintf(str1,"Reading MODAL LIST number = %i", ModalListNumber  );Serial.println(str1);
  sprintf(str1,"ModalListLISTStartAddress  = %lu", ModalListLISTStartAddress  );Serial.println(str1);
  sprintf(str1,"currentMemAddresse3  = %lu, numberOfElement = %i", currentMemAddresse3, numberOfElement  );Serial.println(str1);
#endif

  for(int i= 0; i < numberOfElement ; i++)
  {
    read_DataBytes_FLASH( currentMemAddresse3, &strSize , 1 );
    currentMemAddresse3++;
    
    read_SizedString_FLASH( currentMemAddresse3,           buff         , strSize);
    currentMemAddresse3 += strSize;
    buff[19] = '\0';
    /*if( The_Modal_List[i] != NULL ) { free(   The_Modal_List[i]   ); }
    The_Modal_List[i] = (char *) malloc ( sizeof(char) * strSize);
    strncpy( The_Modal_List[i], buff, strSize);*/

#ifdef DEBUG
  sprintf(str1,"Modal Value %i  = %s, size of string %i", i, buff , strSize  );Serial.println(str1);
  //Serial.println("");
#endif

  } 
}



// This function is not used and has not been tested
/*
int Read_EffectBlock_FromFLASH( struct DYN_EffectBlock *theEffectBlockArray) 
{
  byte strSize;
  
  unsigned long currentMemAddresse4 = D_EffectAndParam_MemBlock;
  currentMemAddresse4 += sizeof( MEM_EffectType ) * (unsigned int) NumOfEffectTypes;
  currentMemAddresse4 += sizeof( MEM_Parameter ) * (unsigned int) TotalNumOfParameters;  

  #ifdef DEBUG
    Serial.println();Serial.println();
    sprintf(str1,"Reading EffectBlock_FromFLASH" );Serial.println(str1);
    sprintf(str1,"D_EffectAndParam_MemBlock  = %lu", D_EffectAndParam_MemBlock  );Serial.println(str1);
    sprintf(str1,"currentMemAddresse  = %lu, NumOfEffectBlocks = %i", currentMemAddresse4, NumOfEffectBlocks  );Serial.println(str1);
  #endif
  
  for(int i= 0; i < NumOfEffectBlocks ; i++)
  {
    read_DataBytes_FLASH( currentMemAddresse4, &(     theEffectBlockArray->ID            ), 1);
    currentMemAddresse4++;
    //  Serial.print("theEffectBlockArray->ID = "); Serial.println(theEffectBlockArray->ID, DEC);
    read_String_FLASH( currentMemAddresse4,           buff          , &strSize);
    buff[19] = '\0';
    //if( theEffectBlockArray[i]->name != NULL ) {free(theEffectBlockArray[i]->name);}
    //theEffectBlockArray[i]->name = (char *) malloc ( sizeof(char) * strSize);
    strncpy( theEffectBlockArray->name, buff, strSize);
    //  sprintf(str1,"theEffectBlockArray->name  = %s", theEffectBlockArray->name  );Serial.println(str1);
    currentMemAddresse4 += 20; 
    read_DataBytes_FLASH( currentMemAddresse4, &(     theEffectBlockArray->effectTypeID  ), 1);
    //  Serial.print("theEffectBlockArray->effectTypeID  = "); Serial.println(theEffectBlockArray->effectTypeID , DEC);
    currentMemAddresse4++;
    read_DataBytes_FLASH( currentMemAddresse4, &(     theEffectBlockArray->ONByPass_CC   ), 1);
    //  Serial.print("theEffectBlockArray->ONByPass_CC = "); Serial.println(theEffectBlockArray->ONByPass_CC, DEC);
    currentMemAddresse4++;
    read_DataBytes_FLASH( currentMemAddresse4, &(     theEffectBlockArray->XY_CC         ), 1);
    //  Serial.print("theEffectBlockArray->XY_CC = "); Serial.println(theEffectBlockArray->XY_CC, DEC);
    currentMemAddresse4++;

#ifdef DEBUG
  Serial.print(F("EFFECT BLOCK number = ")); Serial.println(i, DEC);
  Serial.print(F("theEffectBlockArray->ID = ")); Serial.println(theEffectBlockArray->ID, DEC);
  sprintf(str1,"theEffectBlockArray->name  = %s", theEffectBlockArray->name  );Serial.println(str1);
  Serial.print(F("theEffectBlockArray->effectTypeID  = ")); Serial.println(theEffectBlockArray->effectTypeID , DEC);
  Serial.print(F("theEffectBlockArray->ONByPass_CC = ")); Serial.println(theEffectBlockArray->ONByPass_CC, DEC);
  Serial.print(F("theEffectBlockArray->XY_CC = ")); Serial.println(theEffectBlockArray->XY_CC, DEC);
  Serial.println();
#endif

  }
  
  return 0;
}
*/



/*    struct MEM_EffectBlock {
        byte ID;
        char name[20]; // The max is "Feedback Return" = 15 characters
        byte effectTypeID;
        //char label[20]; // The max is "FeedbackReturn" = 14 characters   == Effect type label // Not needed the label is on the EffectType
        byte ONByPass_CC;
        byte XY_CC;
*/

