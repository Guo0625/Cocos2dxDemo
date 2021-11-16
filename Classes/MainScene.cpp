#include "Home.h"
#include "wb/wb.h"
#include "MainScene.h"
#include "ui/CocosGUI.h" 
#include "SimpleAudioEngine.h"
#include "editor-support/cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace cocos2d::ui;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in MainScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto home = Home::create();
    this->addChild(home);

    return true;
}
