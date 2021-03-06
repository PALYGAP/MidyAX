/////////////////////////////////////////////////////////////////////////////////////////////////
// PROGRAM:     MidyAX - BCR2000 to AXE-FX MIDI communication orchestrator
// AIM:         Provide enhanced usability of the AXE-FX by making it possible to set the 
//              AXE-FX parameters with a hardware interface (knobs/switches of the BCR2000) 
// HARDWARE:    ARDUINO MEGA 128, 4 MIDI ports with a MIDI-IN and MIDI-OUT for each port.
// CREATOR:     Eric FEUILLEAUBOIS
// LICENSE:     GNU license v3 - That means OPEN SOFWARE, COPYLEFT and hope it's useful to you
/////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef AXEFX_H_
#define AXEFX_H_

  #include <avr/pgmspace.h>
  #include <arduino.h>
  
  ///////////////
  // CONSTANTS //
  ///////////////

  #define AXEFX_NumberOf_EffectTypes_DEFINE    38
  #define AXEFX_NumberOf_EffectBlocks_DEFINE   71
  #define AXEFX_NumOf_Parameters_DEFINE        1100
  #define AXEFX_NumOf_ModalLists_DEFINE        84
  #define AXEFX_INT_Parameter_Type_DEFINE      1
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

// AXE-FX SYSEX FUNCTION CODES
  #define AXEFX_SYSEX_WHO_AM_I 0x00
  #define AXEFX_SYSEX_PARAM_DUMP 0x01
  #define AXEFX_SYSEX_PARAM_SET 0x02
  #define AXEFX_SYSEX_PATCH_DUMP 0x03
  #define AXEFX_SYSEX_PATCH_RCV 0x04
  #define AXEFX_SYSEX_PLACE_EFFECT 0x05
  #define AXEFX_SYSEX_CONNECT_EFFECT 0x06
  #define AXEFX_SYSEX_MODIFIER_SET 0x07
  #define AXEFX_SYSEX_QUERY_VERSION 0x08
  #define AXEFX_SYSEX_SET_NAME 0x09
  #define AXEFX_SYSEX_CABIR_RCV 0x0A
  #define AXEFX_SYSEX_CHECKSUM 0x0B
  #define AXEFX_SYSEX_SET_GRID 0x0C
  #define AXEFX_SYSEX_TUNER 0x0D
  #define AXEFX_SYSEX_QUERY_STATES 0x0E
  #define AXEFX_SYSEX_QUERY_NAME 0x0F
  #define AXEFX_SYSEX_TEMPO 0x10
  #define AXEFX_SYSEX_XY 0x11
  #define AXEFX_SYSEX_CABNAME 0x12
  #define AXEFX_SYSEX_CPULOAD 0x13
  #define AXEFX_SYSEX_PATCHNUM 0x14
  #define AXEFX_SYSEX_QUERY_NAME_BY_NUM 0x15
  #define AXEFX_SYSEX_GET_PARAM_INFO 0x16
  #define AXEFX_SYSEX_GET_MIDI_CHANNEL 0x17
  #define AXEFX_SYSEX_GET_MODIFIER_INFO 0x18
  #define AXEFX_SYSEX_CAB_DUMP 0x19
  #define AXEFX_SYSEX_GLOBAL_BLOCK_USED 0x1A
  #define AXEFX_SYSEX_GLOBAL_PATCH 0x1B
  #define AXEFX_SYSEX_BANK_DUMP 0x1C
  #define AXEFX_SYSEX_SAVE_PATCH 0x1D
  #define AXEFX_SYSEX_SET_BYPASS 0x1E
  #define AXEFX_SYSEX_GET_ALL_PARAMS 0x1F
  #define AXEFX_SYSEX_GET_GRID 0x20
  #define AXEFX_SYSEX_RESYNC 0x21
  #define AXEFX_SYSEX_SET_DEFAULTS 0x22
  #define AXEFX_SYSEX_LOOPER_STATE 0x23
  #define AXEFX_SYSEX_MOVE_EFFECT 0x24
  #define AXEFX_SYSEX_FW_UPDATE 0x25
  #define AXEFX_SYSEX_FPGA_UPDATE 0x26
  #define AXEFX_SYSEX_MICRO_UPDATE 0x27
  #define AXEFX_SYSEX_GET_PARAM_STRINGS 0x28
  #define AXEFX_SYSEX_SET_SCENE 0x29
  #define AXEFX_SYSEX_GET_FLAGS 0x2A
  #define AXEFX_SYSEX_MODIFIER_DUMP 0x2B
  #define AXEFX_SYSEX_MODIFIER 0x2C
  #define AXEFX_SYSEX_SET_CAB_NAME 0x2D
  #define AXEFX_SYSEX_SET_PARAM_DIRECT 0x2E
  #define AXEFX_SYSEX_BPM 0x2F
  #define AXEFX_SYSEX_GET_GRAPH 0x30
  #define AXEFX_SYSEX_TM_DATA 0x31
  #define AXEFX_SYSEX_MULTIMSG_START 0x32
  #define AXEFX_SYSEX_MULTIMSG_END 0x33
  #define AXEFX_SYSEX_ERASE_SECTOR 0x34
  #define AXEFX_SYSEX_GET_CONFIG 0x35
  #define AXEFX_SYSEX_GET_GRAPHN 0x36
  #define AXEFX_SYSEX_EDIT_EFFECT 0x37
  #define AXEFX_SYSEX_BROADCAST_KNOB 0x38
  #define AXEFX_SYSEX_BROADCAST_MODIFIER 0x39
  #define AXEFX_SYSEX_GET_POSITION 0x3A
  #define AXEFX_SYSEX_SET_MODPARAM_DIRECT 0x3B
  #define AXEFX_SYSEX_RECALL_PATCH 0x3C
  #define AXEFX_SYSEX_FAILSAFE_FW_UPDATE 0x3D
  #define AXEFX_SYSEX_MUTE 0x3E
  #define AXEFX_SYSEX_SET_IRCAP_NAME 0x3F
  #define AXEFX_SYSEX_CONTROL_IRCAP 0x40
  #define AXEFX_SYSEX_DELETE_CABIR 0x41
  #define AXEFX_SYSEX_EDITOR_DISCONNECT 0x42
  #define AXEFX_SYSEX_DUMP_SYSTEM 0x43
  #define AXEFX_SYSEX_CAB_BANK_DUMP 0x44
  #define AXEFX_SYSEX_STATUS_MSG 0x64
  #define AXEFX_SYSEX_RAWIR_START 0x67
  #define AXEFX_SYSEX_RAWIR_DATA 0x68
  #define AXEFX_SYSEX_RAWIR_END 0x69
  #define AXEFX_SYSEX_FPGA_UPDATE_START 0x6A
  #define AXEFX_SYSEX_FPGA_UPDATE_DATA 0x6B
  #define AXEFX_SYSEX_FPGA_UPDATE_END 0x6C
  #define AXEFX_SYSEX_MICRO_UPDATE_START 0x6D
  #define AXEFX_SYSEX_MICRO_UPDATE_DATA 0x6E
  #define AXEFX_SYSEX_MICRO_UPDATE_END 0x6F
  #define AXEFX_SYSEX_EFFECT_START 0x74
  #define AXEFX_SYSEX_EFFECT_DATA 0x75
  #define AXEFX_SYSEX_EFFECT_END 0x76
  #define AXEFX_SYSEX_PATCH_START 0x77
  #define AXEFX_SYSEX_PATCH_DATA 0x78
  #define AXEFX_SYSEX_PATCH_END 0x79
  #define AXEFX_SYSEX_CABIR_START 0x7A
  #define AXEFX_SYSEX_CABIR_DATA 0x7B
  #define AXEFX_SYSEX_CABIR_END 0x7C
  #define AXEFX_SYSEX_FW_UPDATE_START 0x7D
  #define AXEFX_SYSEX_FW_UPDATE_DATA 0x7E
  #define AXEFX_SYSEX_FW_UPDATE_END 0x7F


  
  
#endif // AXEFX_H_






