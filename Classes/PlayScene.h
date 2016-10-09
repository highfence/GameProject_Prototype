#pragma once


class PlayScene : public Layer
{
public :

	static cocos2d::Scene* createScene();

	virtual bool init() override;
	CREATE_FUNC(PlayScene);
	
};