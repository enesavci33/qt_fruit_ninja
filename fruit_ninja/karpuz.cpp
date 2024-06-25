#include "karpuz.h"


karpuz::karpuz(QWidget *parrent): QPushButton(parrent)
{
    connect(this,&QPushButton::clicked,this,&karpuz::tikla);
    tiklama=false;
}

void karpuz::tikla()
{
    setStyleSheet("border-image: url(:/resimler/2.png);");
    QTimer *timer =new QTimer(this);
    timer->start(500);
    connect(timer,&QTimer::timeout,this,&karpuz::sil);
    tiklama=true;

}

void karpuz::sil()
{

    close();
}


