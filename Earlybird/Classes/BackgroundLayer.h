//
//  BackgroundLayer.hpp
//  Earlybird
//
//  Created by 谢从 on 16/4/13.
//
//
#pragma once
#include "cocos2d.h"
#include "AtlasLoader.h"
#include "time.h"


using namespace cocos2d;
using namespace std;

class BackgroundLayer:public Layer{
public:
    BackgroundLayer();
    ~BackgroundLayer();
    virtual bool init();
    CREATE_FUNC(BackgroundLayer);
    static float getLandHeight();
};