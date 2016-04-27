//
//  GameScene.cpp
//  Earlybird
//
//  Created by zhe on 16/4/14.
//
//

#include "GameScene.h"

GameScene::GameScene(){};
GameScene::~GameScene(){};

bool GameScene::init(){
    if(!Scene::init()){
        return false;
    }
    if(Scene::initWithPhysics()){
        this->getPhysicsWorld()->setGravity(Vect(0,-900));
        auto backgroundLayer = BackgroundLayer::create();
        if(backgroundLayer){
            this->addChild(backgroundLayer);
        }
        
        auto statusLayer = StatusLayer::create();
        
        auto gameLayer = GameLayer::create();
        if(gameLayer){
            gameLayer->setPhyWorld(this->getPhysicsWorld());
            gameLayer->setDelegator(statusLayer);
            this->addChild(gameLayer);
        }
        if(statusLayer){
            this->addChild(statusLayer);
        }
        
        auto optionLayer = OptionLayer::create();
        if (optionLayer) {
            optionLayer->setDelegator(gameLayer);
            this->addChild(optionLayer);
        }
        return  true;
    }else {
        return  false;
    }
}

void GameScene::restart() {
    this->removeAllChildrenWithCleanup(true);
    this->init();
}
