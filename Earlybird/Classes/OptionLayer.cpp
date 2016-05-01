//
//  OptionLayer.cpp
//  Earlybird
//
//  Created by zhe on 16/4/18.
//
//

#include "OptionLayer.h"

OptionLayer::OptionLayer(){};
OptionLayer::~OptionLayer(){};

bool OptionLayer::init(){
    if(Layer::init()){
        auto dispatcher = Director::getInstance()->getEventDispatcher();
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(OptionLayer::onTouchesBegan,this);
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        return true;
    }
    else return false;
};

void OptionLayer::onTouchesBegan(const std::vector<Touch *> &touchs, cocos2d::Event *event){
    this->delegator->onTouch();
    
}
