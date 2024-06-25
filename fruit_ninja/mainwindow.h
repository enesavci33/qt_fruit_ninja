#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <karpuz.h>
#include <QFile>
#include <QMessageBox>
#include <QTimer>
#include <QList>
#include <QChar>
#include <QTime>
#include <QString>
#include <QStringList>

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    karpuz *krp;
    QList<karpuz*> obj;
    int j=30;
    int a=30;
    QStringList skorlar;





public slots:
    void karpuz_olustur();
    void hareket();
    void sure();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
