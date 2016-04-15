//
//  WelcomeScene.hpp
//  Earlybird
//
//  Created by zhe on 16/4/13.
//
//

#ifndef WelcomeScene_hpp
#define WelcomeScene_hpp

#include "cocos2d.h"
#include "BackgroundLayer.h"
#include "AtlasLoader.h"
#include "WelcomeLayer.h"

using namespace cocos2d;

class WelcomeScene:public Scene{
public:
    WelcomeScene();
    ~WelcomeScene();
    virtual bool init();
    CREATE_FUNC(WelcomeScene);
};

#endif /* WelcomeScene_hpp */
