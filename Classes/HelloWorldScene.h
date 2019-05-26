#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#define TAG_MENU_START		0
#define TAG_MENU_OPTION		1
#define TAG_MENU_EXIT		2

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void MainMenu(Ref *pSender);

	Sprite* mainBackground;

	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(HelloWorld);

};



#endif __MENU_SCENE_H__