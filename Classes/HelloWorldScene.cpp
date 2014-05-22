#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !LayerColor::initWithColor(Color4B(255, 255, 255, 255)) )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /*
    auto sprite = Sprite::create("girl.png");
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    */

    //auto *action = MoveTo::create(1.0f, Point(200, 100));
    //auto *actionMove = MoveTo::create(1.0f, Point(200, 100));
    //auto *action = MoveBy::create(1.0f, Point(200, 100));
    //auto *action = RotateBy::create(2.0f, 720.0f);
    //sprite->runAction(*action);

    //auto *ease = EaseCubicActionInOut::create(action);
    //auto *ease = EaseCircleActionInOut::create(action);
    //auto *ease = EaseBackInOut::create(action);
    //sprite->runAction(ease);


    /*
    auto *actionMove = MoveTo::create(1.0f, Point(200, 100));
    auto *actionRotate = EaseBackInOut::create(RotateBy::create(1.0f, 720.0f));
    auto *seq = Sequence::create(
        Spawn::create(actionMove, actionRotate, nullptr),
        EaseBackInOut::create(RotateBy::create(3.0f, -720.0f)),
        EaseElasticOut::create(MoveTo::create(1.0f, Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y))),
        nullptr
    );
    sprite->runAction(RepeatForever::create(seq));
    */

    this->chapter5_2();
    
    return true;
}

void HelloWorld::chapter5_2()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /*
    auto sprite = Sprite::create("girl-frames/girl-frames-0.png");
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);

    auto *animation = Animation::create();
    for (int i = 0; i <= 13; i++) {
        animation->addSpriteFrameWithFile(StringUtils::format("girl-frames/girl-frames-%d.png", i));
    }
    animation->setRestoreOriginalFrame(true);   // 最初の画像に戻すかどうか
    animation->setDelayPerUnit(0.5f / 4.0f);
    */
    
    auto sprite = Sprite::create();
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);

    const int IMAGE_SIZE_W = 250;
    const int IMAGE_SIZE_H = 419;
    auto *animation = Animation::create();
    for (int i = 0; i <= 13; i++) {
        animation->addSpriteFrame(SpriteFrame::create("girl-frames/girl-frames-tiled.png", Rect(IMAGE_SIZE_W * i, 0, IMAGE_SIZE_W, IMAGE_SIZE_H)));
    }
    animation->setDelayPerUnit(0.5f / 4.0f);

    auto *animate = Animate::create(animation);
    auto *animated = RepeatForever::create(animate);
    sprite->runAction(animated);
}

