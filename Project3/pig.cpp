#include "pig.h"
#include "mainwindow.h"
#include "score.h"
#include <QMediaPlayer>

extern QMediaPlayer* pigPlayer;
extern Score* score;

Pig::Pig(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
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
    fixturedef.density = PIG_DENSITY;
    fixturedef.friction = PIG_FRICTION;
    fixturedef.restitution = PIG_RESTITUTION;
    g_body->SetAngularDamping(10);
    g_body->CreateFixture(&fixturedef);

    scene->addItem(&g_pixmap);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
}

void Pig::crack()
{
    score->increase();
    pigPlayer->setMedia(QUrl("qrc:pig.mp3"));
    pigPlayer->play();
    delete this;
}

