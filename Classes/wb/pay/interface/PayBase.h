
#ifndef __PAY_BASE_H__
#define __PAY_BASE_H__

#include <string>

#define VIGAME_BEGIN \
    namespace vigame \
    {
#define VIGAME_END }

VIGAME_BEGIN

class PayBase
{
public:
    virtual void init() = 0;
    virtual void OrderPay(int payId)=0;
    virtual void OrderPay(int payId, int price)=0;
    virtual void OrderPay(int payId, std::string userData)=0;
    virtual void OrderPay(int payId, int price, std::string userData)=0;
    virtual void OrderPay(int payId, int price, int type, std::string userData)=0;
    virtual int GetGiftCtrlFlagUse(int giftId)=0;
    virtual bool IsSupportExit()=0;
    virtual void OpenExitGame()=0;
    virtual bool IsMoreGameBtn()=0;
    virtual void OpenMoreGame()=0;
    virtual bool IsPayReady()=0;
    virtual std::string GetDefaultFeeInfo()=0;
    virtual int GetDefaultPayType()=0;
    virtual bool IsBillingPointExist(std::string bp)=0;
    virtual int GetButtonType(int id)=0;
    virtual int GetMarketType()=0;
    virtual void OrderPayWithType(int payId, int price, int payType,std::string userData)=0;
    virtual void OpenMarket(std::string packageName)=0;
    virtual void OpenAppraise()=0;
    virtual std::string GetPayList()=0;
    virtual void ClearPayList(int payId)=0;
    virtual void ReportUserGameInfo(std::string roldId, std::string roleName, int roleLevel, std::string realmId, std::string realmName, std::string chapter, int combatValue, int pointValue, std::string ext) = 0;
};

VIGAME_END

#endif //__PAY_BASE_H__