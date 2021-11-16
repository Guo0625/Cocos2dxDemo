
#ifndef __PAY_IOS_H__
#define __PAY_IOS_H__

#include <string>
#include "../interface/PayBase.h"
#define VIGAME_BEGIN                     namespace vigame {
#define VIGAME_END                       }

VIGAME_BEGIN

class PayiOS:public PayBase
{
public:
	PayiOS();
	~PayiOS();
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
};

VIGAME_END

#endif //__PAY_IOS_H__