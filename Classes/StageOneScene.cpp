#include "StageOneScene.h"
#include "SimpleAudioEngine.h"
#include "StageSelect.h"

USING_NS_CC;

Scene* StageOneScene::createScene()
{
	auto scene = Scene::create();

	auto layer = StageOneScene::create();

	scene->addChild(layer);

	return scene;
}

bool StageOneScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto tmap = TMXTiledMap::create("/TileMaps/Test1.tmx");
	tmap->setAnchorPoint(Vec2(0,0));
	tmap->setScale(1, 1);
	this->addChild(tmap);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	
	auto objects = tmap->getObjectGroup("Objects");

	ValueMap spawnPoint = objects->getObject("SpawnPoint");

	ValueMap movePoint1 = objects->getObject("move1");
	ValueMap movePoint2 = objects->getObject("move2");
	ValueMap movePoint3 = objects->getObject("move3");
	ValueMap movePoint4 = objects->getObject("move4");
	ValueMap movePoint5 = objects->getObject("move5");
	ValueMap movePoint6 = objects->getObject("move6");
	ValueMap movePoint7 = objects->getObject("move7");
	//ValueMap movePoint8 = objects->getObject("move8");
	int x = spawnPoint["x"].asInt();
	int y = spawnPoint["y"].asInt();

	int m_x1 = movePoint1["x"].asInt();
	int m_y1 = movePoint1["y"].asInt();
	int m_x2 = movePoint2["x"].asInt();
	int m_y2 = movePoint2["y"].asInt();
	int m_x3 = movePoint3["x"].asInt();
	int m_y3 = movePoint3["y"].asInt();
	int m_x4 = movePoint4["x"].asInt();
	int m_y4 = movePoint4["y"].asInt();
	int m_x5 = movePoint5["x"].asInt();
	int m_y5 = movePoint5["y"].asInt();
	int m_x6 = movePoint6["x"].asInt();
	int m_y6 = movePoint6["y"].asInt();
	int m_x7 = movePoint7["x"].asInt();
	int m_y7 = movePoint7["y"].asInt();
	//int m_x8 = movePoint8["x"].asInt();
	//int m_y8 = movePoint8["y"].asInt();

	int k = 0.3;
	int j = 10;
	for (int i = 0; i < 10; i++)
	{

		EnemyPosition = Vec2(x -= j, y);

		this->schedule(schedule_selector(StageOneScene::myTick), 2.0f);
		this->createEnemy();
		auto action = Sequence::create(
			MoveTo::create(2 + k, Vec2(m_x1, m_y1)), MoveTo::create(2, Vec2(m_x2, m_y2)),
			MoveTo::create(2, Vec2(m_x3, m_y3)), MoveTo::create(2, Vec2(m_x4, m_y4)),
			MoveTo::create(2, Vec2(m_x5, m_y5)), MoveTo::create(2, Vec2(m_x6, m_y6)),
			MoveTo::create(2, Vec2(m_x7, m_y7)), nullptr);
		Enemy[i]->runAction(action);
		k += 1;
		j += 10;
	}
	return true;
}

void StageOneScene::onEnter()
{
	Scene::onEnter();

	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(StageOneScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(StageOneScene::onTouchMoved, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void StageOneScene::onExit()
{
	_eventDispatcher->removeEventListener(listener);

	Scene::onExit();
}

bool StageOneScene::onTouchBegan(Touch *touch, Event *event)
{
	auto touchPoint = touch->getLocation();
	auto tmap = TMXTiledMap::create("/TileMaps/Test1.tmx");
	tmap->setScale(1.0, 1.0);
	tmap->setAnchorPoint(Point::ZERO);

	auto objects = tmap->getObjectGroup("Objects");

	ValueMap m_tower = objects->getObject("m_tower");
	int x = m_tower["x"].asInt();
	int y = m_tower["y"].asInt();

	int m_x1 = m_tower["x"].asInt();
	int m_y1 = m_tower["y"].asInt();
	
	if (touchPoint.x > m_x1 - 20 && touchPoint.x<m_x1 + 40 && touchPoint.y>m_y1 - 20 && touchPoint.y > m_y1 + 20)
	{
		auto texture = Director::getInstance()->getTextureCache()->addImage("/monster/Monster_1.png");
		auto Tower = Sprite::createWithTexture(texture, Rect(0, 0, 60, 60));
		Tower->setPosition(m_x1+20, m_y1+20);
		this->addChild(Tower);
	}
	
	return true;
}

void StageOneScene::onTouchMoved(Touch* touch, Event* event)
{
	
}

void StageOneScene::createEnemy()
{
	auto texture = Director::getInstance()->getTextureCache()->addImage("/monster/Monster_1.png");
	for (int i = 0; i < 10; i++)
	{
		Enemy[i] = Sprite::createWithTexture(texture, Rect(0, 0, 60, 60));
		Enemy[i]->setPosition(EnemyPosition);
		this->addChild(Enemy[i]);
	}

	/*auto texture = Director::getInstance()->getTextureCache()->addImage("/res/dragon_animation.png");

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	for (int i = 0; i < 6; i++)
	{
		int index = i % 4;
		int rowIndex = i / 4;

		animation->addSpriteFrameWithTexture(texture, Rect(index * 130, rowIndex * 140 + 70, 110, 70));
	}
	for (int i = 0; i < 10; i++)
	{
		Enemy[i] = Sprite::createWithTexture(texture, Rect(0, 70, 110, 70));
		Enemy[i]->setPosition(EnemyPosition);
		this->addChild(Enemy[i]);

		Enemy[i]->setFlippedX(true);
		Enemy[i]->setScale(0.5f);

		auto animate = Animate::create(animation);
		auto rep = RepeatForever::create(animate);
		Enemy[i]->runAction(rep);
	}*/
}
void StageOneScene::ActionSequence()
{
	auto action = Sequence::create(
		MoveTo::create(2, Vec2(400, 0)), MoveTo::create(2, Vec2(400, 50)),nullptr);
}

void StageOneScene::callEveryFrame(float f)
{
	nNum++;
	if(nNum>60)
	{
		nNum = 1;
	}
	log("fps...%d,nNum");
}
void StageOneScene::myTick(float f)
{
	log("tick******");

}