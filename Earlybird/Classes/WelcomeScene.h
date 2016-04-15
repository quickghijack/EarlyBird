//
//  WelcomeScene.hpp
//  Earlybird
//
//  Created by zhe on 16/4/13.
//
//
#pragma once
#ifndef WelcomeScene_hpp
#define WelcomeScene_hpp

#include "cocos2d.h"
#include "BackgroundLayer.h"
#include "AtlasLoader.h"
#include "WelcomeLayer.h"

using namespace cocos2d;
using namespace std;

class WelcomeScene:public Scene{
public:
    WelcomeScene();
    ~WelcomeScene();
    bool virtual init();
    CREATE_FUNC(WelcomeScene);
};

#endif /* WelcomeScene_hpp */
