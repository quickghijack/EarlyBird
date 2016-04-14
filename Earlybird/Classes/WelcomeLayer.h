//
//  WelcomeLayer.hpp
//  Earlybird
//
//  Created by zhe on 16/4/14.
//
//

#ifndef WelcomeLayer_hpp
#define WelcomeLayer_hpp

#include "cocos2d.h"
#include "AtlasLoader.h"
#include "GameScene.h"
#include "time.h"
#include "SimpleAudioEngine.h"
#include "BirdSprite.h"

using namespace cocos2d;
using namespace std;

class WelcomeLayer:public Layer{
public:
    WelcomeLayer();
    ~WelcomeLayer();
    virtual bool init();
    CREATE_FUNC(WelcomeLayer);
private:
    void menuStartCallback(Ref* sender);
    void scrollLand(float dt);
    Sprite* land1;
    Sprite* land2;
    BirdSprite* bird;
};




#endif /* WelcomeLayer_hpp */
