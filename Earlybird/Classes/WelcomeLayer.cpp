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
    
    Size visiableSize = Director::getInstance()->getVisibleSize();
    Point origin=Director::getInstance()->getVisibleOrigin();
    
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
    title->setPosition(Point(origin.x+visiableSize.width/2,origin.y+(visiableSize.height*5)/7));
    
    Sprite* startButton=Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_play"));
    Sprite* startActiveButton=Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_play"));
    startActiveButton->setPositionY(5);
    auto menuItem=MenuItemSprite::create(startButton, startActiveButton, CC_CALLBACK_1(WelcomeLayer::menuStartCallback, this));
    menuItem->setPosition(Point(origin.x + visiableSize.width/2 ,origin.y + visiableSize.height*2/5));
    
    auto menu=Menu::create(menuItem, NULL);
    menu->setPosition(Point(origin.x,origin.y));
    this->addChild(menu,1);
    
    this->bird=BirdSprite::getInstance();
    this->bird->creatBird();
    this->bird->setTag(BIRD_SPRITE_TAG);
    this->bird->setPosition(Point(origin.x+visiableSize.width/2,origin.y+visiableSize.height*3/5-10));
    //this->bird->setPosition(Point::ZERO);
    this->bird->idle();
    this->addChild(this->bird);
    //add land
    this->land1=Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("land"));
    this->land1->setPosition(Point::ZERO);
    this->land1->setAnchorPoint(Point::ZERO);
    this->addChild(land1);
    
    this->land2 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("land"));
    land2->setAnchorPoint(Point::ZERO);
    land2->setPosition(this->land1->getContentSize().width-2.0f,0);
    this->addChild(land2);
    
    this->schedule(schedule_selector(WelcomeLayer::scrollLand), 0.01f);
    
    Sprite* copyright=Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("brand_copyright"));
    copyright->setAnchorPoint(Point::ZERO);
    copyright->setPosition(Point(origin.x + visiableSize.width/2,origin.y+visiableSize.height/6));
    this->addChild(copyright,10);
    
    return true;
}

void WelcomeLayer::scrollLand(float dt){
    land1->setPositionX(land1->getPositionX()-2.0f);
    this->land2->setPositionX(this->land1->getPositionX()+this->land1->getContentSize().width-2.0f);
    
    if(this->land2->getPositionX() == 0) {
        this->land1->setPositionX(0);
    }

}

void WelcomeLayer::menuStartCallback(Ref *sender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sfx_swooshing.ogg");
    this->removeChildByTag(BIRD_SPRITE_TAG);
    //auto scene = GameScene::create();
    //TransitionScene *transition = TransitionFade::create(1, scene);
    //Director::getInstance()->replaceScene(transition);

}





