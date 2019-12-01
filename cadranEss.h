#ifndef Cadrans_H
#define Cadrans_H
#include <QGraphicsItem>
#include <QPainter>

class CadranEss : public QGraphicsItem
{

public:
    CadranEss(QGraphicsItem *parent =0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getValueMax();
    void setValue(int v);
    int value=0;
    int angle=225;
    int vitesse;

 };




#endif // Cadrans_H
