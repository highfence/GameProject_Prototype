#include "pch.h"
#include "HighscoreScene.h"

Scene* HighscoreScene::createScene()
{
	auto scene = Scene::create();

	auto layer = HighscoreScene::create();
	scene->addChild(layer);

	return scene;
}

bool HighscoreScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	// Ÿ��Ʋ ����.
	auto title = Label::createWithTTF(u8"���̽��ھ� ��", "NotoSansCJKkr-Bold.otf", 34);
	title->setPosition(Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.75f));
	addChild(title);

	// �� ���� ����.
	auto SceneName = Label::createWithTTF("HighscoreScene", "NotoSansCJKkr-Bold.otf", 15);
	SceneName->setAnchorPoint(Point(0, 1));
	SceneName->setPosition(Vec2(5, visibleSize.height));
	addChild(SceneName);

	// Close ��ư ����.	
	auto closeButton = MenuItemImage::create("Close_ButtonOff.png", "Close_ButtonOn.png", CC_CALLBACK_1(HighscoreScene::MenuCloseCallback, this));
	closeButton->setAnchorPoint(Point(1, 0));
	closeButton->setPosition(Vec2(visibleSize.width - 5, 5));
	auto closeMenu = Menu::create(closeButton, NULL);
	closeMenu->setPosition(Vec2::ZERO);
	addChild(closeMenu);

	// Back ��ư ����.
	auto itemBack = MenuItemFont::create("Back to Title", CC_CALLBACK_1(HighscoreScene::ReturnToTitle, this));
	auto Menu = Menu::create(itemBack, NULL);
	Menu->alignItemsVertically();
	addChild(Menu);

	return true;
}

void HighscoreScene::MenuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}

void HighscoreScene::ReturnToTitle(Ref* pSender)
{
	Director::getInstance()->popScene();
}