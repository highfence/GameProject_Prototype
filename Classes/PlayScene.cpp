#include "pch.h"
#include "EndingScene.h"
#include "DeadScene.h"
#include "PlayScene.h"

Scene* PlayScene::createScene()
{
	auto scene = Scene::create();

	auto layer = PlayScene::create();
	scene->addChild(layer);

	return scene;
}

bool PlayScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	// 타이틀 설정
	auto title = Label::createWithTTF("Play Scene", "NotoSansCJKkr-Bold.otf", 34);
	title->setPosition(Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.75f));
	this->addChild(title);

	// 씬 네임 설정
	auto SceneName = Label::createWithTTF("PlayScene", "NotoSansCJKkr-Bold.otf", 15);
	SceneName->setAnchorPoint(Point(0, 1));
	SceneName->setPosition(Vec2(5, visibleSize.height));
	this->addChild(SceneName);

	// Close 버튼 설정
	auto closeButton = MenuItemImage::create("Close_ButtonOff.png", "Close_ButtonOn.png", CC_CALLBACK_1(PlayScene::MenuCloseCallback, this));
	closeButton->setAnchorPoint(Point(1, 0));
	closeButton->setPosition(Vec2(visibleSize.width - 5, 5));
	auto closeMenu = Menu::create(closeButton, NULL);
	closeMenu->setPosition(Vec2::ZERO);
	this->addChild(closeMenu);

	// 메뉴 아이템 설정.
	auto itemDead = MenuItemFont::create("if Player Dead", CC_CALLBACK_1(PlayScene::IfPlayerDead, this));
	auto itemClear = MenuItemFont::create("if Player Clear Stage", CC_CALLBACK_1(PlayScene::IfStageClear, this));
	auto itemCritical = MenuItemFont::create("Effect_Critical Hit", CC_CALLBACK_1(PlayScene::EffectCritical, this));
	auto itemDefence = MenuItemFont::create("Effect_Defence", CC_CALLBACK_1(PlayScene::EffectDefence, this));
	auto itemMiss = MenuItemFont::create("Effect_Miss", CC_CALLBACK_1(PlayScene::EffectMiss, this));

	auto Menu = Menu::create(itemDead, itemClear, itemCritical, itemDefence, itemMiss, NULL);
	Menu->alignItemsVertically();
	this->addChild(Menu);

	return true;
}

void PlayScene::MenuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}

void PlayScene::IfPlayerDead(Ref* pSender)
{
	Director::getInstance()->replaceScene(DeadScene::createScene());
}

void PlayScene::IfStageClear(Ref* pSender)
{
	Director::getInstance()->replaceScene(EndingScene::createScene());
}

void PlayScene::EffectCritical(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("Critical.wav");
}

void PlayScene::EffectDefence(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("Defence.wav");
}

void PlayScene::EffectMiss(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("Miss.wav");
}