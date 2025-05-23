#pragma once
#include "StructOffset.h"

bool isRoomInfo;

struct RInfoBlueTeam {
    std::string Name;
    std::string UserID;
    std::string Squad;
    std::string Rank;
    std::string Hero;
    std::string Spell;
};

struct RInfoRedTeam {
    std::string Name;
    std::string UserID;
    std::string Squad;
    std::string Rank;
    std::string Hero;
    std::string Spell;
};

struct {
    RInfoBlueTeam PlayerB[5];
    RInfoRedTeam PlayerR[5];
} RoomInfo;

void RoomInfoList() {
    void *LogicBattleManager_Instance;
    IL2Cpp::Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "LogicBattleManager", "Instance", &LogicBattleManager_Instance);
    if (LogicBattleManager_Instance) {
        int iGetBattleState = GetBattleState(LogicBattleManager_Instance);
        if (iGetBattleState == 2 || iGetBattleState == 3) {
            auto GetBattlePlayerInfo = ((monoList<void **> *(*)(uintptr_t))SystemData_GetBattlePlayerInfo)(0);
            if (GetBattlePlayerInfo) {
                int PlayerB = 0, PlayerR = 0;
                int iSelfCamp = 1;
                int m_uiID = *(int *)(SystemData_m_uiID);
                for (int i = 0; i < GetBattlePlayerInfo->getSize(); i++) {
                    auto Pawn = GetBattlePlayerInfo->getItems()[i];
                    if (!Pawn) continue;
                    auto iCamp = *(int *) ((uintptr_t)Pawn + SystemData_RoomData_iCamp);
                    auto lUid = *(int *) ((uintptr_t)Pawn + SystemData_RoomData_lUid);
                    if (lUid != m_uiID) continue;
                    iSelfCamp = iCamp;
                    break;
                }
                for (int i = 0; i < GetBattlePlayerInfo->getSize(); i++) {
                    auto Pawn = GetBattlePlayerInfo->getItems()[i];
                    if (!Pawn) continue;
                    auto iCamp = *(int *) ((uintptr_t)Pawn + SystemData_RoomData_iCamp);
                    auto _sName = *(String **)((uintptr_t)Pawn + SystemData_RoomData__sName);
                    auto _steamSimpleName = *(String **)((uintptr_t)Pawn + SystemData_RoomData__steamSimpleName);
                    auto _steamName = *(String **)((uintptr_t)Pawn + SystemData_RoomData__steamName);
                    auto uiRankLevel = *(int *) ((uintptr_t)Pawn + SystemData_RoomData_uiRankLevel);
                    auto iMythPoint = *(int *) ((uintptr_t)Pawn + SystemData_RoomData_iMythPoint);
                    auto heroid = *(int *) ((uintptr_t)Pawn + SystemData_RoomData_heroid);
                    auto summonSkillId = *(int *) ((uintptr_t)Pawn + SystemData_RoomData_summonSkillId);
                    auto lUid = *(int *) ((uintptr_t)Pawn + SystemData_RoomData_lUid);
                    auto uiZoneId = *(int *) ((uintptr_t)Pawn + SystemData_RoomData_uiZoneId);
                    if (iCamp == iSelfCamp) {
                        if (_sName) {
                            RoomInfo.PlayerB[PlayerB].Name = _sName->CString();
                        }
                        RoomInfo.PlayerB[PlayerB].UserID = to_string(lUid) + " (" + to_string(uiZoneId) + ")";
                      
                        RoomInfo.PlayerB[PlayerB].Rank = RankToString(uiRankLevel, iMythPoint);
                        RoomInfo.PlayerB[PlayerB].Hero = HeroToString(heroid);
                        RoomInfo.PlayerB[PlayerB].Spell = SpellToString(summonSkillId);
                        PlayerB++;
                    } else {
                        if (_sName) {
                            RoomInfo.PlayerR[PlayerR].Name = _sName->CString();
                        }
                        RoomInfo.PlayerR[PlayerR].UserID = to_string(lUid) + " (" + to_string(uiZoneId) + ")";
                        
                        RoomInfo.PlayerR[PlayerR].Rank = RankToString(uiRankLevel, iMythPoint);
                        RoomInfo.PlayerR[PlayerR].Hero = HeroToString(heroid);
                        RoomInfo.PlayerR[PlayerR].Spell = SpellToString(summonSkillId);
                        PlayerR++;
                    }
                }
            }
        }
    }
}
