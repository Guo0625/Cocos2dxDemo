#include "TjiOS.h"
#include "cocos2d.h"

VIGAME_BEGIN

TjiOS::TjiOS()
{
}

TjiOS::~TjiOS()
{
}

void TjiOS::init()
{
}

void TjiOS::TJCustomEvent(std::string eventId)
{
}

void TjiOS::TJCustomEvent(std::string eventId, std::string attributes)
{
}

void TjiOS::TJCustomEvent(std::string eventId, std::unordered_map<std::string, std::string> attributes)
{
}

void TjiOS::TJEventValue(std::string eventId, std::string attributes, int duration)
{
}

void TjiOS::TJEventValue(std::string eventId, std::unordered_map<std::string, std::string> attributes, int duration)
{
}

void TjiOS::StartLevel(std::string level)
{
}

void TjiOS::FinishLevel(std::string level, std::string score)
{
}

void TjiOS::FailLevel(std::string level, std::string score)
{
}

void TjiOS::TJPay(double money, double coin, int source)
{
}

void TjiOS::TJPayAndBuy(double money, std::string item, int number, double price, int source)
{
}

void TjiOS::onPageStart(std::string sid)
{
}

void TjiOS::onPageEnd(std::string sid)
{
}

VIGAME_END