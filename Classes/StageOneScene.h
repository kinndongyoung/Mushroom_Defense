#ifndef _StageOneScene_H__
#define _StageOneScene_H__

#include "cocos2d.h"

class StageOneScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(StageOneScene);

	cocos2d::EventListenerTouchOneByOne* listener;

	void onEnter();
	void onExit();
	void doAction(Ref* pSender);
	void ActionSequence();
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	
	void callEveryFrame(float f);
	void myTick(float f);
	void createEnemy();
	//void setViewpointCenter(cocos2d::Vec2 position);
	
	int nNum;
	cocos2d::Size			winSize;
	cocos2d::Vec2			EnemyPosition;
	cocos2d::Sprite*		Enemy[10];
	cocos2d::TMXTiledMap*	tmap;


};

#endif // __StageOneScene_SCENE_H__
