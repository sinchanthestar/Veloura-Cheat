#include "Includes/obfuscate.h"
#include "Zfmodz/Call_Me.h"
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include <jni.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include "Menu/Register.h"
#include "Unity/Call_Unity.h"

  
#include <android/log.h>


#include <iostream>
#include <fstream>
#include <string>
#include <android/log.h>
#include <dlfcn.h>
#include <pthread.h>
#include <unistd.h>
#include <jni.h>
#include <EGL/egl.h>

#define LOG_TAG "Put"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define targetLib OBFUSCATE("libil2cpp.so")

uintptr_t il2cppMap;
void *m_EGL = nullptr;

bool initImGui;

int s_Width = 0;
int s_Height = 0;

static bool setupDone = false;
static bool setupImguiDone = false;

bool copyFile(const char *SRC, const char* DEST)
{
    std::ifstream src(SRC, std::ios::binary);
    std::ofstream dest(DEST, std::ios::binary);
    dest << src.rdbuf();
    return src && dest;
}

const char *libToLoad = OBFUSCATE("/sdcard/Android/data/com.mobile.legends/files/dragon2017/assets/comlibs/armeabi-v7a/libAkSoundEngineNew.bytes");
const char *libToLoad2 = OBFUSCATE("/data/data/com.mobile.legends/app_libs/libAkSoundEngineNew.so");
const char *libToLoad3 = OBFUSCATE("/data/data/com.mobile.legends/app_libs/libAkSoundEngineNew.so");


#define LibToLoad libToLoad
#define LibToLoad2 libToLoad2
#define LibToLoad3 libToLoad3



void *pLibRealUnity = nullptr;
typedef jint(JNICALL *CallJNI_OnLoad_t)(JavaVM *vm, void *reserved);
CallJNI_OnLoad_t RealJNIOnLoad = nullptr;


static const char *done = "";

bool g_Initialized = false;
ImGuiWindow* g_window;

static bool main_window = false;



float sliderDebug = 0.0f;

static bool test = false;
    
EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean _eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
    
    if (glWidth <= 0 || glHeight <= 0) {
        return eglSwapBuffers(dpy, surface);
    }
    
    if (!setupImguiDone) {
        ImGui::CreateContext();
        
        ImGuiStyle* style = &ImGui::GetStyle();
        style->WindowRounding = 5.3f;
        style->FrameRounding = 2.3f;
        style->ScrollbarRounding = 0;
        style->WindowTitleAlign = ImVec2(0.5, 0.5);
        style->WindowMinSize = ImVec2(400, 180);
        style->FramePadding = ImVec2(8, 6);
        style->ScaleAllSizes(1.0f);
        style->ScrollbarSize /= 1;
        
        ImGui_ImplAndroid_Init();
        ImGui_ImplOpenGL3_Init(OBFUSCATE("#version 300 es"));
        ImGui::StyleColorsDark();
        
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigWindowsMoveFromTitleBarOnly = true;
        io.IniFilename = NULL;
        
        static const ImWchar icons_ranges[] = {0x0020, 0x00FF, 0x3000, 0x30FF, 0x31F0, 0x31FF, 0xFF00, 0xFFEF, 0x4e00, 0x9FAF, 0};
        ImFontConfig icons_config;

        ImFontConfig CustomFont;
        CustomFont.FontDataOwnedByAtlas = false;

        icons_config.MergeMode = true;
        icons_config.PixelSnapH = true;
        icons_config.OversampleH = 2.5;
        icons_config.OversampleV = 2.5;

        io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 21.f, &CustomFont);
        io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 19.0f, &icons_config, icons_ranges);
        
        ImFontConfig font_cfg;
        font_cfg.SizePixels = 22.0f;
        io.Fonts->AddFontDefault(&font_cfg);
        
        setupImguiDone = true;
    }
    
    
    ImGuiIO* io = &ImGui::GetIO();
    
    static bool WantTextInputLast = false;
    if (io->WantTextInput && !WantTextInputLast)
        ShowSoftKeyboardInput();
    WantTextInputLast = io->WantTextInput;

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();
    
    if(setupDone){
    //CALL FUNCTION DRAW
    DrawDrone(ImGui::GetBackgroundDrawList());            
   UnlockSkin();
    }
    
    
    
    if (ImGui::Begin(OBFUSCATE("Nuga Base Eksternal - Mobile Legends")), ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse) {

        if (ImGui::BeginTabBar(OBFUSCATE("##tabbar"))) {
                
            if (ImGui::BeginTabItem(OBFUSCATE("Menu"))) {
            
                
                ImGui::BeginGroupPanel(OBFUSCATE(" Group"), ImVec2(-1.0f, 0.0f));
                ImGui::Checkbox(OBFUSCATE("UnlockSkin"), &Config.Visual.UnlockSkin);
                ImGui::Checkbox(OBFUSCATE("MapHack"), &isShowEntity);
                
                //ADJUST DRONE VIEW WITH SLIDER
                ImGui::SliderFloat("Drone View", &SetFieldOfView, 0, 40, "%1.f");
                
                ImGui::Text(OBFUSCATE("Created By Nuga"));
                ImGui::EndTabItem();
            }
            
            if (ImGui::BeginTabItem(OBFUSCATE("RoomInfo"))) {
            
                   if(setupDone){         
            RoomInfoList(); 
                   }
            
              ImGui::TextColored(ImVec4(0.0f, 0.8f, 1.0f, 1.0f), "Team");
                if (ImGui::BeginTable("##Team", 6, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
                    ImGui::TableSetupColumn("Name", 0, 150);
                    ImGui::TableSetupColumn("User ID", 0, 160);
                  
                    ImGui::TableSetupColumn("Rank", 0, 180);
                    ImGui::TableSetupColumn("Hero", 0, 130);
                    ImGui::TableSetupColumn("Spell", 0, 120);
                    ImGui::TableHeadersRow();
                    for (int row = 0; row < 5; row++) {
                        ImGui::TableNextRow();
                        for (int column = 0; column < 5; column++) {
                            ImGui::TableSetColumnIndex(column);
                            char buf[32];
                            if (column == 0) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Name.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 1) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].UserID.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 2) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Rank.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 3) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Hero.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 4) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Spell.c_str());
                                ImGui::TextUnformatted(buf);
                            }
                        }
                    }
                    ImGui::EndTable();
                }
                ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Enemy");
                if (ImGui::BeginTable("##Enemy", 6, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
                    ImGui::TableSetupColumn("Name", 0, 150);
                    ImGui::TableSetupColumn("User ID", 0, 160);
                    
                    ImGui::TableSetupColumn("Rank", 0, 180);
                    ImGui::TableSetupColumn("Hero", 0, 130);
                    ImGui::TableSetupColumn("Spell", 0, 120);
                    ImGui::TableHeadersRow();
                    for (int row = 0; row < 5; row++) {
                        ImGui::TableNextRow();
                        for (int column = 0; column < 5; column++) {
                            ImGui::TableSetColumnIndex(column);
                            char buf[32];
                            if (column == 0) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Name.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 1) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].UserID.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 2) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Rank.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 3) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Hero.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 4) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Spell.c_str());
                                ImGui::TextUnformatted(buf);
                            }
                        }
                    }
                    ImGui::EndTable();
                }
                   
         }
      }
    
    }
    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    return orig_eglSwapBuffers(dpy, surface);
    
}


