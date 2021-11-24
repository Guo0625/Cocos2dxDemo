
#ifndef __PAY_ADDROID_H__
#define __PAY_ADDROID_H__

#include "../interface/PayBase.h"

VIGAME_BEGIN

class PayAndroid:public PayBase
{
public:
	PayAndroid();
	~PayAndroid();
    void init() override;
    void OrderPay(int payId) override;
    void OrderPay(int payId, int price) override;
    void OrderPay(int payId, std::string userData) override;
    void OrderPay(int payId, int price, std::string userData) override;
    void OrderPay(int payId, int price, int type, std::string userData) override;
    int GetGiftCtrlFlagUse(int giftId) override;
    bool IsSupportExit() override;
    void OpenExitGame() override;
    bool IsMoreGameBtn() override;
    void OpenMoreGame() override;
    bool IsPayReady() override;
    std::string GetDefaultFeeInfo() override;
    int GetDefaultPayType() override;
    bool IsBillingPointExist(std::string bp) override;
    int GetButtonType(int id) override;
    int GetMarketType() override;
    void OrderPayWithType(int payId, int price, int payType,std::string userData) override;
    void OpenMarket(std::string packageName) override;
    void OpenAppraise() override;
    std::string GetPayList() override;
    void ClearPayList(int payId) override;
    void ReportUserGameInfo(std::string roldId, std::string roleName, int roleLevel, std::string realmId, std::string realmName, std::string chapter, int combatValue, int pointValue, std::string ext) override;
};

VIGAME_END

#endif //__PAY_ADDROID_H__