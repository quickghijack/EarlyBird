//
//  StatusLayer.cpp
//  Earlybird
//
//  Created by zhe on 16/4/20.
//
//

#include "StatusLayer.h"

StatusLayer::StatusLayer(){};
StatusLayer::~StatusLayer(){};

bool StatusLayer::init(){
    if(!Layer::init()){
        return false;
    }
    this->bestScore=0;
    this->currentScore=0;
    isNewRecord=false;
    Number::getInstance()->loadNumber(NUMBER_FONT.c_str(), "font_0%02d",48);
    Number::getInstance()->loadNumber(NUMBER_SCORE.c_str(),"number_score_%02d");
    this->visiableSize=Director::getInstance()->getVisibleSize();
    this->originPoint=Director::getInstance()->getVisibleOrigin();
    this->showReadyStatus();
    this->loadWhiteSprite();
    return true;
}

void StatusLayer::showReadyStatus(){
    scoreSprite = (Sprite*)Number::getInstance()->convert(NUMBER_SCORE.c_str(), 0);
    scoreSprite->setPosition(Point(this->originPoint.x+this->visiableSize.width/2,this->originPoint.y+this->visiableSize.height*5/6));
    this->addChild(scoreSprite);

    getReadySprite=Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("text_ready"));
    getReadySprite->setPosition(Point(this->originPoint.x+this->visiableSize.width/2,this->originPoint.y+this->visiableSize.height*2/3));
    this->addChild(getReadySprite);
    
    tutorialSprite = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("tutorial"));
    tutorialSprite->setPosition(Point(this->originPoint.x+this->visiableSize.width/2,this->originPoint.y+this->visiableSize.height/2));
    this->addChild(tutorialSprite);
                             
}

void StatusLayer::showStartStatus(){
    this->getReadySprite->runAction(FadeOut::create(0.4f));
    this->tutorialSprite->runAction(FadeOut::create(0.04f));
    
}

void StatusLayer::showOverStatus(int curScore, int bestScore){
    this->currentScore=curScore;
    this->bestScore = bestScore;
    if(curScore>bestScore){
        this->bestScore = currentScore;
        isNewRecord = true;
    }else{
        isNewRecord=false;
    }
    this->removeChild(scoreSprite);
    this->blinkFullScreen();
}

void StatusLayer::onGameStart(){
    showStartStatus();
}

void StatusLayer::onGamePlaying(int score){
    this->removeChild(scoreSprite);
    this->scoreSprite = (Sprite*)Number::getInstance()->convert(NUMBER_FONT.c_str(), score);
    scoreSprite->setPosition(Point(this->originPoint.x+visiableSize.width/2,this->originPoint.y+visiableSize.height*5/6));
    this->addChild(scoreSprite);
}

void StatusLayer::onGameEnd(int curScore, int bestScore){
    this->showOverStatus(curScore, bestScore);
}

void StatusLayer::loadWhiteSprite(){
    whiteSprite = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("white"));
    whiteSprite->setScale(100);
    whiteSprite->setOpacity(0);
    this->addChild(whiteSprite,10000);
}

void StatusLayer::blinkFullScreen(){
    auto fadeOut = FadeOut::create(0.1f);
    auto fadeIn  = FadeIn::create(0.1f);
    auto blinkAction = Sequence::create(fadeIn,fadeOut, NULL);
    CallFunc *acDone = CallFunc::create(CC_CALLBACK_0(StatusLayer::fadeInGameOver, this));
    auto squene = Sequence::createWithTwoActions(blinkAction, acDone);
    whiteSprite->stopAllActions();
    whiteSprite->runAction(squene);
}

void StatusLayer::fadeInGameOver(){
    Sprite* gameOverSprite = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("text_game_over"));
    gameOverSprite->setPosition(Point(originPoint.x+visiableSize.width,originPoint.y+visiableSize.height*2/3));
    this->addChild(gameOverSprite);
    
    auto gameOverFadeIn = FadeIn::create(0.5f);
    //start next action
    CallFunc* actionDone = CallFunc::create(CC_CALLBACK_0(StatusLayer::jumpToScrorePanel, this));
    auto  sequene = Sequence::createWithTwoActions(gameOverFadeIn,actionDone);
    gameOverSprite->stopAllActions();
    gameOverSprite->runAction(sequene);
}
 
void StatusLayer::jumpToScrorePanel(){
    Sprite* scorePanelSprite = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("score_panel"));
    scorePanelSprite->setPosition(Point(originPoint.x+visiableSize.width/2,originPoint.y-scorePanelSprite->getContentSize().height));
    //scorePanelSprite->setPosition(Point(originPoint.x+visiableSize.width/2,originPoint.y-scoreSprite->getContentSize().height));
    this->addChild(scorePanelSprite);
    
    auto bestScoreSprite = (Sprite*)Number::getInstance()->convert(NUMBER_SCORE.c_str(), this->bestScore,Gravity::GRAVITY_RIGHT);
    bestScoreSprite->setAnchorPoint(Point(1,1));
    bestScoreSprite->setPosition(Point(scorePanelSprite->getContentSize().width-28,50));
    scorePanelSprite->addChild(bestScoreSprite);
    
    
    
    string medalName = this->getMedalName(currentScore);
    if(medalName!=""){
        auto medalSprite = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("new"));
        medalSprite->setPosition(-16,12);
        bestScoreSprite->addChild(medalSprite);
    }
    
    auto scorePanelMoveTo = MoveTo::create(0.8f, Point(this->originPoint.x+visiableSize.width/2,this->originPoint.y+visiableSize.height-10.0f));
    EaseExponentialOut* sineIn = EaseExponentialOut::create(scorePanelMoveTo);
    CallFunc* actionDone = CallFunc::create(CC_CALLBACK_0(StatusLayer::fadeInRestBtn, this));
    auto sequene = Sequence::createWithTwoActions(sineIn, actionDone);
    scoreSprite->stopAllActions();
    scoreSprite->runAction(sequene);
    SimpleAudioEngine::getInstance()->playEffect("sfx_swooshing.ogg");
    
}


