
#ifndef __TJ_BASE_H__
#define __TJ_BASE_H__

#include <unordered_map>
#include "../../utils/macros.h"

VIGAME_BEGIN

class TjBase
{
public:
    virtual void init() = 0;
    virtual void TJCustomEvent(std::string eventId) = 0;
    virtual void TJCustomEvent(std::string eventId, std::string attributes) = 0;
    virtual void TJCustomEvent(std::string eventId, std::unordered_map<std::string, std::string> attributes) = 0;
    virtual void TJEventValue(std::string eventId, std::string attributes, int duration) = 0;
    virtual void TJEventValue(std::string eventId, std::unordered_map<std::string, std::string> attributes, int duration) = 0;
    virtual void StartLevel(std::string level) = 0;
    virtual void FinishLevel(std::string level, std::string score) = 0;
    virtual void FailLevel(std::string level, std::string score) = 0;
    virtual void TJPay(double money, double coin, int source) = 0;
    virtual void TJPayAndBuy(double money, std::string item, int number, double price, int source) = 0;
    virtual void onPageStart(std::string sid) = 0;
    virtual void onPageEnd(std::string sid) = 0;

    virtual void ProfileSignIn(std::string provider, std::string puid) = 0;
    virtual void ProfileSignOff() = 0;
    virtual void Buy(std::string item, int number, double price) = 0;
    virtual void Use(std::string item, int number, double price) = 0;
    virtual void Bonus(double coin, int trigger) = 0;
    virtual void Bonus(std::string item, int number, double price, int trigger) = 0;
};

VIGAME_END
#endif //__TJ_BASE_H__