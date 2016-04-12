//
//  AtlasLoader.h
//  Earlybird
//
//  Created by 谢从 on 16/4/11.
//
//

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

typedef struct _atlas{
    char name[255];
    int width;
    int height;
    Point start;
    Point end;
}Atlas;

class AtlasLoader{
public:
    //静态方法获取实例
    static AtlasLoader* getInstance();
    //静态方法删除实例
    static void destoryInstance();
    //同步方法载入图片纹理
    void loadAtlas(string fileName);
    //重载异步方法调用图片纹理
    void loadAtlas(string fileName, Texture2D *texture);
    //得到精灵
    SpriteFrame* getSpriteFrameByName(string name);
protected:
    AtlasLoader();
    virtual bool init();
    static AtlasLoader* shareAtlasLoader;
    Map<std::string, SpriteFrame*> _spriteFrame;
};

