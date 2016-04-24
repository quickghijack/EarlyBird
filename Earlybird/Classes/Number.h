//
//  Number.hpp
//  Earlybird
//
//  Created by zhe on 16/4/20.
//
//

#include "cocos2d.h"
#include "AtlasLoader.h"

using namespace cocos2d;
using namespace std;

typedef enum _gravity{
    GRAVITY_CENTER=1,
    GRAVITY_LEFE,
    GRAVITY_RIGHT
}Gravity;

const int numberInterval = 4;

class NumberSeries:public Ref{
public:
    NumberSeries();
    ~NumberSeries();
    virtual bool init();
    CREATE_FUNC(NumberSeries);
    void loadNumber(const char *fmt,int base=0);
    SpriteFrame* at(int index);
private:
    Vector<SpriteFrame*> numberSeries;
    
};

class Number{
public:
    Number();
    ~Number();
    static Number* getInstance();
    static void destoryInstance();
    virtual bool init();
    virtual bool loadNumber(const char* name,const char* fmt,int base=0);
    Node* convert(const char* name, int number , Gravity gravity =Gravity::GRAVITY_CENTER);
private:
    Map<string, NumberSeries*> numberContainer;
    static Number* sharedNumber;
};