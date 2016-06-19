#ifndef YELLOWBIRD2
#define YELLOWBIRD2

#include "bird.h"

class YellowBird2 : public Bird
{
public:

    YellowBird2(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene);
};

#endif // YELLOWBIRD2

