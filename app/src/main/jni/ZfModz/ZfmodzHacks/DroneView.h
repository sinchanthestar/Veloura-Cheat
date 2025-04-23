#pragma once
#include "StructOffset.h"

//jgn diubah kebawah
static float SetFieldOfView = 0, GetFieldOfView = 0;

//FUNCTION DRONE VIEW
void DroneView() {
    if (GetFieldOfView == 0) {
        GetFieldOfView = get_fieldOfView();
    }
    if (SetFieldOfView > 0 && GetFieldOfView != 0) {
        set_fieldOfView((float)GetFieldOfView + SetFieldOfView);
    }
    if (SetFieldOfView == 0 && GetFieldOfView != 0) {
        set_fieldOfView((float)GetFieldOfView);
    }
}

static bool isShowEntity = false;

bool (*oShowEntityBase)(void * instance);
bool _ShowEntityBase(void * instance) {
    if(instance != NULL){
      if (isShowEntity) {
        return true;
      }else{
        return oShowEntityBase(instance);
      }
    }
    return oShowEntityBase(instance);
}


//Draw
void DrawDrone(ImDrawList *draw) {
    
    //Fix Screen
    auto Screen_SetResolution = reinterpret_cast<void* (__fastcall *)(int, int, bool)>(Screen_set_Resolution);
                                Screen_SetResolution(screenWidth, screenHeight, true);
                                
                                
                                
    //Esp Draw Text
    drawText("SINCHANPANDA", screenWidth / 2.2f , screenHeight / 1.05f , 45.0f , IM_COL32(0,225,0,255));
    
    //LogicStartBattle
	void *BattleBridge_Instance, *BattleManager_Instance, *LogicBattleManager_Instance;
    IL2Cpp::Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleData", "m_BattleBridge", &BattleBridge_Instance);
    if (BattleBridge_Instance) {
        auto _bStartBattle = *(bool *) ((uintptr_t)BattleBridge_Instance + BattleBridge_bStartBattle);
        if (_bStartBattle) {
           //CALL FUNCTION DRONE VIEW
           DroneView();
        }

   }
   
   
}

