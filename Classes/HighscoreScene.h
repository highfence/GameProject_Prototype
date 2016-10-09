#pragma once


class HighscoreScene : public Layer
{
public:

	static Scene* createScene();

	virtual bool init() override;
	CREATE_FUNC(HighscoreScene);

};