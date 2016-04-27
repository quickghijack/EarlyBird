//
//  GameScene.hpp
//  Earlybird
//
//  Created by zhe on 16/4/14.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#pragma once
#include "cocos2d.h"
#include "BackgroundLayer.h"
#include "GameLayer.h";
#include "StatusLayer.h"
#include "OptionLayer.h"

using namespace std;
using namespace cocos2d;

class GameScene:public Scene{
public:
    GameScene();
    ~GameScene();
    virtual bool init();
    
    void restart();
    
    CREATE_FUNC(GameScene);
    
};

#endif /* GameScene_hpp */
