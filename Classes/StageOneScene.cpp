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

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto tmap = TMXTiledMap::create("/TileMaps/TestDesert.tmx");
	//tmap->setTileSize(winSize);
	tmap->setPosition(Point::ZERO);
	tmap->setAnchorPoint(Point::ZERO);
	//tmap->setScale(1.1, 0.95);
	tmap->setScale(1.0, 1.0);
	this->addChild(tmap, 0, 0);

	auto Menu_Archer = MenuItemImage::create("/Tower/ArcherMenu.png", "/Tower/ArcherMenu2.png", CC_CALLBACK_1(StageOneScene::TowerCallback, this));
	auto Menu_Knight = MenuItemImage::create("/Tower/KnightMenu.png", "/Tower/KnightMenu2.png", CC_CALLBACK_1(StageOneScene::TowerCallback, this));
	auto Menu_Magicion = MenuItemImage::create("/Tower/MagicionMenu.png", "/Tower/MagicionMenu2.png", CC_CALLBACK_1(StageOneScene::TowerCallback, this));
	//auto TowerMenu = MenuItemToggle::createWithCallback(CC_CALLBACK_1(StageOneScene::TowerCallback, this), Menu_Knight, Menu_Archer, Menu_Magicion, NULL);

	auto visSize = Director::getInstance()->getVisibleSize();
	Menu_Archer->setTag(TAG_TOWER_ARCHER);
	Menu_Archer->setScale(1.0, 1.0);
	Menu_Knight->setTag(TAG_TOWER_KNIGHT);
	Menu_Knight->setScale(1.0, 1.0);
	Menu_Magicion->setTag(TAG_TOWER_MAGICION);
	Menu_Magicion->setScale(1.0, 1.0);

	auto menu = Menu::create(Menu_Archer, Menu_Knight, Menu_Magicion, NULL);


	auto objects = tmap->getObjectGroup("Objects");

	ValueMap spawnPoint = objects->getObject("SpawnPoint");

	ValueMap movePoint1 = objects->getObject("move1"); ValueMap movePoint2 = objects->getObject("move2");
	ValueMap movePoint3 = objects->getObject("move3"); ValueMap movePoint4 = objects->getObject("move4");
	ValueMap movePoint5 = objects->getObject("move5"); ValueMap movePoint6 = objects->getObject("move6");
	ValueMap movePoint7 = objects->getObject("move7"); ValueMap MenuPoint = objects->getObject("TowerMenu");
	
	//ValueMap movePoint8 = objects->getObject("move8");
	int x = spawnPoint["x"].asInt();
	int y = spawnPoint["y"].asInt();

	int m_x1 = movePoint1["x"].asInt(); int m_y1 = movePoint1["y"].asInt();
	int m_x2 = movePoint2["x"].asInt(); int m_y2 = movePoint2["y"].asInt();
	int m_x3 = movePoint3["x"].asInt(); int m_y3 = movePoint3["y"].asInt();
	int m_x4 = movePoint4["x"].asInt(); int m_y4 = movePoint4["y"].asInt();
	int m_x5 = movePoint5["x"].asInt(); int m_y5 = movePoint5["y"].asInt();
	int m_x6 = movePoint6["x"].asInt(); int m_y6 = movePoint6["y"].asInt();
	int m_x7 = movePoint7["x"].asInt(); int m_y7 = movePoint7["y"].asInt();

	int menuX = MenuPoint["x"].asInt(); int MenuY = MenuPoint["y"].asInt();


	

	menu->setPosition(Vec2(menuX, MenuY));
	menu->alignItemsHorizontallyWithPadding(5);
	this->addChild(menu);
	int k = 0.3;
	int j = 10;
	for (int i = 0; i < 10; i++)
	{

		EnemyPosition = Vec2(x -= j, y);

		this->createEnemy();
		auto action = Sequence::create(
			MoveTo::create(4+k, Vec2(m_x1, m_y1)), MoveTo::create(3, Vec2(m_x2, m_y2)),
			MoveTo::create(3, Vec2(m_x3, m_y3)), MoveTo::create(3, Vec2(m_x4, m_y4)),
			MoveTo::create(3, Vec2(m_x5, m_y5)), MoveTo::create(4, Vec2(m_x6, m_y6)),
			MoveTo::create(4, Vec2(m_x7, m_y7)), nullptr);
		Enemy[i]->runAction(action);
		k += 1;
		j += 10;
	}

	
	//createTowerMenu();
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->setSwallowTouches(true);
	//listener->onTouchBegan = CC_CALLBACK_2(StageOneScene::onTouchBegan, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

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
	//Point location;

	auto location = touch->getLocation();

	auto tmap = TMXTiledMap::create("/TileMaps/TestDesert.tmx");
	auto objects = tmap->getObjectGroup("Objects");
	
	ValueMap tower1 = objects->getObject("tower1"); ValueMap tower2 = objects->getObject("tower2");
	ValueMap tower3 = objects->getObject("tower3"); ValueMap tower4 = objects->getObject("tower4");
	ValueMap tower5 = objects->getObject("tower5"); ValueMap tower6 = objects->getObject("tower6");
	ValueMap tower7 = objects->getObject("tower7"); ValueMap tower8 = objects->getObject("tower8");
	ValueMap tower9 = objects->getObject("tower9"); ValueMap tower10 = objects->getObject("tower10");
	ValueMap tower11 = objects->getObject("tower11"); ValueMap tower12 = objects->getObject("tower12");
	
	t_x[0] = tower1["x"].asInt();    t_y[0] = tower1["y"].asInt();
	t_x[1] = tower2["x"].asInt();    t_y[1] = tower2["y"].asInt();
	t_x[2] = tower3["x"].asInt();    t_y[2] = tower3["y"].asInt();
	t_x[3] = tower4["x"].asInt();    t_y[3] = tower4["y"].asInt();
	t_x[4] = tower5["x"].asInt();    t_y[4] = tower5["y"].asInt();
	t_x[5] = tower6["x"].asInt();    t_y[5] = tower6["y"].asInt();
	t_x[6] = tower7["x"].asInt();    t_y[6] = tower7["y"].asInt();
	t_x[7] = tower8["x"].asInt();    t_y[7] = tower8["y"].asInt();
	t_x[8] = tower9["x"].asInt();    t_y[8] = tower9["y"].asInt();
	t_x[9] = tower10["x"].asInt();   t_y[9] = tower10["y"].asInt();
	t_x[10] = tower11["x"].asInt();  t_y[10] = tower11["y"].asInt();
	t_x[11] = tower12["x"].asInt();  t_y[11] = tower12["y"].asInt();

	switch (m_enumTower)
	{
	case enum_Archer:
	{
		for (int i = 0; i < 12; i++)
		{
			if (location.x > t_x[i] - 80 && location.x < t_x[i] + 50 && location.y > t_y[i] - 80 && location.y < t_y[i] + 80)
			{
				createTower_A(t_x[i], t_y[i]);
			}
		}
	}
	break;
	case enum_Knight:
	{
		for (int i = 0; i < 12; i++)
		{
			if (location.x > t_x[i] - 80 && location.x < t_x[i] + 50 && location.y > t_y[i] - 80 && location.y < t_y[i] + 80)
			{
				createTower_K(t_x[i], t_y[i]);
			}
		}
	}
	break;
	case enum_Magicion:
	{
		for (int i = 0; i < 12; i++)
		{
			if (location.x > t_x[i] - 80 && location.x < t_x[i] + 50 && location.y > t_y[i] - 80 && location.y < t_y[i] + 80)
			{
				createTower_M(t_x[i], t_y[i]);
			}
		}
	}
	break;
	}

	m_enumTower = enum_None;
	return true;
}