void *Init_Thread(void *) {
    copyFile(LibToLoad, LibToLoad2);
    
    
    while (!il2cppMap) {
        il2cppMap = Tools::GetBaseAddress(targetLib);
        sleep(1);
    }
    

    
    Tools::Hook((void *) DobbySymbolResolver(OBFUSCATE("/system/lib/libEGL.so"), OBFUSCATE("eglSwapBuffers")), (void *) _eglSwapBuffers, (void **) &orig_eglSwapBuffers);
    Tools::Hook((void *) DobbySymbolResolver(OBFUSCATE("/system/lib/libandroid.so"), OBFUSCATE("ANativeWindow_getWidth")), (void *) _ANativeWindow_getWidth, (void **) &orig_ANativeWindow_getWidth);
    Tools::Hook((void *) DobbySymbolResolver(OBFUSCATE("/system/lib/libandroid.so"), OBFUSCATE("ANativeWindow_getHeight")), (void *) _ANativeWindow_getHeight, (void **) &orig_ANativeWindow_getHeight);
    Tools::Hook((void *) DobbySymbolResolver(OBFUSCATE("/system/lib/libinput.so"), OBFUSCATE("_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE")), (void *) myInput, (void **) &origInput);
     

    IL2Cpp::Il2CppAttach(targetLib);
    sleep(5);
    
    Tools::Hook((void *) ShowEntity_get_m_CanSight, (void *) _ShowEntityBase, (void **) &oShowEntityBase);
    
Tools::Hook((void *) SystemData_GetHeroSkin, (void *) GetHeroSkin, (void **) &oGetHeroSkin);
    Tools::Hook((void *) SystemData_GetMCLimitSkin, (void *) GetMCLimitSkin, (void **) &oGetMCLimitSkin);
    Tools::Hook((void *) SystemData_GetHeroHolyStatue, (void *) GetHeroHolyStatue, (void **) &oGetHeroHolyStatue);
    Tools::Hook((void *) SystemData_IsCanUseSkin, (void *) IsCanUseSkin, (void **) &oIsCanUseSkin);
    Tools::Hook((void *) SystemData_IsHaveSkin, (void *) IsHaveSkin, (void **) &oIsHaveSkin);
    Tools::Hook((void *) SystemData_IsHaveSkinForever, (void *) IsHaveSkinForever, (void **) &oIsHaveSkinForever);
    Tools::Hook((void *) SystemData_IsHaveStatue, (void *) IsHaveStatue, (void **) &oIsHaveStatue);
    Tools::Hook((void *) SystemData_IsHaveStatueForever, (void *) IsHaveStatueForever, (void **) &oIsHaveStatueForever);
    Tools::Hook((void *) SystemData_IsForbidStatue, (void *) IsForbidStatue, (void **) &oIsForbidStatue);
    Tools::Hook((void *) SystemData_IsForbidSkin, (void *) IsForbidSkin, (void **) &oIsForbidSkin);
    Tools::Hook((void *) SystemData_IsForbidARSkin, (void *) IsForbidARSkin, (void **) &oIsForbidARSkin);
    Tools::Hook((void *) UIChooseHero_SendSelectSkin, (void *) SendSelectSkin, (void **) &oSendSelectSkin);
    Tools::Hook((void *) UIChooseHero_SendSelectSkin2, (void *) SendSelectSkin2, (void **) &oSendSelectSkin2);
    Tools::Hook((void *) UIChooseHero_ShowSkinExpiryDate, (void *) ShowSkinExpiryDate, (void **) &oShowSkinExpiryDate);
    Tools::Hook((void *) UIRankHero_BatttleSelectSkin, (void *) BatttleSelectSkin, (void **) &oBatttleSelectSkin);
    Tools::Hook((void *) UIRankHero_BatttleSelectSkin2, (void *) BatttleSelectSkin2, (void **) &oBatttleSelectSkin2);
    Tools::Hook((void *) UIRankHero_ChangeShow_SendUseSkin, (void *) SendUseSkin, (void **) &oSendUseSkin);
    Tools::Hook((void *) BattleReceiveMessage_SetPlayerData, (void *) SetPlayerData, (void **) &oSetPlayerData);
    Tools::Hook((void *) GameServerConfig_SendRawData, (void *) SendRawData, (void **) &oSendRawData);
   
    setupDone = true;
    
    return nullptr;
}
     
JNIEXPORT jint JNICALL CallJNIOL(JavaVM *vm, void *reserved) {
    LOGI("Exec %s", LibToLoad);
    
    pthread_t myThread;
    pthread_create(&myThread, NULL, Init_Thread, NULL);
    
    sleep(5);
    
    if (!pLibRealUnity) {
            LOGE("Failed to load library: %s", LibToLoad);
            pLibRealUnity = dlopen(LibToLoad3, RTLD_NOW);
        }
    

    if (!RealJNIOnLoad) {
        RealJNIOnLoad = reinterpret_cast<CallJNI_OnLoad_t>(dlsym(pLibRealUnity, "JNI_OnLoad"));
        if (!RealJNIOnLoad) {
            LOGE("Failed to find JNI_OnLoad symbol");
            return -1;
        }
    }
    return RealJNIOnLoad(vm, reserved);
  }

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    jvm = vm;
    JNIEnv *env;
    
    
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    
    
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        LOGE("Failed to get JNI environment");
        return -1;
    }
    
    

    LOGI("Initialize JNI");
    return CallJNIOL(vm, reserved);
}

