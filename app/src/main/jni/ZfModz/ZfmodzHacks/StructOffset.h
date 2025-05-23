#pragma once
#include "ToString.h"

//maphack
#define ShowEntity_get_m_CanSight (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowEntity", "get_m_CanSight", 0)

#define LogicBattleManager_GetBattleState (uintptr_t) IL2Cpp::Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("LogicBattleManager"), OBFUSCATE("GetBattleState"), 0)

#define SystemData_m_uiID (uintptr_t) IL2Cpp::Il2CppGetStaticFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("m_uiID"))

#define SystemData_GetBattlePlayerInfo (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "GetBattlePlayerInfo")



//Class SystemData
#define SystemData_GetHeroSkin (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "GetHeroSkin", 2)
#define SystemData_GetMCLimitSkin (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "GetMCLimitSkin", 1)
#define SystemData_GetHeroHolyStatue (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "GetHeroHolyStatue", 2)
#define SystemData_IsCanUseSkin (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "IsCanUseSkin", 1)
#define SystemData_IsHaveSkin (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "IsHaveSkin", 1)
#define SystemData_IsHaveSkinForever (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "IsHaveSkinForever", 1)
#define SystemData_IsHaveStatue (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "IsHaveStatue", 1)
#define SystemData_IsHaveStatueForever (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "IsHaveStatueForever", 1)
#define SystemData_IsForbidStatue (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "IsForbidStatue", 1)
#define SystemData_IsForbidSkin (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "IsForbidSkin", 1)
#define SystemData_IsForbidARSkin (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "IsForbidARSkin", 1)

//Class SystemData.RoomData
#define SystemData_RoomData_iCamp (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "iCamp")
#define SystemData_RoomData__sName (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "_sName")
#define SystemData_RoomData__steamSimpleName (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "_steamSimpleName")
#define SystemData_RoomData__steamName (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "_steamName")
#define SystemData_RoomData_uiRankLevel (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "uiRankLevel")
#define SystemData_RoomData_iMythPoint (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "iMythPoint")
#define SystemData_RoomData_heroid (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "heroid")
#define SystemData_RoomData_summonSkillId (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "summonSkillId")
#define SystemData_RoomData_lUid (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "lUid")
#define SystemData_RoomData_uiZoneId (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "uiZoneId")
#define LogicBattleManager_m_dicPlayerLogic (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "LogicBattleManager", "m_dicPlayerLogic")

//Class CmdHeroSkin
#define CmdHeroSkin__ctor (uintptr_t) IL2Cpp::Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("MTTDProto"), OBFUSCATE("CmdHeroSkin"), OBFUSCATE(".ctor"))

//Class CmdHeroStatue
#define CmdHeroStatue__ctor (uintptr_t) IL2Cpp::Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("MTTDProto"), OBFUSCATE("CmdHeroStatue"), OBFUSCATE(".ctor"))


//Class UIChooseHero
#define UIChooseHero_ShowSkinExpiryDate (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "UIChooseHero", "ShowSkinExpiryDate",0 )   //CheckHeroDefaultSkin
#define UIChooseHero_SendSelectSkin (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ChooseHeroMgr", "SendSelectSkin", 2)
#define UIChooseHero_SendSelectSkin2 (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "UIChooseHero", "CheckHeroDefaultSkin", 2)

//Class UIRankHero
#define UIRankHero_BatttleSelectSkin (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "UIRankHero", "BatttleSelectSkin", 2)
#define UIRankHero_BatttleSelectSkin2 (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "UIChooseHero", "BatttleSelectSkin", 2)

//Class UIRankHero.ChangeShow
#define UIRankHero_ChangeShow_SendUseSkin (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "UIRankHero/ChangeShow", "SendUseSkin", 2)

//Class BattleReceiveMessage
#define BattleReceiveMessage_SetPlayerData (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleReceiveMessage", "SetPlayerData", 2)
#define BattleReceiveMessage_SetPlayerData_ (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleReceiveMessage", "SetPlayerData", 1)
#define BattleReceiveMessage_AddPlayerInfo (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleReceiveMessage", "AddPlayerInfo", 4)
#define BattleReceiveMessage_AddPlayerInfo_ (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleReceiveMessage", "AddPlayerInfo", 2)

//Class BattlePlayerInfo
#define BattlePlayerInfo_lUid (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "BattlePlayerInfo", "lUid")
#define BattlePlayerInfo_uiSelHero (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "BattlePlayerInfo", "uiSelHero")
#define BattlePlayerInfo_uiSkinId (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "BattlePlayerInfo", "uiSkinId")

//Unlock Skin -> Mencoba
//Class UIRankHero.ChangeShow
#define UIRankHero_ChangeShow_iSelfHero (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "UIRankHero/ChangeShow", "iSelfHero")

//OffsetClassBattleBridge
#define BattleBridge_bStartBattle (uintptr_t) IL2Cpp::Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleBridge", "bStartBattle")

//OffsetClassCamera
#define Camera_get_main (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Camera", "get_main", 0)
#define Camera_get_fieldOfView (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Camera", "get_fieldOfView", 0)
#define Camera_set_fieldOfView (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Camera", "set_fieldOfView", 1)

//OffsetClassScreen
#define Screen_set_Resolution (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Screen", "SetResolution", 3)

#define GameServerConfig_SendRawData (uintptr_t) IL2Cpp::Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "GameServerConfig", "SendRawData", 8)

int GetBattleState(void* instance) { return reinterpret_cast<int(__fastcall *)(void*)>(LogicBattleManager_GetBattleState)(instance); }

template <typename T>
struct monoArray
{
    void* klass;
    void* monitor;
    void* bounds;
    int   max_length;
    void* vector [1];
    int getLength()
    {
        return max_length;
    }
    T getPointer()
    {
        return (T)vector;
    }
};

template <typename T>
struct monoList {
    void *unk0;
    void *unk1;
    monoArray<T> *items;
    int size;
    int version;

    T getItems(){
        return items->getPointer();
    }

    int getSize(){
        return size;
    }

    int getVersion(){
        return version;
    }
};

//Function
void *get_main() {
    return reinterpret_cast<void *(__fastcall *)()>(Camera_get_main)();
}

float get_fieldOfView() {
    return reinterpret_cast<float(__fastcall *)(void *)>(Camera_get_fieldOfView)(get_main());
}

void *set_fieldOfView(float value) {
    return reinterpret_cast<void *(__fastcall *)(void *, float)>(Camera_set_fieldOfView)(get_main(), value);
}

uintptr_t OffsetFunc_ReportMd5;

