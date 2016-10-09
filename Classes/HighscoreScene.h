#pragma once


class HighscoreScene : public Layer
{
public:

	static Scene* createScene();

	virtual bool init() override;

	void MenuCloseCallback(Ref*);
	void ReturnToTitle(Ref*);

	CREATE_FUNC(HighscoreScene);

};