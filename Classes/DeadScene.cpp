#include "pch.h"
#include "TitleScene.h"
#include "DeadScene.h"

Scene* DeadScene::createScene()
{
	auto scene = Scene::create();

	auto layer = DeadScene::create();
	scene->addChild(layer);

	return scene;
}


bool DeadScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	// 타이틀 설정
	auto title = Label::createWithTTF("Player Dead!", "NotoSansCJKkr-Bold.otf", 34);
	title->setPosition(Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.75f));
	this->addChild(title);

	// 씬 네임 설정
	auto SceneName = Label::createWithTTF("DeadScene", "NotoSansCJKkr-Bold.otf", 15);
	SceneName->setAnchorPoint(Point(0, 1));
	SceneName->setPosition(Vec2(5, visibleSize.height));
	this->addChild(SceneName);

	// Close 버튼 설정
	auto closeButton = MenuItemImage::create("Close_ButtonOff.png", "Close_ButtonOn.png", CC_CALLBACK_1(DeadScene::MenuCloseCallback, this));
	closeButton->setAnchorPoint(Point(1, 0));
	closeButton->setPosition(Vec2(visibleSize.width - 5, 5));
	auto closeMenu = Menu::create(closeButton, NULL);
	closeMenu->setPosition(Vec2::ZERO);
	this->addChild(closeMenu);

	// 메뉴 아이템 설정.
	auto itemBack = MenuItemFont::create("Back to Title", CC_CALLBACK_1(DeadScene::ReturnToTitle, this));

	auto Menu = Menu::create(itemBack, NULL);
	Menu->alignItemsVertically();
	this->addChild(Menu);

	return true;
}

void DeadScene::MenuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}

void DeadScene::ReturnToTitle(Ref *pSender)
{
	Director::getInstance()->replaceScene(TitleScene::createScene());
}
