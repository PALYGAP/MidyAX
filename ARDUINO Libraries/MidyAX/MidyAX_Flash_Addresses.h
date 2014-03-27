#ifndef MIDYAX_FLASH_ADDRESSES_H_
#define MIDYAX_FLASH_ADDRESSES_H_


    #define D_FactoryControlPagesMapping_MemBlock 0x00000
    #define D_UserControlPagesMapping_MemBlock	  0x08000
    #define D_MainParam_MemBlock                  0x10000
    #define D_AddresseOfList_MemBlock	          0x10100
    #define D_ListOfAddresses_MemBlock	          0x10200
    #define D_startAddresseOfModalListAddresses   0x11000
    #define D_EffectAndParam_MemBlock             0x20000    
    #define D_ModalLists_MemBlock		          0x50000
    #define D_Upper_MemBlock			          0x70000


    #define SFMA_Mapping_FACTORY_EffectType         0x70000
    #define SFMA_Mapping_USER_EffectType_Mapping	0x70100
    #define SFMA_Mapping_LastUsed_SubPages          0x70200
    #define SFMA_Mapping_FACTORY_QuickAccess_Parameters_Mapping	0x71000
    #define SFMA_Mapping_USER_QuickAccess_Parameters_Mapping	0x72000
    #define SFMA_Mapping_FACTORY_ET_Page_BCR2000_Preset         0x73000
    #define SFMA_Mapping_USER_ET_Page_BCR2000_Preset            0x73100
    #define SFMA_Mapping_UsageStats_EF_ControlPages             0x73200


    #define SFMA_Mapping_FACTORY_EffectType_Parameter_Mapping	0x80000
    #define SFMA_Mapping_USER_EffectType_Parameter_Mapping      0x90000

#endif



