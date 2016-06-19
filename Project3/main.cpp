#include "mainwindow.h"
#include <QApplication>
#include <score.h>

QMediaPlayer* birdPlayer;
QMediaPlayer* woodPlayer;
QMediaPlayer* pigPlayer;

Score* score;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
