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

using namespace cocos2d;
using namespace std;

class LoadingScene: public Scene{
public:
    //default Contruction
    LoadingScene();
    ~LoadingScene();
    
    virtual bool init();
    CREATE_FUNC(LoadingScene);
    
    void onEnter() override;
private:
    void LoadingCallBack(Texture2D  *texture);
    
};

#endif /* LoadingScene_hpp */
