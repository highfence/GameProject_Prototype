#pragma once


class AboutScene : public Layer
{
public:

	static Scene* createScene();

	virtual bool init() override;
	
	void MenuCloseCallback(Ref*);
	void ReturnToTitle(Ref*);

	CREATE_FUNC(AboutScene);

};