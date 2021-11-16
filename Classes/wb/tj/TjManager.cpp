#include "cocos2d.h"
#include "TjManager.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/TjAndroid.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "platform/TjPc.h"
#endif

VIGAME_BEGIN
TjManager *TjManager::getInstance()
{
	static std::unique_ptr<TjManager> s_instance;
	static std::once_flag s_instance_created;
	std::call_once(s_instance_created, [=]
				   { s_instance = std::make_unique<TjManager>(); });
	return s_instance.get();
}

TjManager::TjManager()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	mInterface = new vigame::TjAndroid();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	mInterface = new vigame::TjiOS();
#else
	mInterface = new vigame::TjPc();
#endif
	mInterface->init();
}

TjManager::~TjManager()
{
}

void TjManager::TJCustomEvent(std::string eventId)
{
	mInterface->TJCustomEvent(eventId);
}

void TjManager::TJCustomEvent(std::string eventId, std::string attributes)
{
	mInterface->TJCustomEvent(eventId, attributes);
}

void TjManager::TJCustomEvent(std::string eventId, std::unordered_map<std::string, std::string> attributes) 
{
	mInterface->TJCustomEvent(eventId, attributes);
}

void TjManager::TJEventValue(std::string eventId, std::string attributes, int duration) 
{ 
	mInterface->TJEventValue(eventId, attributes, duration); 
}

void TjManager::StartLevel(std::string level) 
{ 
	mInterface->StartLevel(level); 
}

void TjManager::FinishLevel(std::string level, std::string score) 
{
	mInterface->FinishLevel(level, score); 
}

void TjManager::FailLevel(std::string level, std::string score) 
{ 
	mInterface->FailLevel(level, score); 
}

void TjManager::TJPay(double money, double coin, int source) 
{ 
	mInterface->TJPay(money, coin, source); 
}

void TjManager::TJPayAndBuy(double money, std::string item, int number, double price, int source) 
{ 
	mInterface->TJPayAndBuy(money, item, number, price, source); 
}

void TjManager::onPageStart(std::string sid) 
{ 
	mInterface->onPageStart(sid); 
}

void TjManager::onPageEnd(std::string sid) 
{ 
	mInterface->onPageEnd(sid); 
}

VIGAME_END