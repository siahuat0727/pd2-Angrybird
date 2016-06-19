#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2WorldCallbacks.h>
#include <QMouseEvent>
#include <iostream>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <wood.h>
#include <contact.h>
#include <pig.h>
#include <yellowbird.h>
#include <bluebird.h>
#include <whitebird.h>
#include <yellowbird2.h>
#include <bluebird2.h>
#include <whitebird2.h>
#include <button.h>
#include <score.h>
#include <QString>
#include <string>
#include <cstring>
#include <string.h>

#define NUM_OF_BIRD 7

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);

signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void quit();
    void start();
    void restart();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QList<GameItem *> itemList;
    Button* playButton;
    Button* quitButton;
    QGraphicsTextItem* text;
    b2World *world;
    QTimer timer;
    int index;

    void gameOver(bool win);

    bool press;
    bool started;
    bool super;

    Bird *birdie;
    Bird *bird[9];
    Pig *pig[1];

    float x;
    float y;
    float initialX;
    float initialY;
};

#endif // MAINWINDOW_H
