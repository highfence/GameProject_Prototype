#pragma once

#include "cocos2d.h"

class TitleScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void MenuCloseCallback(cocos2d::Ref* pSender);
	void MenuCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(TitleScene);
};
