#include "Base.h"
#include "Home.h"
#include "SimpleAudioEngine.h"
#include "wb/wb.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h" 

USING_NS_CC;
using namespace cocos2d::ui;

// on "init" you need to initialize your instance
bool Base::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto base = CSLoader::createNode("Base.csb");
    base->setPosition(Vec2(0, (visibleSize.height - 1136)/2));
    this->addChild(base);

    Button* backBtn = static_cast<Button*>(base->getChildByName("Back")); 
    backBtn->addClickEventListener(CC_CALLBACK_1(Base::backBtnCallBack,this));

    Button* btn1 = static_cast<Button*>(base->getChildByName("Button_1")); 
    btn1->addClickEventListener(CC_CALLBACK_1(Base::btn1CallBack,this));

    Button* btn2 = static_cast<Button*>(base->getChildByName("Button_2")); 
    btn2->addClickEventListener(CC_CALLBACK_1(Base::btn2CallBack,this));

    Button* btn3 = static_cast<Button*>(base->getChildByName("Button_3")); 
    btn3->addClickEventListener(CC_CALLBACK_1(Base::btn3CallBack,this));

    Button* btn4 = static_cast<Button*>(base->getChildByName("Button_4")); 
    btn4->addClickEventListener(CC_CALLBACK_1(Base::btn4CallBack,this));

    auto view = base->getChildByName("ListView");

    return true;
}

void Base::backBtnCallBack(Ref* pSender)
{
    auto home = Home::create();
	Director::getInstance()->getRunningScene()->addChild(home);
	this->removeFromParent();
}

void Base::btn1CallBack(Ref* pSender)
{
    cocos2d::log("Base 签名验证暂不支持");
}

void Base::btn2CallBack(Ref* pSender)
{
    bool ret = vigame::CoreManager::getInstance()->GetAuditSwitch();
    if (ret)
    {
        cocos2d::log("not audit");
    }
    else
    {
        cocos2d::log("auditting");
    }
}

void Base::btn3CallBack(Ref* pSender)
{
    std::string str = "appname: " + vigame::CoreManager::getInstance()->GetAppName();
    str += "\nchannel: " + vigame::CoreManager::getInstance()->GetChannel();
    str += "\nprjid: " + vigame::CoreManager::getInstance()->GetPrjid();
    str += "\nappid: " + vigame::CoreManager::getInstance()->GetAppid();
    str += "\nlsn: " + vigame::CoreManager::getInstance()->GetLsn();
    str += "\nuuid: " + vigame::CoreManager::getInstance()->GetUuid();
    str += "\nimsi: " + vigame::CoreManager::getInstance()->GetImsi();
    str += "\nimei: " + vigame::CoreManager::getInstance()->GetImei();
    str += "\noaid: " + vigame::CoreManager::getInstance()->GetOaid();
    str += "\nandroidid: " + vigame::CoreManager::getInstance()->GetAndroidId();
    str += "\nappkey: " + vigame::CoreManager::getInstance()->GetAppkey();
    str += "\npackagename: " + vigame::CoreManager::getInstance()->GetPackageName();
    str += "\nvername: " + vigame::CoreManager::getInstance()->GetVerName();
    str += "\ndnid: " + vigame::CoreManager::getInstance()->GetDnid();
    str += "\nopengl: " + vigame::CoreManager::getInstance()->GetOpenGLVersion();
    str += "\nupdateinfo: " + vigame::CoreManager::getInstance()->GetUpdateInfo();
    str += "\nbuychannel: " + vigame::CoreManager::getInstance()->GetBuyChannel();
    str += "\nbuyuserid: " + vigame::CoreManager::getInstance()->GetBuyUserId();

    cocos2d::log("Base \n*** 应用参数 ***\n%s", str.c_str());
    unsigned long time =  vigame::CoreManager::getInstance()->GetElapsedRealtime();
    cocos2d::log("Base time = %lu", time);

    vigame::CoreManager::getInstance()->UseCDKey("1001", [](vigame::CDKeyState status, std::string price, std::string msg) {
        switch (status)
        {
        // UnUse = -1, // -1 异常，未使用
        // UnExist = 0, // 0兑换码不存在
        // Success = 1, // 1成功
        // Repeat = 2, // 2不能重复使用
        // ParamError = 3, // 3参数错误
        // NetError = 4, // 4网络错误
        case vigame::CDKeyState::UnUse:
            cocos2d::log("Base -1 异常，未使用");
            break;
        case vigame::CDKeyState::UnExist:
            cocos2d::log("Base 0兑换码不存在");
            break;
        case vigame::CDKeyState::Success:
            cocos2d::log("Base 1成功");
            break;
        case vigame::CDKeyState::Repeat:
            cocos2d::log("Base 2不能重复使用");
            break;
        case vigame::CDKeyState::ParamError:
            cocos2d::log("Base 3参数错误");
            break;
        case vigame::CDKeyState::NetError:
            cocos2d::log("Base 4网络错误");
            break;
        default:
            cocos2d::log("Base 未知错误");
            break;
        }
    });
}

void Base::btn4CallBack(Ref* pSender)
{
    cocos2d::log("Base 暂不支持");
}
