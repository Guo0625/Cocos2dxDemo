#include "PayPc.h"
#include "cocos2d.h"

VIGAME_BEGIN

PayPc::PayPc(){}
PayPc::~PayPc(){}
void PayPc::init(){}
void PayPc::OrderPay(int payId) {}
void PayPc::OrderPay(int payId, int price) {}
void PayPc::OrderPay(int payId, std::string userData) {}
void PayPc::OrderPay(int payId, int price, std::string userData) {}
void PayPc::OrderPay(int payId, int price, int type, std::string userData) {}
void PayPc::OrderPayWithType(int payId, int price, int payType,std::string userData) {}
int PayPc::GetGiftCtrlFlagUse(int giftId) { return 0; }
bool PayPc::IsSupportExit() { return true; }
void PayPc::OpenExitGame() {}
bool PayPc::IsMoreGameBtn() { return true; }
void PayPc::OpenMoreGame() {}
bool PayPc::IsPayReady() { return true; }
std::string PayPc::GetDefaultFeeInfo() { return ""; }
int PayPc::GetDefaultPayType() { return 0; }
bool PayPc::IsBillingPointExist(std::string bp) { return true; }
int PayPc::GetButtonType(int id) { return 0; }
int PayPc::GetMarketType() { return 0; }
void PayPc::OpenMarket(std::string packageName) {}
void PayPc::OpenAppraise() {}

VIGAME_END