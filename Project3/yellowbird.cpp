#include "yellowbird.h"
#include <iostream>
#include <QMediaPlayer>

extern QMediaPlayer* birdPlayer;

YellowBird::YellowBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
:Bird(x, y, radius, timer, pixmap, world, scene)
{
}

void YellowBird::superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene)
{
    g_body->SetLinearVelocity(b2Vec2(g_body->GetLinearVelocity().x * 4, g_body->GetLinearVelocity().y * 4));

    birdPlayer->setMedia(QUrl("qrc:yellow.mp3"));
    birdPlayer->play();

}
