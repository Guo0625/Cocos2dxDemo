#include "SocialAndroid.h"
#include "cocos2d.h"

VIGAME_BEGIN

SocialAndroid::SocialAndroid() 
{

}

SocialAndroid::~SocialAndroid() 
{

}

void SocialAndroid::init() 
{

}

void SocialAndroid::Login(int type)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "login", "(I)V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, type); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Social jni get login function error");
	}
#endif
}

void SocialAndroid::GetUserInfo(int type)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getUserInfo", "(I)V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, type); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Social jni get getUserInfo function error");
	}
#endif
}

bool SocialAndroid::IsSupportSocialAgent(int socialType)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "isSupportSocialAgent", "(I)Z");
	if (isExist)
	{
		bool ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID, socialType); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Social jni get isSupportSocialAgent function error");
		return false;
	}
#endif
}

VIGAME_END