#include "bluebird.h"
#include <iostream>

BlueBird::BlueBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
:Bird(x, y, radius, timer, pixmap, world, scene)
{
}

BlueBird::~BlueBird()
{
    delete naruto[0];
    delete naruto[1];
    //std::cout << "dtor";
}

void BlueBird::superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene)
{
    xPos = g_body->GetLinearVelocity().x;
    yPos = g_body->GetLinearVelocity().y; //xyPos doesn't mean position !

    naruto[0] = new Bird(pos.x,pos.y,0.3f,timer,QPixmap(":/blue.png").scaled(height/20.0,height/20.0),world,scene);
    naruto[0]->createBody();
    naruto[0]->g_body->SetLinearVelocity(b2Vec2(0.866*xPos - yPos/2 , xPos/2 + 0.866*yPos));

    naruto[1] = new Bird(pos.x,pos.y,0.3f,timer,QPixmap(":/blue.png").scaled(height/20.0,height/20.0),world,scene);
    naruto[1]->createBody();
    naruto[1]->g_body->SetLinearVelocity(b2Vec2(0.866*xPos + yPos/2 , -xPos/2 + 0.866*yPos));
}
