#include "Voyant_batterie.h"

Voyant_batterie::Voyant_batterie()
{
    valeur=0;

}


QRectF Voyant_batterie::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void Voyant_batterie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{


   QPixmap p3("/home/karim/Bureau/Karim/Icones/batterie.jpg");
   QPixmap p4("/home/karim/Bureau/Karim/Icones/essence.jpg");
   QPixmap p5("/home/karim/Bureau/Karim/Icones/tempmoteur.jpg");
//    QPixmap p6("/home/utilisateur/TDB/ceinture.jpg");
//    QPixmap p7("/home/utilisateur/TDB/portouverte.jpg");
//    QPixmap p8("/home/utilisateur/TDB/pleinphare.jpg");
//    QPixmap p9("/home/utilisateur/TDB/feucroisement.jpg");
//    QPixmap p10("/home/utilisateur/TDB/antibrouillard.jpg");
    painter->setRenderHints(QPainter::Antialiasing);

   // painter->drawPixmap(-500,-200,50,50,p1);
   // painter->drawPixmap(250,-200,50,50,p2);
    //painter->drawPixmap(-50,-20,50,50,p3);
    painter->drawPixmap(-300,-150,50,50,p4);
    painter->drawPixmap(45,-150,50,50,p5);

//    painter->drawPixmap(-120,-20,50,50,p6);
//    painter->drawPixmap(-200,-20,50,50,p7);
//    painter->drawPixmap(-200,-100,50,50,p9);
//    painter->drawPixmap(-120,-100,50,50,p8);
//    painter->drawPixmap(-50,-100,50,50,p10);

    if (getValue()==1){
         painter->drawPixmap(-50,-20,50,50,p3);
         //painter->drawPixmap(-500,-200,50,50,p1);
    }

}

