#ifndef MIDYAX_FLASH_DATA_1_H_
#define MIDYAX_FLASH_DATA_1_H_

#include <avr/pgmspace.h>


unsigned int MaxNumberOfControlPages = 32;
unsigned int MaxNumberOfParameters = 48;
unsigned int NumOfEffectTypes = 38;
unsigned int TotalNumOfParameters = 1100;
unsigned int NumOfEffectBlocks = 71;
unsigned int NumOfModalList = 84;

///////////////////////////////////////////////////

////////////////  EFFECT BLOCKS  //////////////////

///////////////////////////////////////////////////////

PROGMEM byte EffectBlock__ID[71] = { 106, 107, 108, 109, 116, 117, 100, 101, 148, 149, 112, 113, 133, 134, 136, 135, 142, 143, 131, 132, 164, 165, 118, 119, 126, 150, 151, 102, 103, 160, 161, 169, 147, 137, 138, 154, 155, 114, 115, 128, 129, 104, 105, 162, 163, 122, 123, 130, 153, 156, 157, 158, 159, 110, 111, 152, 120, 121, 144, 145, 170, 146, 127, 166, 167, 168, 124, 125, 139, 140, 141};

PROGMEM prog_char EffectBlock__0__name[] = "Amp 1";
PROGMEM prog_char EffectBlock__1__name[] = "Amp 2";
PROGMEM prog_char EffectBlock__2__name[] = "Cabinet 1";
PROGMEM prog_char EffectBlock__3__name[] = "Cabinet 2";
PROGMEM prog_char EffectBlock__4__name[] = "Chorus 1";
PROGMEM prog_char EffectBlock__5__name[] = "Chorus 2";
PROGMEM prog_char EffectBlock__6__name[] = "Compressor 1";
PROGMEM prog_char EffectBlock__7__name[] = "Compressor 2";
PROGMEM prog_char EffectBlock__8__name[] = "Crossover 1";
PROGMEM prog_char EffectBlock__9__name[] = "Crossover 2";
PROGMEM prog_char EffectBlock__10__name[] = "Delay 1";
PROGMEM prog_char EffectBlock__11__name[] = "Delay 2";
PROGMEM prog_char EffectBlock__12__name[] = "Drive 1";
PROGMEM prog_char EffectBlock__13__name[] = "Drive 2";
PROGMEM prog_char EffectBlock__14__name[] = "Effects Loop";
PROGMEM prog_char EffectBlock__15__name[] = "Enhancer";
PROGMEM prog_char EffectBlock__16__name[] = "Feedback Send";
PROGMEM prog_char EffectBlock__17__name[] = "Feedback Return";
PROGMEM prog_char EffectBlock__18__name[] = "Filter 1";
PROGMEM prog_char EffectBlock__19__name[] = "Filter 2";
PROGMEM prog_char EffectBlock__20__name[] = "Filter 3";
PROGMEM prog_char EffectBlock__21__name[] = "Filter 4";
PROGMEM prog_char EffectBlock__22__name[] = "Flanger 1";
PROGMEM prog_char EffectBlock__23__name[] = "Flanger 2";
PROGMEM prog_char EffectBlock__24__name[] = "Formant";
PROGMEM prog_char EffectBlock__25__name[] = "Gate/Expander 1";
PROGMEM prog_char EffectBlock__26__name[] = "Gate/Expander 2";
PROGMEM prog_char EffectBlock__27__name[] = "GraphicEQ 1";
PROGMEM prog_char EffectBlock__28__name[] = "GraphicEQ 2";
PROGMEM prog_char EffectBlock__29__name[] = "GraphicEQ 3";
PROGMEM prog_char EffectBlock__30__name[] = "GraphicEQ 4";
PROGMEM prog_char EffectBlock__31__name[] = "Looper";
PROGMEM prog_char EffectBlock__32__name[] = "Megatap Delay";
PROGMEM prog_char EffectBlock__33__name[] = "Mixer 1";
PROGMEM prog_char EffectBlock__34__name[] = "Mixer 2";
PROGMEM prog_char EffectBlock__35__name[] = "Multiband Comp 1";
PROGMEM prog_char EffectBlock__36__name[] = "Multiband Comp 2";
PROGMEM prog_char EffectBlock__37__name[] = "Multidelay 1";
PROGMEM prog_char EffectBlock__38__name[] = "Multidelay 2";
PROGMEM prog_char EffectBlock__39__name[] = "Panner/Tremolo 1";
PROGMEM prog_char EffectBlock__40__name[] = "Panner/Tremolo 2";
PROGMEM prog_char EffectBlock__41__name[] = "Parametric EQ 1";
PROGMEM prog_char EffectBlock__42__name[] = "Parametric EQ 2";
PROGMEM prog_char EffectBlock__43__name[] = "Parametric EQ 3";
PROGMEM prog_char EffectBlock__44__name[] = "Parametric EQ 4";
PROGMEM prog_char EffectBlock__45__name[] = "Phaser 1";
PROGMEM prog_char EffectBlock__46__name[] = "Phaser 2";
PROGMEM prog_char EffectBlock__47__name[] = "Pitch 1";
PROGMEM prog_char EffectBlock__48__name[] = "Pitch 2";
PROGMEM prog_char EffectBlock__49__name[] = "Quad Chorus 1";
PROGMEM prog_char EffectBlock__50__name[] = "Quad Chorus 2";
PROGMEM prog_char EffectBlock__51__name[] = "Resonator 1";
PROGMEM prog_char EffectBlock__52__name[] = "Resonator 2";
PROGMEM prog_char EffectBlock__53__name[] = "Reverb 1";
PROGMEM prog_char EffectBlock__54__name[] = "Reverb 2";
PROGMEM prog_char EffectBlock__55__name[] = "RingMod";
PROGMEM prog_char EffectBlock__56__name[] = "Rotary 1";
PROGMEM prog_char EffectBlock__57__name[] = "Rotary 2";
PROGMEM prog_char EffectBlock__58__name[] = "Synth 1";
PROGMEM prog_char EffectBlock__59__name[] = "Synth 2";
PROGMEM prog_char EffectBlock__60__name[] = "Tone Match";
PROGMEM prog_char EffectBlock__61__name[] = "Vocoder";
PROGMEM prog_char EffectBlock__62__name[] = "Vol/Pan 1";
PROGMEM prog_char EffectBlock__63__name[] = "Vol/Pan 2";
PROGMEM prog_char EffectBlock__64__name[] = "Vol/Pan 3";
PROGMEM prog_char EffectBlock__65__name[] = "Vol/Pan 4";
PROGMEM prog_char EffectBlock__66__name[] = "Wahwah 1";
PROGMEM prog_char EffectBlock__67__name[] = "Wahwah 2";
PROGMEM prog_char EffectBlock__68__name[] = "NoiseGate";
PROGMEM prog_char EffectBlock__69__name[] = "Output";
PROGMEM prog_char EffectBlock__70__name[] = "Controllers";


PROGMEM char *EffectBlock__name[71] = { EffectBlock__0__name, EffectBlock__1__name, EffectBlock__2__name, EffectBlock__3__name, EffectBlock__4__name, EffectBlock__5__name, EffectBlock__6__name, EffectBlock__7__name, EffectBlock__8__name, EffectBlock__9__name, EffectBlock__10__name, EffectBlock__11__name, EffectBlock__12__name, EffectBlock__13__name, EffectBlock__14__name, EffectBlock__15__name, EffectBlock__16__name, EffectBlock__17__name, EffectBlock__18__name, EffectBlock__19__name, EffectBlock__20__name, EffectBlock__21__name, EffectBlock__22__name, EffectBlock__23__name, EffectBlock__24__name, EffectBlock__25__name, EffectBlock__26__name, EffectBlock__27__name, EffectBlock__28__name, EffectBlock__29__name, EffectBlock__30__name, EffectBlock__31__name, EffectBlock__32__name, EffectBlock__33__name, EffectBlock__34__name, EffectBlock__35__name, EffectBlock__36__name, EffectBlock__37__name, EffectBlock__38__name, EffectBlock__39__name, EffectBlock__40__name, EffectBlock__41__name, EffectBlock__42__name, EffectBlock__43__name, EffectBlock__44__name, EffectBlock__45__name, EffectBlock__46__name, EffectBlock__47__name, EffectBlock__48__name, EffectBlock__49__name, EffectBlock__50__name, EffectBlock__51__name, EffectBlock__52__name, EffectBlock__53__name, EffectBlock__54__name, EffectBlock__55__name, EffectBlock__56__name, EffectBlock__57__name, EffectBlock__58__name, EffectBlock__59__name, EffectBlock__60__name, EffectBlock__61__name, EffectBlock__62__name, EffectBlock__63__name, EffectBlock__64__name, EffectBlock__65__name, EffectBlock__66__name, EffectBlock__67__name, EffectBlock__68__name, EffectBlock__69__name, EffectBlock__70__name};

PROGMEM byte EffectBlock__effectTypeID[71] = { 5, 5, 6, 6, 10, 10, 2, 2, 28, 28, 8, 8, 19, 19, 21, 20, 23, 24, 18, 18, 18, 18, 11, 11, 15, 29, 29, 3, 3, 3, 3, 38, 27, 22, 22, 31, 31, 9, 9, 16, 16, 4, 4, 4, 4, 13, 13, 17, 17, 32, 32, 33, 33, 7, 7, 30, 12, 12, 25, 25, 39, 26, 34, 34, 34, 34, 14, 14, 35, 36, 37};

PROGMEM byte EffectBlock__ONByPass_CC[71] = { 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 59, 51, 0, 0, 52, 53, 54, 55, 56, 57, 58, 60, 61, 62, 63, 64, 65, 0, 66, 0, 0, 67, 68, 69, 70, 90, 91, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 99, 92, 93, 94, 95, 96, 97, 98, 0, 0, 0};

PROGMEM byte EffectBlock__XY_CC[71] = { 100, 101, 102, 103, 104, 105, 0, 0, 0, 0, 106, 107, 108, 109, 0, 0, 0, 0, 0, 0, 0, 0, 110, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 113, 114, 115, 0, 0, 0, 0, 116, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 118, 119, 0, 0, 0};



///////////////////////////////////////////////////

////////////////  EFFECT TYPES   //////////////////

///////////////////////////////////////////////////////

PROGMEM byte EffectType__ID[38] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39};

PROGMEM prog_char EffectType__2__name[] = "Compressor";
PROGMEM prog_char EffectType__3__name[] = "GraphicEQ";
PROGMEM prog_char EffectType__4__name[] = "ParametricEQ";
PROGMEM prog_char EffectType__5__name[] = "Amp";
PROGMEM prog_char EffectType__6__name[] = "Cab";
PROGMEM prog_char EffectType__7__name[] = "Reverb";
PROGMEM prog_char EffectType__8__name[] = "Delay";
PROGMEM prog_char EffectType__9__name[] = "MultiDelay";
PROGMEM prog_char EffectType__10__name[] = "Chorus";
PROGMEM prog_char EffectType__11__name[] = "Flanger";
PROGMEM prog_char EffectType__12__name[] = "Rotary";
PROGMEM prog_char EffectType__13__name[] = "Phaser";
PROGMEM prog_char EffectType__14__name[] = "Wah";
PROGMEM prog_char EffectType__15__name[] = "Formant";
PROGMEM prog_char EffectType__16__name[] = "PanTrem";
PROGMEM prog_char EffectType__17__name[] = "Pitch";
PROGMEM prog_char EffectType__18__name[] = "Filter";
PROGMEM prog_char EffectType__19__name[] = "Drive";
PROGMEM prog_char EffectType__20__name[] = "Enhancer";
PROGMEM prog_char EffectType__21__name[] = "EffectsLoop";
PROGMEM prog_char EffectType__22__name[] = "Mixer";
PROGMEM prog_char EffectType__23__name[] = "FeedbackSend";
PROGMEM prog_char EffectType__24__name[] = "FeedbackReturn";
PROGMEM prog_char EffectType__25__name[] = "Synth";
PROGMEM prog_char EffectType__26__name[] = "Vocoder";
PROGMEM prog_char EffectType__27__name[] = "MegaTap";
PROGMEM prog_char EffectType__28__name[] = "Crossover";
PROGMEM prog_char EffectType__29__name[] = "GateExpander";
PROGMEM prog_char EffectType__30__name[] = "RingMod";
PROGMEM prog_char EffectType__31__name[] = "MultibandComp";
PROGMEM prog_char EffectType__32__name[] = "QuadChorus";
PROGMEM prog_char EffectType__33__name[] = "Resonator";
PROGMEM prog_char EffectType__34__name[] = "VolPan";
PROGMEM prog_char EffectType__35__name[] = "NoiseGate";
PROGMEM prog_char EffectType__36__name[] = "Output";
PROGMEM prog_char EffectType__37__name[] = "Controllers";
PROGMEM prog_char EffectType__38__name[] = "Looper";
PROGMEM prog_char EffectType__39__name[] = "Tone";


PROGMEM char *EffectType__name[38] = { EffectType__2__name, EffectType__3__name, EffectType__4__name, EffectType__5__name, EffectType__6__name, EffectType__7__name, EffectType__8__name, EffectType__9__name, EffectType__10__name, EffectType__11__name, EffectType__12__name, EffectType__13__name, EffectType__14__name, EffectType__15__name, EffectType__16__name, EffectType__17__name, EffectType__18__name, EffectType__19__name, EffectType__20__name, EffectType__21__name, EffectType__22__name, EffectType__23__name, EffectType__24__name, EffectType__25__name, EffectType__26__name, EffectType__27__name, EffectType__28__name, EffectType__29__name, EffectType__30__name, EffectType__31__name, EffectType__32__name, EffectType__33__name, EffectType__34__name, EffectType__35__name, EffectType__36__name, EffectType__37__name, EffectType__38__name, EffectType__39__name};

PROGMEM char EffectType__subTypeParamID[38] = { 12, -1, -1, 0, 12, 0, 0, 35, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, 8, -1};

PROGMEM byte EffectType__onBypassParamID[38] = { 9, 18, 23, 28, 13, 22, 22, 34, 15, 16, 11, 16, 12, 11, 14, 29, 8, 7, 5, 12, -1, -1, 5, 28, 49, 16, 14, 12, 9, 27, 44, 38, 3, -1, 19, -1, 4, 9};

PROGMEM byte EffectType__numOfParameters[38] = { 18, 19, 24, 91, 29, 35, 70, 117, 23, 23, 18, 20, 13, 12, 15, 85, 14, 20, 11, 20, 10, 2, 6, 40, 50, 17, 15, 13, 10, 28, 46, 40, 9, 5, 20, 78, 13, 21};

////////////////  PARAMETERS    //////////////////

PROGMEM byte Parameter__ID[1100] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
0, 1, 
0, 1, 2, 3, 4, 5, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 
0, 1, 2, 3, 4, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

PROGMEM prog_char EffectType__2__Parameter__0__name[] = "COMP_THRESH";
PROGMEM prog_char EffectType__2__Parameter__1__name[] = "COMP_RATIO";
PROGMEM prog_char EffectType__2__Parameter__2__name[] = "COMP_ATTACK";
PROGMEM prog_char EffectType__2__Parameter__3__name[] = "COMP_RELEASE";
PROGMEM prog_char EffectType__2__Parameter__4__name[] = "COMP_LEVEL";
PROGMEM prog_char EffectType__2__Parameter__5__name[] = "COMP_KNEE";
PROGMEM prog_char EffectType__2__Parameter__6__name[] = "COMP_AUTO";
PROGMEM prog_char EffectType__2__Parameter__7__name[] = "COMP_PEAKRMS";
PROGMEM prog_char EffectType__2__Parameter__8__name[] = "COMP_CONTOUR";
PROGMEM prog_char EffectType__2__Parameter__9__name[] = "COMP_BYPASS";
PROGMEM prog_char EffectType__2__Parameter__10__name[] = "COMP_SIDECHAIN";
PROGMEM prog_char EffectType__2__Parameter__11__name[] = "COMP_MIX";
PROGMEM prog_char EffectType__2__Parameter__12__name[] = "COMP_TYPE";
PROGMEM prog_char EffectType__2__Parameter__13__name[] = "COMP_SUSTAIN";
PROGMEM prog_char EffectType__2__Parameter__14__name[] = "COMP_BYPASSMODE";
PROGMEM prog_char EffectType__2__Parameter__15__name[] = "COMP_DELAYTIME";
PROGMEM prog_char EffectType__2__Parameter__16__name[] = "COMP_AUTOMODE";
PROGMEM prog_char EffectType__2__Parameter__17__name[] = "COMP_EMPHASIS";
PROGMEM prog_char EffectType__3__Parameter__0__name[] = "GEQ_GAIN1";
PROGMEM prog_char EffectType__3__Parameter__1__name[] = "GEQ_GAIN2";
PROGMEM prog_char EffectType__3__Parameter__2__name[] = "GEQ_GAIN3";
PROGMEM prog_char EffectType__3__Parameter__3__name[] = "GEQ_GAIN4";
PROGMEM prog_char EffectType__3__Parameter__4__name[] = "GEQ_GAIN5";
PROGMEM prog_char EffectType__3__Parameter__5__name[] = "GEQ_GAIN6";
PROGMEM prog_char EffectType__3__Parameter__6__name[] = "GEQ_GAIN7";
PROGMEM prog_char EffectType__3__Parameter__7__name[] = "GEQ_GAIN8";
PROGMEM prog_char EffectType__3__Parameter__8__name[] = "GEQ_GAIN9";
PROGMEM prog_char EffectType__3__Parameter__9__name[] = "GEQ_GAIN10";
PROGMEM prog_char EffectType__3__Parameter__10__name[] = "GEQ_MIX";
PROGMEM prog_char EffectType__3__Parameter__11__name[] = "GEQ_LEVEL";
PROGMEM prog_char EffectType__3__Parameter__12__name[] = "GEQ_PAN";
PROGMEM prog_char EffectType__3__Parameter__13__name[] = "GEQ_BYPASSMODE";
PROGMEM prog_char EffectType__3__Parameter__14__name[] = "GEQ_GLOBALMIX";
PROGMEM prog_char EffectType__3__Parameter__15__name[] = "GEQ_SPARE1";
PROGMEM prog_char EffectType__3__Parameter__16__name[] = "GEQ_SPARE2";
PROGMEM prog_char EffectType__3__Parameter__17__name[] = "GEQ_SPARE3";
PROGMEM prog_char EffectType__3__Parameter__18__name[] = "GEQ_BYPASS";
PROGMEM prog_char EffectType__4__Parameter__0__name[] = "PEQ_FREQ1";
PROGMEM prog_char EffectType__4__Parameter__1__name[] = "PEQ_FREQ2";
PROGMEM prog_char EffectType__4__Parameter__2__name[] = "PEQ_FREQ3";
PROGMEM prog_char EffectType__4__Parameter__3__name[] = "PEQ_FREQ4";
PROGMEM prog_char EffectType__4__Parameter__4__name[] = "PEQ_FREQ5";
PROGMEM prog_char EffectType__4__Parameter__5__name[] = "PEQ_Q1";
PROGMEM prog_char EffectType__4__Parameter__6__name[] = "PEQ_Q2";
PROGMEM prog_char EffectType__4__Parameter__7__name[] = "PEQ_Q3";
PROGMEM prog_char EffectType__4__Parameter__8__name[] = "PEQ_Q4";
PROGMEM prog_char EffectType__4__Parameter__9__name[] = "PEQ_Q5";
PROGMEM prog_char EffectType__4__Parameter__10__name[] = "PEQ_GAIN1";
PROGMEM prog_char EffectType__4__Parameter__11__name[] = "PEQ_GAIN2";
PROGMEM prog_char EffectType__4__Parameter__12__name[] = "PEQ_GAIN3";
PROGMEM prog_char EffectType__4__Parameter__13__name[] = "PEQ_GAIN4";
PROGMEM prog_char EffectType__4__Parameter__14__name[] = "PEQ_GAIN5";
PROGMEM prog_char EffectType__4__Parameter__15__name[] = "PEQ_LFTYPE";
PROGMEM prog_char EffectType__4__Parameter__16__name[] = "PEQ_HFTYPE";
PROGMEM prog_char EffectType__4__Parameter__17__name[] = "PEQ_SPARE3";
PROGMEM prog_char EffectType__4__Parameter__18__name[] = "PEQ_MIX";
PROGMEM prog_char EffectType__4__Parameter__19__name[] = "PEQ_LEVEL";
PROGMEM prog_char EffectType__4__Parameter__20__name[] = "PEQ_PAN";
PROGMEM prog_char EffectType__4__Parameter__21__name[] = "PEQ_BYPASSMODE";
PROGMEM prog_char EffectType__4__Parameter__22__name[] = "PEQ_GLOBALMIX";
PROGMEM prog_char EffectType__4__Parameter__23__name[] = "PEQ_BYPASS";
PROGMEM prog_char EffectType__5__Parameter__0__name[] = "DISTORT_TYPE";
PROGMEM prog_char EffectType__5__Parameter__1__name[] = "DISTORT_DRIVE";
PROGMEM prog_char EffectType__5__Parameter__2__name[] = "DISTORT_BASS";
PROGMEM prog_char EffectType__5__Parameter__3__name[] = "DISTORT_MID";
PROGMEM prog_char EffectType__5__Parameter__4__name[] = "DISTORT_TREBLE";
PROGMEM prog_char EffectType__5__Parameter__5__name[] = "DISTORT_MASTER";
PROGMEM prog_char EffectType__5__Parameter__6__name[] = "DISTORT_HPFREQ";
PROGMEM prog_char EffectType__5__Parameter__7__name[] = "DISTORT_LPFREQ";
PROGMEM prog_char EffectType__5__Parameter__8__name[] = "DISTORT_TONEFREQ";
PROGMEM prog_char EffectType__5__Parameter__9__name[] = "DISTORT_TONESPACE";
PROGMEM prog_char EffectType__5__Parameter__10__name[] = "DISTORT_BRIGHTCAP";
PROGMEM prog_char EffectType__5__Parameter__11__name[] = "DISTORT_WSLPF";
PROGMEM prog_char EffectType__5__Parameter__12__name[] = "DISTORT_XFHPF";
PROGMEM prog_char EffectType__5__Parameter__13__name[] = "DISTORT_XFLPF";
PROGMEM prog_char EffectType__5__Parameter__14__name[] = "DISTORT_TONELOC";
PROGMEM prog_char EffectType__5__Parameter__15__name[] = "DISTORT_INPUTSELECT";
PROGMEM prog_char EffectType__5__Parameter__16__name[] = "DISTORT_DEPTH";
PROGMEM prog_char EffectType__5__Parameter__17__name[] = "DISTORT_OFFSET1";
PROGMEM prog_char EffectType__5__Parameter__18__name[] = "DISTORT_CLIPTYPE2";
PROGMEM prog_char EffectType__5__Parameter__19__name[] = "DISTORT_SUPPLYSAG";
PROGMEM prog_char EffectType__5__Parameter__20__name[] = "DISTORT_PRESENCE";
PROGMEM prog_char EffectType__5__Parameter__21__name[] = "DISTORT_LEVEL";
PROGMEM prog_char EffectType__5__Parameter__22__name[] = "DISTORT_PAN";
PROGMEM prog_char EffectType__5__Parameter__23__name[] = "DISTORT_BYPASSMODE";
PROGMEM prog_char EffectType__5__Parameter__24__name[] = "DISTORT_BETA";
PROGMEM prog_char EffectType__5__Parameter__25__name[] = "DISTORT_PRESFREQ";
PROGMEM prog_char EffectType__5__Parameter__26__name[] = "DISTORT_SPKRFREQ";
PROGMEM prog_char EffectType__5__Parameter__27__name[] = "DISTORT_SPKRGAIN";
PROGMEM prog_char EffectType__5__Parameter__28__name[] = "DISTORT_BYPASS";
PROGMEM prog_char EffectType__5__Parameter__29__name[] = "DISTORT_DEPTHFREQ";
PROGMEM prog_char EffectType__5__Parameter__30__name[] = "DISTORT_HARDNESS";
PROGMEM prog_char EffectType__5__Parameter__31__name[] = "DISTORT_MVCAP";
PROGMEM prog_char EffectType__5__Parameter__32__name[] = "DISTORT_WSHPF";
PROGMEM prog_char EffectType__5__Parameter__33__name[] = "DISTORT_STABILIZER";
PROGMEM prog_char EffectType__5__Parameter__34__name[] = "DISTORT_TONETYPE";
PROGMEM prog_char EffectType__5__Parameter__35__name[] = "DISTORT_TIMECONST";
PROGMEM prog_char EffectType__5__Parameter__36__name[] = "DISTORT_BIAS";
PROGMEM prog_char EffectType__5__Parameter__37__name[] = "DISTORT_FBTYPE";
PROGMEM prog_char EffectType__5__Parameter__38__name[] = "DISTORT_SPKRGAIN2";
PROGMEM prog_char EffectType__5__Parameter__39__name[] = "DISTORT_BRIGHT";
PROGMEM prog_char EffectType__5__Parameter__40__name[] = "DISTORT_BOOST";
PROGMEM prog_char EffectType__5__Parameter__41__name[] = "DISTORT_SPKRQ";
PROGMEM prog_char EffectType__5__Parameter__42__name[] = "DISTORT_OFFSET2";
PROGMEM prog_char EffectType__5__Parameter__43__name[] = "DISTORT_SPKRHFREQ";
PROGMEM prog_char EffectType__5__Parameter__44__name[] = "DISTORT_SPKRHGAIN";
PROGMEM prog_char EffectType__5__Parameter__45__name[] = "DISTORT_SPKRHQ";
PROGMEM prog_char EffectType__5__Parameter__46__name[] = "DISTORT_XDRIVE";
PROGMEM prog_char EffectType__5__Parameter__47__name[] = "DISTORT_TRIM";
PROGMEM prog_char EffectType__5__Parameter__48__name[] = "DISTORT_HARDNESS2";
PROGMEM prog_char EffectType__5__Parameter__49__name[] = "DISTORT_MVPOSITION";
PROGMEM prog_char EffectType__5__Parameter__50__name[] = "DISTORT_SPKRDRIVE";
PROGMEM prog_char EffectType__5__Parameter__51__name[] = "DISTORT_GAINDIST";
PROGMEM prog_char EffectType__5__Parameter__52__name[] = "DISTORT_SCREENFREQ";
PROGMEM prog_char EffectType__5__Parameter__53__name[] = "DISTORT_SCREENQ";
PROGMEM prog_char EffectType__5__Parameter__54__name[] = "DISTORT_SATSWITCH";
PROGMEM prog_char EffectType__5__Parameter__55__name[] = "DISTORT_EQ1";
PROGMEM prog_char EffectType__5__Parameter__56__name[] = "DISTORT_EQ2";
PROGMEM prog_char EffectType__5__Parameter__57__name[] = "DISTORT_EQ3";
PROGMEM prog_char EffectType__5__Parameter__58__name[] = "DISTORT_EQ4";
PROGMEM prog_char EffectType__5__Parameter__59__name[] = "DISTORT_EQ5";
PROGMEM prog_char EffectType__5__Parameter__60__name[] = "DISTORT_EQ6";
PROGMEM prog_char EffectType__5__Parameter__61__name[] = "DISTORT_EQ7";
PROGMEM prog_char EffectType__5__Parameter__62__name[] = "DISTORT_EQ8";
PROGMEM prog_char EffectType__5__Parameter__63__name[] = "DISTORT_BIASEXCURSION";
PROGMEM prog_char EffectType__5__Parameter__64__name[] = "DISTORT_EXCURSIONTIME";
PROGMEM prog_char EffectType__5__Parameter__65__name[] = "DISTORT_RECOVERYTIME";
PROGMEM prog_char EffectType__5__Parameter__66__name[] = "DISTORT_FEEDFWDFREQ";
PROGMEM prog_char EffectType__5__Parameter__67__name[] = "DISTORT_FEEDFWDFREQ2";
PROGMEM prog_char EffectType__5__Parameter__68__name[] = "DISTORT_TUBETYPE";
PROGMEM prog_char EffectType__5__Parameter__69__name[] = "DISTORT_VOICING";
PROGMEM prog_char EffectType__5__Parameter__70__name[] = "DISTORT_PALPFREQ";
PROGMEM prog_char EffectType__5__Parameter__71__name[] = "DISTORT_PAHPFREQ";
PROGMEM prog_char EffectType__5__Parameter__72__name[] = "DISTORT_HMFREQ";
PROGMEM prog_char EffectType__5__Parameter__73__name[] = "DISTORT_HMRATIO";
PROGMEM prog_char EffectType__5__Parameter__74__name[] = "DISTORT_SPKRMGAIN";
PROGMEM prog_char EffectType__5__Parameter__75__name[] = "DISTORT_DYNAMICS";
PROGMEM prog_char EffectType__5__Parameter__76__name[] = "DISTORT_DYNTIME";
PROGMEM prog_char EffectType__5__Parameter__77__name[] = "DISTORT_MVTRIM";
PROGMEM prog_char EffectType__5__Parameter__78__name[] = "DISTORT_FAT";
PROGMEM prog_char EffectType__5__Parameter__79__name[] = "DISTORT_DEFINITION";
PROGMEM prog_char EffectType__5__Parameter__80__name[] = "DISTORT_PREDYNAMICS";
PROGMEM prog_char EffectType__5__Parameter__81__name[] = "DISTORT_PREDYNTIME";
PROGMEM prog_char EffectType__5__Parameter__82__name[] = "DISTORT_USEMATCHING";
PROGMEM prog_char EffectType__5__Parameter__83__name[] = "DISTORT_PICKATTACK";
PROGMEM prog_char EffectType__5__Parameter__84__name[] = "DISTORT_DYNPRES";
PROGMEM prog_char EffectType__5__Parameter__85__name[] = "DISTORT_DYNDEPTH";
PROGMEM prog_char EffectType__5__Parameter__86__name[] = "DISTORT_SUPPLYTYPE";
PROGMEM prog_char EffectType__5__Parameter__87__name[] = "DISTORT_LINEFREQ";
PROGMEM prog_char EffectType__5__Parameter__88__name[] = "DISTORT_THUNK";
PROGMEM prog_char EffectType__5__Parameter__89__name[] = "DISTORT_TREMFREQ";
PROGMEM prog_char EffectType__5__Parameter__90__name[] = "DISTORT_TREMDEPTH";
PROGMEM prog_char EffectType__6__Parameter__0__name[] = "CABINET_TYPEL";
PROGMEM prog_char EffectType__6__Parameter__1__name[] = "CABINET_MICL";
PROGMEM prog_char EffectType__6__Parameter__2__name[] = "CABINET_TYPER";
PROGMEM prog_char EffectType__6__Parameter__3__name[] = "CABINET_MICR";
PROGMEM prog_char EffectType__6__Parameter__4__name[] = "CABINET_LINK";
PROGMEM prog_char EffectType__6__Parameter__5__name[] = "CABINET_LEVELL";
PROGMEM prog_char EffectType__6__Parameter__6__name[] = "CABINET_LEVELR";
PROGMEM prog_char EffectType__6__Parameter__7__name[] = "CABINET_PANL";
PROGMEM prog_char EffectType__6__Parameter__8__name[] = "CABINET_PANR";
PROGMEM prog_char EffectType__6__Parameter__9__name[] = "CABINET_LEVEL";
PROGMEM prog_char EffectType__6__Parameter__10__name[] = "CABINET_PAN";
PROGMEM prog_char EffectType__6__Parameter__11__name[] = "CABINET_BYPASSMODE";
PROGMEM prog_char EffectType__6__Parameter__12__name[] = "CABINET_MODE";
PROGMEM prog_char EffectType__6__Parameter__13__name[] = "CABINET_BYPASS";
PROGMEM prog_char EffectType__6__Parameter__14__name[] = "CABINET_DRIVEL";
PROGMEM prog_char EffectType__6__Parameter__15__name[] = "CABINET_DRIVER";
PROGMEM prog_char EffectType__6__Parameter__16__name[] = "CABINET_ROOMMIX";
PROGMEM prog_char EffectType__6__Parameter__17__name[] = "CABINET_ROOMSPACE";
PROGMEM prog_char EffectType__6__Parameter__18__name[] = "CABINET_MICSPACE";
PROGMEM prog_char EffectType__6__Parameter__19__name[] = "CABINET_LOCUT";
PROGMEM prog_char EffectType__6__Parameter__20__name[] = "CABINET_HICUT";
PROGMEM prog_char EffectType__6__Parameter__21__name[] = "CABINET_SIZE";
PROGMEM prog_char EffectType__6__Parameter__22__name[] = "CABINET_PROXIMITY";
PROGMEM prog_char EffectType__6__Parameter__23__name[] = "CABINET_DIRECT";
PROGMEM prog_char EffectType__6__Parameter__24__name[] = "CABINET_DYNAMICS";
PROGMEM prog_char EffectType__6__Parameter__25__name[] = "CABINET_DIRECTFREQ";
PROGMEM prog_char EffectType__6__Parameter__26__name[] = "CABINET_DELAYL";
PROGMEM prog_char EffectType__6__Parameter__27__name[] = "CABINET_DELAYR";
PROGMEM prog_char EffectType__6__Parameter__28__name[] = "CABINET_PROXIMITYR";
PROGMEM prog_char EffectType__7__Parameter__0__name[] = "REVERB_TYPE";
PROGMEM prog_char EffectType__7__Parameter__1__name[] = "REVERB_TIME";
PROGMEM prog_char EffectType__7__Parameter__2__name[] = "REVERB_HICUT";
PROGMEM prog_char EffectType__7__Parameter__3__name[] = "REVERB_HFRATIO";
PROGMEM prog_char EffectType__7__Parameter__4__name[] = "REVERB_DIFFUSION";
PROGMEM prog_char EffectType__7__Parameter__5__name[] = "REVERB_SIZE";
PROGMEM prog_char EffectType__7__Parameter__6__name[] = "REVERB_REVERBDELAY";
PROGMEM prog_char EffectType__7__Parameter__7__name[] = "REVERB_EARLYLEVEL";
PROGMEM prog_char EffectType__7__Parameter__8__name[] = "REVERB_REVERBLEVEL";
PROGMEM prog_char EffectType__7__Parameter__9__name[] = "REVERB_PREDELAY";
PROGMEM prog_char EffectType__7__Parameter__10__name[] = "REVERB_LOWCUT";
PROGMEM prog_char EffectType__7__Parameter__11__name[] = "REVERB_DEPTH";
PROGMEM prog_char EffectType__7__Parameter__12__name[] = "REVERB_RATE";
PROGMEM prog_char EffectType__7__Parameter__13__name[] = "REVERB_MIX";
PROGMEM prog_char EffectType__7__Parameter__14__name[] = "REVERB_LEVEL";
PROGMEM prog_char EffectType__7__Parameter__15__name[] = "REVERB_PAN";
PROGMEM prog_char EffectType__7__Parameter__16__name[] = "REVERB_BYPASSMODE";
PROGMEM prog_char EffectType__7__Parameter__17__name[] = "REVERB_GLOBALMIX";
PROGMEM prog_char EffectType__7__Parameter__18__name[] = "REVERB_GAIN";
PROGMEM prog_char EffectType__7__Parameter__19__name[] = "REVERB_DENSITY";
PROGMEM prog_char EffectType__7__Parameter__20__name[] = "REVERB_INPDIFF";
PROGMEM prog_char EffectType__7__Parameter__21__name[] = "REVERB_INDIFFTIME";
PROGMEM prog_char EffectType__7__Parameter__22__name[] = "REVERB_BYPASS";
PROGMEM prog_char EffectType__7__Parameter__23__name[] = "REVERB_NUMSPRINGS";
PROGMEM prog_char EffectType__7__Parameter__24__name[] = "REVERB_TONE";
PROGMEM prog_char EffectType__7__Parameter__25__name[] = "REVERB_WIDTH";
PROGMEM prog_char EffectType__7__Parameter__26__name[] = "REVERB_FREQ1";
PROGMEM prog_char EffectType__7__Parameter__27__name[] = "REVERB_FREQ2";
PROGMEM prog_char EffectType__7__Parameter__28__name[] = "REVERB_Q1";
PROGMEM prog_char EffectType__7__Parameter__29__name[] = "REVERB_Q2";
PROGMEM prog_char EffectType__7__Parameter__30__name[] = "REVERB_GAIN1";
PROGMEM prog_char EffectType__7__Parameter__31__name[] = "REVERB_GAIN2";
PROGMEM prog_char EffectType__7__Parameter__32__name[] = "REVERB_SPRINGDRIVE";
PROGMEM prog_char EffectType__7__Parameter__33__name[] = "REVERB_LFTIME";
PROGMEM prog_char EffectType__7__Parameter__34__name[] = "REVERB_LFXOVER";
PROGMEM prog_char EffectType__8__Parameter__0__name[] = "DELAY_MODEL";
PROGMEM prog_char EffectType__8__Parameter__1__name[] = "DELAY_TYPE";
PROGMEM prog_char EffectType__8__Parameter__2__name[] = "DELAY_TIME";
PROGMEM prog_char EffectType__8__Parameter__3__name[] = "DELAY_RATIO";
PROGMEM prog_char EffectType__8__Parameter__4__name[] = "DELAY_FEED";
PROGMEM prog_char EffectType__8__Parameter__5__name[] = "DELAY_FEEDL";
PROGMEM prog_char EffectType__8__Parameter__6__name[] = "DELAY_FEEDR";
PROGMEM prog_char EffectType__8__Parameter__7__name[] = "DELAY_DELAYPAN";
PROGMEM prog_char EffectType__8__Parameter__8__name[] = "DELAY_SPREAD";
PROGMEM prog_char EffectType__8__Parameter__9__name[] = "DELAY_TEMPO";
PROGMEM prog_char EffectType__8__Parameter__10__name[] = "DELAY_LOCUT";
PROGMEM prog_char EffectType__8__Parameter__11__name[] = "DELAY_HICUT";
PROGMEM prog_char EffectType__8__Parameter__12__name[] = "DELAY_RATE1";
PROGMEM prog_char EffectType__8__Parameter__13__name[] = "DELAY_RATE2";
PROGMEM prog_char EffectType__8__Parameter__14__name[] = "DELAY_DEPTH1";
PROGMEM prog_char EffectType__8__Parameter__15__name[] = "DELAY_DEPTH2";
PROGMEM prog_char EffectType__8__Parameter__16__name[] = "DELAY_DRIVE";
PROGMEM prog_char EffectType__8__Parameter__17__name[] = "DELAY_MIX";
PROGMEM prog_char EffectType__8__Parameter__18__name[] = "DELAY_LEVEL";
PROGMEM prog_char EffectType__8__Parameter__19__name[] = "DELAY_PAN";
PROGMEM prog_char EffectType__8__Parameter__20__name[] = "DELAY_BYPASSMODE";
PROGMEM prog_char EffectType__8__Parameter__21__name[] = "DELAY_GLOBALMIX";
PROGMEM prog_char EffectType__8__Parameter__22__name[] = "DELAY_BYPASS";
PROGMEM prog_char EffectType__8__Parameter__23__name[] = "DELAY_GAIN";
PROGMEM prog_char EffectType__8__Parameter__24__name[] = "DELAY_LFO1TYPE";
PROGMEM prog_char EffectType__8__Parameter__25__name[] = "DELAY_LFO2TYPE";
PROGMEM prog_char EffectType__8__Parameter__26__name[] = "DELAY_TIMER";
PROGMEM prog_char EffectType__8__Parameter__27__name[] = "DELAY_HOLD";
PROGMEM prog_char EffectType__8__Parameter__28__name[] = "DELAY_MSTRFDBK";
PROGMEM prog_char EffectType__8__Parameter__29__name[] = "DELAY_TEMPOR";
PROGMEM prog_char EffectType__8__Parameter__30__name[] = "DELAY_FEEDLR";
PROGMEM prog_char EffectType__8__Parameter__31__name[] = "DELAY_FEEDRL";
PROGMEM prog_char EffectType__8__Parameter__32__name[] = "DELAY_LEVELL";
PROGMEM prog_char EffectType__8__Parameter__33__name[] = "DELAY_LEVELR";
PROGMEM prog_char EffectType__8__Parameter__34__name[] = "DELAY_PANL";
PROGMEM prog_char EffectType__8__Parameter__35__name[] = "DELAY_PANR";
PROGMEM prog_char EffectType__8__Parameter__36__name[] = "DELAY_LFO1PHASE";
PROGMEM prog_char EffectType__8__Parameter__37__name[] = "DELAY_LFO2PHASE";
PROGMEM prog_char EffectType__8__Parameter__38__name[] = "DELAY_SPLICETIME";
PROGMEM prog_char EffectType__8__Parameter__39__name[] = "DELAY_RUN";
PROGMEM prog_char EffectType__8__Parameter__40__name[] = "DELAY_MODE";
PROGMEM prog_char EffectType__8__Parameter__41__name[] = "DELAY_FILTORDER";
PROGMEM prog_char EffectType__8__Parameter__42__name[] = "DELAY_ATTEN";
PROGMEM prog_char EffectType__8__Parameter__43__name[] = "DELAY_THRESH";
PROGMEM prog_char EffectType__8__Parameter__44__name[] = "DELAY_RELEASE";
PROGMEM prog_char EffectType__8__Parameter__45__name[] = "DELAY_DIFFUSE";
PROGMEM prog_char EffectType__8__Parameter__46__name[] = "DELAY_DIFFTIME";
PROGMEM prog_char EffectType__8__Parameter__47__name[] = "DELAY_PHASEREV";
PROGMEM prog_char EffectType__8__Parameter__48__name[] = "DELAY_LFO1TARGET";
PROGMEM prog_char EffectType__8__Parameter__49__name[] = "DELAY_LFO2TARGET";
PROGMEM prog_char EffectType__8__Parameter__50__name[] = "DELAY_LFO1TEMPO";
PROGMEM prog_char EffectType__8__Parameter__51__name[] = "DELAY_LFO2TEMPO";
PROGMEM prog_char EffectType__8__Parameter__52__name[] = "DELAY_RATE3";
PROGMEM prog_char EffectType__8__Parameter__53__name[] = "DELAY_LFO3TYPE";
PROGMEM prog_char EffectType__8__Parameter__54__name[] = "DELAY_LFO3PHASE";
PROGMEM prog_char EffectType__8__Parameter__55__name[] = "DELAY_LFO3TEMPO";
PROGMEM prog_char EffectType__8__Parameter__56__name[] = "DELAY_FSTART";
PROGMEM prog_char EffectType__8__Parameter__57__name[] = "DELAY_FSTOP";
PROGMEM prog_char EffectType__8__Parameter__58__name[] = "DELAY_Q";
PROGMEM prog_char EffectType__8__Parameter__59__name[] = "DELAY_FILTERQ";
PROGMEM prog_char EffectType__8__Parameter__60__name[] = "DELAY_BITREDUCE";
PROGMEM prog_char EffectType__8__Parameter__61__name[] = "DELAY_FREQ1";
PROGMEM prog_char EffectType__8__Parameter__62__name[] = "DELAY_FREQ2";
PROGMEM prog_char EffectType__8__Parameter__63__name[] = "DELAY_Q1";
PROGMEM prog_char EffectType__8__Parameter__64__name[] = "DELAY_Q2";
PROGMEM prog_char EffectType__8__Parameter__65__name[] = "DELAY_GAIN1";
PROGMEM prog_char EffectType__8__Parameter__66__name[] = "DELAY_GAIN2";
PROGMEM prog_char EffectType__8__Parameter__67__name[] = "DELAY_LFORANGE";
PROGMEM prog_char EffectType__8__Parameter__68__name[] = "DELAY_SPEED";
PROGMEM prog_char EffectType__8__Parameter__69__name[] = "DELAY_OFFSET";
PROGMEM prog_char EffectType__9__Parameter__0__name[] = "MULTITAP_TIME1";
PROGMEM prog_char EffectType__9__Parameter__1__name[] = "MULTITAP_TIME2";
PROGMEM prog_char EffectType__9__Parameter__2__name[] = "MULTITAP_TIME3";
PROGMEM prog_char EffectType__9__Parameter__3__name[] = "MULTITAP_TIME4";
PROGMEM prog_char EffectType__9__Parameter__4__name[] = "MULTITAP_TEMPO1";
PROGMEM prog_char EffectType__9__Parameter__5__name[] = "MULTITAP_TEMPO2";
PROGMEM prog_char EffectType__9__Parameter__6__name[] = "MULTITAP_TEMPO3";
PROGMEM prog_char EffectType__9__Parameter__7__name[] = "MULTITAP_TEMPO4";
PROGMEM prog_char EffectType__9__Parameter__8__name[] = "MULTITAP_LEVEL1";
PROGMEM prog_char EffectType__9__Parameter__9__name[] = "MULTITAP_LEVEL2";
PROGMEM prog_char EffectType__9__Parameter__10__name[] = "MULTITAP_LEVEL3";
PROGMEM prog_char EffectType__9__Parameter__11__name[] = "MULTITAP_LEVEL4";
PROGMEM prog_char EffectType__9__Parameter__12__name[] = "MULTITAP_FEEDBACK1";
PROGMEM prog_char EffectType__9__Parameter__13__name[] = "MULTITAP_FEEDBACK2";
PROGMEM prog_char EffectType__9__Parameter__14__name[] = "MULTITAP_FEEDBACK3";
PROGMEM prog_char EffectType__9__Parameter__15__name[] = "MULTITAP_FEEDBACK4";
PROGMEM prog_char EffectType__9__Parameter__16__name[] = "MULTITAP_PAN1";
PROGMEM prog_char EffectType__9__Parameter__17__name[] = "MULTITAP_PAN2";
PROGMEM prog_char EffectType__9__Parameter__18__name[] = "MULTITAP_PAN3";
PROGMEM prog_char EffectType__9__Parameter__19__name[] = "MULTITAP_PAN4";
PROGMEM prog_char EffectType__9__Parameter__20__name[] = "MULTITAP_RATE1";
PROGMEM prog_char EffectType__9__Parameter__21__name[] = "MULTITAP_RATE2";
PROGMEM prog_char EffectType__9__Parameter__22__name[] = "MULTITAP_RATE3";
PROGMEM prog_char EffectType__9__Parameter__23__name[] = "MULTITAP_RATE4";
PROGMEM prog_char EffectType__9__Parameter__24__name[] = "MULTITAP_LFOTEMPO1";
PROGMEM prog_char EffectType__9__Parameter__25__name[] = "MULTITAP_LFOTEMPO2";
PROGMEM prog_char EffectType__9__Parameter__26__name[] = "MULTITAP_LFOTEMPO3";
PROGMEM prog_char EffectType__9__Parameter__27__name[] = "MULTITAP_LFOTEMPO4";
PROGMEM prog_char EffectType__9__Parameter__28__name[] = "MULTITAP_MIX";
PROGMEM prog_char EffectType__9__Parameter__29__name[] = "MULTITAP_LEVEL";
PROGMEM prog_char EffectType__9__Parameter__30__name[] = "MULTITAP_PAN";
PROGMEM prog_char EffectType__9__Parameter__31__name[] = "MULTITAP_BYPASSMODE";
PROGMEM prog_char EffectType__9__Parameter__32__name[] = "MULTITAP_GLOBALMIX";
PROGMEM prog_char EffectType__9__Parameter__33__name[] = "MULTITAP_INGAIN";
PROGMEM prog_char EffectType__9__Parameter__34__name[] = "MULTITAP_BYPASS";
PROGMEM prog_char EffectType__9__Parameter__35__name[] = "MULTITAP_TYPE";
PROGMEM prog_char EffectType__9__Parameter__36__name[] = "MULTITAP_DECAY";
PROGMEM prog_char EffectType__9__Parameter__37__name[] = "MULTITAP_DIFFUSION";
PROGMEM prog_char EffectType__9__Parameter__38__name[] = "MULTITAP_DIFFMIX";
PROGMEM prog_char EffectType__9__Parameter__39__name[] = "MULTITAP_DIFFTIME";
PROGMEM prog_char EffectType__9__Parameter__40__name[] = "MULTITAP_THRESH";
PROGMEM prog_char EffectType__9__Parameter__41__name[] = "MULTITAP_SPLICE";
PROGMEM prog_char EffectType__9__Parameter__42__name[] = "MULTITAP_MSTRTIME";
PROGMEM prog_char EffectType__9__Parameter__43__name[] = "MULTITAP_MSTRLVL";
PROGMEM prog_char EffectType__9__Parameter__44__name[] = "MULTITAP_MSTRPAN";
PROGMEM prog_char EffectType__9__Parameter__45__name[] = "MULTITAP_MSTRFREQ";
PROGMEM prog_char EffectType__9__Parameter__46__name[] = "MULTITAP_MSTRQ";
PROGMEM prog_char EffectType__9__Parameter__47__name[] = "MULTITAP_MSTRFDBK";
PROGMEM prog_char EffectType__9__Parameter__48__name[] = "MULTITAP_MSTRPITCH";
PROGMEM prog_char EffectType__9__Parameter__49__name[] = "MULTITAP_MSTRDTN";
PROGMEM prog_char EffectType__9__Parameter__50__name[] = "MULTITAP_DETUNE1";
PROGMEM prog_char EffectType__9__Parameter__51__name[] = "MULTITAP_DETUNE2";
PROGMEM prog_char EffectType__9__Parameter__52__name[] = "MULTITAP_DETUNE3";
PROGMEM prog_char EffectType__9__Parameter__53__name[] = "MULTITAP_DETUNE4";
PROGMEM prog_char EffectType__9__Parameter__54__name[] = "MULTITAP_SHIFT1";
PROGMEM prog_char EffectType__9__Parameter__55__name[] = "MULTITAP_SHIFT2";
PROGMEM prog_char EffectType__9__Parameter__56__name[] = "MULTITAP_SHIFT3";
PROGMEM prog_char EffectType__9__Parameter__57__name[] = "MULTITAP_SHIFT4";
PROGMEM prog_char EffectType__9__Parameter__58__name[] = "MULTITAP_FREQ1";
PROGMEM prog_char EffectType__9__Parameter__59__name[] = "MULTITAP_FREQ2";
PROGMEM prog_char EffectType__9__Parameter__60__name[] = "MULTITAP_FREQ3";
PROGMEM prog_char EffectType__9__Parameter__61__name[] = "MULTITAP_FREQ4";
PROGMEM prog_char EffectType__9__Parameter__62__name[] = "MULTITAP_Q1";
PROGMEM prog_char EffectType__9__Parameter__63__name[] = "MULTITAP_Q2";
PROGMEM prog_char EffectType__9__Parameter__64__name[] = "MULTITAP_Q3";
PROGMEM prog_char EffectType__9__Parameter__65__name[] = "MULTITAP_Q4";
PROGMEM prog_char EffectType__9__Parameter__66__name[] = "MULTITAP_MSTRRATE";
PROGMEM prog_char EffectType__9__Parameter__67__name[] = "MULTITAP_ATTEN";
PROGMEM prog_char EffectType__9__Parameter__68__name[] = "MULTITAP_MSTRDEPTH";
PROGMEM prog_char EffectType__9__Parameter__69__name[] = "MULTITAP_DIRECTION";
PROGMEM prog_char EffectType__9__Parameter__70__name[] = "MULTITAP_SPEED";
PROGMEM prog_char EffectType__9__Parameter__71__name[] = "MULTITAP_DEPTH1";
PROGMEM prog_char EffectType__9__Parameter__72__name[] = "MULTITAP_DEPTH2";
PROGMEM prog_char EffectType__9__Parameter__73__name[] = "MULTITAP_DEPTH3";
PROGMEM prog_char EffectType__9__Parameter__74__name[] = "MULTITAP_DEPTH4";
PROGMEM prog_char EffectType__9__Parameter__75__name[] = "MULTITAP_LFOLOCK";
PROGMEM prog_char EffectType__9__Parameter__76__name[] = "MULTITAP_FBKSEND";
PROGMEM prog_char EffectType__9__Parameter__77__name[] = "MULTITAP_FBKRET";
PROGMEM prog_char EffectType__9__Parameter__78__name[] = "MULTITAP_STEREO";
PROGMEM prog_char EffectType__9__Parameter__79__name[] = "MULTITAP_TIMEM";
PROGMEM prog_char EffectType__9__Parameter__80__name[] = "MULTITAP_SUBDIV";
PROGMEM prog_char EffectType__9__Parameter__81__name[] = "MULTITAP_QUANTIZE";
PROGMEM prog_char EffectType__9__Parameter__82__name[] = "MULTITAP_RDECAY";
PROGMEM prog_char EffectType__9__Parameter__83__name[] = "MULTITAP_DECAYSTYLE";
PROGMEM prog_char EffectType__9__Parameter__84__name[] = "MULTITAP_NUMTAPS";
PROGMEM prog_char EffectType__9__Parameter__85__name[] = "MULTITAP_SHUFFLE";
PROGMEM prog_char EffectType__9__Parameter__86__name[] = "MULTITAP_RTEMPO";
PROGMEM prog_char EffectType__9__Parameter__87__name[] = "MULTITAP_SPREAD";
PROGMEM prog_char EffectType__9__Parameter__88__name[] = "MULTITAP_PANSHAPE";
PROGMEM prog_char EffectType__9__Parameter__89__name[] = "MULTITAP_PANALPHA";
PROGMEM prog_char EffectType__9__Parameter__90__name[] = "MULTITAP_LOWCUT";
PROGMEM prog_char EffectType__9__Parameter__91__name[] = "MULTITAP_HICUT";
PROGMEM prog_char EffectType__9__Parameter__92__name[] = "MULTITAP_OFFSET";
PROGMEM prog_char EffectType__9__Parameter__93__name[] = "MULTITAP_FEEDBACK";
PROGMEM prog_char EffectType__9__Parameter__94__name[] = "MULTITAP_TIME1M";
PROGMEM prog_char EffectType__9__Parameter__95__name[] = "MULTITAP_TIME2M";
PROGMEM prog_char EffectType__9__Parameter__96__name[] = "MULTITAP_TIME3M";
PROGMEM prog_char EffectType__9__Parameter__97__name[] = "MULTITAP_TIME4M";
PROGMEM prog_char EffectType__9__Parameter__98__name[] = "MULTITAP_TIME5M";
PROGMEM prog_char EffectType__9__Parameter__99__name[] = "MULTITAP_TIME6M";
PROGMEM prog_char EffectType__9__Parameter__100__name[] = "MULTITAP_TIME7M";
PROGMEM prog_char EffectType__9__Parameter__101__name[] = "MULTITAP_TIME8M";
PROGMEM prog_char EffectType__9__Parameter__102__name[] = "MULTITAP_TIME9M";
PROGMEM prog_char EffectType__9__Parameter__103__name[] = "MULTITAP_TIME10M";
PROGMEM prog_char EffectType__9__Parameter__104__name[] = "MULTITAP_RLEVEL1";
PROGMEM prog_char EffectType__9__Parameter__105__name[] = "MULTITAP_RLEVEL2";
PROGMEM prog_char EffectType__9__Parameter__106__name[] = "MULTITAP_RLEVEL3";
PROGMEM prog_char EffectType__9__Parameter__107__name[] = "MULTITAP_RLEVEL4";
PROGMEM prog_char EffectType__9__Parameter__108__name[] = "MULTITAP_RLEVEL5";
PROGMEM prog_char EffectType__9__Parameter__109__name[] = "MULTITAP_RLEVEL6";
PROGMEM prog_char EffectType__9__Parameter__110__name[] = "MULTITAP_RLEVEL7";
PROGMEM prog_char EffectType__9__Parameter__111__name[] = "MULTITAP_RLEVEL8";
PROGMEM prog_char EffectType__9__Parameter__112__name[] = "MULTITAP_RLEVEL9";
PROGMEM prog_char EffectType__9__Parameter__113__name[] = "MULTITAP_RLEVEL10";
PROGMEM prog_char EffectType__9__Parameter__114__name[] = "MULTITAP_REFTEMPO";
PROGMEM prog_char EffectType__9__Parameter__115__name[] = "MULTITAP_TRACKTEMPO";
PROGMEM prog_char EffectType__9__Parameter__116__name[] = "MULTITAP_RELEASE";
PROGMEM prog_char EffectType__10__Parameter__0__name[] = "CHORUS_TYPE";
PROGMEM prog_char EffectType__10__Parameter__1__name[] = "CHORUS_VOICES";
PROGMEM prog_char EffectType__10__Parameter__2__name[] = "CHORUS_RATE";
PROGMEM prog_char EffectType__10__Parameter__3__name[] = "CHORUS_TEMPO";
PROGMEM prog_char EffectType__10__Parameter__4__name[] = "CHORUS_DEPTH";
PROGMEM prog_char EffectType__10__Parameter__5__name[] = "CHORUS_HICUT";
PROGMEM prog_char EffectType__10__Parameter__6__name[] = "CHORUS_DELAYTIME";
PROGMEM prog_char EffectType__10__Parameter__7__name[] = "CHORUS_LFOPHASE";
PROGMEM prog_char EffectType__10__Parameter__8__name[] = "CHORUS_LFOTYPE";
PROGMEM prog_char EffectType__10__Parameter__9__name[] = "CHORUS_AUTO";
PROGMEM prog_char EffectType__10__Parameter__10__name[] = "CHORUS_MIX";
PROGMEM prog_char EffectType__10__Parameter__11__name[] = "CHORUS_LEVEL";
PROGMEM prog_char EffectType__10__Parameter__12__name[] = "CHORUS_PAN";
PROGMEM prog_char EffectType__10__Parameter__13__name[] = "CHORUS_BYPASSMODE";
PROGMEM prog_char EffectType__10__Parameter__14__name[] = "CHORUS_GLOBALMIX";
PROGMEM prog_char EffectType__10__Parameter__15__name[] = "CHORUS_BYPASS";
PROGMEM prog_char EffectType__10__Parameter__16__name[] = "CHORUS_PHASEREV";
PROGMEM prog_char EffectType__10__Parameter__17__name[] = "CHORUS_WIDTH";
PROGMEM prog_char EffectType__10__Parameter__18__name[] = "CHORUS_LFO2RATE";
PROGMEM prog_char EffectType__10__Parameter__19__name[] = "CHORUS_LFO2DEPTH";
PROGMEM prog_char EffectType__10__Parameter__20__name[] = "CHORUS_DRIVE";
PROGMEM prog_char EffectType__10__Parameter__21__name[] = "CHORUS_LOCUT";
PROGMEM prog_char EffectType__10__Parameter__22__name[] = "CHORUS_SPREAD";
PROGMEM prog_char EffectType__11__Parameter__0__name[] = "FLANGER_TYPE";
PROGMEM prog_char EffectType__11__Parameter__1__name[] = "FLANGER_RATE";
PROGMEM prog_char EffectType__11__Parameter__2__name[] = "FLANGER_TEMPO";
PROGMEM prog_char EffectType__11__Parameter__3__name[] = "FLANGER_DEPTH";
PROGMEM prog_char EffectType__11__Parameter__4__name[] = "FLANGER_FEEDBACK";
PROGMEM prog_char EffectType__11__Parameter__5__name[] = "FLANGER_DELAYTIME";
PROGMEM prog_char EffectType__11__Parameter__6__name[] = "FLANGER_MANUAL";
PROGMEM prog_char EffectType__11__Parameter__7__name[] = "FLANGER_LFOPHASE";
PROGMEM prog_char EffectType__11__Parameter__8__name[] = "FLANGER_LFOTYPE";
PROGMEM prog_char EffectType__11__Parameter__9__name[] = "FLANGER_LFOFILTER";
PROGMEM prog_char EffectType__11__Parameter__10__name[] = "FLANGER_AUTO";
PROGMEM prog_char EffectType__11__Parameter__11__name[] = "FLANGER_MIX";
PROGMEM prog_char EffectType__11__Parameter__12__name[] = "FLANGER_LEVEL";
PROGMEM prog_char EffectType__11__Parameter__13__name[] = "FLANGER_PAN";
PROGMEM prog_char EffectType__11__Parameter__14__name[] = "FLANGER_BYPASSMODE";
PROGMEM prog_char EffectType__11__Parameter__15__name[] = "FLANGER_GLOBALMIX";
PROGMEM prog_char EffectType__11__Parameter__16__name[] = "FLANGER_BYPASS";
PROGMEM prog_char EffectType__11__Parameter__17__name[] = "FLANGER_PHASEREV";
PROGMEM prog_char EffectType__11__Parameter__18__name[] = "FLANGER_THRUZERO";
PROGMEM prog_char EffectType__11__Parameter__19__name[] = "FLANGER_HICUT";
PROGMEM prog_char EffectType__11__Parameter__20__name[] = "FLANGER_DRIVE";
PROGMEM prog_char EffectType__11__Parameter__21__name[] = "FLANGER_LOCUT";
PROGMEM prog_char EffectType__11__Parameter__22__name[] = "FLANGER_SPREAD";
PROGMEM prog_char EffectType__12__Parameter__0__name[] = "ROTARY_RATE";
PROGMEM prog_char EffectType__12__Parameter__1__name[] = "ROTARY_LFDEPTH";
PROGMEM prog_char EffectType__12__Parameter__2__name[] = "ROTARY_HFDEPTH";
PROGMEM prog_char EffectType__12__Parameter__3__name[] = "ROTARY_HFLEVEL";
PROGMEM prog_char EffectType__12__Parameter__4__name[] = "ROTARY_TEMPO";
PROGMEM prog_char EffectType__12__Parameter__5__name[] = "ROTARY_MIX";
PROGMEM prog_char EffectType__12__Parameter__6__name[] = "ROTARY_LEVEL";
PROGMEM prog_char EffectType__12__Parameter__7__name[] = "ROTARY_PAN";
PROGMEM prog_char EffectType__12__Parameter__8__name[] = "ROTARY_BYPASSMODE";
PROGMEM prog_char EffectType__12__Parameter__9__name[] = "ROTARY_GLOBALMIX";
PROGMEM prog_char EffectType__12__Parameter__10__name[] = "ROTARY_HFLENGTH";
PROGMEM prog_char EffectType__12__Parameter__11__name[] = "ROTARY_BYPASS";
PROGMEM prog_char EffectType__12__Parameter__12__name[] = "ROTARY_WIDTH";
PROGMEM prog_char EffectType__12__Parameter__13__name[] = "ROTARY_LOWMULT";
PROGMEM prog_char EffectType__12__Parameter__14__name[] = "ROTARY_LOWTIME";
PROGMEM prog_char EffectType__12__Parameter__15__name[] = "ROTARY_HIGHTIME";
PROGMEM prog_char EffectType__12__Parameter__16__name[] = "ROTARY_LFWIDTH";
PROGMEM prog_char EffectType__12__Parameter__17__name[] = "ROTARY_DRIVE";
PROGMEM prog_char EffectType__13__Parameter__0__name[] = "PHASER_TYPE";
PROGMEM prog_char EffectType__13__Parameter__1__name[] = "PHASER_ORDER";
PROGMEM prog_char EffectType__13__Parameter__2__name[] = "PHASER_RATE";
PROGMEM prog_char EffectType__13__Parameter__3__name[] = "PHASER_LFOTYPE";
PROGMEM prog_char EffectType__13__Parameter__4__name[] = "PHASER_TEMPO";
PROGMEM prog_char EffectType__13__Parameter__5__name[] = "PHASER_DEPTH";
PROGMEM prog_char EffectType__13__Parameter__6__name[] = "PHASER_FEEDBACK";
PROGMEM prog_char EffectType__13__Parameter__7__name[] = "PHASER_FSTART";
PROGMEM prog_char EffectType__13__Parameter__8__name[] = "PHASER_FSPAN";
PROGMEM prog_char EffectType__13__Parameter__9__name[] = "PHASER_LFOPHASE";
PROGMEM prog_char EffectType__13__Parameter__10__name[] = "PHASER_BIAS";
PROGMEM prog_char EffectType__13__Parameter__11__name[] = "PHASER_MIX";
PROGMEM prog_char EffectType__13__Parameter__12__name[] = "PHASER_LEVEL";
PROGMEM prog_char EffectType__13__Parameter__13__name[] = "PHASER_PAN";
PROGMEM prog_char EffectType__13__Parameter__14__name[] = "PHASER_BYPASSMODE";
PROGMEM prog_char EffectType__13__Parameter__15__name[] = "PHASER_GLOBALMIX";
PROGMEM prog_char EffectType__13__Parameter__16__name[] = "PHASER_BYPASS";
PROGMEM prog_char EffectType__13__Parameter__17__name[] = "PHASER_MODE";
PROGMEM prog_char EffectType__13__Parameter__18__name[] = "PHASER_FBTAP";
PROGMEM prog_char EffectType__13__Parameter__19__name[] = "PHASER_TONE";
PROGMEM prog_char EffectType__14__Parameter__0__name[] = "WAH_TYPE";
PROGMEM prog_char EffectType__14__Parameter__1__name[] = "WAH_FSTART";
PROGMEM prog_char EffectType__14__Parameter__2__name[] = "WAH_FSTOP";
PROGMEM prog_char EffectType__14__Parameter__3__name[] = "WAH_Q";
PROGMEM prog_char EffectType__14__Parameter__4__name[] = "WAH_TRACK";
PROGMEM prog_char EffectType__14__Parameter__5__name[] = "WAH_FREQ";
PROGMEM prog_char EffectType__14__Parameter__6__name[] = "WAH_LEVEL";
PROGMEM prog_char EffectType__14__Parameter__7__name[] = "WAH_PAN";
PROGMEM prog_char EffectType__14__Parameter__8__name[] = "WAH_BYPASSMODE";
PROGMEM prog_char EffectType__14__Parameter__9__name[] = "WAH_GLOBALMIX";
PROGMEM prog_char EffectType__14__Parameter__10__name[] = "WAH_DRIVE";
PROGMEM prog_char EffectType__14__Parameter__11__name[] = "WAH_SPARE2";
PROGMEM prog_char EffectType__14__Parameter__12__name[] = "WAH_BYPASS";
PROGMEM prog_char EffectType__15__Parameter__0__name[] = "FORMANT_FSTART";
PROGMEM prog_char EffectType__15__Parameter__1__name[] = "FORMANT_FMID";
PROGMEM prog_char EffectType__15__Parameter__2__name[] = "FORMANT_FEND";
PROGMEM prog_char EffectType__15__Parameter__3__name[] = "FORMANT_Q";
PROGMEM prog_char EffectType__15__Parameter__4__name[] = "FORMANT_CTRL";
PROGMEM prog_char EffectType__15__Parameter__5__name[] = "FORMANT_MIX";
PROGMEM prog_char EffectType__15__Parameter__6__name[] = "FORMANT_LEVEL";
PROGMEM prog_char EffectType__15__Parameter__7__name[] = "FORMANT_PAN";
PROGMEM prog_char EffectType__15__Parameter__8__name[] = "FORMANT_BYPASSMODE";
PROGMEM prog_char EffectType__15__Parameter__9__name[] = "FORMANT_GLOBALMIX";
PROGMEM prog_char EffectType__15__Parameter__10__name[] = "FORMANT_SPARE";
PROGMEM prog_char EffectType__15__Parameter__11__name[] = "FORMANT_BYPASS";
PROGMEM prog_char EffectType__16__Parameter__0__name[] = "TREMOLO_TYPE";
PROGMEM prog_char EffectType__16__Parameter__1__name[] = "TREMOLO_LFOTYPE";
PROGMEM prog_char EffectType__16__Parameter__2__name[] = "TREMOLO_RATE";
PROGMEM prog_char EffectType__16__Parameter__3__name[] = "TREMOLO_DEPTH";
PROGMEM prog_char EffectType__16__Parameter__4__name[] = "TREMOLO_DUTY";
PROGMEM prog_char EffectType__16__Parameter__5__name[] = "TREMOLO_TEMPO";
PROGMEM prog_char EffectType__16__Parameter__6__name[] = "TREMOLO_MIX";
PROGMEM prog_char EffectType__16__Parameter__7__name[] = "TREMOLO_LEVEL";
PROGMEM prog_char EffectType__16__Parameter__8__name[] = "TREMOLO_PAN";
PROGMEM prog_char EffectType__16__Parameter__9__name[] = "TREMOLO_BYPASSMODE";
PROGMEM prog_char EffectType__16__Parameter__10__name[] = "TREMOLO_GLOBALMIX";
PROGMEM prog_char EffectType__16__Parameter__11__name[] = "TREMOLO_PHASE";
PROGMEM prog_char EffectType__16__Parameter__12__name[] = "TREMOLO_WIDTH";
PROGMEM prog_char EffectType__16__Parameter__13__name[] = "TREMOLO_CENTER";
PROGMEM prog_char EffectType__16__Parameter__14__name[] = "TREMOLO_BYPASS";
PROGMEM prog_char EffectType__17__Parameter__0__name[] = "PITCH_TYPE";
PROGMEM prog_char EffectType__17__Parameter__1__name[] = "PITCH_PITCHMODE";
PROGMEM prog_char EffectType__17__Parameter__2__name[] = "PITCH_CTRL";
PROGMEM prog_char EffectType__17__Parameter__3__name[] = "PITCH_UCTRL";
PROGMEM prog_char EffectType__17__Parameter__4__name[] = "PITCH_HARM1";
PROGMEM prog_char EffectType__17__Parameter__5__name[] = "PITCH_HARM2";
PROGMEM prog_char EffectType__17__Parameter__6__name[] = "PITCH_KEY";
PROGMEM prog_char EffectType__17__Parameter__7__name[] = "PITCH_SCALE";
PROGMEM prog_char EffectType__17__Parameter__8__name[] = "PITCH_MODE";
PROGMEM prog_char EffectType__17__Parameter__9__name[] = "PITCH_DETUNE1";
PROGMEM prog_char EffectType__17__Parameter__10__name[] = "PITCH_DETUNE2";
PROGMEM prog_char EffectType__17__Parameter__11__name[] = "PITCH_SHIFT1";
PROGMEM prog_char EffectType__17__Parameter__12__name[] = "PITCH_SHIFT2";
PROGMEM prog_char EffectType__17__Parameter__13__name[] = "PITCH_LEVEL1";
PROGMEM prog_char EffectType__17__Parameter__14__name[] = "PITCH_LEVEL2";
PROGMEM prog_char EffectType__17__Parameter__15__name[] = "PITCH_PAN1";
PROGMEM prog_char EffectType__17__Parameter__16__name[] = "PITCH_PAN2";
PROGMEM prog_char EffectType__17__Parameter__17__name[] = "PITCH_DELAY1";
PROGMEM prog_char EffectType__17__Parameter__18__name[] = "PITCH_DELAY2";
PROGMEM prog_char EffectType__17__Parameter__19__name[] = "PITCH_FEEDBACK1";
PROGMEM prog_char EffectType__17__Parameter__20__name[] = "PITCH_FEEDBACK2";
PROGMEM prog_char EffectType__17__Parameter__21__name[] = "PITCH_TRACKMODE";
PROGMEM prog_char EffectType__17__Parameter__22__name[] = "PITCH_TRACKING";
PROGMEM prog_char EffectType__17__Parameter__23__name[] = "PITCH_MIX";
PROGMEM prog_char EffectType__17__Parameter__24__name[] = "PITCH_LEVEL";
PROGMEM prog_char EffectType__17__Parameter__25__name[] = "PITCH_PAN";
PROGMEM prog_char EffectType__17__Parameter__26__name[] = "PITCH_BYPASSMODE";
PROGMEM prog_char EffectType__17__Parameter__27__name[] = "PITCH_GLOBALMIX";
PROGMEM prog_char EffectType__17__Parameter__28__name[] = "PITCH_GAIN";
PROGMEM prog_char EffectType__17__Parameter__29__name[] = "PITCH_BYPASS";
PROGMEM prog_char EffectType__17__Parameter__30__name[] = "PITCH_XFADE";
PROGMEM prog_char EffectType__17__Parameter__31__name[] = "PITCH_SPLICE1";
PROGMEM prog_char EffectType__17__Parameter__32__name[] = "PITCH_SPLICE2";
PROGMEM prog_char EffectType__17__Parameter__33__name[] = "PITCH_DTEMPO1";
PROGMEM prog_char EffectType__17__Parameter__34__name[] = "PITCH_DTEMPO2";
PROGMEM prog_char EffectType__17__Parameter__35__name[] = "PITCH_STEMPO1";
PROGMEM prog_char EffectType__17__Parameter__36__name[] = "PITCH_STEMPO2";
PROGMEM prog_char EffectType__17__Parameter__37__name[] = "PITCH_FBTYPE";
PROGMEM prog_char EffectType__17__Parameter__38__name[] = "PITCH_DIRECTION";
PROGMEM prog_char EffectType__17__Parameter__39__name[] = "PITCH_LPFREQ";
PROGMEM prog_char EffectType__17__Parameter__40__name[] = "PITCH_GLIDE";
PROGMEM prog_char EffectType__17__Parameter__41__name[] = "PITCH_MDELAY";
PROGMEM prog_char EffectType__17__Parameter__42__name[] = "PITCH_MFDBK";
PROGMEM prog_char EffectType__17__Parameter__43__name[] = "PITCH_MPAN";
PROGMEM prog_char EffectType__17__Parameter__44__name[] = "PITCH_MLEVEL";
PROGMEM prog_char EffectType__17__Parameter__45__name[] = "PITCH_CUSTOMNOTE";
PROGMEM prog_char EffectType__17__Parameter__46__name[] = "PITCH_NOTE2";
PROGMEM prog_char EffectType__17__Parameter__47__name[] = "PITCH_NOTE3";
PROGMEM prog_char EffectType__17__Parameter__48__name[] = "PITCH_NOTE4";
PROGMEM prog_char EffectType__17__Parameter__49__name[] = "PITCH_NOTE5";
PROGMEM prog_char EffectType__17__Parameter__50__name[] = "PITCH_NOTE6";
PROGMEM prog_char EffectType__17__Parameter__51__name[] = "PITCH_NOTE7";
PROGMEM prog_char EffectType__17__Parameter__52__name[] = "PITCH_NOTE8";
PROGMEM prog_char EffectType__17__Parameter__53__name[] = "PITCH_CUSTOMSCALE1";
PROGMEM prog_char EffectType__17__Parameter__54__name[] = "PITCH_CUSTOMSCALE2";
PROGMEM prog_char EffectType__17__Parameter__55__name[] = "PITCH_NUMSTEPS";
PROGMEM prog_char EffectType__17__Parameter__56__name[] = "PITCH_NUMREPEATS";
PROGMEM prog_char EffectType__17__Parameter__57__name[] = "PITCH_ARPRUN";
PROGMEM prog_char EffectType__17__Parameter__58__name[] = "PITCH_TEMPO";
PROGMEM prog_char EffectType__17__Parameter__59__name[] = "PITCH_STEP1";
PROGMEM prog_char EffectType__17__Parameter__60__name[] = "PITCH_STEP2";
PROGMEM prog_char EffectType__17__Parameter__61__name[] = "PITCH_STEP3";
PROGMEM prog_char EffectType__17__Parameter__62__name[] = "PITCH_STEP4";
PROGMEM prog_char EffectType__17__Parameter__63__name[] = "PITCH_STEP5";
PROGMEM prog_char EffectType__17__Parameter__64__name[] = "PITCH_STEP6";
PROGMEM prog_char EffectType__17__Parameter__65__name[] = "PITCH_STEP7";
PROGMEM prog_char EffectType__17__Parameter__66__name[] = "PITCH_STEP8";
PROGMEM prog_char EffectType__17__Parameter__67__name[] = "PITCH_STEP9";
PROGMEM prog_char EffectType__17__Parameter__68__name[] = "PITCH_STEP10";
PROGMEM prog_char EffectType__17__Parameter__69__name[] = "PITCH_STEP11";
PROGMEM prog_char EffectType__17__Parameter__70__name[] = "PITCH_STEP12";
PROGMEM prog_char EffectType__17__Parameter__71__name[] = "PITCH_STEP13";
PROGMEM prog_char EffectType__17__Parameter__72__name[] = "PITCH_STEP14";
PROGMEM prog_char EffectType__17__Parameter__73__name[] = "PITCH_STEP15";
PROGMEM prog_char EffectType__17__Parameter__74__name[] = "PITCH_STEP16";
PROGMEM prog_char EffectType__17__Parameter__75__name[] = "PITCH_AMPSHAPE";
PROGMEM prog_char EffectType__17__Parameter__76__name[] = "PITCH_AMPALPHA";
PROGMEM prog_char EffectType__17__Parameter__77__name[] = "PITCH_PANSHAPE";
PROGMEM prog_char EffectType__17__Parameter__78__name[] = "PITCH_PANALPHA";
PROGMEM prog_char EffectType__17__Parameter__79__name[] = "PITCH_TIME1";
PROGMEM prog_char EffectType__17__Parameter__80__name[] = "PITCH_TIME2";
PROGMEM prog_char EffectType__17__Parameter__81__name[] = "PITCH_SOURCE";
PROGMEM prog_char EffectType__17__Parameter__82__name[] = "PITCH_INMODE";
PROGMEM prog_char EffectType__17__Parameter__83__name[] = "PITCH_LEARN";
PROGMEM prog_char EffectType__17__Parameter__84__name[] = "PITCH_LOCUT";
PROGMEM prog_char EffectType__18__Parameter__0__name[] = "FILTER_TYPE";
PROGMEM prog_char EffectType__18__Parameter__1__name[] = "FILTER_FREQ";
PROGMEM prog_char EffectType__18__Parameter__2__name[] = "FILTER_Q";
PROGMEM prog_char EffectType__18__Parameter__3__name[] = "FILTER_GAIN";
PROGMEM prog_char EffectType__18__Parameter__4__name[] = "FILTER_LEVEL";
PROGMEM prog_char EffectType__18__Parameter__5__name[] = "FILTER_BAL";
PROGMEM prog_char EffectType__18__Parameter__6__name[] = "FILTER_BYPASSMODE";
PROGMEM prog_char EffectType__18__Parameter__7__name[] = "FILTER_ORDER";
PROGMEM prog_char EffectType__18__Parameter__8__name[] = "FILTER_BYPASS";
PROGMEM prog_char EffectType__18__Parameter__9__name[] = "FILTER_PANL";
PROGMEM prog_char EffectType__18__Parameter__10__name[] = "FILTER_PANR";
PROGMEM prog_char EffectType__18__Parameter__11__name[] = "FILTER_PHASE";
PROGMEM prog_char EffectType__18__Parameter__12__name[] = "FILTER_LOWCUT";
PROGMEM prog_char EffectType__18__Parameter__13__name[] = "FILTER_HICUT";
PROGMEM prog_char EffectType__19__Parameter__0__name[] = "FUZZ_TYPE";
PROGMEM prog_char EffectType__19__Parameter__1__name[] = "FUZZ_DRIVE";
PROGMEM prog_char EffectType__19__Parameter__2__name[] = "FUZZ_TONE";
PROGMEM prog_char EffectType__19__Parameter__3__name[] = "FUZZ_LEVEL";
PROGMEM prog_char EffectType__19__Parameter__4__name[] = "FUZZ_MIX";
PROGMEM prog_char EffectType__19__Parameter__5__name[] = "FUZZ_BYPASSMODE";
PROGMEM prog_char EffectType__19__Parameter__6__name[] = "FUZZ_SLEW";
PROGMEM prog_char EffectType__19__Parameter__7__name[] = "FUZZ_BYPASS";
PROGMEM prog_char EffectType__19__Parameter__8__name[] = "FUZZ_LOCUT";
PROGMEM prog_char EffectType__19__Parameter__9__name[] = "FUZZ_HICUT";
PROGMEM prog_char EffectType__19__Parameter__10__name[] = "FUZZ_CLIPTYPE";
PROGMEM prog_char EffectType__19__Parameter__11__name[] = "FUZZ_BIAS";
PROGMEM prog_char EffectType__19__Parameter__12__name[] = "FUZZ_BASS";
PROGMEM prog_char EffectType__19__Parameter__13__name[] = "FUZZ_MID";
PROGMEM prog_char EffectType__19__Parameter__14__name[] = "FUZZ_MIDFREQ";
PROGMEM prog_char EffectType__19__Parameter__15__name[] = "FUZZ_TREBLE";
PROGMEM prog_char EffectType__19__Parameter__16__name[] = "FUZZ_BITREDUCE";
PROGMEM prog_char EffectType__19__Parameter__17__name[] = "FUZZ_INPUTSELECT";
PROGMEM prog_char EffectType__19__Parameter__18__name[] = "FUZZ_PAN";
PROGMEM prog_char EffectType__19__Parameter__19__name[] = "FUZZ_RESAMPLE";
PROGMEM prog_char EffectType__20__Parameter__0__name[] = "ENHANCER_WIDTH";
PROGMEM prog_char EffectType__20__Parameter__1__name[] = "ENHANCER_DEPTH";
PROGMEM prog_char EffectType__20__Parameter__2__name[] = "ENHANCER_LOWCUT";
PROGMEM prog_char EffectType__20__Parameter__3__name[] = "ENHANCER_HICUT";
PROGMEM prog_char EffectType__20__Parameter__4__name[] = "ENHANCER_LEVEL";
PROGMEM prog_char EffectType__20__Parameter__5__name[] = "ENHANCER_BYPASS";
PROGMEM prog_char EffectType__20__Parameter__6__name[] = "ENHANCER_TYPE";
PROGMEM prog_char EffectType__20__Parameter__7__name[] = "ENHANCER_INVERT";
PROGMEM prog_char EffectType__20__Parameter__8__name[] = "ENHANCER_PANL";
PROGMEM prog_char EffectType__20__Parameter__9__name[] = "ENHANCER_PANR";
PROGMEM prog_char EffectType__20__Parameter__10__name[] = "ENHANCER_BALANCE";
PROGMEM prog_char EffectType__21__Parameter__0__name[] = "LOOP_LEVEL1";
PROGMEM prog_char EffectType__21__Parameter__1__name[] = "LOOP_LEVEL2";
PROGMEM prog_char EffectType__21__Parameter__2__name[] = "LOOP_LEVEL3";
PROGMEM prog_char EffectType__21__Parameter__3__name[] = "LOOP_LEVEL4";
PROGMEM prog_char EffectType__21__Parameter__4__name[] = "LOOP_PAN1";
PROGMEM prog_char EffectType__21__Parameter__5__name[] = "LOOP_PAN2";
PROGMEM prog_char EffectType__21__Parameter__6__name[] = "LOOP_PAN3";
PROGMEM prog_char EffectType__21__Parameter__7__name[] = "LOOP_PAN4";
PROGMEM prog_char EffectType__21__Parameter__8__name[] = "LOOP_MAIN1";
PROGMEM prog_char EffectType__21__Parameter__9__name[] = "LOOP_MAIN2";
PROGMEM prog_char EffectType__21__Parameter__10__name[] = "LOOP_MAIN3";
PROGMEM prog_char EffectType__21__Parameter__11__name[] = "LOOP_MAIN4";
PROGMEM prog_char EffectType__21__Parameter__12__name[] = "LOOP_MAIN5";
PROGMEM prog_char EffectType__21__Parameter__13__name[] = "LOOP_MAIN6";
PROGMEM prog_char EffectType__21__Parameter__14__name[] = "LOOP_MAIN7";
PROGMEM prog_char EffectType__21__Parameter__15__name[] = "LOOP_MAIN8";
PROGMEM prog_char EffectType__21__Parameter__16__name[] = "LOOP_LEVEL";
PROGMEM prog_char EffectType__21__Parameter__17__name[] = "LOOP_PAN";
PROGMEM prog_char EffectType__21__Parameter__18__name[] = "LOOP_BYPASSMODE";
PROGMEM prog_char EffectType__21__Parameter__19__name[] = "LOOP_BYPASS";
PROGMEM prog_char EffectType__22__Parameter__0__name[] = "MIXER_GAIN1";
PROGMEM prog_char EffectType__22__Parameter__1__name[] = "MIXER_GAIN2";
PROGMEM prog_char EffectType__22__Parameter__2__name[] = "MIXER_GAIN3";
PROGMEM prog_char EffectType__22__Parameter__3__name[] = "MIXER_GAIN4";
PROGMEM prog_char EffectType__22__Parameter__4__name[] = "MIXER_PAN1";
PROGMEM prog_char EffectType__22__Parameter__5__name[] = "MIXER_PAN2";
PROGMEM prog_char EffectType__22__Parameter__6__name[] = "MIXER_PAN3";
PROGMEM prog_char EffectType__22__Parameter__7__name[] = "MIXER_PAN4";
PROGMEM prog_char EffectType__22__Parameter__8__name[] = "MIXER_MASTER";
PROGMEM prog_char EffectType__22__Parameter__9__name[] = "MIXER_MODE";
PROGMEM prog_char EffectType__23__Parameter__0__name[] = "FBSEND_LEVEL";
PROGMEM prog_char EffectType__23__Parameter__1__name[] = "FBSEND_OUTPUT";
PROGMEM prog_char EffectType__24__Parameter__0__name[] = "FEEDBACK_MIX";
PROGMEM prog_char EffectType__24__Parameter__1__name[] = "FEEDBACK_LEVEL";
PROGMEM prog_char EffectType__24__Parameter__2__name[] = "FEEDBACK_PAN";
PROGMEM prog_char EffectType__24__Parameter__3__name[] = "FEEDBACK_BYPASSMODE";
PROGMEM prog_char EffectType__24__Parameter__4__name[] = "FEEDBACK_GLOBALMIX";
PROGMEM prog_char EffectType__24__Parameter__5__name[] = "FEEDBACK_BYPASS";
PROGMEM prog_char EffectType__25__Parameter__0__name[] = "SYNTH_TYPE1";
PROGMEM prog_char EffectType__25__Parameter__1__name[] = "SYNTH_FREQ1";
PROGMEM prog_char EffectType__25__Parameter__2__name[] = "SYNTH_TRACK1";
PROGMEM prog_char EffectType__25__Parameter__3__name[] = "SYNTH_SHIFT1";
PROGMEM prog_char EffectType__25__Parameter__4__name[] = "SYNTH_DETUNE1";
PROGMEM prog_char EffectType__25__Parameter__5__name[] = "SYNTH_DUTY1";
PROGMEM prog_char EffectType__25__Parameter__6__name[] = "SYNTH_LEVEL1";
PROGMEM prog_char EffectType__25__Parameter__7__name[] = "SYNTH_PAN1";
PROGMEM prog_char EffectType__25__Parameter__8__name[] = "SYNTH_ATTACK1";
PROGMEM prog_char EffectType__25__Parameter__9__name[] = "SYNTH_HICUT1";
PROGMEM prog_char EffectType__25__Parameter__10__name[] = "SYNTH_Q1";
PROGMEM prog_char EffectType__25__Parameter__11__name[] = "SYNTH_TYPE2";
PROGMEM prog_char EffectType__25__Parameter__12__name[] = "SYNTH_FREQ2";
PROGMEM prog_char EffectType__25__Parameter__13__name[] = "SYNTH_TRACK2";
PROGMEM prog_char EffectType__25__Parameter__14__name[] = "SYNTH_SHIFT2";
PROGMEM prog_char EffectType__25__Parameter__15__name[] = "SYNTH_DETUNE2";
PROGMEM prog_char EffectType__25__Parameter__16__name[] = "SYNTH_DUTY2";
PROGMEM prog_char EffectType__25__Parameter__17__name[] = "SYNTH_LEVEL2";
PROGMEM prog_char EffectType__25__Parameter__18__name[] = "SYNTH_PAN2";
PROGMEM prog_char EffectType__25__Parameter__19__name[] = "SYNTH_ATTACK2";
PROGMEM prog_char EffectType__25__Parameter__20__name[] = "SYNTH_HICUT2";
PROGMEM prog_char EffectType__25__Parameter__21__name[] = "SYNTH_Q2";
PROGMEM prog_char EffectType__25__Parameter__22__name[] = "SYNTH_SPARE1";
PROGMEM prog_char EffectType__25__Parameter__23__name[] = "SYNTH_MIX";
PROGMEM prog_char EffectType__25__Parameter__24__name[] = "SYNTH_LEVEL";
PROGMEM prog_char EffectType__25__Parameter__25__name[] = "SYNTH_PAN";
PROGMEM prog_char EffectType__25__Parameter__26__name[] = "SYNTH_BYPASSMODE";
PROGMEM prog_char EffectType__25__Parameter__27__name[] = "SYNTH_GLOBALMIX";
PROGMEM prog_char EffectType__25__Parameter__28__name[] = "SYNTH_BYPASS";
PROGMEM prog_char EffectType__25__Parameter__29__name[] = "SYNTH_TYPE3";
PROGMEM prog_char EffectType__25__Parameter__30__name[] = "SYNTH_FREQ3";
PROGMEM prog_char EffectType__25__Parameter__31__name[] = "SYNTH_TRACK3";
PROGMEM prog_char EffectType__25__Parameter__32__name[] = "SYNTH_SHIFT3";
PROGMEM prog_char EffectType__25__Parameter__33__name[] = "SYNTH_DETUNE3";
PROGMEM prog_char EffectType__25__Parameter__34__name[] = "SYNTH_DUTY3";
PROGMEM prog_char EffectType__25__Parameter__35__name[] = "SYNTH_LEVEL3";
PROGMEM prog_char EffectType__25__Parameter__36__name[] = "SYNTH_PAN3";
PROGMEM prog_char EffectType__25__Parameter__37__name[] = "SYNTH_ATTACK3";
PROGMEM prog_char EffectType__25__Parameter__38__name[] = "SYNTH_HICUT3";
PROGMEM prog_char EffectType__25__Parameter__39__name[] = "SYNTH_Q3";
PROGMEM prog_char EffectType__26__Parameter__0__name[] = "VOCODER_INSOURCE";
PROGMEM prog_char EffectType__26__Parameter__1__name[] = "VOCODER_NUMBANDS";
PROGMEM prog_char EffectType__26__Parameter__2__name[] = "VOCODER_FREQSTART";
PROGMEM prog_char EffectType__26__Parameter__3__name[] = "VOCODER_FREQSTOP";
PROGMEM prog_char EffectType__26__Parameter__4__name[] = "VOCODER_CSHIFT";
PROGMEM prog_char EffectType__26__Parameter__5__name[] = "VOCODER_FREEZE";
PROGMEM prog_char EffectType__26__Parameter__6__name[] = "VOCODER_MASTERLVL";
PROGMEM prog_char EffectType__26__Parameter__7__name[] = "VOCODER_MASTERPAN";
PROGMEM prog_char EffectType__26__Parameter__8__name[] = "VOCODER_RES";
PROGMEM prog_char EffectType__26__Parameter__9__name[] = "VOCODER_ATTACK";
PROGMEM prog_char EffectType__26__Parameter__10__name[] = "VOCODER_RELEASE";
PROGMEM prog_char EffectType__26__Parameter__11__name[] = "VOCODER_HPMIX";
PROGMEM prog_char EffectType__26__Parameter__12__name[] = "VOCODER_MIX";
PROGMEM prog_char EffectType__26__Parameter__13__name[] = "VOCODER_LEVEL";
PROGMEM prog_char EffectType__26__Parameter__14__name[] = "VOCODER_PAN";
PROGMEM prog_char EffectType__26__Parameter__15__name[] = "VOCODER_BYPASSMODE";
PROGMEM prog_char EffectType__26__Parameter__16__name[] = "VOCODER_GLOBALMIX";
PROGMEM prog_char EffectType__26__Parameter__17__name[] = "VOCODER_LEVEL1";
PROGMEM prog_char EffectType__26__Parameter__18__name[] = "VOCODER_LEVEL2";
PROGMEM prog_char EffectType__26__Parameter__19__name[] = "VOCODER_LEVEL3";
PROGMEM prog_char EffectType__26__Parameter__20__name[] = "VOCODER_LEVEL4";
PROGMEM prog_char EffectType__26__Parameter__21__name[] = "VOCODER_LEVEL5";
PROGMEM prog_char EffectType__26__Parameter__22__name[] = "VOCODER_LEVEL6";
PROGMEM prog_char EffectType__26__Parameter__23__name[] = "VOCODER_LEVEL7";
PROGMEM prog_char EffectType__26__Parameter__24__name[] = "VOCODER_LEVEL8";
PROGMEM prog_char EffectType__26__Parameter__25__name[] = "VOCODER_LEVEL9";
PROGMEM prog_char EffectType__26__Parameter__26__name[] = "VOCODER_LEVEL10";
PROGMEM prog_char EffectType__26__Parameter__27__name[] = "VOCODER_LEVEL11";
PROGMEM prog_char EffectType__26__Parameter__28__name[] = "VOCODER_LEVEL12";
PROGMEM prog_char EffectType__26__Parameter__29__name[] = "VOCODER_LEVEL13";
PROGMEM prog_char EffectType__26__Parameter__30__name[] = "VOCODER_LEVEL14";
PROGMEM prog_char EffectType__26__Parameter__31__name[] = "VOCODER_LEVEL15";
PROGMEM prog_char EffectType__26__Parameter__32__name[] = "VOCODER_LEVEL16";
PROGMEM prog_char EffectType__26__Parameter__33__name[] = "VOCODER_PAN1";
PROGMEM prog_char EffectType__26__Parameter__34__name[] = "VOCODER_PAN2";
PROGMEM prog_char EffectType__26__Parameter__35__name[] = "VOCODER_PAN3";
PROGMEM prog_char EffectType__26__Parameter__36__name[] = "VOCODER_PAN4";
PROGMEM prog_char EffectType__26__Parameter__37__name[] = "VOCODER_PAN5";
PROGMEM prog_char EffectType__26__Parameter__38__name[] = "VOCODER_PAN6";
PROGMEM prog_char EffectType__26__Parameter__39__name[] = "VOCODER_PAN7";
PROGMEM prog_char EffectType__26__Parameter__40__name[] = "VOCODER_PAN8";
PROGMEM prog_char EffectType__26__Parameter__41__name[] = "VOCODER_PAN9";
PROGMEM prog_char EffectType__26__Parameter__42__name[] = "VOCODER_PAN10";
PROGMEM prog_char EffectType__26__Parameter__43__name[] = "VOCODER_PAN11";
PROGMEM prog_char EffectType__26__Parameter__44__name[] = "VOCODER_PAN12";
PROGMEM prog_char EffectType__26__Parameter__45__name[] = "VOCODER_PAN13";
PROGMEM prog_char EffectType__26__Parameter__46__name[] = "VOCODER_PAN14";
PROGMEM prog_char EffectType__26__Parameter__47__name[] = "VOCODER_PAN15";
PROGMEM prog_char EffectType__26__Parameter__48__name[] = "VOCODER_PAN16";
PROGMEM prog_char EffectType__26__Parameter__49__name[] = "VOCODER_BYPASS";
PROGMEM prog_char EffectType__27__Parameter__0__name[] = "MEGATAP_INGAIN";
PROGMEM prog_char EffectType__27__Parameter__1__name[] = "MEGATAP_MASTERLVL";
PROGMEM prog_char EffectType__27__Parameter__2__name[] = "MEGATAP_TIME";
PROGMEM prog_char EffectType__27__Parameter__3__name[] = "MEGATAP_NUMTAPS";
PROGMEM prog_char EffectType__27__Parameter__4__name[] = "MEGATAP_TIMESHAPE";
PROGMEM prog_char EffectType__27__Parameter__5__name[] = "MEGATAP_TIMEALPHA";
PROGMEM prog_char EffectType__27__Parameter__6__name[] = "MEGATAP_AMPSHAPE";
PROGMEM prog_char EffectType__27__Parameter__7__name[] = "MEGATAP_AMPALPHA";
PROGMEM prog_char EffectType__27__Parameter__8__name[] = "MEGATAP_PANSHAPE";
PROGMEM prog_char EffectType__27__Parameter__9__name[] = "MEGATAP_PANALPHA";
PROGMEM prog_char EffectType__27__Parameter__10__name[] = "MEGATAP_RANDOM";
PROGMEM prog_char EffectType__27__Parameter__11__name[] = "MEGATAP_MIX";
PROGMEM prog_char EffectType__27__Parameter__12__name[] = "MEGATAP_LEVEL";
PROGMEM prog_char EffectType__27__Parameter__13__name[] = "MEGATAP_PAN";
PROGMEM prog_char EffectType__27__Parameter__14__name[] = "MEGATAP_BYPASSMODE";
PROGMEM prog_char EffectType__27__Parameter__15__name[] = "MEGATAP_GLOBALMIX";
PROGMEM prog_char EffectType__27__Parameter__16__name[] = "MEGATAP_BYPASS";
PROGMEM prog_char EffectType__28__Parameter__0__name[] = "CROSSOVER_FREQ";
PROGMEM prog_char EffectType__28__Parameter__1__name[] = "CROSSOVER_FREQRANGE";
PROGMEM prog_char EffectType__28__Parameter__2__name[] = "CROSSOVER_LOWGAINL";
PROGMEM prog_char EffectType__28__Parameter__3__name[] = "CROSSOVER_HIGAINL";
PROGMEM prog_char EffectType__28__Parameter__4__name[] = "CROSSOVER_LOWGAINR";
PROGMEM prog_char EffectType__28__Parameter__5__name[] = "CROSSOVER_HIGAINR";
PROGMEM prog_char EffectType__28__Parameter__6__name[] = "CROSSOVER_LOWPANL";
PROGMEM prog_char EffectType__28__Parameter__7__name[] = "CROSSOVER_HIPANL";
PROGMEM prog_char EffectType__28__Parameter__8__name[] = "CROSSOVER_LOWPANR";
PROGMEM prog_char EffectType__28__Parameter__9__name[] = "CROSSOVER_HIPANR";
PROGMEM prog_char EffectType__28__Parameter__10__name[] = "CROSSOVER_MIX";
PROGMEM prog_char EffectType__28__Parameter__11__name[] = "CROSSOVER_LEVEL";
PROGMEM prog_char EffectType__28__Parameter__12__name[] = "CROSSOVER_PAN";
PROGMEM prog_char EffectType__28__Parameter__13__name[] = "CROSSOVER_BYPASSMODE";
PROGMEM prog_char EffectType__28__Parameter__14__name[] = "CROSSOVER_BYPASS";
PROGMEM prog_char EffectType__29__Parameter__0__name[] = "GATE_THRESH";
PROGMEM prog_char EffectType__29__Parameter__1__name[] = "GATE_ATTACK";
PROGMEM prog_char EffectType__29__Parameter__2__name[] = "GATE_HOLD";
PROGMEM prog_char EffectType__29__Parameter__3__name[] = "GATE_RELEASE";
PROGMEM prog_char EffectType__29__Parameter__4__name[] = "GATE_RATIO";
PROGMEM prog_char EffectType__29__Parameter__5__name[] = "GATE_KEY";
PROGMEM prog_char EffectType__29__Parameter__6__name[] = "GATE_LOWCUT";
PROGMEM prog_char EffectType__29__Parameter__7__name[] = "GATE_HICUT";
PROGMEM prog_char EffectType__29__Parameter__8__name[] = "GATE_MIX";
PROGMEM prog_char EffectType__29__Parameter__9__name[] = "GATE_LEVEL";
PROGMEM prog_char EffectType__29__Parameter__10__name[] = "GATE_PAN";
PROGMEM prog_char EffectType__29__Parameter__11__name[] = "GATE_BYPASSMODE";
PROGMEM prog_char EffectType__29__Parameter__12__name[] = "GATE_BYPASS";
PROGMEM prog_char EffectType__30__Parameter__0__name[] = "RINGMOD_COARSE";
PROGMEM prog_char EffectType__30__Parameter__1__name[] = "RINGMOD_FINE";
PROGMEM prog_char EffectType__30__Parameter__2__name[] = "RINGMOD_TRACK";
PROGMEM prog_char EffectType__30__Parameter__3__name[] = "RINGMOD_LOWCUT";
PROGMEM prog_char EffectType__30__Parameter__4__name[] = "RINGMOD_MIX";
PROGMEM prog_char EffectType__30__Parameter__5__name[] = "RINGMOD_LEVEL";
PROGMEM prog_char EffectType__30__Parameter__6__name[] = "RINGMOD_PAN";
PROGMEM prog_char EffectType__30__Parameter__7__name[] = "RINGMOD_BYPASSMODE";
PROGMEM prog_char EffectType__30__Parameter__8__name[] = "RINGMOD_GLOBALMIX";
PROGMEM prog_char EffectType__30__Parameter__9__name[] = "RINGMOD_BYPASS";
PROGMEM prog_char EffectType__31__Parameter__0__name[] = "MULTICOMP_FREQ1";
PROGMEM prog_char EffectType__31__Parameter__1__name[] = "MULTICOMP_FREQ2";
PROGMEM prog_char EffectType__31__Parameter__2__name[] = "MULTICOMP_THRESH1";
PROGMEM prog_char EffectType__31__Parameter__3__name[] = "MULTICOMP_RATIO1";
PROGMEM prog_char EffectType__31__Parameter__4__name[] = "MULTICOMP_ATTACK1";
PROGMEM prog_char EffectType__31__Parameter__5__name[] = "MULTICOMP_RELEASE1";
PROGMEM prog_char EffectType__31__Parameter__6__name[] = "MULTICOMP_LEVEL1";
PROGMEM prog_char EffectType__31__Parameter__7__name[] = "MULTICOMP_DETECT1";
PROGMEM prog_char EffectType__31__Parameter__8__name[] = "MULTICOMP_MUTE1";
PROGMEM prog_char EffectType__31__Parameter__9__name[] = "MULTICOMP_THRESH2";
PROGMEM prog_char EffectType__31__Parameter__10__name[] = "MULTICOMP_RATIO2";
PROGMEM prog_char EffectType__31__Parameter__11__name[] = "MULTICOMP_ATTACK2";
PROGMEM prog_char EffectType__31__Parameter__12__name[] = "MULTICOMP_RELEASE2";
PROGMEM prog_char EffectType__31__Parameter__13__name[] = "MULTICOMP_LEVEL2";
PROGMEM prog_char EffectType__31__Parameter__14__name[] = "MULTICOMP_DETECT2";
PROGMEM prog_char EffectType__31__Parameter__15__name[] = "MULTICOMP_MUTE2";
PROGMEM prog_char EffectType__31__Parameter__16__name[] = "MULTICOMP_THRESH3";
PROGMEM prog_char EffectType__31__Parameter__17__name[] = "MULTICOMP_RATIO3";
PROGMEM prog_char EffectType__31__Parameter__18__name[] = "MULTICOMP_ATTACK3";
PROGMEM prog_char EffectType__31__Parameter__19__name[] = "MULTICOMP_RELEASE3";
PROGMEM prog_char EffectType__31__Parameter__20__name[] = "MULTICOMP_LEVEL3";
PROGMEM prog_char EffectType__31__Parameter__21__name[] = "MULTICOMP_DETECT3";
PROGMEM prog_char EffectType__31__Parameter__22__name[] = "MULTICOMP_MUTE3";
PROGMEM prog_char EffectType__31__Parameter__23__name[] = "MULTICOMP_MIX";
PROGMEM prog_char EffectType__31__Parameter__24__name[] = "MULTICOMP_LEVEL";
PROGMEM prog_char EffectType__31__Parameter__25__name[] = "MULTICOMP_PAN";
PROGMEM prog_char EffectType__31__Parameter__26__name[] = "MULTICOMP_BYPASSMODE";
PROGMEM prog_char EffectType__31__Parameter__27__name[] = "MULTICOMP_BYPASS";
PROGMEM prog_char EffectType__32__Parameter__0__name[] = "QUADCHO_MASTERTIME";
PROGMEM prog_char EffectType__32__Parameter__1__name[] = "QUADCHO_MASTERLVL";
PROGMEM prog_char EffectType__32__Parameter__2__name[] = "QUADCHO_MASTERPAN";
PROGMEM prog_char EffectType__32__Parameter__3__name[] = "QUADCHO_MASTERRATE";
PROGMEM prog_char EffectType__32__Parameter__4__name[] = "QUADCHO_MASTERDEPTH";
PROGMEM prog_char EffectType__32__Parameter__5__name[] = "QUADCHO_MASTERFDBK";
PROGMEM prog_char EffectType__32__Parameter__6__name[] = "QUADCHO_TIME1";
PROGMEM prog_char EffectType__32__Parameter__7__name[] = "QUADCHO_TIME2";
PROGMEM prog_char EffectType__32__Parameter__8__name[] = "QUADCHO_TIME3";
PROGMEM prog_char EffectType__32__Parameter__9__name[] = "QUADCHO_TIME4";
PROGMEM prog_char EffectType__32__Parameter__10__name[] = "QUADCHO_LEVEL1";
PROGMEM prog_char EffectType__32__Parameter__11__name[] = "QUADCHO_LEVEL2";
PROGMEM prog_char EffectType__32__Parameter__12__name[] = "QUADCHO_LEVEL3";
PROGMEM prog_char EffectType__32__Parameter__13__name[] = "QUADCHO_LEVEL4";
PROGMEM prog_char EffectType__32__Parameter__14__name[] = "QUADCHO_PAN1";
PROGMEM prog_char EffectType__32__Parameter__15__name[] = "QUADCHO_PAN2";
PROGMEM prog_char EffectType__32__Parameter__16__name[] = "QUADCHO_PAN3";
PROGMEM prog_char EffectType__32__Parameter__17__name[] = "QUADCHO_PAN4";
PROGMEM prog_char EffectType__32__Parameter__18__name[] = "QUADCHO_DEPTH1";
PROGMEM prog_char EffectType__32__Parameter__19__name[] = "QUADCHO_DEPTH2";
PROGMEM prog_char EffectType__32__Parameter__20__name[] = "QUADCHO_DEPTH3";
PROGMEM prog_char EffectType__32__Parameter__21__name[] = "QUADCHO_DEPTH4";
PROGMEM prog_char EffectType__32__Parameter__22__name[] = "QUADCHO_MORPH1";
PROGMEM prog_char EffectType__32__Parameter__23__name[] = "QUADCHO_MORPH2";
PROGMEM prog_char EffectType__32__Parameter__24__name[] = "QUADCHO_MORPH3";
PROGMEM prog_char EffectType__32__Parameter__25__name[] = "QUADCHO_MORPH4";
PROGMEM prog_char EffectType__32__Parameter__26__name[] = "QUADCHO_TYPE1";
PROGMEM prog_char EffectType__32__Parameter__27__name[] = "QUADCHO_TYPE2";
PROGMEM prog_char EffectType__32__Parameter__28__name[] = "QUADCHO_TYPE3";
PROGMEM prog_char EffectType__32__Parameter__29__name[] = "QUADCHO_TYPE4";
PROGMEM prog_char EffectType__32__Parameter__30__name[] = "QUADCHO_RATE1";
PROGMEM prog_char EffectType__32__Parameter__31__name[] = "QUADCHO_RATE2";
PROGMEM prog_char EffectType__32__Parameter__32__name[] = "QUADCHO_RATE3";
PROGMEM prog_char EffectType__32__Parameter__33__name[] = "QUADCHO_RATE4";
PROGMEM prog_char EffectType__32__Parameter__34__name[] = "QUADCHO_MDEPTH";
PROGMEM prog_char EffectType__32__Parameter__35__name[] = "QUADCHO_MODE";
PROGMEM prog_char EffectType__32__Parameter__36__name[] = "QUADCHO_LFOLOCK";
PROGMEM prog_char EffectType__32__Parameter__37__name[] = "QUADCHO_WIDE";
PROGMEM prog_char EffectType__32__Parameter__38__name[] = "QUADCHO_PHASE";
PROGMEM prog_char EffectType__32__Parameter__39__name[] = "QUADCHO_MIX";
PROGMEM prog_char EffectType__32__Parameter__40__name[] = "QUADCHO_LEVEL";
PROGMEM prog_char EffectType__32__Parameter__41__name[] = "QUADCHO_PAN";
PROGMEM prog_char EffectType__32__Parameter__42__name[] = "QUADCHO_BYPASSMODE";
PROGMEM prog_char EffectType__32__Parameter__43__name[] = "QUADCHO_GLOBALMIX";
PROGMEM prog_char EffectType__32__Parameter__44__name[] = "QUADCHO_BYPASS";
PROGMEM prog_char EffectType__32__Parameter__45__name[] = "QUADCHO_HICUT";
PROGMEM prog_char EffectType__33__Parameter__0__name[] = "RESONATOR_MODE";
PROGMEM prog_char EffectType__33__Parameter__1__name[] = "RESONATOR_CHORD";
PROGMEM prog_char EffectType__33__Parameter__2__name[] = "RESONATOR_INGAIN";
PROGMEM prog_char EffectType__33__Parameter__3__name[] = "RESONATOR_FREQ";
PROGMEM prog_char EffectType__33__Parameter__4__name[] = "RESONATOR_MASTERFREQ";
PROGMEM prog_char EffectType__33__Parameter__5__name[] = "RESONATOR_MASTERLVL";
PROGMEM prog_char EffectType__33__Parameter__6__name[] = "RESONATOR_MASTERPAN";
PROGMEM prog_char EffectType__33__Parameter__7__name[] = "RESONATOR_MASTERFDBK";
PROGMEM prog_char EffectType__33__Parameter__8__name[] = "RESONATOR_MASTERQ";
PROGMEM prog_char EffectType__33__Parameter__9__name[] = "RESONATOR_FREQ1";
PROGMEM prog_char EffectType__33__Parameter__10__name[] = "RESONATOR_FREQ2";
PROGMEM prog_char EffectType__33__Parameter__11__name[] = "RESONATOR_FREQ3";
PROGMEM prog_char EffectType__33__Parameter__12__name[] = "RESONATOR_FREQ4";
PROGMEM prog_char EffectType__33__Parameter__13__name[] = "RESONATOR_FDBK1";
PROGMEM prog_char EffectType__33__Parameter__14__name[] = "RESONATOR_FDBK2";
PROGMEM prog_char EffectType__33__Parameter__15__name[] = "RESONATOR_FDBK3";
PROGMEM prog_char EffectType__33__Parameter__16__name[] = "RESONATOR_FDBK4";
PROGMEM prog_char EffectType__33__Parameter__17__name[] = "RESONATOR_LOC1";
PROGMEM prog_char EffectType__33__Parameter__18__name[] = "RESONATOR_LOC2";
PROGMEM prog_char EffectType__33__Parameter__19__name[] = "RESONATOR_LOC3";
PROGMEM prog_char EffectType__33__Parameter__20__name[] = "RESONATOR_LOC4";
PROGMEM prog_char EffectType__33__Parameter__21__name[] = "RESONATOR_Q1";
PROGMEM prog_char EffectType__33__Parameter__22__name[] = "RESONATOR_Q2";
PROGMEM prog_char EffectType__33__Parameter__23__name[] = "RESONATOR_Q3";
PROGMEM prog_char EffectType__33__Parameter__24__name[] = "RESONATOR_Q4";
PROGMEM prog_char EffectType__33__Parameter__25__name[] = "RESONATOR_LEVEL1";
PROGMEM prog_char EffectType__33__Parameter__26__name[] = "RESONATOR_LEVEL2";
PROGMEM prog_char EffectType__33__Parameter__27__name[] = "RESONATOR_LEVEL3";
PROGMEM prog_char EffectType__33__Parameter__28__name[] = "RESONATOR_LEVEL4";
PROGMEM prog_char EffectType__33__Parameter__29__name[] = "RESONATOR_PAN1";
PROGMEM prog_char EffectType__33__Parameter__30__name[] = "RESONATOR_PAN2";
PROGMEM prog_char EffectType__33__Parameter__31__name[] = "RESONATOR_PAN3";
PROGMEM prog_char EffectType__33__Parameter__32__name[] = "RESONATOR_PAN4";
PROGMEM prog_char EffectType__33__Parameter__33__name[] = "RESONATOR_MIX";
PROGMEM prog_char EffectType__33__Parameter__34__name[] = "RESONATOR_LEVEL";
PROGMEM prog_char EffectType__33__Parameter__35__name[] = "RESONATOR_PAN";
PROGMEM prog_char EffectType__33__Parameter__36__name[] = "RESONATOR_BYPASSMODE";
PROGMEM prog_char EffectType__33__Parameter__37__name[] = "RESONATOR_GLOBALMIX";
PROGMEM prog_char EffectType__33__Parameter__38__name[] = "RESONATOR_BYPASS";
PROGMEM prog_char EffectType__33__Parameter__39__name[] = "RESONATOR_INPUTMODE";
PROGMEM prog_char EffectType__34__Parameter__0__name[] = "VOLUME_GAIN";
PROGMEM prog_char EffectType__34__Parameter__1__name[] = "VOLUME_BAL";
PROGMEM prog_char EffectType__34__Parameter__2__name[] = "VOLUME_TAPER";
PROGMEM prog_char EffectType__34__Parameter__3__name[] = "VOLUME_BYPASS";
PROGMEM prog_char EffectType__34__Parameter__4__name[] = "VOLUME_PANL";
PROGMEM prog_char EffectType__34__Parameter__5__name[] = "VOLUME_PANR";
PROGMEM prog_char EffectType__34__Parameter__6__name[] = "VOLUME_LEVEL";
PROGMEM prog_char EffectType__34__Parameter__7__name[] = "VOLUME_BYPASSMODE";
PROGMEM prog_char EffectType__34__Parameter__8__name[] = "VOLUME_INPUTMODE";
PROGMEM prog_char EffectType__35__Parameter__0__name[] = "NOISEGATE_THRESH";
PROGMEM prog_char EffectType__35__Parameter__1__name[] = "NOISEGATE_RATIO";
PROGMEM prog_char EffectType__35__Parameter__2__name[] = "NOISEGATE_RELEASE";
PROGMEM prog_char EffectType__35__Parameter__3__name[] = "NOISEGATE_ATTACK";
PROGMEM prog_char EffectType__35__Parameter__4__name[] = "NOISEGATE_Z";
PROGMEM prog_char EffectType__36__Parameter__0__name[] = "OUTPUT_LEVEL1";
PROGMEM prog_char EffectType__36__Parameter__1__name[] = "OUTPUT_LEVEL2";
PROGMEM prog_char EffectType__36__Parameter__2__name[] = "OUTPUT_LEVEL3";
PROGMEM prog_char EffectType__36__Parameter__3__name[] = "OUTPUT_LEVEL4";
PROGMEM prog_char EffectType__36__Parameter__4__name[] = "OUTPUT_PAN1";
PROGMEM prog_char EffectType__36__Parameter__5__name[] = "OUTPUT_PAN2";
PROGMEM prog_char EffectType__36__Parameter__6__name[] = "OUTPUT_PAN3";
PROGMEM prog_char EffectType__36__Parameter__7__name[] = "OUTPUT_PAN4";
PROGMEM prog_char EffectType__36__Parameter__8__name[] = "OUTPUT_MAIN1";
PROGMEM prog_char EffectType__36__Parameter__9__name[] = "OUTPUT_MAIN2";
PROGMEM prog_char EffectType__36__Parameter__10__name[] = "OUTPUT_MAIN3";
PROGMEM prog_char EffectType__36__Parameter__11__name[] = "OUTPUT_MAIN4";
PROGMEM prog_char EffectType__36__Parameter__12__name[] = "OUTPUT_MAIN5";
PROGMEM prog_char EffectType__36__Parameter__13__name[] = "OUTPUT_MAIN6";
PROGMEM prog_char EffectType__36__Parameter__14__name[] = "OUTPUT_MAIN7";
PROGMEM prog_char EffectType__36__Parameter__15__name[] = "OUTPUT_MAIN8";
PROGMEM prog_char EffectType__36__Parameter__16__name[] = "OUTPUT_LEVEL";
PROGMEM prog_char EffectType__36__Parameter__17__name[] = "OUTPUT_PAN";
PROGMEM prog_char EffectType__36__Parameter__18__name[] = "OUTPUT_BYPASSMODE";
PROGMEM prog_char EffectType__36__Parameter__19__name[] = "OUTPUT_BYPASS";
PROGMEM prog_char EffectType__37__Parameter__0__name[] = "CONTROLLERS_LFO1TYPE";
PROGMEM prog_char EffectType__37__Parameter__1__name[] = "CONTROLLERS_LFO1FREQ";
PROGMEM prog_char EffectType__37__Parameter__2__name[] = "CONTROLLERS_LFO1DEPTH";
PROGMEM prog_char EffectType__37__Parameter__3__name[] = "CONTROLLERS_LFO1DUTY";
PROGMEM prog_char EffectType__37__Parameter__4__name[] = "CONTROLLERS_LFO1PHASE";
PROGMEM prog_char EffectType__37__Parameter__5__name[] = "CONTROLLERS_LFO1TEMPO";
PROGMEM prog_char EffectType__37__Parameter__6__name[] = "CONTROLLERS_LFO2TYPE";
PROGMEM prog_char EffectType__37__Parameter__7__name[] = "CONTROLLERS_LFO2FREQ";
PROGMEM prog_char EffectType__37__Parameter__8__name[] = "CONTROLLERS_LFO2DEPTH";
PROGMEM prog_char EffectType__37__Parameter__9__name[] = "CONTROLLERS_LFO2DUTY";
PROGMEM prog_char EffectType__37__Parameter__10__name[] = "CONTROLLERS_LFO2PHASE";
PROGMEM prog_char EffectType__37__Parameter__11__name[] = "CONTROLLERS_LFO2TEMPO";
PROGMEM prog_char EffectType__37__Parameter__12__name[] = "CONTROLLERS_ADSR1MODE";
PROGMEM prog_char EffectType__37__Parameter__13__name[] = "CONTROLLERS_ADSR1RETRIG";
PROGMEM prog_char EffectType__37__Parameter__14__name[] = "CONTROLLERS_ADSR1ATTACK";
PROGMEM prog_char EffectType__37__Parameter__15__name[] = "CONTROLLERS_ADSR1DECAY";
PROGMEM prog_char EffectType__37__Parameter__16__name[] = "CONTROLLERS_ADSR1SUSTAIN";
PROGMEM prog_char EffectType__37__Parameter__17__name[] = "CONTROLLERS_ADSR1LEVEL";
PROGMEM prog_char EffectType__37__Parameter__18__name[] = "CONTROLLERS_ADSR1RELEASE";
PROGMEM prog_char EffectType__37__Parameter__19__name[] = "CONTROLLERS_ADSR1THRESH";
PROGMEM prog_char EffectType__37__Parameter__20__name[] = "CONTROLLERS_ADSR2MODE";
PROGMEM prog_char EffectType__37__Parameter__21__name[] = "CONTROLLERS_ADSR2RETRIG";
PROGMEM prog_char EffectType__37__Parameter__22__name[] = "CONTROLLERS_ADSR2ATTACK";
PROGMEM prog_char EffectType__37__Parameter__23__name[] = "CONTROLLERS_ADSR2DECAY";
PROGMEM prog_char EffectType__37__Parameter__24__name[] = "CONTROLLERS_ADSR2SUSTAIN";
PROGMEM prog_char EffectType__37__Parameter__25__name[] = "CONTROLLERS_ADSR2LEVEL";
PROGMEM prog_char EffectType__37__Parameter__26__name[] = "CONTROLLERS_ADSR2RELEASE";
PROGMEM prog_char EffectType__37__Parameter__27__name[] = "CONTROLLERS_ADSR2THRESH";
PROGMEM prog_char EffectType__37__Parameter__28__name[] = "CONTROLLERS_ENVATTACK";
PROGMEM prog_char EffectType__37__Parameter__29__name[] = "CONTROLLERS_ENVRELEASE";
PROGMEM prog_char EffectType__37__Parameter__30__name[] = "CONTROLLERS_ENVSENS";
PROGMEM prog_char EffectType__37__Parameter__31__name[] = "CONTROLLERS_ENVGAIN";
PROGMEM prog_char EffectType__37__Parameter__32__name[] = "CONTROLLERS_TEMPO";
PROGMEM prog_char EffectType__37__Parameter__33__name[] = "CONTROLLERS_TEMPOTOUSE";
PROGMEM prog_char EffectType__37__Parameter__34__name[] = "CONTROLLERS_SEQFREQ";
PROGMEM prog_char EffectType__37__Parameter__35__name[] = "CONTROLLERS_SEQTEMPO";
PROGMEM prog_char EffectType__37__Parameter__36__name[] = "CONTROLLERS_SEQSTAGES";
PROGMEM prog_char EffectType__37__Parameter__37__name[] = "CONTROLLERS_SEQ1";
PROGMEM prog_char EffectType__37__Parameter__38__name[] = "CONTROLLERS_SEQ2";
PROGMEM prog_char EffectType__37__Parameter__39__name[] = "CONTROLLERS_SEQ3";
PROGMEM prog_char EffectType__37__Parameter__40__name[] = "CONTROLLERS_SEQ4";
PROGMEM prog_char EffectType__37__Parameter__41__name[] = "CONTROLLERS_SEQ5";
PROGMEM prog_char EffectType__37__Parameter__42__name[] = "CONTROLLERS_SEQ6";
PROGMEM prog_char EffectType__37__Parameter__43__name[] = "CONTROLLERS_SEQ7";
PROGMEM prog_char EffectType__37__Parameter__44__name[] = "CONTROLLERS_SEQ8";
PROGMEM prog_char EffectType__37__Parameter__45__name[] = "CONTROLLERS_SEQ9";
PROGMEM prog_char EffectType__37__Parameter__46__name[] = "CONTROLLERS_SEQ10";
PROGMEM prog_char EffectType__37__Parameter__47__name[] = "CONTROLLERS_SEQ11";
PROGMEM prog_char EffectType__37__Parameter__48__name[] = "CONTROLLERS_SEQ12";
PROGMEM prog_char EffectType__37__Parameter__49__name[] = "CONTROLLERS_SEQ13";
PROGMEM prog_char EffectType__37__Parameter__50__name[] = "CONTROLLERS_SEQ14";
PROGMEM prog_char EffectType__37__Parameter__51__name[] = "CONTROLLERS_SEQ15";
PROGMEM prog_char EffectType__37__Parameter__52__name[] = "CONTROLLERS_SEQ16";
PROGMEM prog_char EffectType__37__Parameter__53__name[] = "CONTROLLERS_AUTODELAY";
PROGMEM prog_char EffectType__37__Parameter__54__name[] = "CONTROLLERS_SEQRUN";
PROGMEM prog_char EffectType__37__Parameter__55__name[] = "CONTROLLERS_KNOBA";
PROGMEM prog_char EffectType__37__Parameter__56__name[] = "CONTROLLERS_KNOBB";
PROGMEM prog_char EffectType__37__Parameter__57__name[] = "CONTROLLERS_KNOBC";
PROGMEM prog_char EffectType__37__Parameter__58__name[] = "CONTROLLERS_KNOBD";
PROGMEM prog_char EffectType__37__Parameter__59__name[] = "CONTROLLERS_SEQ17";
PROGMEM prog_char EffectType__37__Parameter__60__name[] = "CONTROLLERS_SEQ18";
PROGMEM prog_char EffectType__37__Parameter__61__name[] = "CONTROLLERS_SEQ19";
PROGMEM prog_char EffectType__37__Parameter__62__name[] = "CONTROLLERS_SEQ20";
PROGMEM prog_char EffectType__37__Parameter__63__name[] = "CONTROLLERS_SEQ21";
PROGMEM prog_char EffectType__37__Parameter__64__name[] = "CONTROLLERS_SEQ22";
PROGMEM prog_char EffectType__37__Parameter__65__name[] = "CONTROLLERS_SEQ23";
PROGMEM prog_char EffectType__37__Parameter__66__name[] = "CONTROLLERS_SEQ24";
PROGMEM prog_char EffectType__37__Parameter__67__name[] = "CONTROLLERS_SEQ25";
PROGMEM prog_char EffectType__37__Parameter__68__name[] = "CONTROLLERS_SEQ26";
PROGMEM prog_char EffectType__37__Parameter__69__name[] = "CONTROLLERS_SEQ27";
PROGMEM prog_char EffectType__37__Parameter__70__name[] = "CONTROLLERS_SEQ28";
PROGMEM prog_char EffectType__37__Parameter__71__name[] = "CONTROLLERS_SEQ29";
PROGMEM prog_char EffectType__37__Parameter__72__name[] = "CONTROLLERS_SEQ30";
PROGMEM prog_char EffectType__37__Parameter__73__name[] = "CONTROLLERS_SEQ31";
PROGMEM prog_char EffectType__37__Parameter__74__name[] = "CONTROLLERS_SEQ32";
PROGMEM prog_char EffectType__37__Parameter__75__name[] = "CONTROLLERS_LFO1RUNCTRL";
PROGMEM prog_char EffectType__37__Parameter__76__name[] = "CONTROLLERS_LFO2RUNCTRL";
PROGMEM prog_char EffectType__37__Parameter__77__name[] = "CONTROLLERS_SEQRUNCTRL";
PROGMEM prog_char EffectType__38__Parameter__0__name[] = "LOOPER_MIX";
PROGMEM prog_char EffectType__38__Parameter__1__name[] = "LOOPER_LEVEL";
PROGMEM prog_char EffectType__38__Parameter__2__name[] = "LOOPER_PAN";
PROGMEM prog_char EffectType__38__Parameter__3__name[] = "LOOPER_BYPASSMODE";
PROGMEM prog_char EffectType__38__Parameter__4__name[] = "LOOPER_BYPASS";
PROGMEM prog_char EffectType__38__Parameter__5__name[] = "LOOPER_DUB_MIX";
PROGMEM prog_char EffectType__38__Parameter__6__name[] = "LOOPER_THRESH";
PROGMEM prog_char EffectType__38__Parameter__7__name[] = "LOOPER_THRESH_LEVEL";
PROGMEM prog_char EffectType__38__Parameter__8__name[] = "LOOPER_MODE";
PROGMEM prog_char EffectType__38__Parameter__9__name[] = "LOOPER_QUANTIZE";
PROGMEM prog_char EffectType__38__Parameter__10__name[] = "LOOPER_STOP";
PROGMEM prog_char EffectType__38__Parameter__11__name[] = "LOOPER_START";
PROGMEM prog_char EffectType__38__Parameter__12__name[] = "LOOPER_PLAYIMMEDIATE";
PROGMEM prog_char EffectType__39__Parameter__0__name[] = "EQMATCH_RUN";
PROGMEM prog_char EffectType__39__Parameter__1__name[] = "EQMATCH_AMOUNT";
PROGMEM prog_char EffectType__39__Parameter__2__name[] = "EQMATCH_SMOOTHING";
PROGMEM prog_char EffectType__39__Parameter__3__name[] = "EQMATCH_CAPTUREREF";
PROGMEM prog_char EffectType__39__Parameter__4__name[] = "EQMATCH_CAPTUREUSER";
PROGMEM prog_char EffectType__39__Parameter__5__name[] = "EQMATCH_MATCH";
PROGMEM prog_char EffectType__39__Parameter__6__name[] = "EQMATCH_LEVEL";
PROGMEM prog_char EffectType__39__Parameter__7__name[] = "EQMATCH_PAN";
PROGMEM prog_char EffectType__39__Parameter__8__name[] = "EQMATCH_BYPASSMODE";
PROGMEM prog_char EffectType__39__Parameter__9__name[] = "EQMATCH_BYPASS";
PROGMEM prog_char EffectType__39__Parameter__10__name[] = "EQMATCH_SOURCE";
PROGMEM prog_char EffectType__39__Parameter__11__name[] = "EQMATCH_TIME";
PROGMEM prog_char EffectType__39__Parameter__12__name[] = "EQMATCH_REFCHAN";
PROGMEM prog_char EffectType__39__Parameter__13__name[] = "EQMATCH_LOCALCHAN";
PROGMEM prog_char EffectType__39__Parameter__14__name[] = "EQMATCH_REFSOLO";
PROGMEM prog_char EffectType__39__Parameter__15__name[] = "EQMATCH_RESOLUTION";
PROGMEM prog_char EffectType__39__Parameter__16__name[] = "EQMATCH_TAPER";
PROGMEM prog_char EffectType__39__Parameter__17__name[] = "EQMATCH_ACCUMULATE";
PROGMEM prog_char EffectType__39__Parameter__18__name[] = "EQMATCH_NORM1";
PROGMEM prog_char EffectType__39__Parameter__19__name[] = "EQMATCH_NORM2";
PROGMEM prog_char EffectType__39__Parameter__20__name[] = "EQMATCH_LFMATCH";


PROGMEM char *Parameter__name[1100] = { EffectType__2__Parameter__0__name, EffectType__2__Parameter__1__name, EffectType__2__Parameter__2__name, EffectType__2__Parameter__3__name, EffectType__2__Parameter__4__name, EffectType__2__Parameter__5__name, EffectType__2__Parameter__6__name, EffectType__2__Parameter__7__name, EffectType__2__Parameter__8__name, EffectType__2__Parameter__9__name, EffectType__2__Parameter__10__name, EffectType__2__Parameter__11__name, EffectType__2__Parameter__12__name, EffectType__2__Parameter__13__name, EffectType__2__Parameter__14__name, EffectType__2__Parameter__15__name, EffectType__2__Parameter__16__name, EffectType__2__Parameter__17__name, 
EffectType__3__Parameter__0__name, EffectType__3__Parameter__1__name, EffectType__3__Parameter__2__name, EffectType__3__Parameter__3__name, EffectType__3__Parameter__4__name, EffectType__3__Parameter__5__name, EffectType__3__Parameter__6__name, EffectType__3__Parameter__7__name, EffectType__3__Parameter__8__name, EffectType__3__Parameter__9__name, EffectType__3__Parameter__10__name, EffectType__3__Parameter__11__name, EffectType__3__Parameter__12__name, EffectType__3__Parameter__13__name, EffectType__3__Parameter__14__name, EffectType__3__Parameter__15__name, EffectType__3__Parameter__16__name, EffectType__3__Parameter__17__name, EffectType__3__Parameter__18__name, 
EffectType__4__Parameter__0__name, EffectType__4__Parameter__1__name, EffectType__4__Parameter__2__name, EffectType__4__Parameter__3__name, EffectType__4__Parameter__4__name, EffectType__4__Parameter__5__name, EffectType__4__Parameter__6__name, EffectType__4__Parameter__7__name, EffectType__4__Parameter__8__name, EffectType__4__Parameter__9__name, EffectType__4__Parameter__10__name, EffectType__4__Parameter__11__name, EffectType__4__Parameter__12__name, EffectType__4__Parameter__13__name, EffectType__4__Parameter__14__name, EffectType__4__Parameter__15__name, EffectType__4__Parameter__16__name, EffectType__4__Parameter__17__name, EffectType__4__Parameter__18__name, EffectType__4__Parameter__19__name, EffectType__4__Parameter__20__name, EffectType__4__Parameter__21__name, EffectType__4__Parameter__22__name, EffectType__4__Parameter__23__name, 
EffectType__5__Parameter__0__name, EffectType__5__Parameter__1__name, EffectType__5__Parameter__2__name, EffectType__5__Parameter__3__name, EffectType__5__Parameter__4__name, EffectType__5__Parameter__5__name, EffectType__5__Parameter__6__name, EffectType__5__Parameter__7__name, EffectType__5__Parameter__8__name, EffectType__5__Parameter__9__name, EffectType__5__Parameter__10__name, EffectType__5__Parameter__11__name, EffectType__5__Parameter__12__name, EffectType__5__Parameter__13__name, EffectType__5__Parameter__14__name, EffectType__5__Parameter__15__name, EffectType__5__Parameter__16__name, EffectType__5__Parameter__17__name, EffectType__5__Parameter__18__name, EffectType__5__Parameter__19__name, EffectType__5__Parameter__20__name, EffectType__5__Parameter__21__name, EffectType__5__Parameter__22__name, EffectType__5__Parameter__23__name, EffectType__5__Parameter__24__name, EffectType__5__Parameter__25__name, EffectType__5__Parameter__26__name, EffectType__5__Parameter__27__name, EffectType__5__Parameter__28__name, EffectType__5__Parameter__29__name, EffectType__5__Parameter__30__name, EffectType__5__Parameter__31__name, EffectType__5__Parameter__32__name, EffectType__5__Parameter__33__name, EffectType__5__Parameter__34__name, EffectType__5__Parameter__35__name, EffectType__5__Parameter__36__name, EffectType__5__Parameter__37__name, EffectType__5__Parameter__38__name, EffectType__5__Parameter__39__name, EffectType__5__Parameter__40__name, EffectType__5__Parameter__41__name, EffectType__5__Parameter__42__name, EffectType__5__Parameter__43__name, EffectType__5__Parameter__44__name, EffectType__5__Parameter__45__name, EffectType__5__Parameter__46__name, EffectType__5__Parameter__47__name, EffectType__5__Parameter__48__name, EffectType__5__Parameter__49__name, EffectType__5__Parameter__50__name, EffectType__5__Parameter__51__name, EffectType__5__Parameter__52__name, EffectType__5__Parameter__53__name, EffectType__5__Parameter__54__name, EffectType__5__Parameter__55__name, EffectType__5__Parameter__56__name, EffectType__5__Parameter__57__name, EffectType__5__Parameter__58__name, EffectType__5__Parameter__59__name, EffectType__5__Parameter__60__name, EffectType__5__Parameter__61__name, EffectType__5__Parameter__62__name, EffectType__5__Parameter__63__name, EffectType__5__Parameter__64__name, EffectType__5__Parameter__65__name, EffectType__5__Parameter__66__name, EffectType__5__Parameter__67__name, EffectType__5__Parameter__68__name, EffectType__5__Parameter__69__name, EffectType__5__Parameter__70__name, EffectType__5__Parameter__71__name, EffectType__5__Parameter__72__name, EffectType__5__Parameter__73__name, EffectType__5__Parameter__74__name, EffectType__5__Parameter__75__name, EffectType__5__Parameter__76__name, EffectType__5__Parameter__77__name, EffectType__5__Parameter__78__name, EffectType__5__Parameter__79__name, EffectType__5__Parameter__80__name, EffectType__5__Parameter__81__name, EffectType__5__Parameter__82__name, EffectType__5__Parameter__83__name, EffectType__5__Parameter__84__name, EffectType__5__Parameter__85__name, EffectType__5__Parameter__86__name, EffectType__5__Parameter__87__name, EffectType__5__Parameter__88__name, EffectType__5__Parameter__89__name, EffectType__5__Parameter__90__name, 
EffectType__6__Parameter__0__name, EffectType__6__Parameter__1__name, EffectType__6__Parameter__2__name, EffectType__6__Parameter__3__name, EffectType__6__Parameter__4__name, EffectType__6__Parameter__5__name, EffectType__6__Parameter__6__name, EffectType__6__Parameter__7__name, EffectType__6__Parameter__8__name, EffectType__6__Parameter__9__name, EffectType__6__Parameter__10__name, EffectType__6__Parameter__11__name, EffectType__6__Parameter__12__name, EffectType__6__Parameter__13__name, EffectType__6__Parameter__14__name, EffectType__6__Parameter__15__name, EffectType__6__Parameter__16__name, EffectType__6__Parameter__17__name, EffectType__6__Parameter__18__name, EffectType__6__Parameter__19__name, EffectType__6__Parameter__20__name, EffectType__6__Parameter__21__name, EffectType__6__Parameter__22__name, EffectType__6__Parameter__23__name, EffectType__6__Parameter__24__name, EffectType__6__Parameter__25__name, EffectType__6__Parameter__26__name, EffectType__6__Parameter__27__name, EffectType__6__Parameter__28__name, 
EffectType__7__Parameter__0__name, EffectType__7__Parameter__1__name, EffectType__7__Parameter__2__name, EffectType__7__Parameter__3__name, EffectType__7__Parameter__4__name, EffectType__7__Parameter__5__name, EffectType__7__Parameter__6__name, EffectType__7__Parameter__7__name, EffectType__7__Parameter__8__name, EffectType__7__Parameter__9__name, EffectType__7__Parameter__10__name, EffectType__7__Parameter__11__name, EffectType__7__Parameter__12__name, EffectType__7__Parameter__13__name, EffectType__7__Parameter__14__name, EffectType__7__Parameter__15__name, EffectType__7__Parameter__16__name, EffectType__7__Parameter__17__name, EffectType__7__Parameter__18__name, EffectType__7__Parameter__19__name, EffectType__7__Parameter__20__name, EffectType__7__Parameter__21__name, EffectType__7__Parameter__22__name, EffectType__7__Parameter__23__name, EffectType__7__Parameter__24__name, EffectType__7__Parameter__25__name, EffectType__7__Parameter__26__name, EffectType__7__Parameter__27__name, EffectType__7__Parameter__28__name, EffectType__7__Parameter__29__name, EffectType__7__Parameter__30__name, EffectType__7__Parameter__31__name, EffectType__7__Parameter__32__name, EffectType__7__Parameter__33__name, EffectType__7__Parameter__34__name, 
EffectType__8__Parameter__0__name, EffectType__8__Parameter__1__name, EffectType__8__Parameter__2__name, EffectType__8__Parameter__3__name, EffectType__8__Parameter__4__name, EffectType__8__Parameter__5__name, EffectType__8__Parameter__6__name, EffectType__8__Parameter__7__name, EffectType__8__Parameter__8__name, EffectType__8__Parameter__9__name, EffectType__8__Parameter__10__name, EffectType__8__Parameter__11__name, EffectType__8__Parameter__12__name, EffectType__8__Parameter__13__name, EffectType__8__Parameter__14__name, EffectType__8__Parameter__15__name, EffectType__8__Parameter__16__name, EffectType__8__Parameter__17__name, EffectType__8__Parameter__18__name, EffectType__8__Parameter__19__name, EffectType__8__Parameter__20__name, EffectType__8__Parameter__21__name, EffectType__8__Parameter__22__name, EffectType__8__Parameter__23__name, EffectType__8__Parameter__24__name, EffectType__8__Parameter__25__name, EffectType__8__Parameter__26__name, EffectType__8__Parameter__27__name, EffectType__8__Parameter__28__name, EffectType__8__Parameter__29__name, EffectType__8__Parameter__30__name, EffectType__8__Parameter__31__name, EffectType__8__Parameter__32__name, EffectType__8__Parameter__33__name, EffectType__8__Parameter__34__name, EffectType__8__Parameter__35__name, EffectType__8__Parameter__36__name, EffectType__8__Parameter__37__name, EffectType__8__Parameter__38__name, EffectType__8__Parameter__39__name, EffectType__8__Parameter__40__name, EffectType__8__Parameter__41__name, EffectType__8__Parameter__42__name, EffectType__8__Parameter__43__name, EffectType__8__Parameter__44__name, EffectType__8__Parameter__45__name, EffectType__8__Parameter__46__name, EffectType__8__Parameter__47__name, EffectType__8__Parameter__48__name, EffectType__8__Parameter__49__name, EffectType__8__Parameter__50__name, EffectType__8__Parameter__51__name, EffectType__8__Parameter__52__name, EffectType__8__Parameter__53__name, EffectType__8__Parameter__54__name, EffectType__8__Parameter__55__name, EffectType__8__Parameter__56__name, EffectType__8__Parameter__57__name, EffectType__8__Parameter__58__name, EffectType__8__Parameter__59__name, EffectType__8__Parameter__60__name, EffectType__8__Parameter__61__name, EffectType__8__Parameter__62__name, EffectType__8__Parameter__63__name, EffectType__8__Parameter__64__name, EffectType__8__Parameter__65__name, EffectType__8__Parameter__66__name, EffectType__8__Parameter__67__name, EffectType__8__Parameter__68__name, EffectType__8__Parameter__69__name, 
EffectType__9__Parameter__0__name, EffectType__9__Parameter__1__name, EffectType__9__Parameter__2__name, EffectType__9__Parameter__3__name, EffectType__9__Parameter__4__name, EffectType__9__Parameter__5__name, EffectType__9__Parameter__6__name, EffectType__9__Parameter__7__name, EffectType__9__Parameter__8__name, EffectType__9__Parameter__9__name, EffectType__9__Parameter__10__name, EffectType__9__Parameter__11__name, EffectType__9__Parameter__12__name, EffectType__9__Parameter__13__name, EffectType__9__Parameter__14__name, EffectType__9__Parameter__15__name, EffectType__9__Parameter__16__name, EffectType__9__Parameter__17__name, EffectType__9__Parameter__18__name, EffectType__9__Parameter__19__name, EffectType__9__Parameter__20__name, EffectType__9__Parameter__21__name, EffectType__9__Parameter__22__name, EffectType__9__Parameter__23__name, EffectType__9__Parameter__24__name, EffectType__9__Parameter__25__name, EffectType__9__Parameter__26__name, EffectType__9__Parameter__27__name, EffectType__9__Parameter__28__name, EffectType__9__Parameter__29__name, EffectType__9__Parameter__30__name, EffectType__9__Parameter__31__name, EffectType__9__Parameter__32__name, EffectType__9__Parameter__33__name, EffectType__9__Parameter__34__name, EffectType__9__Parameter__35__name, EffectType__9__Parameter__36__name, EffectType__9__Parameter__37__name, EffectType__9__Parameter__38__name, EffectType__9__Parameter__39__name, EffectType__9__Parameter__40__name, EffectType__9__Parameter__41__name, EffectType__9__Parameter__42__name, EffectType__9__Parameter__43__name, EffectType__9__Parameter__44__name, EffectType__9__Parameter__45__name, EffectType__9__Parameter__46__name, EffectType__9__Parameter__47__name, EffectType__9__Parameter__48__name, EffectType__9__Parameter__49__name, EffectType__9__Parameter__50__name, EffectType__9__Parameter__51__name, EffectType__9__Parameter__52__name, EffectType__9__Parameter__53__name, EffectType__9__Parameter__54__name, EffectType__9__Parameter__55__name, EffectType__9__Parameter__56__name, EffectType__9__Parameter__57__name, EffectType__9__Parameter__58__name, EffectType__9__Parameter__59__name, EffectType__9__Parameter__60__name, EffectType__9__Parameter__61__name, EffectType__9__Parameter__62__name, EffectType__9__Parameter__63__name, EffectType__9__Parameter__64__name, EffectType__9__Parameter__65__name, EffectType__9__Parameter__66__name, EffectType__9__Parameter__67__name, EffectType__9__Parameter__68__name, EffectType__9__Parameter__69__name, EffectType__9__Parameter__70__name, EffectType__9__Parameter__71__name, EffectType__9__Parameter__72__name, EffectType__9__Parameter__73__name, EffectType__9__Parameter__74__name, EffectType__9__Parameter__75__name, EffectType__9__Parameter__76__name, EffectType__9__Parameter__77__name, EffectType__9__Parameter__78__name, EffectType__9__Parameter__79__name, EffectType__9__Parameter__80__name, EffectType__9__Parameter__81__name, EffectType__9__Parameter__82__name, EffectType__9__Parameter__83__name, EffectType__9__Parameter__84__name, EffectType__9__Parameter__85__name, EffectType__9__Parameter__86__name, EffectType__9__Parameter__87__name, EffectType__9__Parameter__88__name, EffectType__9__Parameter__89__name, EffectType__9__Parameter__90__name, EffectType__9__Parameter__91__name, EffectType__9__Parameter__92__name, EffectType__9__Parameter__93__name, EffectType__9__Parameter__94__name, EffectType__9__Parameter__95__name, EffectType__9__Parameter__96__name, EffectType__9__Parameter__97__name, EffectType__9__Parameter__98__name, EffectType__9__Parameter__99__name, EffectType__9__Parameter__100__name, EffectType__9__Parameter__101__name, EffectType__9__Parameter__102__name, EffectType__9__Parameter__103__name, EffectType__9__Parameter__104__name, EffectType__9__Parameter__105__name, EffectType__9__Parameter__106__name, EffectType__9__Parameter__107__name, EffectType__9__Parameter__108__name, EffectType__9__Parameter__109__name, EffectType__9__Parameter__110__name, EffectType__9__Parameter__111__name, EffectType__9__Parameter__112__name, EffectType__9__Parameter__113__name, EffectType__9__Parameter__114__name, EffectType__9__Parameter__115__name, EffectType__9__Parameter__116__name, 
EffectType__10__Parameter__0__name, EffectType__10__Parameter__1__name, EffectType__10__Parameter__2__name, EffectType__10__Parameter__3__name, EffectType__10__Parameter__4__name, EffectType__10__Parameter__5__name, EffectType__10__Parameter__6__name, EffectType__10__Parameter__7__name, EffectType__10__Parameter__8__name, EffectType__10__Parameter__9__name, EffectType__10__Parameter__10__name, EffectType__10__Parameter__11__name, EffectType__10__Parameter__12__name, EffectType__10__Parameter__13__name, EffectType__10__Parameter__14__name, EffectType__10__Parameter__15__name, EffectType__10__Parameter__16__name, EffectType__10__Parameter__17__name, EffectType__10__Parameter__18__name, EffectType__10__Parameter__19__name, EffectType__10__Parameter__20__name, EffectType__10__Parameter__21__name, EffectType__10__Parameter__22__name, 
EffectType__11__Parameter__0__name, EffectType__11__Parameter__1__name, EffectType__11__Parameter__2__name, EffectType__11__Parameter__3__name, EffectType__11__Parameter__4__name, EffectType__11__Parameter__5__name, EffectType__11__Parameter__6__name, EffectType__11__Parameter__7__name, EffectType__11__Parameter__8__name, EffectType__11__Parameter__9__name, EffectType__11__Parameter__10__name, EffectType__11__Parameter__11__name, EffectType__11__Parameter__12__name, EffectType__11__Parameter__13__name, EffectType__11__Parameter__14__name, EffectType__11__Parameter__15__name, EffectType__11__Parameter__16__name, EffectType__11__Parameter__17__name, EffectType__11__Parameter__18__name, EffectType__11__Parameter__19__name, EffectType__11__Parameter__20__name, EffectType__11__Parameter__21__name, EffectType__11__Parameter__22__name, 
EffectType__12__Parameter__0__name, EffectType__12__Parameter__1__name, EffectType__12__Parameter__2__name, EffectType__12__Parameter__3__name, EffectType__12__Parameter__4__name, EffectType__12__Parameter__5__name, EffectType__12__Parameter__6__name, EffectType__12__Parameter__7__name, EffectType__12__Parameter__8__name, EffectType__12__Parameter__9__name, EffectType__12__Parameter__10__name, EffectType__12__Parameter__11__name, EffectType__12__Parameter__12__name, EffectType__12__Parameter__13__name, EffectType__12__Parameter__14__name, EffectType__12__Parameter__15__name, EffectType__12__Parameter__16__name, EffectType__12__Parameter__17__name, 
EffectType__13__Parameter__0__name, EffectType__13__Parameter__1__name, EffectType__13__Parameter__2__name, EffectType__13__Parameter__3__name, EffectType__13__Parameter__4__name, EffectType__13__Parameter__5__name, EffectType__13__Parameter__6__name, EffectType__13__Parameter__7__name, EffectType__13__Parameter__8__name, EffectType__13__Parameter__9__name, EffectType__13__Parameter__10__name, EffectType__13__Parameter__11__name, EffectType__13__Parameter__12__name, EffectType__13__Parameter__13__name, EffectType__13__Parameter__14__name, EffectType__13__Parameter__15__name, EffectType__13__Parameter__16__name, EffectType__13__Parameter__17__name, EffectType__13__Parameter__18__name, EffectType__13__Parameter__19__name, 
EffectType__14__Parameter__0__name, EffectType__14__Parameter__1__name, EffectType__14__Parameter__2__name, EffectType__14__Parameter__3__name, EffectType__14__Parameter__4__name, EffectType__14__Parameter__5__name, EffectType__14__Parameter__6__name, EffectType__14__Parameter__7__name, EffectType__14__Parameter__8__name, EffectType__14__Parameter__9__name, EffectType__14__Parameter__10__name, EffectType__14__Parameter__11__name, EffectType__14__Parameter__12__name, 
EffectType__15__Parameter__0__name, EffectType__15__Parameter__1__name, EffectType__15__Parameter__2__name, EffectType__15__Parameter__3__name, EffectType__15__Parameter__4__name, EffectType__15__Parameter__5__name, EffectType__15__Parameter__6__name, EffectType__15__Parameter__7__name, EffectType__15__Parameter__8__name, EffectType__15__Parameter__9__name, EffectType__15__Parameter__10__name, EffectType__15__Parameter__11__name, 
EffectType__16__Parameter__0__name, EffectType__16__Parameter__1__name, EffectType__16__Parameter__2__name, EffectType__16__Parameter__3__name, EffectType__16__Parameter__4__name, EffectType__16__Parameter__5__name, EffectType__16__Parameter__6__name, EffectType__16__Parameter__7__name, EffectType__16__Parameter__8__name, EffectType__16__Parameter__9__name, EffectType__16__Parameter__10__name, EffectType__16__Parameter__11__name, EffectType__16__Parameter__12__name, EffectType__16__Parameter__13__name, EffectType__16__Parameter__14__name, 
EffectType__17__Parameter__0__name, EffectType__17__Parameter__1__name, EffectType__17__Parameter__2__name, EffectType__17__Parameter__3__name, EffectType__17__Parameter__4__name, EffectType__17__Parameter__5__name, EffectType__17__Parameter__6__name, EffectType__17__Parameter__7__name, EffectType__17__Parameter__8__name, EffectType__17__Parameter__9__name, EffectType__17__Parameter__10__name, EffectType__17__Parameter__11__name, EffectType__17__Parameter__12__name, EffectType__17__Parameter__13__name, EffectType__17__Parameter__14__name, EffectType__17__Parameter__15__name, EffectType__17__Parameter__16__name, EffectType__17__Parameter__17__name, EffectType__17__Parameter__18__name, EffectType__17__Parameter__19__name, EffectType__17__Parameter__20__name, EffectType__17__Parameter__21__name, EffectType__17__Parameter__22__name, EffectType__17__Parameter__23__name, EffectType__17__Parameter__24__name, EffectType__17__Parameter__25__name, EffectType__17__Parameter__26__name, EffectType__17__Parameter__27__name, EffectType__17__Parameter__28__name, EffectType__17__Parameter__29__name, EffectType__17__Parameter__30__name, EffectType__17__Parameter__31__name, EffectType__17__Parameter__32__name, EffectType__17__Parameter__33__name, EffectType__17__Parameter__34__name, EffectType__17__Parameter__35__name, EffectType__17__Parameter__36__name, EffectType__17__Parameter__37__name, EffectType__17__Parameter__38__name, EffectType__17__Parameter__39__name, EffectType__17__Parameter__40__name, EffectType__17__Parameter__41__name, EffectType__17__Parameter__42__name, EffectType__17__Parameter__43__name, EffectType__17__Parameter__44__name, EffectType__17__Parameter__45__name, EffectType__17__Parameter__46__name, EffectType__17__Parameter__47__name, EffectType__17__Parameter__48__name, EffectType__17__Parameter__49__name, EffectType__17__Parameter__50__name, EffectType__17__Parameter__51__name, EffectType__17__Parameter__52__name, EffectType__17__Parameter__53__name, EffectType__17__Parameter__54__name, EffectType__17__Parameter__55__name, EffectType__17__Parameter__56__name, EffectType__17__Parameter__57__name, EffectType__17__Parameter__58__name, EffectType__17__Parameter__59__name, EffectType__17__Parameter__60__name, EffectType__17__Parameter__61__name, EffectType__17__Parameter__62__name, EffectType__17__Parameter__63__name, EffectType__17__Parameter__64__name, EffectType__17__Parameter__65__name, EffectType__17__Parameter__66__name, EffectType__17__Parameter__67__name, EffectType__17__Parameter__68__name, EffectType__17__Parameter__69__name, EffectType__17__Parameter__70__name, EffectType__17__Parameter__71__name, EffectType__17__Parameter__72__name, EffectType__17__Parameter__73__name, EffectType__17__Parameter__74__name, EffectType__17__Parameter__75__name, EffectType__17__Parameter__76__name, EffectType__17__Parameter__77__name, EffectType__17__Parameter__78__name, EffectType__17__Parameter__79__name, EffectType__17__Parameter__80__name, EffectType__17__Parameter__81__name, EffectType__17__Parameter__82__name, EffectType__17__Parameter__83__name, EffectType__17__Parameter__84__name, 
EffectType__18__Parameter__0__name, EffectType__18__Parameter__1__name, EffectType__18__Parameter__2__name, EffectType__18__Parameter__3__name, EffectType__18__Parameter__4__name, EffectType__18__Parameter__5__name, EffectType__18__Parameter__6__name, EffectType__18__Parameter__7__name, EffectType__18__Parameter__8__name, EffectType__18__Parameter__9__name, EffectType__18__Parameter__10__name, EffectType__18__Parameter__11__name, EffectType__18__Parameter__12__name, EffectType__18__Parameter__13__name, 
EffectType__19__Parameter__0__name, EffectType__19__Parameter__1__name, EffectType__19__Parameter__2__name, EffectType__19__Parameter__3__name, EffectType__19__Parameter__4__name, EffectType__19__Parameter__5__name, EffectType__19__Parameter__6__name, EffectType__19__Parameter__7__name, EffectType__19__Parameter__8__name, EffectType__19__Parameter__9__name, EffectType__19__Parameter__10__name, EffectType__19__Parameter__11__name, EffectType__19__Parameter__12__name, EffectType__19__Parameter__13__name, EffectType__19__Parameter__14__name, EffectType__19__Parameter__15__name, EffectType__19__Parameter__16__name, EffectType__19__Parameter__17__name, EffectType__19__Parameter__18__name, EffectType__19__Parameter__19__name, 
EffectType__20__Parameter__0__name, EffectType__20__Parameter__1__name, EffectType__20__Parameter__2__name, EffectType__20__Parameter__3__name, EffectType__20__Parameter__4__name, EffectType__20__Parameter__5__name, EffectType__20__Parameter__6__name, EffectType__20__Parameter__7__name, EffectType__20__Parameter__8__name, EffectType__20__Parameter__9__name, EffectType__20__Parameter__10__name, 
EffectType__21__Parameter__0__name, EffectType__21__Parameter__1__name, EffectType__21__Parameter__2__name, EffectType__21__Parameter__3__name, EffectType__21__Parameter__4__name, EffectType__21__Parameter__5__name, EffectType__21__Parameter__6__name, EffectType__21__Parameter__7__name, EffectType__21__Parameter__8__name, EffectType__21__Parameter__9__name, EffectType__21__Parameter__10__name, EffectType__21__Parameter__11__name, EffectType__21__Parameter__12__name, EffectType__21__Parameter__13__name, EffectType__21__Parameter__14__name, EffectType__21__Parameter__15__name, EffectType__21__Parameter__16__name, EffectType__21__Parameter__17__name, EffectType__21__Parameter__18__name, EffectType__21__Parameter__19__name, 
EffectType__22__Parameter__0__name, EffectType__22__Parameter__1__name, EffectType__22__Parameter__2__name, EffectType__22__Parameter__3__name, EffectType__22__Parameter__4__name, EffectType__22__Parameter__5__name, EffectType__22__Parameter__6__name, EffectType__22__Parameter__7__name, EffectType__22__Parameter__8__name, EffectType__22__Parameter__9__name, 
EffectType__23__Parameter__0__name, EffectType__23__Parameter__1__name, 
EffectType__24__Parameter__0__name, EffectType__24__Parameter__1__name, EffectType__24__Parameter__2__name, EffectType__24__Parameter__3__name, EffectType__24__Parameter__4__name, EffectType__24__Parameter__5__name, 
EffectType__25__Parameter__0__name, EffectType__25__Parameter__1__name, EffectType__25__Parameter__2__name, EffectType__25__Parameter__3__name, EffectType__25__Parameter__4__name, EffectType__25__Parameter__5__name, EffectType__25__Parameter__6__name, EffectType__25__Parameter__7__name, EffectType__25__Parameter__8__name, EffectType__25__Parameter__9__name, EffectType__25__Parameter__10__name, EffectType__25__Parameter__11__name, EffectType__25__Parameter__12__name, EffectType__25__Parameter__13__name, EffectType__25__Parameter__14__name, EffectType__25__Parameter__15__name, EffectType__25__Parameter__16__name, EffectType__25__Parameter__17__name, EffectType__25__Parameter__18__name, EffectType__25__Parameter__19__name, EffectType__25__Parameter__20__name, EffectType__25__Parameter__21__name, EffectType__25__Parameter__22__name, EffectType__25__Parameter__23__name, EffectType__25__Parameter__24__name, EffectType__25__Parameter__25__name, EffectType__25__Parameter__26__name, EffectType__25__Parameter__27__name, EffectType__25__Parameter__28__name, EffectType__25__Parameter__29__name, EffectType__25__Parameter__30__name, EffectType__25__Parameter__31__name, EffectType__25__Parameter__32__name, EffectType__25__Parameter__33__name, EffectType__25__Parameter__34__name, EffectType__25__Parameter__35__name, EffectType__25__Parameter__36__name, EffectType__25__Parameter__37__name, EffectType__25__Parameter__38__name, EffectType__25__Parameter__39__name, 
EffectType__26__Parameter__0__name, EffectType__26__Parameter__1__name, EffectType__26__Parameter__2__name, EffectType__26__Parameter__3__name, EffectType__26__Parameter__4__name, EffectType__26__Parameter__5__name, EffectType__26__Parameter__6__name, EffectType__26__Parameter__7__name, EffectType__26__Parameter__8__name, EffectType__26__Parameter__9__name, EffectType__26__Parameter__10__name, EffectType__26__Parameter__11__name, EffectType__26__Parameter__12__name, EffectType__26__Parameter__13__name, EffectType__26__Parameter__14__name, EffectType__26__Parameter__15__name, EffectType__26__Parameter__16__name, EffectType__26__Parameter__17__name, EffectType__26__Parameter__18__name, EffectType__26__Parameter__19__name, EffectType__26__Parameter__20__name, EffectType__26__Parameter__21__name, EffectType__26__Parameter__22__name, EffectType__26__Parameter__23__name, EffectType__26__Parameter__24__name, EffectType__26__Parameter__25__name, EffectType__26__Parameter__26__name, EffectType__26__Parameter__27__name, EffectType__26__Parameter__28__name, EffectType__26__Parameter__29__name, EffectType__26__Parameter__30__name, EffectType__26__Parameter__31__name, EffectType__26__Parameter__32__name, EffectType__26__Parameter__33__name, EffectType__26__Parameter__34__name, EffectType__26__Parameter__35__name, EffectType__26__Parameter__36__name, EffectType__26__Parameter__37__name, EffectType__26__Parameter__38__name, EffectType__26__Parameter__39__name, EffectType__26__Parameter__40__name, EffectType__26__Parameter__41__name, EffectType__26__Parameter__42__name, EffectType__26__Parameter__43__name, EffectType__26__Parameter__44__name, EffectType__26__Parameter__45__name, EffectType__26__Parameter__46__name, EffectType__26__Parameter__47__name, EffectType__26__Parameter__48__name, EffectType__26__Parameter__49__name, 
EffectType__27__Parameter__0__name, EffectType__27__Parameter__1__name, EffectType__27__Parameter__2__name, EffectType__27__Parameter__3__name, EffectType__27__Parameter__4__name, EffectType__27__Parameter__5__name, EffectType__27__Parameter__6__name, EffectType__27__Parameter__7__name, EffectType__27__Parameter__8__name, EffectType__27__Parameter__9__name, EffectType__27__Parameter__10__name, EffectType__27__Parameter__11__name, EffectType__27__Parameter__12__name, EffectType__27__Parameter__13__name, EffectType__27__Parameter__14__name, EffectType__27__Parameter__15__name, EffectType__27__Parameter__16__name, 
EffectType__28__Parameter__0__name, EffectType__28__Parameter__1__name, EffectType__28__Parameter__2__name, EffectType__28__Parameter__3__name, EffectType__28__Parameter__4__name, EffectType__28__Parameter__5__name, EffectType__28__Parameter__6__name, EffectType__28__Parameter__7__name, EffectType__28__Parameter__8__name, EffectType__28__Parameter__9__name, EffectType__28__Parameter__10__name, EffectType__28__Parameter__11__name, EffectType__28__Parameter__12__name, EffectType__28__Parameter__13__name, EffectType__28__Parameter__14__name, 
EffectType__29__Parameter__0__name, EffectType__29__Parameter__1__name, EffectType__29__Parameter__2__name, EffectType__29__Parameter__3__name, EffectType__29__Parameter__4__name, EffectType__29__Parameter__5__name, EffectType__29__Parameter__6__name, EffectType__29__Parameter__7__name, EffectType__29__Parameter__8__name, EffectType__29__Parameter__9__name, EffectType__29__Parameter__10__name, EffectType__29__Parameter__11__name, EffectType__29__Parameter__12__name, 
EffectType__30__Parameter__0__name, EffectType__30__Parameter__1__name, EffectType__30__Parameter__2__name, EffectType__30__Parameter__3__name, EffectType__30__Parameter__4__name, EffectType__30__Parameter__5__name, EffectType__30__Parameter__6__name, EffectType__30__Parameter__7__name, EffectType__30__Parameter__8__name, EffectType__30__Parameter__9__name, 
EffectType__31__Parameter__0__name, EffectType__31__Parameter__1__name, EffectType__31__Parameter__2__name, EffectType__31__Parameter__3__name, EffectType__31__Parameter__4__name, EffectType__31__Parameter__5__name, EffectType__31__Parameter__6__name, EffectType__31__Parameter__7__name, EffectType__31__Parameter__8__name, EffectType__31__Parameter__9__name, EffectType__31__Parameter__10__name, EffectType__31__Parameter__11__name, EffectType__31__Parameter__12__name, EffectType__31__Parameter__13__name, EffectType__31__Parameter__14__name, EffectType__31__Parameter__15__name, EffectType__31__Parameter__16__name, EffectType__31__Parameter__17__name, EffectType__31__Parameter__18__name, EffectType__31__Parameter__19__name, EffectType__31__Parameter__20__name, EffectType__31__Parameter__21__name, EffectType__31__Parameter__22__name, EffectType__31__Parameter__23__name, EffectType__31__Parameter__24__name, EffectType__31__Parameter__25__name, EffectType__31__Parameter__26__name, EffectType__31__Parameter__27__name, 
EffectType__32__Parameter__0__name, EffectType__32__Parameter__1__name, EffectType__32__Parameter__2__name, EffectType__32__Parameter__3__name, EffectType__32__Parameter__4__name, EffectType__32__Parameter__5__name, EffectType__32__Parameter__6__name, EffectType__32__Parameter__7__name, EffectType__32__Parameter__8__name, EffectType__32__Parameter__9__name, EffectType__32__Parameter__10__name, EffectType__32__Parameter__11__name, EffectType__32__Parameter__12__name, EffectType__32__Parameter__13__name, EffectType__32__Parameter__14__name, EffectType__32__Parameter__15__name, EffectType__32__Parameter__16__name, EffectType__32__Parameter__17__name, EffectType__32__Parameter__18__name, EffectType__32__Parameter__19__name, EffectType__32__Parameter__20__name, EffectType__32__Parameter__21__name, EffectType__32__Parameter__22__name, EffectType__32__Parameter__23__name, EffectType__32__Parameter__24__name, EffectType__32__Parameter__25__name, EffectType__32__Parameter__26__name, EffectType__32__Parameter__27__name, EffectType__32__Parameter__28__name, EffectType__32__Parameter__29__name, EffectType__32__Parameter__30__name, EffectType__32__Parameter__31__name, EffectType__32__Parameter__32__name, EffectType__32__Parameter__33__name, EffectType__32__Parameter__34__name, EffectType__32__Parameter__35__name, EffectType__32__Parameter__36__name, EffectType__32__Parameter__37__name, EffectType__32__Parameter__38__name, EffectType__32__Parameter__39__name, EffectType__32__Parameter__40__name, EffectType__32__Parameter__41__name, EffectType__32__Parameter__42__name, EffectType__32__Parameter__43__name, EffectType__32__Parameter__44__name, EffectType__32__Parameter__45__name, 
EffectType__33__Parameter__0__name, EffectType__33__Parameter__1__name, EffectType__33__Parameter__2__name, EffectType__33__Parameter__3__name, EffectType__33__Parameter__4__name, EffectType__33__Parameter__5__name, EffectType__33__Parameter__6__name, EffectType__33__Parameter__7__name, EffectType__33__Parameter__8__name, EffectType__33__Parameter__9__name, EffectType__33__Parameter__10__name, EffectType__33__Parameter__11__name, EffectType__33__Parameter__12__name, EffectType__33__Parameter__13__name, EffectType__33__Parameter__14__name, EffectType__33__Parameter__15__name, EffectType__33__Parameter__16__name, EffectType__33__Parameter__17__name, EffectType__33__Parameter__18__name, EffectType__33__Parameter__19__name, EffectType__33__Parameter__20__name, EffectType__33__Parameter__21__name, EffectType__33__Parameter__22__name, EffectType__33__Parameter__23__name, EffectType__33__Parameter__24__name, EffectType__33__Parameter__25__name, EffectType__33__Parameter__26__name, EffectType__33__Parameter__27__name, EffectType__33__Parameter__28__name, EffectType__33__Parameter__29__name, EffectType__33__Parameter__30__name, EffectType__33__Parameter__31__name, EffectType__33__Parameter__32__name, EffectType__33__Parameter__33__name, EffectType__33__Parameter__34__name, EffectType__33__Parameter__35__name, EffectType__33__Parameter__36__name, EffectType__33__Parameter__37__name, EffectType__33__Parameter__38__name, EffectType__33__Parameter__39__name, 
EffectType__34__Parameter__0__name, EffectType__34__Parameter__1__name, EffectType__34__Parameter__2__name, EffectType__34__Parameter__3__name, EffectType__34__Parameter__4__name, EffectType__34__Parameter__5__name, EffectType__34__Parameter__6__name, EffectType__34__Parameter__7__name, EffectType__34__Parameter__8__name, 
EffectType__35__Parameter__0__name, EffectType__35__Parameter__1__name, EffectType__35__Parameter__2__name, EffectType__35__Parameter__3__name, EffectType__35__Parameter__4__name, 
EffectType__36__Parameter__0__name, EffectType__36__Parameter__1__name, EffectType__36__Parameter__2__name, EffectType__36__Parameter__3__name, EffectType__36__Parameter__4__name, EffectType__36__Parameter__5__name, EffectType__36__Parameter__6__name, EffectType__36__Parameter__7__name, EffectType__36__Parameter__8__name, EffectType__36__Parameter__9__name, EffectType__36__Parameter__10__name, EffectType__36__Parameter__11__name, EffectType__36__Parameter__12__name, EffectType__36__Parameter__13__name, EffectType__36__Parameter__14__name, EffectType__36__Parameter__15__name, EffectType__36__Parameter__16__name, EffectType__36__Parameter__17__name, EffectType__36__Parameter__18__name, EffectType__36__Parameter__19__name, 
EffectType__37__Parameter__0__name, EffectType__37__Parameter__1__name, EffectType__37__Parameter__2__name, EffectType__37__Parameter__3__name, EffectType__37__Parameter__4__name, EffectType__37__Parameter__5__name, EffectType__37__Parameter__6__name, EffectType__37__Parameter__7__name, EffectType__37__Parameter__8__name, EffectType__37__Parameter__9__name, EffectType__37__Parameter__10__name, EffectType__37__Parameter__11__name, EffectType__37__Parameter__12__name, EffectType__37__Parameter__13__name, EffectType__37__Parameter__14__name, EffectType__37__Parameter__15__name, EffectType__37__Parameter__16__name, EffectType__37__Parameter__17__name, EffectType__37__Parameter__18__name, EffectType__37__Parameter__19__name, EffectType__37__Parameter__20__name, EffectType__37__Parameter__21__name, EffectType__37__Parameter__22__name, EffectType__37__Parameter__23__name, EffectType__37__Parameter__24__name, EffectType__37__Parameter__25__name, EffectType__37__Parameter__26__name, EffectType__37__Parameter__27__name, EffectType__37__Parameter__28__name, EffectType__37__Parameter__29__name, EffectType__37__Parameter__30__name, EffectType__37__Parameter__31__name, EffectType__37__Parameter__32__name, EffectType__37__Parameter__33__name, EffectType__37__Parameter__34__name, EffectType__37__Parameter__35__name, EffectType__37__Parameter__36__name, EffectType__37__Parameter__37__name, EffectType__37__Parameter__38__name, EffectType__37__Parameter__39__name, EffectType__37__Parameter__40__name, EffectType__37__Parameter__41__name, EffectType__37__Parameter__42__name, EffectType__37__Parameter__43__name, EffectType__37__Parameter__44__name, EffectType__37__Parameter__45__name, EffectType__37__Parameter__46__name, EffectType__37__Parameter__47__name, EffectType__37__Parameter__48__name, EffectType__37__Parameter__49__name, EffectType__37__Parameter__50__name, EffectType__37__Parameter__51__name, EffectType__37__Parameter__52__name, EffectType__37__Parameter__53__name, EffectType__37__Parameter__54__name, EffectType__37__Parameter__55__name, EffectType__37__Parameter__56__name, EffectType__37__Parameter__57__name, EffectType__37__Parameter__58__name, EffectType__37__Parameter__59__name, EffectType__37__Parameter__60__name, EffectType__37__Parameter__61__name, EffectType__37__Parameter__62__name, EffectType__37__Parameter__63__name, EffectType__37__Parameter__64__name, EffectType__37__Parameter__65__name, EffectType__37__Parameter__66__name, EffectType__37__Parameter__67__name, EffectType__37__Parameter__68__name, EffectType__37__Parameter__69__name, EffectType__37__Parameter__70__name, EffectType__37__Parameter__71__name, EffectType__37__Parameter__72__name, EffectType__37__Parameter__73__name, EffectType__37__Parameter__74__name, EffectType__37__Parameter__75__name, EffectType__37__Parameter__76__name, EffectType__37__Parameter__77__name, 
EffectType__38__Parameter__0__name, EffectType__38__Parameter__1__name, EffectType__38__Parameter__2__name, EffectType__38__Parameter__3__name, EffectType__38__Parameter__4__name, EffectType__38__Parameter__5__name, EffectType__38__Parameter__6__name, EffectType__38__Parameter__7__name, EffectType__38__Parameter__8__name, EffectType__38__Parameter__9__name, EffectType__38__Parameter__10__name, EffectType__38__Parameter__11__name, EffectType__38__Parameter__12__name, 
EffectType__39__Parameter__0__name, EffectType__39__Parameter__1__name, EffectType__39__Parameter__2__name, EffectType__39__Parameter__3__name, EffectType__39__Parameter__4__name, EffectType__39__Parameter__5__name, EffectType__39__Parameter__6__name, EffectType__39__Parameter__7__name, EffectType__39__Parameter__8__name, EffectType__39__Parameter__9__name, EffectType__39__Parameter__10__name, EffectType__39__Parameter__11__name, EffectType__39__Parameter__12__name, EffectType__39__Parameter__13__name, EffectType__39__Parameter__14__name, EffectType__39__Parameter__15__name, EffectType__39__Parameter__16__name, EffectType__39__Parameter__17__name, EffectType__39__Parameter__18__name, EffectType__39__Parameter__19__name, EffectType__39__Parameter__20__name};

PROGMEM prog_char EffectType__2__Parameter__0__label[] = "Threshold";
PROGMEM prog_char EffectType__2__Parameter__1__label[] = "Ratio";
PROGMEM prog_char EffectType__2__Parameter__2__label[] = "Attack";
PROGMEM prog_char EffectType__2__Parameter__3__label[] = "Release";
PROGMEM prog_char EffectType__2__Parameter__4__label[] = "Level";
PROGMEM prog_char EffectType__2__Parameter__5__label[] = "Knee";
PROGMEM prog_char EffectType__2__Parameter__6__label[] = "Makeup";
PROGMEM prog_char EffectType__2__Parameter__7__label[] = "Detect";
PROGMEM prog_char EffectType__2__Parameter__8__label[] = "Filter";
PROGMEM prog_char EffectType__2__Parameter__9__label[] = "";
PROGMEM prog_char EffectType__2__Parameter__10__label[] = "Sidechain Select";
PROGMEM prog_char EffectType__2__Parameter__11__label[] = "Mix";
PROGMEM prog_char EffectType__2__Parameter__12__label[] = "";
PROGMEM prog_char EffectType__2__Parameter__13__label[] = "Sustain";
PROGMEM prog_char EffectType__2__Parameter__14__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__2__Parameter__15__label[] = "Look-Ahead";
PROGMEM prog_char EffectType__2__Parameter__16__label[] = "Auto";
PROGMEM prog_char EffectType__2__Parameter__17__label[] = "Emphasis";
PROGMEM prog_char EffectType__3__Parameter__0__label[] = "31";
PROGMEM prog_char EffectType__3__Parameter__1__label[] = "63";
PROGMEM prog_char EffectType__3__Parameter__2__label[] = "125";
PROGMEM prog_char EffectType__3__Parameter__3__label[] = "250";
PROGMEM prog_char EffectType__3__Parameter__4__label[] = "500";
PROGMEM prog_char EffectType__3__Parameter__5__label[] = "1k";
PROGMEM prog_char EffectType__3__Parameter__6__label[] = "2k";
PROGMEM prog_char EffectType__3__Parameter__7__label[] = "4k";
PROGMEM prog_char EffectType__3__Parameter__8__label[] = "8k";
PROGMEM prog_char EffectType__3__Parameter__9__label[] = "16k";
PROGMEM prog_char EffectType__3__Parameter__10__label[] = "";
PROGMEM prog_char EffectType__3__Parameter__11__label[] = "Level";
PROGMEM prog_char EffectType__3__Parameter__12__label[] = "Balance";
PROGMEM prog_char EffectType__3__Parameter__13__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__3__Parameter__14__label[] = "";
PROGMEM prog_char EffectType__3__Parameter__15__label[] = "";
PROGMEM prog_char EffectType__3__Parameter__16__label[] = "";
PROGMEM prog_char EffectType__3__Parameter__17__label[] = "";
PROGMEM prog_char EffectType__3__Parameter__18__label[] = "";
PROGMEM prog_char EffectType__4__Parameter__0__label[] = "Freq 1";
PROGMEM prog_char EffectType__4__Parameter__1__label[] = "Freq 2";
PROGMEM prog_char EffectType__4__Parameter__2__label[] = "Freq 3";
PROGMEM prog_char EffectType__4__Parameter__3__label[] = "Freq 4";
PROGMEM prog_char EffectType__4__Parameter__4__label[] = "Freq 5";
PROGMEM prog_char EffectType__4__Parameter__5__label[] = "Q1";
PROGMEM prog_char EffectType__4__Parameter__6__label[] = "Q2";
PROGMEM prog_char EffectType__4__Parameter__7__label[] = "Q3";
PROGMEM prog_char EffectType__4__Parameter__8__label[] = "Q4";
PROGMEM prog_char EffectType__4__Parameter__9__label[] = "Q5";
PROGMEM prog_char EffectType__4__Parameter__10__label[] = "Gain 1";
PROGMEM prog_char EffectType__4__Parameter__11__label[] = "Gain 2";
PROGMEM prog_char EffectType__4__Parameter__12__label[] = "Gain 3";
PROGMEM prog_char EffectType__4__Parameter__13__label[] = "Gain 4";
PROGMEM prog_char EffectType__4__Parameter__14__label[] = "Gain 5";
PROGMEM prog_char EffectType__4__Parameter__15__label[] = "Frequency 1 Type";
PROGMEM prog_char EffectType__4__Parameter__16__label[] = "Frequency 5 Type";
PROGMEM prog_char EffectType__4__Parameter__17__label[] = "";
PROGMEM prog_char EffectType__4__Parameter__18__label[] = "";
PROGMEM prog_char EffectType__4__Parameter__19__label[] = "Level";
PROGMEM prog_char EffectType__4__Parameter__20__label[] = "Balance";
PROGMEM prog_char EffectType__4__Parameter__21__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__4__Parameter__22__label[] = "";
PROGMEM prog_char EffectType__4__Parameter__23__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__0__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__1__label[] = "Drive";
PROGMEM prog_char EffectType__5__Parameter__2__label[] = "Bass";
PROGMEM prog_char EffectType__5__Parameter__3__label[] = "Mid";
PROGMEM prog_char EffectType__5__Parameter__4__label[] = "Treb";
PROGMEM prog_char EffectType__5__Parameter__5__label[] = "Master Vol";
PROGMEM prog_char EffectType__5__Parameter__6__label[] = "Low Cut";
PROGMEM prog_char EffectType__5__Parameter__7__label[] = "Hi Cut";
PROGMEM prog_char EffectType__5__Parameter__8__label[] = "Tone Freq";
PROGMEM prog_char EffectType__5__Parameter__9__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__10__label[] = "Bright Cap";
PROGMEM prog_char EffectType__5__Parameter__11__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__12__label[] = "XFormer Low Freq";
PROGMEM prog_char EffectType__5__Parameter__13__label[] = "XFormer Hi Freq";
PROGMEM prog_char EffectType__5__Parameter__14__label[] = "Tone Location";
PROGMEM prog_char EffectType__5__Parameter__15__label[] = "Input Select";
PROGMEM prog_char EffectType__5__Parameter__16__label[] = "Depth";
PROGMEM prog_char EffectType__5__Parameter__17__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__18__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__19__label[] = "Supply Sag";
PROGMEM prog_char EffectType__5__Parameter__20__label[] = "Presence";
PROGMEM prog_char EffectType__5__Parameter__21__label[] = "Level";
PROGMEM prog_char EffectType__5__Parameter__22__label[] = "Balance";
PROGMEM prog_char EffectType__5__Parameter__23__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__5__Parameter__24__label[] = "Damping";
PROGMEM prog_char EffectType__5__Parameter__25__label[] = "Presence Freq";
PROGMEM prog_char EffectType__5__Parameter__26__label[] = "Low Res Freq";
PROGMEM prog_char EffectType__5__Parameter__27__label[] = "Low Resonance";
PROGMEM prog_char EffectType__5__Parameter__28__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__29__label[] = "Depth Freq";
PROGMEM prog_char EffectType__5__Parameter__30__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__31__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__32__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__33__label[] = "Grid Modeling";
PROGMEM prog_char EffectType__5__Parameter__34__label[] = "Tonestack Type";
PROGMEM prog_char EffectType__5__Parameter__35__label[] = "B+ Time Constant";
PROGMEM prog_char EffectType__5__Parameter__36__label[] = "Power Tube Bias";
PROGMEM prog_char EffectType__5__Parameter__37__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__38__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__39__label[] = "Bright";
PROGMEM prog_char EffectType__5__Parameter__40__label[] = "Boost";
PROGMEM prog_char EffectType__5__Parameter__41__label[] = "Low Res Q";
PROGMEM prog_char EffectType__5__Parameter__42__label[] = "Preamp Bias";
PROGMEM prog_char EffectType__5__Parameter__43__label[] = "Hi Freq";
PROGMEM prog_char EffectType__5__Parameter__44__label[] = "Hi Resonance";
PROGMEM prog_char EffectType__5__Parameter__45__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__46__label[] = "XFormer Drive";
PROGMEM prog_char EffectType__5__Parameter__47__label[] = "Input Trim";
PROGMEM prog_char EffectType__5__Parameter__48__label[] = "Triode Hardness";
PROGMEM prog_char EffectType__5__Parameter__49__label[] = "MV Location";
PROGMEM prog_char EffectType__5__Parameter__50__label[] = "Speaker Drive";
PROGMEM prog_char EffectType__5__Parameter__51__label[] = "XFormer Match";
PROGMEM prog_char EffectType__5__Parameter__52__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__53__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__54__label[] = "Saturation";
PROGMEM prog_char EffectType__5__Parameter__55__label[] = "63";
PROGMEM prog_char EffectType__5__Parameter__56__label[] = "125";
PROGMEM prog_char EffectType__5__Parameter__57__label[] = "250";
PROGMEM prog_char EffectType__5__Parameter__58__label[] = "500";
PROGMEM prog_char EffectType__5__Parameter__59__label[] = "1K";
PROGMEM prog_char EffectType__5__Parameter__60__label[] = "2K";
PROGMEM prog_char EffectType__5__Parameter__61__label[] = "4K";
PROGMEM prog_char EffectType__5__Parameter__62__label[] = "8K";
PROGMEM prog_char EffectType__5__Parameter__63__label[] = "Bias Excursion";
PROGMEM prog_char EffectType__5__Parameter__64__label[] = "Excursion Time";
PROGMEM prog_char EffectType__5__Parameter__65__label[] = "Recovery Time";
PROGMEM prog_char EffectType__5__Parameter__66__label[] = "Triode 2 Plate Freq";
PROGMEM prog_char EffectType__5__Parameter__67__label[] = "Triode 1 Plate Freq";
PROGMEM prog_char EffectType__5__Parameter__68__label[] = "Power Tube Type";
PROGMEM prog_char EffectType__5__Parameter__69__label[] = "Amp Voicing";
PROGMEM prog_char EffectType__5__Parameter__70__label[] = "Power Amp Hi Cut";
PROGMEM prog_char EffectType__5__Parameter__71__label[] = "Power Amp Low Cut";
PROGMEM prog_char EffectType__5__Parameter__72__label[] = "Character Freq";
PROGMEM prog_char EffectType__5__Parameter__73__label[] = "Character";
PROGMEM prog_char EffectType__5__Parameter__74__label[] = "";
PROGMEM prog_char EffectType__5__Parameter__75__label[] = "Dynamics";
PROGMEM prog_char EffectType__5__Parameter__76__label[] = "Dynamics Time";
PROGMEM prog_char EffectType__5__Parameter__77__label[] = "Master Vol Trim";
PROGMEM prog_char EffectType__5__Parameter__78__label[] = "Fat";
PROGMEM prog_char EffectType__5__Parameter__79__label[] = "Definition";
PROGMEM prog_char EffectType__5__Parameter__80__label[] = "Compression";
PROGMEM prog_char EffectType__5__Parameter__81__label[] = "Preamp Dyn Time";
PROGMEM prog_char EffectType__5__Parameter__82__label[] = "Use MIMIC(TM)";
PROGMEM prog_char EffectType__5__Parameter__83__label[] = "Pick Attack";
PROGMEM prog_char EffectType__5__Parameter__84__label[] = "Dynamic Presence";
PROGMEM prog_char EffectType__5__Parameter__85__label[] = "Dynamic Depth";
PROGMEM prog_char EffectType__5__Parameter__86__label[] = "Power Supply Type";
PROGMEM prog_char EffectType__5__Parameter__87__label[] = "AC Line Freq";
PROGMEM prog_char EffectType__5__Parameter__88__label[] = "Thunk";
PROGMEM prog_char EffectType__5__Parameter__89__label[] = "Tremolo Freq";
PROGMEM prog_char EffectType__5__Parameter__90__label[] = "Tremolo Depth";
PROGMEM prog_char EffectType__6__Parameter__0__label[] = "Cab L";
PROGMEM prog_char EffectType__6__Parameter__1__label[] = "Mic L";
PROGMEM prog_char EffectType__6__Parameter__2__label[] = "Cab R";
PROGMEM prog_char EffectType__6__Parameter__3__label[] = "Mic R";
PROGMEM prog_char EffectType__6__Parameter__4__label[] = "Link";
PROGMEM prog_char EffectType__6__Parameter__5__label[] = "Level L";
PROGMEM prog_char EffectType__6__Parameter__6__label[] = "Level R";
PROGMEM prog_char EffectType__6__Parameter__7__label[] = "Pan L";
PROGMEM prog_char EffectType__6__Parameter__8__label[] = "Pan R";
PROGMEM prog_char EffectType__6__Parameter__9__label[] = "Level";
PROGMEM prog_char EffectType__6__Parameter__10__label[] = "Balance";
PROGMEM prog_char EffectType__6__Parameter__11__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__6__Parameter__12__label[] = "";
PROGMEM prog_char EffectType__6__Parameter__13__label[] = "";
PROGMEM prog_char EffectType__6__Parameter__14__label[] = "";
PROGMEM prog_char EffectType__6__Parameter__15__label[] = "";
PROGMEM prog_char EffectType__6__Parameter__16__label[] = "Room Level";
PROGMEM prog_char EffectType__6__Parameter__17__label[] = "Room Size";
PROGMEM prog_char EffectType__6__Parameter__18__label[] = "Mic Spacing";
PROGMEM prog_char EffectType__6__Parameter__19__label[] = "Low Cut";
PROGMEM prog_char EffectType__6__Parameter__20__label[] = "High Cut";
PROGMEM prog_char EffectType__6__Parameter__21__label[] = "Cab Size";
PROGMEM prog_char EffectType__6__Parameter__22__label[] = "Proximity L";
PROGMEM prog_char EffectType__6__Parameter__23__label[] = "Air";
PROGMEM prog_char EffectType__6__Parameter__24__label[] = "Motor Drive";
PROGMEM prog_char EffectType__6__Parameter__25__label[] = "Air Frequency";
PROGMEM prog_char EffectType__6__Parameter__26__label[] = "Delay Left";
PROGMEM prog_char EffectType__6__Parameter__27__label[] = "Delay Right";
PROGMEM prog_char EffectType__6__Parameter__28__label[] = "Proximity R";
PROGMEM prog_char EffectType__7__Parameter__0__label[] = "";
PROGMEM prog_char EffectType__7__Parameter__1__label[] = "Time";
PROGMEM prog_char EffectType__7__Parameter__2__label[] = "High Cut";
PROGMEM prog_char EffectType__7__Parameter__3__label[] = "Color";
PROGMEM prog_char EffectType__7__Parameter__4__label[] = "Wall Diffusion";
PROGMEM prog_char EffectType__7__Parameter__5__label[] = "Size";
PROGMEM prog_char EffectType__7__Parameter__6__label[] = "Tail Delay";
PROGMEM prog_char EffectType__7__Parameter__7__label[] = "Early Level";
PROGMEM prog_char EffectType__7__Parameter__8__label[] = "Reverb Level";
PROGMEM prog_char EffectType__7__Parameter__9__label[] = "PreDelay";
PROGMEM prog_char EffectType__7__Parameter__10__label[] = "Low Cut";
PROGMEM prog_char EffectType__7__Parameter__11__label[] = "Mod Depth";
PROGMEM prog_char EffectType__7__Parameter__12__label[] = "Mod Rate";
PROGMEM prog_char EffectType__7__Parameter__13__label[] = "Mix";
PROGMEM prog_char EffectType__7__Parameter__14__label[] = "Level";
PROGMEM prog_char EffectType__7__Parameter__15__label[] = "Balance";
PROGMEM prog_char EffectType__7__Parameter__16__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__7__Parameter__17__label[] = "";
PROGMEM prog_char EffectType__7__Parameter__18__label[] = "Input Gain";
PROGMEM prog_char EffectType__7__Parameter__19__label[] = "Echo Density";
PROGMEM prog_char EffectType__7__Parameter__20__label[] = "Input Diffusion";
PROGMEM prog_char EffectType__7__Parameter__21__label[] = "Diffusion Time";
PROGMEM prog_char EffectType__7__Parameter__22__label[] = "";
PROGMEM prog_char EffectType__7__Parameter__23__label[] = "Number Springs";
PROGMEM prog_char EffectType__7__Parameter__24__label[] = "Spring Tone";
PROGMEM prog_char EffectType__7__Parameter__25__label[] = "";
PROGMEM prog_char EffectType__7__Parameter__26__label[] = "Frequency 1";
PROGMEM prog_char EffectType__7__Parameter__27__label[] = "Frequency 2";
PROGMEM prog_char EffectType__7__Parameter__28__label[] = "Q 1";
PROGMEM prog_char EffectType__7__Parameter__29__label[] = "Q 2";
PROGMEM prog_char EffectType__7__Parameter__30__label[] = "Gain 1";
PROGMEM prog_char EffectType__7__Parameter__31__label[] = "Gain 2";
PROGMEM prog_char EffectType__7__Parameter__32__label[] = "Spring Drive";
PROGMEM prog_char EffectType__7__Parameter__33__label[] = "LF Time";
PROGMEM prog_char EffectType__7__Parameter__34__label[] = "LF Crossover";
PROGMEM prog_char EffectType__8__Parameter__0__label[] = "";
PROGMEM prog_char EffectType__8__Parameter__1__label[] = "";
PROGMEM prog_char EffectType__8__Parameter__2__label[] = "Head 1 Time";
PROGMEM prog_char EffectType__8__Parameter__3__label[] = "Head 2 Ratio";
PROGMEM prog_char EffectType__8__Parameter__4__label[] = "Feedback 1";
PROGMEM prog_char EffectType__8__Parameter__5__label[] = "Feedback L";
PROGMEM prog_char EffectType__8__Parameter__6__label[] = "Feedback 2";
PROGMEM prog_char EffectType__8__Parameter__7__label[] = "Echo Pan";
PROGMEM prog_char EffectType__8__Parameter__8__label[] = "Spread (Width)";
PROGMEM prog_char EffectType__8__Parameter__9__label[] = "Head 1 Tempo";
PROGMEM prog_char EffectType__8__Parameter__10__label[] = "Low Cut";
PROGMEM prog_char EffectType__8__Parameter__11__label[] = "High Cut";
PROGMEM prog_char EffectType__8__Parameter__12__label[] = "LFO1 Rate";
PROGMEM prog_char EffectType__8__Parameter__13__label[] = "LFO2 Rate";
PROGMEM prog_char EffectType__8__Parameter__14__label[] = "LFO1 Depth";
PROGMEM prog_char EffectType__8__Parameter__15__label[] = "LFO2 Depth";
PROGMEM prog_char EffectType__8__Parameter__16__label[] = "Drive";
PROGMEM prog_char EffectType__8__Parameter__17__label[] = "Mix";
PROGMEM prog_char EffectType__8__Parameter__18__label[] = "Level";
PROGMEM prog_char EffectType__8__Parameter__19__label[] = "Balance";
PROGMEM prog_char EffectType__8__Parameter__20__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__8__Parameter__21__label[] = "";
PROGMEM prog_char EffectType__8__Parameter__22__label[] = "";
PROGMEM prog_char EffectType__8__Parameter__23__label[] = "Input Gain";
PROGMEM prog_char EffectType__8__Parameter__24__label[] = "LFO1 Type";
PROGMEM prog_char EffectType__8__Parameter__25__label[] = "LFO2 Type";
PROGMEM prog_char EffectType__8__Parameter__26__label[] = "Time R";
PROGMEM prog_char EffectType__8__Parameter__27__label[] = "Hold";
PROGMEM prog_char EffectType__8__Parameter__28__label[] = "Master Feedback";
PROGMEM prog_char EffectType__8__Parameter__29__label[] = "Tempo R";
PROGMEM prog_char EffectType__8__Parameter__30__label[] = "Feedback L>R";
PROGMEM prog_char EffectType__8__Parameter__31__label[] = "Feedback R>L";
PROGMEM prog_char EffectType__8__Parameter__32__label[] = "Level 1";
PROGMEM prog_char EffectType__8__Parameter__33__label[] = "Level 2";
PROGMEM prog_char EffectType__8__Parameter__34__label[] = "Pan 1";
PROGMEM prog_char EffectType__8__Parameter__35__label[] = "Pan 2";
PROGMEM prog_char EffectType__8__Parameter__36__label[] = "LFO1 Phase";
PROGMEM prog_char EffectType__8__Parameter__37__label[] = "LFO2 Phase";
PROGMEM prog_char EffectType__8__Parameter__38__label[] = "XFade Time";
PROGMEM prog_char EffectType__8__Parameter__39__label[] = "Run";
PROGMEM prog_char EffectType__8__Parameter__40__label[] = "Trigger Restart";
PROGMEM prog_char EffectType__8__Parameter__41__label[] = "Filter Slope";
PROGMEM prog_char EffectType__8__Parameter__42__label[] = "Ducker Attenuation";
PROGMEM prog_char EffectType__8__Parameter__43__label[] = "Ducker Threshold";
PROGMEM prog_char EffectType__8__Parameter__44__label[] = "Ducker Release";
PROGMEM prog_char EffectType__8__Parameter__45__label[] = "Diffusion";
PROGMEM prog_char EffectType__8__Parameter__46__label[] = "Diff Time";
PROGMEM prog_char EffectType__8__Parameter__47__label[] = "Phase Reverse";
PROGMEM prog_char EffectType__8__Parameter__48__label[] = "LFO1 Target";
PROGMEM prog_char EffectType__8__Parameter__49__label[] = "LFO2 Target";
PROGMEM prog_char EffectType__8__Parameter__50__label[] = "LFO1 Tempo";
PROGMEM prog_char EffectType__8__Parameter__51__label[] = "LFO2 Tempo";
PROGMEM prog_char EffectType__8__Parameter__52__label[] = "Sweep Rate";
PROGMEM prog_char EffectType__8__Parameter__53__label[] = "Sweep Type";
PROGMEM prog_char EffectType__8__Parameter__54__label[] = "Sweep Phase";
PROGMEM prog_char EffectType__8__Parameter__55__label[] = "Sweep Tempo";
PROGMEM prog_char EffectType__8__Parameter__56__label[] = "Start Freq";
PROGMEM prog_char EffectType__8__Parameter__57__label[] = "Stop Freq";
PROGMEM prog_char EffectType__8__Parameter__58__label[] = "Resonance";
PROGMEM prog_char EffectType__8__Parameter__59__label[] = "Q";
PROGMEM prog_char EffectType__8__Parameter__60__label[] = "Bit Reduction";
PROGMEM prog_char EffectType__8__Parameter__61__label[] = "Frequency 1";
PROGMEM prog_char EffectType__8__Parameter__62__label[] = "Frequency 2";
PROGMEM prog_char EffectType__8__Parameter__63__label[] = "Q 1";
PROGMEM prog_char EffectType__8__Parameter__64__label[] = "Q 2";
PROGMEM prog_char EffectType__8__Parameter__65__label[] = "Gain 1";
PROGMEM prog_char EffectType__8__Parameter__66__label[] = "Gain 2";
PROGMEM prog_char EffectType__8__Parameter__67__label[] = "LFO Depth Range";
PROGMEM prog_char EffectType__8__Parameter__68__label[] = "Motor Speed";
PROGMEM prog_char EffectType__8__Parameter__69__label[] = "Right Post Delay";
PROGMEM prog_char EffectType__9__Parameter__0__label[] = "Time 1";
PROGMEM prog_char EffectType__9__Parameter__1__label[] = "Time 2";
PROGMEM prog_char EffectType__9__Parameter__2__label[] = "Time 3";
PROGMEM prog_char EffectType__9__Parameter__3__label[] = "Time 4";
PROGMEM prog_char EffectType__9__Parameter__4__label[] = "Tempo 1";
PROGMEM prog_char EffectType__9__Parameter__5__label[] = "Tempo 2";
PROGMEM prog_char EffectType__9__Parameter__6__label[] = "Tempo 3";
PROGMEM prog_char EffectType__9__Parameter__7__label[] = "Tempo 4";
PROGMEM prog_char EffectType__9__Parameter__8__label[] = "Level 1";
PROGMEM prog_char EffectType__9__Parameter__9__label[] = "Level 2";
PROGMEM prog_char EffectType__9__Parameter__10__label[] = "Level 3";
PROGMEM prog_char EffectType__9__Parameter__11__label[] = "Level 4";
PROGMEM prog_char EffectType__9__Parameter__12__label[] = "Feedback 1";
PROGMEM prog_char EffectType__9__Parameter__13__label[] = "Feedback 2";
PROGMEM prog_char EffectType__9__Parameter__14__label[] = "Feedback 3";
PROGMEM prog_char EffectType__9__Parameter__15__label[] = "Feedback 4";
PROGMEM prog_char EffectType__9__Parameter__16__label[] = "Pan 1";
PROGMEM prog_char EffectType__9__Parameter__17__label[] = "Pan 2";
PROGMEM prog_char EffectType__9__Parameter__18__label[] = "Pan 3";
PROGMEM prog_char EffectType__9__Parameter__19__label[] = "Pan 4";
PROGMEM prog_char EffectType__9__Parameter__20__label[] = "LFO1 Rate";
PROGMEM prog_char EffectType__9__Parameter__21__label[] = "LFO2 Rate";
PROGMEM prog_char EffectType__9__Parameter__22__label[] = "LFO3 Rate";
PROGMEM prog_char EffectType__9__Parameter__23__label[] = "LFO4 Rate";
PROGMEM prog_char EffectType__9__Parameter__24__label[] = "LFO1 Tempo";
PROGMEM prog_char EffectType__9__Parameter__25__label[] = "LFO2 Tempo";
PROGMEM prog_char EffectType__9__Parameter__26__label[] = "LFO3 Tempo";
PROGMEM prog_char EffectType__9__Parameter__27__label[] = "LFO4 Tempo";
PROGMEM prog_char EffectType__9__Parameter__28__label[] = "Mix";
PROGMEM prog_char EffectType__9__Parameter__29__label[] = "Level";
PROGMEM prog_char EffectType__9__Parameter__30__label[] = "Balance";
PROGMEM prog_char EffectType__9__Parameter__31__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__9__Parameter__32__label[] = "";
PROGMEM prog_char EffectType__9__Parameter__33__label[] = "Input Gain";
PROGMEM prog_char EffectType__9__Parameter__34__label[] = "";
PROGMEM prog_char EffectType__9__Parameter__35__label[] = "";
PROGMEM prog_char EffectType__9__Parameter__36__label[] = "Decay time";
PROGMEM prog_char EffectType__9__Parameter__37__label[] = "Diffusion";
PROGMEM prog_char EffectType__9__Parameter__38__label[] = "Diffusion";
PROGMEM prog_char EffectType__9__Parameter__39__label[] = "Diffusion time";
PROGMEM prog_char EffectType__9__Parameter__40__label[] = "Ducker Threshold";
PROGMEM prog_char EffectType__9__Parameter__41__label[] = "Crossfade";
PROGMEM prog_char EffectType__9__Parameter__42__label[] = "Mstr Time";
PROGMEM prog_char EffectType__9__Parameter__43__label[] = "Mstr Level";
PROGMEM prog_char EffectType__9__Parameter__44__label[] = "Mstr Pan";
PROGMEM prog_char EffectType__9__Parameter__45__label[] = "Mstr Frequency";
PROGMEM prog_char EffectType__9__Parameter__46__label[] = "Mstr Q";
PROGMEM prog_char EffectType__9__Parameter__47__label[] = "Mstr Feedback";
PROGMEM prog_char EffectType__9__Parameter__48__label[] = "Master Pitch";
PROGMEM prog_char EffectType__9__Parameter__49__label[] = "Master Detune";
PROGMEM prog_char EffectType__9__Parameter__50__label[] = "Detune 1";
PROGMEM prog_char EffectType__9__Parameter__51__label[] = "Detune 2";
PROGMEM prog_char EffectType__9__Parameter__52__label[] = "Detune 3";
PROGMEM prog_char EffectType__9__Parameter__53__label[] = "Detune 4";
PROGMEM prog_char EffectType__9__Parameter__54__label[] = "Shift 1";
PROGMEM prog_char EffectType__9__Parameter__55__label[] = "Shift 2";
PROGMEM prog_char EffectType__9__Parameter__56__label[] = "Shift 3";
PROGMEM prog_char EffectType__9__Parameter__57__label[] = "Shift 4";
PROGMEM prog_char EffectType__9__Parameter__58__label[] = "Freq 1";
PROGMEM prog_char EffectType__9__Parameter__59__label[] = "Freq 2";
PROGMEM prog_char EffectType__9__Parameter__60__label[] = "Freq 3";
PROGMEM prog_char EffectType__9__Parameter__61__label[] = "Freq 4";
PROGMEM prog_char EffectType__9__Parameter__62__label[] = "Q 1";
PROGMEM prog_char EffectType__9__Parameter__63__label[] = "Q 2";
PROGMEM prog_char EffectType__9__Parameter__64__label[] = "Q 3";
PROGMEM prog_char EffectType__9__Parameter__65__label[] = "Q 4";
PROGMEM prog_char EffectType__9__Parameter__66__label[] = "Mstr Rate";
PROGMEM prog_char EffectType__9__Parameter__67__label[] = "Ducker Attenuation";
PROGMEM prog_char EffectType__9__Parameter__68__label[] = "Mstr Depth";
PROGMEM prog_char EffectType__9__Parameter__69__label[] = "Direction";
PROGMEM prog_char EffectType__9__Parameter__70__label[] = "Tape Speed";
PROGMEM prog_char EffectType__9__Parameter__71__label[] = "LFO1 Depth";
PROGMEM prog_char EffectType__9__Parameter__72__label[] = "LFO2 Depth";
PROGMEM prog_char EffectType__9__Parameter__73__label[] = "LFO3 Depth";
PROGMEM prog_char EffectType__9__Parameter__74__label[] = "LFO4 Depth";
PROGMEM prog_char EffectType__9__Parameter__75__label[] = "LFO1 Master";
PROGMEM prog_char EffectType__9__Parameter__76__label[] = "FB Send";
PROGMEM prog_char EffectType__9__Parameter__77__label[] = "FB Return";
PROGMEM prog_char EffectType__9__Parameter__78__label[] = "Mono/Stereo";
PROGMEM prog_char EffectType__9__Parameter__79__label[] = "Delay time";
PROGMEM prog_char EffectType__9__Parameter__80__label[] = "";
PROGMEM prog_char EffectType__9__Parameter__81__label[] = "Quantize";
PROGMEM prog_char EffectType__9__Parameter__82__label[] = "Decay";
PROGMEM prog_char EffectType__9__Parameter__83__label[] = "";
PROGMEM prog_char EffectType__9__Parameter__84__label[] = "Number of Taps";
PROGMEM prog_char EffectType__9__Parameter__85__label[] = "Shuffle";
PROGMEM prog_char EffectType__9__Parameter__86__label[] = "Delay tempo";
PROGMEM prog_char EffectType__9__Parameter__87__label[] = "Spread";
PROGMEM prog_char EffectType__9__Parameter__88__label[] = "Pan Shape";
PROGMEM prog_char EffectType__9__Parameter__89__label[] = "Pan alpha";
PROGMEM prog_char EffectType__9__Parameter__90__label[] = "Low cut";
PROGMEM prog_char EffectType__9__Parameter__91__label[] = "High cut";
PROGMEM prog_char EffectType__9__Parameter__92__label[] = "Ratio";
PROGMEM prog_char EffectType__9__Parameter__93__label[] = "Feedback";
PROGMEM prog_char EffectType__9__Parameter__94__label[] = "Tap1 Time";
PROGMEM prog_char EffectType__9__Parameter__95__label[] = "Tap2 Time";
PROGMEM prog_char EffectType__9__Parameter__96__label[] = "Tap3 Time";
PROGMEM prog_char EffectType__9__Parameter__97__label[] = "Tap4 Time";
PROGMEM prog_char EffectType__9__Parameter__98__label[] = "Tap5 Time";
PROGMEM prog_char EffectType__9__Parameter__99__label[] = "Tap6 Time";
PROGMEM prog_char EffectType__9__Parameter__100__label[] = "Tap7 Time";
PROGMEM prog_char EffectType__9__Parameter__101__label[] = "Tap8 Time";
PROGMEM prog_char EffectType__9__Parameter__102__label[] = "Tap9 Time";
PROGMEM prog_char EffectType__9__Parameter__103__label[] = "Tap10 Time";
PROGMEM prog_char EffectType__9__Parameter__104__label[] = "Tap1 Level";
PROGMEM prog_char EffectType__9__Parameter__105__label[] = "Tap2 Level";
PROGMEM prog_char EffectType__9__Parameter__106__label[] = "Tap3 Level";
PROGMEM prog_char EffectType__9__Parameter__107__label[] = "Tap4 Level";
PROGMEM prog_char EffectType__9__Parameter__108__label[] = "Tap5 Level";
PROGMEM prog_char EffectType__9__Parameter__109__label[] = "Tap6 Level";
PROGMEM prog_char EffectType__9__Parameter__110__label[] = "Tap7 Level";
PROGMEM prog_char EffectType__9__Parameter__111__label[] = "Tap8 Level";
PROGMEM prog_char EffectType__9__Parameter__112__label[] = "Tap9 Level";
PROGMEM prog_char EffectType__9__Parameter__113__label[] = "Tap10 Level";
PROGMEM prog_char EffectType__9__Parameter__114__label[] = "";
PROGMEM prog_char EffectType__9__Parameter__115__label[] = "";
PROGMEM prog_char EffectType__9__Parameter__116__label[] = "Ducker Release";
PROGMEM prog_char EffectType__10__Parameter__0__label[] = "";
PROGMEM prog_char EffectType__10__Parameter__1__label[] = "Voices";
PROGMEM prog_char EffectType__10__Parameter__2__label[] = "Rate";
PROGMEM prog_char EffectType__10__Parameter__3__label[] = "Tempo";
PROGMEM prog_char EffectType__10__Parameter__4__label[] = "Depth";
PROGMEM prog_char EffectType__10__Parameter__5__label[] = "Hi Cut Freq";
PROGMEM prog_char EffectType__10__Parameter__6__label[] = "Delay time";
PROGMEM prog_char EffectType__10__Parameter__7__label[] = "LFO Phase";
PROGMEM prog_char EffectType__10__Parameter__8__label[] = "LFO Type";
PROGMEM prog_char EffectType__10__Parameter__9__label[] = "Auto depth";
PROGMEM prog_char EffectType__10__Parameter__10__label[] = "Mix";
PROGMEM prog_char EffectType__10__Parameter__11__label[] = "Level";
PROGMEM prog_char EffectType__10__Parameter__12__label[] = "Balance";
PROGMEM prog_char EffectType__10__Parameter__13__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__10__Parameter__14__label[] = "";
PROGMEM prog_char EffectType__10__Parameter__15__label[] = "";
PROGMEM prog_char EffectType__10__Parameter__16__label[] = "Phase Reverse";
PROGMEM prog_char EffectType__10__Parameter__17__label[] = "Width";
PROGMEM prog_char EffectType__10__Parameter__18__label[] = "LFO2 Rate";
PROGMEM prog_char EffectType__10__Parameter__19__label[] = "LFO2 Depth";
PROGMEM prog_char EffectType__10__Parameter__20__label[] = "Drive";
PROGMEM prog_char EffectType__10__Parameter__21__label[] = "Low Cut Freq";
PROGMEM prog_char EffectType__10__Parameter__22__label[] = "Spread";
PROGMEM prog_char EffectType__11__Parameter__0__label[] = "";
PROGMEM prog_char EffectType__11__Parameter__1__label[] = "Rate";
PROGMEM prog_char EffectType__11__Parameter__2__label[] = "Tempo";
PROGMEM prog_char EffectType__11__Parameter__3__label[] = "Depth";
PROGMEM prog_char EffectType__11__Parameter__4__label[] = "Feedback";
PROGMEM prog_char EffectType__11__Parameter__5__label[] = "Delay Time";
PROGMEM prog_char EffectType__11__Parameter__6__label[] = "Dry Delay Shift";
PROGMEM prog_char EffectType__11__Parameter__7__label[] = "LFO Phase";
PROGMEM prog_char EffectType__11__Parameter__8__label[] = "LFO Type";
PROGMEM prog_char EffectType__11__Parameter__9__label[] = "LFO Hicut";
PROGMEM prog_char EffectType__11__Parameter__10__label[] = "Auto depth";
PROGMEM prog_char EffectType__11__Parameter__11__label[] = "Mix";
PROGMEM prog_char EffectType__11__Parameter__12__label[] = "Level";
PROGMEM prog_char EffectType__11__Parameter__13__label[] = "Balance";
PROGMEM prog_char EffectType__11__Parameter__14__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__11__Parameter__15__label[] = "";
PROGMEM prog_char EffectType__11__Parameter__16__label[] = "";
PROGMEM prog_char EffectType__11__Parameter__17__label[] = "Phase Reverse";
PROGMEM prog_char EffectType__11__Parameter__18__label[] = "Thru-Zero";
PROGMEM prog_char EffectType__11__Parameter__19__label[] = "Hi Cut Freq";
PROGMEM prog_char EffectType__11__Parameter__20__label[] = "Drive";
PROGMEM prog_char EffectType__11__Parameter__21__label[] = "Low Cut Freq";
PROGMEM prog_char EffectType__11__Parameter__22__label[] = "Spread";
PROGMEM prog_char EffectType__12__Parameter__0__label[] = "Rate";
PROGMEM prog_char EffectType__12__Parameter__1__label[] = "Low Rotor Depth";
PROGMEM prog_char EffectType__12__Parameter__2__label[] = "Hi Rotor Depth";
PROGMEM prog_char EffectType__12__Parameter__3__label[] = "Hi Rotor Level";
PROGMEM prog_char EffectType__12__Parameter__4__label[] = "Tempo";
PROGMEM prog_char EffectType__12__Parameter__5__label[] = "Mix";
PROGMEM prog_char EffectType__12__Parameter__6__label[] = "Level";
PROGMEM prog_char EffectType__12__Parameter__7__label[] = "Balance";
PROGMEM prog_char EffectType__12__Parameter__8__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__12__Parameter__9__label[] = "";
PROGMEM prog_char EffectType__12__Parameter__10__label[] = "Hi Rotor Horn Length";
PROGMEM prog_char EffectType__12__Parameter__11__label[] = "";
PROGMEM prog_char EffectType__12__Parameter__12__label[] = "HF Mic Spacing";
PROGMEM prog_char EffectType__12__Parameter__13__label[] = "Low Rate Mult";
PROGMEM prog_char EffectType__12__Parameter__14__label[] = "Low Time Const";
PROGMEM prog_char EffectType__12__Parameter__15__label[] = "Hi Time Const";
PROGMEM prog_char EffectType__12__Parameter__16__label[] = "LF Mic Spacing";
PROGMEM prog_char EffectType__12__Parameter__17__label[] = "Drive";
PROGMEM prog_char EffectType__13__Parameter__0__label[] = "";
PROGMEM prog_char EffectType__13__Parameter__1__label[] = "Order";
PROGMEM prog_char EffectType__13__Parameter__2__label[] = "Rate";
PROGMEM prog_char EffectType__13__Parameter__3__label[] = "LFO Type";
PROGMEM prog_char EffectType__13__Parameter__4__label[] = "Tempo";
PROGMEM prog_char EffectType__13__Parameter__5__label[] = "Depth";
PROGMEM prog_char EffectType__13__Parameter__6__label[] = "Feedback";
PROGMEM prog_char EffectType__13__Parameter__7__label[] = "Frequency Start";
PROGMEM prog_char EffectType__13__Parameter__8__label[] = "Frequency Span";
PROGMEM prog_char EffectType__13__Parameter__9__label[] = "LFO Phase";
PROGMEM prog_char EffectType__13__Parameter__10__label[] = "Bulb Bias";
PROGMEM prog_char EffectType__13__Parameter__11__label[] = "Mix";
PROGMEM prog_char EffectType__13__Parameter__12__label[] = "Level";
PROGMEM prog_char EffectType__13__Parameter__13__label[] = "Balance";
PROGMEM prog_char EffectType__13__Parameter__14__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__13__Parameter__15__label[] = "";
PROGMEM prog_char EffectType__13__Parameter__16__label[] = "";
PROGMEM prog_char EffectType__13__Parameter__17__label[] = "Vibe Mode";
PROGMEM prog_char EffectType__13__Parameter__18__label[] = "Fdbk Tap";
PROGMEM prog_char EffectType__13__Parameter__19__label[] = "Tone";
PROGMEM prog_char EffectType__14__Parameter__0__label[] = "Filter Type";
PROGMEM prog_char EffectType__14__Parameter__1__label[] = "Frequency Min";
PROGMEM prog_char EffectType__14__Parameter__2__label[] = "Frequency Max";
PROGMEM prog_char EffectType__14__Parameter__3__label[] = "Resonance";
PROGMEM prog_char EffectType__14__Parameter__4__label[] = "Tracking";
PROGMEM prog_char EffectType__14__Parameter__5__label[] = "Control";
PROGMEM prog_char EffectType__14__Parameter__6__label[] = "Level";
PROGMEM prog_char EffectType__14__Parameter__7__label[] = "Balance";
PROGMEM prog_char EffectType__14__Parameter__8__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__14__Parameter__9__label[] = "";
PROGMEM prog_char EffectType__14__Parameter__10__label[] = "Drive";
PROGMEM prog_char EffectType__14__Parameter__11__label[] = "";
PROGMEM prog_char EffectType__14__Parameter__12__label[] = "";
PROGMEM prog_char EffectType__15__Parameter__0__label[] = "Start";
PROGMEM prog_char EffectType__15__Parameter__1__label[] = "Mid";
PROGMEM prog_char EffectType__15__Parameter__2__label[] = "End";
PROGMEM prog_char EffectType__15__Parameter__3__label[] = "Resonance";
PROGMEM prog_char EffectType__15__Parameter__4__label[] = "Control";
PROGMEM prog_char EffectType__15__Parameter__5__label[] = "Mix";
PROGMEM prog_char EffectType__15__Parameter__6__label[] = "Level";
PROGMEM prog_char EffectType__15__Parameter__7__label[] = "Balance";
PROGMEM prog_char EffectType__15__Parameter__8__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__15__Parameter__9__label[] = "";
PROGMEM prog_char EffectType__15__Parameter__10__label[] = "";
PROGMEM prog_char EffectType__15__Parameter__11__label[] = "";
PROGMEM prog_char EffectType__16__Parameter__0__label[] = "";
PROGMEM prog_char EffectType__16__Parameter__1__label[] = "LFO Type";
PROGMEM prog_char EffectType__16__Parameter__2__label[] = "Rate";
PROGMEM prog_char EffectType__16__Parameter__3__label[] = "Depth";
PROGMEM prog_char EffectType__16__Parameter__4__label[] = "Duty";
PROGMEM prog_char EffectType__16__Parameter__5__label[] = "Tempo";
PROGMEM prog_char EffectType__16__Parameter__6__label[] = "";
PROGMEM prog_char EffectType__16__Parameter__7__label[] = "Level";
PROGMEM prog_char EffectType__16__Parameter__8__label[] = "Balance";
PROGMEM prog_char EffectType__16__Parameter__9__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__16__Parameter__10__label[] = "";
PROGMEM prog_char EffectType__16__Parameter__11__label[] = "LFO Phase";
PROGMEM prog_char EffectType__16__Parameter__12__label[] = "Width";
PROGMEM prog_char EffectType__16__Parameter__13__label[] = "Pan Center";
PROGMEM prog_char EffectType__16__Parameter__14__label[] = "";
PROGMEM prog_char EffectType__17__Parameter__0__label[] = "";
PROGMEM prog_char EffectType__17__Parameter__1__label[] = "Mode";
PROGMEM prog_char EffectType__17__Parameter__2__label[] = "Master Pitch";
PROGMEM prog_char EffectType__17__Parameter__3__label[] = "Control";
PROGMEM prog_char EffectType__17__Parameter__4__label[] = "Voice1 Harmony";
PROGMEM prog_char EffectType__17__Parameter__5__label[] = "Voice2 Harmony";
PROGMEM prog_char EffectType__17__Parameter__6__label[] = "Key";
PROGMEM prog_char EffectType__17__Parameter__7__label[] = "Scale";
PROGMEM prog_char EffectType__17__Parameter__8__label[] = "Track Mode";
PROGMEM prog_char EffectType__17__Parameter__9__label[] = "Voice1 Detune";
PROGMEM prog_char EffectType__17__Parameter__10__label[] = "Voice2 Detune";
PROGMEM prog_char EffectType__17__Parameter__11__label[] = "Start";
PROGMEM prog_char EffectType__17__Parameter__12__label[] = "Stop";
PROGMEM prog_char EffectType__17__Parameter__13__label[] = "Level 1";
PROGMEM prog_char EffectType__17__Parameter__14__label[] = "Level 2";
PROGMEM prog_char EffectType__17__Parameter__15__label[] = "Pan 1";
PROGMEM prog_char EffectType__17__Parameter__16__label[] = "Pan 2";
PROGMEM prog_char EffectType__17__Parameter__17__label[] = "Delay 1";
PROGMEM prog_char EffectType__17__Parameter__18__label[] = "Delay 2";
PROGMEM prog_char EffectType__17__Parameter__19__label[] = "Feedback 1";
PROGMEM prog_char EffectType__17__Parameter__20__label[] = "Feedback 2";
PROGMEM prog_char EffectType__17__Parameter__21__label[] = "Pitch track";
PROGMEM prog_char EffectType__17__Parameter__22__label[] = "Track Adjust";
PROGMEM prog_char EffectType__17__Parameter__23__label[] = "Mix";
PROGMEM prog_char EffectType__17__Parameter__24__label[] = "Level";
PROGMEM prog_char EffectType__17__Parameter__25__label[] = "Balance";
PROGMEM prog_char EffectType__17__Parameter__26__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__17__Parameter__27__label[] = "";
PROGMEM prog_char EffectType__17__Parameter__28__label[] = "Input Gain";
PROGMEM prog_char EffectType__17__Parameter__29__label[] = "";
PROGMEM prog_char EffectType__17__Parameter__30__label[] = "Crossfade";
PROGMEM prog_char EffectType__17__Parameter__31__label[] = "V1 Splice";
PROGMEM prog_char EffectType__17__Parameter__32__label[] = "V2 Splice";
PROGMEM prog_char EffectType__17__Parameter__33__label[] = "Tempo 1";
PROGMEM prog_char EffectType__17__Parameter__34__label[] = "Delay Tempo 2";
PROGMEM prog_char EffectType__17__Parameter__35__label[] = "Spltempo 1";
PROGMEM prog_char EffectType__17__Parameter__36__label[] = "Spltempo 2";
PROGMEM prog_char EffectType__17__Parameter__37__label[] = "Feedback type";
PROGMEM prog_char EffectType__17__Parameter__38__label[] = "Reverse";
PROGMEM prog_char EffectType__17__Parameter__39__label[] = "Hi Cut Frequency";
PROGMEM prog_char EffectType__17__Parameter__40__label[] = "Glide Time";
PROGMEM prog_char EffectType__17__Parameter__41__label[] = "Master Delay";
PROGMEM prog_char EffectType__17__Parameter__42__label[] = "Master Feedback";
PROGMEM prog_char EffectType__17__Parameter__43__label[] = "Master Pan";
PROGMEM prog_char EffectType__17__Parameter__44__label[] = "Master Level";
PROGMEM prog_char EffectType__17__Parameter__45__label[] = "Custom Notes";
PROGMEM prog_char EffectType__17__Parameter__46__label[] = "Note 2";
PROGMEM prog_char EffectType__17__Parameter__47__label[] = "Note 3";
PROGMEM prog_char EffectType__17__Parameter__48__label[] = "Note 4";
PROGMEM prog_char EffectType__17__Parameter__49__label[] = "Note 5";
PROGMEM prog_char EffectType__17__Parameter__50__label[] = "Note 6";
PROGMEM prog_char EffectType__17__Parameter__51__label[] = "Note 7";
PROGMEM prog_char EffectType__17__Parameter__52__label[] = "Note 8";
PROGMEM prog_char EffectType__17__Parameter__53__label[] = "Voice 1 Scale";
PROGMEM prog_char EffectType__17__Parameter__54__label[] = "Voice 2 Scale";
PROGMEM prog_char EffectType__17__Parameter__55__label[] = "Stages";
PROGMEM prog_char EffectType__17__Parameter__56__label[] = "Repeats";
PROGMEM prog_char EffectType__17__Parameter__57__label[] = "Run";
PROGMEM prog_char EffectType__17__Parameter__58__label[] = "Tempo";
PROGMEM prog_char EffectType__17__Parameter__59__label[] = "  Stage 1   Shift";
PROGMEM prog_char EffectType__17__Parameter__60__label[] = "  Stage 2   Shift";
PROGMEM prog_char EffectType__17__Parameter__61__label[] = "  Stage 3   Shift";
PROGMEM prog_char EffectType__17__Parameter__62__label[] = "  Stage 4   Shift";
PROGMEM prog_char EffectType__17__Parameter__63__label[] = "  Stage 5   Shift";
PROGMEM prog_char EffectType__17__Parameter__64__label[] = "  Stage 6   Shift";
PROGMEM prog_char EffectType__17__Parameter__65__label[] = "  Stage 7   Shift";
PROGMEM prog_char EffectType__17__Parameter__66__label[] = "  Stage 8   Shift";
PROGMEM prog_char EffectType__17__Parameter__67__label[] = "  Stage 9   Shift";
PROGMEM prog_char EffectType__17__Parameter__68__label[] = "  Stage 10  Shift";
PROGMEM prog_char EffectType__17__Parameter__69__label[] = "  Stage 11  Shift";
PROGMEM prog_char EffectType__17__Parameter__70__label[] = "  Stage 12  Shift";
PROGMEM prog_char EffectType__17__Parameter__71__label[] = "  Stage 13  Shift";
PROGMEM prog_char EffectType__17__Parameter__72__label[] = "  Stage 14  Shift";
PROGMEM prog_char EffectType__17__Parameter__73__label[] = "  Stage 15  Shift";
PROGMEM prog_char EffectType__17__Parameter__74__label[] = "  Stage 16  Shift";
PROGMEM prog_char EffectType__17__Parameter__75__label[] = "Amplitude Shape";
PROGMEM prog_char EffectType__17__Parameter__76__label[] = "Amplitude Alpha";
PROGMEM prog_char EffectType__17__Parameter__77__label[] = "Pan Shape";
PROGMEM prog_char EffectType__17__Parameter__78__label[] = "Pan Alpha";
PROGMEM prog_char EffectType__17__Parameter__79__label[] = "Delay 1";
PROGMEM prog_char EffectType__17__Parameter__80__label[] = "Delay 2";
PROGMEM prog_char EffectType__17__Parameter__81__label[] = "Pitch Source";
PROGMEM prog_char EffectType__17__Parameter__82__label[] = "Input Mode";
PROGMEM prog_char EffectType__17__Parameter__83__label[] = "Learn";
PROGMEM prog_char EffectType__17__Parameter__84__label[] = "Low Cut Frequency";
PROGMEM prog_char EffectType__18__Parameter__0__label[] = "Type";
PROGMEM prog_char EffectType__18__Parameter__1__label[] = "Frequency";
PROGMEM prog_char EffectType__18__Parameter__2__label[] = "Q";
PROGMEM prog_char EffectType__18__Parameter__3__label[] = "Gain";
PROGMEM prog_char EffectType__18__Parameter__4__label[] = "Level";
PROGMEM prog_char EffectType__18__Parameter__5__label[] = "Balance";
PROGMEM prog_char EffectType__18__Parameter__6__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__18__Parameter__7__label[] = "Order";
PROGMEM prog_char EffectType__18__Parameter__8__label[] = "";
PROGMEM prog_char EffectType__18__Parameter__9__label[] = "Pan Left";
PROGMEM prog_char EffectType__18__Parameter__10__label[] = "Pan Right";
PROGMEM prog_char EffectType__18__Parameter__11__label[] = "Invert";
PROGMEM prog_char EffectType__18__Parameter__12__label[] = "Lowcut";
PROGMEM prog_char EffectType__18__Parameter__13__label[] = "Hicut";
PROGMEM prog_char EffectType__19__Parameter__0__label[] = "";
PROGMEM prog_char EffectType__19__Parameter__1__label[] = "Drive";
PROGMEM prog_char EffectType__19__Parameter__2__label[] = "Tone";
PROGMEM prog_char EffectType__19__Parameter__3__label[] = "Level";
PROGMEM prog_char EffectType__19__Parameter__4__label[] = "Mix";
PROGMEM prog_char EffectType__19__Parameter__5__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__19__Parameter__6__label[] = "Slew Limit";
PROGMEM prog_char EffectType__19__Parameter__7__label[] = "";
PROGMEM prog_char EffectType__19__Parameter__8__label[] = "Low Cut";
PROGMEM prog_char EffectType__19__Parameter__9__label[] = "High Cut";
PROGMEM prog_char EffectType__19__Parameter__10__label[] = "Clip Type";
PROGMEM prog_char EffectType__19__Parameter__11__label[] = "Bias";
PROGMEM prog_char EffectType__19__Parameter__12__label[] = "Bass";
PROGMEM prog_char EffectType__19__Parameter__13__label[] = "Mid";
PROGMEM prog_char EffectType__19__Parameter__14__label[] = "Mid Freq";
PROGMEM prog_char EffectType__19__Parameter__15__label[] = "Treble";
PROGMEM prog_char EffectType__19__Parameter__16__label[] = "Bit Reduce";
PROGMEM prog_char EffectType__19__Parameter__17__label[] = "Input Select";
PROGMEM prog_char EffectType__19__Parameter__18__label[] = "Balance";
PROGMEM prog_char EffectType__19__Parameter__19__label[] = "Sample Rate";
PROGMEM prog_char EffectType__20__Parameter__0__label[] = "Width";
PROGMEM prog_char EffectType__20__Parameter__1__label[] = "Depth";
PROGMEM prog_char EffectType__20__Parameter__2__label[] = "Low cut";
PROGMEM prog_char EffectType__20__Parameter__3__label[] = "High Cut";
PROGMEM prog_char EffectType__20__Parameter__4__label[] = "Level";
PROGMEM prog_char EffectType__20__Parameter__5__label[] = "";
PROGMEM prog_char EffectType__20__Parameter__6__label[] = "";
PROGMEM prog_char EffectType__20__Parameter__7__label[] = "Invert";
PROGMEM prog_char EffectType__20__Parameter__8__label[] = "Pan Left";
PROGMEM prog_char EffectType__20__Parameter__9__label[] = "Pan Right";
PROGMEM prog_char EffectType__20__Parameter__10__label[] = "Balance";
PROGMEM prog_char EffectType__21__Parameter__0__label[] = "Level 1";
PROGMEM prog_char EffectType__21__Parameter__1__label[] = "Level 2";
PROGMEM prog_char EffectType__21__Parameter__2__label[] = "Level 3";
PROGMEM prog_char EffectType__21__Parameter__3__label[] = "Level 4";
PROGMEM prog_char EffectType__21__Parameter__4__label[] = "Pan 1";
PROGMEM prog_char EffectType__21__Parameter__5__label[] = "Pan 2";
PROGMEM prog_char EffectType__21__Parameter__6__label[] = "Pan 3";
PROGMEM prog_char EffectType__21__Parameter__7__label[] = "Pan 4";
PROGMEM prog_char EffectType__21__Parameter__8__label[] = "";
PROGMEM prog_char EffectType__21__Parameter__9__label[] = "";
PROGMEM prog_char EffectType__21__Parameter__10__label[] = "";
PROGMEM prog_char EffectType__21__Parameter__11__label[] = "";
PROGMEM prog_char EffectType__21__Parameter__12__label[] = "";
PROGMEM prog_char EffectType__21__Parameter__13__label[] = "";
PROGMEM prog_char EffectType__21__Parameter__14__label[] = "";
PROGMEM prog_char EffectType__21__Parameter__15__label[] = "";
PROGMEM prog_char EffectType__21__Parameter__16__label[] = "Level";
PROGMEM prog_char EffectType__21__Parameter__17__label[] = "Balance";
PROGMEM prog_char EffectType__21__Parameter__18__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__21__Parameter__19__label[] = "";
PROGMEM prog_char EffectType__22__Parameter__0__label[] = "Gain 1";
PROGMEM prog_char EffectType__22__Parameter__1__label[] = "Gain 2";
PROGMEM prog_char EffectType__22__Parameter__2__label[] = "Gain 3";
PROGMEM prog_char EffectType__22__Parameter__3__label[] = "Gain 4";
PROGMEM prog_char EffectType__22__Parameter__4__label[] = "Balance 1";
PROGMEM prog_char EffectType__22__Parameter__5__label[] = "Balance 2";
PROGMEM prog_char EffectType__22__Parameter__6__label[] = "Balance 3";
PROGMEM prog_char EffectType__22__Parameter__7__label[] = "Balance 4";
PROGMEM prog_char EffectType__22__Parameter__8__label[] = "Master level";
PROGMEM prog_char EffectType__22__Parameter__9__label[] = "Output mode";
PROGMEM prog_char EffectType__23__Parameter__0__label[] = "";
PROGMEM prog_char EffectType__23__Parameter__1__label[] = "";
PROGMEM prog_char EffectType__24__Parameter__0__label[] = "";
PROGMEM prog_char EffectType__24__Parameter__1__label[] = "";
PROGMEM prog_char EffectType__24__Parameter__2__label[] = "";
PROGMEM prog_char EffectType__24__Parameter__3__label[] = "";
PROGMEM prog_char EffectType__24__Parameter__4__label[] = "";
PROGMEM prog_char EffectType__24__Parameter__5__label[] = "";
PROGMEM prog_char EffectType__25__Parameter__0__label[] = "Type";
PROGMEM prog_char EffectType__25__Parameter__1__label[] = "Frequency";
PROGMEM prog_char EffectType__25__Parameter__2__label[] = "Track";
PROGMEM prog_char EffectType__25__Parameter__3__label[] = "Shift";
PROGMEM prog_char EffectType__25__Parameter__4__label[] = "Tune";
PROGMEM prog_char EffectType__25__Parameter__5__label[] = "Duty";
PROGMEM prog_char EffectType__25__Parameter__6__label[] = "Voice 1  Level";
PROGMEM prog_char EffectType__25__Parameter__7__label[] = "Voice 1    Pan";
PROGMEM prog_char EffectType__25__Parameter__8__label[] = "Attack";
PROGMEM prog_char EffectType__25__Parameter__9__label[] = "Filter";
PROGMEM prog_char EffectType__25__Parameter__10__label[] = "Q";
PROGMEM prog_char EffectType__25__Parameter__11__label[] = "Type";
PROGMEM prog_char EffectType__25__Parameter__12__label[] = "Frequency";
PROGMEM prog_char EffectType__25__Parameter__13__label[] = "Track";
PROGMEM prog_char EffectType__25__Parameter__14__label[] = "Shift";
PROGMEM prog_char EffectType__25__Parameter__15__label[] = "Tune";
PROGMEM prog_char EffectType__25__Parameter__16__label[] = "Duty";
PROGMEM prog_char EffectType__25__Parameter__17__label[] = "Voice 2  Level";
PROGMEM prog_char EffectType__25__Parameter__18__label[] = "Voice 2    Pan";
PROGMEM prog_char EffectType__25__Parameter__19__label[] = "Attack";
PROGMEM prog_char EffectType__25__Parameter__20__label[] = "Filter";
PROGMEM prog_char EffectType__25__Parameter__21__label[] = "Q";
PROGMEM prog_char EffectType__25__Parameter__22__label[] = "";
PROGMEM prog_char EffectType__25__Parameter__23__label[] = "Mix";
PROGMEM prog_char EffectType__25__Parameter__24__label[] = "Level";
PROGMEM prog_char EffectType__25__Parameter__25__label[] = "Pan";
PROGMEM prog_char EffectType__25__Parameter__26__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__25__Parameter__27__label[] = "";
PROGMEM prog_char EffectType__25__Parameter__28__label[] = "";
PROGMEM prog_char EffectType__25__Parameter__29__label[] = "Type";
PROGMEM prog_char EffectType__25__Parameter__30__label[] = "Frequency";
PROGMEM prog_char EffectType__25__Parameter__31__label[] = "Track";
PROGMEM prog_char EffectType__25__Parameter__32__label[] = "Shift";
PROGMEM prog_char EffectType__25__Parameter__33__label[] = "Tune";
PROGMEM prog_char EffectType__25__Parameter__34__label[] = "Duty";
PROGMEM prog_char EffectType__25__Parameter__35__label[] = "Voice 3  Level";
PROGMEM prog_char EffectType__25__Parameter__36__label[] = "Voice 3    Pan";
PROGMEM prog_char EffectType__25__Parameter__37__label[] = "Attack";
PROGMEM prog_char EffectType__25__Parameter__38__label[] = "Filter";
PROGMEM prog_char EffectType__25__Parameter__39__label[] = "Q";
PROGMEM prog_char EffectType__26__Parameter__0__label[] = "Input Select (Carrier)";
PROGMEM prog_char EffectType__26__Parameter__1__label[] = "Bands";
PROGMEM prog_char EffectType__26__Parameter__2__label[] = "Frequency Min";
PROGMEM prog_char EffectType__26__Parameter__3__label[] = "Frequency Max ";
PROGMEM prog_char EffectType__26__Parameter__4__label[] = "Shift";
PROGMEM prog_char EffectType__26__Parameter__5__label[] = "Freeze";
PROGMEM prog_char EffectType__26__Parameter__6__label[] = "Master Level";
PROGMEM prog_char EffectType__26__Parameter__7__label[] = "Master Pan";
PROGMEM prog_char EffectType__26__Parameter__8__label[] = "Resonance";
PROGMEM prog_char EffectType__26__Parameter__9__label[] = "Attack";
PROGMEM prog_char EffectType__26__Parameter__10__label[] = "Release";
PROGMEM prog_char EffectType__26__Parameter__11__label[] = "Highpass Mix In";
PROGMEM prog_char EffectType__26__Parameter__12__label[] = "Mix";
PROGMEM prog_char EffectType__26__Parameter__13__label[] = "Level";
PROGMEM prog_char EffectType__26__Parameter__14__label[] = "Balance";
PROGMEM prog_char EffectType__26__Parameter__15__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__26__Parameter__16__label[] = "";
PROGMEM prog_char EffectType__26__Parameter__17__label[] = "1";
PROGMEM prog_char EffectType__26__Parameter__18__label[] = "2";
PROGMEM prog_char EffectType__26__Parameter__19__label[] = "3";
PROGMEM prog_char EffectType__26__Parameter__20__label[] = "4";
PROGMEM prog_char EffectType__26__Parameter__21__label[] = "5";
PROGMEM prog_char EffectType__26__Parameter__22__label[] = "6";
PROGMEM prog_char EffectType__26__Parameter__23__label[] = "7";
PROGMEM prog_char EffectType__26__Parameter__24__label[] = "8";
PROGMEM prog_char EffectType__26__Parameter__25__label[] = "9";
PROGMEM prog_char EffectType__26__Parameter__26__label[] = "10";
PROGMEM prog_char EffectType__26__Parameter__27__label[] = "11";
PROGMEM prog_char EffectType__26__Parameter__28__label[] = "12";
PROGMEM prog_char EffectType__26__Parameter__29__label[] = "13";
PROGMEM prog_char EffectType__26__Parameter__30__label[] = "14";
PROGMEM prog_char EffectType__26__Parameter__31__label[] = "15";
PROGMEM prog_char EffectType__26__Parameter__32__label[] = "16";
PROGMEM prog_char EffectType__26__Parameter__33__label[] = "Pan 1";
PROGMEM prog_char EffectType__26__Parameter__34__label[] = "Pan 2";
PROGMEM prog_char EffectType__26__Parameter__35__label[] = "Pan 3";
PROGMEM prog_char EffectType__26__Parameter__36__label[] = "Pan 4";
PROGMEM prog_char EffectType__26__Parameter__37__label[] = "Pan 5";
PROGMEM prog_char EffectType__26__Parameter__38__label[] = "Pan 6";
PROGMEM prog_char EffectType__26__Parameter__39__label[] = "Pan 7";
PROGMEM prog_char EffectType__26__Parameter__40__label[] = "Pan 8";
PROGMEM prog_char EffectType__26__Parameter__41__label[] = "Pan 9";
PROGMEM prog_char EffectType__26__Parameter__42__label[] = "Pan 10";
PROGMEM prog_char EffectType__26__Parameter__43__label[] = "Pan 11";
PROGMEM prog_char EffectType__26__Parameter__44__label[] = "Pan 12";
PROGMEM prog_char EffectType__26__Parameter__45__label[] = "Pan 13";
PROGMEM prog_char EffectType__26__Parameter__46__label[] = "Pan 14";
PROGMEM prog_char EffectType__26__Parameter__47__label[] = "Pan 15";
PROGMEM prog_char EffectType__26__Parameter__48__label[] = "Pan 16";
PROGMEM prog_char EffectType__26__Parameter__49__label[] = "";
PROGMEM prog_char EffectType__27__Parameter__0__label[] = "In Gain";
PROGMEM prog_char EffectType__27__Parameter__1__label[] = "Master level";
PROGMEM prog_char EffectType__27__Parameter__2__label[] = "Time";
PROGMEM prog_char EffectType__27__Parameter__3__label[] = "Number of Taps";
PROGMEM prog_char EffectType__27__Parameter__4__label[] = "Time Shape";
PROGMEM prog_char EffectType__27__Parameter__5__label[] = "Time Alpha";
PROGMEM prog_char EffectType__27__Parameter__6__label[] = "Amplitude shape";
PROGMEM prog_char EffectType__27__Parameter__7__label[] = "Amplitude Alpha";
PROGMEM prog_char EffectType__27__Parameter__8__label[] = "Pan Shape";
PROGMEM prog_char EffectType__27__Parameter__9__label[] = "Pan Alpha";
PROGMEM prog_char EffectType__27__Parameter__10__label[] = "Time Randomize";
PROGMEM prog_char EffectType__27__Parameter__11__label[] = "Mix";
PROGMEM prog_char EffectType__27__Parameter__12__label[] = "Level";
PROGMEM prog_char EffectType__27__Parameter__13__label[] = "Balance";
PROGMEM prog_char EffectType__27__Parameter__14__label[] = "Bypassmode";
PROGMEM prog_char EffectType__27__Parameter__15__label[] = "";
PROGMEM prog_char EffectType__27__Parameter__16__label[] = "";
PROGMEM prog_char EffectType__28__Parameter__0__label[] = "Freq";
PROGMEM prog_char EffectType__28__Parameter__1__label[] = "Freq Multiplier";
PROGMEM prog_char EffectType__28__Parameter__2__label[] = "Lo Level L";
PROGMEM prog_char EffectType__28__Parameter__3__label[] = "Hi level L";
PROGMEM prog_char EffectType__28__Parameter__4__label[] = "Lo Level R";
PROGMEM prog_char EffectType__28__Parameter__5__label[] = "Hi Level R";
PROGMEM prog_char EffectType__28__Parameter__6__label[] = "Lo Pan L";
PROGMEM prog_char EffectType__28__Parameter__7__label[] = "Hi Pan L";
PROGMEM prog_char EffectType__28__Parameter__8__label[] = "Lo Pan R";
PROGMEM prog_char EffectType__28__Parameter__9__label[] = "Hi Pan R";
PROGMEM prog_char EffectType__28__Parameter__10__label[] = "";
PROGMEM prog_char EffectType__28__Parameter__11__label[] = "Level";
PROGMEM prog_char EffectType__28__Parameter__12__label[] = "Balance";
PROGMEM prog_char EffectType__28__Parameter__13__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__28__Parameter__14__label[] = "";
PROGMEM prog_char EffectType__29__Parameter__0__label[] = "Threhold";
PROGMEM prog_char EffectType__29__Parameter__1__label[] = "Attack";
PROGMEM prog_char EffectType__29__Parameter__2__label[] = "Hold";
PROGMEM prog_char EffectType__29__Parameter__3__label[] = "Release";
PROGMEM prog_char EffectType__29__Parameter__4__label[] = "Ratio";
PROGMEM prog_char EffectType__29__Parameter__5__label[] = "Sidechain Select";
PROGMEM prog_char EffectType__29__Parameter__6__label[] = "Low Cut";
PROGMEM prog_char EffectType__29__Parameter__7__label[] = "High Cut";
PROGMEM prog_char EffectType__29__Parameter__8__label[] = "";
PROGMEM prog_char EffectType__29__Parameter__9__label[] = "Level";
PROGMEM prog_char EffectType__29__Parameter__10__label[] = "Balance";
PROGMEM prog_char EffectType__29__Parameter__11__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__29__Parameter__12__label[] = "";
PROGMEM prog_char EffectType__30__Parameter__0__label[] = "Frequency";
PROGMEM prog_char EffectType__30__Parameter__1__label[] = "Frequency multiplier";
PROGMEM prog_char EffectType__30__Parameter__2__label[] = "Track";
PROGMEM prog_char EffectType__30__Parameter__3__label[] = "High Cut";
PROGMEM prog_char EffectType__30__Parameter__4__label[] = "Mix";
PROGMEM prog_char EffectType__30__Parameter__5__label[] = "Level";
PROGMEM prog_char EffectType__30__Parameter__6__label[] = "Balance";
PROGMEM prog_char EffectType__30__Parameter__7__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__30__Parameter__8__label[] = "Global Mix";
PROGMEM prog_char EffectType__30__Parameter__9__label[] = "";
PROGMEM prog_char EffectType__31__Parameter__0__label[] = "Frequency 1";
PROGMEM prog_char EffectType__31__Parameter__1__label[] = "Frequency 2";
PROGMEM prog_char EffectType__31__Parameter__2__label[] = "Thresh 1";
PROGMEM prog_char EffectType__31__Parameter__3__label[] = "Ratio 1";
PROGMEM prog_char EffectType__31__Parameter__4__label[] = "Attack 1";
PROGMEM prog_char EffectType__31__Parameter__5__label[] = "Release 1";
PROGMEM prog_char EffectType__31__Parameter__6__label[] = "Level 1";
PROGMEM prog_char EffectType__31__Parameter__7__label[] = "Detect 1";
PROGMEM prog_char EffectType__31__Parameter__8__label[] = "Mute 1";
PROGMEM prog_char EffectType__31__Parameter__9__label[] = "Thresh 2";
PROGMEM prog_char EffectType__31__Parameter__10__label[] = "Ratio 2";
PROGMEM prog_char EffectType__31__Parameter__11__label[] = "Attack 2";
PROGMEM prog_char EffectType__31__Parameter__12__label[] = "Release 2";
PROGMEM prog_char EffectType__31__Parameter__13__label[] = "Level 2";
PROGMEM prog_char EffectType__31__Parameter__14__label[] = "Detect 2";
PROGMEM prog_char EffectType__31__Parameter__15__label[] = "Mute 2";
PROGMEM prog_char EffectType__31__Parameter__16__label[] = "Thresh 3";
PROGMEM prog_char EffectType__31__Parameter__17__label[] = "Ratio 3";
PROGMEM prog_char EffectType__31__Parameter__18__label[] = "Attack 3";
PROGMEM prog_char EffectType__31__Parameter__19__label[] = "Release 3";
PROGMEM prog_char EffectType__31__Parameter__20__label[] = "Level 3";
PROGMEM prog_char EffectType__31__Parameter__21__label[] = "Detect 3";
PROGMEM prog_char EffectType__31__Parameter__22__label[] = "Mute 3";
PROGMEM prog_char EffectType__31__Parameter__23__label[] = "";
PROGMEM prog_char EffectType__31__Parameter__24__label[] = "Level";
PROGMEM prog_char EffectType__31__Parameter__25__label[] = "Balance";
PROGMEM prog_char EffectType__31__Parameter__26__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__31__Parameter__27__label[] = "";
PROGMEM prog_char EffectType__32__Parameter__0__label[] = "Mstr Time";
PROGMEM prog_char EffectType__32__Parameter__1__label[] = "Mstr Level";
PROGMEM prog_char EffectType__32__Parameter__2__label[] = "Mstr Pan";
PROGMEM prog_char EffectType__32__Parameter__3__label[] = "Mstr Rate";
PROGMEM prog_char EffectType__32__Parameter__4__label[] = "Mstr Depth";
PROGMEM prog_char EffectType__32__Parameter__5__label[] = "Feedback";
PROGMEM prog_char EffectType__32__Parameter__6__label[] = "Time 1";
PROGMEM prog_char EffectType__32__Parameter__7__label[] = "Time 2";
PROGMEM prog_char EffectType__32__Parameter__8__label[] = "Time 3";
PROGMEM prog_char EffectType__32__Parameter__9__label[] = "Time 4";
PROGMEM prog_char EffectType__32__Parameter__10__label[] = "Level 1";
PROGMEM prog_char EffectType__32__Parameter__11__label[] = "Level 2";
PROGMEM prog_char EffectType__32__Parameter__12__label[] = "Level 3";
PROGMEM prog_char EffectType__32__Parameter__13__label[] = "Level 4";
PROGMEM prog_char EffectType__32__Parameter__14__label[] = "Pan 1";
PROGMEM prog_char EffectType__32__Parameter__15__label[] = "Pan 2";
PROGMEM prog_char EffectType__32__Parameter__16__label[] = "Pan 3";
PROGMEM prog_char EffectType__32__Parameter__17__label[] = "Pan 4";
PROGMEM prog_char EffectType__32__Parameter__18__label[] = "Depth 1 (From Morph)";
PROGMEM prog_char EffectType__32__Parameter__19__label[] = "Depth 2 (From Morph)";
PROGMEM prog_char EffectType__32__Parameter__20__label[] = "Depth 3 (From Morph)";
PROGMEM prog_char EffectType__32__Parameter__21__label[] = "Depth 4 (From Morph)";
PROGMEM prog_char EffectType__32__Parameter__22__label[] = "Morph1 (LFO1/2/3)";
PROGMEM prog_char EffectType__32__Parameter__23__label[] = "Morph2 (LFO1/2/3)";
PROGMEM prog_char EffectType__32__Parameter__24__label[] = "Morph3 (LFO1/2/3)";
PROGMEM prog_char EffectType__32__Parameter__25__label[] = "Morph4 (LFO1/2/3)";
PROGMEM prog_char EffectType__32__Parameter__26__label[] = "LFO1 Type";
PROGMEM prog_char EffectType__32__Parameter__27__label[] = "LFO2 Type";
PROGMEM prog_char EffectType__32__Parameter__28__label[] = "LFO3 Type";
PROGMEM prog_char EffectType__32__Parameter__29__label[] = "LFO4 Type";
PROGMEM prog_char EffectType__32__Parameter__30__label[] = "LFO1 Rate Multiplier";
PROGMEM prog_char EffectType__32__Parameter__31__label[] = "LFO2 Rate Multiplier";
PROGMEM prog_char EffectType__32__Parameter__32__label[] = "LFO3 Rate Multiplier";
PROGMEM prog_char EffectType__32__Parameter__33__label[] = "LFO4 Rate Multiplier";
PROGMEM prog_char EffectType__32__Parameter__34__label[] = "Main Depth (LFO4>ALL)";
PROGMEM prog_char EffectType__32__Parameter__35__label[] = "Input Mode";
PROGMEM prog_char EffectType__32__Parameter__36__label[] = "LFO1 Master";
PROGMEM prog_char EffectType__32__Parameter__37__label[] = "Wide Mode";
PROGMEM prog_char EffectType__32__Parameter__38__label[] = "Main Phase (LFO4)";
PROGMEM prog_char EffectType__32__Parameter__39__label[] = "Mix";
PROGMEM prog_char EffectType__32__Parameter__40__label[] = "Level";
PROGMEM prog_char EffectType__32__Parameter__41__label[] = "Balance";
PROGMEM prog_char EffectType__32__Parameter__42__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__32__Parameter__43__label[] = "";
PROGMEM prog_char EffectType__32__Parameter__44__label[] = "";
PROGMEM prog_char EffectType__32__Parameter__45__label[] = "Hi Cut Frequency";
PROGMEM prog_char EffectType__33__Parameter__0__label[] = "";
PROGMEM prog_char EffectType__33__Parameter__1__label[] = "Chord Type";
PROGMEM prog_char EffectType__33__Parameter__2__label[] = "Input Gain";
PROGMEM prog_char EffectType__33__Parameter__3__label[] = "Frequency";
PROGMEM prog_char EffectType__33__Parameter__4__label[] = "Master Frequency";
PROGMEM prog_char EffectType__33__Parameter__5__label[] = "Master Level";
PROGMEM prog_char EffectType__33__Parameter__6__label[] = "Master Pan";
PROGMEM prog_char EffectType__33__Parameter__7__label[] = "Master Feedback";
PROGMEM prog_char EffectType__33__Parameter__8__label[] = "Master Q";
PROGMEM prog_char EffectType__33__Parameter__9__label[] = "Freq  1";
PROGMEM prog_char EffectType__33__Parameter__10__label[] = "Freq  2";
PROGMEM prog_char EffectType__33__Parameter__11__label[] = "Freq  3";
PROGMEM prog_char EffectType__33__Parameter__12__label[] = "Freq  4";
PROGMEM prog_char EffectType__33__Parameter__13__label[] = "FB 1";
PROGMEM prog_char EffectType__33__Parameter__14__label[] = "FB 2";
PROGMEM prog_char EffectType__33__Parameter__15__label[] = "FB 3";
PROGMEM prog_char EffectType__33__Parameter__16__label[] = "FB 4";
PROGMEM prog_char EffectType__33__Parameter__17__label[] = "Filter Loc 1";
PROGMEM prog_char EffectType__33__Parameter__18__label[] = "Filter Loc 2";
PROGMEM prog_char EffectType__33__Parameter__19__label[] = "Filter Loc 3";
PROGMEM prog_char EffectType__33__Parameter__20__label[] = "Filter Loc 4";
PROGMEM prog_char EffectType__33__Parameter__21__label[] = "Q 1";
PROGMEM prog_char EffectType__33__Parameter__22__label[] = "Q 2";
PROGMEM prog_char EffectType__33__Parameter__23__label[] = "Q 3";
PROGMEM prog_char EffectType__33__Parameter__24__label[] = "Q 4";
PROGMEM prog_char EffectType__33__Parameter__25__label[] = "Level 1";
PROGMEM prog_char EffectType__33__Parameter__26__label[] = "Level 2";
PROGMEM prog_char EffectType__33__Parameter__27__label[] = "Level 3";
PROGMEM prog_char EffectType__33__Parameter__28__label[] = "Level 4";
PROGMEM prog_char EffectType__33__Parameter__29__label[] = "Pan 1";
PROGMEM prog_char EffectType__33__Parameter__30__label[] = "Pan 2";
PROGMEM prog_char EffectType__33__Parameter__31__label[] = "Pan 3";
PROGMEM prog_char EffectType__33__Parameter__32__label[] = "Pan 4";
PROGMEM prog_char EffectType__33__Parameter__33__label[] = "Mix";
PROGMEM prog_char EffectType__33__Parameter__34__label[] = "Level";
PROGMEM prog_char EffectType__33__Parameter__35__label[] = "Balance";
PROGMEM prog_char EffectType__33__Parameter__36__label[] = "Bypassmode";
PROGMEM prog_char EffectType__33__Parameter__37__label[] = "";
PROGMEM prog_char EffectType__33__Parameter__38__label[] = "";
PROGMEM prog_char EffectType__33__Parameter__39__label[] = "Input Mode";
PROGMEM prog_char EffectType__34__Parameter__0__label[] = "Volume";
PROGMEM prog_char EffectType__34__Parameter__1__label[] = "Balance";
PROGMEM prog_char EffectType__34__Parameter__2__label[] = "Volume Taper";
PROGMEM prog_char EffectType__34__Parameter__3__label[] = "";
PROGMEM prog_char EffectType__34__Parameter__4__label[] = "Pan Left";
PROGMEM prog_char EffectType__34__Parameter__5__label[] = "Pan Right";
PROGMEM prog_char EffectType__34__Parameter__6__label[] = "Level";
PROGMEM prog_char EffectType__34__Parameter__7__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__34__Parameter__8__label[] = "Input Select";
PROGMEM prog_char EffectType__35__Parameter__0__label[] = "Threshold";
PROGMEM prog_char EffectType__35__Parameter__1__label[] = "Ratio";
PROGMEM prog_char EffectType__35__Parameter__2__label[] = "Release";
PROGMEM prog_char EffectType__35__Parameter__3__label[] = "Attack";
PROGMEM prog_char EffectType__35__Parameter__4__label[] = "Input Z";
PROGMEM prog_char EffectType__36__Parameter__0__label[] = "Level 1";
PROGMEM prog_char EffectType__36__Parameter__1__label[] = "Level 2";
PROGMEM prog_char EffectType__36__Parameter__2__label[] = "Level 3";
PROGMEM prog_char EffectType__36__Parameter__3__label[] = "Level 4";
PROGMEM prog_char EffectType__36__Parameter__4__label[] = "Balance 1";
PROGMEM prog_char EffectType__36__Parameter__5__label[] = "Balance 2";
PROGMEM prog_char EffectType__36__Parameter__6__label[] = "Balance 3";
PROGMEM prog_char EffectType__36__Parameter__7__label[] = "Balance 4";
PROGMEM prog_char EffectType__36__Parameter__8__label[] = "";
PROGMEM prog_char EffectType__36__Parameter__9__label[] = "";
PROGMEM prog_char EffectType__36__Parameter__10__label[] = "";
PROGMEM prog_char EffectType__36__Parameter__11__label[] = "";
PROGMEM prog_char EffectType__36__Parameter__12__label[] = "";
PROGMEM prog_char EffectType__36__Parameter__13__label[] = "";
PROGMEM prog_char EffectType__36__Parameter__14__label[] = "";
PROGMEM prog_char EffectType__36__Parameter__15__label[] = "";
PROGMEM prog_char EffectType__36__Parameter__16__label[] = "";
PROGMEM prog_char EffectType__36__Parameter__17__label[] = "";
PROGMEM prog_char EffectType__36__Parameter__18__label[] = "";
PROGMEM prog_char EffectType__36__Parameter__19__label[] = "";
PROGMEM prog_char EffectType__37__Parameter__0__label[] = "LFO1 Type (Run)";
PROGMEM prog_char EffectType__37__Parameter__1__label[] = "LFO1 Rate";
PROGMEM prog_char EffectType__37__Parameter__2__label[] = "LFO1 Depth";
PROGMEM prog_char EffectType__37__Parameter__3__label[] = "LFO1 Duty";
PROGMEM prog_char EffectType__37__Parameter__4__label[] = "Output B Phase";
PROGMEM prog_char EffectType__37__Parameter__5__label[] = "LFO1 Tempo";
PROGMEM prog_char EffectType__37__Parameter__6__label[] = "LFO2 Type (Run)";
PROGMEM prog_char EffectType__37__Parameter__7__label[] = "LFO2 Rate";
PROGMEM prog_char EffectType__37__Parameter__8__label[] = "LFO2 Depth";
PROGMEM prog_char EffectType__37__Parameter__9__label[] = "LFO2 Duty";
PROGMEM prog_char EffectType__37__Parameter__10__label[] = "Output B Phase";
PROGMEM prog_char EffectType__37__Parameter__11__label[] = "LFO2 Tempo";
PROGMEM prog_char EffectType__37__Parameter__12__label[] = "Mode";
PROGMEM prog_char EffectType__37__Parameter__13__label[] = "Retrig";
PROGMEM prog_char EffectType__37__Parameter__14__label[] = "Attack";
PROGMEM prog_char EffectType__37__Parameter__15__label[] = "Decay";
PROGMEM prog_char EffectType__37__Parameter__16__label[] = "Sustain";
PROGMEM prog_char EffectType__37__Parameter__17__label[] = "Level";
PROGMEM prog_char EffectType__37__Parameter__18__label[] = "Release";
PROGMEM prog_char EffectType__37__Parameter__19__label[] = "Threshold";
PROGMEM prog_char EffectType__37__Parameter__20__label[] = "Mode";
PROGMEM prog_char EffectType__37__Parameter__21__label[] = "Retrig";
PROGMEM prog_char EffectType__37__Parameter__22__label[] = "Attack";
PROGMEM prog_char EffectType__37__Parameter__23__label[] = "Decay";
PROGMEM prog_char EffectType__37__Parameter__24__label[] = "Sustain";
PROGMEM prog_char EffectType__37__Parameter__25__label[] = "Level";
PROGMEM prog_char EffectType__37__Parameter__26__label[] = "Release";
PROGMEM prog_char EffectType__37__Parameter__27__label[] = "Threshold";
PROGMEM prog_char EffectType__37__Parameter__28__label[] = "Attack";
PROGMEM prog_char EffectType__37__Parameter__29__label[] = "Release";
PROGMEM prog_char EffectType__37__Parameter__30__label[] = "Threshold";
PROGMEM prog_char EffectType__37__Parameter__31__label[] = "Gain";
PROGMEM prog_char EffectType__37__Parameter__32__label[] = "";
PROGMEM prog_char EffectType__37__Parameter__33__label[] = "";
PROGMEM prog_char EffectType__37__Parameter__34__label[] = "Rate";
PROGMEM prog_char EffectType__37__Parameter__35__label[] = "Tempo";
PROGMEM prog_char EffectType__37__Parameter__36__label[] = "Stages";
PROGMEM prog_char EffectType__37__Parameter__37__label[] = "Stage 1";
PROGMEM prog_char EffectType__37__Parameter__38__label[] = "Stage 2";
PROGMEM prog_char EffectType__37__Parameter__39__label[] = "Stage 3";
PROGMEM prog_char EffectType__37__Parameter__40__label[] = "Stage 4";
PROGMEM prog_char EffectType__37__Parameter__41__label[] = "Stage 5";
PROGMEM prog_char EffectType__37__Parameter__42__label[] = "Stage 6";
PROGMEM prog_char EffectType__37__Parameter__43__label[] = "Stage 7";
PROGMEM prog_char EffectType__37__Parameter__44__label[] = "Stage 8";
PROGMEM prog_char EffectType__37__Parameter__45__label[] = "Stage 9";
PROGMEM prog_char EffectType__37__Parameter__46__label[] = "Stage 10";
PROGMEM prog_char EffectType__37__Parameter__47__label[] = "Stage 11";
PROGMEM prog_char EffectType__37__Parameter__48__label[] = "Stage 12";
PROGMEM prog_char EffectType__37__Parameter__49__label[] = "Stage 13";
PROGMEM prog_char EffectType__37__Parameter__50__label[] = "Stage 14";
PROGMEM prog_char EffectType__37__Parameter__51__label[] = "Stage 15";
PROGMEM prog_char EffectType__37__Parameter__52__label[] = "Stage 16";
PROGMEM prog_char EffectType__37__Parameter__53__label[] = "";
PROGMEM prog_char EffectType__37__Parameter__54__label[] = "Run";
PROGMEM prog_char EffectType__37__Parameter__55__label[] = "Manual A";
PROGMEM prog_char EffectType__37__Parameter__56__label[] = "Manual B";
PROGMEM prog_char EffectType__37__Parameter__57__label[] = "Manual C";
PROGMEM prog_char EffectType__37__Parameter__58__label[] = "Manual D";
PROGMEM prog_char EffectType__37__Parameter__59__label[] = "Stage 17";
PROGMEM prog_char EffectType__37__Parameter__60__label[] = "Stage 18";
PROGMEM prog_char EffectType__37__Parameter__61__label[] = "Stage 19";
PROGMEM prog_char EffectType__37__Parameter__62__label[] = "Stage 20";
PROGMEM prog_char EffectType__37__Parameter__63__label[] = "Stage 21";
PROGMEM prog_char EffectType__37__Parameter__64__label[] = "Stage 22";
PROGMEM prog_char EffectType__37__Parameter__65__label[] = "Stage 23";
PROGMEM prog_char EffectType__37__Parameter__66__label[] = "Stage 24";
PROGMEM prog_char EffectType__37__Parameter__67__label[] = "Stage 25";
PROGMEM prog_char EffectType__37__Parameter__68__label[] = "Stage 26";
PROGMEM prog_char EffectType__37__Parameter__69__label[] = "Stage 27";
PROGMEM prog_char EffectType__37__Parameter__70__label[] = "Stage 28";
PROGMEM prog_char EffectType__37__Parameter__71__label[] = "Stage 29";
PROGMEM prog_char EffectType__37__Parameter__72__label[] = "Stage 30";
PROGMEM prog_char EffectType__37__Parameter__73__label[] = "Stage 31";
PROGMEM prog_char EffectType__37__Parameter__74__label[] = "Stage 32";
PROGMEM prog_char EffectType__37__Parameter__75__label[] = "";
PROGMEM prog_char EffectType__37__Parameter__76__label[] = "";
PROGMEM prog_char EffectType__37__Parameter__77__label[] = "";
PROGMEM prog_char EffectType__38__Parameter__0__label[] = "Mix";
PROGMEM prog_char EffectType__38__Parameter__1__label[] = "Level";
PROGMEM prog_char EffectType__38__Parameter__2__label[] = "Balance";
PROGMEM prog_char EffectType__38__Parameter__3__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__38__Parameter__4__label[] = "";
PROGMEM prog_char EffectType__38__Parameter__5__label[] = "Dub Mix";
PROGMEM prog_char EffectType__38__Parameter__6__label[] = "Threshold";
PROGMEM prog_char EffectType__38__Parameter__7__label[] = "Threshold Level";
PROGMEM prog_char EffectType__38__Parameter__8__label[] = "";
PROGMEM prog_char EffectType__38__Parameter__9__label[] = "Quantize";
PROGMEM prog_char EffectType__38__Parameter__10__label[] = "Trim Stop";
PROGMEM prog_char EffectType__38__Parameter__11__label[] = "Trim Start";
PROGMEM prog_char EffectType__38__Parameter__12__label[] = "Play Immediately";
PROGMEM prog_char EffectType__39__Parameter__0__label[] = "";
PROGMEM prog_char EffectType__39__Parameter__1__label[] = "Amount";
PROGMEM prog_char EffectType__39__Parameter__2__label[] = "Smoothing";
PROGMEM prog_char EffectType__39__Parameter__3__label[] = "Reference";
PROGMEM prog_char EffectType__39__Parameter__4__label[] = "Local";
PROGMEM prog_char EffectType__39__Parameter__5__label[] = "Match";
PROGMEM prog_char EffectType__39__Parameter__6__label[] = "Level";
PROGMEM prog_char EffectType__39__Parameter__7__label[] = "Balance";
PROGMEM prog_char EffectType__39__Parameter__8__label[] = "Bypass Mode";
PROGMEM prog_char EffectType__39__Parameter__9__label[] = "";
PROGMEM prog_char EffectType__39__Parameter__10__label[] = "Ref Source";
PROGMEM prog_char EffectType__39__Parameter__11__label[] = "Time";
PROGMEM prog_char EffectType__39__Parameter__12__label[] = "Ref Channel";
PROGMEM prog_char EffectType__39__Parameter__13__label[] = "Local Channel";
PROGMEM prog_char EffectType__39__Parameter__14__label[] = "Ref Solo";
PROGMEM prog_char EffectType__39__Parameter__15__label[] = "Resolution";
PROGMEM prog_char EffectType__39__Parameter__16__label[] = "";
PROGMEM prog_char EffectType__39__Parameter__17__label[] = "";
PROGMEM prog_char EffectType__39__Parameter__18__label[] = "";
PROGMEM prog_char EffectType__39__Parameter__19__label[] = "";
PROGMEM prog_char EffectType__39__Parameter__20__label[] = "";


PROGMEM char *Parameter__label[1100] = { EffectType__2__Parameter__0__label, EffectType__2__Parameter__1__label, EffectType__2__Parameter__2__label, EffectType__2__Parameter__3__label, EffectType__2__Parameter__4__label, EffectType__2__Parameter__5__label, EffectType__2__Parameter__6__label, EffectType__2__Parameter__7__label, EffectType__2__Parameter__8__label, EffectType__2__Parameter__9__label, EffectType__2__Parameter__10__label, EffectType__2__Parameter__11__label, EffectType__2__Parameter__12__label, EffectType__2__Parameter__13__label, EffectType__2__Parameter__14__label, EffectType__2__Parameter__15__label, EffectType__2__Parameter__16__label, EffectType__2__Parameter__17__label, 
EffectType__3__Parameter__0__label, EffectType__3__Parameter__1__label, EffectType__3__Parameter__2__label, EffectType__3__Parameter__3__label, EffectType__3__Parameter__4__label, EffectType__3__Parameter__5__label, EffectType__3__Parameter__6__label, EffectType__3__Parameter__7__label, EffectType__3__Parameter__8__label, EffectType__3__Parameter__9__label, EffectType__3__Parameter__10__label, EffectType__3__Parameter__11__label, EffectType__3__Parameter__12__label, EffectType__3__Parameter__13__label, EffectType__3__Parameter__14__label, EffectType__3__Parameter__15__label, EffectType__3__Parameter__16__label, EffectType__3__Parameter__17__label, EffectType__3__Parameter__18__label, 
EffectType__4__Parameter__0__label, EffectType__4__Parameter__1__label, EffectType__4__Parameter__2__label, EffectType__4__Parameter__3__label, EffectType__4__Parameter__4__label, EffectType__4__Parameter__5__label, EffectType__4__Parameter__6__label, EffectType__4__Parameter__7__label, EffectType__4__Parameter__8__label, EffectType__4__Parameter__9__label, EffectType__4__Parameter__10__label, EffectType__4__Parameter__11__label, EffectType__4__Parameter__12__label, EffectType__4__Parameter__13__label, EffectType__4__Parameter__14__label, EffectType__4__Parameter__15__label, EffectType__4__Parameter__16__label, EffectType__4__Parameter__17__label, EffectType__4__Parameter__18__label, EffectType__4__Parameter__19__label, EffectType__4__Parameter__20__label, EffectType__4__Parameter__21__label, EffectType__4__Parameter__22__label, EffectType__4__Parameter__23__label, 
EffectType__5__Parameter__0__label, EffectType__5__Parameter__1__label, EffectType__5__Parameter__2__label, EffectType__5__Parameter__3__label, EffectType__5__Parameter__4__label, EffectType__5__Parameter__5__label, EffectType__5__Parameter__6__label, EffectType__5__Parameter__7__label, EffectType__5__Parameter__8__label, EffectType__5__Parameter__9__label, EffectType__5__Parameter__10__label, EffectType__5__Parameter__11__label, EffectType__5__Parameter__12__label, EffectType__5__Parameter__13__label, EffectType__5__Parameter__14__label, EffectType__5__Parameter__15__label, EffectType__5__Parameter__16__label, EffectType__5__Parameter__17__label, EffectType__5__Parameter__18__label, EffectType__5__Parameter__19__label, EffectType__5__Parameter__20__label, EffectType__5__Parameter__21__label, EffectType__5__Parameter__22__label, EffectType__5__Parameter__23__label, EffectType__5__Parameter__24__label, EffectType__5__Parameter__25__label, EffectType__5__Parameter__26__label, EffectType__5__Parameter__27__label, EffectType__5__Parameter__28__label, EffectType__5__Parameter__29__label, EffectType__5__Parameter__30__label, EffectType__5__Parameter__31__label, EffectType__5__Parameter__32__label, EffectType__5__Parameter__33__label, EffectType__5__Parameter__34__label, EffectType__5__Parameter__35__label, EffectType__5__Parameter__36__label, EffectType__5__Parameter__37__label, EffectType__5__Parameter__38__label, EffectType__5__Parameter__39__label, EffectType__5__Parameter__40__label, EffectType__5__Parameter__41__label, EffectType__5__Parameter__42__label, EffectType__5__Parameter__43__label, EffectType__5__Parameter__44__label, EffectType__5__Parameter__45__label, EffectType__5__Parameter__46__label, EffectType__5__Parameter__47__label, EffectType__5__Parameter__48__label, EffectType__5__Parameter__49__label, EffectType__5__Parameter__50__label, EffectType__5__Parameter__51__label, EffectType__5__Parameter__52__label, EffectType__5__Parameter__53__label, EffectType__5__Parameter__54__label, EffectType__5__Parameter__55__label, EffectType__5__Parameter__56__label, EffectType__5__Parameter__57__label, EffectType__5__Parameter__58__label, EffectType__5__Parameter__59__label, EffectType__5__Parameter__60__label, EffectType__5__Parameter__61__label, EffectType__5__Parameter__62__label, EffectType__5__Parameter__63__label, EffectType__5__Parameter__64__label, EffectType__5__Parameter__65__label, EffectType__5__Parameter__66__label, EffectType__5__Parameter__67__label, EffectType__5__Parameter__68__label, EffectType__5__Parameter__69__label, EffectType__5__Parameter__70__label, EffectType__5__Parameter__71__label, EffectType__5__Parameter__72__label, EffectType__5__Parameter__73__label, EffectType__5__Parameter__74__label, EffectType__5__Parameter__75__label, EffectType__5__Parameter__76__label, EffectType__5__Parameter__77__label, EffectType__5__Parameter__78__label, EffectType__5__Parameter__79__label, EffectType__5__Parameter__80__label, EffectType__5__Parameter__81__label, EffectType__5__Parameter__82__label, EffectType__5__Parameter__83__label, EffectType__5__Parameter__84__label, EffectType__5__Parameter__85__label, EffectType__5__Parameter__86__label, EffectType__5__Parameter__87__label, EffectType__5__Parameter__88__label, EffectType__5__Parameter__89__label, EffectType__5__Parameter__90__label, 
EffectType__6__Parameter__0__label, EffectType__6__Parameter__1__label, EffectType__6__Parameter__2__label, EffectType__6__Parameter__3__label, EffectType__6__Parameter__4__label, EffectType__6__Parameter__5__label, EffectType__6__Parameter__6__label, EffectType__6__Parameter__7__label, EffectType__6__Parameter__8__label, EffectType__6__Parameter__9__label, EffectType__6__Parameter__10__label, EffectType__6__Parameter__11__label, EffectType__6__Parameter__12__label, EffectType__6__Parameter__13__label, EffectType__6__Parameter__14__label, EffectType__6__Parameter__15__label, EffectType__6__Parameter__16__label, EffectType__6__Parameter__17__label, EffectType__6__Parameter__18__label, EffectType__6__Parameter__19__label, EffectType__6__Parameter__20__label, EffectType__6__Parameter__21__label, EffectType__6__Parameter__22__label, EffectType__6__Parameter__23__label, EffectType__6__Parameter__24__label, EffectType__6__Parameter__25__label, EffectType__6__Parameter__26__label, EffectType__6__Parameter__27__label, EffectType__6__Parameter__28__label, 
EffectType__7__Parameter__0__label, EffectType__7__Parameter__1__label, EffectType__7__Parameter__2__label, EffectType__7__Parameter__3__label, EffectType__7__Parameter__4__label, EffectType__7__Parameter__5__label, EffectType__7__Parameter__6__label, EffectType__7__Parameter__7__label, EffectType__7__Parameter__8__label, EffectType__7__Parameter__9__label, EffectType__7__Parameter__10__label, EffectType__7__Parameter__11__label, EffectType__7__Parameter__12__label, EffectType__7__Parameter__13__label, EffectType__7__Parameter__14__label, EffectType__7__Parameter__15__label, EffectType__7__Parameter__16__label, EffectType__7__Parameter__17__label, EffectType__7__Parameter__18__label, EffectType__7__Parameter__19__label, EffectType__7__Parameter__20__label, EffectType__7__Parameter__21__label, EffectType__7__Parameter__22__label, EffectType__7__Parameter__23__label, EffectType__7__Parameter__24__label, EffectType__7__Parameter__25__label, EffectType__7__Parameter__26__label, EffectType__7__Parameter__27__label, EffectType__7__Parameter__28__label, EffectType__7__Parameter__29__label, EffectType__7__Parameter__30__label, EffectType__7__Parameter__31__label, EffectType__7__Parameter__32__label, EffectType__7__Parameter__33__label, EffectType__7__Parameter__34__label, 
EffectType__8__Parameter__0__label, EffectType__8__Parameter__1__label, EffectType__8__Parameter__2__label, EffectType__8__Parameter__3__label, EffectType__8__Parameter__4__label, EffectType__8__Parameter__5__label, EffectType__8__Parameter__6__label, EffectType__8__Parameter__7__label, EffectType__8__Parameter__8__label, EffectType__8__Parameter__9__label, EffectType__8__Parameter__10__label, EffectType__8__Parameter__11__label, EffectType__8__Parameter__12__label, EffectType__8__Parameter__13__label, EffectType__8__Parameter__14__label, EffectType__8__Parameter__15__label, EffectType__8__Parameter__16__label, EffectType__8__Parameter__17__label, EffectType__8__Parameter__18__label, EffectType__8__Parameter__19__label, EffectType__8__Parameter__20__label, EffectType__8__Parameter__21__label, EffectType__8__Parameter__22__label, EffectType__8__Parameter__23__label, EffectType__8__Parameter__24__label, EffectType__8__Parameter__25__label, EffectType__8__Parameter__26__label, EffectType__8__Parameter__27__label, EffectType__8__Parameter__28__label, EffectType__8__Parameter__29__label, EffectType__8__Parameter__30__label, EffectType__8__Parameter__31__label, EffectType__8__Parameter__32__label, EffectType__8__Parameter__33__label, EffectType__8__Parameter__34__label, EffectType__8__Parameter__35__label, EffectType__8__Parameter__36__label, EffectType__8__Parameter__37__label, EffectType__8__Parameter__38__label, EffectType__8__Parameter__39__label, EffectType__8__Parameter__40__label, EffectType__8__Parameter__41__label, EffectType__8__Parameter__42__label, EffectType__8__Parameter__43__label, EffectType__8__Parameter__44__label, EffectType__8__Parameter__45__label, EffectType__8__Parameter__46__label, EffectType__8__Parameter__47__label, EffectType__8__Parameter__48__label, EffectType__8__Parameter__49__label, EffectType__8__Parameter__50__label, EffectType__8__Parameter__51__label, EffectType__8__Parameter__52__label, EffectType__8__Parameter__53__label, EffectType__8__Parameter__54__label, EffectType__8__Parameter__55__label, EffectType__8__Parameter__56__label, EffectType__8__Parameter__57__label, EffectType__8__Parameter__58__label, EffectType__8__Parameter__59__label, EffectType__8__Parameter__60__label, EffectType__8__Parameter__61__label, EffectType__8__Parameter__62__label, EffectType__8__Parameter__63__label, EffectType__8__Parameter__64__label, EffectType__8__Parameter__65__label, EffectType__8__Parameter__66__label, EffectType__8__Parameter__67__label, EffectType__8__Parameter__68__label, EffectType__8__Parameter__69__label, 
EffectType__9__Parameter__0__label, EffectType__9__Parameter__1__label, EffectType__9__Parameter__2__label, EffectType__9__Parameter__3__label, EffectType__9__Parameter__4__label, EffectType__9__Parameter__5__label, EffectType__9__Parameter__6__label, EffectType__9__Parameter__7__label, EffectType__9__Parameter__8__label, EffectType__9__Parameter__9__label, EffectType__9__Parameter__10__label, EffectType__9__Parameter__11__label, EffectType__9__Parameter__12__label, EffectType__9__Parameter__13__label, EffectType__9__Parameter__14__label, EffectType__9__Parameter__15__label, EffectType__9__Parameter__16__label, EffectType__9__Parameter__17__label, EffectType__9__Parameter__18__label, EffectType__9__Parameter__19__label, EffectType__9__Parameter__20__label, EffectType__9__Parameter__21__label, EffectType__9__Parameter__22__label, EffectType__9__Parameter__23__label, EffectType__9__Parameter__24__label, EffectType__9__Parameter__25__label, EffectType__9__Parameter__26__label, EffectType__9__Parameter__27__label, EffectType__9__Parameter__28__label, EffectType__9__Parameter__29__label, EffectType__9__Parameter__30__label, EffectType__9__Parameter__31__label, EffectType__9__Parameter__32__label, EffectType__9__Parameter__33__label, EffectType__9__Parameter__34__label, EffectType__9__Parameter__35__label, EffectType__9__Parameter__36__label, EffectType__9__Parameter__37__label, EffectType__9__Parameter__38__label, EffectType__9__Parameter__39__label, EffectType__9__Parameter__40__label, EffectType__9__Parameter__41__label, EffectType__9__Parameter__42__label, EffectType__9__Parameter__43__label, EffectType__9__Parameter__44__label, EffectType__9__Parameter__45__label, EffectType__9__Parameter__46__label, EffectType__9__Parameter__47__label, EffectType__9__Parameter__48__label, EffectType__9__Parameter__49__label, EffectType__9__Parameter__50__label, EffectType__9__Parameter__51__label, EffectType__9__Parameter__52__label, EffectType__9__Parameter__53__label, EffectType__9__Parameter__54__label, EffectType__9__Parameter__55__label, EffectType__9__Parameter__56__label, EffectType__9__Parameter__57__label, EffectType__9__Parameter__58__label, EffectType__9__Parameter__59__label, EffectType__9__Parameter__60__label, EffectType__9__Parameter__61__label, EffectType__9__Parameter__62__label, EffectType__9__Parameter__63__label, EffectType__9__Parameter__64__label, EffectType__9__Parameter__65__label, EffectType__9__Parameter__66__label, EffectType__9__Parameter__67__label, EffectType__9__Parameter__68__label, EffectType__9__Parameter__69__label, EffectType__9__Parameter__70__label, EffectType__9__Parameter__71__label, EffectType__9__Parameter__72__label, EffectType__9__Parameter__73__label, EffectType__9__Parameter__74__label, EffectType__9__Parameter__75__label, EffectType__9__Parameter__76__label, EffectType__9__Parameter__77__label, EffectType__9__Parameter__78__label, EffectType__9__Parameter__79__label, EffectType__9__Parameter__80__label, EffectType__9__Parameter__81__label, EffectType__9__Parameter__82__label, EffectType__9__Parameter__83__label, EffectType__9__Parameter__84__label, EffectType__9__Parameter__85__label, EffectType__9__Parameter__86__label, EffectType__9__Parameter__87__label, EffectType__9__Parameter__88__label, EffectType__9__Parameter__89__label, EffectType__9__Parameter__90__label, EffectType__9__Parameter__91__label, EffectType__9__Parameter__92__label, EffectType__9__Parameter__93__label, EffectType__9__Parameter__94__label, EffectType__9__Parameter__95__label, EffectType__9__Parameter__96__label, EffectType__9__Parameter__97__label, EffectType__9__Parameter__98__label, EffectType__9__Parameter__99__label, EffectType__9__Parameter__100__label, EffectType__9__Parameter__101__label, EffectType__9__Parameter__102__label, EffectType__9__Parameter__103__label, EffectType__9__Parameter__104__label, EffectType__9__Parameter__105__label, EffectType__9__Parameter__106__label, EffectType__9__Parameter__107__label, EffectType__9__Parameter__108__label, EffectType__9__Parameter__109__label, EffectType__9__Parameter__110__label, EffectType__9__Parameter__111__label, EffectType__9__Parameter__112__label, EffectType__9__Parameter__113__label, EffectType__9__Parameter__114__label, EffectType__9__Parameter__115__label, EffectType__9__Parameter__116__label, 
EffectType__10__Parameter__0__label, EffectType__10__Parameter__1__label, EffectType__10__Parameter__2__label, EffectType__10__Parameter__3__label, EffectType__10__Parameter__4__label, EffectType__10__Parameter__5__label, EffectType__10__Parameter__6__label, EffectType__10__Parameter__7__label, EffectType__10__Parameter__8__label, EffectType__10__Parameter__9__label, EffectType__10__Parameter__10__label, EffectType__10__Parameter__11__label, EffectType__10__Parameter__12__label, EffectType__10__Parameter__13__label, EffectType__10__Parameter__14__label, EffectType__10__Parameter__15__label, EffectType__10__Parameter__16__label, EffectType__10__Parameter__17__label, EffectType__10__Parameter__18__label, EffectType__10__Parameter__19__label, EffectType__10__Parameter__20__label, EffectType__10__Parameter__21__label, EffectType__10__Parameter__22__label, 
EffectType__11__Parameter__0__label, EffectType__11__Parameter__1__label, EffectType__11__Parameter__2__label, EffectType__11__Parameter__3__label, EffectType__11__Parameter__4__label, EffectType__11__Parameter__5__label, EffectType__11__Parameter__6__label, EffectType__11__Parameter__7__label, EffectType__11__Parameter__8__label, EffectType__11__Parameter__9__label, EffectType__11__Parameter__10__label, EffectType__11__Parameter__11__label, EffectType__11__Parameter__12__label, EffectType__11__Parameter__13__label, EffectType__11__Parameter__14__label, EffectType__11__Parameter__15__label, EffectType__11__Parameter__16__label, EffectType__11__Parameter__17__label, EffectType__11__Parameter__18__label, EffectType__11__Parameter__19__label, EffectType__11__Parameter__20__label, EffectType__11__Parameter__21__label, EffectType__11__Parameter__22__label, 
EffectType__12__Parameter__0__label, EffectType__12__Parameter__1__label, EffectType__12__Parameter__2__label, EffectType__12__Parameter__3__label, EffectType__12__Parameter__4__label, EffectType__12__Parameter__5__label, EffectType__12__Parameter__6__label, EffectType__12__Parameter__7__label, EffectType__12__Parameter__8__label, EffectType__12__Parameter__9__label, EffectType__12__Parameter__10__label, EffectType__12__Parameter__11__label, EffectType__12__Parameter__12__label, EffectType__12__Parameter__13__label, EffectType__12__Parameter__14__label, EffectType__12__Parameter__15__label, EffectType__12__Parameter__16__label, EffectType__12__Parameter__17__label, 
EffectType__13__Parameter__0__label, EffectType__13__Parameter__1__label, EffectType__13__Parameter__2__label, EffectType__13__Parameter__3__label, EffectType__13__Parameter__4__label, EffectType__13__Parameter__5__label, EffectType__13__Parameter__6__label, EffectType__13__Parameter__7__label, EffectType__13__Parameter__8__label, EffectType__13__Parameter__9__label, EffectType__13__Parameter__10__label, EffectType__13__Parameter__11__label, EffectType__13__Parameter__12__label, EffectType__13__Parameter__13__label, EffectType__13__Parameter__14__label, EffectType__13__Parameter__15__label, EffectType__13__Parameter__16__label, EffectType__13__Parameter__17__label, EffectType__13__Parameter__18__label, EffectType__13__Parameter__19__label, 
EffectType__14__Parameter__0__label, EffectType__14__Parameter__1__label, EffectType__14__Parameter__2__label, EffectType__14__Parameter__3__label, EffectType__14__Parameter__4__label, EffectType__14__Parameter__5__label, EffectType__14__Parameter__6__label, EffectType__14__Parameter__7__label, EffectType__14__Parameter__8__label, EffectType__14__Parameter__9__label, EffectType__14__Parameter__10__label, EffectType__14__Parameter__11__label, EffectType__14__Parameter__12__label, 
EffectType__15__Parameter__0__label, EffectType__15__Parameter__1__label, EffectType__15__Parameter__2__label, EffectType__15__Parameter__3__label, EffectType__15__Parameter__4__label, EffectType__15__Parameter__5__label, EffectType__15__Parameter__6__label, EffectType__15__Parameter__7__label, EffectType__15__Parameter__8__label, EffectType__15__Parameter__9__label, EffectType__15__Parameter__10__label, EffectType__15__Parameter__11__label, 
EffectType__16__Parameter__0__label, EffectType__16__Parameter__1__label, EffectType__16__Parameter__2__label, EffectType__16__Parameter__3__label, EffectType__16__Parameter__4__label, EffectType__16__Parameter__5__label, EffectType__16__Parameter__6__label, EffectType__16__Parameter__7__label, EffectType__16__Parameter__8__label, EffectType__16__Parameter__9__label, EffectType__16__Parameter__10__label, EffectType__16__Parameter__11__label, EffectType__16__Parameter__12__label, EffectType__16__Parameter__13__label, EffectType__16__Parameter__14__label, 
EffectType__17__Parameter__0__label, EffectType__17__Parameter__1__label, EffectType__17__Parameter__2__label, EffectType__17__Parameter__3__label, EffectType__17__Parameter__4__label, EffectType__17__Parameter__5__label, EffectType__17__Parameter__6__label, EffectType__17__Parameter__7__label, EffectType__17__Parameter__8__label, EffectType__17__Parameter__9__label, EffectType__17__Parameter__10__label, EffectType__17__Parameter__11__label, EffectType__17__Parameter__12__label, EffectType__17__Parameter__13__label, EffectType__17__Parameter__14__label, EffectType__17__Parameter__15__label, EffectType__17__Parameter__16__label, EffectType__17__Parameter__17__label, EffectType__17__Parameter__18__label, EffectType__17__Parameter__19__label, EffectType__17__Parameter__20__label, EffectType__17__Parameter__21__label, EffectType__17__Parameter__22__label, EffectType__17__Parameter__23__label, EffectType__17__Parameter__24__label, EffectType__17__Parameter__25__label, EffectType__17__Parameter__26__label, EffectType__17__Parameter__27__label, EffectType__17__Parameter__28__label, EffectType__17__Parameter__29__label, EffectType__17__Parameter__30__label, EffectType__17__Parameter__31__label, EffectType__17__Parameter__32__label, EffectType__17__Parameter__33__label, EffectType__17__Parameter__34__label, EffectType__17__Parameter__35__label, EffectType__17__Parameter__36__label, EffectType__17__Parameter__37__label, EffectType__17__Parameter__38__label, EffectType__17__Parameter__39__label, EffectType__17__Parameter__40__label, EffectType__17__Parameter__41__label, EffectType__17__Parameter__42__label, EffectType__17__Parameter__43__label, EffectType__17__Parameter__44__label, EffectType__17__Parameter__45__label, EffectType__17__Parameter__46__label, EffectType__17__Parameter__47__label, EffectType__17__Parameter__48__label, EffectType__17__Parameter__49__label, EffectType__17__Parameter__50__label, EffectType__17__Parameter__51__label, EffectType__17__Parameter__52__label, EffectType__17__Parameter__53__label, EffectType__17__Parameter__54__label, EffectType__17__Parameter__55__label, EffectType__17__Parameter__56__label, EffectType__17__Parameter__57__label, EffectType__17__Parameter__58__label, EffectType__17__Parameter__59__label, EffectType__17__Parameter__60__label, EffectType__17__Parameter__61__label, EffectType__17__Parameter__62__label, EffectType__17__Parameter__63__label, EffectType__17__Parameter__64__label, EffectType__17__Parameter__65__label, EffectType__17__Parameter__66__label, EffectType__17__Parameter__67__label, EffectType__17__Parameter__68__label, EffectType__17__Parameter__69__label, EffectType__17__Parameter__70__label, EffectType__17__Parameter__71__label, EffectType__17__Parameter__72__label, EffectType__17__Parameter__73__label, EffectType__17__Parameter__74__label, EffectType__17__Parameter__75__label, EffectType__17__Parameter__76__label, EffectType__17__Parameter__77__label, EffectType__17__Parameter__78__label, EffectType__17__Parameter__79__label, EffectType__17__Parameter__80__label, EffectType__17__Parameter__81__label, EffectType__17__Parameter__82__label, EffectType__17__Parameter__83__label, EffectType__17__Parameter__84__label, 
EffectType__18__Parameter__0__label, EffectType__18__Parameter__1__label, EffectType__18__Parameter__2__label, EffectType__18__Parameter__3__label, EffectType__18__Parameter__4__label, EffectType__18__Parameter__5__label, EffectType__18__Parameter__6__label, EffectType__18__Parameter__7__label, EffectType__18__Parameter__8__label, EffectType__18__Parameter__9__label, EffectType__18__Parameter__10__label, EffectType__18__Parameter__11__label, EffectType__18__Parameter__12__label, EffectType__18__Parameter__13__label, 
EffectType__19__Parameter__0__label, EffectType__19__Parameter__1__label, EffectType__19__Parameter__2__label, EffectType__19__Parameter__3__label, EffectType__19__Parameter__4__label, EffectType__19__Parameter__5__label, EffectType__19__Parameter__6__label, EffectType__19__Parameter__7__label, EffectType__19__Parameter__8__label, EffectType__19__Parameter__9__label, EffectType__19__Parameter__10__label, EffectType__19__Parameter__11__label, EffectType__19__Parameter__12__label, EffectType__19__Parameter__13__label, EffectType__19__Parameter__14__label, EffectType__19__Parameter__15__label, EffectType__19__Parameter__16__label, EffectType__19__Parameter__17__label, EffectType__19__Parameter__18__label, EffectType__19__Parameter__19__label, 
EffectType__20__Parameter__0__label, EffectType__20__Parameter__1__label, EffectType__20__Parameter__2__label, EffectType__20__Parameter__3__label, EffectType__20__Parameter__4__label, EffectType__20__Parameter__5__label, EffectType__20__Parameter__6__label, EffectType__20__Parameter__7__label, EffectType__20__Parameter__8__label, EffectType__20__Parameter__9__label, EffectType__20__Parameter__10__label, 
EffectType__21__Parameter__0__label, EffectType__21__Parameter__1__label, EffectType__21__Parameter__2__label, EffectType__21__Parameter__3__label, EffectType__21__Parameter__4__label, EffectType__21__Parameter__5__label, EffectType__21__Parameter__6__label, EffectType__21__Parameter__7__label, EffectType__21__Parameter__8__label, EffectType__21__Parameter__9__label, EffectType__21__Parameter__10__label, EffectType__21__Parameter__11__label, EffectType__21__Parameter__12__label, EffectType__21__Parameter__13__label, EffectType__21__Parameter__14__label, EffectType__21__Parameter__15__label, EffectType__21__Parameter__16__label, EffectType__21__Parameter__17__label, EffectType__21__Parameter__18__label, EffectType__21__Parameter__19__label, 
EffectType__22__Parameter__0__label, EffectType__22__Parameter__1__label, EffectType__22__Parameter__2__label, EffectType__22__Parameter__3__label, EffectType__22__Parameter__4__label, EffectType__22__Parameter__5__label, EffectType__22__Parameter__6__label, EffectType__22__Parameter__7__label, EffectType__22__Parameter__8__label, EffectType__22__Parameter__9__label, 
EffectType__23__Parameter__0__label, EffectType__23__Parameter__1__label, 
EffectType__24__Parameter__0__label, EffectType__24__Parameter__1__label, EffectType__24__Parameter__2__label, EffectType__24__Parameter__3__label, EffectType__24__Parameter__4__label, EffectType__24__Parameter__5__label, 
EffectType__25__Parameter__0__label, EffectType__25__Parameter__1__label, EffectType__25__Parameter__2__label, EffectType__25__Parameter__3__label, EffectType__25__Parameter__4__label, EffectType__25__Parameter__5__label, EffectType__25__Parameter__6__label, EffectType__25__Parameter__7__label, EffectType__25__Parameter__8__label, EffectType__25__Parameter__9__label, EffectType__25__Parameter__10__label, EffectType__25__Parameter__11__label, EffectType__25__Parameter__12__label, EffectType__25__Parameter__13__label, EffectType__25__Parameter__14__label, EffectType__25__Parameter__15__label, EffectType__25__Parameter__16__label, EffectType__25__Parameter__17__label, EffectType__25__Parameter__18__label, EffectType__25__Parameter__19__label, EffectType__25__Parameter__20__label, EffectType__25__Parameter__21__label, EffectType__25__Parameter__22__label, EffectType__25__Parameter__23__label, EffectType__25__Parameter__24__label, EffectType__25__Parameter__25__label, EffectType__25__Parameter__26__label, EffectType__25__Parameter__27__label, EffectType__25__Parameter__28__label, EffectType__25__Parameter__29__label, EffectType__25__Parameter__30__label, EffectType__25__Parameter__31__label, EffectType__25__Parameter__32__label, EffectType__25__Parameter__33__label, EffectType__25__Parameter__34__label, EffectType__25__Parameter__35__label, EffectType__25__Parameter__36__label, EffectType__25__Parameter__37__label, EffectType__25__Parameter__38__label, EffectType__25__Parameter__39__label, 
EffectType__26__Parameter__0__label, EffectType__26__Parameter__1__label, EffectType__26__Parameter__2__label, EffectType__26__Parameter__3__label, EffectType__26__Parameter__4__label, EffectType__26__Parameter__5__label, EffectType__26__Parameter__6__label, EffectType__26__Parameter__7__label, EffectType__26__Parameter__8__label, EffectType__26__Parameter__9__label, EffectType__26__Parameter__10__label, EffectType__26__Parameter__11__label, EffectType__26__Parameter__12__label, EffectType__26__Parameter__13__label, EffectType__26__Parameter__14__label, EffectType__26__Parameter__15__label, EffectType__26__Parameter__16__label, EffectType__26__Parameter__17__label, EffectType__26__Parameter__18__label, EffectType__26__Parameter__19__label, EffectType__26__Parameter__20__label, EffectType__26__Parameter__21__label, EffectType__26__Parameter__22__label, EffectType__26__Parameter__23__label, EffectType__26__Parameter__24__label, EffectType__26__Parameter__25__label, EffectType__26__Parameter__26__label, EffectType__26__Parameter__27__label, EffectType__26__Parameter__28__label, EffectType__26__Parameter__29__label, EffectType__26__Parameter__30__label, EffectType__26__Parameter__31__label, EffectType__26__Parameter__32__label, EffectType__26__Parameter__33__label, EffectType__26__Parameter__34__label, EffectType__26__Parameter__35__label, EffectType__26__Parameter__36__label, EffectType__26__Parameter__37__label, EffectType__26__Parameter__38__label, EffectType__26__Parameter__39__label, EffectType__26__Parameter__40__label, EffectType__26__Parameter__41__label, EffectType__26__Parameter__42__label, EffectType__26__Parameter__43__label, EffectType__26__Parameter__44__label, EffectType__26__Parameter__45__label, EffectType__26__Parameter__46__label, EffectType__26__Parameter__47__label, EffectType__26__Parameter__48__label, EffectType__26__Parameter__49__label, 
EffectType__27__Parameter__0__label, EffectType__27__Parameter__1__label, EffectType__27__Parameter__2__label, EffectType__27__Parameter__3__label, EffectType__27__Parameter__4__label, EffectType__27__Parameter__5__label, EffectType__27__Parameter__6__label, EffectType__27__Parameter__7__label, EffectType__27__Parameter__8__label, EffectType__27__Parameter__9__label, EffectType__27__Parameter__10__label, EffectType__27__Parameter__11__label, EffectType__27__Parameter__12__label, EffectType__27__Parameter__13__label, EffectType__27__Parameter__14__label, EffectType__27__Parameter__15__label, EffectType__27__Parameter__16__label, 
EffectType__28__Parameter__0__label, EffectType__28__Parameter__1__label, EffectType__28__Parameter__2__label, EffectType__28__Parameter__3__label, EffectType__28__Parameter__4__label, EffectType__28__Parameter__5__label, EffectType__28__Parameter__6__label, EffectType__28__Parameter__7__label, EffectType__28__Parameter__8__label, EffectType__28__Parameter__9__label, EffectType__28__Parameter__10__label, EffectType__28__Parameter__11__label, EffectType__28__Parameter__12__label, EffectType__28__Parameter__13__label, EffectType__28__Parameter__14__label, 
EffectType__29__Parameter__0__label, EffectType__29__Parameter__1__label, EffectType__29__Parameter__2__label, EffectType__29__Parameter__3__label, EffectType__29__Parameter__4__label, EffectType__29__Parameter__5__label, EffectType__29__Parameter__6__label, EffectType__29__Parameter__7__label, EffectType__29__Parameter__8__label, EffectType__29__Parameter__9__label, EffectType__29__Parameter__10__label, EffectType__29__Parameter__11__label, EffectType__29__Parameter__12__label, 
EffectType__30__Parameter__0__label, EffectType__30__Parameter__1__label, EffectType__30__Parameter__2__label, EffectType__30__Parameter__3__label, EffectType__30__Parameter__4__label, EffectType__30__Parameter__5__label, EffectType__30__Parameter__6__label, EffectType__30__Parameter__7__label, EffectType__30__Parameter__8__label, EffectType__30__Parameter__9__label, 
EffectType__31__Parameter__0__label, EffectType__31__Parameter__1__label, EffectType__31__Parameter__2__label, EffectType__31__Parameter__3__label, EffectType__31__Parameter__4__label, EffectType__31__Parameter__5__label, EffectType__31__Parameter__6__label, EffectType__31__Parameter__7__label, EffectType__31__Parameter__8__label, EffectType__31__Parameter__9__label, EffectType__31__Parameter__10__label, EffectType__31__Parameter__11__label, EffectType__31__Parameter__12__label, EffectType__31__Parameter__13__label, EffectType__31__Parameter__14__label, EffectType__31__Parameter__15__label, EffectType__31__Parameter__16__label, EffectType__31__Parameter__17__label, EffectType__31__Parameter__18__label, EffectType__31__Parameter__19__label, EffectType__31__Parameter__20__label, EffectType__31__Parameter__21__label, EffectType__31__Parameter__22__label, EffectType__31__Parameter__23__label, EffectType__31__Parameter__24__label, EffectType__31__Parameter__25__label, EffectType__31__Parameter__26__label, EffectType__31__Parameter__27__label, 
EffectType__32__Parameter__0__label, EffectType__32__Parameter__1__label, EffectType__32__Parameter__2__label, EffectType__32__Parameter__3__label, EffectType__32__Parameter__4__label, EffectType__32__Parameter__5__label, EffectType__32__Parameter__6__label, EffectType__32__Parameter__7__label, EffectType__32__Parameter__8__label, EffectType__32__Parameter__9__label, EffectType__32__Parameter__10__label, EffectType__32__Parameter__11__label, EffectType__32__Parameter__12__label, EffectType__32__Parameter__13__label, EffectType__32__Parameter__14__label, EffectType__32__Parameter__15__label, EffectType__32__Parameter__16__label, EffectType__32__Parameter__17__label, EffectType__32__Parameter__18__label, EffectType__32__Parameter__19__label, EffectType__32__Parameter__20__label, EffectType__32__Parameter__21__label, EffectType__32__Parameter__22__label, EffectType__32__Parameter__23__label, EffectType__32__Parameter__24__label, EffectType__32__Parameter__25__label, EffectType__32__Parameter__26__label, EffectType__32__Parameter__27__label, EffectType__32__Parameter__28__label, EffectType__32__Parameter__29__label, EffectType__32__Parameter__30__label, EffectType__32__Parameter__31__label, EffectType__32__Parameter__32__label, EffectType__32__Parameter__33__label, EffectType__32__Parameter__34__label, EffectType__32__Parameter__35__label, EffectType__32__Parameter__36__label, EffectType__32__Parameter__37__label, EffectType__32__Parameter__38__label, EffectType__32__Parameter__39__label, EffectType__32__Parameter__40__label, EffectType__32__Parameter__41__label, EffectType__32__Parameter__42__label, EffectType__32__Parameter__43__label, EffectType__32__Parameter__44__label, EffectType__32__Parameter__45__label, 
EffectType__33__Parameter__0__label, EffectType__33__Parameter__1__label, EffectType__33__Parameter__2__label, EffectType__33__Parameter__3__label, EffectType__33__Parameter__4__label, EffectType__33__Parameter__5__label, EffectType__33__Parameter__6__label, EffectType__33__Parameter__7__label, EffectType__33__Parameter__8__label, EffectType__33__Parameter__9__label, EffectType__33__Parameter__10__label, EffectType__33__Parameter__11__label, EffectType__33__Parameter__12__label, EffectType__33__Parameter__13__label, EffectType__33__Parameter__14__label, EffectType__33__Parameter__15__label, EffectType__33__Parameter__16__label, EffectType__33__Parameter__17__label, EffectType__33__Parameter__18__label, EffectType__33__Parameter__19__label, EffectType__33__Parameter__20__label, EffectType__33__Parameter__21__label, EffectType__33__Parameter__22__label, EffectType__33__Parameter__23__label, EffectType__33__Parameter__24__label, EffectType__33__Parameter__25__label, EffectType__33__Parameter__26__label, EffectType__33__Parameter__27__label, EffectType__33__Parameter__28__label, EffectType__33__Parameter__29__label, EffectType__33__Parameter__30__label, EffectType__33__Parameter__31__label, EffectType__33__Parameter__32__label, EffectType__33__Parameter__33__label, EffectType__33__Parameter__34__label, EffectType__33__Parameter__35__label, EffectType__33__Parameter__36__label, EffectType__33__Parameter__37__label, EffectType__33__Parameter__38__label, EffectType__33__Parameter__39__label, 
EffectType__34__Parameter__0__label, EffectType__34__Parameter__1__label, EffectType__34__Parameter__2__label, EffectType__34__Parameter__3__label, EffectType__34__Parameter__4__label, EffectType__34__Parameter__5__label, EffectType__34__Parameter__6__label, EffectType__34__Parameter__7__label, EffectType__34__Parameter__8__label, 
EffectType__35__Parameter__0__label, EffectType__35__Parameter__1__label, EffectType__35__Parameter__2__label, EffectType__35__Parameter__3__label, EffectType__35__Parameter__4__label, 
EffectType__36__Parameter__0__label, EffectType__36__Parameter__1__label, EffectType__36__Parameter__2__label, EffectType__36__Parameter__3__label, EffectType__36__Parameter__4__label, EffectType__36__Parameter__5__label, EffectType__36__Parameter__6__label, EffectType__36__Parameter__7__label, EffectType__36__Parameter__8__label, EffectType__36__Parameter__9__label, EffectType__36__Parameter__10__label, EffectType__36__Parameter__11__label, EffectType__36__Parameter__12__label, EffectType__36__Parameter__13__label, EffectType__36__Parameter__14__label, EffectType__36__Parameter__15__label, EffectType__36__Parameter__16__label, EffectType__36__Parameter__17__label, EffectType__36__Parameter__18__label, EffectType__36__Parameter__19__label, 
EffectType__37__Parameter__0__label, EffectType__37__Parameter__1__label, EffectType__37__Parameter__2__label, EffectType__37__Parameter__3__label, EffectType__37__Parameter__4__label, EffectType__37__Parameter__5__label, EffectType__37__Parameter__6__label, EffectType__37__Parameter__7__label, EffectType__37__Parameter__8__label, EffectType__37__Parameter__9__label, EffectType__37__Parameter__10__label, EffectType__37__Parameter__11__label, EffectType__37__Parameter__12__label, EffectType__37__Parameter__13__label, EffectType__37__Parameter__14__label, EffectType__37__Parameter__15__label, EffectType__37__Parameter__16__label, EffectType__37__Parameter__17__label, EffectType__37__Parameter__18__label, EffectType__37__Parameter__19__label, EffectType__37__Parameter__20__label, EffectType__37__Parameter__21__label, EffectType__37__Parameter__22__label, EffectType__37__Parameter__23__label, EffectType__37__Parameter__24__label, EffectType__37__Parameter__25__label, EffectType__37__Parameter__26__label, EffectType__37__Parameter__27__label, EffectType__37__Parameter__28__label, EffectType__37__Parameter__29__label, EffectType__37__Parameter__30__label, EffectType__37__Parameter__31__label, EffectType__37__Parameter__32__label, EffectType__37__Parameter__33__label, EffectType__37__Parameter__34__label, EffectType__37__Parameter__35__label, EffectType__37__Parameter__36__label, EffectType__37__Parameter__37__label, EffectType__37__Parameter__38__label, EffectType__37__Parameter__39__label, EffectType__37__Parameter__40__label, EffectType__37__Parameter__41__label, EffectType__37__Parameter__42__label, EffectType__37__Parameter__43__label, EffectType__37__Parameter__44__label, EffectType__37__Parameter__45__label, EffectType__37__Parameter__46__label, EffectType__37__Parameter__47__label, EffectType__37__Parameter__48__label, EffectType__37__Parameter__49__label, EffectType__37__Parameter__50__label, EffectType__37__Parameter__51__label, EffectType__37__Parameter__52__label, EffectType__37__Parameter__53__label, EffectType__37__Parameter__54__label, EffectType__37__Parameter__55__label, EffectType__37__Parameter__56__label, EffectType__37__Parameter__57__label, EffectType__37__Parameter__58__label, EffectType__37__Parameter__59__label, EffectType__37__Parameter__60__label, EffectType__37__Parameter__61__label, EffectType__37__Parameter__62__label, EffectType__37__Parameter__63__label, EffectType__37__Parameter__64__label, EffectType__37__Parameter__65__label, EffectType__37__Parameter__66__label, EffectType__37__Parameter__67__label, EffectType__37__Parameter__68__label, EffectType__37__Parameter__69__label, EffectType__37__Parameter__70__label, EffectType__37__Parameter__71__label, EffectType__37__Parameter__72__label, EffectType__37__Parameter__73__label, EffectType__37__Parameter__74__label, EffectType__37__Parameter__75__label, EffectType__37__Parameter__76__label, EffectType__37__Parameter__77__label, 
EffectType__38__Parameter__0__label, EffectType__38__Parameter__1__label, EffectType__38__Parameter__2__label, EffectType__38__Parameter__3__label, EffectType__38__Parameter__4__label, EffectType__38__Parameter__5__label, EffectType__38__Parameter__6__label, EffectType__38__Parameter__7__label, EffectType__38__Parameter__8__label, EffectType__38__Parameter__9__label, EffectType__38__Parameter__10__label, EffectType__38__Parameter__11__label, EffectType__38__Parameter__12__label, 
EffectType__39__Parameter__0__label, EffectType__39__Parameter__1__label, EffectType__39__Parameter__2__label, EffectType__39__Parameter__3__label, EffectType__39__Parameter__4__label, EffectType__39__Parameter__5__label, EffectType__39__Parameter__6__label, EffectType__39__Parameter__7__label, EffectType__39__Parameter__8__label, EffectType__39__Parameter__9__label, EffectType__39__Parameter__10__label, EffectType__39__Parameter__11__label, EffectType__39__Parameter__12__label, EffectType__39__Parameter__13__label, EffectType__39__Parameter__14__label, EffectType__39__Parameter__15__label, EffectType__39__Parameter__16__label, EffectType__39__Parameter__17__label, EffectType__39__Parameter__18__label, EffectType__39__Parameter__19__label, EffectType__39__Parameter__20__label};

PROGMEM byte Parameter__modifierID[1100] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0, 255, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 201, 202, 255, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 201, 202, 255, 0, 0, 
0, 203, 0, 0, 0, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 201, 202, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0, 0, 0, 0, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 211, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 201, 202, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 203, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 201, 202, 255, 0, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 200, 201, 202, 0, 200, 206, 207, 0, 0, 0, 203, 204, 205, 206, 207, 200, 201, 202, 255, 0, 0, 208, 0, 0, 204, 200, 213, 0, 0, 0, 211, 212, 0, 0, 200, 200, 0, 209, 0, 0, 200, 0, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0, 0, 0, 0, 0, 0, 200, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 201, 202, 255, 0, 203, 0, 0, 0, 0, 0, 0, 0, 0, 204, 205, 206, 207, 208, 209, 210, 211, 0, 0, 0, 0, 0, 0, 0, 0, 214, 215, 216, 217, 0, 0, 0, 0, 212, 0, 213, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 203, 0, 204, 204, 0, 0, 0, 0, 200, 201, 202, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 203, 0, 204, 205, 200, 0, 0, 0, 0, 0, 200, 201, 202, 255, 0, 0, 0, 0, 0, 0, 0, 0, 
203, 0, 0, 0, 0, 200, 201, 202, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 203, 0, 0, 204, 205, 206, 0, 0, 0, 200, 201, 202, 255, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 203, 201, 202, 255, 0, 0, 0, 0, 
0, 0, 0, 204, 203, 200, 201, 202, 255, 0, 0, 0, 
0, 0, 203, 204, 205, 0, 200, 201, 202, 255, 0, 200, 206, 0, 0, 
0, 0, 203, 203, 200, 200, 200, 0, 0, 204, 205, 200, 200, 200, 200, 200, 200, 0, 0, 0, 0, 0, 0, 200, 201, 202, 255, 0, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207, 208, 209, 210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 211, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 200, 
0, 200, 201, 202, 203, 204, 255, 0, 0, 0, 0, 0, 0, 0, 
0, 201, 202, 203, 200, 255, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 201, 205, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 201, 202, 255, 0, 
200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 
0, 0, 
200, 201, 202, 255, 0, 0, 
0, 203, 0, 213, 215, 204, 205, 206, 0, 207, 0, 0, 208, 0, 214, 216, 209, 210, 211, 0, 212, 0, 0, 200, 201, 202, 255, 0, 0, 0, 224, 0, 218, 219, 220, 221, 222, 0, 223, 0, 
0, 0, 0, 0, 0, 205, 203, 204, 0, 0, 0, 0, 200, 201, 202, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
203, 204, 200, 0, 0, 0, 0, 0, 0, 0, 0, 200, 201, 202, 255, 0, 0, 
200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 201, 202, 255, 0, 
203, 0, 0, 0, 202, 0, 0, 0, 200, 201, 202, 255, 0, 
203, 204, 0, 0, 200, 201, 202, 255, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 201, 202, 255, 0, 
203, 204, 205, 206, 207, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 201, 202, 255, 0, 0, 0, 
0, 0, 203, 204, 205, 206, 207, 208, 209, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 201, 202, 255, 0, 0, 0, 
200, 201, 0, 0, 202, 203, 204, 255, 0, 
200, 201, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
206, 200, 202, 204, 0, 0, 207, 201, 203, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 201, 0, 
203, 202, 201, 255, 0, 200, 0, 0, 0, 0, 204, 205, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, 0, 0, 200, 0, 0, 0, 0, 0, 0};

PROGMEM byte Parameter__displayType [1100] = { 0, 0, 0, 0, 0, 2, 1, 4, 0, 0, 2, 0, 0, 0, 2, 0, 1, 0, 
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 2, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 5, 0, 0, 0, 0, 
7, 7, 7, 7, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 2, 0, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 0, 0, 4, 4, 4, 2, 2, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 
0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 5, 5, 4, 0, 0, 4, 0, 0, 0, 0, 4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 2, 0, 0, 0, 0, 2, 5, 0, 0, 0, 2, 0, 0, 5, 0, 0, 0, 0, 0, 0, 
0, 0, 4, 0, 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 2, 0, 0, 4, 1, 0, 0, 0, 0, 
0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 4, 0, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 1, 0, 
2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 
4, 4, 4, 0, 0, 0, 0, 0, 2, 0, 0, 0, 
0, 2, 0, 0, 0, 4, 0, 0, 0, 2, 0, 0, 0, 0, 0, 
0, 2, 0, 0, 0, 0, 5, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 4, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 2, 1, 0, 
2, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 5, 0, 0, 
0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 
3, 3, 3, 3, 0, 0, 0, 0, 0, 2, 
0, 0, 
0, 0, 0, 0, 0, 0, 
2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 
4, 5, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 
0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 
0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 
0, 0, 1, 0, 0, 0, 0, 2, 1, 0, 
0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, 1, 0, 0, 0, 2, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 2, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 
0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 
0, 0, 2, 0, 0, 0, 0, 2, 2, 
0, 0, 0, 0, 2, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 1, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 2, 0, 0, 1, 0, 0, 1, 0, 0, 1, 
0, 0, 0, 1, 1, 1, 0, 0, 2, 0, 4, 0, 4, 4, 1, 4, 0, 0, 0, 0, 0};

PROGMEM prog_char Parameter__displayTypeModalValues__0[] = "knob";
PROGMEM prog_char Parameter__displayTypeModalValues__1[] = "toggle";
PROGMEM prog_char Parameter__displayTypeModalValues__2[] = "dropdownlarge";
PROGMEM prog_char Parameter__displayTypeModalValues__3[] = "slider";
PROGMEM prog_char Parameter__displayTypeModalValues__4[] = "dropdown";
PROGMEM prog_char Parameter__displayTypeModalValues__5[] = "dropdownsmall";
PROGMEM prog_char Parameter__displayTypeModalValues__6[] = "reversetoggle";
PROGMEM prog_char Parameter__displayTypeModalValues__7[] = "dropdownhuge";


PROGMEM char *Parameter__displayTypeModalValues[8] = { Parameter__displayTypeModalValues__0, 
Parameter__displayTypeModalValues__1, 
Parameter__displayTypeModalValues__2, 
Parameter__displayTypeModalValues__3, 
Parameter__displayTypeModalValues__4, 
Parameter__displayTypeModalValues__5, 
Parameter__displayTypeModalValues__6, 
Parameter__displayTypeModalValues__7};

PROGMEM byte Parameter__type [1100] = { 3, 4, 4, 4, 3, 1, 1, 1, 4, 0, 1, 3, 1, 5, 9, 3, 1, 3, 
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6, 7, 8, 10, 12, 1, 0, 0, 0, 
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 1, 1, 0, 6, 7, 8, 10, 12, 0, 
1, 3, 3, 3, 3, 3, 4, 4, 4, 3, 4, 4, 4, 4, 1, 1, 3, 3, 1, 3, 3, 7, 8, 10, 3, 4, 4, 3, 0, 4, 1, 4, 4, 1, 1, 4, 3, 1, 0, 1, 1, 4, 3, 4, 3, 1, 4, 4, 3, 1, 5, 4, 4, 4, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 1, 1, 4, 4, 4, 3, 3, 3, 4, 4, 1, 3, 3, 4, 1, 3, 3, 3, 1, 3, 3, 4, 3, 
2, 1, 2, 1, 1, 3, 3, 3, 3, 7, 8, 10, 1, 0, 5, 5, 3, 3, 3, 4, 4, 4, 3, 3, 3, 4, 3, 3, 3, 
1, 3, 4, 5, 3, 3, 3, 3, 3, 3, 4, 3, 4, 6, 7, 8, 11, 12, 3, 1, 3, 3, 0, 1, 3, 3, 4, 4, 4, 4, 3, 3, 5, 4, 4, 
1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 4, 4, 4, 4, 3, 3, 5, 6, 7, 8, 11, 12, 0, 3, 1, 1, 3, 1, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 3, 3, 4, 3, 3, 1, 1, 1, 1, 1, 4, 1, 3, 1, 4, 4, 5, 4, 1, 4, 4, 4, 4, 3, 3, 1, 4, 3, 
3, 3, 3, 3, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 1, 1, 1, 1, 6, 7, 8, 11, 12, 3, 0, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 1, 4, 3, 3, 3, 3, 1, 13, 13, 1, 0, 1, 1, 3, 1, 1, 3, 1, 3, 1, 3, 4, 4, 3, 3, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 13, 0, 3, 
1, 1, 4, 1, 3, 4, 3, 3, 1, 1, 6, 7, 8, 9, 12, 0, 1, 3, 4, 3, 5, 4, 3, 
1, 4, 1, 3, 3, 3, 3, 3, 1, 4, 1, 6, 7, 8, 9, 12, 0, 1, 1, 4, 5, 4, 3, 
3, 3, 3, 3, 1, 6, 7, 8, 9, 12, 3, 0, 3, 4, 4, 4, 3, 5, 
1, 1, 4, 1, 1, 5, 3, 4, 3, 3, 3, 6, 7, 8, 9, 12, 0, 1, 1, 3, 
1, 4, 4, 5, 3, 3, 7, 8, 10, 3, 5, 1, 0, 
1, 1, 1, 5, 3, 6, 7, 8, 9, 12, 0, 0, 
1, 1, 4, 3, 3, 1, 6, 7, 8, 10, 12, 3, 3, 3, 0, 
1, 1, 3, 3, 1, 1, 1, 1, 1, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 6, 7, 8, 11, 12, 3, 0, 3, 3, 3, 1, 1, 1, 1, 1, 1, 4, 4, 3, 3, 3, 3, 1, 13, 13, 13, 13, 13, 13, 13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 3, 3, 1, 1, 1, 4, 
1, 4, 4, 3, 7, 8, 10, 1, 0, 3, 3, 1, 4, 4, 
1, 5, 3, 3, 3, 10, 5, 0, 4, 4, 1, 3, 3, 3, 4, 3, 1, 1, 8, 4, 
3, 3, 4, 4, 7, 0, 1, 1, 3, 3, 8, 
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 7, 8, 10, 0, 
3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 
3, 3, 
6, 7, 8, 10, 12, 0, 
1, 4, 1, 3, 3, 3, 3, 3, 4, 4, 4, 1, 4, 1, 3, 3, 3, 3, 3, 4, 4, 4, 0, 6, 7, 8, 9, 12, 0, 1, 4, 1, 3, 3, 3, 3, 3, 4, 4, 4, 
1, 1, 4, 4, 4, 1, 3, 3, 4, 4, 4, 3, 6, 7, 8, 9, 12, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 
3, 3, 3, 1, 1, 3, 1, 3, 1, 3, 3, 6, 7, 8, 11, 12, 0, 
4, 1, 4, 4, 4, 4, 3, 3, 3, 3, 0, 7, 8, 10, 0, 
3, 4, 4, 4, 4, 1, 4, 4, 0, 7, 8, 10, 0, 
4, 4, 1, 4, 6, 7, 8, 9, 12, 0, 
4, 4, 3, 4, 4, 4, 3, 1, 1, 3, 4, 4, 4, 3, 1, 1, 3, 4, 4, 4, 3, 1, 1, 6, 7, 8, 10, 0, 
3, 3, 3, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 4, 4, 4, 4, 3, 1, 1, 1, 3, 6, 7, 8, 9, 12, 0, 4, 
1, 1, 3, 4, 4, 3, 3, 3, 4, 4, 4, 4, 4, 3, 3, 3, 3, 1, 1, 1, 1, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 6, 7, 8, 11, 12, 0, 1, 
3, 3, 1, 0, 3, 3, 7, 10, 1, 
3, 4, 4, 4, 1, 
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 7, 8, 10, 0, 
1, 4, 3, 3, 3, 1, 1, 4, 3, 3, 3, 1, 1, 1, 4, 4, 4, 3, 4, 3, 1, 1, 4, 4, 4, 3, 4, 3, 4, 4, 3, 3, 13, 1, 4, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 13, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 
6, 7, 8, 9, 0, 3, 1, 3, 1, 1, 3, 3, 1, 
1, 3, 3, 1, 1, 1, 7, 8, 10, 0, 1, 4, 1, 1, 1, 1, 1, 1, 0, 0, 1};

PROGMEM prog_char Parameter__typeModalValues__0[] = "NONE";
PROGMEM prog_char Parameter__typeModalValues__1[] = "INT";
PROGMEM prog_char Parameter__typeModalValues__2[] = "INTXL";
PROGMEM prog_char Parameter__typeModalValues__3[] = "LIN";
PROGMEM prog_char Parameter__typeModalValues__4[] = "LOG";
PROGMEM prog_char Parameter__typeModalValues__5[] = "LOGLOG";
PROGMEM prog_char Parameter__typeModalValues__6[] = "MIX";
PROGMEM prog_char Parameter__typeModalValues__7[] = "LEVEL";
PROGMEM prog_char Parameter__typeModalValues__8[] = "PAN";
PROGMEM prog_char Parameter__typeModalValues__9[] = "BYP1";
PROGMEM prog_char Parameter__typeModalValues__10[] = "BYP2";
PROGMEM prog_char Parameter__typeModalValues__11[] = "BYP3";
PROGMEM prog_char Parameter__typeModalValues__12[] = "GMIX";
PROGMEM prog_char Parameter__typeModalValues__13[] = "DUMMY";


PROGMEM char *Parameter__typeModalValues[14] = { Parameter__typeModalValues__0, 
Parameter__typeModalValues__1, 
Parameter__typeModalValues__2, 
Parameter__typeModalValues__3, 
Parameter__typeModalValues__4, 
Parameter__typeModalValues__5, 
Parameter__typeModalValues__6, 
Parameter__typeModalValues__7, 
Parameter__typeModalValues__8, 
Parameter__typeModalValues__9, 
Parameter__typeModalValues__10, 
Parameter__typeModalValues__11, 
Parameter__typeModalValues__12, 
Parameter__typeModalValues__13};

PROGMEM unsigned int Parameter__defaultValue[1100] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 
0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

PROGMEM int Parameter__minDispValue[1100] = { -80, 1, 0, 0, -20, 0, 0, 0, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 
-12, -12, -12, -12, -12, -12, -12, -12, -12, -12, 0, -80, -1, 0, 0, 0, 0, 0, 0, 
20, 100, 100, 100, 200, 0, 0, 0, 0, 0, -12, -12, -12, -12, -12, 0, 0, 0, 0, -80, -1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 10, 2000, 200, 1, 0, 400, 10, 4000, 0, 0, 0, -1, 0, 0, 0, -80, -1, 0, 0, 0, 40, 0, 0, 50, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 400, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -12, -12, -12, -12, -12, -12, -12, -12, 0, 0, 0, 400, 400, 0, 0, 2000, 10, 100, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, 0, 30, 0, 0, 0, 
0, 0, 0, 0, 0, -80, -80, -1, -1, -80, -1, 0, 0, 0, 0, 0, 0, 0, 0, 20, 200, 0, 0, 0, 0, 2000, 0, 0, 0, 
0, 0, 200, 0, 0, 0, 0, -40, -40, 0, 20, 0, 0, 0, -80, -1, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 20, 100, 0, 0, -12, -12, 0, 0, 100, 
0, 0, 0, 0, -1, -1, -1, -1, -1, 0, 20, 200, 0, 0, 0, 0, 0, 0, -80, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, -80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 500, 0, 0, 0, 20, 100, 0, 0, -12, -12, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -80, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -80, 0, 0, 0, -1, 0, 0, 0, -2, -2, -50, -50, -50, -50, -24, -24, -24, -24, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 20, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, 30, 0, 0, 
0, 1, 0, 0, 0, 200, 0, 0, 0, 0, 0, -80, -1, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -80, -1, 0, 0, 0, 0, 0, 200, 0, 20, 0, 
0, 0, 0, -6, 0, 0, -80, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 1, 0, 50, 1, 0, 0, 0, -80, -1, 0, 0, 0, 0, 0, 0, 
0, 100, 500, 2, 0, 0, -80, -1, 0, 0, 0, 0, 0, 
0, 0, 0, 4, 0, 0, -80, -1, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, -80, -1, 0, 0, 0, 0, -1, 0, 
0, 0, -1, 0, 0, 0, 0, 0, 0, -50, -50, -24, -24, 0, 0, -1, -1, 0, 0, 0, 0, 0, 30, 0, -80, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, -1, 0, 4, 1, 2, 3, 4, 5, 6, 7, 0, 0, 2, 1, 0, 1, -24, -24, -24, -24, -24, -24, -24, -24, -24, -24, -24, -24, -24, -24, -24, -24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 
0, 20, 0, -12, -80, -1, 0, 0, 0, -1, -1, 0, 20, 200, 
0, 0, 0, 0, 0, 0, 0, 0, 20, 200, 0, -1, -12, -12, 200, -12, 0, 0, -1, 0, 
0, 0, 20, 200, -80, 0, 0, 0, -1, -1, -1, 
-20, -20, -20, -20, -1, -1, -1, -1, -20, -20, -20, -20, -20, -20, -20, -20, -80, -1, 0, 0, 
0, 0, 0, 0, -1, -1, -1, -1, -80, 0, 
0, 0, 
0, -80, -1, 0, 0, 0, 
0, 40, 0, -24, -50, 0, 0, -1, 0, 200, 0, 0, 40, 0, -24, -50, 0, 0, -1, 0, 200, 0, 0, 0, -80, -1, 0, 0, 0, 0, 20, 0, -24, -50, 0, 0, -1, 0, 200, 0, 
0, 0, 20, 2000, 0, 0, 0, -1, 0, 0, 0, 0, 0, -80, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 
0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, -80, -1, 0, 0, 0, 
40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -80, -1, 0, 0, 
-100, 0, 0, 0, 1, 0, 10, 200, 0, -80, -1, 0, 0, 
2, 0, 0, 200, 0, -80, -1, 0, 0, 0, 
50, 1000, -80, 1, 0, 0, -20, 0, 0, -80, 1, 0, 0, -20, 0, 0, -80, 1, 0, 0, -20, 0, 0, 0, -80, -1, 0, 0, 
0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -80, -1, 0, 0, 0, 200, 
0, 0, 0, 50, 0, 0, -1, -1, 0, 100, 100, 100, 100, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, 0, -80, -1, 0, 0, 0, 0, 
0, -1, 0, 0, -1, -1, -80, 0, 0, 
-100, 1, 0, 0, 0, 
-20, -20, -20, -20, -1, -1, -1, -1, -20, -20, -20, -20, -20, -20, -20, -20, -80, -1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -80, 0, 0, 0, 0, 0, 0, 0, -80, 0, 0, -100, 1, 30, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, -80, -1, 0, 0, 0, 0, -100, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, -80, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

PROGMEM unsigned int Parameter__maxDispValue[1100] = { 0, 20, 0, 1, 20, 3, 1, 2, 1000, 0, 8, 1, 2, 100, 2, 0, 1, 0, 
12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 1, 20, 1, 1, 0, 3, 0, 0, 0, 
2000, 10000, 10000, 10000, 20000, 10, 10, 10, 10, 10, 12, 12, 12, 12, 12, 2, 2, 0, 1, 20, 1, 1, 0, 0, 
172, 1, 1, 1, 1, 1, 1000, 20000, 2000, 4, 0, 40000, 1000, 40000, 3, 2, 1, 1, 12, 0, 1, 20, 1, 1, 0, 10, 400, 24, 0, 500, 3, 0, 2000, 4, 71, 0, 1, 19, 0, 1, 1, 10, 1, 4000, 24, 1, 10, 10, 1, 2, 1, 10, 100, 10, 1, 12, 12, 12, 12, 12, 12, 12, 12, 1, 0, 0, 40000, 40000, 11, 7, 20000, 1000, 10000, 1, 1, 1, 0, 10, 1, 0, 1, 0, 1, 1, 1, 1, 1, 100, 40, 20, 1, 
232, 11, 232, 11, 1, 0, 0, 1, 1, 20, 1, 1, 2, 0, 2, 2, 1, 1, 1, 2000, 20000, 4, 1, 1, 10, 20000, 0, 0, 1, 
20, 20, 20000, 1, 1, 1, 0, 10, 10, 0, 2000, 1, 10, 1, 20, 1, 4, 0, 1, 8, 1, 1, 1, 6, 12, 1, 2000, 10000, 10, 10, 12, 12, 1, 2, 10000, 
13, 6, 8, 1, 1, 1, 1, 1, 1, 78, 2000, 20000, 10, 20, 1, 1, 10, 1, 20, 1, 4, 0, 0, 1, 8, 8, 8, 1, 2, 78, 1, 1, 1, 1, 1, 1, 3, 3, 0, 1, 1, 4, 80, 0, 1, 1, 1, 3, 2, 2, 78, 78, 10, 8, 3, 78, 1000, 5000, 10, 10, 24, 2000, 10000, 10, 10, 12, 12, 1, 2, 0, 
2, 2, 2, 2, 78, 78, 78, 78, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 10, 10, 78, 78, 78, 78, 1, 20, 1, 4, 0, 1, 0, 9, 60, 1, 1, 1, 0, 1, 1, 1, 1, 3, 10, 1, 2, 2, 50, 50, 50, 50, 24, 24, 24, 24, 10000, 10000, 10000, 10000, 10, 10, 10, 10, 1, 80, 1, 1, 2, 1, 1, 1, 1, 1, 3, 3, 1, 2, 78, 78, 1, 1, 10, 0, 78, 1, 5, 1, 2000, 20000, 1, 1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 250, 0, 1, 
10, 4, 10, 78, 1, 20000, 0, 3, 8, 2, 1, 20, 1, 2, 0, 0, 3, 1, 2, 1, 10, 2000, 1, 
5, 10, 78, 1, 0, 0, 1, 3, 8, 100, 2, 1, 20, 1, 2, 0, 0, 3, 1, 20000, 1, 2000, 1, 
10, 1, 1, 6, 78, 1, 20, 1, 2, 0, 1, 0, 3, 10, 10, 10, 3, 10, 
7, 5, 10, 8, 78, 10, 0, 5000, 10, 3, 2, 1, 20, 1, 2, 0, 0, 2, 1, 0, 
7, 1000, 5000, 20, 1, 1, 20, 1, 1, 1, 2, 5, 0, 
9, 9, 9, 40, 1, 1, 20, 1, 2, 0, 0, 0, 
1, 8, 20, 1, 0, 78, 1, 20, 1, 1, 0, 3, 4, 1, 0, 
8, 5, 1, 1, 48, 48, 11, 17, 1, 50, 50, 24, 24, 1, 1, 1, 1, 2, 2, 1, 1, 2, 8100, 1, 20, 1, 4, 0, 1, 0, 1, 2, 2, 78, 78, 78, 78, 2, 1, 20000, 1, 1, 1, 1, 1, 8, 6, 7, 8, 9, 10, 11, 12, 31, 31, 16, 31, 1, 78, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 5, 1, 5, 1, 0, 0, 1, 1, 1, 2000, 
8, 20000, 10, 12, 20, 1, 1, 1, 1, 1, 1, 3, 2000, 20000, 
28, 1, 1, 1, 1, 1, 1, 0, 2000, 20000, 9, 1, 12, 12, 2000, 12, 24, 2, 1, 1, 
1, 1, 2000, 20000, 20, 0, 1, 3, 1, 1, 1, 
20, 20, 20, 20, 1, 1, 1, 1, 20, 20, 20, 20, 20, 20, 20, 20, 20, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 20, 1, 
1, 1, 
1, 20, 1, 1, 0, 0, 
7, 4000, 3, 24, 50, 0, 1, 1, 1, 20000, 10, 7, 4000, 3, 24, 50, 0, 1, 1, 1, 20000, 10, 0, 1, 20, 1, 2, 0, 0, 7, 20000, 3, 24, 50, 0, 1, 1, 1, 20000, 10, 
1, 3, 2000, 20000, 2, 1, 1, 1, 5, 1, 1, 1, 1, 20, 1, 2, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 2, 40, 5, 1, 5, 1, 5, 1, 0, 1, 20, 1, 4, 0, 0, 
800, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 20, 1, 1, 0, 
0, 1, 1, 1, 20, 6, 1000, 20000, 0, 20, 1, 1, 0, 
2000, 2, 1, 20000, 1, 20, 1, 2, 0, 0, 
500, 10000, 0, 20, 0, 1, 20, 1, 1, 0, 20, 0, 1, 20, 1, 1, 0, 20, 0, 1, 20, 1, 1, 1, 20, 1, 1, 0, 
1, 1, 1, 10, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 8, 8, 8, 10, 10, 10, 10, 1, 1, 1, 1, 3, 1, 20, 1, 2, 0, 0, 20000, 
1, 8, 1, 5000, 2, 1, 1, 1, 10, 10000, 10000, 10000, 10000, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 10, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 20, 1, 4, 0, 0, 1, 
1, 1, 5, 0, 1, 1, 20, 1, 2, 
0, 20, 1, 1, 12, 
20, 20, 20, 20, 1, 1, 1, 1, 20, 20, 20, 20, 20, 20, 20, 20, 20, 1, 1, 0, 
8, 30, 0, 0, 3, 78, 8, 30, 0, 0, 3, 78, 2, 1, 10, 10, 10, 1, 10, 0, 2, 1, 10, 10, 10, 1, 10, 0, 10, 10, 0, 4, 250, 1, 30, 78, 32, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 20, 1, 1, 0, 1, 1, 0, 3, 1, 1, 0, 1, 
1, 1, 1, 1, 1, 0, 20, 1, 1, 0, 7, 100, 2, 2, 1, 1, 2, 1, 0, 0, 1};

PROGMEM byte Parameter__precision [1100] = { 1, 3, 3, 2, 1, 0, 0, 0, 2, 0, 0, 1, 0, 2, 0, 3, 0, 2, 
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 
2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 0, 0, 0, 1, 1, 1, 0, 0, 0, 
0, 2, 2, 2, 2, 2, 1, 0, 1, 3, 1, 0, 1, 0, 0, 0, 2, 3, 0, 2, 2, 1, 1, 0, 2, 3, 1, 2, 0, 2, 0, 1, 2, 0, 0, 2, 3, 0, 0, 0, 0, 3, 3, 1, 2, 0, 2, 3, 3, 0, 2, 3, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 1, 0, 0, 0, 0, 2, 2, 2, 1, 2, 3, 0, 2, 1, 2, 0, 1, 2, 2, 0, 0, 2, 3, 1, 
0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 2, 2, 1, 2, 1, 1, 0, 3, 2, 1, 2, 0, 3, 3, 2, 
0, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 2, 1, 2, 2, 3, 3, 2, 2, 2, 2, 2, 
0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 3, 3, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 3, 0, 1, 0, 0, 0, 2, 3, 0, 2, 2, 3, 3, 2, 2, 0, 3, 1, 
1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 1, 1, 1, 0, 3, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 
0, 0, 3, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 3, 1, 2, 2, 1, 
0, 3, 0, 1, 1, 2, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 2, 3, 1, 
3, 1, 1, 2, 0, 1, 1, 1, 0, 0, 1, 0, 1, 3, 3, 3, 1, 2, 
0, 0, 3, 0, 0, 2, 1, 1, 2, 1, 2, 1, 1, 1, 0, 0, 0, 0, 0, 2, 
0, 0, 0, 2, 2, 2, 1, 1, 0, 2, 2, 0, 0, 
0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 0, 0, 
0, 0, 3, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 
0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 2, 
0, 1, 3, 2, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 
0, 2, 2, 2, 1, 0, 2, 0, 1, 1, 0, 3, 1, 1, 1, 1, 0, 0, 1, 0, 
1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 
2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0, 
1, 1, 1, 1, 2, 2, 2, 2, 1, 0, 
1, 1, 
0, 1, 1, 0, 0, 0, 
0, 2, 0, 0, 2, 1, 1, 1, 2, 0, 3, 0, 2, 0, 0, 2, 1, 1, 1, 2, 2, 3, 0, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 2, 1, 1, 1, 2, 2, 2, 
0, 0, 1, 0, 2, 0, 1, 1, 2, 2, 2, 1, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 
1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 
1, 2, 2, 2, 2, 0, 2, 2, 0, 1, 1, 0, 0, 
2, 3, 0, 0, 1, 1, 1, 0, 0, 0, 
1, 0, 1, 3, 3, 2, 1, 0, 0, 1, 3, 3, 2, 1, 0, 0, 1, 3, 3, 2, 1, 0, 0, 1, 1, 1, 0, 0, 
1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 3, 3, 3, 3, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 
0, 0, 1, 2, 3, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
2, 2, 0, 0, 1, 1, 1, 0, 0, 
1, 2, 2, 2, 0, 
2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0, 
0, 3, 1, 1, 1, 0, 0, 3, 1, 1, 1, 0, 0, 0, 2, 2, 2, 1, 2, 1, 0, 0, 2, 2, 2, 1, 2, 1, 2, 2, 1, 2, 0, 0, 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 
0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0};

PROGMEM byte Parameter__unit [1100] = { 1, 0, 4, 4, 1, 0, 0, 0, 2, 0, 0, 5, 0, 0, 0, 4, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0, 0, 0, 
2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 5, 1, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 2, 2, 2, 0, -8, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 2, 0, -8, 2, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 4, 4, 2, 2, 0, 0, 2, 2, 2, 0, 0, 5, 4, 0, 0, 0, 5, 4, 0, 5, 0, 0, 0, 2, 0, 2, 5, 
0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 5, 0, 5, 2, 2, 0, 0, 5, 0, 2, 4, 4, 0, 
0, 3, 2, 0, 5, 0, 4, 1, 1, 4, 2, 5, 2, 5, 1, 0, 0, 0, 5, 0, 5, 5, 0, 0, 0, 5, 2, 2, 0, 0, 1, 1, 0, 0, 2, 
0, 0, 4, 5, 5, 5, 5, 0, 5, 0, 2, 2, 2, 2, 5, 5, 0, 5, 1, 0, 0, 0, 0, 5, 0, 0, 4, 0, 5, 0, 5, 5, 5, 5, 0, 0, 6, 6, 4, 0, 0, 0, 1, 1, 4, 5, 5, 0, 0, 0, 0, 0, 2, 0, 6, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 1, 1, 0, 0, 4, 
4, 4, 4, 4, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 5, 1, 0, 0, 0, 5, 0, 0, 3, 5, 5, 5, 1, 5, 5, 5, 5, 0, 0, 5, 5, 5, 7, 7, 7, 7, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 5, 1, 5, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 5, 0, 5, 2, 2, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 4, 
0, 0, 2, 0, 5, 2, 4, 6, 0, 0, 5, 1, 0, 0, 0, 0, 0, 5, 2, 5, 0, 2, 5, 
0, 2, 0, 5, 5, 4, 5, 6, 0, 2, 0, 5, 1, 0, 0, 0, 0, 0, 0, 2, 0, 2, 5, 
2, 5, 5, 1, 0, 5, 1, 0, 0, 0, 5, 0, 5, 0, 3, 3, 5, 0, 
0, 0, 2, 0, 0, 0, 5, 2, 0, 6, 0, 5, 1, 0, 0, 0, 0, 0, 0, 0, 
0, 2, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 5, 5, 1, 0, 0, 0, 0, 0, 
0, 0, 2, 5, 5, 0, 5, 1, 0, 0, 0, 6, 5, 0, 0, 
0, 0, 5, 5, 0, 0, 0, 0, 0, 7, 7, 0, 0, 5, 5, 0, 0, 4, 4, 5, 5, 0, 0, 5, 1, 0, 0, 0, 5, 0, 5, 4, 4, 0, 0, 0, 0, 0, 0, 2, 4, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 5, 4, 4, 0, 0, 0, 2, 
0, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 
0, 0, 0, 0, 5, 0, 0, 0, 2, 2, 0, 0, 1, 1, 2, 1, 0, 0, 0, 2, 
5, 5, 2, 2, 1, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
5, 5, 5, 5, 0, 0, 0, 0, 1, 0, 
5, 5, 
5, 1, 0, 0, 0, 0, 
0, 2, 0, 0, 7, 5, 5, 0, 4, 2, 0, 0, 2, 0, 0, 7, 5, 5, 0, 4, 2, 0, 0, 5, 1, 0, 0, 0, 0, 0, 2, 0, 0, 7, 5, 5, 0, 4, 2, 0, 
0, 0, 2, 2, 0, 0, 5, 5, 0, 4, 4, 5, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
5, 5, 4, 0, 0, 5, 0, 5, 0, 5, 5, 5, 1, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
1, 4, 4, 4, 0, 0, 2, 2, 0, 1, 0, 0, 0, 
2, 0, 0, 2, 5, 1, 0, 0, 0, 0, 
2, 2, 1, 0, 4, 4, 1, 0, 0, 1, 0, 4, 4, 1, 0, 0, 1, 0, 4, 4, 1, 0, 0, 5, 1, 0, 0, 0, 
5, 5, 5, 2, 5, 5, 4, 4, 4, 4, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 6, 5, 1, 0, 0, 0, 0, 2, 
0, 0, 5, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 1, 0, 0, 
1, 0, 4, 4, 0, 
1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
0, 2, 5, 5, 6, 0, 0, 2, 5, 5, 6, 0, 0, 0, 4, 4, 4, 5, 4, 1, 0, 0, 4, 4, 4, 5, 4, 1, 4, 4, 1, 0, 0, 0, 2, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 
5, 1, 0, 0, 0, 5, 0, 1, 0, 0, 5, 5, 0, 
0, 5, 5, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

PROGMEM prog_char Parameter__unitModalValues__0[] = "";
PROGMEM prog_char Parameter__unitModalValues__1[] = "DB";
PROGMEM prog_char Parameter__unitModalValues__2[] = "Hz";
PROGMEM prog_char Parameter__unitModalValues__3[] = "Sec";
PROGMEM prog_char Parameter__unitModalValues__4[] = "MSec";
PROGMEM prog_char Parameter__unitModalValues__5[] = "Prc";
PROGMEM prog_char Parameter__unitModalValues__6[] = "Deg";
PROGMEM prog_char Parameter__unitModalValues__7[] = "Cents";


PROGMEM char *Parameter__unitModalValues[8] = { Parameter__unitModalValues__0, 
Parameter__unitModalValues__1, 
Parameter__unitModalValues__2, 
Parameter__unitModalValues__3, 
Parameter__unitModalValues__4, 
Parameter__unitModalValues__5, 
Parameter__unitModalValues__6, 
Parameter__unitModalValues__7};

PROGMEM unsigned int Parameter__numVals [1100] = { 65534, 65534, 65534, 65534, 65534, 4, 2, 3, 65534, 65534, 9, 65534, 3, 65534, 3, 65534, 2, 65534, 
65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 65534, 4, 65534, 65534, 65534, 
65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 3, 3, 65534, 65534, 65534, 65534, 2, 65534, 65534, 
173, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 4, 3, 65534, 65534, 13, 65534, 65534, 65534, 65534, 2, 65534, 65534, 65534, 65534, 65534, 65534, 4, 65534, 65534, 5, 72, 65534, 65534, 20, 65534, 2, 2, 65534, 65534, 65534, 65534, 2, 65534, 65534, 65534, 3, 65534, 65534, 65534, 65534, 2, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 12, 8, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 65534, 65534, 65534, 2, 65534, 65534, 65534, 2, 65534, 65534, 65534, 65534, 
65534, 12, 65534, 12, 2, 65534, 65534, 65534, 65534, 65534, 65534, 2, 3, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 
21, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 5, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 
14, 7, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 79, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 5, 65534, 65534, 65534, 9, 9, 65534, 2, 65534, 79, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 2, 5, 65534, 65534, 65534, 65534, 65534, 4, 3, 3, 79, 79, 65534, 9, 65534, 79, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 65534, 65534, 
65534, 65534, 65534, 65534, 79, 79, 79, 79, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 79, 79, 79, 79, 65534, 65534, 65534, 5, 65534, 65534, 65534, 10, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 65534, 65534, 65534, 65534, 65534, 2, 65534, 65534, 2, 65534, 79, 79, 65534, 65534, 65534, 65534, 79, 65534, 6, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 
11, 65534, 65534, 79, 65534, 65534, 65534, 65534, 9, 3, 65534, 65534, 65534, 3, 65534, 65534, 4, 65534, 65534, 65534, 65534, 65534, 65534, 
6, 65534, 79, 65534, 65534, 65534, 65534, 65534, 9, 65534, 3, 65534, 65534, 65534, 3, 65534, 65534, 4, 2, 65534, 65534, 65534, 65534, 
65534, 65534, 65534, 65534, 79, 65534, 65534, 65534, 3, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 
8, 6, 65534, 9, 79, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 3, 65534, 65534, 3, 65534, 65534, 
8, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 65534, 65534, 6, 65534, 
10, 10, 10, 65534, 65534, 65534, 65534, 65534, 3, 65534, 65534, 65534, 
2, 9, 65534, 65534, 65534, 79, 65534, 65534, 65534, 2, 65534, 65534, 65534, 65534, 65534, 
9, 6, 65534, 65534, 49, 49, 12, 18, 2, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 3, 65534, 65534, 65534, 65534, 5, 65534, 65534, 65534, 65534, 65534, 65534, 79, 79, 79, 79, 3, 2, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 78, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 6, 65534, 6, 65534, 65534, 65534, 2, 2, 2, 65534, 
9, 65534, 65534, 65534, 65534, 65534, 2, 2, 65534, 65534, 65534, 4, 65534, 65534, 
29, 65534, 65534, 65534, 65534, 2, 65534, 65534, 65534, 65534, 10, 65534, 65534, 65534, 65534, 65534, 65534, 3, 65534, 65534, 
65534, 65534, 65534, 65534, 65534, 65534, 2, 4, 65534, 65534, 65534, 
65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 65534, 
65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 
65534, 65534, 
65534, 65534, 65534, 2, 65534, 65534, 
8, 65534, 4, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 8, 65534, 4, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 3, 65534, 65534, 8, 65534, 4, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 
2, 65534, 65534, 65534, 65534, 2, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 3, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 
65534, 65534, 65534, 65534, 6, 65534, 6, 65534, 6, 65534, 65534, 65534, 65534, 65534, 5, 65534, 65534, 
65534, 2, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 65534, 
65534, 65534, 65534, 65534, 65534, 7, 65534, 65534, 65534, 65534, 65534, 2, 65534, 
65534, 65534, 2, 65534, 65534, 65534, 65534, 3, 65534, 65534, 
65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 2, 65534, 65534, 65534, 65534, 65534, 2, 2, 65534, 65534, 65534, 65534, 65534, 2, 2, 65534, 65534, 65534, 2, 65534, 
65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 9, 9, 9, 9, 65534, 65534, 65534, 65534, 65534, 2, 2, 2, 65534, 65534, 65534, 65534, 3, 65534, 65534, 65534, 
2, 9, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 2, 2, 2, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 5, 65534, 65534, 2, 
65534, 65534, 6, 65534, 65534, 65534, 65534, 2, 3, 
65534, 65534, 65534, 65534, 13, 
65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 65534, 
9, 65534, 65534, 65534, 65534, 79, 9, 65534, 65534, 65534, 65534, 79, 3, 2, 65534, 65534, 65534, 65534, 65534, 65534, 3, 2, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 65534, 79, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2, 2, 2, 
65534, 65534, 65534, 2, 65534, 65534, 2, 65534, 4, 2, 65534, 65534, 2, 
2, 65534, 65534, 2, 2, 65534, 65534, 65534, 2, 65534, 8, 65534, 3, 3, 2, 2, 3, 2, 65534, 65534, 65534};

PROGMEM int Parameter__idListVal [1100] = { -1, -1, -1, -1, -1, 1, 2, 3, -1, -1, 4, -1, 5, -1, 6, -1, 2, -1, 
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 7, -1, 8, -1, -1, -1, 
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 9, 9, -1, -1, -1, -1, 7, -1, -1, 
10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 11, 12, -1, -1, 13, -1, -1, -1, -1, 7, -1, -1, -1, -1, -1, -1, 14, -1, -1, 15, 16, -1, -1, 17, -1, 2, 2, -1, -1, -1, -1, 2, -1, -1, -1, 18, -1, -1, -1, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, 20, -1, -1, -1, -1, -1, -1, -1, -1, 2, -1, -1, -1, 2, -1, -1, -1, 21, -1, -1, -1, -1, 
-1, 22, -1, 22, 2, -1, -1, -1, -1, -1, -1, 7, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
24, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 25, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
26, 27, -1, -1, -1, -1, -1, -1, -1, 28, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 25, -1, -1, -1, 29, 29, -1, 2, -1, 28, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, 2, 30, -1, -1, -1, -1, -1, 31, 32, 32, 28, 28, -1, 29, -1, 28, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 33, -1, -1, 
-1, -1, -1, -1, 28, 28, 28, 28, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 28, 28, 28, 28, -1, -1, -1, 25, -1, -1, -1, 34, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 35, -1, -1, -1, -1, -1, 2, -1, -1, 36, -1, 28, 28, -1, -1, -1, -1, 28, -1, 37, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
38, -1, -1, 28, -1, -1, -1, -1, 29, 39, -1, -1, -1, 6, -1, -1, 31, -1, -1, -1, -1, -1, -1, 
40, -1, 28, -1, -1, -1, -1, -1, 29, -1, 39, -1, -1, -1, 6, -1, -1, 31, 2, -1, -1, -1, -1, 
-1, -1, -1, -1, 28, -1, -1, -1, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
41, 42, -1, 29, 28, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, -1, -1, 43, -1, -1, 
44, -1, -1, -1, -1, -1, -1, -1, 7, -1, -1, 45, -1, 
46, 46, 46, -1, -1, -1, -1, -1, 6, -1, -1, -1, 
47, 29, -1, -1, -1, 28, -1, -1, -1, 7, -1, -1, -1, -1, -1, 
48, 49, -1, -1, 50, 50, 51, 52, 53, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 54, -1, -1, -1, -1, 25, -1, -1, -1, -1, -1, -1, 28, 28, 28, 28, 55, 35, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, 56, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 37, -1, 37, -1, -1, -1, 57, 36, 2, -1, 
58, -1, -1, -1, -1, -1, 7, 59, -1, -1, -1, 31, -1, -1, 
60, -1, -1, -1, -1, 7, -1, -1, -1, -1, 61, -1, -1, -1, -1, -1, -1, 62, -1, -1, 
-1, -1, -1, -1, -1, -1, 63, 31, -1, -1, -1, 
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 7, -1, 
-1, -1, -1, -1, -1, -1, -1, -1, -1, 64, 
-1, -1, 
-1, -1, -1, 7, -1, -1, 
65, -1, 66, -1, -1, -1, -1, -1, -1, -1, -1, 65, -1, 66, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, -1, -1, 65, -1, 66, -1, -1, -1, -1, -1, -1, -1, -1, 
67, -1, -1, -1, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
-1, -1, -1, -1, 37, -1, 37, -1, 37, -1, -1, -1, -1, -1, 25, -1, -1, 
-1, 68, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 7, -1, 
-1, -1, -1, -1, -1, 69, -1, -1, -1, -1, -1, 7, -1, 
-1, -1, 2, -1, -1, -1, -1, 6, -1, -1, 
-1, -1, -1, -1, -1, -1, -1, 70, 71, -1, -1, -1, -1, -1, 70, 71, -1, -1, -1, -1, -1, 70, 71, -1, -1, -1, 7, -1, 
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 29, 29, 29, 29, -1, -1, -1, -1, -1, 36, 2, 2, -1, -1, -1, -1, 6, -1, -1, -1, 
72, 73, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 74, 74, 74, 74, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 25, -1, -1, 36, 
-1, -1, 45, -1, -1, -1, -1, 7, 75, 
-1, -1, -1, -1, 76, 
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 7, -1, 
29, -1, -1, -1, -1, 28, 29, -1, -1, -1, -1, 28, 77, 2, -1, -1, -1, -1, -1, -1, 77, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 78, -1, 28, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, 2, 2, 
-1, -1, -1, 79, -1, -1, 2, -1, 80, 2, -1, -1, 2, 
81, -1, -1, 2, 2, -1, -1, -1, 7, -1, 82, -1, 83, 83, 2, 33, 84, 2, -1, -1, -1};

PROGMEM prog_char Factory__Cabinet__0[] = "1x6 OVAL";
PROGMEM prog_char Factory__Cabinet__1[] = "1x8 TWEED";
PROGMEM prog_char Factory__Cabinet__2[] = "1x10 GOLD";
PROGMEM prog_char Factory__Cabinet__3[] = "1x10 BLUE";
PROGMEM prog_char Factory__Cabinet__4[] = "1x12 TWEED";
PROGMEM prog_char Factory__Cabinet__5[] = "1x12 BLACK";
PROGMEM prog_char Factory__Cabinet__6[] = "1x12 BLUE";
PROGMEM prog_char Factory__Cabinet__7[] = "1x12 E12L (RW)";
PROGMEM prog_char Factory__Cabinet__8[] = "1x12 STUDIO";
PROGMEM prog_char Factory__Cabinet__9[] = "1x12 EMI OPEN BACK (JM)";
PROGMEM prog_char Factory__Cabinet__10[] = "1x12 BOOGAFUNK BLUE (OH)";
PROGMEM prog_char Factory__Cabinet__11[] = "1x12 BOOGAFUNK E12L (OH)";
PROGMEM prog_char Factory__Cabinet__12[] = "1x12 TWEED BLUE (RW)";
PROGMEM prog_char Factory__Cabinet__13[] = "1x12 TWEED DELUXE (RW)";
PROGMEM prog_char Factory__Cabinet__14[] = "1x12 BRIT BLUE (RW)";
PROGMEM prog_char Factory__Cabinet__15[] = "1x12 BRIT G12H30 (RW)";
PROGMEM prog_char Factory__Cabinet__16[] = "1x15 BLUES";
PROGMEM prog_char Factory__Cabinet__17[] = "1x15 THUNDERBOLT (RW)";
PROGMEM prog_char Factory__Cabinet__18[] = "2x12 BLACK";
PROGMEM prog_char Factory__Cabinet__19[] = "2x12 BRIT";
PROGMEM prog_char Factory__Cabinet__20[] = "2x12 DOUBLEVERB D120 (RW)";
PROGMEM prog_char Factory__Cabinet__21[] = "2x12 DOUBLEVERB C12N (RW)";
PROGMEM prog_char Factory__Cabinet__22[] = "2x12 BLUE";
PROGMEM prog_char Factory__Cabinet__23[] = "2x12 TOP BOOST BLUE (RW)";
PROGMEM prog_char Factory__Cabinet__24[] = "2x12 TOP BOOST SILVER (RW)";
PROGMEM prog_char Factory__Cabinet__25[] = "2x12 BOUTIQUE (RW)";
PROGMEM prog_char Factory__Cabinet__26[] = "2x12 JAZZ (RW)";
PROGMEM prog_char Factory__Cabinet__27[] = "2x12 GOLD 30 FAR-FIELD (JM)";
PROGMEM prog_char Factory__Cabinet__28[] = "2x12 G12-65 FAR-FIELD (JM)";
PROGMEM prog_char Factory__Cabinet__29[] = "2x12 BOUTIQUE";
PROGMEM prog_char Factory__Cabinet__30[] = "2x15 DOUBLESHOW (RW)";
PROGMEM prog_char Factory__Cabinet__31[] = "4x10 TWEED BASS";
PROGMEM prog_char Factory__Cabinet__32[] = "4x10 BASSGUY P10 (RW)";
PROGMEM prog_char Factory__Cabinet__33[] = "4x12 BASKETWEAVE G12H30 (RW)";
PROGMEM prog_char Factory__Cabinet__34[] = "4x12 BASKETWEAVE G12L (RW)";
PROGMEM prog_char Factory__Cabinet__35[] = "4x12 BASKETWEAVE G12M20 (RW)";
PROGMEM prog_char Factory__Cabinet__36[] = "4x12 BASKETWEAVE G12M25 (RW)";
PROGMEM prog_char Factory__Cabinet__37[] = "4x12 1960A G12M (RW)";
PROGMEM prog_char Factory__Cabinet__38[] = "4x12 1960B T75 (RW)";
PROGMEM prog_char Factory__Cabinet__39[] = "4x12 1960B K120 (RW)";
PROGMEM prog_char Factory__Cabinet__40[] = "4x12 1960B V30 (RW)";
PROGMEM prog_char Factory__Cabinet__41[] = "4x12 HI-POWER (RW)";
PROGMEM prog_char Factory__Cabinet__42[] = "4x12 RECTO V30 (RW)";
PROGMEM prog_char Factory__Cabinet__43[] = "4x12 RECTO V30 (OH)";
PROGMEM prog_char Factory__Cabinet__44[] = "4x12 SOLO V12 (RW)";
PROGMEM prog_char Factory__Cabinet__45[] = "4x12 SOLO S12X (RW)";
PROGMEM prog_char Factory__Cabinet__46[] = "4x12 GERMAN V30 (RW)";
PROGMEM prog_char Factory__Cabinet__47[] = "4x12 GERMAN BOUTIQUE (RW)";
PROGMEM prog_char Factory__Cabinet__48[] = "4x12 PVH6160 (RW)";
PROGMEM prog_char Factory__Cabinet__49[] = "4x12 UBER T75 (RW)";
PROGMEM prog_char Factory__Cabinet__50[] = "4x12 UBER V30 (RW)";
PROGMEM prog_char Factory__Cabinet__51[] = "4x12 UBER T75+V30 (RW)";
PROGMEM prog_char Factory__Cabinet__52[] = "4x12 CITRUS V30 (RW)";
PROGMEM prog_char Factory__Cabinet__53[] = "4x12 MILLs 12K (OH)";
PROGMEM prog_char Factory__Cabinet__54[] = "4x12 SLM BLUE (OH)";
PROGMEM prog_char Factory__Cabinet__55[] = "4x12 SLM G65 (OH)";
PROGMEM prog_char Factory__Cabinet__56[] = "4x12 SLM H75 (OH)";
PROGMEM prog_char Factory__Cabinet__57[] = "4x12 SLM M75 (OH)";
PROGMEM prog_char Factory__Cabinet__58[] = "4x12 SLM V30 (OH)";
PROGMEM prog_char Factory__Cabinet__59[] = "4x12 20W";
PROGMEM prog_char Factory__Cabinet__60[] = "4x12 25W";
PROGMEM prog_char Factory__Cabinet__61[] = "4x12 V30";
PROGMEM prog_char Factory__Cabinet__62[] = "4x12 GERMAN";
PROGMEM prog_char Factory__Cabinet__63[] = "4x12 30W (ULTRA)";
PROGMEM prog_char Factory__Cabinet__64[] = "4x12 CALI";
PROGMEM prog_char Factory__Cabinet__65[] = "1x15 L.A. BASS";
PROGMEM prog_char Factory__Cabinet__66[] = "4x10 ALUMINUM BASS (RW)";
PROGMEM prog_char Factory__Cabinet__67[] = "8x10 SV BASS (RW)";
PROGMEM prog_char Factory__Cabinet__68[] = "4x12 V30 #1 (KALTHALLEN)";
PROGMEM prog_char Factory__Cabinet__69[] = "4x12 V30 #2 (KALTHALLEN)";
PROGMEM prog_char Factory__Cabinet__70[] = "4x12 V30 #3 (KALTHALLEN)";
PROGMEM prog_char Factory__Cabinet__71[] = "4x12 V30 #4 (KALTHALLEN)";
PROGMEM prog_char Factory__Cabinet__72[] = "4x12 G12T75 #1 (KALTHALLEN)";
PROGMEM prog_char Factory__Cabinet__73[] = "4x12 G12T75 #2 (KALTHALLEN)";
PROGMEM prog_char Factory__Cabinet__74[] = "1x8 CHAMPLIFIER MIX";
PROGMEM prog_char Factory__Cabinet__75[] = "1X8 VIBRATO CHAMPLIFIER MIX";
PROGMEM prog_char Factory__Cabinet__76[] = "1x10 PRINCE TONE BLACK MIX";
PROGMEM prog_char Factory__Cabinet__77[] = "1x10 PRINCE TONE SILVER MIX";
PROGMEM prog_char Factory__Cabinet__78[] = "1X12 JUNIOR BLUES MIX";
PROGMEM prog_char Factory__Cabinet__79[] = "1x12 DELUXE VERB MIX";
PROGMEM prog_char Factory__Cabinet__80[] = "1x12 DELUXE TWEED MIX";
PROGMEM prog_char Factory__Cabinet__81[] = "1x12 VIBRATO LUX MIX";
PROGMEM prog_char Factory__Cabinet__82[] = "1x12 CLASS-A 15W BLUE MIX";
PROGMEM prog_char Factory__Cabinet__83[] = "1x12 DIVISION 13 MIX";
PROGMEM prog_char Factory__Cabinet__84[] = "1x12 HOT KITTY MIX";
PROGMEM prog_char Factory__Cabinet__85[] = "1x12 HAWAII MIX";
PROGMEM prog_char Factory__Cabinet__86[] = "1x15 TWEED PRO MIX";
PROGMEM prog_char Factory__Cabinet__87[] = "1x15 EMPIRE MIX";
PROGMEM prog_char Factory__Cabinet__88[] = "2x10 SUPER TWEED MIX";
PROGMEM prog_char Factory__Cabinet__89[] = "2x10 VIBRATO LUX MIX";
PROGMEM prog_char Factory__Cabinet__90[] = "2x12 DOUBLE VERB MIX";
PROGMEM prog_char Factory__Cabinet__91[] = "2x12 PRO VERB MIX";
PROGMEM prog_char Factory__Cabinet__92[] = "2x12 CLASS-A 30W BLUE MIX";
PROGMEM prog_char Factory__Cabinet__93[] = "2x12 CLASS-A 30W SILVER MIX";
PROGMEM prog_char Factory__Cabinet__94[] = "2x12 SUPREMO MIX";
PROGMEM prog_char Factory__Cabinet__95[] = "2x12 SANTIAGO EJ1250";
PROGMEM prog_char Factory__Cabinet__96[] = "2x12 SANTIAGO ALTEC";
PROGMEM prog_char Factory__Cabinet__97[] = "3x10 VIBRATO KING MIX";
PROGMEM prog_char Factory__Cabinet__98[] = "4x10 BASSGUY MIX";
PROGMEM prog_char Factory__Cabinet__99[] = "4x10 SUPER VERB MIX";
PROGMEM prog_char Factory__Cabinet__100[] = "4x12 BASKETWEAVE GREEN MIX";
PROGMEM prog_char Factory__Cabinet__101[] = "4x12 BASKETWEAVE AX MIX";
PROGMEM prog_char Factory__Cabinet__102[] = "4x12 BASKETWEAVE TV MIX";
PROGMEM prog_char Factory__Cabinet__103[] = "4x12 CALI LEAD 80S MIX";
PROGMEM prog_char Factory__Cabinet__104[] = "4x12 RUMBLE EV12L MIX";
PROGMEM prog_char Factory__Cabinet__105[] = "4x12 RUMBLE EV12S MIX";
PROGMEM prog_char Factory__Cabinet__106[] = "4x12 PVH6160 MIX";
PROGMEM prog_char Factory__Cabinet__107[] = "4x12 PETRUCCI V30 MIX";
PROGMEM prog_char Factory__Cabinet__108[] = "1x15 SV BASS M88";
PROGMEM prog_char Factory__Cabinet__109[] = "1x15 SV BASS SUBKICK";
PROGMEM prog_char Factory__Cabinet__110[] = "4x10 SV BASS M88";
PROGMEM prog_char Factory__Cabinet__111[] = "4x10 SV BASS SUBKICK";
PROGMEM prog_char Factory__Cabinet__112[] = "4x10+TWEETER SV BASS M88";


PROGMEM char *Factory__Cabinet[113] = { Factory__Cabinet__0, 
Factory__Cabinet__1, 
Factory__Cabinet__2, 
Factory__Cabinet__3, 
Factory__Cabinet__4, 
Factory__Cabinet__5, 
Factory__Cabinet__6, 
Factory__Cabinet__7, 
Factory__Cabinet__8, 
Factory__Cabinet__9, 
Factory__Cabinet__10, 
Factory__Cabinet__11, 
Factory__Cabinet__12, 
Factory__Cabinet__13, 
Factory__Cabinet__14, 
Factory__Cabinet__15, 
Factory__Cabinet__16, 
Factory__Cabinet__17, 
Factory__Cabinet__18, 
Factory__Cabinet__19, 
Factory__Cabinet__20, 
Factory__Cabinet__21, 
Factory__Cabinet__22, 
Factory__Cabinet__23, 
Factory__Cabinet__24, 
Factory__Cabinet__25, 
Factory__Cabinet__26, 
Factory__Cabinet__27, 
Factory__Cabinet__28, 
Factory__Cabinet__29, 
Factory__Cabinet__30, 
Factory__Cabinet__31, 
Factory__Cabinet__32, 
Factory__Cabinet__33, 
Factory__Cabinet__34, 
Factory__Cabinet__35, 
Factory__Cabinet__36, 
Factory__Cabinet__37, 
Factory__Cabinet__38, 
Factory__Cabinet__39, 
Factory__Cabinet__40, 
Factory__Cabinet__41, 
Factory__Cabinet__42, 
Factory__Cabinet__43, 
Factory__Cabinet__44, 
Factory__Cabinet__45, 
Factory__Cabinet__46, 
Factory__Cabinet__47, 
Factory__Cabinet__48, 
Factory__Cabinet__49, 
Factory__Cabinet__50, 
Factory__Cabinet__51, 
Factory__Cabinet__52, 
Factory__Cabinet__53, 
Factory__Cabinet__54, 
Factory__Cabinet__55, 
Factory__Cabinet__56, 
Factory__Cabinet__57, 
Factory__Cabinet__58, 
Factory__Cabinet__59, 
Factory__Cabinet__60, 
Factory__Cabinet__61, 
Factory__Cabinet__62, 
Factory__Cabinet__63, 
Factory__Cabinet__64, 
Factory__Cabinet__65, 
Factory__Cabinet__66, 
Factory__Cabinet__67, 
Factory__Cabinet__68, 
Factory__Cabinet__69, 
Factory__Cabinet__70, 
Factory__Cabinet__71, 
Factory__Cabinet__72, 
Factory__Cabinet__73, 
Factory__Cabinet__74, 
Factory__Cabinet__75, 
Factory__Cabinet__76, 
Factory__Cabinet__77, 
Factory__Cabinet__78, 
Factory__Cabinet__79, 
Factory__Cabinet__80, 
Factory__Cabinet__81, 
Factory__Cabinet__82, 
Factory__Cabinet__83, 
Factory__Cabinet__84, 
Factory__Cabinet__85, 
Factory__Cabinet__86, 
Factory__Cabinet__87, 
Factory__Cabinet__88, 
Factory__Cabinet__89, 
Factory__Cabinet__90, 
Factory__Cabinet__91, 
Factory__Cabinet__92, 
Factory__Cabinet__93, 
Factory__Cabinet__94, 
Factory__Cabinet__95, 
Factory__Cabinet__96, 
Factory__Cabinet__97, 
Factory__Cabinet__98, 
Factory__Cabinet__99, 
Factory__Cabinet__100, 
Factory__Cabinet__101, 
Factory__Cabinet__102, 
Factory__Cabinet__103, 
Factory__Cabinet__104, 
Factory__Cabinet__105, 
Factory__Cabinet__106, 
Factory__Cabinet__107, 
Factory__Cabinet__108, 
Factory__Cabinet__109, 
Factory__Cabinet__110, 
Factory__Cabinet__111, 
Factory__Cabinet__112};

PROGMEM short Number__User__Cabinet = 100;



#endif
