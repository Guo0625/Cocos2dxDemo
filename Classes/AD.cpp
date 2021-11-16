#include "AD.h"
#include "Home.h"
#include "SimpleAudioEngine.h"
#include "wb/wb.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h" 

USING_NS_CC;
using namespace cocos2d::ui;

AD::AD()
{
	status = 0;
	splashBtn = nullptr;
}

AD::~AD()
{

}

// on "init" you need to initialize your instance
bool AD::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto ad = CSLoader::createNode("Ad.csb");
    ad->setPosition(Vec2(0, (visibleSize.height - 1136)/2));
    this->addChild(ad);

    cocos2d::log("cocos2d OpenAd banner");
    vigame::ADManager::getInstance()->OpenAd("banner");

    Button* backBtn = static_cast<Button*>(ad->getChildByName("Back")); 
    backBtn->addClickEventListener(CC_CALLBACK_1(AD::backBtnCallBack,this));

	this->splashBtn = static_cast<Button*>(ad->getChildByName("Button_1"));
	Button* btn = static_cast<Button*>(this->splashBtn);
	btn->addClickEventListener(CC_CALLBACK_1(AD::splashBtnCallBack,this));

    this->bannerBtn = static_cast<Button*>(ad->getChildByName("Button_3")); 
    btn = static_cast<Button*>(this->bannerBtn);
    btn->addClickEventListener(CC_CALLBACK_1(AD::bannerBtnCallBack,this));

    Button* cbannerBtn = static_cast<Button*>(ad->getChildByName("Button_4")); 
    cbannerBtn->addClickEventListener(CC_CALLBACK_1(AD::cbannerBtnCallBack,this));

    this->pauseBtn = static_cast<Button*>(ad->getChildByName("Button_5")); 
    btn = static_cast<Button*>(this->pauseBtn);
    btn->addClickEventListener(CC_CALLBACK_1(AD::pauseBtnCallBack,this));

    this->exit_gameBtn = static_cast<Button*>(ad->getChildByName("Button_6")); 
    btn = static_cast<Button*>(this->exit_gameBtn);
    btn->addClickEventListener(CC_CALLBACK_1(AD::exit_gameBtnCallBack,this));

    this->home_mfzsBtn = static_cast<Button*>(ad->getChildByName("Button_7")); 
    btn = static_cast<Button*>(this->home_mfzsBtn);
    btn->addClickEventListener(CC_CALLBACK_1(AD::home_mfzsBtnCallBack,this));

    this->level_win_mfzsBtn = static_cast<Button*>(ad->getChildByName("Button_8")); 
    btn = static_cast<Button*>(this->level_win_mfzsBtn);
    btn->addClickEventListener(CC_CALLBACK_1(AD::level_win_mfzsBtnCallBack,this));

    this->schedule(CC_SCHEDULE_SELECTOR(AD::updateAdStaus), 1);

	updateAdStaus(0);
    return true;
}

void AD::backBtnCallBack(Ref* pSender)
{
    cocos2d::log("cocos2d close banner");
    vigame::ADManager::getInstance()->CloseAd("banner");
    auto home = Home::create();
	Director::getInstance()->getRunningScene()->addChild(home);
	this->removeFromParent();
}

void AD::splashBtnCallBack(Ref* pSender)
{
    vigame::ADManager::getInstance()->OpenAd("splash", [](bool ret, std::string param) {
        if(ret)
        {
            cocos2d::log("VideoCallBack Success = %s", param.c_str());
        } else {
            cocos2d::log("VideoCallBack Fail = %s", param.c_str());
        }
    });
}

void AD::bannerBtnCallBack(Ref* pSender)
{
    cocos2d::log("cocos2d open banner");
    vigame::ADManager::getInstance()->OpenAd("banner", [](bool ret, std::string param) {
        if(ret)
        {
            cocos2d::log("VideoCallBack banner Success = %s", param.c_str());
        } else {
            cocos2d::log("VideoCallBack banner Fail = %s", param.c_str());
        }
    });
}

void AD::cbannerBtnCallBack(Ref* pSender)
{
    cocos2d::log("cocos2d close banner");
    vigame::ADManager::getInstance()->CloseAd("banner");
}

void AD::pauseBtnCallBack(Ref* pSender)
{
    vigame::ADManager::getInstance()->OpenAd("pause", [](bool ret, std::string param) {
        if(ret)
        {
            cocos2d::log("VideoCallBack Success = %s", param.c_str());
        } else {
            cocos2d::log("VideoCallBack Fail = %s", param.c_str());
        }
    });
}

void AD::exit_gameBtnCallBack(Ref* pSender)
{
    vigame::ADManager::getInstance()->OpenAd("exit_game", [](bool ret, std::string param) {
        if(ret)
        {
            cocos2d::log("VideoCallBack Success = %s", param.c_str());
        } else {
            cocos2d::log("VideoCallBack Fail = %s", param.c_str());
        }
    });
}

void AD::home_mfzsBtnCallBack(Ref* pSender)
{
    vigame::ADManager::getInstance()->OpenAd("dj_mfzs", [](bool ret, std::string param) {
        if(ret)
        {
            cocos2d::log("VideoCallBack Success = %s", param.c_str());
        } else {
            cocos2d::log("VideoCallBack Fail = %s", param.c_str());
        }
    });
}

void AD::level_win_mfzsBtnCallBack(Ref* pSender)
{
    vigame::ADManager::getInstance()->OpenAd("level_win_mfzs", [](bool ret, std::string param) {
        if(ret)
        {
            cocos2d::log("VideoCallBack Success = %s", param.c_str());
        } else {
            cocos2d::log("VideoCallBack Fail = %s", param.c_str());
        }
    });
}

void AD::updateAdStaus(float dt)
{
    cocos2d::log("cocos2d updateAdStaus = %f", dt);
    std::string posName = "splash";
    Button* btn = static_cast<Button*>(this->splashBtn);
    if (vigame::ADManager::getInstance()->IsAdReady(posName))
    {
        btn->setEnabled(true);
    }
    else
    {
        btn->setEnabled(false);
    }

    posName = "banner";
    btn = static_cast<Button*>(this->bannerBtn);
    if (vigame::ADManager::getInstance()->IsAdReady(posName))
    {
        btn->setEnabled(true);
    }
    else
    {
        btn->setEnabled(false);
    }

    posName = "pause";
    btn = static_cast<Button*>(this->pauseBtn);
    if (vigame::ADManager::getInstance()->IsAdReady(posName))
    {
        btn->setEnabled(true);
    }
    else
    {
        btn->setEnabled(false);
    }

    posName = "exit_game";
    btn = static_cast<Button*>(this->exit_gameBtn);
    if (vigame::ADManager::getInstance()->IsAdReady(posName))
    {
        btn->setEnabled(true);
    }
    else
    {
        btn->setEnabled(false);
    }

    posName = "home_mfzs";
    btn = static_cast<Button*>(this->home_mfzsBtn);
    if (vigame::ADManager::getInstance()->IsAdReady(posName))
    {
        btn->setEnabled(true);
    }
    else
    {
        btn->setEnabled(false);
    }

    posName = "level_win_mfzs";
    btn = static_cast<Button*>(this->level_win_mfzsBtn);
    if (vigame::ADManager::getInstance()->IsAdReady(posName))
    {
        btn->setEnabled(true);
    }
    else
    {
        btn->setEnabled(false);
    }
}