#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <CadranVitesse.h>
#include <cadrantourparmin.h>
#include <cadranEss.h>
#include <voyants.h>
#include <QTimer>
#include <QMainWindow>
#include "karim_scene.h"
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
   void connexion();
   void reception();
    void update_km();

private:
    Ui::MainWindow *ui;
    QTcpServer * server;
    QTcpSocket * socket;
    QTimer *updateTimer;
    karim_scene *dashboard;
    int vitesse_actuelle=0;
    float km_parcourus=0;
};

#endif // MAINWINDOW_H
