#pragma once


class PlayScene : public Layer
{
public :

	static cocos2d::Scene* createScene();

	virtual bool init() override;

	void MenuCloseCallback(Ref*);
	void IfPlayerDead(Ref*);
	void IfStageClear(Ref*);

	void EffectCritical(Ref*);
	void EffectDefence(Ref*);
	void EffectMiss(Ref*);

	CREATE_FUNC(PlayScene);
	
};