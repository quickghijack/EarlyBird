//
//  GameLayer.cpp
//  Earlybird
//
//  Created by zhe on 16/4/17.
//
//
#pragma once
#include "cocos2d.h"
#include "UserRecord.h"
#include "OptionLayer.h"
#include "BirdSprite.h"
#include "BackgroundLayer.h"
#include "AtlasLoader.h"
#include "SimpleAudioEngine.h"
#include <cstdlib>

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

const int UP_PIP=21;
const int DOWN_PIP=12;
const int PIP_PASS = 30;
const int PIP_NEW=31;

const int BIRD_RADIUS = 15;
