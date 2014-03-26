/////////////////////////////////
//  @file		MIDYAX.h
//  Project		MIDYAX
/////////////////////////////////

#ifndef MIDYAX_H_
#define MIDYAX_H_

#include <avr/pgmspace.h>



//////////////////////
//  BCR2000 SETUP  // 
//////////////////////
#define BCR2000_ENCODER_NUMBER 32
#define BCR2000_PUSH_BUT_NUMBER 8


#define BCR2000_NumberOf_ControlPage_Buttons_DEFINE 16
#define BCR2000_NumberOf_Encoders_DEFINE 32
#define BCR2000_NumberOf_EncSwitchButtons_DEFINE 8
#define BCR2000_Max_NumberOf_ControlPage_DEFINE 32


// Mapping des Effect Type avec les 30 CONTROL PAGEs 
//short BCR2000_Preset_Effect_Type_ID [BCR2000_MAX_PRESET] = {
byte ControlPages_USER_Mapping[ BCR2000_Max_NumberOf_ControlPage_DEFINE ] = {
  /*  1 */  2,  /* COMPRESSOR*/
  /*  2 */ 14,  /* WHA-WHA */  
  /*  3 */ 13,  /* PHASER */
  /*  4 */ 19,  /* DRIVE */
  /*  5 */  5,  /* AMP 1 */
  /*  6 */  6,  /* CAB */
  /*  7 */ 10,  /* CHORUS */
  /*  8 */ 11,  /* FLANGER */
  /*  9 */  8,  /* DELAY */
  /* 10 */  9,  /* MULTI DELAY */                                      
  /* 11 */ 12,  /* ROTARY */
  /* 12 */  7,  /* REVERB */
  /* 13 */  3,  /* GRAPHICEQ */
  /* 14 */  4,  /* PARAMETRICEQ */
  /* 15 */ 18,  /* FILTER */
  /* 16 */ 22,  /* MIXER */

  /* 17 */ 31,  /* MULTIBANDCOMP */
  /* 18 */ 17,  /* PITCH */
  /* 19 */ 20,  /* ENHANCER */
  /* 20 */ 21 , /* EFFECTLOOP */
//  /* 21 */  5,  /* AMP 2 */
  /* 21 */ 26,  /* VOCODER */
  /* 22 */ 39,  /* TONE MATCH */
  /* 23 */ 32,  /* QUADCHORUS */
  /* 24 */ 25,  /* SYNTH */
  /* 25 */ 16,  /* PANTREM */
  /* 26 */ 27,  /* MEGATAP */
  /* 27 */ 29,  /* GATEEXPANDER
  /* 28 */ 35,  /* NOISEGATE */
  /* 29 */ 33,  /* RESONATOR */
  /* 30 */ 15,  /* FORMANT */
  /* 31 */ 28,  /* CROSSOVER */
  /* 32 */ 34,  /* VOLPAN */
};

//short ControlPages_USER_Parameter_Mapping[ BCR2000_Max_NumberOf_ControlPage_DEFINE ] = {
//  /*  1 */  2,  /* COMPRESSOR*/
//  /*  2 */ 14,  /* WHA-WHA */  
//  /*  3 */ 13,  /* PHASER */
//  /*  4 */ 19,  /* DRIVE */
//  /*  5 */  5,  /* AMP */
//  /*  6 */  6,  /* CAB */
//  /*  7 */ 10,  /* CHORUS */
//  /*  8 */ 11,  /* FLANGER */
//  /*  9 */  8,  /* DELAY */
//  /* 10 */  9,  /* MULTI DELAY */                                      
//  /* 11 */ 12,  /* ROTARY */
//  /* 12 */  7,  /* REVERB */
//  /* 13 */  3,  /* GRAPHICEQ */
//  /* 14 */  4,  /* PARAMETRICEQ */
//  /* 15 */ 18,  /* FILTER */
//  /* 16 */ 22,  /* MIXER */

//  /* 17 */ 31,  /* MULTIBANDCOMP */
//  /* 18 */ 17,  /* PITCH */
//  /* 19 */ 20,  /* ENHANCER */
//  /* 20 */ 21 , /* EFFECTLOOP */
         //  /* 21 */  5,  /* AMP 2 */
