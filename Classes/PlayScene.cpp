#include "pch.h"
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

	return true;
}