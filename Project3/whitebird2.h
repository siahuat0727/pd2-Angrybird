#ifndef WHITEBIRD2
#define WHITEBIRD2

#include "bird.h"

class WhiteBird2 : public Bird
{
public:

    WhiteBird2(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    ~WhiteBird2();
    virtual void superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene);

    Bird * egg[7];
};

#endif // WHITEBIRD2

