//
//  UserRecord.hpp
//  Earlybird
//
//  Created by zhe on 16/4/17.
//
//

#ifndef UserRecord_hpp
#define UserRecord_hpp

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class UserRecord : public Ref{
public:
    UserRecord();
    ~UserRecord();
    static UserRecord* getInstance();
    static void destoryInstance();
    virtual bool init();
    void saveIntgerToUserDefault(const char* key,int sorce);
    int readIntgerFromUserDefault(const char* key);
private:
    static UserRecord* shareUserRecord;
};

#endif /* UserRecord_hpp */
