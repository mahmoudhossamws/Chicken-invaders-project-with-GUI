#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"

Game::Game(QWidget *parent){
    setWindowTitle("Chicken Invaders");
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/images/space.jpg")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    myplayer=new class Player();
    myplayer->setFlag(QGraphicsItem::ItemIsFocusable);
    myplayer->setFocus();
    myplayer->setPos(400,600-180);
    scene->addItem(myplayer);

    score = new  class score();
    score->setPos(100,20);
    scene->addItem(score);
    health = new class health();
    health->setPos(600,20);
    scene->addItem(health);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),myplayer,SLOT(createEnemy()));
    timer->start(2000);

    show();
}
