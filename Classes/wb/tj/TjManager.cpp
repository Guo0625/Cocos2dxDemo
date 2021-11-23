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
	this->mInterface = new vigame::TjAndroid();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	mInterface = new vigame::TjiOS();
#else
	mInterface = new vigame::TjPc();
#endif
	this->mInterface->init();
}

TjManager::~TjManager()
{
}

/**
 * @brief 自定义事件(getSignature方法先调用这个)
 * 
 * @param eventId 
 */
void TjManager::TJCustomEvent(std::string eventId)
{
	this->mInterface->TJCustomEvent(eventId);
}

/**
 * @brief 自定义事件(单属性)
 * 
 * @param eventId 
 * @param attributes 
 */
void TjManager::TJCustomEvent(std::string eventId, std::string attributes)
{
	this->mInterface->TJCustomEvent(eventId, attributes);
}

/**
 * @brief 自定义事件(多属性)
 * 
 * @param eventId 
 * @param attributes 
 */
void TjManager::TJCustomEvent(std::string eventId, std::unordered_map<std::string, std::string> attributes) 
{
	this->mInterface->TJCustomEvent(eventId, attributes);
}

/**
 * @brief 自定义计算事件
 * 
 * @param eventId 
 * @param attributes 
 * @param duration 
 */
void TjManager::TJEventValue(std::string eventId, std::string attributes, int duration) 
{ 
	this->mInterface->TJEventValue(eventId, attributes, duration); 
}

/**
 * @brief 关卡开始
 * 
 * @param level 
 */
void TjManager::StartLevel(std::string level) 
{ 
	this->mInterface->StartLevel(level); 
}

/**
 * @brief 关卡结束
 * 
 * @param level 
 * @param score 
 */
void TjManager::FinishLevel(std::string level, std::string score) 
{
	this->mInterface->FinishLevel(level, score); 
}

/**
 * @brief 关卡失败
 * 
 * @param level 
 * @param score 
 */
void TjManager::FailLevel(std::string level, std::string score) 
{ 
	this->mInterface->FailLevel(level, score); 
}

/**
 * @brief 充值
 * 
 * @param money 
 * @param coin 
 * @param source 
 */
void TjManager::TJPay(double money, double coin, int source) 
{ 
	this->mInterface->TJPay(money, coin, source); 
}

/**
 * @brief 充值并购买道具
 * 
 * @param money 
 * @param item 
 * @param number 
 * @param price 
 * @param source 
 */
void TjManager::TJPayAndBuy(double money, std::string item, int number, double price, int source) 
{ 
	this->mInterface->TJPayAndBuy(money, item, number, price, source); 
}

/**
 * @brief 页面开始
 * 
 * @param sid 
 */
void TjManager::onPageStart(std::string sid) 
{ 
	this->mInterface->onPageStart(sid); 
}

/**
 * @brief 页面结束
 * 
 * @param sid 
 */
void TjManager::onPageEnd(std::string sid) 
{ 
	this->mInterface->onPageEnd(sid); 
}

/**
 * @brief 账号统计
 * 
 * @param provider 
 * @param puid 
 */
void TjManager::TJProfileSignIn(std::string provider, std::string puid) 
{
	this->mInterface->ProfileSignIn(provider, puid);
}

/**
 * @brief 账号统计
 * 
 */
void TjManager::TJProfileSignOff() 
{
	this->mInterface->ProfileSignOff();
}

/**
 * @brief 消耗
 * 
 * @param item 
 * @param number 
 * @param price 
 */
void TjManager::TJUse(std::string item, int number, double price) 
{
	this->mInterface->Use(item, number, price);
}

/**
 * @brief 赠送金币
 * 
 * @param coin 
 * @param trigger 
 */
void TjManager::TJBonus(double coin, int trigger) 
{
	this->mInterface->Bonus(coin, trigger);
}

/**
 * @brief 赠送道具
 * 
 * @param item 
 * @param number 
 * @param price 
 * @param trigger 
 */
void TjManager::TJBonus(std::string item, int number, double price, int trigger) 
{
	this->mInterface->Bonus(item, number, price, trigger);
}


VIGAME_END