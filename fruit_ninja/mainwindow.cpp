#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "karpuz.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QTimer *timer =new QTimer(this);
    timer->start(1000);
    connect(timer,&QTimer::timeout,this,&MainWindow::karpuz_olustur);
    QTimer *timer2 =new QTimer(this);
    timer2->start(700);
    connect(timer2,&QTimer::timeout,this,&MainWindow::hareket);
    QTimer *timer3 =new QTimer(this);
    timer3->start(1000);
    connect(timer3,&QTimer::timeout,this,&MainWindow::sure);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::karpuz_olustur()
{
    int x,y;
    int sayac=0;

    if(ui->label_2->text()!="0")
    {
        QStringList konumlar,konumlar2;
        QFile my_file("C:/Qt Dosyalari/odevvv/konumlar.txt");
        if(!my_file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this,"hata",my_file.errorString());
            return;
        }
        QTextStream dosya(&my_file);
        while(!dosya.atEnd())
        {
            QString satir=dosya.readLine();
            konumlar.append(satir);
        }
        my_file.close();
        int a;
        srand(time(NULL));
        a=rand()%30;
        konumlar2=konumlar[a].split(" ");
        x=konumlar2[0].toInt();
        y=konumlar2[1].toInt();
        karpuz *krp =new karpuz(this);
        obj.push_back(krp);
        krp->setGeometry(x,y,50,50);
        krp->setStyleSheet("border-image: url(:/resimler/1.png);");
        krp->show();
        ui->label_kac->setText("0");
        ui->label_kes->setText("0");
        for(int i=0;i<obj.size();i++)
        {
            if(obj[i]->tiklama)
            {
                sayac+=1;
                ui->label_kac->setText(QString::number(obj.size()-sayac));
                ui->label_kes->setText(QString::number(sayac));
            }
        }
    }

}

void MainWindow::hareket()
{
    if(ui->label_2->text()!="0")
    {
        int sayi=obj.size();
        for(int i=0;i<sayi;i++)
        {
            obj[i]->setGeometry(obj[i]->x(),obj[i]->y()+10,50,50);
        }
    }
}
void MainWindow::sure()
{
    j=j-1;
    ui->label_2->setText(QString::number(j));

    if(j==0)
    {
        QStringList skorlar;
        QFile my_file2("C:/Qt Dosyalari/odevvv/skorlar.txt");
        if(!my_file2.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this,"hata",my_file2.errorString());
            return;
        }
        QTextStream dosya2(&my_file2);
        while(!dosya2.atEnd())
        {
            QString satir=dosya2.readLine();
            skorlar.append(satir);
        }
        my_file2.close();
        int en_b=skorlar[0].toInt();
        for(int i=0;i<skorlar.size();i++)
        {
            if(skorlar[i].toInt()>en_b)
            {
                en_b=skorlar[i].toInt();
            }
        }
        if(ui->label_kes->text().toInt()>en_b)
        {
            en_b=ui->label_kes->text().toInt();
            skorlar.append(QString::number(en_b));
            QMessageBox::information(this,"Tebrikler.Maksimum skoru geçtiniz.Oyun bitti.","Kaçırılan->"+
                                            ui->label_kac->text()+"\n"+"Kesilen->"+ui->label_kes->text()
                                                                                                +"\n"+"Maksimum skor->"+QString::number(en_b));
            QFile my_file3("C:/Qt Dosyalari/odevvv/skorlar.txt");
            if(!my_file3.open(QIODevice::WriteOnly))
            {
                QMessageBox::critical(this,"hata",my_file3.errorString());
                return;
            }
            QTextStream dosya3(&my_file3);
            for(int a=0;a<skorlar.size();a++)
            {
                dosya3 << skorlar[a]+"\n";
            }
            my_file3.close();
            close();


        }
        else
        {
            skorlar.append(ui->label_kes->text());
            QMessageBox::information(this,"Üzgünüz maksimum skoru geçemediniz.Oyun bitti.","Kaçırılan->"+
                                            ui->label_kac->text()+"\n"+"Kesilen->"+ui->label_kes->text()
                                                                                                 +"\n"+"Maksimum skor->"+QString::number(en_b));

            QFile my_file4("C:/Qt Dosyalari/odevvv/skorlar.txt");
            if(!my_file4.open(QIODevice::WriteOnly))
            {
                QMessageBox::critical(this,"hata",my_file4.errorString());
                return;
            }
            QTextStream dosya4(&my_file4);
            for(int b=0;b<skorlar.size();b++)
            {
                dosya4 << skorlar[b]+"\n";
            }
            my_file4.close();

            close();
        }
    }
}




