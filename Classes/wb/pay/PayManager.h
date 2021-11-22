#ifndef __PAY_MANAGER_H__
#define __PAY_MANAGER_H__

#include <string>
#include <map>
#include <queue>
#include <functional>
#include "interface/PayBase.h"

#define VIGAME_BEGIN                     namespace vigame {
#define VIGAME_END                       }

VIGAME_BEGIN

enum PayTypeDef
{
    //支付类型
    PAY_TYPE_Free = -1,
    PAY_TYPE_NOFEE = 0,
    PAY_TYPE_QPAY = 1,
    PAY_TYPE_MM = 2,
    PAY_TYPE_CMGAME = 3,
    PAY_TYPE_UNI = 4,
    PAY_TYPE_UNIWo = 5,
    PAY_TYPE_CTEStore = 6,
    PAY_TYPE_Egame = 7,
    PAY_TYPE_Telecom = 9,//电信开放平台
    PAY_TYPE_AliPay = 10,//支付宝支付
    PAY_TYPE_WXPay = 11,//微信
    //PAY_TYPE_Thrid = 12,//第三方渠道支付
    PAY_TYPE_NetPay = 13,//网络支付:微信和支付宝
    PAY_TYPE_Amigo = 100,
    PAY_TYPE_Duoku = 101,
    PAY_TYPE_Kugou = 102,
    PAY_TYPE_360 = 103,
    PAY_TYPE_OPPO = 104,
    PAY_TYPE_Anzhi = 105,
    PAY_TYPE_Mi = 106,
    PAY_TYPE_Vivo = 107,
    PAY_TYPE_MiWeChat = 108,
    PAY_TYPE_Meizu = 109,
    PAY_TYPE_UC = 110,
    PAY_TYPE_Midas = 111,
    PAY_TYPE_GooglePlay = 112,
    PAY_TYPE_Huawei = 113,
    PAY_TYPE_YSDK = 114,
    PAY_TYPE_COOLPAD = 115,
    PAY_TYPE_AliGame = 116
};

enum PayStatus
{
    PaySuccess = 1, // 支付成功
    PayFail = 0, // 支付失败
    PayCancel = -1 // 支付取消
};

class PayManager
{
public:
	PayManager();
	~PayManager();
	static PayManager* getInstance();
	void OrderPay(int payId, std::function<void(PayStatus, int, std::string)> func);
	void OrderPay(int payId, int price, std::function<void(PayStatus, int, std::string)> func);
	void OrderPay(int payId, std::string userData, std::function<void(PayStatus, int, std::string)> func);
	void OrderPay(int payId, int price, std::string userData, std::function<void(PayStatus, int, std::string)> func);
	void OrderPay(int payId, int price, int type, std::string userData, std::function<void(PayStatus, int, std::string)> func);
	void OrderPayWithType(int payId, int price, int payType,std::string userData, std::function<void(PayStatus, int, std::string)> func);
	int GetGiftCtrlFlagUse(int giftId);
	bool IsSupportExit();
	void OpenExitGame();
	bool IsMoreGameBtn();
	void OpenMoreGame();
	bool IsPayReady();
	std::string GetDefaultFeeInfo();
	int GetDefaultPayType();
	bool IsBillingPointExist(std::string bp);
	int GetButtonType(int id);
	int GetMarketType();
	void OpenMarket(std::string packageName);
	void OpenAppraise();
	void PayCheckCallBack(std::string params);
    void setPayCallBack(std::function<void(PayStatus, int, std::string)> func);

    /**
     * @brief 获取补单列表
     * 
     * @return std::vector<std::string> 
     */
    std::vector<std::string> GetPayList();

    /**
     * @brief 根据id删除补单
     * 
     * @param payId 
     */
    void ClearPayList(int payId);

    /** 上报用户游戏信息
     * @brief 
     * 
     * @param roldId 
     * @param roleName 
     * @param roleLevel 
     * @param realmId 
     * @param realmName 
     * @param chapter 
     * @param combatValue 
     * @param pointValue 
     * @param ext 
     */
    void ReportUserGameInfo(std::string roldId, std::string roleName, int roleLevel, std::string realmId, std::string realmName, std::string chapter, int combatValue, int pointValue, std::string ext);
private:
    PayBase* mInterface;
	std::function<void(PayStatus, int, std::string)> func;
	std::vector<std::string> Split(std::string s, std::string delimiter);
};

VIGAME_END

#endif //__PAY_MANAGER_H__