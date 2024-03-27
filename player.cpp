#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include <QAudioOutput>
#include <QMediaPlayer>
Player::Player()
{
    setPixmap(QPixmap(":/images/images/ship.png").scaled(140, 200));


}

void Player::keyPressEvent(QKeyEvent *event)
{

        // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
        setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
        setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+22,y()-90);
        scene()->addItem(bullet);
        QAudioOutput * lasersound= new QAudioOutput();
        lasersound->setVolume(50);
        QMediaPlayer *laser=new QMediaPlayer();
        laser->setAudioOutput(lasersound);
        laser->setSource(QUrl("qrc:/sounds/sounds/X2Download.app - Laser Shot Sound Effect (128 kbps).mp3"));
        laser->play();
    }


}
 // CreateEnemy function used to create the eneimes
void Player::createEnemy()
{ if (!isgameover)
    {Enemy* enemy = new Enemy();
        scene()->addItem(enemy);}

}
