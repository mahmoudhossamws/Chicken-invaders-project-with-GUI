#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>
#include "score.h"
#include "health.h"
#include "Game.h"
#include <QAudioOutput>
#include <QMediaPlayer>
extern Game * game;
Bullet::Bullet():QObject(), QGraphicsPixmapItem() {

        // *******  Setting the bullets' size ********
    setPixmap(QPixmap(":/images/images/redlaser.png").scaled(100, 120));

        // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}

// Move function is used to 1-  move the bullet upwards
                         // 2- Handle the collision of the bullets with enemies
void Bullet:: move()
{
    QList<QGraphicsItem *> coliding_items=collidingItems();
    for (int i=0,n=coliding_items.size();i<n;i++)
    {
        if (typeid(*(coliding_items[i]))==typeid(Enemy))
        {
            QAudioOutput * chickensound= new QAudioOutput();
            chickensound->setVolume(50);
            QMediaPlayer *chicken=new QMediaPlayer();
            chicken->setAudioOutput(chickensound);
            chicken->setSource(QUrl("qrc:/sounds/sounds/Chicken Scream Noise - Sound Effect for editing.mp3"));
            chicken->play();
            game->score->increase();
            scene()->removeItem(coliding_items[i]);
                scene()->removeItem(this);
            delete coliding_items[i];
                delete this;
            return;
        }
    }
    setPos(x(),y()-10);
    if(y()+160<0)
    {
        scene()->removeItem(this);
        delete this;
    }

        // *******  Getting the colliding items with the Bullet ********


        // *******  Moving the bullets upward ********

}
