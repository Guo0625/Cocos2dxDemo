#include "cocos2d.h"
#include "SocialManager.h"
#include "../utils/Utils.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/SocialAndroid.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "platform/SocialiOS.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "platform/SocialPc.h"
#endif

VIGAME_BEGIN

SocialManager *SocialManager::getInstance()
{
	static std::unique_ptr<SocialManager> s_instance;
	static std::once_flag s_instance_created;
	std::call_once(s_instance_created, [=]
				   { s_instance = std::make_unique<SocialManager>(); });
	return s_instance.get();
}

SocialManager::SocialManager()
{
	this->loginCallFun = nullptr;
	this->userInfoCallFun = nullptr;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	mInterface = new vigame::SocialAndroid();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	this->mInterface = new vigame::SocialiOS();
#else
	this->mInterface = new vigame::SocialPc();
#endif
	this->mInterface->init();
}

SocialManager::~SocialManager()
{

}

void SocialManager::Login(LoginType type, std::function<void(bool)> func)
{
	this->loginCallFun = func;
	this->mInterface->Login(static_cast<int>(type));
}

void SocialManager::GetUserInfo(LoginType type, std::function<void(bool, std::string)> func)
{
	this->userInfoCallFun = func;
	this->mInterface->GetUserInfo(static_cast<int>(type));
}

void SocialManager::LoginCallBack(std::string result)
{
	if (this->loginCallFun == nullptr) return;
	cocos2d::log("Social LoginCallBack result = %s", result.c_str());
	bool isSuccess = false;
	if (result == "true")
	{
		isSuccess = true;
	}

	this->loginCallFun(isSuccess);
	this->loginCallFun = nullptr;
}

void SocialManager::GetUserInfoCallBack(std::string params)
{
	if (this->userInfoCallFun == nullptr) return;
	cocos2d::log("Social GetUserInfoCallBack params = %s", params.c_str());
	std::vector<std::string> tokens = vigame::Utils::getInstance()->Split(params, "#");
	std::string userInfo = tokens[0];
	std::string result = tokens[1];
	bool isSuccess = result == "true";

	this->userInfoCallFun(isSuccess, userInfo);
	this->userInfoCallFun = nullptr;
}

bool SocialManager::IsSupportSocialAgent(LoginType socialType)
{
	return this->mInterface->IsSupportSocialAgent(socialType);
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
extern "C"
{
	JNIEXPORT void Java_com_vimedia_cocos2dxbridge_Cocos2dxWbActivity_LoginCallBack(JNIEnv *env, jobject thiz, jstring jparams)
	{
		std::string params = cocos2d::JniHelper::jstring2string(jparams);
		vigame::SocialManager::getInstance()->LoginCallBack(params);
	}

	JNIEXPORT void Java_com_vimedia_cocos2dxbridge_Cocos2dxWbActivity_GetUserInfoCallBack(JNIEnv *env, jobject thiz, jstring jparams)
	{
		std::string params = cocos2d::JniHelper::jstring2string(jparams);
		vigame::SocialManager::getInstance()->GetUserInfoCallBack(params);
	}
}

#endif

VIGAME_END