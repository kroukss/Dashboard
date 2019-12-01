#ifndef CadranVitesse_H
#define CadranVitesse_H
#include <QGraphicsItem>
#include <QPainter>

class CadranVitesse : public QGraphicsItem
{

public:
    CadranVitesse(QGraphicsItem *parent =0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int vitesse;//la vitesse actualisé
    int value=0;
    //int start;
    //int end;

    int getValueMax();
    //int getValue();
    void setValue(int );
    int angle=225;


 };


#endif // CadranVitesse_H
