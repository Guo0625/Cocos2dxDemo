#include "Social.h"
#include "Home.h"
#include "SimpleAudioEngine.h"
#include "wb/wb.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h" 

USING_NS_CC;
using namespace cocos2d::ui;

// on "init" you need to initialize your instance
bool Social::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto pay = CSLoader::createNode("Social.csb");
    pay->setPosition(Vec2(0, (visibleSize.height - 1136)/2));
    this->addChild(pay);

    Button* backBtn = static_cast<Button*>(pay->getChildByName("Back")); 
    backBtn->addClickEventListener(CC_CALLBACK_1(Social::backBtnCallBack,this));

    auto view = pay->getChildByName("ListView");

    Button* btn1 = static_cast<Button*>(view->getChildByName("Button_1")); 
    btn1->addClickEventListener(CC_CALLBACK_1(Social::btn1CallBack,this));

    Button* btn2 = static_cast<Button*>(view->getChildByName("Button_2")); 
    btn2->addClickEventListener(CC_CALLBACK_1(Social::btn2CallBack,this));

    Button* btn3 = static_cast<Button*>(view->getChildByName("Button_3")); 
    btn3->addClickEventListener(CC_CALLBACK_1(Social::btn3CallBack,this));

    Button* btn4 = static_cast<Button*>(view->getChildByName("Button_4")); 
    btn4->addClickEventListener(CC_CALLBACK_1(Social::btn4CallBack,this));

    return true;
}

void Social::backBtnCallBack(Ref* pSender)
{
    auto home = Home::create();
	Director::getInstance()->getRunningScene()->addChild(home);
	this->removeFromParent();
}

void Social::btn1CallBack(Ref* pSender)
{
    vigame::SocialManager::getInstance()->Login(vigame::LoginType::TYPE_WX, [](bool ret){
        if (ret)
        {
            cocos2d::log("Social 登录成功");
        }
        else
        {
            cocos2d::log("Social 登录失败");
        }
        
    });
}

void Social::btn2CallBack(Ref* pSender)
{
    vigame::SocialManager::getInstance()->GetUserInfo(vigame::LoginType::TYPE_WX, [](bool ret, std::string param) {
        if (ret)
        {
            cocos2d::log("Social 获取成功 %s", param.c_str());
        }
        else
        {
            cocos2d::log("Social 获取失败 %s", param.c_str());
        }
    });
}

void Social::btn3CallBack(Ref* pSender)
{
    cocos2d::log("Social 暂不支持");
}

void Social::btn4CallBack(Ref* pSender)
{
    cocos2d::log("Social 暂不支持");
}
