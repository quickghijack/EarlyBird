//
//  AtlasLoader.cpp
//  Earlybird
//
//  Created by 谢从 on 16/4/11.
//
//

#include "AtlasLoader.h"

AtlasLoader* AtlasLoader::shareAtlasLoader=nullptr;

AtlasLoader* AtlasLoader::getInstance(){
    if (shareAtlasLoader==NULL){
        shareAtlasLoader=new AtlasLoader();
        if (!shareAtlasLoader->init()){
            delete shareAtlasLoader;
            shareAtlasLoader=NULL;
            CCLOG("ERROR:could not init shareAtlasLoader");

        }
    }
    return shareAtlasLoader;
}
AtlasLoader::AtlasLoader(){};
AtlasLoader::~AtlasLoader(){};

void AtlasLoader::destoryInstance(){
    CC_SAFE_DELETE(shareAtlasLoader);
}

bool AtlasLoader::init(){
    return true;
}

void AtlasLoader::loadAtlas(string fileName){
    auto textureAtlas=Director::getInstance()->getTextureCache()->addImage("Image/atlas.png");
    this->loadAtlas(fileName, textureAtlas);
}

void AtlasLoader::loadAtlas(string fileName, cocos2d::Texture2D *texture){
    string data=FileUtils::getInstance()->getStringFromFile(fileName);
    unsigned long pos;
    Atlas atlas;
    pos = data.find_first_of("\n");
    string line=data.substr(0,pos);
    while(line!=""){
        sscanf(line.c_str(), "%s %d %d %f %f %f %f",&atlas.name,
        &atlas.width,&atlas.height,&atlas.start.x,&atlas.start.y,
               &atlas.end.x,&atlas.end.y);
        atlas.start.x=1024*atlas.start.x;
        atlas.start.y=1024*atlas.start.y;
        atlas.end.x=1024*atlas.end.x;
        atlas.end.y=1024*atlas.end.y;
        //next
        pos = data.find_first_of("\n");
        string line=data.substr(0,pos);
        
        //fix bug
        if(atlas.name == string("land")) {
            atlas.start.x += 1;
        }
        Rect rect =Rect(atlas.start.x, atlas.start.y, atlas.width, atlas.height);
        auto frame=SpriteFrame::createWithTexture(texture, rect);
        this->_spriteFrame.insert(string(atlas.name), frame);
    }
    
}

SpriteFrame* AtlasLoader::getSpriteFrameByName(string name){
    return this->_spriteFrame.at(name);
}

















