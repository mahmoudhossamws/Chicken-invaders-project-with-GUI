#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include "player.h"
#include "Game.h"
#include "qapplication.h"
#include <QTimer>
#include <QDebug>
extern Game * game;
Enemy::Enemy() {

  setPixmap(QPixmap(":/images/images/chicken.png").scaled(80, 80));

        // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    setPos(random_number,0);

        // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
    qDebug()<<"inside constructor";

}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy:: move()
{

    setPos(x(),y()+5);

        if(y()+200>800)
    {
        game->score->decrease();
        game->health->decrease();
        scene()->removeItem(this);
            delete this;
    }
}

