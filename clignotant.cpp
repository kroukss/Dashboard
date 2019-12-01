#include "clignotant.h"
#include <QPainter>
#include "voyants.h"
#include <QTest>

clignotant::clignotant(QGraphicsItem *parent)
{
    value=0;
    cligno=0;
}

QRectF clignotant::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void clignotant::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{

    painter->setRenderHint(QPainter::Antialiasing);

    if (getValue() !=0)
    {
        if (getValue()==-1){
            QPixmap image("/home/karim/Bureau/Karim/Icones/clignotg.jpg");
            QPixmap image2=image.scaled(30,30);
            painter->setOpacity(cligno);
            painter->drawPixmap(-500,-200,50,50,image2);
        }
        if (getValue()==1){
            QPixmap image("/home/karim/Bureau/Karim/Icones/clignotd.jpg");
            QPixmap image2=image.scaled(30,30);
            painter->setOpacity(cligno);
            painter->drawPixmap(250,-200,50,50,image2);
        }
        if (getValue()==2){
            QPixmap image("/home/karim/Bureau/Karim/Icones/clignotd.jpg");
            QPixmap image2=image.scaled(30,30);
            painter->setOpacity(cligno);
            painter->drawPixmap(250,-200,50,50,image2);

            QPixmap image3("/home/karim/Bureau/Karim/Icones/clignotg.jpg");
            QPixmap image4=image3.scaled(30,30);
            painter->setOpacity(cligno);
            painter->drawPixmap(-500,-200,50,50,image4);
        }

    MAJ();
    }
}
void clignotant::MAJ()
{
   if (this->cligno==1){
    this->cligno=0;
   }
   else{
       this->cligno=1;
   }
    QTest::qWait(500);
    update();
}
