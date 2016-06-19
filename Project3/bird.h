#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsPixmapItem>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.8f
#define BIRD_RESTITUTION 0.2f

class Bird : public GameItem
{
public:
    Bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void createBody();
    void setLinearVelocity(b2Vec2 velocity);
    virtual void superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene);
    b2BodyDef bodydef;
    b2FixtureDef fixturedef;
    float xPos;
    float yPos;
    float radius;
    virtual ~Bird();
    QGraphicsPixmapItem*smoke;
    QGraphicsScene *sceneForSmoke;

private:
};

#endif // BIRD_H
