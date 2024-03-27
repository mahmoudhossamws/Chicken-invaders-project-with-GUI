
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include "score.h"
#include "health.h"
#include "Game.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
Game * game;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    game = new Game();
    game->show();



    return a.exec();
}
