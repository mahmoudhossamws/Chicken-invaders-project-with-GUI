#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer

#include "main.cpp"
#include "qapplication.h"
#include <QTimer>
#include <QDebug>
#include "score.h"

score::score() {
    currentscore=0;
    setFont(QFont("times",16));
    setDefaultTextColor(Qt::blue);
    setPlainText("Score: "+QString::number(currentscore));
    setPos(100,20);
}
void score:: decrease()
{
    if (currentscore>0)
    currentscore--;
    setDefaultTextColor(Qt::red);
    setPlainText("Score: "+QString::number(currentscore));
}
void score:: increase()
{
    currentscore++;
    setDefaultTextColor(Qt::blue);
    setPlainText("Score: "+QString::number(currentscore));
}
