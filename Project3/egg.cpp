#include "egg.h"

Egg::Egg(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
:Bird(x, y, radius, timer, pixmap, world, scene)
{
}

void Egg::createBody()
{
    // Create Body
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(mappedPoint.x() * g_worldsize.width() / g_windowsize.width() + g_size.width()*2, (1.0f - mappedPoint.y()/g_windowsize.height())*g_worldsize.height()+g_size.height());
    bodydef.userData = this;
    bodydef.allowSleep = false;
    g_body = g_world->CreateBody(&bodydef);
    b2CircleShape bodyshape;
    bodyshape.m_radius = 0.2f;
    fixturedef.shape = &bodyshape;
    fixturedef.density = 1000;
    fixturedef.friction = 0.5f;
    fixturedef.restitution = 0.4f;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

}
