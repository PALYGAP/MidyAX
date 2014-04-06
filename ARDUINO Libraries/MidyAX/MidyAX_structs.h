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


#ifndef MIDYAX_STRUCTS_H_
#define MIDYAX_STRUCTS_H_

#include <Arduino.h>

    struct MEM_EffectBlock {
        byte ID;
        char name[20]; // The max is "Feedback Return" = 15 characters
        byte effectTypeID;
        //char label[20]; // The max is "FeedbackReturn" = 14 characters   == Effect type label // Not needed the label is on the EffectType
        byte ONByPass_CC;
        byte XY_CC;
    };

    	
    struct MEM_Parameter {  
        byte ID;
        char name[20]; 
        char label[20];
        byte modifierID; // ID du modifiers qui peut piloter ce paramètres    0 = No modifier
        //bool sticky; //???
        byte displayType; // knob, slider, toggle, ... 
        byte type; // LIN, LOG, ...
        unsigned int defaultValue; // Default internal value  -- Not really needed since it could be reloaded from the AXE-FX if the effect type changes
        int minDispValue; 
        unsigned int maxDispValue;
        byte precision; //Précision interne ???
        byte unit; // dB, pF, Hz, ...
        unsigned int numVals; // Si <300 contient le nombre de modalitées possibles, sinon c'est le MAX de la valeur interne MIDI.
        int idListVal; //identifiant de la liste de valeurs.
    };
   
    struct MEM_EffectType {
        byte ID; //the ID is also the index in the table of effectTypes
        char name[20];
        char subTypeParamID; // -1 if no sub-type parameter for that EFFECT TYPE
        byte onBypassParamID; // -1 if no ONBYpass parameter for that EFFECT TYPE
        byte numOfParameters;  // Number of parameters for that effect
        //unsigned long  startAddresseOfParam ;
        // Construct a table of present/absent parameter depending on the effect subType
    };
    
#endif
