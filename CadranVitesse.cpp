#include "CadranVitesse.h"
#include "qmath.h"
#include <QFont>
#include <QDateTime>
#include <QFontDatabase>

#include <QLine>

CadranVitesse::CadranVitesse(QGraphicsItem *parent)
{
    vitesse=0;
    value=270; //Vitesse max
}

QRectF CadranVitesse::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void CadranVitesse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{


QRect carre[13];
   for (int i=0;i<13;i++)
    {
        carre[i]=QRect(-200+i*5,-200+i*5,400-i*10,400-i*10);
    }

  // Design du cercle aiguille
  QRadialGradient radialGrad(QPointF(-50, 100), 400);
         radialGrad.setColorAt(0, Qt::black);
         radialGrad.setColorAt(1, Qt::gray);
   painter->setBrush(radialGrad);
   painter->setPen(QPen(QBrush("darkGray"),4,Qt::SolidLine));
   painter->setRenderHints(QPainter::Antialiasing);
   painter->drawEllipse(-20,-20,40,40);

   //Design du cadran vitesse
   for (int i=5;i>0;i--)
    {
        painter->setPen(QPen(QBrush("gray") , i, Qt::SolidLine,Qt::FlatCap));
        painter->setRenderHints(QPainter::Antialiasing);
        painter->drawArc(carre[4],300*16,300*16);
        painter->drawLine(92, 155, -92, 155);
        painter->setPen(QPen(QBrush("blue") , i, Qt::SolidLine,Qt::FlatCap));
        painter->drawArc(carre[2],300*16,300*16);
        painter->drawLine(96, 165, -96, 165);
    }

    //Ajout des traits
    painter->setPen(QPen(QBrush("white") , 10, Qt::SolidLine,Qt::FlatCap));

    int k=2;
     for (float i=225;i>-46;i-=10.0*270/value)
         {
         if(k%2==0)
            painter->drawArc(carre[6],i*16,8*4);
         else
             painter->drawArc(carre[6],i*16,8);
          k++;
         }

    //Ajout des graduations
    painter->setPen(QPen(QBrush("white") ,10, Qt::SolidLine,Qt::FlatCap));
    painter->drawText(QRectF(-200,-100,400,400),Qt::AlignCenter,"Km/h");
     float pi=3.1415;
     int j=0;
     for (float i=35*pi/28;i>=-7*pi/28;i-=12*pi/(27*4)*270/(value+1))
     {
         painter->drawText(qCos(i)*145-6,-qSin(i)*145+6,QString("%1").arg(j*2));
         j+=10;
     }

    //Design de l'aiguille
     painter->rotate(angle);
     painter->setPen(QPen( Qt::darkRed , 8, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
     painter->drawLine(0, 0, 0, -170);
     painter->setRenderHints(QPainter::Antialiasing);
     painter->rotate(-angle);

    //Design du rectangle
     painter->setPen(QPen( Qt::black , 2, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
     QRadialGradient radialGrad2(QPointF(-100, 0), 300);
           radialGrad2.setColorAt(0, QColor(0, 128, 255));
           radialGrad2.setColorAt(1, Qt::cyan);
     painter->setBrush(radialGrad2);

     painter->translate(405,45);
     painter->drawRect(-200,-70,190,190);
     painter->drawLine(-200,25,0,25);

     //Ajout d'une police LCD
     int id = QFontDatabase::addApplicationFont(":/LCDfont.ttf");
     QString family = QFontDatabase::applicationFontFamilies(id).at(0);
     QFont F(family);
     F.setPixelSize(33);
     painter->setFont(F);
     painter->setPen(QPen(Qt::darkBlue));

     //Ajout de l'heure
     painter->drawText(QRectF(-50,-30,-135,200),Qt::AlignCenter,QString("%1 km/h").arg(angle-225));
     QString sDate = QDateTime::currentDateTime().toString("hh:mm");
     painter->drawText(QRectF(-50,-120,-100,200),Qt::AlignCenter,QString("%1").arg(sDate));

}

int CadranVitesse::getValueMax()
{
    return value;
}

/*int CadranVitesse::getValue()
{
    return value*1.0*(angle+(start-360))/(start-end);
}*/

void CadranVitesse::setValue(int v)
{
    angle=v+225;
}
