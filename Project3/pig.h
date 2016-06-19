#ifndef PIG
#define PIG

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define PIG_DENSITY 5.0f
#define PIG_FRICTION 0.5f
#define PIG_RESTITUTION 0.5f

class Pig : public GameItem
{
public:
    Pig(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void crack();
    b2BodyDef bodydef;
    b2FixtureDef fixturedef;

};

#endif // PIG

