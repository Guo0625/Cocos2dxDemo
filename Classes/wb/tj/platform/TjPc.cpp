#include "TjPc.h"
#include "cocos2d.h"

VIGAME_BEGIN

TjPc::TjPc()
{
}

TjPc::~TjPc()
{
}

void TjPc::init()
{
}

void TjPc::TJCustomEvent(std::string eventId)
{
}

void TjPc::TJCustomEvent(std::string eventId, std::string attributes)
{
}

void TjPc::TJCustomEvent(std::string eventId, std::unordered_map<std::string, std::string> attributes)
{
}

void TjPc::TJEventValue(std::string eventId, std::string attributes, int duration)
{
}

void TjPc::TJEventValue(std::string eventId, std::unordered_map<std::string, std::string> attributes, int duration)
{
}

void TjPc::StartLevel(std::string level)
{
}

void TjPc::FinishLevel(std::string level, std::string score)
{
}

void TjPc::FailLevel(std::string level, std::string score)
{
}

void TjPc::TJPay(double money, double coin, int source)
{
}

void TjPc::TJPayAndBuy(double money, std::string item, int number, double price, int source)
{
}

void TjPc::onPageStart(std::string sid)
{
}

void TjPc::onPageEnd(std::string sid)
{
}

void TjPc::ProfileSignIn(std::string provider, std::string puid)
{

}

void TjPc::ProfileSignOff()
{

}

void TjPc::Use(std::string item, int number, double price)
{

}

void TjPc::Bonus(double coin, int trigger)
{

}

void TjPc::Bonus(std::string item, int number, double price, int trigger)
{

}


VIGAME_END