#ifndef __STAGESELECT_SCENE_H__
#define __STAGESELECT_SCENE_H__

#include "cocos2d.h"

#define TAG_STAGE_ONE		3
#define TAG_STAGE_TWO		4
#define TAG_STAGE_BACK		5

USING_NS_CC;

class StageSelScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	void StageSelectMenu(Ref *pSender);

	Sprite* stageBackground;

	virtual bool init();

	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(StageSelScene);
};

#endif