#ifndef WOOD_H
#define WOOD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define WOOD_DENSITY 6.0f
#define WOOD_FRICTION 0.8f
#define WOOD_RESTITUTION 0.5f

class Wood : public GameItem
{
public:
    Wood(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void collide();
    virtual void crack();
    //void setLinearVelocity(b2Vec2 velocity);
    QPixmap pixmap2;

};

#endif // WOOD_H
