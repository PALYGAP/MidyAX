/////////////////////////////////////////////////////////////////////////////////////////////////
// PROGRAM:     MidyAX - BCR2000 to AXE-FX MIDI communication orchestrator
// AIM:         Provide enhanced usability of the AXE-FX by making it possible to set the 
//              AXE-FX parameters with a hardware interface (knobs/switches of the BCR2000) 
// HARDWARE:    ARDUINO MEGA 128, 4 MIDI ports with a MIDI-IN and MIDI-OUT for each port.
// CREATOR:     Eric FEUILLEAUBOIS
// LICENSE:     GNU license v3 - That means OPEN SOFWARE, COPYLEFT and hope it's useful to you
/////////////////////////////////////////////////////////////////////////////////////////////////



#ifndef UVGA_H_
#define UVGA_H_


  enum ScreenType
  {
    INIT_SCREEN = 1,
    OPERATIONAL_PARAMETERS_SCREEN,
    EFFECT_TYPE_CONTROL_PAGE,
    QUICKACCESS_CONTROL_PAGE,
    CUSTOM_EFFECT_TYPE_CONTROL_PAGE,
    CUSTOM_QUICKACCESS_CONTROL_PAGE,
    CUSTOM_QUICKACCESS_CONTROL_PAGE_EFFECTBLOCK,
    LOOPER,
    SPECIAL_FUNCTIONS_GEN_MENU,
    SPECIAL_FUNCTIONS_1,
    SPECIAL_FUNCTIONS_2,
    SPECIAL_FUNCTIONS_3,
    SPECIAL_FUNCTIONS_4,
    SPECIAL_FUNCTIONS_5,
  };
  
  enum Param_State
  {
    NO_PARAMETER = 0,
    PARAMETER_NOT_ACTIVE,
    PARAMETER_ACTIVE,
  };




#endif // UVGA_H_

