#include "TJ.h"
#include "Home.h"
#include "SimpleAudioEngine.h"
#include "wb/wb.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h" 

USING_NS_CC;
using namespace cocos2d::ui;

// on "init" you need to initialize your instance
bool TJ::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto pay = CSLoader::createNode("TJ.csb");
    pay->setPosition(Vec2(0, (visibleSize.height - 1136)/2));
    this->addChild(pay);

    Button* backBtn = static_cast<Button*>(pay->getChildByName("Back")); 
    backBtn->addClickEventListener(CC_CALLBACK_1(TJ::backBtnCallBack,this));

    auto view = pay->getChildByName("ListView_1");
    auto panel1 = view->getChildByName("Panel_1");

    Button* btn1 = static_cast<Button*>(panel1->getChildByName("Button_1")); 
    btn1->addClickEventListener(CC_CALLBACK_1(TJ::btn1CallBack,this));

    Button* btn2 = static_cast<Button*>(panel1->getChildByName("Button_2")); 
    btn2->addClickEventListener(CC_CALLBACK_1(TJ::btn2CallBack,this));

    auto panel2 = view->getChildByName("Panel_2");
    Button* btn3 = static_cast<Button*>(panel2->getChildByName("Button_1")); 
    btn3->addClickEventListener(CC_CALLBACK_1(TJ::btn3CallBack,this));

    Button* btn4 = static_cast<Button*>(panel2->getChildByName("Button_2")); 
    btn4->addClickEventListener(CC_CALLBACK_1(TJ::btn4CallBack,this));

    auto view2 = pay->getChildByName("ListView_2");
    auto panel3 = view2->getChildByName("Panel_1");
    Button* btn5 = static_cast<Button*>(panel3->getChildByName("Button_1")); 
    btn5->addClickEventListener(CC_CALLBACK_1(TJ::btn5CallBack,this));

    Button* btn6 = static_cast<Button*>(panel3->getChildByName("Button_2")); 
    btn6->addClickEventListener(CC_CALLBACK_1(TJ::btn6CallBack,this));

    Button* btn7 = static_cast<Button*>(panel3->getChildByName("Button_3")); 
    btn7->addClickEventListener(CC_CALLBACK_1(TJ::btn7CallBack,this));

    auto view3 = pay->getChildByName("ListView_3");
    auto panel4 = view3->getChildByName("Panel_1");
    Button* btn8 = static_cast<Button*>(panel4->getChildByName("Button_1")); 
    btn8->addClickEventListener(CC_CALLBACK_1(TJ::btn8CallBack,this));

    Button* btn9 = static_cast<Button*>(panel4->getChildByName("Button_2")); 
    btn9->addClickEventListener(CC_CALLBACK_1(TJ::btn9CallBack,this));

    return true;
}

void TJ::backBtnCallBack(Ref* pSender)
{
    auto home = Home::create();
	Director::getInstance()->getRunningScene()->addChild(home);
	this->removeFromParent();
}

void TJ::btn1CallBack(Ref* pSender)
{
    vigame::TjManager::getInstance()->TJCustomEvent("app_home_show");
}

void TJ::btn2CallBack(Ref* pSender)
{
    vigame::TjManager::getInstance()->TJCustomEvent("ad_video_ready", "video");
}

void TJ::btn3CallBack(Ref* pSender)
{
    std::unordered_map<std::string, std::string> ps {
        { "level", "10" },
        { "role", "1"},
        { "revive", "1"},
        { "pass", "1"},
        { "survivor", "1"}
    };
    vigame::TjManager::getInstance()->TJCustomEvent("self_inGame", ps);
}

void TJ::btn4CallBack(Ref* pSender)
{
    std::unordered_map<std::string, std::string> ps {
        { "hat", "hat10"}
    };
    vigame::TjManager::getInstance()->TJCustomEvent("self_skin", ps);
}

void TJ::btn5CallBack(Ref* pSender)
{
    vigame::TjManager::getInstance()->StartLevel("1");
}

void TJ::btn6CallBack(Ref* pSender)
{
    vigame::TjManager::getInstance()->FinishLevel("1", "10");
}

void TJ::btn7CallBack(Ref* pSender)
{
    vigame::TjManager::getInstance()->FailLevel("2", "5");
}

void TJ::btn8CallBack(Ref* pSender)
{
    vigame::TjManager::getInstance()->TJPay(10, 100, -1);
}

void TJ::btn9CallBack(Ref* pSender)
{
    vigame::TjManager::getInstance()->TJPayAndBuy(10, "item", 10, 100, -1);
}
