#include "CoreAndroid.h"
#include "cocos2d.h"

VIGAME_BEGIN

CoreAndroid::CoreAndroid()
{
}

CoreAndroid::~CoreAndroid()
{
}

void CoreAndroid::init()
{
}

std::string CoreAndroid::getSignature() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getSignature", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string str = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID)); //call Java method
		methodInfo.env->ExceptionClear();
		return str;
	}
	else
	{
		cocos2d::log("Core jni get getSignature function error");
		return "";
	}
#endif

}

VIGAME_END