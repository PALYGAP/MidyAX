////////////////////////////////////////////////////////////////////////////////////////////
// PROGRAM:     PROTOTYPE of MidyAX - BCR2000 to AXE-FX MIDI orchestrator
// HARDWARE:    ARDUINO MEGA, 4 MIDI ports with a MIDI-IN and MIDI-OUT for each port.
// CREATOR:     Eric FEUILLEAUBOIS
// COPYRIGHTS:  LGNU
////////////////////////////////////////////////////////////////////////////////////////////


#ifndef AXEFX_H_
#define AXEFX_H_

  #include <avr/pgmspace.h>
  #include <arduino.h>
  
  ///////////////
  // CONSTANTS //
  ///////////////

  #define AXEFX_NumberOf_EffectTypes_DEFINE  38
  #define AXEFX_NumberOf_EffectBlocks_DEFINE 71
  #define AXEFX_NumOf_Parameters_DEFINE      1100
  #define AXEFX_NumOf_ModalLists_DEFINE      84
  #define AXEFX_INT_Parameter_Type_DEFINE    1
  #define AXEFX_INTXL_Parameter_Type_DEFINE    2
  
  // Target of the current MidyAX software
  PROGMEM byte AXEFX_Firmware_Version_ToUse = 11,
               AXEFX_Model_ToUse = 3,
               MFC101_Firmware_Version_ToUse = 2;
  
  PROGMEM byte AXEFX_NumOf_SCENES = 8,
               AXEFX_MaxNumerOf_Instance_per_EffectBlock = 4,
               AXEFX_NumberOf_EffectBlock_per_EffectType = 4;
  PROGMEM byte AXEFX_Manuf_ID[3] = {0x00, 0x01, 0x74 };


  // List of the FAS models
  enum FAS_Model {
    FAS_Model_Standard,
    FAS_Model_ULTRA,
    FAS_Model_MFC101,
    FAS_Model_II,
  };
  
  
  
  ///////////////
  // VARIABLES //
  ///////////////

  byte AXEFX_Firmware_Version,
       AXEFX_Model,
       MFC101_Firmware_Version,
       AXEFX_MIDI_Channel = 12;   // By default the AXE_FX channel is set to 12
   
   
   
  //////////////////////
  // LOOPER SPECIFICS //  
  //////////////////////
 
  // CONTANTS //
  PROGMEM byte  AXEFX_LOOPER_RECORD_CC = 28,
                AXEFX_LOOPER_PLAY_CC = 29,
                AXEFX_LOOPER_ONCE_CC = 30,
                AXEFX_LOOPER_DUB_CC = 31,
                AXEFX_LOOPER_REVERSE_CC = 32,
                AXEFX_LOOPER_BYPASS_CC = 33,
                AXEFX_LOOPER_HALF_CC = 120,
                AXEFX_LOOPER_UNDO_CC = 121,
                AXEFX_LOOPER_METRO_CC = 122;
  

  // VARIABLES //
  byte  AXEFX_LOOPER__STATE,        // Global LOOPER STATE - ON / OFF
        AXEFX_LOOPER_STATE_RECORD,
        AXEFX_LOOPER_STATE_PLAY,
        AXEFX_LOOPER_STATE_ONCE,
        AXEFX_LOOPER_STATE_DUB,
        AXEFX_LOOPER_STATE_REVERSE,
        AXEFX_LOOPER_STATE_UNDO,
        AXEFX_LOOPER_STATE_HALF,
        AXEFX_LOOPER_STATE_METRO;
  
    
// LOOPER variables
boolean LOOPER_STATE_RECORD,
        LOOPER_STATE_PLAY,
        LOOPER_STATE_ONCE,
        LOOPER_STATE_DUB,
        LOOPER_STATE_REVERSE,
        LOOPER_STATE_UNDO,
        LOOPER_STATE_HALF,
        LOOPER_STATE_METRO,
        LOOPER_STATE = false;
  
  
#endif // AXEFX_H_
