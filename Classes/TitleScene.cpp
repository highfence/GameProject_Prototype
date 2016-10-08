#include "TitleScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* TitleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TitleScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TitleScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// 타이틀 설정
	auto title = Label::createWithTTF("Scene Management Prototype", "NotoSansCJKkr-Bold.otf", 34);
	title->setPosition(Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.75f));
	this->addChild(title);
	
	// 씬 네임 설정
	auto SceneName = Label::createWithTTF("TitleScene", "NotoSansCJKkr-Bold.otf", 15);
	SceneName->setAnchorPoint(Point(0, 1));
	SceneName->setPosition(Vec2(5, visibleSize.height));
	this->addChild(SceneName);

	// Close 버튼 설정.	
	auto closeButton = MenuItemImage::create("Close_ButtonOff.png", "Close_ButtonOn.png", CC_CALLBACK_1(TitleScene::MenuCloseCallback, this));
	closeButton->setAnchorPoint(Point(1, 0));
	closeButton->setPosition(Vec2(visibleSize.width - 5, 5));
	auto closeMenu = Menu::create(closeButton, NULL);
	closeMenu->setPosition(Vec2::ZERO);
	this->addChild(closeMenu);

	// Menu 설정.
	auto itemPlay = MenuItemFont::create("PlayScene", CC_CALLBACK_1(TitleScene::MenuCallback, this));
	auto itemHighScore = MenuItemFont::create("HighScore", CC_CALLBACK_1(TitleScene::MenuCallback, this));
	auto itemAbout = MenuItemFont::create("About this", CC_CALLBACK_1(TitleScene::MenuCallback, this));

	auto menu = Menu::create(itemPlay, itemHighScore, itemAbout, NULL);
	menu->alignItemsVertically();
	this->addChild(menu);

    return true;
}


void TitleScene::MenuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate  back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
}

void TitleScene::MenuCallback(Ref* pSender)
{
	CCLOG("menuCallback");
	auto item = (MenuItemFont*)pSender;
}