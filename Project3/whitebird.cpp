#include "whitebird.h"
#include <iostream>
#include "egg.h"
#include <QMediaPlayer>

extern QMediaPlayer* birdPlayer;

WhiteBird::WhiteBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
:Bird(x, y, radius, timer, pixmap, world, scene)
{
}

WhiteBird::~WhiteBird()
{
    delete egg;
}

void WhiteBird::superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene)
{
    egg = new Egg(pos.x,pos.y,0.3f,timer,QPixmap(":/egg.png").scaled(height/16.0,height/16.0),world,scene);
    egg->createBody();
    egg->g_body->SetLinearVelocity(b2Vec2(0 ,-5));
    g_body->SetLinearVelocity(b2Vec2(10,20));

    birdPlayer->setMedia(QUrl("qrc:egg.mp3"));
    birdPlayer->play();
}
