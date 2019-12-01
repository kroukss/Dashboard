#ifndef CLIGNOTANT_H
#define CLIGNOTANT_H
#include <QGraphicsItem>
#include "objet_virtuel.h"

class clignotant : public objet_virtuel
{
public:
   clignotant(QGraphicsItem *parent=nullptr);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int cligno;
    void MAJ();
    //int value;
};
#endif // CLIGNOTANT_H
