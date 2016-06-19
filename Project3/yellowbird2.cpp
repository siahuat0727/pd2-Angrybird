#include "yellowbird2.h"
#include <QMediaPlayer>

extern QMediaPlayer* birdPlayer;

YellowBird2::YellowBird2(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
:Bird(x, y, radius, timer, pixmap, world, scene)
{
}

void YellowBird2::superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene)
{
    g_body->SetLinearVelocity(b2Vec2(g_body->GetLinearVelocity().x * 10, g_body->GetLinearVelocity().y * 10));\

    birdPlayer->setMedia(QUrl("qrc:yellow.mp3"));
    birdPlayer->play();
}
