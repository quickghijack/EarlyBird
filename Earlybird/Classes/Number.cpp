//
//  Number.cpp
//  Earlybird
//
//  Created by zhe on 16/4/20.
//
//

#include "Number.h"
NumberSeries::NumberSeries(){};
NumberSeries::~NumberSeries(){};

bool NumberSeries::init(){
    this->numberSeries = Vector<SpriteFrame*>(10);
    return true;
};

void NumberSeries::loadNumber(const char *fmt,int base){
    for(int i=base;i<10+base;i++){
        const char* fileName = String::createWithFormat(fmt,i)->getCString();
        auto frame=AtlasLoader::getInstance()->getSpriteFrameByName(fileName);
        numberSeries.pushBack(frame);
    }
}

SpriteFrame* NumberSeries::at(int index){
    return numberSeries.at(index);
}

/*----------------------Number Class---------------------------*/

Number* Number::sharedNumber=nullptr;

Number* Number::getInstance(){
    if(sharedNumber==NULL){
        sharedNumber = new Number();
        if (!sharedNumber->init()) {
            CC_SAFE_DELETE(sharedNumber);
            CCLOG("ERROR:init shareNumber fail");
            sharedNumber=nullptr;
        }
    }
    return sharedNumber;
}

void Number::destoryInstance(){
    CC_SAFE_DELETE(sharedNumber);
}

bool Number::init(){
    return true;
}

Number::Number(){};
Number::~Number(){};

bool Number::loadNumber(const char *name, const char *fmt,int base){
    auto numberSeries = NumberSeries::create();
    numberSeries->loadNumber(fmt,base);
    numberContainer.insert(name, numberSeries);
    return true;
};

Node* Number::convert(const char *name, int number,Gravity gravity){
    auto numbers = numberContainer.at(name);
    if(numbers == 0){
        auto numberZero = Sprite::createWithSpriteFrame(numbers->at(0));
        numberZero->setAnchorPoint(Point(0.5,0));
        return numberZero;
    }
    
    auto numberNode = Node::create();
    float totalWidth = 0;
    while (number) {
        int tmp = number%10;
        number = number /10;
        auto sprite = Sprite::createWithSpriteFrame(numbers->at(tmp));
        totalWidth=totalWidth+sprite->getContentSize().width;
        numberNode->addChild(sprite);
    }
    
    auto numberZero = Sprite::createWithSpriteFrame(numbers->at(0));
    numberNode->setContentSize(Size(totalWidth,numberZero->getContentSize().width));
    //numberNode->addChild(numberZero);
    if (gravity==GRAVITY_CENTER) {
        float singleWidth = totalWidth / numberNode->getChildrenCount();
        int index = numberNode->getChildrenCount() / 2;
        for(auto child:numberNode->getChildren()){
            child -> setAnchorPoint(Point(0.5,0));
            float offline = singleWidth* index --;
            child->setPositionX(offline);
        }
    }else if(gravity == Gravity::GRAVITY_RIGHT) {
        float singleWidth = totalWidth/numberNode->getChildrenCount();
        int index = numberNode->getChildrenCount();
        for(auto child : numberNode->getChildren()) {
            child->setAnchorPoint(Point(1, 0));
            float offLength = singleWidth*index--;
            child->setPositionX(offLength);
        }
    }else if(gravity == Gravity::GRAVITY_LEFE) {
        float singleWidth = totalWidth/numberNode->getChildrenCount();
        int index = 0;
        for(auto child : numberNode->getChildren()) {
            child->setAnchorPoint(Point::ZERO);
            float offLength = singleWidth*index++;
            child->setPositionX(offLength);
        } 
    }
return numberNode;
}