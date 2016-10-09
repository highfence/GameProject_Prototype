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

	return true;
}