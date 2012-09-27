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

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    void update(float dt);

    virtual void didAccelerate(CCAcceleration* pAccelerationValue);

    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(HelloWorld);

private:
	cocos2d::CCSpriteBatchNode * _batchNode;
	cocos2d::CCSprite * _ship;

	CCParallaxNodeExtras *_backgroundNode;
	CCSprite *_spacedust1;
	CCSprite *_spacedust2;
	CCSprite *_planetsunrise;
	CCSprite *_galaxy;
	CCSprite *_spacialanomaly;
	CCSprite *_spacialanomaly2;

	float _shipPointsPerSecY;
	double rollingX ;
};

#endif // __HELLOWORLD_SCENE_H__
