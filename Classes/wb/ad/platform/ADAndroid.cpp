
#include "ADAndroid.h"
#include "cocos2d.h"

VIGAME_BEGIN

ADAndroid::ADAndroid()
{
}

ADAndroid::~ADAndroid()
{
}

void ADAndroid::init()
{

}

void ADAndroid::OpenAd(std::string adName)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openAd", "(Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(adName.c_str());							//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("AD jni get openAd function error");
	}
#endif
}

void ADAndroid::OpenYsAd(std::string adName, int width, int height, int x, int y)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openYsAd", "(Ljava/lang/String;IIIII)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(adName.c_str());													//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str, width, height, x, y, 1); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("AD jni get openYsAd function error");
	}
#endif
}

void ADAndroid::CloseAd(std::string adName)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "closeAd", "(Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(adName.c_str());							//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("AD jni get closeAd function error");
	}
#endif
}

bool ADAndroid::IsAdReady(std::string adName)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "isAdReady", "(Ljava/lang/String;)Z");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(adName.c_str());										  //create jstring
		bool ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("AD jni get isAdReady function error");
		return false;
	}
#endif
}

bool ADAndroid::IsAdBeOpenInLevel(std::string adName, int level)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "isAdBeOpenInLevel", "(Ljava/lang/String;I)Z");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(adName.c_str());												 //create jstring
		bool ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID, str, level); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("AD jni get isAdReady function error");
		return false;
	}
#endif
}

std::string ADAndroid::GetAdPositionParam(std::string adName, std::string param)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getAdPositionParam", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
	if (isExist)
	{
		jstring str1 = methodInfo.env->NewStringUTF(adName.c_str());																								  //create jstring
		jstring str2 = methodInfo.env->NewStringUTF(param.c_str());																									  //create jstring
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)(methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, str1, str2))); //call Java method
		methodInfo.env->DeleteLocalRef(str1);
		methodInfo.env->DeleteLocalRef(str2);
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("AD jni get isAdReady function error");
		return "";
	}
#endif
}

bool ADAndroid::IsAdTypeExist(std::string adType)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "isAdTypeExist", "(Ljava/lang/String)Z");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(adType.c_str());										  //create jstring
		bool ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("AD jni get isAdReady function error");
		return false;
	}
#endif
}

int ADAndroid::GetVideoLimitOpenNum()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getVideoLimitOpenNum", "()I");
	if (isExist)
	{
		jint ret = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("AD jni get isAdReady function error");
		return 0;
	}
#endif
}

VIGAME_END