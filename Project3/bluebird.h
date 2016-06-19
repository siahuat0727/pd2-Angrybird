#ifndef BLUEBIRD
#define BLUEBIRD

#include "bird.h"

class BlueBird : public Bird{
public:

    BlueBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    ~BlueBird();

    virtual void superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene);

    Bird * naruto[2];
};

#endif // BLUEBIRD

