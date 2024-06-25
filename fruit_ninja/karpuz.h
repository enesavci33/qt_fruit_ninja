#ifndef KARPUZ_H
#define KARPUZ_H

#include <QPushButton>
#include <QWidget>
#include <QTimer>
class karpuz : public QPushButton
{
    Q_OBJECT
public:
    karpuz(QWidget *parrent=0);
    karpuz *krp;
    bool tiklama;

public slots:
    void tikla();
    void sil();
};


#endif // KARPUZ_H
