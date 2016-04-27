//
//  StatusLayer.hpp
//  Earlybird
//
//  Created by zhe on 16/4/20.
//
//


#pragma once
#include "cocos2d.h"
#include "AtlasLoader.h"
#include "GameLayer.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Number.h"
#include <cstdlib>



using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;

const string NUMBER_SCORE="number_score";
const string NUMBER_FONT = "font";
const int CURRENT_SCORE_SPRITE_TAG = 10001;

class StatusLayer : public Layer, public StatusDelegate{
public:
    StatusLayer();
    ~StatusLayer();
    virtual bool init();
    CREATE_FUNC(StatusLayer);
    void onGameStart();
    void onGamePlaying(int score);
    void onGameEnd(int curScore, int bestScore);
private:
    void showReadyStatus();
    void showStartStatus();
    void showOverStatus(int curScore,int bestScore);
    void loadWhiteSprite();
    void blinkFullScreen();
    void fadeInGameOver();
    void jumpToScrorePanel();
    void fadeInRestBtn();
    void refrenceScoreCallBack();
    void refrenceScoreExecutor(float dt);
    string getMedalName(int score);
    Sprite* blink;
    void setBlinkSprite();
    void blinkAction();
    void menuRestartCallBack(Ref * sender);
    Sprite* scoreSprite;
    Sprite* getReadySprite;
    Sprite* tutorialSprite;
    Sprite* whiteSprite;
    int currentScore;
    int bestScore;
    int tmpScore;
    bool isNewRecord;
    Point originPoint;
    Size visiableSize;
};

