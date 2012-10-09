//
//  Created by Gonzalo Diaz Cruz on 04-09-12.
//  Copyright Studio Pangea 2012. All rights reserved.
//  http://www.studiopangea.com/
//

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CCParallaxNodeExtras.h"

using namespace cocos2d;

typedef enum {
  KENDREASONWIN,
  KENDREASONLOSE
} EndReason;


class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual ~HelloWorld();

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    void update(float dt);
    void gameLogic(float dt);
    void spriteMoveFinished(CCNode* sender);
    void setInvisible(CCNode * node);

    virtual void didAccelerate(CCAcceleration* pAccelerationValue);
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);

    void endScene( EndReason endReason ) ;
    void restartTapped() ;

    float getTimeTick();

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

protected:
    int _projectilesDestroyed;
    int _goal;
    cocos2d::CCArray *_asteroids;

private:
    // Space Ship
    cocos2d::CCSpriteBatchNode * _batchNode;
    cocos2d::CCSprite * _ship;

    // Background and continuous parallax
    CCParallaxNodeExtras *_backgroundNode;
    CCSprite *_spacedust1;
    CCSprite *_spacedust2;
    CCSprite *_planetsunrise;
    CCSprite *_galaxy;
    CCSprite *_spacialanomaly;
    CCSprite *_spacialanomaly2;

    // Accelerometer
    float _shipPointsPerSecY;

    // Laser
    CCArray*  _shipLasers ;
    int _nextShipLaser ;

    // Score
    int _lives ;

    // Score
    double _gameOverTime ;
    bool _gameOver ;
};

#endif // __HELLOWORLD_SCENE_H__
