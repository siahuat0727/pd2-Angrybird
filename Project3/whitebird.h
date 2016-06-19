#ifndef WHITEBIRD
#define WHITEBIRD

#include "bird.h"

class WhiteBird : public Bird
{
public:

    WhiteBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual ~WhiteBird();
    virtual void superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene);

    Bird * egg;
};

#endif // WHITEBIRD

