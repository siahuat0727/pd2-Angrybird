#include "whitebird2.h"
#include <iostream>
#include "egg.h"
#include <QMediaPlayer>

extern QMediaPlayer* birdPlayer;

WhiteBird2::WhiteBird2(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
:Bird(x, y, radius, timer, pixmap, world, scene)
{
}

WhiteBird2::~WhiteBird2()
{
    for(int i = 0; i < 9; ++i)
     delete egg[i];
}

void WhiteBird2::superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene)
{
    for(int i = 0; i < 9; ++i){
        egg[i] = new Egg(pos.x,pos.y,0.3f,timer,QPixmap(":/egg.png").scaled(height/16.0,height/16.0),world,scene);
        egg[i]->createBody();
        egg[i]->g_body->SetLinearVelocity(b2Vec2(3*(i-4) ,-10));
    }
    g_body->SetLinearVelocity(b2Vec2(15,30));

    birdPlayer->setMedia(QUrl("qrc:egg.mp3"));
    birdPlayer->play();

}
