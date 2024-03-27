#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsRectItem>
#include <QObject>

class score: public QGraphicsTextItem
{ Q_OBJECT
public:
    score();
    int currentscore;
    void increase();
    void decrease();
};

#endif // SCORE_H
