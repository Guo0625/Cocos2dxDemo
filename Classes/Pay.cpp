#include "Pay.h"
#include "Home.h"
#include "SimpleAudioEngine.h"
#include "wb/wb.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h" 

USING_NS_CC;
using namespace cocos2d::ui;

// on "init" you need to initialize your instance
bool Pay::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto pay = CSLoader::createNode("Pay.csb");
    pay->setPosition(Vec2(0, (visibleSize.height - 1136)/2));
    this->addChild(pay);

    Button* backBtn = static_cast<Button*>(pay->getChildByName("Back")); 
    backBtn->addClickEventListener(CC_CALLBACK_1(Pay::backBtnCallBack,this));

    auto view = pay->getChildByName("ListView_1");
    auto panel1 = view->getChildByName("Panel_1");

    Button* btn1 = static_cast<Button*>(panel1->getChildByName("Button_1")); 
    btn1->addClickEventListener(CC_CALLBACK_1(Pay::btn1CallBack,this));

    Button* btn2 = static_cast<Button*>(panel1->getChildByName("Button_2")); 
    btn2->addClickEventListener(CC_CALLBACK_1(Pay::btn2CallBack,this));

    auto panel2 = view->getChildByName("Panel_2");
    Button* btn3 = static_cast<Button*>(panel2->getChildByName("Button_1")); 
    btn3->addClickEventListener(CC_CALLBACK_1(Pay::btn3CallBack,this));

    Button* btn4 = static_cast<Button*>(panel2->getChildByName("Button_2")); 
    btn4->addClickEventListener(CC_CALLBACK_1(Pay::btn4CallBack,this));

    auto panel3 = view->getChildByName("Panel_3");
    Button* btn5 = static_cast<Button*>(panel3->getChildByName("Button_1")); 
    btn5->addClickEventListener(CC_CALLBACK_1(Pay::btn5CallBack,this));

    Button* btn6 = static_cast<Button*>(panel3->getChildByName("Button_2")); 
    btn6->addClickEventListener(CC_CALLBACK_1(Pay::btn6CallBack,this));

    auto panel4 = view->getChildByName("Panel_4");
    Button* btn7 = static_cast<Button*>(panel4->getChildByName("Button_1")); 
    btn7->addClickEventListener(CC_CALLBACK_1(Pay::btn7CallBack,this));

    Button* btn8 = static_cast<Button*>(panel4->getChildByName("Button_2")); 
    btn8->addClickEventListener(CC_CALLBACK_1(Pay::btn8CallBack,this));

    auto view2 = pay->getChildByName("ListView_2");
    auto panel5 = view2->getChildByName("Panel_1");
    Button* btn9 = static_cast<Button*>(panel5->getChildByName("Button_1")); 
    btn9->addClickEventListener(CC_CALLBACK_1(Pay::btn9CallBack,this));
    
    Button* btn10 = static_cast<Button*>(panel5->getChildByName("Button_2")); 
    btn10->addClickEventListener(CC_CALLBACK_1(Pay::btn10CallBack,this));

    auto panel6 = view2->getChildByName("Panel_2");
    Button* btn11 = static_cast<Button*>(panel6->getChildByName("Button_1")); 
    btn11->addClickEventListener(CC_CALLBACK_1(Pay::btn11CallBack,this));
    
    Button* btn12 = static_cast<Button*>(panel6->getChildByName("Button_2")); 
    btn12->addClickEventListener(CC_CALLBACK_1(Pay::btn12CallBack,this));
    
    auto panel7 = view2->getChildByName("Panel_3");
    Button* btn13 = static_cast<Button*>(panel7->getChildByName("Button_1")); 
    btn13->addClickEventListener(CC_CALLBACK_1(Pay::btn13CallBack,this));

    return true;
}

void Pay::backBtnCallBack(Ref* pSender)
{
    auto home = Home::create();
	Director::getInstance()->getRunningScene()->addChild(home);
	this->removeFromParent();
}

void Pay::btn1CallBack(Ref* pSender)
{
    // check current billing  implementation type; only list few pay type.
    int defType = vigame::PayManager::getInstance()->GetDefaultPayType();
    std::string result = "";
    switch (defType)
    {
        case vigame::PayTypeDef::PAY_TYPE_Free:
            result = "Free";
            break;
        case vigame::PayTypeDef::PAY_TYPE_AliPay:
            result = "Alipay";
            break;
        case vigame::PayTypeDef::PAY_TYPE_WXPay:
            result = "WeChatPay";
            break;
        case vigame::PayTypeDef::PAY_TYPE_Mi:
            result = "MiPay";
            break;
        case vigame::PayTypeDef::PAY_TYPE_OPPO:
            result = "OppoPay";
            break;
        case vigame::PayTypeDef::PAY_TYPE_Vivo:
            result = "VivoPay";
            break;
        case vigame::PayTypeDef::PAY_TYPE_Huawei:
            result = "HuaweiPay";
            break;
        case vigame::PayTypeDef::PAY_TYPE_NOFEE:
            result = "NoFee";
            break;
        default:
            result = "";
            cocos2d::log("PayManager PAY_TYPE = %d", defType);
            break;
    }
    if(result != "") 
    {
        cocos2d::log("PayManager PAY_TYPE = %s", result.c_str());
    }
}

void Pay::btn2CallBack(Ref* pSender)
{
    std::string info = vigame::PayManager::getInstance()->GetDefaultFeeInfo();
    cocos2d::log("PayManager FeeInfo %s", info.c_str());
    // check the pay id whether exist.
    if(vigame::PayManager::getInstance()->IsBillingPointExist("1001"))
    {
        cocos2d::log("PayManager Billing Point Is Exist.");
    } else {
        cocos2d::log("PayManager Billing Point Is Not Exist.");
    }
}

