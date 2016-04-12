//
//  LoadingScene.cpp
//  Earlybird
//
//  Created by 谢从 on 16/4/12.
//
//

#include "LoadingScene.h"

LoadingScene::LoadingScene(){};
LoadingScene::~LoadingScene(){};

bool LoadingScene::init(){
    if(Scene::init()) {return true; }
    else {return false;}
};

void LoadingScene::onEnter(){
    //add backgroud to this scene
    Sprite *background = Sprite::create("image/splash.png");
    
}
