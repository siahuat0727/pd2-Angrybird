#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTransform>
#include <QtMath>

class GameItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    GameItem(b2World *world, QGraphicsItem*parent =0);
    virtual ~GameItem();
    static void setGlobalSize(QSizeF worldsize, QSizeF windowsize);
    virtual void collide();
    virtual void crack();
    b2Body *g_body;
    b2Vec2 pos;
    QPointF mappedPoint;

public slots:
    void paint();

protected:
    QSizeF g_size;
    b2World *g_world;
    static QSizeF g_worldsize, g_windowsize;
    QGraphicsPixmapItem g_pixmap;
    int initialX;
    int initialY;
};

#endif // GAMEITEM_H
