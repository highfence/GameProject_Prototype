#include "pch.h"
#include "TitleScene.h"
#include "StoryScene.h"
#include "PlayScene.h"

Scene* StoryScene::createScene()
{
	auto scene = Scene::create();

	auto layer = StoryScene::create();
	scene->addChild(layer);

	return scene;
}

bool StoryScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();

	// BGM 재생.
	SimpleAudioEngine::getInstance()->playBackgroundMusic("justClimbing.mp3");

	// 타이틀 설정
	auto title = Label::createWithTTF("Story Scene", "NotoSansCJKkr-Bold.otf", 34);
	title->setPosition(Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.75f));
	this->addChild(title);

	// 씬 네임 설정
	auto SceneName = Label::createWithTTF("StoryScene", "NotoSansCJKkr-Bold.otf", 15);
	SceneName->setAnchorPoint(Point(0, 1));
	SceneName->setPosition(Vec2(5, visibleSize.height));
	this->addChild(SceneName);

	// Close 버튼 설정
	auto closeButton = MenuItemImage::create("Close_ButtonOff.png", "Close_ButtonOn.png", CC_CALLBACK_1(StoryScene::MenuCloseCallback, this));
	closeButton->setAnchorPoint(Point(1, 0));
	closeButton->setPosition(Vec2(visibleSize.width - 5, 5));
	auto closeMenu = Menu::create(closeButton, NULL);
	closeMenu->setPosition(Vec2::ZERO);
	this->addChild(closeMenu);

	// 메뉴 아이템 설정.
	auto itemPlay = MenuItemFont::create("Skip Story", CC_CALLBACK_1(StoryScene::ChangeToPlayScene, this));
	auto itemBack = MenuItemFont::create("Back to Title", CC_CALLBACK_1(StoryScene::ReturnToTitle, this));
	auto itemPause = MenuItemFont::create("BGM Pause", CC_CALLBACK_1(StoryScene::StopBGM, this));
	auto itemResume = MenuItemFont::create("BGM Replay", CC_CALLBACK_1(StoryScene::ReplayBGM, this));

	auto Menu = Menu::create(itemPlay, itemBack, itemPause, itemResume, NULL);
	Menu->alignItemsVertically();
	this->addChild(Menu);


	return true;
}

void StoryScene::MenuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}

void StoryScene::ChangeToPlayScene(Ref* pSender)
{
	Director::getInstance()->replaceScene(PlayScene::createScene());
}

void StoryScene::ReturnToTitle(Ref* pSener)
{
	Director::getInstance()->replaceScene(TitleScene::createScene());
}


void StoryScene::StopBGM(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void StoryScene::ReplayBGM(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
