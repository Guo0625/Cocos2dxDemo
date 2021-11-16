#include "cocos2d.h"
#include "CoreManager.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/CoreAndroid.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "platform/CoreiOS.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "platform/CorePc.h"
#endif

VIGAME_BEGIN

CoreManager *CoreManager::getInstance()
{
	static std::unique_ptr<CoreManager> s_instance;
	static std::once_flag s_instance_created;
	std::call_once(s_instance_created, [=]
				   { s_instance = std::make_unique<CoreManager>(); });
	return s_instance.get();
}

CoreManager::CoreManager()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	mInterface = new vigame::CoreAndroid();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	mInterface = new vigame::CoreiOS();
#else
	mInterface = new vigame::CorePc();
#endif
	mInterface->init();
}

CoreManager::~CoreManager()
{
}

std::string CoreManager::getSignature() 
{
	return mInterface->getSignature();
}

VIGAME_END