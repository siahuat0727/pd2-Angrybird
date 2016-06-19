#include "wood.h"
#include <iostream>
#include <typeinfo>
#include <bird.h>
#include <QMediaPlayer>

extern QMediaPlayer* woodPlayer;

Wood::Wood(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world),pixmap2(":/wood2.png")
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(w,h);

    // Create body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.bullet = true;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w,h);
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyBox;
    fixturedef.density = WOOD_DENSITY;
    fixturedef.friction = WOOD_FRICTION;
    fixturedef.restitution = WOOD_RESTITUTION;
    g_body->SetAngularDamping(10);
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&g_pixmap);
}

void Wood::collide()
{
    woodPlayer->setMedia(QUrl("qrc:collide.mp3"));
    woodPlayer->play();
    delete this;
}

void Wood::crack()
{
    woodPlayer->setMedia(QUrl("qrc:crack.mp3"));
    woodPlayer->play();
    g_pixmap.setPixmap(pixmap2.scaled(33.75,33.75));
}
