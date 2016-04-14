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