LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                    ../../Classes/wb/utils/Utils.cpp \
                    ../../Classes/wb/ad/platform/ADAndroid.cpp \
                    ../../Classes/wb/ad/ADManager.cpp \
                    ../../Classes/wb/tj/platform/TjAndroid.cpp \
                    ../../Classes/wb/tj/TjManager.cpp \
                    ../../Classes/wb/pay/platform/PayAndroid.cpp \
                    ../../Classes/wb/pay/PayManager.cpp \
                    ../../Classes/wb/core/platform/CoreAndroid.cpp \
                    ../../Classes/wb/core/CoreManager.cpp \
                    ../../Classes/wb/social/platform/SocialAndroid.cpp \
                    ../../Classes/wb/social/SocialManager.cpp \
                    ../../Classes/AppDelegate.cpp \
                    ../../Classes/MainScene.cpp \
                    ../../Classes/Home.cpp \
                    ../../Classes/AD.cpp \
                    ../../Classes/Pay.cpp \
                    ../../Classes/TJ.cpp \
                    ../../Classes/Social.cpp \
                    ../../Classes/Base.cpp 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

LOCAL_CPPFLAGS += -frtti -fexceptions -std=c++14
LOCAL_CFLAGS += -ffunction-sections -fdata-sections
LOCAL_LDFLAGS += -Wl,--gc-sections 

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
