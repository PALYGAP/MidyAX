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



#ifndef BCR2000_H_
#define BCR2000_H_

  #include <avr/pgmspace.h>

  ///////////////
  // FUNCTIONS //
  ///////////////

  void Change_BCR2000_Preset ( int Preset_Number, boolean init);
  void BCR2000_Init_Current_Preset_Controls_Values ( void );
  void BCR2000_ManageCC ( byte CC_channel, byte CC_number, byte CC_value );
  void Manage4EffectStateButtons( void );

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
