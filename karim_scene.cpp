#include "karim_scene.h"
#include "CadranVitesse.h"
#include "cadrantourparmin.h"
#include "cadranEss.h"
#include "voyants.h"
#include "Voyant_batterie.h"
#include "clignotant.h"
#include <QGraphicsScene>

#include <QMainWindow>


karim_scene::karim_scene()
{
    Vitesse=new CadranVitesse();
    CompteTours= new CadranTourParMin();
    Essence= new CadranEss();
    Temperature = new CadranEss();
    Clignotant = new clignotant();

    VoyantBatterie = new Voyant_batterie();

    Vitesse->setPos(-400,100);
    CompteTours->setPos(200,100);
    Essence->setPos(20,-250);
    Temperature->setPos(370,-250);

    this->addItem(Vitesse);
    this->addItem(CompteTours);
    this->addItem(Essence);
    this->addItem(Temperature);
    this->addItem(Clignotant);
    this->addItem(VoyantBatterie);

}
