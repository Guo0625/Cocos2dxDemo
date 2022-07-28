
#include "Ad.h"
#include "../../cocos/platform/android/jni/JniHelper.h"

VIGAME_BEGIN

const std::string AndroidBridge_Path = "com/vimedia/game/AndroidBridge";

ADManager* ADManager::getInstance()
{
	static std::unique_ptr<ADManager> s_instance;
	static std::once_flag s_instance_created;
	std::call_once(s_instance_created, [=] { s_instance = std::make_unique<ADManager>(); });
	return s_instance.get();
}

void ADManager::OpenAd(std::string adName)
{
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo methodInfo;
    bool isExist = JniHelper::getStaticMethodInfo(methodInfo, AndroidBridge_Path, "openAd", "(Ljava/lang/String;)V");
	if(isExist) {
        CCLog("call OpenAd");
        jstring str = methodInfo.env->NewStringUTF(adName);//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str);//call Java method
        methodInfo.env->DeleteLocalRef(str);
	}else {
		CCLog("share error");
	}
    #endif
}

void ADManager::OpenYsAd(std::string adName, int width, int height, int x, int y)
{

}

void ADManager::CloseAd(std::string adName)
{

}

bool ADManager::IsAdReady(std::string adName)
{

}

bool ADManager::IsAdBeOpenInLevel(std::string adName, int level)
{

}

std::string ADManager::GetAdPositionParam(std::string adName, std::string param)
{

}

bool ADManager::IsAdTypeExist(std::string adType)
{

}

int ADManager::GetVideoLimitOpenNum()
{

}

VIGAME_END