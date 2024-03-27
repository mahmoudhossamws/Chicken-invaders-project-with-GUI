#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include "score.h"
#include "health.h"

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
public:
    void keyPressEvent(QKeyEvent * event);
    bool isgameover=false;
public slots:
    void createEnemy();

};

#endif // PLAYER_H