//  /* 21 */ 26,  /* VOCODER */
//  /* 22 */ 39,  /* TONE MATCH */
//  /* 23 */ 32,  /* QUADCHORUS */
//  /* 24 */ 25,  /* SYNTH */
//  /* 25 */ 16,  /* PANTREM */
//  /* 26 */ 27,  /* MEGATAP */
//  /* 27 */ 29,  /* GATEEXPANDER
//  /* 28 */ 35,  /* NOISEGATE */
//  /* 29 */ 33,  /* RESONATOR */
//  /* 30 */ 15,  /* FORMANT */
//  /* 31 */ 28,  /* CROSSOVER */
//  /* 32 */ 34,  /* VOLPAN */
//};

              
PROGMEM byte PROGMEM_BYTE___BCR2000_Encoder_CC_Mapping[ BCR2000_ENCODER_NUMBER + BCR2000_PUSH_BUT_NUMBER ] = {
  /*  1 */  1,  
  /*  2 */  2, 
  /*  3 */  3, 
  /*  4 */  4,
  /*  5 */  5,
  /*  6 */  6, 
  /*  7 */  7, 
  /*  8 */  8,
  
  /*  9 */  9, 
  /* 10 */  10,                                       
  /* 11 */  11, 
  /* 12 */  12,
  /* 13 */  13,
  /* 14 */  14,
  /* 15 */  15, 
  /* 16 */  16,

  /* 17 */  17, 
  /* 18 */  18,
  /* 19 */  19,
  /* 20 */  20,
  /* 21 */  21, 
  /* 22 */  22,
  /* 23 */  23,
  /* 24 */  24,
  
  /* 25 */  25,
  /* 26 */  26,
  /* 27 */  27,
  /* 28 */  28,
  /* 29 */  29,
  /* 30 */  30,
  /* 31 */  31,
  /* 32 */  32,
  
  /* 33 */  33,
  /* 34 */  34, 
  /* 35 */  35, 
  /* 36 */  36,
  /* 37 */  37,
  /* 38 */  38,
  /* 39 */  39,
  /* 40 */  40,
       };


////////////////////
//  AXE-FX SETUP  // 
////////////////////


#define MAX_NUMBER_EFFECTS 71
#define NUMBER_EFFECT_TYPE 39

           

PROGMEM byte PROGMEM_BYTE___EffectBlock__ONByPass_CC[MAX_NUMBER_EFFECTS] = {
37, 38, 39, 40, 41, 42, 43, 44, 45, 46,
47, 48, 49, 50, 59, 51, 0, 0, 52, 53,
54, 55, 56, 57, 58, 60, 61, 62, 63, 64,
65, 0, 66, 0, 0, 67, 68, 69, 70, 90,
91, 71, 72, 73, 74, 75, 76, 77, 78, 79,
80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
99, 92, 93, 94, 95, 96, 97, 98, 0, 0,
0};

PROGMEM byte PROGMEM_BYTE___EffectBlock__XY_CC[MAX_NUMBER_EFFECTS] = {
100, 101, 102, 103, 104, 105, 0, 0, 0, 0,
106, 107, 108, 109, 0, 0, 0, 0, 0, 0,
0, 0, 110, 111, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 112, 113, 114, 115, 0,
0, 0, 0, 116, 117, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 118, 119, 0, 0,
0};


// CREATE the AXE_effect Block structure
struct AXE_effect {
  byte  effect_id_hex;
  short  effect_onbypass_cc;
  short  effect_xy_cc; 
};  

