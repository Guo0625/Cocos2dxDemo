#ifndef __TJ_MANAGER_H__
#define __TJ_MANAGER_H__

#include <string>
#include <map>
#include <queue>
#include <functional>
#include "interface/TjBase.h"

#define VIGAME_BEGIN                     namespace vigame {
#define VIGAME_END                       }

VIGAME_BEGIN

class TjManager
{
public:
	TjManager();
	~TjManager();
	static TjManager* getInstance();
    void TJCustomEvent(std::string eventId);
    void TJCustomEvent(std::string eventId, std::string attributes);
    void TJCustomEvent(std::string eventId, std::unordered_map<std::string, std::string> attributes);
    void TJEventValue(std::string eventId, std::string attributes,int duration);
    void StartLevel(std::string level);
    void FinishLevel(std::string level, std::string score);
    void FailLevel(std::string level, std::string score);
    void TJPay(double money,double coin, int source);
    void TJPayAndBuy(double money, std::string item, int number, double price, int source);
    void onPageStart(std::string sid);
    void onPageEnd(std::string sid);
    void TJProfileSignIn(std::string provider, std::string puid);
    void TJProfileSignOff();
    void TJUse(std::string item, int number, double price);
    void TJBonus(double coin, int trigger);
    void TJBonus(std::string item, int number, double price, int trigger);

private:
    TjBase* mInterface;
};

VIGAME_END

#endif //__TJ_MANAGER_H__