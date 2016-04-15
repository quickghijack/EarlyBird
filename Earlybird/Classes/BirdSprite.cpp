//
//  BirdSprite.cpp
//  Earlybird
//
//  Created by zhe on 16/4/14.
//
//

#include "BirdSprite.h"

BirdSprite::BirdSprite(){};
BirdSprite::~BirdSprite(){};

BirdSprite* BirdSprite::shareBirdSprite=nullptr;

BirdSprite* BirdSprite::getInstance(){
    if(shareBirdSprite==NULL){
        shareBirdSprite=new BirdSprite::BirdSprite();
        if(!shareBirdSprite->init()){
            CC_SAFE_DELETE(shareBirdSprite);
            shareBirdSprite=NULL;
            CCLOG("ERROR:could not init ShareBirdSprite");
        }
    }
    return shareBirdSprite;
}

bool BirdSprite::init(){
    if(!initWithTexture(NULL, Rect::ZERO)){
        return false;
    }

    this->isFirstTime=3;
    return true;
}

bool BirdSprite::creatBird(){
    this->createBirdByRandom();
    
    
    if(Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName(this->birdName))){
        Animation* animation = this->createAnimation(this->birdNameFormat.c_str(), 3, 10);
        Animate* animate=Animate::create(animation);
        this->idleAction=RepeatForever::create(animate);
        
        ActionInterval* up=MoveBy::create(0.4f, Point(0,8));
        ActionInterval* upBack=up->reverse();
        this->swingAction=RepeatForever::create(Sequence::create(up,upBack, NULL));
        return true;
    }else{
        return false;
    }
}

Animation* BirdSprite::createAnimation(const char *fmt, int count, float fps){
    Animation* animation=Animation::create();
    animation->setDelayPerUnit(1/fps);
    for (int i=0; i<count; i++) {
        const char* fileName=String::createWithFormat(fmt,i)->getCString();
        SpriteFrame *frame=AtlasLoader::getInstance()->getSpriteFrameByName(fileName);
        animation->addSpriteFrame(frame);
    }
    return animation;
}

void BirdSprite::idle(){
    if(changeState(ACTION_STATE_FLY)){
        this->runAction(idleAction);
        this->runAction(swingAction);
    }
}

void BirdSprite::fly(){
    if(changeState(ACTION_STATE_IDEL)){
        this->stopAction(swingAction);
        this->getPhysicsBody()->setGravityEnable(true);
    }
}

void BirdSprite::die(){
    if(changeState(ACTION_STATE_DIE)){
        this->stopAllActions();
    }
    
}

bool BirdSprite::changeState(ActionState state){
    this->currentStatus = state;
    return true;
}

void BirdSprite::createBirdByRandom(){
//    if(this->isFirstTime & 1){
//        this->isFirstTime &= 2;
//    }else if(this->isFirstTime & 2){
//        this->isFirstTime &= 1;
//        return ;
//    }
    
    srand((unsigned) time(NULL));
    int type=((int)rand())%3;
    switch (type) {
        case 0:
            this->birdName="bird0_0";
            this->birdNameFormat="bird0_%d";
            break;
        case 1:
            this->birdName="bird1_0";
            this->birdNameFormat="bird1_%d";
            break;
        case 2:
            this->birdName="bird2_0";
            this->birdNameFormat="bird2_%d";
            break;
        default:
            this->birdName="bird2_0";
            this->birdNameFormat="bird2_%d";
            break;
    }
}


