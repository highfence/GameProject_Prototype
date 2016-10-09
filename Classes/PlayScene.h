#pragma once


class PlayScene : public Layer
{
public :

	static Scene* createScene();

	virtual bool init() override;
	CREATE_FUNC(PlayScene);
	
};