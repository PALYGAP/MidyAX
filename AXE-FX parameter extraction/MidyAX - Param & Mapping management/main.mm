//
//  main.cpp
//  MidyAX - Param & Mapping management
//
//  Created by Eric Feuilleaubois on 10/04/12.
//  Copyright (c) 2012 __LeafONICS__. All rights reserved.
//

//#define NDEBUG  // To uncomment to remove ASSERT statement evaluation
#define AXE_FX_PARAM_FILE_GENERATION

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "AxemlLoader.h"


// tutorial demo program
//#include "stdafx.h" // Only for Visual cC++
//#define TIXML_USE_STL
#include "tinyxml/tinyxml.h"
#include "tinyxml/tinystr.h"
#include "AXE-FX_XmlLoad.h"

// MAC CoreMidi library
#import <CoreMIDI/CoreMIDI.h>
#import <Foundation/Foundation.h>


// MIDI Stuffs
NSString *getName(MIDIObjectRef object);
void completionProc(MIDISysexSendRequest *request);
static void midiInputCallback(const MIDIPacketList *list, void *procRef, void *srcRef);
#define SYSEX_LENGTH 6000
MIDIEndpointRef destinationRef;
FILE *midiFP;
Byte sysExMessage[SYSEX_LENGTH];
unsigned int sysExLength = 0;
int EffectTypeNumb = 0, ParameterNumb = 0; //EffectBlockNumb = 0,
int MAX_EffectTypeNumb = 0,
    MAX_EffectBlockNumb = 0,
    MAX_ParameterNumb = 0;
float convertToFloat( Byte *received5bytes );



#define MAX_NUMBER_OF_PARAMETER_PER_EFFECT 200


AXEFX_effect theEffects[300];

int NumberOfEffects = 0;
bool waitingForSYSEXResponse = false;



struct EffectBlock {
    int ID;
    char name[32]; // The max is "Feedback Return" = 15 characters
    int effectTypeID;
    //char label[20]; // The max is "FeedbackReturn" = 14 characters   == Effect type label // Not needed the label is on the EffectType
    int ONByPass_CC;
    int XY_CC;
};
EffectBlock effectBlocks [200];

struct Parameter {
    int ID;
    char name[32]; 
    char label[32];
    int modifierID; // ID du modifiers qui peut piloter ce paramètres    0 = No modifier
    bool sticky; //???
    int displayType; // knob, slider, toggle, ... 
    int type; // LIN, LOG, ...
    int defaultValue; // Default internal value  -- Not really needed since it could be reloaded from the AXE-FX if the effect type changes
    int minDispValue; 
    int maxDispValue;
    int precision; //Précision interne ???
    int unit; // dB, pF, Hz, ...
    int numVals; // Si <300 contient le nombre de modalitées possibles, sinon c'est le MAX de la valeur interne MIDI.
    int idListVal; //identifiant de la liste de valeurs.
};

//char ListVal [100][200][200]; // ID de la liste de valeur  -  Index dans la liste   - Taille (199 char) de la chaine

struct EffectType {
    int ID; //the ID is also the index in the table of effectTypes
    char name[32];
    int subTypeParamID; // -1 if no sub-type parameter for that EFFECT TYPE
    int onBypassParamID; // -1 if no ONBYpass parameter for that EFFECT TYPE
    int numOfParameters;  // Number of parameters for that effect
    Parameter parameters[MAX_NUMBER_OF_PARAMETER_PER_EFFECT];
    // Construct a table of present/absent parameter depending on the effect subType
};
EffectType effectTypes [200];  // Les instances 0 et 1 sont vides !!!
EffectType controlTypes [40];  // Specific for ControllerParameters


/////////////////////////////////      MidyAX variables    //////////////
int numOfEffectBlocks, //containts the number of blocks --> do a -1 to access the right element in the table
numOfEffectTypes,
numOfParameters,
totalNumOfParameters = 0; 



enum
{
    B_SKIP,                // don't call setParam()
    B_INT,
    B_INTXL,        // accelerate
    B_LIN,
    B_LOG,
    B_LOGLOG,
    B_MIX,
    B_LEVEL,
    B_PAN,
    B_BYP1,
    B_BYP2,
    B_BYP3,
    B_GMIX,
    B_DUMMY,        // don't call setParam() but report range to editor
};
enum
{
    B_NONE,
    B_DB,
    B_HZ,
    B_SEC,
    B_MSEC,
    B_PRC,
    B_DEG,
    B_CENTS,
};


// List of MODAL VALUES for parameters
int numOfListOfParamModalValues = 0;
int effectTypeNbAndParamNb[1000][2];
char listOfParamModalValues[300][250][50]; // Nb effect type x Nb param x Nb modal values x Nb characters
int correspModalList[1000];







