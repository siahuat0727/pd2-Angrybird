#include "bird.h"
#include "mainwindow.h"
#include <QMediaPlayer>

extern QMediaPlayer* birdPlayer;

Bird::Bird(float x, float y, float r, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
:GameItem(world),xPos(x), yPos(y), radius(r), sceneForSmoke(scene)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    mappedPoint.setX(((x - g_size.width()/2) * g_windowsize.width())/g_worldsize.width());
    mappedPoint.setY((1.0f - (y + g_size.height()/2)/g_worldsize.height()) * g_windowsize.height());
    g_pixmap.setPos((((x - g_size.width()/2) * g_windowsize.width())/g_worldsize.width(),100),(1.0f - (y + g_size.height()/2)/g_worldsize.height()) * g_windowsize.height());
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);

    scene->addItem(&g_pixmap);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
}

void Bird::createBody()
{
    // Create Body
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(mappedPoint.x() * g_worldsize.width() / g_windowsize.width() + g_size.width()*2, (1.0f - mappedPoint.y()/g_windowsize.height())*g_worldsize.height()+g_size.height());
    bodydef.userData = this;
    bodydef.allowSleep = false;
    g_body = g_world->CreateBody(&bodydef);
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    birdPlayer->setMedia(QUrl("qrc:fly.mp3"));
    birdPlayer->play();
/*
    smokeTimer = new QTimer();
    connect(smokeTimer,SIGNAL(timeout()),this,SLOT(addSmoke()));
    smokeTimer->start(100/6);
    */

    smoke = new QGraphicsPixmapItem();
    smoke->setPos(mappedPoint.x(),mappedPoint.y());
    smoke->setPixmap(QPixmap(":/smoke.png"));
    sceneForSmoke->addItem(smoke);
}

void Bird::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}

void Bird::superPower(QTimer *timer, int height, b2World *world, QGraphicsScene *scene)
{

}

Bird::~Bird()
{
    delete smoke;
}
