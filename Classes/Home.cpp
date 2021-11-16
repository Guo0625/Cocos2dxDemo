#include "Home.h"
#include "SimpleAudioEngine.h"
#include "wb/wb.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h" 
#include "AD.h"
#include "Pay.h"
#include "TJ.h"

USING_NS_CC;
using namespace cocos2d::ui;

// on "init" you need to initialize your instance
bool Home::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto home = CSLoader::createNode("Home.csb");
    home->setPosition(Vec2(0, (visibleSize.height - 1136)/2));
    this->addChild(home);
    auto panel = home->getChildByName("ListView");
    Button* backBtn = static_cast<Button*>(home->getChildByName("Back")); 
    backBtn->addClickEventListener(CC_CALLBACK_1(Home::buttonCallBack,this));
    // ad Button
    Button* adBtn = static_cast<Button*>(panel->getChildByName("Button_2")); 
    adBtn->addClickEventListener(CC_CALLBACK_1(Home::adButtonCallBack,this));
    // pay Button
    Button* payBtn = static_cast<Button*>(panel->getChildByName("Button_3")); 
    payBtn->addClickEventListener(CC_CALLBACK_1(Home::payButtonCallBack,this));
    // tj Button
    Button* tjBtn = static_cast<Button*>(panel->getChildByName("Button_4")); 
    tjBtn->addClickEventListener(CC_CALLBACK_1(Home::tjButtonCallBack,this));

    return true;
}

void Home::adButtonCallBack(Ref* pSender) {
    // open ad Layer
    cocos2d::log("open ad Layer");
    auto ad = AD::create();
	Director::getInstance()->getRunningScene()->addChild(ad);
	this->removeFromParent();
}

void Home::payButtonCallBack(Ref* pSender) {
    cocos2d::log("open pay Layer");
    auto pay = Pay::create();
	Director::getInstance()->getRunningScene()->addChild(pay);
	this->removeFromParent();
}

void Home::tjButtonCallBack(Ref* pSender) {
    cocos2d::log("open ty Layer");
    auto tj = TJ::create();
	Director::getInstance()->getRunningScene()->addChild(tj);
	this->removeFromParent();
}

void Home::buttonCallBack(Ref* pSender) {

}
