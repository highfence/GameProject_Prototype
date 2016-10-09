#pragma once


class TitleScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;
    
    // a selector callback
    void MenuCloseCallback(cocos2d::Ref* pSender);
	void MenuCallback(cocos2d::Ref* pSender);
	void ChangeToPlayScene(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(TitleScene);
};
