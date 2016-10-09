#include "pch.h"
#include "AboutScene.h"

Scene* AboutScene::createScene()
{
	auto scene = Scene::create();

	auto layer = AboutScene::create();
	scene->addChild(layer);

	return scene;
}

bool AboutScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	auto visibleSize = Director::getInstance()->getVisibleSize();

	// 타이틀 설정.
	auto title = Label::createWithTTF(u8"어바웃 씬", "NotoSansCJKkr-Bold.otf", 34);
	title->setPosition(Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.75f));
	this->addChild(title);

	// 씬 네임 설정.
	auto SceneName = Label::createWithTTF("AboutScene", "NotoSansCJKkr-Bold.otf", 15);
	SceneName->setAnchorPoint(Point(0, 1));
	SceneName->setPosition(Vec2(5, visibleSize.height));
	this->addChild(SceneName);

	// Close 버튼 설정.	
	auto closeButton = MenuItemImage::create("Close_ButtonOff.png", "Close_ButtonOn.png", CC_CALLBACK_1(AboutScene::MenuCloseCallback, this));
	closeButton->setAnchorPoint(Point(1, 0));
	closeButton->setPosition(Vec2(visibleSize.width - 5, 5));
	auto closeMenu = Menu::create(closeButton, NULL);
	closeMenu->setPosition(Vec2::ZERO);
	this->addChild(closeMenu);

	// Back 버튼 설정.
	auto itemBack = MenuItemFont::create("Back to Title", CC_CALLBACK_1(AboutScene::ReturnToTitle, this));
	auto Menu = Menu::create(itemBack, NULL);
	Menu->alignItemsVertically();
	this->addChild(Menu);

	return true;

	return true;
}

void AboutScene::MenuCloseCallback(Ref *pSender)
{
	Director::getInstance()->end();
}

void AboutScene::ReturnToTitle(Ref *pSender)
{
	Director::getInstance()->popScene();
}
