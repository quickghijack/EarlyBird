//
//  GameLayer.hpp
//  Earlybird
//
//  Created by zhe on 16/4/17.
//
//
#pragma once
#ifndef GameLayer_hpp
#define GameLayer_hpp

#include "cocos2d.h"
#include "UserRecord.h"
#include "OptionLayer.h"
#include "BirdSprite.h"
#include "BackgroundLayer.h"
#include "AtlasLoader.h"
#include "SimpleAudioEngine.h"
#include <cstdlib>

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

#define min(X,Y) ((X)<(Y)?(X):(Y))
#define max(X,Y) ((X)>(Y)?(X):(Y))

const int UP_PIP=21;
const int DOWN_PIP=12;
const int PIP_PASS = 30;
const int PIP_NEW=31;
const int PIP_INTERVAL = 180;

const int BIRD_RADIUS = 15;
const int PIP_HEIGHT = 320;
const int PIP_WIDTH=52;
const int PIP_SHIFT_SPEED=80.0f;
const int PIP_DISTANCE=100;
const int PIP_COUNT=2;
const int WAIT_DISTANCE=100;

typedef enum _game_status{
    GAME_STATUS_READY=1,
    GAME_STATUS_START,
    GAME_STATUS_OVER
}GameStatus;

typedef enum : uint8_t {
    ColliderTypeBird        = 0x1,
    ColliderTypeLand        = 0x1<<1,
    ColliderTypePip         = 0x1<<2
} ColliderType;

class StatusDelegate{
public:
    
    ~StatusDelegate(){};
    StatusDelegate(){};
    virtual void onGameStart(void)=0;
    virtual void onGamePlaying(int score)=0;
    virtual void onGameEnd(int curSorce,int bestSorce)=0;
    
};

class GameLayer:public Layer,public OptionDelegate{
public:
    GameLayer();
    ~GameLayer();
    virtual bool init();
    CREATE_FUNC(GameLayer);
    
    CC_SYNTHESIZE(StatusDelegate*, delegator, Delegator);
    //override in optiondelegate
    void onTouch();
    
    void setPhyWorld(PhysicsWorld* world){this->world = world;}
    void update(float delta);
private:
    void rotateBird();
    
    void createPips();
    
    int getRandomHeight();
    
    void checkHit();
    //由于birdSprite是单例类所以重新开始的时候必须先从前一个layer里删除才能添加到新的layer
    void birdSpriteFallOut();
    void birdSpriteRemove();
    
    PhysicsWorld* world;
    
    GameStatus gameStatus;
    
    int score;
    
    BirdSprite* bird;
    
    Node* groundNode;
    
    vector<Node*> pips;
    
    Sprite *landSprite1,*landSprite2;
    
    SEL_SCHEDULE shiftLand;
    
    void scrollLand(float dt);
    
    bool onContactBegin(PhysicsContact &contact);
    
    void gameOver();
    
};


#endif /* GameLayer_hpp */
