#ifndef VOYANTS_H
#define VOYANTS_H


#include <QGraphicsItem>
#include <QPainter>


class Voyants : public QGraphicsItem
{

public:
    int getValue() const;
    void setValue(int value);
    int getValueMax() const;

protected:
    int valeur;
    int valeurMax;

 };

#endif // VOYANTS_H
