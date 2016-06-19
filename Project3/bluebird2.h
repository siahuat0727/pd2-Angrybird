#ifndef BLUE2
#define BLUE2

#include "bird.h"

class BlueBird2 : public Bird{
public:

    BlueBird2(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    ~BlueBird2();

    virtual void superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene);

    Bird * naruto[4];
};

#endif // BLUE2

