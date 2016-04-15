//
//  WelcomeLayer.cpp
//  Earlybird
//
//  Created by zhe on 16/4/14.
//
//

#include "WelcomeLayer.h"

WelcomeLayer::WelcomeLayer(){};
WelcomeLayer::~WelcomeLayer(){};

bool WelcomeLayer::init(){
    if(!Layer::init())
    {    return false;}
    
    Size visableSize = Director::getInstance()->getVisibleSize();
    Point orgin=Director::getInstance()->getVisibleOrigin();
    
    time_t t=time(NULL);
    tm* lt=localtime(&t);
    int hour=lt->tm_hour;
    Sprite* background;
    if (hour>6&&hour<18){
        background=Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_day"));
    }
    else{
        background=Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_night"));
    }
    background->setAnchorPoint(Point::ZERO);
    background->setPosition(Point::ZERO);
    this->addChild(background);
    
    Sprite* title=Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("title"));
    title->setPosition(Point(orgin.x+visableSize.width/2,orgin.y+(visableSize.height*5)/7));
    
    
    
    
}

