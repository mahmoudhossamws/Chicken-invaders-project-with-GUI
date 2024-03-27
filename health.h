#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsRectItem>
#include <QObject>

class health:  public QGraphicsTextItem
{ Q_OBJECT
public:
    health();
    int currenthealth;
    void increase();
    void decrease();
    void gameover();
};

#endif // HEALTH_H
