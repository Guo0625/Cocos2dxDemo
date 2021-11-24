
#ifndef __TJ_IOS_H__
#define __TJ_IOS_H__

#include "../interface/TjBase.h"

VIGAME_BEGIN

class TjiOS:public TjBase
{
public:
	TjiOS();
	~TjiOS();
    void init() override;
    void TJCustomEvent(std::string eventId) override;
    void TJCustomEvent(std::string eventId, std::string attributes) override;
    void TJCustomEvent(std::string eventId, std::unordered_map<std::string, std::string> attributes) override;
    void TJEventValue(std::string eventId, std::string attributes, int duration) override;
    void TJEventValue(std::string eventId, std::unordered_map<std::string, std::string> attributes, int duration) override;
    void StartLevel(std::string level) override;
    void FinishLevel(std::string level, std::string score) override;
    void FailLevel(std::string level, std::string score) override;
    void TJPay(double money, double coin, int source) override;
    void TJPayAndBuy(double money, std::string item, int number, double price, int source) override;
    void onPageStart(std::string sid) override;
    void onPageEnd(std::string sid) override;
    void ProfileSignIn(std::string provider, std::string puid) override;
    void ProfileSignOff() override;
    void Buy(std::string item, int number, double price) override;
    void Use(std::string item, int number, double price) override;
    void Bonus(double coin, int trigger) override;
    void Bonus(std::string item, int number, double price, int trigger) override;
};

VIGAME_END
#endif //__TJ_IOS_H__