// Defines all the AXE_effect Block structure
AXE_effect The_AXE_Effects [MAX_NUMBER_EFFECTS] ={
{ 0x64, 	43, 	0 },
{ 0x65, 	44, 	0 },
{ 0x66, 	62, 	0 },
{ 0x67, 	63, 	0 },
{ 0x68, 	71, 	0 },
{ 0x69, 	72, 	0 },
{ 0x6A, 	37, 	100 },
{ 0x6B, 	38, 	101 },
{ 0x6C, 	39, 	102 },
{ 0x6D, 	40, 	103 },
{ 0x6E, 	83, 	116 },
{ 0x6F, 	84, 	117 },
{ 0x70, 	47, 	106 },
{ 0x71, 	48, 	107 },
{ 0x72, 	69, 	0 },
{ 0x73, 	70, 	0 },
{ 0x74, 	41, 	104 },
{ 0x75, 	42, 	105 },
{ 0x76, 	56, 	110 },
{ 0x77, 	57, 	111 },
{ 0x78, 	86, 	0 },
{ 0x79, 	87, 	0 },
{ 0x7A, 	75, 	112 },
{ 0x7B, 	76, 	113 },
{ 0x7C, 	97, 	118 },
{ 0x7D, 	98, 	119 },
{ 0x7E, 	58, 	0 },
{ 0x7F, 	93, 	0 },
{ 0x80, 	90, 	0 },
{ 0x81, 	91, 	0 },
{ 0x82, 	77, 	114 },
{ 0x83, 	52, 	0 },
{ 0x84, 	53, 	0 },
{ 0x85, 	49, 	108 },
{ 0x86, 	50, 	109 },
{ 0x87, 	51, 	0 },
{ 0x88, 	59, 	0 },
{ 0x89, 	0, 	0 },
{ 0x8A, 	0, 	0 },
{ 0x8B, 	0, 	0 },
{ 0x8C, 	0, 	0 },
{ 0x8D, 	0, 	0 },
{ 0x8E, 	0, 	0 },
{ 0x8F, 	0, 	0 },
{ 0x90, 	88, 	0 },
{ 0x91, 	89, 	0 },
{ 0x92, 	92, 	0 },
{ 0x93, 	66, 	0 },
{ 0x94, 	45, 	0 },
{ 0x95, 	46, 	0 },
{ 0x96, 	60, 	0 },
{ 0x97, 	61, 	0 },
{ 0x98, 	85, 	0 },
{ 0x99, 	78, 	115 },
{ 0x9A, 	67, 	0 },
{ 0x9B, 	68, 	0 },
{ 0x9C, 	79, 	0 },
{ 0x9D, 	80, 	0 },
{ 0x9E, 	81, 	0 },
{ 0x9F, 	82, 	0 },
{ 0xA0, 	64, 	0 },
{ 0xA1, 	65, 	0 },
{ 0xA2, 	73, 	0 },
{ 0xA3, 	74, 	0 },
{ 0xA4, 	54, 	0 },
{ 0xA5, 	55, 	0 },
{ 0xA6, 	94, 	0 },
{ 0xA7, 	95, 	0 },
{ 0xA8, 	96, 	0 },
{ 0xA9, 	0, 	0 },
{ 0xAA, 	99, 	0 }
};


                     
PROGMEM byte PROGMEM_BYTE___AXEFX_Effect_ID[ MAX_NUMBER_EFFECTS ] = {
  0x64,0x65,0x66,0x67,0xA0,0xA1,0x68,0x69,0xA2,0xA3,
  0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,0x70,0x71,0x72,0x73,
  0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,
  0x7E,0x80,0x81,0x82,0x99,0x83,0x84,0xA4,0xA5,0x85,
  0x86,0x87,0x88,0x89,0x8A,0x8E,0x8F,0x90,0x91,0x92,
  0x93,0x94,0x95,0x96,0x97,0x98,0x9A,0x9B,0x9C,0x9D,
  0x9E,0x9F,0x7F,0xA6,0xA7,0xA8,0x8B,0x8C,0x8D,0xA9, 0xAA
  };


// Type of each effect block
PROGMEM byte PROGMEM_BYTE___AXEFX_Effect_Type[ MAX_NUMBER_EFFECTS ] = {
  2,2,3,3,3,3,4,4,4,4,
  5,5,6,6,7,7,8,8,9,9,
  10,10,11,11,12,12,13,13,14,14,
  15,16,16,17,17,18,18,18,18,19,
  19,20,21,22,22,23,24,25,25,26,
  27,28,28,29,29,30,31,31,32,32,
  33,33,34,34,34,34,35,36,37,38, 39
  };


// Number of block per effect type
PROGMEM byte PROGMEM_BYTE___AXEFX_Effect_Type_Number[ NUMBER_EFFECT_TYPE ] = {
  0,0,2,4,4,2,2,2,2,2,
  2,2,2,2,2,1,2,2,4,2,
  1,1,2,1,1,2,1,1,2,2,
  1,2,2,2,4,1,1,1,1
  };
//*/



////////////////////////////////////////////////////////
////////     AXE-FX
////////////////////////////////////////////////////////
#define AXEFX_NumOf_SCENES_DEFINE 8


////////////////////////////////////////////////////////
////////     CURRENT PRESET
////////////////////////////////////////////////////////
byte CurentPreset_CurrentSCENE_Number = -1;
char CurentPreset_AXEFX_Preset_Name[32];





////////////////////////////////////////////////////////
////////     Control_Pages & Mappings
////////////////////////////////////////////////////////
#define ControlPages_NumberOf_ET_ControlPages_DEFINE AXEFX_NumberOf_EffectTypes_DEFINE 
#define ControlPages_NumberOf_QuickAccess_Page_DEFINE 4
#define ControlPages_NumberOf_Sub_Pages_DEFINE 4






#endif // MIDYAX_H_
