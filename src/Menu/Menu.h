#include <iostream>
#include "../Plane/Plane.h"
#include "../Airport_network/Aiport_network.h"

#ifndef CONTROLEAERIEN_GROUPE_1_B_MENU_H
#define CONTROLEAERIEN_GROUPE_1_B_MENU_H

#define LARGEUR_FENETRE 1300
#define HAUTEUR_FENETRE 700

void Game_Menu(unsigned int &choix);
void airplane_information(unsigned int &choix, Plane &p);
void airport_information(unsigned int &choix, Aiport_network &a);

#endif //CONTROLEAERIEN_GROUPE_1_B_MENU_H
