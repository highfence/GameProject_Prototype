#pragma once


class StoryScene : public Layer
{
public:

	static Scene* createScene();

	virtual bool init() override;

	void MenuCloseCallback(Ref*);
	void ReturnToTitle(Ref*);
	void ChangeToPlayScene(Ref*);

	CREATE_FUNC(StoryScene);

};