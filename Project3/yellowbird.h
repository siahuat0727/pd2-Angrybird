#ifndef YELLOWBIRD
#define YELLOWBIRD

#include "bird.h"

class YellowBird : public Bird
{
public:

    YellowBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene);
};

#endif // YELLOWBIRD

