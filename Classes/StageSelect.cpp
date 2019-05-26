#include "StageSelect.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
USING_NS_CC;

using namespace CocosDenshion;

Scene* StageSelScene::createScene()
{
	auto scene = Scene::create();

	auto layer = StageSelScene::create();

	scene->addChild(layer);

	return scene;
}

bool StageSelScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//this->schedule(schedule_selector(StageSelScene::scheduleCallback), 0.1f);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//StageOneSceneInit();  // 스테이지1 씬으로 들어감
	//StageTwoSceneInit();  // 스테이지2 씬으로 들어감

	stageBackground = Sprite::create("stageselectbase.png");
	stageBackground->setPosition(Point::ZERO);
	stageBackground->setAnchorPoint(Point::ZERO);
	stageBackground->setScale(0.8, 0.8);
	this->addChild(stageBackground);

	auto visSize = Director::getInstance()->getVisibleSize();
	auto menuOne = MenuItemImage::create("stage/s_stage1.png", "stage/on_s_stage1.png", CC_CALLBACK_1(StageSelScene::StageSelectMenu, this));
	auto menuTwo = MenuItemImage::create("stage/s_stage2.png", "stage/on_s_stage2.png", CC_CALLBACK_1(StageSelScene::StageSelectMenu, this));
	auto menuThree = MenuItemImage::create("stage/s_stage3.png", "stage/on_s_stage3.png", CC_CALLBACK_1(StageSelScene::StageSelectMenu, this));
	auto menuFour = MenuItemImage::create("stage/s_stage4.png", "stage/on_s_stage4.png", CC_CALLBACK_1(StageSelScene::StageSelectMenu, this));
	auto menuFive = MenuItemImage::create("stage/s_stage5.png", "stage/on_s_stage5.png", CC_CALLBACK_1(StageSelScene::StageSelectMenu, this));
	auto menuBack = MenuItemImage::create("back.png", "on_back.png", CC_CALLBACK_1(StageSelScene::StageSelectMenu, this));

	menuOne->setTag(TAG_STAGE_ONE);
	menuOne->setScale(1.0, 1.0);
	menuTwo->setTag(TAG_STAGE_TWO);
	menuTwo->setScale(1.0, 1.0);
	menuThree->setScale(1.0, 1.0);
	menuFour->setScale(1.0, 1.0);
	menuFive->setScale(1.0, 1.0);
	menuBack->setTag(TAG_STAGE_BACK);
	menuBack->setScale(1.0, 1.0);

	auto menu = Menu::create(menuOne, menuTwo, menuThree, menuFour, menuFive, NULL);
	menu->setPosition(Point(visSize.width / 2, visSize.height / 3));
	menu->alignItemsHorizontallyWithPadding(10);
	this->addChild(menu);

	auto menu2 = Menu::create(menuBack, NULL);
	menu2->setPosition(Vec2(1180, 620));
	this->addChild(menu2);
	return true;
}

void StageSelScene::StageSelectMenu(Ref *pSender)
{
	auto item = (MenuItem*)pSender;
	switch (item->getTag())
	{
	case TAG_STAGE_ONE:
	{
		
	}
	break;
	case TAG_STAGE_TWO:
	{
	
	}
	break;
	case TAG_STAGE_BACK:
	{
		this->removeChild(stageBackground);
		auto scene = TransitionFadeTR::create(0.5f, HelloWorld::createScene());
		Director::getInstance()->replaceScene(scene);
	}
	break;
	}
}