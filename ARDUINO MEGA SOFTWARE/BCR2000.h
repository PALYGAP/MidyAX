/////////////////////////////////
//  @file		BCR2000.h
//  Project		BCR2000 HEADER
/////////////////////////////////

#ifndef BCR2000_H_
#define BCR2000_H_

  #include <avr/pgmspace.h>


  ///////////////
  // CONSTANTS //
  ///////////////

  #define BCR2000_NumberOf_Encoders_DEFINE 32
  #define BCR2000_NumberOf_EncSwitchButtons_DEFINE  8
  #define BCR2000_NumberOf_ControlPage_Buttons_DEFINE  16
  #define BCR2000_Max_NumberOf_ControlPage_DEFINE  32
  #define BCR2000_NumberOf_Controls_DEFINE     BCR2000_NumberOf_Encoders_DEFINE + BCR2000_NumberOf_EncSwitchButtons_DEFINE  

  #define BCR2000_SUBPAGE1_CC_DEFINE	  57
  #define BCR2000_SUBPAGE2_CC_DEFINE	  58
  #define BCR2000_SHIFT_CC_DEFINE	  59
  #define BCR2000_QUICKACCESS_CC_DEFINE	  60
  #define BCR2000_RECORD_DEFINE	          61
  #define BCR2000_PLAY_DEFINE	          62
  #define BCR2000_CUSTOMIZE_CC_DEFINE	  63
  #define BCR2000_SPEC_FUNC_CC_DEFINE	  64
  #define BCR2000_SCENE_DOWN_CC_DEFINE	  65
  #define BCR2000_SCENE_UP_CC_DEFINE	  66
  #define BCR2000_XY_CC_DEFINE	          67
  #define BCR2000_ONBYPASS_CC_DEFINE	  68
  #define BCR2000_BlockSelect1_CC_DEFINE  69
  #define BCR2000_BlockSelect2_CC_DEFINE  70
  #define BCR2000_Footswitch1_CC_DEFINE	  71
  #define BCR2000_Footswitch1_CC_DEFINE	  72

boolean CUSTOMIZE_STATE = false;

  
  PROGMEM byte BEHRINGER_Manuf_ID[3] = {0x00, 0x20, 0x32 },
               BCF2000_Model_ID = 0x14,
               BCR2000_Model_ID = 0x15;
    
  ///////////////
  // VARIABLES //
  ///////////////
  
  byte BCR2000_MIDI_Channel = 1,  
       BCF2000_Device_ID,
       BCR2000_Device_ID;
  
  
#endif // BCR2000_H_