void StatusLayer::fadeInRestBtn(){
    auto tmpNode = Node::create();
    
    auto restartButton = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_play"));
    auto restartActiveButton = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_play"));
    restartActiveButton->setPositionY(-4);
    auto menuItem = MenuItemSprite::create(restartButton, restartActiveButton, CC_CALLBACK_1(StatusLayer::menuRestartCallBack, this));
    auto menu = Menu::create(menuItem, NULL);
    menu->setPosition(Point(this->originPoint.x + this->visiableSize.width / 2 - restartButton->getContentSize().width / 2, this->originPoint.y + this->visiableSize.height * 2 / 7 - 10.0f));
    tmpNode->addChild(menu);
    
    
    auto rateBtn = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_score"));
    rateBtn->setPosition(Point(this->originPoint.x+visiableSize.width/2+rateBtn->getContentSize().width/2,this->originPoint.y+visiableSize.height*2/7 - 10.0f));
    //setposition到底是全局位置还是针对父类的位置？
    tmpNode->addChild(rateBtn);
    this->addChild(tmpNode);
    
    auto fadein = FadeIn::create(0.1f);
    
    CallFunc* actionDone = CallFunc::create(CC_CALLBACK_0(StatusLayer::refrenceScoreCallBack, this));
    auto sequence = Sequence::createWithTwoActions(fadein, actionDone);
    tmpNode->stopAllActions();
    tmpNode->runAction(sequence);
}

void StatusLayer::refrenceScoreCallBack(){
    this->tmpScore=0;
    schedule(schedule_selector(StatusLayer::refrenceScoreExecutor), 0.1f);
}

void StatusLayer::refrenceScoreExecutor(float dt){
    if(this->getChildByTag(CURRENT_SCORE_SPRITE_TAG)){
        this->removeChildByTag(CURRENT_SCORE_SPRITE_TAG);
    }
    scoreSprite = (Sprite*)Number::getInstance()->convert(NUMBER_SCORE.c_str(), this->tmpScore,Gravity::GRAVITY_RIGHT);
    scoreSprite->setAnchorPoint(Point(1,0));
    scoreSprite->setPosition(Point(this->originPoint.x+visiableSize.width*3/4+20.0f,this->originPoint.y+this->visiableSize.height*1/2));
    scoreSprite->setTag(CURRENT_SCORE_SPRITE_TAG);
    this->addChild(scoreSprite,1000);
    this->tmpScore++;
    if(this->tmpScore>this->currentScore){
        unschedule(schedule_selector(StatusLayer::refrenceScoreExecutor));
    }
}

void StatusLayer::setBlinkSprite(){
    this->blink = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("blink_00"));
    Animation* animation = Animation::create();
    animation->setDelayPerUnit(0.1f);
    for(int i=0;i<3;i++){
        const char *fileName = String::createWithFormat("blink_%02d",i)->getCString();
        auto *frame = AtlasLoader::getInstance()->getSpriteFrameByName(fileName);
        animation->addSpriteFrame(frame);
    }
    for(int i = 2;i>=0;i--){
        const char *filename = String::createWithFormat("blink_%02d",i)->getCString();
        auto *frame = AtlasLoader::getInstance()->getSpriteFrameByName(filename);
        animation->addSpriteFrame(frame);
    }
    auto animate = Animate::create(animation);
    auto actionDone = CallFunc::create(CC_CALLBACK_0(StatusLayer::blinkAction, this));
    auto sequence = Sequence::createWithTwoActions(animate, actionDone);
    blink->runAction(RepeatForever::create(sequence));
}


void StatusLayer::blinkAction(){
    if(this->blink&&this->blink->getParent()){
        Size activeSize = this->blink->getParent()->getContentSize();
        this->blink->setPosition(rand()%((int)(activeSize.width)),rand()%((int)activeSize.height));
    }
}


string StatusLayer::getMedalName(int score){
    this->setBlinkSprite();
    string medalName = "";
    string medalsName = "";
    if(this->currentScore >=10 && this->currentScore < 20){//iron medals
        medalsName = "medals_0";
    }else if(this->currentScore >= 20 && currentScore < 30){//bronze medals
        medalsName = "medals_1";
    }else if(currentScore >=30 && currentScore < 50){//silver medals
        medalsName = "medals_2";
    }else if(currentScore >=50){//golden medals
        medalsName = "medals_3";
    }
    return medalsName;
}

void StatusLayer::menuRestartCallBack(cocos2d::Ref *sender){
    SimpleAudioEngine::getInstance()->playEffect("sfx_swooshing.ogg");
    auto scene = GameScene::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}