void StageOneScene::onTouchMoved(Touch* touch, Event* event)
{

}

void StageOneScene::TowerCallback(Ref* pSender)
{
	auto item = (MenuItem*)pSender;

	switch (item->getTag())
	{
	case TAG_TOWER_ARCHER:
	{
		m_enumTower = enum_Archer;
	}
	break;
	case TAG_TOWER_KNIGHT:
	{
		m_enumTower = enum_Knight;
	}
	break;
	case TAG_TOWER_MAGICION:
	{

		m_enumTower = enum_Magicion;
	}
	break;
	}
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(StageOneScene::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void StageOneScene::createTowerMenu()
{
	//auto Menu_Knight = MenuItemImage::create("/Tower/KnightMenu.png", "/Tower/KnightMenu2.png", StageOneScene::createTowerMenu, this));
	//auto Menu_Archer = MenuItemImage::create("/Tower/ArcherMenu.png", "/Tower/ArcherMenu2.png");
	//auto Menu_Magicion = MenuItemImage::create("/Tower/MagicionMenu.png", "/Tower/MagicionMenu2.png");
	//auto TowerMenu = MenuItemToggle::createWithCallback(CC_CALLBACK_1(StageOneScene::TowerCallback, this), Menu_Knight, Menu_Archer, Menu_Magicion, NULL);
	//auto objects = tmap->getObjectGroup("Objects");
	//ValueMap movePoint7 = objects->getObject("move7");
	////ValueMap movePoint6 = objects->getObject("move6");
	//int m_x7 = movePoint7["x"].asInt();
	//int m_y7 = movePoint7["y"].asInt();
	//int m_x6 = movePoint6["x"].asInt();
	//int m_y6 = movePoint6["y"].asInt();
	//TowerMenu->setPosition(200, 200);

	//Menu_Magicion->setPosition(m_x6, m_y6);
	//this->addChild(TowerMenu);
	//this->addChild(Menu_Magicion);
}



void StageOneScene::createTower_K(float touchX, float touchY)
{
	auto texture = Director::getInstance()->getTextureCache()->addImage("/Tower/knight.png");
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	animation->addSpriteFrameWithTexture(texture, Rect(33, 0, 60, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(160, 0, 75, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(290, 0, 75, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(410, 0, 75, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(530, 0, 110, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(785, 0, 85, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(920, 0, 75, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(1050, 0, 65, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(1185, 0, 70, 110));

	auto texture1 = Director::getInstance()->getTextureCache()->addImage("/Tower/Attack1_11.png");
	Tower_K = Sprite::createWithTexture(texture1, Rect(0, 0, 130, 130));


	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);


	Tower_K->setPosition(Vec2(touchX, touchY));
	this->addChild(Tower_K);
	Tower_K->runAction(rep);


}

void StageOneScene::createTower_A(float touchX, float touchY)
{
	auto texture = Director::getInstance()->getTextureCache()->addImage("/Tower/archer.png");
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	animation->addSpriteFrameWithTexture(texture, Rect(0, 0, 75, 75));
	animation->addSpriteFrameWithTexture(texture, Rect(133, 0, 66, 75));
	animation->addSpriteFrameWithTexture(texture, Rect(195, 0, 63, 75));
	animation->addSpriteFrameWithTexture(texture, Rect(257, 0, 58, 75));
	animation->addSpriteFrameWithTexture(texture, Rect(316, 0, 71, 75));
	animation->addSpriteFrameWithTexture(texture, Rect(387, 0, 70, 75));


	auto texture1 = Director::getInstance()->getTextureCache()->addImage("/Tower/shoot1.png");
	Tower_A = Sprite::createWithTexture(texture1, Rect(0, 0, 130, 130));


	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);


	Tower_A->setPosition(Vec2(touchX, touchY));
	this->addChild(Tower_A);
	Tower_A->runAction(rep);


}


void StageOneScene::createTower_M(float touchX, float touchY)
{
	auto texture = Director::getInstance()->getTextureCache()->addImage("/Tower/magician.png");
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.14f);

	animation->addSpriteFrameWithTexture(texture, Rect(300, 35, 75, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(430, 25, 75, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(550, 25, 70, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(685, 25, 55, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(815, 25, 62, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(940, 25, 60, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(1075, 25, 70, 110));
	animation->addSpriteFrameWithTexture(texture, Rect(1200, 25, 78, 110));


	auto texture1 = Director::getInstance()->getTextureCache()->addImage("/Tower/Magic.png");
	Tower_M = Sprite::createWithTexture(texture1, Rect(0, 0, 130, 130));


	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);


	Tower_M->setPosition(Vec2(touchX, touchY));
	this->addChild(Tower_M);
	Tower_M->runAction(rep);


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
		MoveTo::create(2, Vec2(400, 0)), MoveTo::create(2, Vec2(400, 50)), nullptr);
}

void StageOneScene::callEveryFrame(float f)
{
	nNum++;
	if (nNum>60)
	{
		nNum = 1;
	}
	log("fps...%d,nNum");
}
void StageOneScene::myTick(float f)
{
	log("tick******");
	
}
//
//double coll = pow(tower_x, 2.0) + pow(EnemyPosition.x, 2.0);
//double coll2 = pow(tower_y, 2.0) + pow(EnemyPosition.y, 2.0);
//double r_coll = sqrt(coll + coll2);