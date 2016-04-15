//
//  WelcomeScene.cpp
//  Earlybird
//
//  Created by 谢从 on 16/4/13.
//
//

#include "WelcomeScene.h"

WelcomeScene::WelcomeScene(){}
WelcomeScene::~WelcomeScene(){}

bool WelcomeScene::init(){
    bool bRet=false;
    do{
        CC_BREAK_IF(!Scene::init());
        auto _welcomeLayer= WelcomeLayer::create();
        CC_BREAK_IF(!_welcomeLayer);
        this->addChild(_welcomeLayer);
        bRet=true;
    }while(0);
    return bRet;
};
