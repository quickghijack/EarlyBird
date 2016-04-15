//
//  BirdSprite.hpp
//  Earlybird
//
//  Created by zhe on 16/4/14.
//
//

#ifndef BirdSprite_hpp
#define BirdSprite_hpp

#include "cocos2d.h"
#include "AtlasLoader.h"
#include "time.h"

using namespace cocos2d;

typedef enum{
    ACTION_STATE_IDEL,
    ACTION_STATE_FLY,
    ACTION_STATE_DIE
}ActionState;

class BirdSprite:public Sprite{
public:
    BirdSprite();
    ~BirdSprite();
    static BirdSprite* getInstance();
    virtual bool init();
    bool creatBird();
    void idle();
    void fly();
    void die();
    
protected:
    static cocos2d::Animation* createAnimation(const char *fmt,int count,float fps);
    void createBirdByRandom();

private:
    static BirdSprite* shareBirdSprite;
    bool changeState(ActionState state);
    Action* idleAction;
    Action* swingAction;
    Action* dieAction;
    ActionState currentStatus;
    string birdName;
    string birdNameFormat;
    unsigned int isFirstTime;
    
    
};

#endif /* BirdSprite_hpp */
