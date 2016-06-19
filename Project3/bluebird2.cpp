#include "bluebird2.h"

BlueBird2::BlueBird2(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
:Bird(x, y, radius, timer, pixmap, world, scene)
{
}

BlueBird2::~BlueBird2()
{
    delete naruto[0];
    delete naruto[1];
    delete naruto[2];
    delete naruto[3];
}

void BlueBird2::superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene)
{
    xPos = g_body->GetLinearVelocity().x;
    yPos = g_body->GetLinearVelocity().y;

    naruto[0] = new Bird(pos.x,pos.y,0.3f,timer,QPixmap(":/blue2.png").scaled(height/20.0,height/20.0),world,scene);
    naruto[0]->createBody();
    naruto[0]->g_body->SetLinearVelocity(b2Vec2(0.866*xPos - yPos/2 , xPos/2 + 0.866*yPos));

    naruto[1] = new Bird(pos.x,pos.y,0.3f,timer,QPixmap(":/blue2.png").scaled(height/20.0,height/20.0),world,scene);
    naruto[1]->createBody();
    naruto[1]->g_body->SetLinearVelocity(b2Vec2(0.866*xPos + yPos/2 , -xPos/2 + 0.866*yPos));

    naruto[2] = new Bird(pos.x,pos.y,0.3f,timer,QPixmap(":/blue2.png").scaled(height/20.0,height/20.0),world,scene);
    naruto[2]->createBody();
    naruto[2]->g_body->SetLinearVelocity(b2Vec2(0.707*xPos - 0.707*yPos , 0.707*xPos + 0.707*yPos));

    naruto[3] = new Bird(pos.x,pos.y,0.3f,timer,QPixmap(":/blue2.png").scaled(height/20.0,height/20.0),world,scene);
    naruto[3]->createBody();
    naruto[3]->g_body->SetLinearVelocity(b2Vec2(0.707*xPos + 0.707*yPos , -0.707*xPos + 0.707*yPos));
}
