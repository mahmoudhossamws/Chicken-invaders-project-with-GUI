#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include "qapplication.h"
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include "score.h"
#include "health.h"
#include "Game.h"
extern Game * game;
health::health() {
    currenthealth=3;
    setFont(QFont("times",16));
    setDefaultTextColor(Qt::green);
    setPlainText("Health: "+QString::number(currenthealth));
    setPos(500,20);
}
void health:: decrease()
{
    currenthealth--;
    setPlainText("Health: "+QString::number(currenthealth));
    if(currenthealth==0)
    {
        gameover();
    }
}
void health:: increase()
{
    // Maybe we will want to develop it to make health able to increase
}
void health::gameover()
{
  //  game->myplayer->isgameover=true;
  //  game->scene->removeItem(game->myplayer);
    // game->scene->removeItem(game->score);
   // game->scene->removeItem(game->health);
  game->scene->clear();
    QMessageBox::about(game,"GAME OVER       ","You lost              \n Score: " +QString::number(game->score->currentscore));
}
