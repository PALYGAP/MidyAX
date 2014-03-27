//
//  AXE-FX_XmlLoad.h
//  MidyAX - Param & Mapping management
//
//  Created by Eric Feuilleaubois on 29/09/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MidyAX___Param___Mapping_management_AXE_FX_XmlLoad_h
#define MidyAX___Param___Mapping_management_AXE_FX_XmlLoad_h


const unsigned int NUM_INDENTS_PER_SPACE=2;

struct AXEFX_effect
{
	int ID;
	char name[30];
    char type[20];
    int typeID;
};



struct DefaultAxeCcs
{
	std::string mParameter;
	int			mCc;
};


const char * getIndent( unsigned int numIndents );


int dump_attribs_to_stdout(TiXmlElement* pElement, unsigned int indent);

const char * getIndentAlt( unsigned int numIndents );

bool load_AXEFX_effect(TiXmlElement* pElement, unsigned int indent);


#endif
