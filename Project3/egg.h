#ifndef EGG
#define EGG

#include "bird.h"

class Egg : public Bird{
public:

    Egg(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void createBody();

};

#endif // EGG

