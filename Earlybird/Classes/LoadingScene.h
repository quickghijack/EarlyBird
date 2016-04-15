//
//  LoadingScene.hpp
//  Earlybird
//
//  Created by 谢从 on 16/4/12.
//
//

#ifndef LoadingScene_hpp
#define LoadingScene_hpp

#include "cocos2d.h"
#include "AtlasLoader.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"

using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;

class LoadingScene: public Scene{
public:
    //default Contruction
    LoadingScene();
    ~LoadingScene();
    
    virtual bool init() override;
    CREATE_FUNC(LoadingScene);
    
    void onEnter() override;
private:
    void LoadingCallBack(Texture2D  *texture);
    
};

#endif /* LoadingScene_hpp */
