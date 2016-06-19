#include "gameitem.h"
#include <iostream>


GameItem::GameItem(b2World *world, QGraphicsItem* parent):
    g_body(NULL),g_world(world),QGraphicsPixmapItem(parent),initialX(0),initialY(0)
{
}

GameItem::~GameItem()
{
    if(g_body != NULL)
        g_world->DestroyBody(g_body);
}

QSizeF GameItem::g_windowsize = QSizeF();
QSizeF GameItem::g_worldsize = QSizeF();

void GameItem::setGlobalSize(QSizeF worldsize, QSizeF windowsize)
{
    g_worldsize = worldsize;
    g_windowsize = windowsize;
}

void GameItem::paint()
{
    if(g_body == NULL){
        g_pixmap.setPos(mappedPoint);
        g_pixmap.resetTransform();
        return;
    }

    pos = g_body->GetPosition();

    mappedPoint.setX(((pos.x - g_size.width()/2) * g_windowsize.width())/g_worldsize.width());
    mappedPoint.setY((1.0f - (pos.y + g_size.height()/2)/g_worldsize.height()) * g_windowsize.height());
    g_pixmap.setPos(mappedPoint);
    g_pixmap.resetTransform();
    g_pixmap.setRotation(-(g_body->GetAngle()*180/3.14159));
    if(initialX == 0){
        initialX = mappedPoint.x();
        initialY = mappedPoint.y();
    }


    if(((initialX - mappedPoint.x())*((initialX - mappedPoint.x())) + (initialY - mappedPoint.y())*((initialY - mappedPoint.y())))>= 20){
        collide();
        return;
    }

    if(((initialX - mappedPoint.x())*((initialX - mappedPoint.x())) + (initialY - mappedPoint.y())*((initialY - mappedPoint.y())))>= 2.8)
        crack();


    initialX = mappedPoint.x();
    initialY = mappedPoint.y();
}
/*
void GameItem::addSmoke()
{

    if(i < 30){
        smoke[i] = new QGraphicsPixmapItem();
        smoke[i]->setPos(mappedPoint.x(),mappedPoint.y());
        smoke[i]->setPixmap(QPixmap(":/smoke.png"));
        scene->addItem(smoke[i++]);
    }

}
*/
void GameItem::collide()
{

}

void GameItem::crack()
{

}
