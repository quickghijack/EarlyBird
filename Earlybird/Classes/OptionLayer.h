//
//  OptionLayer.hpp
//  Earlybird
//
//  Created by zhe on 16/4/18.
//
//

#ifndef OptionLayer_hpp
#define OptionLayer_hpp

#pragma once
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

class OptionDelegate{
public:
    //a abstart method
    virtual void onTouch() = 0;
    
};

class OptionLayer:public Layer{
public:
    OptionLayer();
    ~OptionLayer();
    
    virtual bool init();
    CREATE_FUNC(OptionLayer);
    
    void onTouchesBegan(const std::vector<Touch*> &touchs, Event *event);
    
    CC_SYNTHESIZE(OptionDelegate*, delegator, Delegator)
};

#endif /* OptionLayer_hpp */
