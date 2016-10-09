#pragma once


class TitleScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;
    
    // a selector callback
    void MenuCloseCallback(Ref*);
	void ChangeToStoryScene(Ref*);
	void ChangeToHighscoreScene(Ref*);
	void ChangeToAboutScene(Ref*);

    // implement the "static create()" method manually
    CREATE_FUNC(TitleScene);
};
