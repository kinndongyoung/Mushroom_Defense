#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "StageSelect.h"

using namespace CocosDenshion;
USING_NS_CC;

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();

	auto layer = HelloWorld::create();

	scene->addChild(layer);

	return scene;
}

bool HelloWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	mainBackground = Sprite::create("mainbase.png");
	mainBackground->setPosition(Point::ZERO);
	mainBackground->setAnchorPoint(Point::ZERO);
	mainBackground->setScale(1.0, 1.0);
	this->addChild(mainBackground);

	auto visSize = Director::getInstance()->getVisibleSize();
	auto menuOne = MenuItemImage::create("start.png", "on_start.png", CC_CALLBACK_1(HelloWorld::MainMenu, this));
	auto menuTwo = MenuItemImage::create("option.png", "on_option.png", CC_CALLBACK_1(HelloWorld::MainMenu, this));
	auto menuThree = MenuItemImage::create("exit.png", "on_exit.png", CC_CALLBACK_1(HelloWorld::MainMenu, this));

	menuOne->setTag(TAG_MENU_START);
	menuOne->setScale(1.0, 1.0);
	menuTwo->setTag(TAG_MENU_OPTION);
	menuTwo->setScale(1.0, 1.0);
	menuThree->setTag(TAG_MENU_EXIT);
	menuThree->setScale(1.0, 1.0);

	auto menu = Menu::create(menuOne, menuTwo, menuThree, NULL);
	menu->setPosition(Point(visSize.width / 3, visSize.height / 3));
	menu->alignItemsVerticallyWithPadding(5);
	this->addChild(menu);

	return true;
}

void HelloWorld::MainMenu(Ref *pSender)
{
	auto item = (MenuItem*)pSender;

	switch (item->getTag())
	{
	case TAG_MENU_START:
	{
		this->removeChild(mainBackground);
		auto scene = TransitionFadeTR::create(0.5f, StageSelScene::createScene());
		Director::getInstance()->replaceScene(scene);
		//SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		//SimpleAudioEngine::getInstance()->playBackgroundMusic("Sound/ingame.wav");
	}
	break;
	case TAG_MENU_OPTION:
	{
	}
	break;
	case TAG_MENU_EXIT:
	{

		Director::getInstance()->end();
		break;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
#endif
		break;
	}
	}
}