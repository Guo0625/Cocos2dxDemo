
#ifndef __TJ_BASE_H__
#define __TJ_BASE_H__

#include <unordered_map>
#include <string>

#define VIGAME_BEGIN \
    namespace vigame \
    {
#define VIGAME_END }

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
};

VIGAME_END
#endif //__TJ_BASE_H__