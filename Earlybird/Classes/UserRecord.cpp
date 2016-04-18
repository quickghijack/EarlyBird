
//
//  UserRecord.cpp
//  Earlybird
//
//  Created by zhe on 16/4/17.
//
//

#include "UserRecord.h"

UserRecord::UserRecord(){};
UserRecord::~UserRecord(){};

bool UserRecord::init(){
    return true;
}

UserRecord* UserRecord::shareUserRecord=nullptr;

UserRecord* UserRecord::getInstance(){
    if(shareUserRecord==NULL){
        shareUserRecord=new UserRecord();
        if(!shareUserRecord->init()){
            CC_SAFE_DELETE(shareUserRecord);
            CCLOG("ERROR:init UserRecord failed");
            shareUserRecord=nullptr;
        }
    }
    return shareUserRecord;
}

void UserRecord::saveIntgerToUserDefault(const char *key, int sorce){
    UserDefault::getInstance()->setIntegerForKey(key, sorce);
}

int UserRecord::readIntgerFromUserDefault(const char *key){
    return UserDefault::getInstance()->getIntegerForKey(key);
}