#include "PayiOS.h"
#include "cocos2d.h"

#import "IOSLoader.h"

VIGAME_BEGIN

PayiOS::PayiOS(){}
PayiOS::~PayiOS(){}
void PayiOS::init(){}
void PayiOS::OrderPay(int payId) 
{
    [IOSLoader purchaseWithProductId] 
}

void PayiOS::OrderPay(int payId, int price) {}
void PayiOS::OrderPay(int payId, std::string userData) {}
void PayiOS::OrderPay(int payId, int price, std::string userData) {}
void PayiOS::OrderPay(int payId, int price, int type, std::string userData) {}
void PayiOS::OrderPayWithType(int payId, int price, int payType,std::string userData) {}
int PayiOS::GetGiftCtrlFlagUse(int giftId) { return 0; }
bool PayiOS::IsSupportExit() { return true; }
void PayiOS::OpenExitGame() {}
bool PayiOS::IsMoreGameBtn() { return true; }
void PayiOS::OpenMoreGame() {}
bool PayiOS::IsPayReady() { return true; }
std::string PayiOS::GetDefaultFeeInfo() { return ""; }
int PayiOS::GetDefaultPayType() { return 0; }
bool PayiOS::IsBillingPointExist(std::string bp) { return true; }
int PayiOS::GetButtonType(int id) { return 0; }
int PayiOS::GetMarketType() { return 0; }
void PayiOS::OpenMarket(std::string packageName) {}
void PayiOS::OpenAppraise() {}

VIGAME_END