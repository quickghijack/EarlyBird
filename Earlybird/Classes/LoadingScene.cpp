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
    Sprite *background = Sprite::create("image/splash.png");
    
    Size visableSize=Director::getInstance()->getVisibleSize();
    Point origin=Director::getInstance()->getVisibleOrigin();
    background->setPosition(origin.x+visableSize.width/2,origin.y+visableSize.height/2);
    this->addChild(background);
    
//    Texture2D* text = Director::getInstance()->getTextureCache()->addImage("image/atlas.png");
//    AtlasLoader::getInstance()->loadAtlas("image/atlas.txt", text);
//    Scene* scene=HelloWorld::createScene();
//    Director::getInstance()->replaceScene(scene);
    Director::getInstance()->getTextureCache()->addImageAsync("image/atlas.png", CC_CALLBACK_1(LoadingScene::LoadingCallBack, this));
    
};

void LoadingScene::LoadingCallBack(cocos2d::Texture2D *texture){
    AtlasLoader::getInstance()->loadAtlas("image/atlas.txt", texture);
    
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_die.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_hit.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_point.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_swooshing.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_wing.ogg");
    //Scene* scene=HelloWorld::createScene();
    Scene* scene=WelcomeScene::create();
    TransitionScene* trans=TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(trans);
    
};