void Pay::btn3CallBack(Ref* pSender)
{
    // get the gift switch
    // ctrl id：控制参数（
    // 1-新手礼包 - 进入游戏首页时如果没购买过新手礼包则弹出
    // 2-快冲 - 用户虚拟货币不足时弹出
    // 3-限时礼包 - 进入游戏首页时如果已经买过新手礼包则弹出
    // 4-过关奖励 - 过关时弹出
    // 5-vip礼包 - 进入关卡选择页时弹出 6-今日特价
    // 7-实惠大礼包
    // 8-商城）
    int giftId = 1;
    cocos2d::log("PayManager 值为 %d", vigame::PayManager::getInstance()->GetGiftCtrlFlagUse(giftId));
}

void Pay::btn4CallBack(Ref* pSender)
{
    // get button type，payID--pay ID; retrurn ：0 buy, 1 receive
    int id = 1;//pay id of the button
    int buttonType = vigame::PayManager::getInstance()->GetButtonType(id);
    if (buttonType == 0)
    {
        cocos2d::log("PayManager the button is buy type");
    }
    else if (buttonType == 1)
    {
        cocos2d::log("PayManager the button is receive type");
    }
}

void Pay::btn5CallBack(Ref* pSender)
{
    //Default Pay
    vigame::PayManager::getInstance()->OrderPay(1001, "Custom data that you set yourself", [](vigame::PayStatus status, int payId, std::string userData) {
        std::string ret = "";
        switch (status)
        {
            case vigame::PayStatus::PaySuccess:
                ret = "PaySuccess";
                break;
            case vigame::PayStatus::PayFail:
                ret = "PayFail";
                break;
            case vigame::PayStatus::PayCancel:
                ret = "PayCancel";
                break;
            default:
                ret = "";
                break;
        }
        ret = ret + " " + userData;
        cocos2d::log("PayManager %s", ret.c_str());
    });
}

void Pay::btn6CallBack(Ref* pSender)
{
   // ali pay
    vigame::PayManager::getInstance()->OrderPayWithType(1001, 100, vigame::PayTypeDef::PAY_TYPE_AliPay, "Custom data that you set yourself", 
    [](vigame::PayStatus status, int payId, std::string userData) {
        std::string ret = "";
        switch (status)
        {
            case vigame::PayStatus::PaySuccess:
                ret = "PaySuccess";
                break;
            case vigame::PayStatus::PayFail:
                ret = "PayFail";
                break;
            case vigame::PayStatus::PayCancel:
                ret = "PayCancel";
                break;
            default:
                ret = "";
                break;
        }
        ret = ret + " " + userData;
        cocos2d::log("PayManager ali pay %s", ret.c_str());
    });
}

void Pay::btn7CallBack(Ref* pSender)
{
   // wechat pay
    vigame::PayManager::getInstance()->OrderPayWithType(1001, 100, vigame::PayTypeDef::PAY_TYPE_WXPay, "Custom data that you set yourself",
     [](vigame::PayStatus status, int payId, std::string userData) {
        std::string ret = "";
        switch (status)
        {
            case vigame::PayStatus::PaySuccess:
                ret = "PaySuccess";
                break;
            case vigame::PayStatus::PayFail:
                ret = "PayFail";
                break;
            case vigame::PayStatus::PayCancel:
                ret = "PayCancel";
                break;
            default:
                ret = "";
                break;
        }
        ret = ret + " " + userData;
        cocos2d::log("PayManager wechat pay %s", ret.c_str());
    });
}

void Pay::btn8CallBack(Ref* pSender)
{
    // open more game
    vigame::PayManager::getInstance()->OpenMoreGame();
}

void Pay::btn9CallBack(Ref* pSender)
{
    // get current market type
    int marketType = vigame::PayManager::getInstance()->GetMarketType();
    std::string result = "";
    switch (marketType)
    {
        case vigame::PayTypeDef::PAY_TYPE_Mi:
            result = "Mi";
            break;
        case vigame::PayTypeDef::PAY_TYPE_OPPO:
            result = "Oppo";
            break;
        case vigame::PayTypeDef::PAY_TYPE_Vivo:
            result = "Vivo";
            break;
        case vigame::PayTypeDef::PAY_TYPE_Huawei:
            result = "Huawei";
            break;
        default:
            result = "";
            cocos2d::log("PayManager market type %d", marketType);
            break;
    }
    if(result != "")
    {
        cocos2d::log("PayManager market type %s", result.c_str());
    }
    
}

void Pay::btn10CallBack(Ref* pSender)
{
    // current market whether support exit
    if (vigame::PayManager::getInstance()->IsSupportExit())
    {
        cocos2d::log("PayManager current market support Exit ");
    }
    else
    {
        cocos2d::log("PayManager current market don't support Exit ");
    }
}

void Pay::btn11CallBack(Ref* pSender)
{
    // Show Exit Panel
    // vigame::PayManager::getInstance()->ShowExitPanel();
}

void Pay::btn12CallBack(Ref* pSender)
{
    // open one app store eg: com.tencent.mobile qq
    vigame::PayManager::getInstance()->OpenMarket("com.tencent.mobileqq");
}

void Pay::btn13CallBack(Ref* pSender)
{
    // open app Appraise
    vigame::PayManager::getInstance()->OpenAppraise();
}
