//
//  LoadingScene.cpp
//  Earlybird
//
//  Created by on 16/4/12.
//
//

#include "LoadingScene.h"
#include "WelcomeScene.h"
LoadingScene::LoadingScene(){};
LoadingScene::~LoadingScene(){};

bool LoadingScene::init(){
    if(Scene::init()) {return true; }
    else {return false;}
};

void LoadingScene::onEnter(){
    //add backgroud to this scene
    Sprite *background = Sprite::create("splash.png");
    
    Size visiableSize=Director::getInstance()->getVisibleSize();
    Point origin=Director::getInstance()->getVisibleOrigin();
    background->setPosition(origin.x+visiableSize.width/2,origin.y+visiableSize.height/2);
    this->addChild(background);
    
    Director::getInstance()->getTextureCache()->addImageAsync("atlas.png", CC_CALLBACK_1(LoadingScene::LoadingCallBack, this));
};

void LoadingScene::LoadingCallBack(cocos2d::Texture2D *texture){
    AtlasLoader::getInstance()->loadAtlas("atlas.txt", texture);
    
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_die.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_hit.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_point.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_swooshing.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_wing.ogg");
    
    Scene* scene=WelcomeScene::create();
    TransitionScene* trans=TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(trans);
};
