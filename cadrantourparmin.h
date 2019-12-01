#ifndef CADRANTOURPARMIN_H
#define CADRANTOURPARMIN_H
#include <QGraphicsItem>
#include <QPainter>

class CadranTourParMin : public QGraphicsItem
{

public:
    CadranTourParMin(QGraphicsItem *parent =0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int vitesse;

    int value=0;
    int start;
    int end;

    int getValueMax();
    int getValue();
    void setValue(int );
    int angle=225;
 };




#endif // CADRANTOURPARMIN_H
