#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Score::increase(){
    score += 5000;
    setPlainText(QString("Score: ") + QString::number(score));

}

int Score::getScore(){
    return score;
}

void Score::resetScore()
{
    score = 0;
}
