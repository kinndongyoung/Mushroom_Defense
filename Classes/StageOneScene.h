#ifndef _StageOneScene_H__
#define _StageOneScene_H__

#include "cocos2d.h"

USING_NS_CC;

#define TAG_TOWER_ARCHER      6
#define TAG_TOWER_KNIGHT      7
#define TAG_TOWER_MAGICION      8

enum TOWER
{
	enum_None,
	enum_Knight,
	enum_Archer,
	enum_Magicion
};

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
	void TowerCallback(cocos2d::Ref* pSender);
	void createTower_A(float touchX, float touchY);
	void createTower_K(float touchX, float touchY);
	void createTower_M(float touchX, float touchY);
	void createTowerMenu();

	void callEveryFrame(float f);
	void myTick(float f);
	void createEnemy();
	//void setViewpointCenter(cocos2d::Vec2 position);
	TOWER m_enumTower = enum_None;
	int nNum;
	cocos2d::Size         winSize;
	cocos2d::Vec2         EnemyPosition;
	cocos2d::Sprite*      Enemy[10];
	cocos2d::TMXTiledMap*   tmap;

	cocos2d::Vec2         TowerPos;
	cocos2d::Sprite*      Tower_A;
	cocos2d::Sprite*      Tower_K;
	cocos2d::Sprite*      Tower_M;
	
	int t_x[12];
	int t_y[12];
};

#endif // __StageOneScene_SCENE_H__