int main (int argc, const char * argv[])
{
	const char pFilename[200] = "/Users/ericfeuilleaubois/Documents/LeafONICS/_PROGRAMMING/MidyAX/MidyAX - Param & Mapping management/V3.0 - Version 10 AXE-FX II/default.axeml";
    FILE *fp;
    
    fp = fopen("/Users/ericfeuilleaubois/Documents/LeafONICS/_PROGRAMMING/MidyAX/MidyAX - Param & Mapping management/V3.0 - Version 10 AXE-FX II/Axe-fx_PARAM.txt", "w");
    assert(fp);
    
    // OPEN MIDI Logs file
    midiFP = fopen("/Users/ericfeuilleaubois/Documents/LeafONICS/_PROGRAMMING/MidyAX/MidyAX - Param & Mapping management/V3.0 - Version 10 AXE-FX II/MIDI-Logs.txt", "w");
    assert(midiFP);
	
    TiXmlDocument doc(pFilename);
	bool loadOkay  = doc.LoadFile();
    
    ///////////////////// CHARGEMENT DE default.axeml ////////////////////////////////////
	if (loadOkay)   {	printf("\n%s:\n", pFilename); }
	else            {	printf("Failed to load file \"%s\"\n", pFilename); }

    
    TiXmlNode *configNode = 0; 
    TiXmlElement* EffectPoolInstance = 0, *EffectPool = 0, *EffectParameterLists = 0, *EffectParameters = 0, *EffectParameter = 0;
    int id, effectTypeID, bypassParamNumber, typeParamNumber; //iTempo;
    char blockName[50], effectTypeName[50];
    
    

    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
    
    
    
    /////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////// Lecture des éléments de default.axeml ////////////////////////////////////    
    /////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    ////////////////////////////////////////////////////////////////////////
    // Reads the FIRST part of the default.axeml file  : EFFECT BLOCKS  ////
    ////////////////////////////////////////////////////////////////////////
    
    // Navigate to nodes of type EffectPoolInstance and then manipulate them as Elements and not Node, to access their properties
    configNode = doc.FirstChild( "CONFIG");
    assert( configNode );
    EffectPool = configNode->FirstChildElement("EffectPool");	
    assert( EffectPool );
    EffectPoolInstance = EffectPool->FirstChildElement("EffectPoolInstance");
    EffectPoolInstance = EffectPoolInstance->ToElement();
    assert( EffectPoolInstance  );

#ifdef AXE_FX_PARAM_FILE_GENERATION
    printf( "\n\n-----------------  EffectPool  -----------------\n\n");
    // Browse through all the elements and print to sdtout
    do
    {
       EffectPoolInstance->QueryIntAttribute( "id", &id );
        strcpy( blockName, EffectPoolInstance->Attribute( "name") );
        strcpy( effectTypeName, EffectPoolInstance->Attribute( "type") ) ;
        EffectPoolInstance->QueryIntAttribute( "typeID", &effectTypeID );
        
        printf( "EffectPoolInstance ID = %i\n", id);
        printf( "Block Name = %s\n", blockName);
        printf( "Effect Type = %s\n", effectTypeName);
        printf( "Effect Type ID = %i\n\n", effectTypeID);
        
        fprintf(fp,"%i %s %s %i\n", id, blockName, effectTypeName, effectTypeID);
        
    }
    while ((EffectPoolInstance = EffectPoolInstance->NextSiblingElement("EffectPoolInstance")) != 0);
#endif


    // Browses the EFFECT BLOCKS of the default.axeml file
    EffectPoolInstance = EffectPool->FirstChildElement("EffectPoolInstance");
    EffectPoolInstance = EffectPoolInstance->ToElement();
    assert( EffectPoolInstance  );
    numOfEffectBlocks = 0;
    do
    {
        if(strcmp(EffectPoolInstance->Attribute( "name"), "Dummy") == 0) continue; // Dummies are just dummies
        
         ///////////   FILLs the effectsBlocks table (EffectBlock structure)   ////////////////        
        EffectPoolInstance->QueryIntAttribute( "id", &(effectBlocks[numOfEffectBlocks].ID) );
        strcpy( effectBlocks[numOfEffectBlocks].name, EffectPoolInstance->Attribute( "name") );
        EffectPoolInstance->QueryIntAttribute( "typeID", &effectBlocks[numOfEffectBlocks].effectTypeID );
        
        numOfEffectBlocks++;
    }
    while ((EffectPoolInstance = EffectPoolInstance->NextSiblingElement("EffectPoolInstance")) != 0);    

    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Reads the SECOND part of the default.axeml file  : LIST OF THE EFFECTS and THEIR PARAMETERS  ////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    EffectParameterLists = configNode->FirstChildElement("EffectParameterLists");	
    assert( EffectParameterLists );
    EffectParameters = EffectParameterLists->FirstChildElement("EffectParameters");
    assert( EffectParameters );

    char parName[50], parStiky[50], parStringVals[50], minVal[50], maxVal[50];
    int parID,parModifierID;
    
    // Remove the ASSERT statements with proper testing of values. Take care of the possibility to have dummy elements
    
    fprintf(fp,"\n\n");
    
    numOfEffectTypes = 0;
    do
    {
        
        /// FOR NOW "MODIFIER" EFFECT TYPE and PARAM ARE EXCLUDED
        if( strcmp(EffectParameters->Attribute( "name"), "Modifier") == 0
            || strcmp(EffectParameters->Attribute( "name"), "Dummy") == 0) continue;
        
#ifdef AXE_FX_PARAM_FILE_GENERATION        
        strcpy( effectTypeName, EffectParameters->Attribute( "name") );
        EffectParameters->QueryIntAttribute( "typeID", &effectTypeID );
        EffectParameters->QueryIntAttribute( "bypassParam", &bypassParamNumber );
        EffectParameters->QueryIntAttribute( "typeParam", &typeParamNumber );
        
        printf( "\n\n-----------------  %s  -----------------\n", effectTypeName);
        printf( "Effect Type ID = %i\n", effectTypeID);
        printf( "Number of the Bypass Parameter = %i\n", bypassParamNumber);
        printf( "Number of the Type Parameter = %i\n\n", typeParamNumber);
        printf( "\n----------Parameters of %s  --------------\n", effectTypeName);
        
        fprintf(fp,"%s %i %i %i\n", effectTypeName, effectTypeID, bypassParamNumber, typeParamNumber);
#endif

        
        ///////// STARTs FILLING the effectType table (EffectType sctucture) ////////////////// 

        //  effectTypeID is used as the index of the table effectTypes !!!
        EffectParameters->QueryIntAttribute( "typeID", &effectTypeID );
        effectTypes[effectTypeID].ID = effectTypeID; // Stored in the structrure but index of table is ID
        strcpy( effectTypes[effectTypeID].name, EffectParameters->Attribute( "name") );
        EffectParameters->QueryIntAttribute( "bypassParam", &(effectTypes[effectTypeID].onBypassParamID) );
        EffectParameters->QueryIntAttribute( "typeParam", &(effectTypes[effectTypeID].subTypeParamID) );  
        
        
        EffectParameter = EffectParameters->FirstChildElement("EffectParameter");
        assert( EffectParameter );
        
        numOfEffectTypes++;
        
        numOfParameters = 0;
        do
        {
#ifdef AXE_FX_PARAM_FILE_GENERATION                
            EffectParameter->QueryIntAttribute( "id", &parID );
            strcpy( parName, EffectParameter->Attribute( "name") );
            EffectParameter->QueryIntAttribute( "modifierID", &parModifierID );
            strcpy( parStiky, EffectParameter->Attribute( "sticky") );
            strcpy( minVal, EffectParameter->Attribute( "minVal") );
            strcpy( maxVal, EffectParameter->Attribute( "maxVal") );
            strcpy( parStringVals, EffectParameter->Attribute( "stringVals") );
            
            printf( "Parameter ID = %i\n", parID);
            printf( "Parameter Name = %s\n", parName);
            printf( "Modifier ID = %i\n", parModifierID);
            printf( "Sticky = %s\n", parStiky);
            printf( "Minimum Value = %s\n", minVal);
            printf( "Maximum Value = %s\n", maxVal);
            printf( "String Values = %s\n\n", parStringVals);
            
            //fprintf(fp,"%i %s %i %s %s %s %s\n", parID, parName, parModifierID, parStiky, minVal, maxVal, parStringVals);
            fprintf(fp,"%i %i %s\n", parID, parModifierID, parStiky);
#endif
            
            EffectParameter->QueryIntAttribute( "id", &(effectTypes[effectTypeID].parameters[numOfParameters].ID ) );
            strcpy( effectTypes[effectTypeID].parameters[numOfParameters].name, EffectParameter->Attribute( "name") );
            EffectParameter->QueryIntAttribute( "modifierID", &(effectTypes[effectTypeID].parameters[numOfParameters].modifierID ));
            if ( strcmp (EffectParameter->Attribute( "sticky"), "false") == 0)
            { effectTypes[effectTypeID].parameters[numOfParameters].sticky = false; }
            else { effectTypes[effectTypeID].parameters[numOfParameters].sticky = true; }
            
            numOfParameters++;
        }
        while ( ( EffectParameter = EffectParameter->NextSiblingElement("EffectParameter") ) != 0 );

        effectTypes[effectTypeID].numOfParameters = numOfParameters;
        totalNumOfParameters += numOfParameters; //Caculate the total number of parameters 
        
        
#ifdef AXE_FX_PARAM_FILE_GENERATION          
        fprintf(fp,"\n\n");
#endif
    }
    while ( ( EffectParameters = EffectParameters->NextSiblingElement("EffectParameters") ) != 0 );    


    
    
    
    ////////////////////////////////////////////////////////////////////////////////
    // Reads the THIRD part of the default.axeml file  :  LIST OF "CONTROLLER"  ////
    ////////////////////////////////////////////////////////////////////////////////
    
    TiXmlElement* ControllerParameterLists = 0, *ControllerParameters = 0, *ControllerParameter = 0;    
    ControllerParameterLists = configNode->FirstChildElement("ControllerParameterLists");	
    assert( ControllerParameterLists );
    ControllerParameters = ControllerParameterLists->FirstChildElement("ControllerParameters");
    assert( ControllerParameters  );
    
    int numOfControlTypes;
    char controlTypeName[50];
    
    numOfControlTypes = 0;
    do
    {
        
#ifdef AXE_FX_PARAM_FILE_GENERATION        
        strcpy( controlTypeName, ControllerParameters->Attribute( "name") );
        ControllerParameters->QueryIntAttribute( "typeID", &effectTypeID );

        
        printf( "\n\n-----------------  %s  -----------------\n", effectTypeName);
        printf( "Effect Type ID = %i\n", effectTypeID);
        printf( "\n----------Parameters of %s  --------------\n", effectTypeName);
        
        fprintf(fp,"%s %i\n", controlTypeName, effectTypeID);
#endif
        
        
        ///////// STARTs FILLING the effectType table (EffectType sctucture) ////////////////// 
        
        //  effectTypeID is used as the index of the table effectTypes !!!
        ControllerParameters->QueryIntAttribute( "typeID", &effectTypeID );
        effectTypes[effectTypeID].ID = effectTypeID; // Stored in the structrure but index of table is ID
        strcpy( effectTypes[effectTypeID].name, ControllerParameters->Attribute( "name") );
       
        
        ControllerParameter = ControllerParameters->FirstChildElement("ControllerParameter");
        assert( ControllerParameter );
        
        numOfControlTypes++;
        
        numOfParameters = 0;
        do
        {
#ifdef AXE_FX_PARAM_FILE_GENERATION                
            ControllerParameter->QueryIntAttribute( "id", &parID );
            strcpy( parName, ControllerParameter->Attribute( "name") );
            ControllerParameter->QueryIntAttribute( "modifierID", &parModifierID );
            strcpy( parStiky, ControllerParameter->Attribute( "sticky") );
            strcpy( minVal, ControllerParameter->Attribute( "minVal") );
            strcpy( maxVal, ControllerParameter->Attribute( "maxVal") );
            strcpy( parStringVals, ControllerParameter->Attribute( "stringVals") );
            
            printf( "Parameter ID = %i\n", parID);
            printf( "Parameter Name = %s\n", parName);
            printf( "Modifier ID = %i\n", parModifierID);
            printf( "Sticky = %s\n", parStiky);
            printf( "Minimum Value = %s\n", minVal);
            printf( "Maximum Value = %s\n", maxVal);
            printf( "String Values = %s\n\n", parStringVals);
            
            //fprintf(fp,"%i %s %i %s %s %s %s\n", parID, parName, parModifierID, parStiky, minVal, maxVal, parStringVals);
            fprintf(fp,"%i %i %s\n", parID, parModifierID, parStiky);
#endif
            
            ControllerParameter->QueryIntAttribute( "id", &(controlTypes[effectTypeID].parameters[numOfParameters].ID ) );
            strcpy( controlTypes[effectTypeID].parameters[numOfParameters].name, ControllerParameter->Attribute( "name") );
            ControllerParameter->QueryIntAttribute( "modifierID", &(controlTypes[effectTypeID].parameters[numOfParameters].modifierID ));
            if ( strcmp (ControllerParameter->Attribute( "sticky"), "false") == 0)
            { controlTypes[effectTypeID].parameters[numOfParameters].sticky = false; }
            else { controlTypes[effectTypeID].parameters[numOfParameters].sticky = true; }
            
            numOfParameters++;
        }
        while ( ( ControllerParameter = ControllerParameter->NextSiblingElement("ControllerParameter") ) != 0 );
        
        controlTypes[effectTypeID].numOfParameters = numOfParameters;
        //totalNumOfParameters += numOfParameters; //Caculate the total number of parameters 
        
        
#ifdef AXE_FX_PARAM_FILE_GENERATION          
        fprintf(fp,"\n\n");
#endif
    }
    while ( ( ControllerParameters = ControllerParameters->NextSiblingElement("ControllerParameters") ) != 0 );    
  
    
    
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////
    // Reads the FOURTH part of the default.axeml file  :  PARAMETERS INFORMATIONS ////
    ///////////////////////////////////////////////////////////////////////////////////
    
    TiXmlElement *EffectLayouts = 0, *EditorControls = 0, *EffectVariants = 0, *EffectVariant = 0, *Page = 0, *Mixer = 0, *Parameters = 0, *Row = 0, *EditorControl = 0;
    char effectTypeLabel[50], effectTypeName2[50], syncVariantsToType[50], usegraph[50], effectVariantName[50], parameterLabel[50], parameterName[50], parameterDisplayType[50];
    int numOfDisplayedParam, effectTypeID2, effectVariantNumber;
    //numOfDisplayedParam --> Counts the number of displayed parameter in AXE-EDIT for an Effect Type Variant
    
    int numOfDisplayType = 0; // Counts the number of display type modal values (knobs, slidder, ...)
    char displayTypeModalValues[50][50];
    
    
    EffectLayouts = configNode->FirstChildElement("EffectLayouts");	
    assert( EffectLayouts );
    EditorControls = EffectLayouts->FirstChildElement("EditorControls");
    assert( EditorControls );

    do 
    {
        strcpy( effectTypeLabel, EditorControls->Attribute( "name") );
        // Skip MODIFIER 
        if ( strcmp(effectTypeLabel, "Modifier") == 0 ) continue;  /// FOR NOW MODIFIER and "EFFECT TYPE" and PARMAM ARE EXCLUDED
        
        EditorControls->QueryIntAttribute( "typeID", &effectTypeID2 );
        if ( EditorControls->Attribute( "type") != NULL)
            {strcpy( effectTypeName2, EditorControls->Attribute( "type") ) ;}
        else { strcpy( effectTypeName2, "" ) ;}
        if ( EditorControls->Attribute( "syncVariantsToType") != NULL) 
            { strcpy( syncVariantsToType, EditorControls->Attribute( "syncVariantsToType") ) ;}
        else { strcpy( syncVariantsToType, "" ) ;}
        if ( EditorControls->Attribute( "usegraph") != NULL) 
            { strcpy( usegraph, EditorControls->Attribute( "usegraph") ) ;}
        else { strcpy( usegraph, "" ) ;}

#ifdef AXE_FX_PARAM_FILE_GENERATION 
        printf( "\n\n--------  EFFECT TYPE %s  -------\n", effectTypeLabel);
        printf( "Label of the Effect Type = %s\n", effectTypeLabel);
        printf( "Effect Type ID = %i\n", effectTypeID2);
        printf( "Effect Type name = %s\n", effectTypeName2);    
        printf( "syncVariantsToType = %s\n", syncVariantsToType);    
        printf( "usegraph = %s\n", usegraph);
 
        fprintf(fp,"%s %s %i %s %s %s\n", effectTypeLabel, effectTypeLabel, effectTypeID2, effectTypeName2, syncVariantsToType, usegraph);
#endif
        
        EffectVariants = EditorControls->FirstChildElement("EffectVariants");
        assert( EffectVariants );
        EffectVariant = EffectVariants->FirstChildElement("EffectVariant");
        assert( EffectVariant );

        do 
        {
            EffectVariant->QueryIntAttribute( "value", &effectVariantNumber );
            strcpy( effectVariantName, EffectVariant->Attribute( "name") );
#ifdef AXE_FX_PARAM_FILE_GENERATION 
            printf( "\n\n-----  EFFECT VARIANT n° %i - %s ------\n", effectVariantNumber, effectVariantName);
            printf( "Effect Variant name = %s\n", effectVariantName);
            printf( "Effect Variant number = %i\n", effectVariantNumber);
#endif
            if (effectVariantNumber == 0) { fprintf(fp,"%s %i\n", effectVariantName, effectVariantNumber);}
            numOfDisplayedParam = 0;  //Counts the number of displayed parameter in AXE-EDIT for an Effect Type Variant
            
            Page = EffectVariant->FirstChildElement("Page");
            assert( Page );
            
            do 
            {
                Parameters = Page->FirstChildElement("Parameters");
                
                // Read EditorControl of the PARAMETERS block if any
                if ( (Row = Parameters->FirstChildElement("Row")) == NULL ) continue;
                
                do 
                {
                    if ( (EditorControl = Row->FirstChildElement("EditorControl")) == NULL ) continue;
                    do 
                    {
                        // If the ELEMENT has no attribute move to the next
                        if(EditorControl->FirstAttribute() == NULL) continue;
 
#ifdef AXE_FX_PARAM_FILE_GENERATION 
                        if( EditorControl->Attribute( "type") != NULL )
                        { strcpy( parameterDisplayType, EditorControl->Attribute( "type") );}
                        else { strcpy( parameterDisplayType, "" );}
                        
                        if( strcmp ( parameterDisplayType, "spacer") != 0) 
                        {
                            if( EditorControl->Attribute( "name") != NULL )
                                { strcpy( parameterLabel, EditorControl->Attribute( "name") );}
                            else { strcpy( parameterLabel, "" );}
                            if( EditorControl->Attribute( "parameterName") != NULL )
                                { strcpy( parameterName, EditorControl->Attribute( "parameterName") );}
                            else { strcpy( parameterName, "" );}

                            printf( "      Parameter label = %s   ", parameterLabel);
                            printf( "Mapped Prameter name = %s   ", parameterName);
                            printf( "Display type = %s\n", parameterDisplayType);  
                            
                            if (effectVariantNumber == 0) { fprintf(fp,"%i %s %s\n",  numOfDisplayedParam, parameterLabel, parameterDisplayType); numOfDisplayedParam++;}
                        }
#endif
                            
                        if( EditorControl->Attribute( "type") != NULL )
                            { strcpy( parameterDisplayType, EditorControl->Attribute( "type") );}
                        else { strcpy( parameterDisplayType, "" );}
                            
                        if( strcmp ( parameterDisplayType, "spacer") != 0) 
                        {
                            if( EditorControl->Attribute( "name") != NULL && EditorControl->Attribute( "parameterName") != NULL )
                            { 
                                int i, j;
                                strcpy( parameterName, EditorControl->Attribute( "parameterName") );
                                
                                // Search the parameter by its name in the effectType.parameter table
                                for(i=0; i < effectTypes[effectTypeID2].numOfParameters; i++)
                                {
                                    if( strcmp(effectTypes[effectTypeID2].parameters[i].name, parameterName) == 0 )
                                    {
                                        strcpy( effectTypes[effectTypeID2].parameters[i].label, EditorControl->Attribute( "name") );
                                        break;
                                    }
                                }
                                // if not match is found issue a warning
                                if (i == effectTypes[effectTypeID2].numOfParameters )
                                {
                                    printf( "PARAM NOT FOUND IN EFFECT TYPE ---- Parameter label = %s   ", parameterLabel);
                                    printf( "Mapped Prameter name = %s   ", parameterName);
                                    printf( "Display type = %s\n", parameterDisplayType); 
                                
                                }
                                else {
                                    // Build transco table for display type
                                    // Search for the value in the current table
                                    for(j=0; j < numOfDisplayType; j++)
                                    {
                                        if( strcmp( displayTypeModalValues[j], EditorControl->Attribute( "type") ) == 0) { break; }
                                    }
                                    // Add the value to the current table
                                    if( j == numOfDisplayType )
                                    {
                                        strcpy( displayTypeModalValues[j],  EditorControl->Attribute( "type") );
                                        numOfDisplayType++;
                                    } 
                                    
                                    // Apply transco table
                                    effectTypes[effectTypeID2].parameters[i].displayType = j;
                                }
                            } 
                        }                           
                    }
                    while ( ( EditorControl = EditorControl->NextSiblingElement("EditorControl") ) != 0 );    
                }
                while ( ( Row = Row->NextSiblingElement("Row") ) != 0 );

                
                // Read EditorControl of the MIXER block if any
                if( Page->FirstChildElement("Mixer") != NULL )
                {
                    Mixer = Page->FirstChildElement("Mixer");
                    assert( Mixer );
                    
                    if ( Mixer->FirstChildElement("Row") != NULL)
                    {
                        Row = Mixer->FirstChildElement("Row");
                        assert( Row );
                        
                        do 
                        {
                            if (Row->FirstChildElement("EditorControl") != NULL)
                            {
                                EditorControl = Row->FirstChildElement("EditorControl");
                                assert( EditorControl );    
                                
                                do 
                                {
                                    // If the ELEMENT has no attribute move to the next
                                    if(EditorControl->FirstAttribute() == NULL) continue;

#ifdef AXE_FX_PARAM_FILE_GENERATION 
                                    if( EditorControl->Attribute( "type") != NULL )
                                    { strcpy( parameterDisplayType, EditorControl->Attribute( "type") );}
                                    else { strcpy( parameterDisplayType, "" );}
                                    
                                    if( strcmp ( parameterDisplayType, "spacer") != 0) 
                                    {
                                        if( EditorControl->Attribute( "name") != NULL )
                                        { strcpy( parameterLabel, EditorControl->Attribute( "name") );}
                                        else { strcpy( parameterLabel, "" );}
                                        if( EditorControl->Attribute( "parameterName") != NULL )
                                        { strcpy( parameterName, EditorControl->Attribute( "parameterName") );}
                                        else { strcpy( parameterName, "" );}
                                        
                                        printf( "      Parameter label = %s   ", parameterLabel);
                                        printf( "Mapped Prameter name = %s   ", parameterName);
                                        printf( "Display type = %s\n", parameterDisplayType);  
                                        
                                        if (effectVariantNumber == 0) { fprintf(fp,"%i %s %s\n",  numOfDisplayedParam, parameterLabel, parameterDisplayType); numOfDisplayedParam++;}
                                    }
#endif
                                    if( EditorControl->Attribute( "type") != NULL )
                                    { strcpy( parameterDisplayType, EditorControl->Attribute( "type") );}
                                    else { strcpy( parameterDisplayType, "" );}
                                    
                                    if( strcmp ( parameterDisplayType, "spacer") != 0) 
                                    {
                                        if( EditorControl->Attribute( "name") != NULL && EditorControl->Attribute( "parameterName") != NULL )
                                        { 
                                            int i, j;
                                            strcpy( parameterName, EditorControl->Attribute( "parameterName") );
                                            
                                            // Search the parameter by its name in the effectType.parameter table
                                            for(i=0; i < effectTypes[effectTypeID2].numOfParameters; i++)
                                            {
                                                if( strcmp(effectTypes[effectTypeID2].parameters[i].name, parameterName) == 0 )
                                                {
                                                    strcpy( effectTypes[effectTypeID2].parameters[i].label, EditorControl->Attribute( "name") );
                                                    break;
                                                }
                                            }
                                            // if not match is found issue a warning
                                            if (i == effectTypes[effectTypeID2].numOfParameters )
                                            {
                                                printf( "PARAM NOT FOUND IN EFFECT TYPE ---- Parameter label = %s   ", parameterLabel);
                                                printf( "Mapped Prameter name = %s   ", parameterName);
                                                printf( "Display type = %s\n", parameterDisplayType); 
                                            }
                                            else {    
                                                // Build transco table for display type
                                                // Search for the value in the current table
                                                for(j=0; j < numOfDisplayType; j++)
                                                {
                                                    if( strcmp( displayTypeModalValues[j], EditorControl->Attribute( "type") ) == 0) { break; }
                                                }
                                                // Add the value to the current table
                                                if( j == numOfDisplayType )
                                                {
                                                    strcpy( displayTypeModalValues[j],  EditorControl->Attribute( "type") );
                                                    numOfDisplayType++;
                                                } 
                                                
                                                // Apply transco table
                                                effectTypes[effectTypeID2].parameters[i].displayType = j;
                                            }
                                        } 
                                    }
                                }
                                while ( ( EditorControl = EditorControl->NextSiblingElement("EditorControl") ) != 0 );
                            }
                        }
                        while ( ( Row = Row->NextSiblingElement("Row") ) != 0 );
                    }
                }
            }
            while ( ( Page = Page->NextSiblingElement("Page") ) != 0 ); 
            
        }
        while ( ( EffectVariant = EffectVariant->NextSiblingElement("EffectVariant") ) != 0 );
        
        fprintf(fp,"\n\n");
    }
    while ( ( EditorControls = EditorControls->NextSiblingElement("EditorControls") ) != 0 );     


    
    /////////////////////////////////////////////////////////////////////
    // Reads the FIFTH part of the default.axeml file : CABs labels  ////
    /////////////////////////////////////////////////////////////////////
    
    TiXmlElement *CabPool = 0, *Cab = 0;
    char factCabLabel[200][50];
    int numOfFactCab = 0, cabID, numberUserCabs;
    
    CabPool = configNode->FirstChildElement("CabPool");	
    assert( CabPool );
    
    CabPool->QueryIntAttribute( "numUserCabs", &numberUserCabs );
    
    Cab = CabPool->FirstChildElement("Cab");
    assert( Cab );

    
    printf( "\n\n--------  CABs  -------\n");
    printf( "Number of user Cabs on the AXE-FX = %i \n\n", numberUserCabs);
    
    fprintf(fp, "\n\n");
    fprintf(fp, "\n\n--------  CABs  -------\n");
    fprintf(fp, "Number of user Cabs on the AXE-FX = %i \n\n", numberUserCabs);
    do 
    {
        Cab->QueryIntAttribute( "id", &cabID );
        strcpy( factCabLabel[numOfFactCab], Cab->Attribute( "name") );

        printf( "CAB ID = %i    ", cabID);
        printf( "CAB label = %s\n", factCabLabel[numOfFactCab]);
        
        fprintf(fp,"%i %s \n",  cabID, factCabLabel[numOfFactCab]); 
        numOfFactCab++;
    }
    while ( ( Cab = Cab->NextSiblingElement("Cab") ) != 0 );     

    
    //////////////////////////////////////////////////////////////////////
    // Reads the fourth part of the default.axeml file : AMPs label   ////
    //////////////////////////////////////////////////////////////////////
    
    TiXmlElement *AmpPool = 0, *Amp = 0;
    char factAmpLabel[200][50];
    int numOfFactAmp = 0, ampID;
    
    AmpPool = configNode->FirstChildElement("AmpPool");	
    assert( AmpPool );
    
    Amp = AmpPool->FirstChildElement("Amp");
    assert( Amp );
    
    
    printf( "\n\n--------  AMPs  -------\n");
    
    fprintf(fp, "\n\n");
    fprintf(fp, "\n\n--------  AMPs  -------\n");
    do 
    {
        Amp->QueryIntAttribute( "id", &ampID );
        strcpy( factAmpLabel[numOfFactAmp], Amp->Attribute( "name") );
        
        printf( "AMP ID = %i    ", ampID);
        printf( "AMP label = %s\n", factAmpLabel[numOfFactAmp]);
        
        fprintf(fp,"%i %s \n",  ampID, factAmpLabel[numOfFactAmp]); 
        numOfFactAmp++;
    }
    while ( ( Amp = Amp->NextSiblingElement("Amp") ) != 0 );     
    
    
   
    //fclose(fp);    
    

    
    
    
    
    
    // QUERY the AXE-FX II for all the information on the parameters not present in the DEFAULT.AXEML file
    
    //Connect to the AXE-FX MIDI device ON THE MAC
    
    // How many MIDI devices do we have?
    ItemCount deviceCount = MIDIGetNumberOfDevices();
    
    // Iterate through all MIDI devices
    for (int i = 0 ; i < deviceCount ; ++i) {
        
        // Grab a reference to current device
        MIDIDeviceRef device = MIDIGetDevice(i);
        NSLog(@"Device: %@", getName(device));
        
        // Is this device online? (Currently connected?)
        SInt32 isOffline = 0;
        MIDIObjectGetIntegerProperty(device, kMIDIPropertyOffline, &isOffline);
        NSLog(@"Device is online: %s", (isOffline ? "No" : "Yes"));
        
        // How many entities do we have?
        ItemCount entityCount = MIDIDeviceGetNumberOfEntities(device);
        
        // Iterate through this device's entities
        for (ItemCount j = 0 ; j < entityCount ; ++j) {
            
            // Grab a reference to an entity
            MIDIEntityRef entity = MIDIDeviceGetEntity(device, j);
            NSLog(@"  Entity: %@", getName(entity));
            
            // Iterate through this device's source endpoints (MIDI In)
            ItemCount sourceCount = MIDIEntityGetNumberOfSources(entity);
            for (ItemCount k = 0 ; k < sourceCount ; ++k) {
                
                // Grab a reference to a source endpoint
                MIDIEndpointRef source = MIDIEntityGetSource(entity, k);
                NSLog(@"    Source: %@", getName(source));
            }
            
            // Iterate through this device's destination endpoints
            ItemCount destCount = MIDIEntityGetNumberOfDestinations(entity);
            for (ItemCount k = 0 ; k < destCount ; ++k) {
                
                // Grab a reference to a destination endpoint
                MIDIEndpointRef dest = MIDIEntityGetDestination(entity, k);
                NSLog(@"    Destination: %@", getName(dest));
            }
        }
        NSLog(@"------");
    }
    
 
	// Send a SYSEX message
	NSString *myDeviceName = @"AXE-FX II";
	int myDeviceLocation = -1;

    //Looks for the AXE-FX MIDI device
    for (int i = 0 ; i < deviceCount ; ++i) 
	{
        MIDIDeviceRef device = MIDIGetDevice(i);
		if( device )
		{
			CFStringRef deviceName;
			if( MIDIObjectGetStringProperty(device, kMIDIPropertyName, &deviceName) == noErr)
			{
				NSString *foundName = (__bridge NSString *) deviceName;
				if( [foundName isEqualToString:myDeviceName] )
				{
					myDeviceLocation = i;
                    NSLog(@"Found MIDI DEVICE : %@", myDeviceName);
				}
			}
            CFArrayRef *midiProperties;
            
            MIDIObjectGetProperties(device, (CFPropertyListRef *) &midiProperties, YES);
            //NSLog(@"Midi properties: %d \n %@", i, midiProperties);
            
		}
	}
    if( myDeviceLocation == -1 )
    {
        NSLog(@"The AXE-FX II MIDI Device was not found on the MAC");
        return false;
    }
    else{ NSLog(@"The AXE-FX II MIDI Device found on the MAC"); }
    
    // Log info of the AXE-FX II MIDI device
    CFArrayRef *midiProperties;
	MIDIDeviceRef myMIDIDevice = MIDIGetDevice(myDeviceLocation);
    MIDIObjectGetProperties(myMIDIDevice, (CFPropertyListRef *) &midiProperties, YES);
    NSLog(@"Midi properties:\n %@", midiProperties);
    
    // Log info of the AXE-FX II MIDI destination   
	NSLog(@"Getting Entities for MIDI device");
	MIDIEntityRef entDestinationRef = MIDIDeviceGetEntity(myMIDIDevice,0);
	if( !entDestinationRef ) return false;
	NSLog(@"Getting Destination for MIDI device");
	destinationRef = MIDIEntityGetDestination(entDestinationRef,0);
	if( !destinationRef ) return false;

    
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    // Sending a SYSEX to the AXE_FX

    EffectTypeNumb= 2;
	//EffectBlockNumb = 0; 
    ParameterNumb = 0;
    MAX_EffectTypeNumb = numOfEffectTypes + 2 ;
	MAX_EffectBlockNumb = numOfEffectBlocks; // for(int i=2; i < numOfEffectTypes + 2 ; i++)
    MAX_ParameterNumb = effectTypes[EffectTypeNumb].numOfParameters;


	NSString *SysExCommandString = @"F0 00 01 74 03 08 0E F7";  // @"F0 00 01 74 03 16 74 00 02 00 66 F7"; 

	//Converting String to DATA
	SysExCommandString = [SysExCommandString stringByReplacingOccurrencesOfString:@" " withString:@""];
	NSMutableData *commandToSend= [[NSMutableData alloc] init];
	unsigned char whole_byte;
	char byte_char[3] = {'\0','\0','\0'};
	int commandLength = [SysExCommandString length] /2;
	for(int i=0; i < commandLength; i++)
	{
		byte_char[0] = [SysExCommandString characterAtIndex:i*2];
		byte_char[1] = [SysExCommandString characterAtIndex:i*2+1];
		whole_byte = strtol(byte_char, NULL, 16);
		[commandToSend appendBytes:&whole_byte length:1]; 
	}

	int length = [commandToSend length];

	const unsigned char *p = ( const unsigned char *) CFDataGetBytePtr((__bridge CFDataRef) commandToSend);

	MIDISysexSendRequest sendRequest;
	sendRequest.destination = destinationRef;
	sendRequest.data = (Byte *) p;
	sendRequest.bytesToSend = length;
	sendRequest.complete = 0;
	sendRequest.completionProc = completionProc;
	sendRequest.completionRefCon = &sendRequest;

    waitingForSYSEXResponse = true;
	MIDISendSysex(&sendRequest);

	NSLog(@"The SYSEX command: %@ was sent to the AXE-FX II", commandToSend);
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    // Receiving a SYSEX message

	MIDIClientRef midiClient;

	OSStatus result;
    
	result = MIDIClientCreate(CFSTR("MIDI client"), NULL, NULL, &midiClient);
	if (result != noErr) {
		NSLog(@"Error creating MIDI client: %@ ",
			//GetMacOSStatusErrorString(result),
              [NSError errorWithDomain:NSOSStatusErrorDomain code:result userInfo:nil]);
			//GetMacOSStatusCommentString(result)
            //[NSError errorWithDomain:NSOSStatusErrorDomain code:result userInfo:nil],);
			return false;
	}

	MIDIPortRef inputPort;
	result = MIDIInputPortCreate(midiClient, CFSTR("Input"), midiInputCallback, NULL, &inputPort);

	MIDIObjectRef endPoint;
	MIDIObjectType foundObj;
    
	result = MIDIObjectFindByUniqueID(-1690171313, &endPoint, &foundObj);
	result = MIDIPortConnectSource(inputPort, endPoint, NULL);
    
    CFRunLoopRunInMode(kCFRunLoopDefaultMode, 30, false);

  
    fclose(midiFP);
    

    
    
    
    
    // SEARCH for same list and build correspondance table
    // 0 in the table means no correspondance 
    int found;
    correspModalList[1] = 0;
    for(int i = 2; i <= numOfListOfParamModalValues; i++)  // Start at modal list number 2 otherwise finds 1 matches with 1 !!!
    {
        found = 0;
        correspModalList[i] = 0;
        for(int j = 0; j < i ; j++)
        {   
            int numvalI, numvalJ;
            numvalI = effectTypes[ effectTypeNbAndParamNb[i][0] ].parameters[ effectTypeNbAndParamNb[i][1] ].numVals;
            numvalJ = effectTypes[ effectTypeNbAndParamNb[j][0] ].parameters[ effectTypeNbAndParamNb[j][1] ].numVals;
            
            if ( numvalI == numvalJ )
            {
                int k;
                for(k = 0; k < numvalI; k++)
                {
                    if ( strcmp( listOfParamModalValues[i][k], listOfParamModalValues[j][k]) != 0) break;
                }
                if ( k == numvalI)
                {
                    // Add a correpondance !!!
                    correspModalList[i] = j;
                    found = 1;
                }
            }
            if (found == 1) break;
        }
    }  
    
    // Translate the numbers of the modal list
    // Put new number for list with no correspondance    
    int newNumberOfModalList = 1;
    int newCorespondanceTable[1000];
    for(int i = 1; i <= numOfListOfParamModalValues; i++)
    {
        if (correspModalList[i] == 0)
        {
            newCorespondanceTable[i] = newNumberOfModalList;
            newNumberOfModalList++;
        } 
    }
    newNumberOfModalList--;
    
    // Transcode number for list with correspondance
    for(int i = 1; i <= numOfListOfParamModalValues; i++)
    {
        if (correspModalList[i] != 0)
        {
            newCorespondanceTable[i] = newCorespondanceTable[ correspModalList[i] ];
        } 
    }
    // Update the field in the EffectType.parameter struct 
    for(int i = 1; i <= numOfListOfParamModalValues; i++)
    {
        effectTypes[ effectTypeNbAndParamNb[i][0] ].parameters[ effectTypeNbAndParamNb[i][1] ].idListVal = newCorespondanceTable[i];
    }  
    
    
    
    
    // WRITE modal values tables to file 
    fprintf(fp,"\n\nTABLE of modal values for the DISPLAY TYPE of a parameter\n");
    for(int i = 0; i < numOfDisplayType; i++)
    {
        fprintf(fp,"%s\n", displayTypeModalValues[i] );
    }
    

    int numOfParamType = 14; // Stores the number of modal value of PARAMETER TYPE (LIN, LOG, ...)
	char	ParamType_0[15] = "NONE",
			ParamType_1[15] = "INT",
			ParamType_2[15] = "INTXL",
			ParamType_3[15] = "LIN",
			ParamType_4[15] = "LOG",
			ParamType_5[15] = "LOGLOG",
			ParamType_6[15] = "MIX",
			ParamType_7[15] = "LEVEL",
			ParamType_8[15] = "PAN",
			ParamType_9[15] = "BYP1",
			ParamType_10[15] = "BYP2",
			ParamType_11[15] = "BYP3",
			ParamType_12[15] = "GMIX",
			ParamType_13[15] = "DUMMY";
	char *paramTypeModalValues[50] = {ParamType_0, ParamType_1, ParamType_2, ParamType_3, ParamType_4, ParamType_5, ParamType_6, ParamType_7, ParamType_8, ParamType_9, ParamType_10, ParamType_11, ParamType_12, ParamType_13};

    int numOfUnit = 8; // Stores the number of modal value of UNIT(dB, ...)
	char	Unit_0[15] = "",
			Unit_1[15] = "DB",
			Unit_2[15] = "Hz",
			Unit_3[15] = "Sec",
			Unit_4[15] = "MSec",
			Unit_5[15] = "Prc",
			Unit_6[15] = "Deg",
			Unit_7[15] = "Cents";
	char *unitModalValues[50] = {Unit_0, Unit_1, Unit_2, Unit_3, Unit_4, Unit_5, Unit_6, Unit_7};

    fprintf(fp,"\n\nTABLE of modal values for the PARAMETER TYPE of a parameter\n");
    for(int i = 0; i < numOfParamType; i++)
    {
        fprintf(fp,"%s\n", paramTypeModalValues[i] );
    }
    
    fprintf(fp,"\n\nTABLE of modal values for the UNIT of a parameter\n");
    for(int i = 0; i < numOfUnit; i++)
    {
        fprintf(fp,"%s\n", unitModalValues[i] );
    }
    
    fprintf(fp,"\n\nTABLE of modal values for the EFFECT TYPE PARAMETERS\n");
    fprintf(fp,"There are %i parameters with a list of modal values\n\n", numOfListOfParamModalValues);
    //for(int i = 0; i < numOfListOfParamModalValues; i++)
    for(int i = 1; i <= numOfListOfParamModalValues; i++)
    {
        if ( correspModalList[i] == 0 )
        {
            fprintf(fp,"List number %i for Efect Type %i and Parameter %i  -- %i values\n", i, effectTypeNbAndParamNb[i][0], effectTypeNbAndParamNb[i][1], effectTypes[ effectTypeNbAndParamNb[i][0] ].parameters[ effectTypeNbAndParamNb[i][1] ].numVals);
            for(int j = 0; j < effectTypes[ effectTypeNbAndParamNb[i][0] ].parameters[ effectTypeNbAndParamNb[i][1] ].numVals; j++)
            {
                fprintf(fp,"%s\n", listOfParamModalValues[i][j] );
            }
            fprintf(fp,"\n");
        }
    }    
    
    fprintf(fp,"\n\nCORRESPONDANCE DES LISTES\n");
    for(int i = 1; i <= numOfListOfParamModalValues; i++)
    {
        fprintf(fp,"%i %i\n", i, correspModalList[i]);
    }        
    
    
    
    fprintf(fp,"\n\n NEW CORRESPONDANCE DES LISTES\n");
    for(int i = 1; i <= numOfListOfParamModalValues; i++)
    {
        fprintf(fp,"%i %i\n", i, newCorespondanceTable[i]);
    }        
    
    fclose(fp);    

    
    
    
   
    
    
    
    
    
    
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    ///
    ///      FILE OUTPUT: MidyAX_Flash_Data_1.H (Header)
    ///
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    FILE *fp1 = fopen("/Users/ericfeuilleaubois/Documents/LeafONICS/_PROGRAMMING/MidyAX/MidyAX - Param & Mapping management/V3.0 - Version 10 AXE-FX II/MidyAX_Flash_Data_1.h", "w");
    assert(fp1);
    
    fprintf(fp1, "#ifndef MIDYAX_FLASH_DATA_1_H_\n");
    fprintf(fp1, "#define MIDYAX_FLASH_DATA_1_H_\n\n");
    fprintf(fp1, "#include <avr/pgmspace.h>\n\n\n");

    fprintf(fp1, "unsigned int MaxNumberOfControlPages = %i;\n", 32);
    fprintf(fp1, "unsigned int MaxNumberOfParameters = %i;\n", 48);
    fprintf(fp1, "unsigned int NumOfEffectTypes = %i;\n",  numOfEffectTypes);
    fprintf(fp1, "unsigned int TotalNumOfParameters = %i;\n", totalNumOfParameters); // = to numTotParam but calculate before
    fprintf(fp1, "unsigned int NumOfEffectBlocks = %i;\n", numOfEffectBlocks);
    
  
    
 
    /////////////////////////////////////////////////////////////////
    ////////           EFFECT BLOCKS                    /////////////
    /////////////////////////////////////////////////////////////////
    
    fprintf(fp1, "\n\n///////////////////////////////////////////////////\n\n");
    fprintf(fp1, "////////////////  EFFECT BLOCKS  //////////////////\n\n");
    fprintf(fp1, "///////////////////////////////////////////////////////\n\n");
    
    ///////////////      EffectBlock__ID 
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM byte EffectBlock__ID[%i] = { ", numOfEffectBlocks);
    for(int i=0; i < numOfEffectBlocks; i++)
    {
        fprintf(fp1, "%i", effectBlocks[i].ID);
        if ( i < numOfEffectBlocks - 1) { fprintf(fp1, ", "); }
    }
    fprintf(fp1, "};\n\n");
    

    ///////////////      EffectBlock__name 
    //////////////////////////////////////////////////////////////////////////
    for(int i=0; i < numOfEffectBlocks; i++)
    {
        fprintf(fp1, "PROGMEM prog_char EffectBlock__%i__name[] = \"%s\";\n", i, effectBlocks[i].name);
    }
    fprintf(fp1, "\n\n");
    
    fprintf(fp1, "PROGMEM char *EffectBlock__name[%i] = { ", numOfEffectBlocks);
    for(int i=0; i < numOfEffectBlocks; i++)
    {
        fprintf(fp1, "EffectBlock__%i__name", i);
        if ( i < numOfEffectBlocks - 1) { fprintf(fp1, ", "); }
    }
    fprintf(fp1, "};\n\n");    
    

    ///////////////      EffectBlock__effectTypeID
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM byte EffectBlock__effectTypeID[%i] = { ", numOfEffectBlocks);
    for(int i=0; i < numOfEffectBlocks; i++)
    {
        fprintf(fp1, "%i", effectBlocks[i].effectTypeID);
        if ( i < numOfEffectBlocks - 1) { fprintf(fp1, ", "); }
    }
    fprintf(fp1, "};\n\n");

    struct AXE_effect {
        int  effect_id_hex;
        short  effect_onbypass_cc;
        short  effect_xy_cc; 
    };  
    
    
    // ON/BYPASS CCs and X/Y CCs
    AXE_effect The_AXE_Effects [71] ={
        { 0x64, 	43, 	0, },
        { 0x65, 	44, 	0, },
        { 0x66, 	62, 	0, },
        { 0x67, 	63, 	0, },
        { 0x68, 	71, 	0, },
        { 0x69, 	72, 	0, },
        { 0x6A, 	37, 	100, },
        { 0x6B, 	38, 	101, },
        { 0x6C, 	39, 	102, },
        { 0x6D, 	40, 	103, },
        { 0x6E, 	83, 	116, },
        { 0x6F, 	84, 	117, },
        { 0x70, 	47, 	106, },
        { 0x71, 	48, 	107, },
        { 0x72, 	69, 	0, },
        { 0x73, 	70, 	0, },
        { 0x74, 	41, 	104, },
        { 0x75, 	42, 	105, },
        { 0x76, 	56, 	110, },
        { 0x77, 	57, 	111, },
        { 0x78, 	86, 	0, },
        { 0x79, 	87, 	0, },
        { 0x7A, 	75, 	112, },
        { 0x7B, 	76, 	113, },
        { 0x7C, 	97, 	118, },
        { 0x7D, 	98, 	119, },
        { 0x7E, 	58, 	0, },
        { 0x7F, 	93, 	0, },
        { 0x80, 	90, 	0, },
        { 0x81, 	91, 	0, },
        { 0x82, 	77, 	114, },
        { 0x83, 	52, 	0, },
        { 0x84, 	53, 	0, },
        { 0x85, 	49, 	108, },
        { 0x86, 	50, 	109, },
        { 0x87, 	51, 	0, },
        { 0x88, 	59, 	0, },
        { 0x89, 	0, 	0, },
        { 0x8A, 	0, 	0, },
        { 0x8B, 	0, 	0, },
        { 0x8C, 	0, 	0, },
        { 0x8D, 	0, 	0, },
        { 0x8E, 	0, 	0, },
        { 0x8F, 	0, 	0, },
        { 0x90, 	88, 	0, },
        { 0x91, 	89, 	0, },
        { 0x92, 	92, 	0, },
        { 0x93, 	66, 	0, },
        { 0x94, 	45, 	0, },
        { 0x95, 	46, 	0, },
        { 0x96, 	60, 	0, },
        { 0x97, 	61, 	0, },
        { 0x98, 	85, 	0, },
        { 0x99, 	78, 	115, },
        { 0x9A, 	67, 	0, },
        { 0x9B, 	68, 	0, },
        { 0x9C, 	79, 	0, },
        { 0x9D, 	80, 	0, },
        { 0x9E, 	81, 	0, },
        { 0x9F, 	82, 	0, },
        { 0xA0, 	64, 	0, },
        { 0xA1, 	65, 	0, },
        { 0xA2, 	73, 	0, },
        { 0xA3, 	74, 	0, },
        { 0xA4, 	54, 	0, },
        { 0xA5, 	55, 	0, },
        { 0xA6, 	94, 	0, },
        { 0xA7, 	95, 	0, },
        { 0xA8, 	96, 	0, },
        { 0xA9, 	0,      0, },
        { 0xAA, 	99, 	0, }
    };
    
    
    
    ///////////////      EffectBlock__ONByPass_CC
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM byte EffectBlock__ONByPass_CC[%i] = { ", numOfEffectBlocks);
    for(int i=0; i < numOfEffectBlocks; i++)
    {
        for(int j=0; j < numOfEffectBlocks; j++)
        {
            if(The_AXE_Effects[j].effect_id_hex == effectBlocks[i].ID )
            {
                //fprintf(fp1, "%i", effectBlocks[i].ONByPass_CC);
                fprintf(fp1, "%i", The_AXE_Effects[j].effect_onbypass_cc);  // TEMPORARY
                if ( i < numOfEffectBlocks - 1) { fprintf(fp1, ", "); }
            }
        }    
    }
    fprintf(fp1, "};\n\n");
    
    ///////////////      EffectBlock__XY_CC
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM byte EffectBlock__XY_CC[%i] = { ", numOfEffectBlocks);
    for(int i=0; i < numOfEffectBlocks; i++)
    {
        for(int j=0; j < numOfEffectBlocks; j++)
        {
            if(The_AXE_Effects[j].effect_id_hex == effectBlocks[i].ID )
            {
                //fprintf(fp1, "%i", effectBlocks[i].XY_CC);
                fprintf(fp1, "%i", The_AXE_Effects[j].effect_xy_cc); // TEMPORARY
                if ( i < numOfEffectBlocks - 1) { fprintf(fp1, ", "); }
            }
        }
    }
    fprintf(fp1, "};\n\n");
    
   

    /////////////////////////////////////////////////////////////////
    ////////           EFFECT TYPES                      /////////////
    /////////////////////////////////////////////////////////////////  
    
    bool NO_CONTROLLERS = false; // set to TRUE t exlude the controller Effect type 
    
    fprintf(fp1, "\n\n///////////////////////////////////////////////////\n\n");
    fprintf(fp1, "////////////////  EFFECT TYPES   //////////////////\n\n");
    fprintf(fp1, "///////////////////////////////////////////////////////\n\n");

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////// LOOP on numOfEffectTypes are specific and start from 2
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    
    
    ///////////////      EffectType__ID 
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM byte EffectType__ID[%i] = { ", numOfEffectTypes);
    for(int i=2; i < numOfEffectTypes + 2 ; i++)   
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        fprintf(fp1, "%i", effectTypes[i].ID);
        if ( i < numOfEffectTypes +1 ) { fprintf(fp1, ", "); }
    }
    fprintf(fp1, "};\n\n");
    
    ///////////////      EffectType__name 
    //////////////////////////////////////////////////////////////////////////
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        fprintf(fp1, "PROGMEM prog_char EffectType__%i__name[] = \"%s\";\n", i, effectTypes[i].name);
    }
    fprintf(fp1, "\n\n");
    
    fprintf(fp1, "PROGMEM char *EffectType__name[%i] = { ", numOfEffectTypes );
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        fprintf(fp1, "EffectType__%i__name", i);
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", "); }
    }
    fprintf(fp1, "};\n\n");        
    
    ///////////////      EffectType__subTypeParamID 
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM char EffectType__subTypeParamID[%i] = { ", numOfEffectTypes);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        fprintf(fp1, "%i", effectTypes[i].subTypeParamID);
        if ( i < numOfEffectTypes +1 ) { fprintf(fp1, ", "); }
    }
    fprintf(fp1, "};\n\n");    
    
    ///////////////      EffectType__onBypassParamID
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM byte EffectType__onBypassParamID[%i] = { ", numOfEffectTypes);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        fprintf(fp1, "%i", effectTypes[i].onBypassParamID);
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", "); }
    }
    fprintf(fp1, "};\n\n");
    
    ///////////////      EffectType__numOfParameters 
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM byte EffectType__numOfParameters[%i] = { ", numOfEffectTypes);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        fprintf(fp1, "%i", effectTypes[i].numOfParameters);
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", "); }
    }
    fprintf(fp1, "};\n\n");
    

    /////////////////////////////////////////////////////////////////
    ////////           PARAMETERS                       /////////////
    /////////////////////////////////////////////////////////////////  

    
    // Calcul du nombre total de paramètres
    int numTotParam = 0;
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        numTotParam = numTotParam + effectTypes[i].numOfParameters;
    }
    
    fprintf(fp1, "////////////////  PARAMETERS    //////////////////\n\n");
    
    // ID is there number in the list
    ///////////////      Parameter__ID 
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM byte Parameter__ID[%i] = { ", numTotParam);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "%i", effectTypes[i].parameters[j].ID);
            if ( j < effectTypes[i].numOfParameters - 1) { fprintf(fp1, ", "); }
        }
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n");    



    ///////////////      Parameter__name 
    //////////////////////////////////////////////////////////////////////////
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "PROGMEM prog_char EffectType__%i__Parameter__%i__name[] = \"%s\";\n", i,j,effectTypes[i].parameters[j].name);
        }
    }
    fprintf(fp1, "\n\n");
    
    fprintf(fp1, "PROGMEM char *Parameter__name[%i] = { ", numTotParam);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "EffectType__%i__Parameter__%i__name", i, j);
            if ( j < effectTypes[i].numOfParameters - 1) { fprintf(fp1, ", "); }
        }
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n");  
    
    ///////////////      Parameter__label 
    //////////////////////////////////////////////////////////////////////////
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "PROGMEM prog_char EffectType__%i__Parameter__%i__label[] = \"%s\";\n", i,j,effectTypes[i].parameters[j].label);
        }
    }
    fprintf(fp1, "\n\n");
    
    fprintf(fp1, "PROGMEM char *Parameter__label[%i] = { ", numTotParam);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "EffectType__%i__Parameter__%i__label", i, j);
            if ( j < effectTypes[i].numOfParameters - 1) { fprintf(fp1, ", "); }
        }
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n");  

    
    ///////////////      Parameter__modifierID 
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM byte Parameter__modifierID[%i] = { ", numTotParam);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "%i", effectTypes[i].parameters[j].modifierID);
            if ( j < effectTypes[i].numOfParameters - 1) { fprintf(fp1, ", "); }
        }
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n");    
    

    // The "sticky" param info is not used
    
    
    ///////////////      Parameter__displayType 
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM byte Parameter__displayType [%i] = { ", numTotParam);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "%i", effectTypes[i].parameters[j].displayType);
            if ( j < effectTypes[i].numOfParameters - 1) { fprintf(fp1, ", "); }
        }
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n"); 

    for(int i=0; i < numOfDisplayType; i++)
    {
        fprintf(fp1, "PROGMEM prog_char Parameter__displayTypeModalValues__%i[] = \"%s\";\n", i, displayTypeModalValues[i]);
    }
    fprintf(fp1, "\n\n");
    
    fprintf(fp1, "PROGMEM char *Parameter__displayTypeModalValues[%i] = { ", numOfDisplayType);
    for(int i=0; i < numOfDisplayType; i++)
    {
        fprintf(fp1, "Parameter__displayTypeModalValues__%i", i);
        if ( i < numOfDisplayType - 1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n");   
    

    ///////////////      Parameter__type 
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM byte Parameter__type [%i] = { ", numTotParam);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "%i", effectTypes[i].parameters[j].type);
            if ( j < effectTypes[i].numOfParameters - 1) { fprintf(fp1, ", "); }
        }
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n");

    for(int i=0; i < numOfParamType; i++)
    {
        fprintf(fp1, "PROGMEM prog_char Parameter__typeModalValues__%i[] = \"%s\";\n", i, paramTypeModalValues[i]);
    }
    fprintf(fp1, "\n\n");
    
    fprintf(fp1, "PROGMEM char *Parameter__typeModalValues[%i] = { ", numOfParamType);
    for(int i=0; i < numOfParamType; i++)
    {
        fprintf(fp1, "Parameter__typeModalValues__%i", i);
        if ( i < numOfParamType - 1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n"); 
    
    // These values depend on the su-type of the Effect Type --> to be loaded dynamically
    //////////////      Parameter__defaultValue 
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM unsigned int Parameter__defaultValue[%i] = { ", numTotParam);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "%i", effectTypes[i].parameters[j].defaultValue);
            if ( j < effectTypes[i].numOfParameters - 1) { fprintf(fp1, ", "); }
        }
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n");

    
    ///////////////      Parameter__minDispValue 
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM int Parameter__minDispValue[%i] = { ", numTotParam);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "%i", effectTypes[i].parameters[j].minDispValue);
            if ( j < effectTypes[i].numOfParameters - 1) { fprintf(fp1, ", "); }
        }
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n");
    
    
    ///////////////      Parameter__maxDispValue 
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM unsigned int Parameter__maxDispValue[%i] = { ", numTotParam);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "%i", effectTypes[i].parameters[j].maxDispValue);
            if ( j < effectTypes[i].numOfParameters - 1) { fprintf(fp1, ", "); }
        }
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n");
    
    
    ///////////////      Parameter__precision 
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM byte Parameter__precision [%i] = { ", numTotParam);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "%i", effectTypes[i].parameters[j].precision);
            if ( j < effectTypes[i].numOfParameters - 1) { fprintf(fp1, ", "); }
        }
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n");

    
    ///////////////      Parameter__unit 
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM byte Parameter__unit [%i] = { ", numTotParam);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "%i", effectTypes[i].parameters[j].unit);
            if ( j < effectTypes[i].numOfParameters - 1) { fprintf(fp1, ", "); }
        }
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n");
    
    
    for(int i=0; i < numOfUnit; i++)
    {
        fprintf(fp1, "PROGMEM prog_char Parameter__unitModalValues__%i[] = \"%s\";\n", i, unitModalValues[i]);
    }
    fprintf(fp1, "\n\n");
    
    fprintf(fp1, "PROGMEM char *Parameter__unitModalValues[%i] = { ", numOfUnit);
    for(int i=0; i < numOfUnit; i++)
    {
        fprintf(fp1, "Parameter__unitModalValues__%i", i);
        if ( i < numOfUnit - 1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n");
    
    
    
    ///////////////      Parameter__numVals
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM unsigned int Parameter__numVals [%i] = { ", numTotParam);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "%i", effectTypes[i].parameters[j].numVals);
            if ( j < effectTypes[i].numOfParameters - 1) { fprintf(fp1, ", "); }
        }
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n"); 
    
    
    ///////////////      Parameter__idListVal
    //////////////////////////////////////////////////////////////////////////
    fprintf(fp1, "PROGMEM int Parameter__idListVal [%i] = { ", numTotParam);
    for(int i=2; i < numOfEffectTypes + 2; i++)
    {
        if(effectTypes[i].ID == 37 and NO_CONTROLLERS) continue;
        for(int j=0; j < effectTypes[i].numOfParameters; j++)
        {
            fprintf(fp1, "%i", effectTypes[i].parameters[j].idListVal);
            if ( j < effectTypes[i].numOfParameters - 1) { fprintf(fp1, ", "); }
        }
        if ( i < numOfEffectTypes +1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n"); 
    

    /////////////////////////////////////////////////////////////////
    ////////           CAB                              /////////////
    /////////////////////////////////////////////////////////////////  
    for(int i=0; i < numOfFactCab; i++)
    {
        fprintf(fp1, "PROGMEM prog_char Factory__Cabinet__%i[] = \"%s\";\n", i, factCabLabel[i]);
    }
    fprintf(fp1, "\n\n");
    
    fprintf(fp1, "PROGMEM char *Factory__Cabinet[%i] = { ", numOfFactCab);
    for(int i=0; i < numOfFactCab; i++)
    {
        fprintf(fp1, "Factory__Cabinet__%i", i);
        if ( i < numOfFactCab - 1) { fprintf(fp1, ", \n"); }
    }
    fprintf(fp1, "};\n\n"); 
    
    fprintf(fp1, "PROGMEM short Number__User__Cabinet = %i;\n\n", numberUserCabs);
    
    fprintf(fp1, "\n\n#endif\n");
    
    fclose(fp1);

    

    
    
    
    
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    ///
    ///      FILE OUTPUT: MidyAX_Flash_Data_2.H (Header)
    ///
    ///
    ///      FILE OUTPUT: ALL THE ML_*.txt for the uSD of the uVGA
    ///
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    fp1 = fopen("/Users/ericfeuilleaubois/Documents/LeafONICS/_PROGRAMMING/MidyAX/MidyAX - Param & Mapping management/V3.0 - Version 10 AXE-FX II/MidyAX_Flash_Data_2.h", "w");
    assert(fp1);
    
    fprintf(fp1, "#ifndef MIDYAX_FLASH_DATA_2_H_\n");
    fprintf(fp1, "#define MIDYAX_FLASH_DATA_2_H\n\n");
    fprintf(fp1, "#include <avr/pgmspace.h>\n\n\n");

    fprintf(fp1, "unsigned int MaxNumberOfControlPages = %i;\n", 32);
    fprintf(fp1, "unsigned int MaxNumberOfParameters = %i;\n", 48);
    fprintf(fp1, "unsigned int NumOfEffectTypes = %i;\n",  numOfEffectTypes);
    fprintf(fp1, "unsigned int TotalNumOfParameters = %i;\n", totalNumOfParameters); // = to numTotParam but calculate before
    fprintf(fp1, "unsigned int NumOfEffectBlocks = %i;\n", numOfEffectBlocks);
    fprintf(fp1, "unsigned int NumOfModalList = %i;\n\n\n", newNumberOfModalList);    
    
    
    /////////////////////////////////////////////////////////////////
    ////////           LIST OF MODAL VALUES             /////////////
    /////////////////////////////////////////////////////////////////     
    

    fprintf(fp1,"\n\n//TABLE of modal values for the EFFECT TYPE PARAMETERS\n");
    //fprintf(fp1,"There are %i parameters with a list of modal values\n\n", numOfListOfParamModalValues);
    //for(int i = 0; i < numOfListOfParamModalValues; i++)
    
    FILE *fp2;
    int fileIndex = 1;
	char nameModalFile[500];
    for(int i = 1; i <= numOfListOfParamModalValues; i++)
    {
        if ( correspModalList[i] == 0 )
        {
			// Open a file for each modal list that has not already been written
			sprintf( nameModalFile, "/Users/ericfeuilleaubois/Documents/LeafONICS/_PROGRAMMING/MidyAX/UVGA/ML_%i.txt", fileIndex); 
			fp2 = fopen(nameModalFile, "w");
			fprintf(fp2,"%i\n", effectTypes[ effectTypeNbAndParamNb[i][0] ].parameters[ effectTypeNbAndParamNb[i][1] ].numVals );
			assert(fp2);

            for(int j = 0; j < effectTypes[ effectTypeNbAndParamNb[i][0] ].parameters[ effectTypeNbAndParamNb[i][1] ].numVals; j++)
            {
                fprintf(fp1,"PROGMEM prog_char PAR__MODLIST__%i__VAL__%i[] = \"%s\";\n", newCorespondanceTable[i],j,listOfParamModalValues[i][j] );
                fprintf(fp2,"%s\n", listOfParamModalValues[i][j] );
            }
            
            fprintf(fp1, "PROGMEM char *PAR__MODLIST__%i [%i] = { ", newCorespondanceTable[i], effectTypes[ effectTypeNbAndParamNb[i][0] ].parameters[ effectTypeNbAndParamNb[i][1] ].numVals);
            
            //fprintf(fp1,"List number %i for Efect Type %i and Parameter %i  -- %i values\n", i, effectTypeNbAndParamNb[i][0], effectTypeNbAndParamNb[i][1], effectTypes[ effectTypeNbAndParamNb[i][0] ].parameters[ effectTypeNbAndParamNb[i][1] ].numVals);
            for(int j = 0; j < effectTypes[ effectTypeNbAndParamNb[i][0] ].parameters[ effectTypeNbAndParamNb[i][1] ].numVals; j++)
            {
                fprintf(fp1,"PAR__MODLIST__%i__VAL__%i", newCorespondanceTable[i], j );
                if ( j < effectTypes[ effectTypeNbAndParamNb[i][0] ].parameters[ effectTypeNbAndParamNb[i][1] ].numVals - 1) { fprintf(fp1, ", "); }
            }
            fileIndex++;
			fclose(fp2);
            
            fprintf(fp1, "};\n\n"); 
        }
    }    
    
    fprintf(fp1,"\n\n//LIST OF THE MODAL LISTS\n");
    fprintf(fp1, "PROGMEM char **ModalList_list[%i] = { ", newNumberOfModalList);
    for(int i = 1; i <= newNumberOfModalList; i++)
    {
        fprintf(fp1,"PAR__MODLIST__%i", i);    
        if ( i < newNumberOfModalList ) { fprintf(fp1, ", "); }
    }      
    fprintf(fp1, "};\n\n"); 
    
    fprintf(fp1,"\n\n//SIZE OF THE MODAL LISTS\n");
    fprintf(fp1, "PROGMEM int ModalList_size[%i] = { ", newNumberOfModalList);
    int countNew =0;
    for(int i = 1; i <= numOfListOfParamModalValues; i++)
    {
        if ( correspModalList[i] == 0 )
        {        
            fprintf(fp1,"%i", effectTypes[ effectTypeNbAndParamNb[i][0] ].parameters[ effectTypeNbAndParamNb[i][1] ].numVals);
            countNew++;
            if ( countNew < newNumberOfModalList ) { fprintf(fp1, ", "); }
        }
    }
    fprintf(fp1, "};\n\n"); 

    fprintf(fp1, "\n\n#endif\n");
    fclose(fp1);
   
    
    
    
    
    
    
    
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    ///
    ///      FILE OUTPUT: MidyAX_Flash_Addresses.h (Header)
    ///
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    fp1 = fopen("/Users/ericfeuilleaubois/Documents/LeafONICS/_PROGRAMMING/MidyAX/MidyAX_Flash_Addresses.h", "w");
    assert(fp1);
    
    fprintf(fp1, "#ifndef MIDYAX_FLASH_ADDRESSES_H_\n");
    fprintf(fp1, "#define MIDYAX_FLASH_ADDRESSES_H_\n\n");
    
    unsigned long   FactoryControlPagesMapping_MemBlock = 0x00000,
                    UserControlPagesMapping_MemBlock = 0x08000,
                    VarAndMemoryAddresses_MemBlock = 0x10000,
                    EffectAndParam_MemBlock = 0x20000,
                    ModalLists_MemBlock = 0x40000,
                    Upper_MemBlock = 0x60000;
    
    unsigned long   currentMemAddresse;
    
    fprintf(fp1, "unsigned long D_FactoryControlPagesMapping_MemBlock = %lu; \n", FactoryControlPagesMapping_MemBlock);
    fprintf(fp1, "unsigned long D_UserControlPagesMapping_MemBlock = %lu; \n", UserControlPagesMapping_MemBlock);
    fprintf(fp1, "unsigned long D_VarAndMemoryAddresses_MemBlock = %lu; \n", VarAndMemoryAddresses_MemBlock);    
    fprintf(fp1, "unsigned long D_EffectAndParam_MemBlock = %lu; \n", EffectAndParam_MemBlock);    
    fprintf(fp1, "unsigned long D_ModalLists_MemBlock = %lu; \n", ModalLists_MemBlock);
    fprintf(fp1, "unsigned long D_Upper_MemBlock = %lu; \n", Upper_MemBlock);    
    
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////           add defines for address in  VarAndMemoryAddresses_MemBlock           /////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    
    currentMemAddresse = VarAndMemoryAddresses_MemBlock;
    
    fprintf(fp1, "#define D_MaxNumberOfControlPages %lu\n", currentMemAddresse); 
    currentMemAddresse += 2;    
    fprintf(fp1, "#define D_MaxNumberOfParameters %lu\n", currentMemAddresse); 
    currentMemAddresse += 2;
    fprintf(fp1, "#define D_NumOfEffectTypes %lu\n", currentMemAddresse); 
    currentMemAddresse += 2;
    fprintf(fp1, "#define D_TotalNumOfParameters %lu\n", currentMemAddresse); 
    currentMemAddresse += 2;
    fprintf(fp1, "#define D_NumOfEffectBlocks %lu\n", currentMemAddresse); 
    currentMemAddresse += 2;
    fprintf(fp1, "#define D_NumOfModalList %lu\n", currentMemAddresse); 
    currentMemAddresse += 2;

    
    fprintf(fp1, "\n\n#endif\n");
    fclose(fp1);
    
    
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    ///
    ///      FILE OUTPUT: ALL the EFFECT TYPE files . FOR uVGA !!!
    ///
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
	char EffetTypeFile[500];
    
	// sprintf( nameModalFile, "/Users/ericfeuilleaubois/Documents/LeafONICS/MidyAX/ModList%i.txt", fileIndex);
	// fp2 = fopen(nameModalFile, "w");
	// fprintf(fp2,"%i\n", effectTypes[ effectTypeNbAndParamNb[i][0] ].parameters[ effectTypeNbAndParamNb[i][1] ].numVals );
	// assert(fp2);
    
    
    //fprintf(fp1, "PROGMEM byte EffectType__ID[%i] = { ", numOfEffectTypes);
    
    
    for(int i=2; i < numOfEffectTypes + 2 ; i++)   
    {
        
		sprintf( EffetTypeFile, "/Users/ericfeuilleaubois/Documents/LeafONICS/_PROGRAMMING/MidyAX/UVGA/ET%i.txt", i);
		fp2 = fopen(EffetTypeFile, "w");
        
        int numberOfParam = 0;

        for(int j = 0 ; j < effectTypes[ i ].numOfParameters ; j++)
        {
            if( strcmp(effectTypes[ i ].parameters[j].label, "" ) != 0 )
            {
                numberOfParam++;
            }
		}
        
        
		fprintf(fp2,"%i\n", numberOfParam) ;
		assert(fp2);
        
        for(int j = 0 ; j < effectTypes[ i ].numOfParameters ; j++)
        {
            if( strcmp(effectTypes[ i ].parameters[j].label, "" ) != 0 )
            {
                fprintf(fp2,"%i  %s   %s\n", effectTypes[ i ].parameters[j].ID, effectTypes[ i ].parameters[j].name,
                        effectTypes[ i ].parameters[j].label) ;
            }
		}
		fclose(fp2);
	}
    
    return 0;
}





bool load_AXEFX_effect(TiXmlElement* pElement, unsigned int indent)
{
	if ( !pElement ) return 0;
    
	TiXmlAttribute* pAttrib=pElement->FirstAttribute();
	int i=0;
	int ival;
	double dval;
	const char* pIndent=getIndent(indent);
	printf("\n");
    
    /////
    int ID, typeID;
    const char *name, *type;
    AXEFX_effect *currentEffect;
    
    if ( strcmp( pAttrib->Name(), "id" ) != 0 )  { return false; }
    printf( "%s%s: value=[%s]", pIndent, pAttrib->Name(), pAttrib->Value());
    if (pAttrib->QueryIntValue(&ID)==TIXML_SUCCESS)   { printf( "  int=%d", ID); } else { return false; }
    pAttrib=pAttrib->Next();
    
    if ( strcmp( pAttrib->Name(), "name" ) != 0 )  { return false; }
    printf( "%s%s: value=[%s]", pIndent, pAttrib->Name(), pAttrib->Value());
    name = pAttrib->Value();
    pAttrib=pAttrib->Next();
    
    if ( strcmp( pAttrib->Name(), "type" ) != 0 )  { return false; }    
    printf( "%s%s: value=[%s]", pIndent, pAttrib->Name(), pAttrib->Value());
    type = pAttrib->Value();
    pAttrib=pAttrib->Next();
    
    if ( strcmp( pAttrib->Name(), "typeID" ) != 0 )  { return false; }
    printf( "%s%s: value=[%s]", pIndent, pAttrib->Name(), pAttrib->Value());
    if (pAttrib->QueryIntValue(&typeID)==TIXML_SUCCESS)   { printf( "  int=%d", typeID); } else { return false; } 
    
    printf( "\n" );
    
    // Store the effect just read
    NumberOfEffects++;
    theEffects[NumberOfEffects].ID = ID;
    strcpy ( theEffects[NumberOfEffects].name, const_cast<char*> (name) );
    strcpy ( theEffects[NumberOfEffects].type, const_cast<char*> (type) );
    //currentEffect = &(theEffects[NumberOfEffects]);
    //strcpy (  const_cast<char*> (name) , const_cast<char*> (type) );
    theEffects[NumberOfEffects].ID = typeID;
    
    printf( "id=%i name=%s type=%s typeID=%i\n", theEffects[NumberOfEffects].ID, theEffects[NumberOfEffects].name,
           theEffects[NumberOfEffects].type, theEffects[NumberOfEffects].typeID);
    printf( "\n" );
    
    
	return true;	
}





// consider: define this list in an external xml file
DefaultAxeCcs kDefaultAxeCcs[] = 
{
	// these don't have defaults (some can't be bypassed)
	{"feedback send", 0},
	{"mixer 1", 0},
	{"mixer 2", 0},
	{"feedback return", 0},
	{"noisegate", 0},
    
	{"input volume", 10},
	{"out 1 volume", 11},
	{"out 2 volume", 12},
	{"output", 13},
	{"taptempo", 14},
	{"tuner", 15},
	{"external 1", 16},
	{"external 2", 17},
	{"external 3", 18},
	{"external 4", 19},
	{"external 5", 20},
	{"external 6", 21},
	{"external 7", 22},
	{"external 8", 23},
    
	// extra AxeFx II externals
	{"external 9", 24},
	{"external 10", 25},
	{"external 11", 26},
	{"external 12", 27},
    
	// 2 loopers in AxeFx Std/Ultra
	{"looper 1 record", 24},
	{"looper 1 play", 25},
	{"looper 1 once", 26},
	{"looper 1 overdub", 27},
	{"looper 1 reverse", 28},
	{"looper 2 record", 29},
	{"looper 2 play", 30},
	{"looper 2 once", 31},
	{"looper 2 overdub", 32},
	{"looper 2 reverse", 33},
    
	// single looper in AxeFx II (?)
	{"looper record", 28},
	{"looper play", 29},
	{"looper once", 30},
	{"looper overdub", 31},
	{"looper reverse", 32},
	{"looper bypass", 33},
    
	{"global preset effect toggle", 34},
	{"volume increment", 35},
	{"volume decrement", 36},
    
	{"amp 1", 37},
	{"amp 2", 38},
	{"cabinet 1", 39},
	{"cabinet 2", 40},
	{"chorus 1", 41},
	{"chorus 2", 42},
	{"compressor 1", 43},
	{"compressor 2", 44},
	{"crossover 1", 45},
	{"crossover 2", 46},
	{"delay 1", 47},
	{"delay 2", 48},
	{"drive 1", 49},
	{"drive 2", 50},
	{"enhancer", 51},
	{"filter 1", 52},
	{"filter 2", 53},
	{"filter 3", 54},
	{"filter 4", 55},
	{"flanger 1", 56},
	{"flanger 2", 57},
	{"formant", 58},
	{"effects loop", 59},
	{"gate/expander 1", 60},
	{"gate/expander 2", 61},
	{"graphic eq 1", 62},
	{"graphic eq 2", 63},
	{"graphic eq 3", 64},
	{"graphic eq 4", 65},
	{"megatap delay", 66},
	{"multiband comp 1", 67},
	{"multiband comp 2", 68},
	{"multidelay 1", 69},
	{"multidelay 2", 70},
	{"parametric eq 1", 71},
	{"parametric eq 2", 72},
	{"parametric eq 3", 73},
	{"parametric eq 4", 74},
	{"phaser 1", 75},
	{"phaser 2", 76},
	{"pitch 1", 77},
	{"pitch 2", 78},
	{"quad chorus 1", 79},
	{"quad chorus 2", 80},
	{"resonator 1", 81},
	{"resonator 2", 82},
	{"reverb 1", 83},
	{"reverb 2", 84},
	{"ring mod", 85},
	{"rotary 1", 86},
	{"rotary 2", 87},
	{"synth 1", 88},
	{"synth 2", 89},
	{"panner/tremolo 1", 90},
	{"panner/tremolo 2", 91},
	{"vocoder", 92},
	{"vol/pan 1", 93},
	{"vol/pan 2", 94},
	{"vol/pan 3", 95},
	{"vol/pan 4", 96},
	{"wah-wah 1", 97},
	{"wah-wah 2", 98},
    
	// x/y ccs introduced in AxeFx II
	{"amp 1 x/y", 100},
	{"amp 2 x/y", 101},
	{"cabinet 1 x/y", 102},
	{"cabinet 2 x/y", 103},
	{"chorus 1 x/y", 104},
	{"chorus 2 x/y", 105},
	{"delay 1 x/y", 106},
	{"delay 2 x/y", 107},
	{"drive 1 x/y", 108},
	{"drive 2 x/y", 109},
	{"flanger 1 x/y", 110},
	{"flanger 2 x/y", 111},
	{"phaser 1 x/y", 112},
	{"phaser 2 x/y", 113},
	{"pitch 1 x/y", 114},
	{"pitch 2 x/y", 115},
	{"reverb 1 x/y", 116},
	{"reverb 2 x/y", 117},
	{"wah-wah 1 x/y", 118},
	{"wah-wah 2 x/y", 119},
    
	{"", -1}
};

void dump_to_stdout( TiXmlNode* pParent, unsigned int indent = 0)
{
	if ( !pParent ) return;
    
	TiXmlNode* pChild;
	TiXmlText* pText;
	int t = pParent->Type();
	printf( "%s", getIndent(indent));
	int num;
    const char *Ctemp;
    
    ///////////
    bool rOK;
    
	switch ( t )
	{
        case TiXmlNode::TINYXML_DOCUMENT:
            printf( "Document" );
            break;
            
        case TiXmlNode::TINYXML_ELEMENT:
            
            Ctemp = pParent->Value();
            if (strcmp( Ctemp, "EffectPoolInstance" ) == 0)
            {
                rOK = load_AXEFX_effect(pParent->ToElement(), indent+1);
            }                        
            
            printf( "Element [%s]", Ctemp );
            
            num=dump_attribs_to_stdout(pParent->ToElement(), indent+1);
            switch(num)
		{
			case 0:  printf( " (No attributes)"); break;
			case 1:  printf( "%s1 attribute", getIndentAlt(indent)); break;
			default: printf( "%s%d attributes", getIndentAlt(indent), num); break;
		}
            break;
            
        case TiXmlNode::TINYXML_COMMENT:
            printf( "Comment: [%s]", pParent->Value());
            break;
            
        case TiXmlNode::TINYXML_UNKNOWN:
            printf( "Unknown" );
            break;
            
        case TiXmlNode::TINYXML_TEXT:
            pText = pParent->ToText();
            printf( "Text: [%s]", pText->Value() );
            break;
            
        case TiXmlNode::TINYXML_DECLARATION:
            printf( "Declaration" );
            break;
        default:
            break;
	}
	printf( "\n" );
	for ( pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling()) 
	{
		dump_to_stdout( pChild, indent+1 );
	}
}


Byte Calculate_CheckSum(Byte  *cur_sysex, int cur_size)
{
  int j;
  
  Byte result = cur_sysex[0];
  for(j=1; j < cur_size-2 ; j++)
  {
    result = result ^ cur_sysex[j];
  }
  result = result & 0x7F;          
  return result;
}




NSString *getName(MIDIObjectRef object)
{
    // Returns the name of a given MIDIObjectRef as an NSString
    CFStringRef name = nil;
    if (noErr != MIDIObjectGetStringProperty(object, kMIDIPropertyName, &name))
        return nil;
    return (__bridge NSString *)name;
}



void completionProc(MIDISysexSendRequest *request)
{
	if( request->complete == true)
        NSLog(@"completionProc: The SYSEX request was sent");
		//sleep(2);
}


static void midiInputCallback(const MIDIPacketList *list, void *procRef, void *srcRef)
{

    UInt16 nBytes;
    const MIDIPacket *packet = &list->packet[0];
	unsigned int sysexRequestLength;
    static int lastRequested_EffectTypeNumb = -1, lastRequested_ParameterNumb = -1, lastRequested_EffectBlockID = -1;
    static bool endOfSYSEXFound = true, SYSEX_GET_PARAM_INFO_Sent = false;
    
    if(	packet->data[0] == 0xF0 )
    {
       sysExLength = 0;
       endOfSYSEXFound = false;
		NSLog(@"Start receiving SYSEX");
    }
	else {
        if ( endOfSYSEXFound == true )	NSLog(@"No SYSEX message in the Received PacketList ");
	}
    
    if(	endOfSYSEXFound == false)
    {
        NSLog(@"Num of Packet in the Packet list %i", list->numPackets);
	    for( unsigned int i = 0; i < list->numPackets; i++) 
		{
			if( sysExLength > SYSEX_LENGTH)
			{
				NSLog(@"Maximum SYSEX storage reached");
				// Allow reception of next SYSEX
				endOfSYSEXFound = true;
				waitingForSYSEXResponse = false;
				break;
			}
			if( packet->length > 1 ) NSLog(@"Length of packet > 1");
            sysExMessage[ sysExLength ] = packet->data[0];
			sysExLength++;

            if(	packet->data[0] == 0xF7 )
            { 
                endOfSYSEXFound = true; 
                waitingForSYSEXResponse = false;
				break;
            }

            packet = MIDIPacketNext(packet);
            if(packet == NULL) break;
		}
	}


    if( waitingForSYSEXResponse == false )  //Peux être déclanché si reception de messages autres que SYSEX !!!! A corriger
    {
		// Once a full SYSEX message is received print it to a file
		fprintf(midiFP, "RECEIV SYSEX = ");
        for( unsigned int i = 0; i < sysExLength; i++) 
        {
            fprintf(midiFP, "x%2.2X ", sysExMessage[i]);
        }
        fprintf(midiFP, "\n\n");
        fflush(midiFP);

		////////////////////////
		//Read SYSEX responses
		////////////////////////
        Byte DSP_Version_Major, DSP_Revision_Minor, FPGA_Revision, Microcontroller_Revision, Product_Version,Hardware_Revision;
        unsigned int Param_Prec, Param_Type, Param_Unit, Btempo1, Btempo2, Btempo3, Btempo4;
        float Param_Low_Limit, Param_High_Limit, Param_Multiplier, Param_Resolution;
        unsigned int NbOfElemInList = 0, posInString = 0;
        
		switch( sysExMessage[5] ) 
		{
		// SYSEX_QUERY_VERSION
		case 0x08 : 
			if( sysExMessage[4] != 0x03)
			{
				NSLog(@"Not connected to an AXE-FX II");
				exit(-1);  //End program
			}
			DSP_Version_Major = sysExMessage[6];		// 1 byte (i.e. hundreds value after decimal)
			DSP_Revision_Minor = sysExMessage[7];		// 1 byte (i.e. hundreds value after decimal)
			FPGA_Revision = sysExMessage[8];			// 1 Byte
			Microcontroller_Revision = sysExMessage[9]; // 1 Byte
			Product_Version = sysExMessage[10];			// 1 Byte
			Hardware_Revision = sysExMessage[11];		// 1 Byte
		break;

		// SYSEX_GET_PARAM_INFO
		case 0x16 :
			//Param_Prec = (sysExMessage[6] << 4) >> 4;
            //Param_Type = (sysExMessage[6] >> 4) ^ ( (sysExMessage[7] << 7) >> 4) ; 
            //Param_Unit = (sysExMessage[7] << 3) >> 4;
            Param_Prec = ( int(sysExMessage[6]) << 28) >> 28;
            Btempo1 = sysExMessage[7] << 31;
            Btempo2 = Btempo1 >> 28;
            Btempo3 = sysExMessage[6] >> 4;
            Btempo4 = Btempo3 ^ Btempo2;
            Param_Type = Btempo4;
			Param_Unit = (sysExMessage[7] << 27) >> 28;
                
            /*if( Param_Type != B_INT )
			{
				// No need to ask for the String values
				SYSEX_GET_PARAM_INFO_Sent =  false;
				ParameterNumb++;
			}*/

            Param_Low_Limit = convertToFloat( &(sysExMessage[11]) ); 
            Param_High_Limit = convertToFloat( &(sysExMessage[16]) );    
            Param_Multiplier = convertToFloat( &(sysExMessage[21]) );
            Param_Resolution = convertToFloat( &(sysExMessage[26]) );

			//Store the values on the right parameter object 
			//int defaultValue; // Default internal value  -- Not really needed since it could be reloaded from the AXE-FX if the effect type changes

			effectTypes[lastRequested_EffectTypeNumb].parameters[lastRequested_ParameterNumb].minDispValue = Param_Low_Limit;        
            effectTypes[lastRequested_EffectTypeNumb].parameters[lastRequested_ParameterNumb].maxDispValue = Param_High_Limit;        
			effectTypes[lastRequested_EffectTypeNumb].parameters[lastRequested_ParameterNumb].precision = (int) Param_Prec;
			effectTypes[lastRequested_EffectTypeNumb].parameters[lastRequested_ParameterNumb].type = int( Param_Type );        
            effectTypes[lastRequested_EffectTypeNumb].parameters[lastRequested_ParameterNumb].unit = int (Param_Unit );
                
            // Default values when there is no modal list.
            effectTypes[lastRequested_EffectTypeNumb].parameters[lastRequested_ParameterNumb].idListVal = - 1;
            effectTypes[lastRequested_EffectTypeNumb].parameters[lastRequested_ParameterNumb].numVals = 65534;                
		break;

		// SYSEX_GET_PARAM_STRINGS
		case 0x28 :
                 /*   int numOfListOfParamModalValues =0;
                    int effectTypeNbAndParamNb[1000][2];
                    char listOfParamModalValues[300][250][50]; // Nb effect type x Nb param x Nb modal values x Nb characters
                    int correspModalList[1000]; */
                    
                numOfListOfParamModalValues++;                
                for( unsigned int i = 6; i < sysExLength; i++) 
                {
                    if( sysExMessage[i] == 0x00 )
                    {
                        listOfParamModalValues[ numOfListOfParamModalValues ][ NbOfElemInList ][ posInString ] = '\0';
                        NbOfElemInList++;
                        posInString = 0;
                    }
                    else {
                        listOfParamModalValues[ numOfListOfParamModalValues ][ NbOfElemInList ][ posInString ] = sysExMessage[i];
                        posInString ++;
                        
                    }
                }
                effectTypeNbAndParamNb[numOfListOfParamModalValues][0] = effectTypes[lastRequested_EffectTypeNumb].ID;    
                effectTypeNbAndParamNb[numOfListOfParamModalValues][1] = lastRequested_ParameterNumb;
                
			/*Effect_ID = sysExMessage[6] + sysExMessage[7] x 0x80;
			Param_ID = sysExMessage[8] + sysExMessage[9] x 0x80;
            ReceivedValue1 = long(sysExMessage[10]) + long(sysExMessage[11]) * 128 + long(sysExMessage[12]) * 16384;
            */
                
            effectTypes[ effectTypeNbAndParamNb[numOfListOfParamModalValues][0] ].parameters[ effectTypeNbAndParamNb[numOfListOfParamModalValues][1] ].numVals = NbOfElemInList;
                
        break;

		default:
		break;
		}
        
        
        if( lastRequested_EffectTypeNumb == MAX_EffectTypeNumb -1 &&
           lastRequested_ParameterNumb == MAX_ParameterNumb -1)
        //if( lastRequested_EffectTypeNumb == -1 &&
        //       lastRequested_ParameterNumb == -1 )
        {
            //CFRunLoopRef loopRef = CFRunLoopGetCurrent ( );
            //CFRunLoopStop( loopRef );  
            return;
        }

        /*/////////////////////////////////////////////////////////////////////////////////////////////////////
        // Sending a SYSEX to the AXE_FX
        
        NSString *SysExCommandString = @"F0 00 01 74 03 08 0E F7";
        
        //Converting String to DATA
        SysExCommandString = [SysExCommandString stringByReplacingOccurrencesOfString:@" " withString:@""];
        NSMutableData *commandToSend= [[NSMutableData alloc] init];
        unsigned char whole_byte;
        char byte_char[3] = {'\0','\0','\0'};
        int commandLength = [SysExCommandString length] /2;
        for(int i=0; i < commandLength; i++)
        {
            byte_char[0] = [SysExCommandString characterAtIndex:i*2];
            byte_char[1] = [SysExCommandString characterAtIndex:i*2+1];
            whole_byte = strtol(byte_char, NULL, 16);
            [commandToSend appendBytes:&whole_byte length:1]; 
        }
        int length = [commandToSend length];
        const unsigned char *p = ( const unsigned char *) CFDataGetBytePtr((__bridge CFDataRef) commandToSend);
        */


		//Construct the next SYSEX message to be sent
		unsigned char sysexMessageToSend[256];
		unsigned int sizeOfCommand = 0;

		// SYSEX header
		sysexMessageToSend[0] = 0xF0;
		sysexMessageToSend[1] = 0x00;
		sysexMessageToSend[2] = 0x01;
		sysexMessageToSend[3] = 0x74;
		sysexMessageToSend[4] = 0x03;


		// Ask for the parameter infos

		if( EffectTypeNumb < MAX_EffectTypeNumb )
		{
            lastRequested_EffectTypeNumb = EffectTypeNumb;
            
            for(int i = 0; i < numOfEffectBlocks; i++)
            {
                if( effectBlocks[i].effectTypeID == effectTypes[lastRequested_EffectTypeNumb].ID )
                {
                    lastRequested_EffectBlockID = effectBlocks[i].ID;                    
                    break;
                }
            }

            // The Max number of parameter is a function of the Effect type ID not the effect block ID
            MAX_ParameterNumb = effectTypes[lastRequested_EffectTypeNumb].numOfParameters;

			if(  ParameterNumb < MAX_ParameterNumb ) 
			{
                lastRequested_ParameterNumb = ParameterNumb;
                
                sysexMessageToSend[6] = lastRequested_EffectBlockID - int( lastRequested_EffectBlockID / 0x80) * 0x80;
                sysexMessageToSend[7] = lastRequested_EffectBlockID / 0x80;                    
                sysexMessageToSend[8] = lastRequested_ParameterNumb - (lastRequested_ParameterNumb/ 0x80);
                sysexMessageToSend[9] = lastRequested_ParameterNumb/ 0x80; 
                
                if( SYSEX_GET_PARAM_INFO_Sent ==  false)
				{
					//Send the SYSEX_GET_PARAM_INFO SYSEX
					sysexMessageToSend[5] = 0x16; 		//Function code
					sizeOfCommand = 5;
					sysexRequestLength = 7 + sizeOfCommand;
					SYSEX_GET_PARAM_INFO_Sent = true;
				}
				else {
                    //Send the SYSEX_GET_PARAM_STRINGS
                    sysexMessageToSend[5] = 0x28; 		//Function code
                    sizeOfCommand = 5;
                    sysexRequestLength = 7 + sizeOfCommand;
                    SYSEX_GET_PARAM_INFO_Sent =  false;
                    ParameterNumb++;
				}
			}

            if( ParameterNumb == MAX_ParameterNumb)
            {
                ParameterNumb = 0;
                EffectTypeNumb++;
            }
		}
			
		// Checksum + end of SYSEX
		// This version of Calculate_CheckSum does not automatically take into account F0 and F7  --> Have to be added to the sysexMessageToSend
		sysexMessageToSend[sysexRequestLength-2] = Calculate_CheckSum( sysexMessageToSend, sysexRequestLength );
		sysexMessageToSend[sysexRequestLength-1] = 0xF7;



		// Construction of the SYSEX request
        MIDISysexSendRequest sendRequest;
        sendRequest.destination = destinationRef;
        sendRequest.data = (Byte *) sysexMessageToSend;
        sendRequest.bytesToSend = sysexRequestLength;
        sendRequest.complete = 0;
        sendRequest.completionProc = completionProc;
        sendRequest.completionRefCon = &sendRequest;

        fprintf(midiFP, "SENT   SYSEX = ");
        for( unsigned int i = 0; i < sysexRequestLength; i++) 
        {
            fprintf(midiFP, "x%2.2X ", sysexMessageToSend[i]);
        }
        fprintf(midiFP, "\n");
        fflush(midiFP);
        
        
		// Sending SYSEX request
        waitingForSYSEXResponse = true;
        MIDISendSysex(&sendRequest);
        //sleep(1);
        usleep(300);
        
        //NSLog(@"The SYSEX command: %@ was sent to the AXE-FX II", sysexMessageToSend);
    }
   
    
    
    
    
    
    
    /*NSLog(@"Received SYSEX: %s", sysExMessage);
    
    NSMutableData *sysexReceived= [[NSMutableData alloc] init];
	for(int i=0; i < packet->length; i++)
	{
		[sysexReceived appendBytes:&packet->data[i] length:1]; 
	}
    NSLog(@"Sent SYSEX: %@", sysexReceived);*/

    /*for (unsigned int i = 0; i < list->numPackets; i++) 
	{
        nBytes = packet->length;
		status == 0xF0

//Now we've copied the data, we check if the last byte is the SysEx End message.
            
            // Check if the last byte is SysEx End.
            continueSysEx = (packet->data[nBytes - 1] == 0xF7);

//If we've finished the message, or if we've filled the buffer then we have  a complete SysEx message to process. Here we're not doing anything with it, but in a proper application we'd pass it to whatever acts on the MIDI messages.

            if (!continueSysEx || sysExLength == SYSEX_LENGTH) 
			{
                // We would process the SysEx message here, as it is we're just ignoring it
                
                sysExLength = 0;
            }
			else {

//If we weren't continuing a SysEx message then we need to iterate over all the bytes in the MIDIPacket parsing the messages that are contained in it.

				UInt16 iByte, size;
            
				iByte = 0;
				while (iByte < nBytes) {
                size = 0;
                
                // First byte should be status
                unsigned char status = packet->data[iByte];
                if (status < 0xC0) {
                    size = 3;
                } else if (status < 0xE0) {
                    size = 2;
                } else if (status < 0xF0) {
                    size = 3;
                } else if (status == 0xF0) {
                    // MIDI SysEx then we copy the rest of the message into the SysEx message buffer
                    unsigned int lengthLeftInMessage = nBytes - iByte;
                    unsigned int lengthToCopy = MIN (lengthLeftInMessage, SYSEX_LENGTH);
                    
                    memcpy(sysExMessage + sysExLength, packet->data, lengthToCopy);
                    sysExLength += lengthToCopy;
                    
                    size = 0;
                    iByte = nBytes;

                    // Check whether the message at the end is the end of the SysEx
                    continueSysEx = (packet->data[nBytes - 1] != 0xF7);
                } else if (status < 0xF3) {
                    size = 3;
                } else if (status == 0xF3) {
                    size = 2;
                } else {
                    size = 1;
                }
            
                unsigned char messageType = status & 0xF0;
                unsigned char messageChannel = status & 0xF;

//Now we know the size of each message, what type it is, and what channel it was received on and we can pass it off to something that will parse it. For this example, here is some code that just prints the message and the values. Ideally this would happen on a low priority thread so that it doesn't block the thread that receives the MIDI messages, but for this example it doesn't matter too much.
    
                switch (status & 0xF0) {
                    case 0x80:
                        NSLog(@"Note off: %d, %d", packet->data[iByte + 1], packet->data[iByte + 2]);
                        break;
                        
                    case 0x90:
                        NSLog(@"Note on: %d, %d", packet->data[iByte + 1], packet->data[iByte + 2]);
                        break;
                        
                    case 0xA0:
                        NSLog(@"Aftertouch: %d, %d", packet->data[iByte + 1], packet->data[iByte + 2]);
                        break;
                        
                    case 0xB0:
                        NSLog(@"Control message: %d, %d", packet->data[iByte + 1], packet->data[iByte + 2]);
                        break;
                        
                    case 0xC0:
                        NSLog(@"Program change: %d", packet->data[iByte + 1]);
                        break;
                        
                    case 0xD0:
                        NSLog(@"Change aftertouch: %d", packet->data[iByte + 1]);
                        break;
                        
                    case 0xE0:
                        NSLog(@"Pitch wheel: %d, %d", packet->data[iByte + 1], packet->data[iByte + 2]);
                        break;
                        
                    default:
                        NSLog(@"Some other message");
                        break;
                }
                
                iByte += size;
            }
        }

//As mentioned above, to get the next MIDIPacket you need to use MIDIPacketNext.

        packet = MIDIPacketNext(packet);
    }*/

}

union Float_Bytes {
    Byte The_bytes[4];
    float f;
};


float convertToFloat( Byte *received5bytes)
{
    Float_Bytes FB;
    Byte Btempo1, Btempo2;

    for(int i = 1; i < 5; i++)
    {
        Btempo1 = received5bytes[i] << (8-i);
        Btempo2 = received5bytes[i-1] >> (i-1);
        FB.The_bytes[i-1] = Btempo1 ^ Btempo2; 
    }
    return FB.f;
}

