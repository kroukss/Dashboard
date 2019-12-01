#ifndef KARIM_SCENE_H
#define KARIM_SCENE_H
#include <CadranVitesse.h>
#include <cadrantourparmin.h>
#include <cadranEss.h>

#include <voyants.h>
#include <clignotant.h>
#include <Voyant_batterie.h>

#include <QMainWindow>
#include <QGraphicsScene>

class karim_scene : public QGraphicsScene
{
public:
    karim_scene();

    CadranVitesse *Vitesse;
    CadranTourParMin *CompteTours;
    CadranEss *Essence;
    CadranEss *Temperature;

    clignotant * Clignotant;
    Voyants *VoyantBatterie;


};

#endif // KARIM_SCENE_H
