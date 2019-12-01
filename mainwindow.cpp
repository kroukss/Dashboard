#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include "CadranVitesse.h"
#include <cadranEss.h>

#include <QDebug>
#include "karim_scene.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 2222);
    connect(server,SIGNAL(newConnection()),this, SLOT(connexion()));
    dashboard = new karim_scene;
    ui->graphicsView->setScene(dashboard);

    ui->graphicsView->setBackgroundBrush(Qt::black);
    ui->graphicsView->show();
    ui->graphicsView->setSceneRect(-400,-250,500,500);

    ui->pushButton_gauche->setCheckable(true);
    ui->pushButton_droit->setCheckable(true);

    ui->pushButton_warning->setIcon(QIcon("/home/utilisateur/TDB/warning.png"));
    ui->pushButton_warning->setIconSize(QSize(230,114));
}

void MainWindow::connexion()
{
    socket = this->server->nextPendingConnection();
    qDebug() << "connexion etablie";
    connect(socket, SIGNAL(readyRead()),this, SLOT(reception()));
}
void MainWindow::reception()
{
    QString string(socket->readAll());
    QString message = string.section(' ',0,1);
    if(message=="CANN SPEED"){
        int vitesse = string.section(' ', 2,2).toInt();
        if(vitesse>=0 && vitesse <= dashboard->Vitesse->getValueMax()){
            dashboard->Vitesse->setValue(vitesse);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
            vitesse_actuelle=vitesse;
        }
        else{
            QString text;
            text = QString("vitesse incorrect, vitesse comprise entre 0 et %1").arg(dashboard->Vitesse->getValueMax());
            socket->write(text.toUtf8());
        }
    }
    if(message=="CANN BATTERY_LIGHT"){
        int battery_on = string.section(' ', 2,2).toInt();
        if(battery_on==0 || battery_on==1){
            dashboard->VoyantBatterie->setValue(battery_on);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("valeur incorrecte, doit être égale à 0 ou 1");
            socket->write(text.toUtf8());
          }
    }

    if(message=="CANN RPM"){
        int rpm = string.section(' ', 2,2).toInt();
        if(rpm>=0 && rpm <= dashboard->CompteTours->getValueMax()){
            dashboard->CompteTours->setValue(rpm);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("rpm incorrect, vitesse comprise entre 0 et %1").arg(dashboard->CompteTours->getValueMax());
            socket->write(text.toUtf8());
        }
    }

  if(message=="CANN GAZ"){
        int essence = string.section(' ', 2,2).toInt();
        if(essence>=0 && essence <= dashboard->Essence->getValueMax()){
            dashboard->Essence->setValue(essence);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("Quantité incorrect, quantité comprise entre 0 et %1").arg(dashboard->Essence->getValueMax());

            socket->write(text.toUtf8());
            }
    }
    else if(message=="CANN TURN"){
        int cligno = string.section(' ', 2,2).toInt();
        if(cligno>=-1 && cligno <= 1){
            dashboard->Clignotant->setValue(cligno);
           // ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toLocal8Bit());
        }
        else{
            QString text;

            text = QString("Incorrect -1=>gauche 0=>null 1=>droite");
            socket->write(text.toLocal8Bit());
        }
    }

    else if(message=="CANN DASHBOARD"){
        QStringList PRENOMS;
        PRENOMS<<"HUGO"<<"HENRI" << "JONAS"<<"KARIM";
        QString prenom = string.section(' ', 2,2);
        if (PRENOMS.contains(prenom)==true){
            if (prenom=="KARIM"){
                delete dashboard;
                dashboard =new karim_scene;
                ui->graphicsView->setScene(dashboard);
            }
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("Cette scène n'existe pas.");
            socket->write(text.toUtf8());
        }
    }
  /*  else if(message=="CANN LIGHT"){
        int light = string.section(' ', 2,2).toInt();

        if(light>=0 && light <= 3){
            switch (light) {
            case 1:
                dashboard->position->setValue(1);
                dashboard->croisement->setValue(0);
                dashboard->route->setValue(0);
                break;
            case 2:
                dashboard->position->setValue(0);
                dashboard->croisement->setValue(1);
                dashboard->route->setValue(0);

                break;
            case 3:
                dashboard->position->setValue(0);
                dashboard->croisement->setValue(0);
                dashboard->route->setValue(1);

                break;
             default:
                dashboard->position->setValue(0);
                dashboard->croisement->setValue(0);
                dashboard->route->setValue(0);
                break;

            }
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("valeur incorrect, valeur entre 0 et 3").arg(dashboard->Essence->getValueMax());
            socket->write(text.toUtf8());
        }
    }
    else if(message=="CANN WARNING"){
        int warning = string.section(' ', 2,2).toInt();
        if(warning>=0 && warning <= 1){
            dashboard->warning->setValue(warning);
            dashboard->Clignotant->setValue(2*warning);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("Quantité incorrect, vitesse comprise entre 0 et %1").arg(dashboard->Essence->getValueMax());
            socket->write(text.toUtf8());
        }
    }*/

    else
        qDebug() << "erreur lors de la reception du message";

}

void MainWindow::update_km()
{
    km_parcourus+=1.0*(vitesse_actuelle)/3600;
    //dashboard->CompteurKm->setValue(km_parcourus);
    ui->graphicsView->scene()->update();
}


MainWindow::~MainWindow()
{
    delete ui;
}
