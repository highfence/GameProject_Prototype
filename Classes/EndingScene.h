#pragma once


class EndingScene : public Layer
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init() override;

	void MenuCloseCallback(Ref*);
	void ReturnToTitle(Ref*);
	CREATE_FUNC(EndingScene);

};