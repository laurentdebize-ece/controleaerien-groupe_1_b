#ifndef CONTROLEAERIEN_GROUPE_1_B_PLANE_H
#define CONTROLEAERIEN_GROUPE_1_B_PLANE_H
#include "Airplane.h"
#include <fstream>
#include <queue>
#include <sstream>

class Plane {
private:
    std::vector<Airplane *> m_airplane;
public:
    Plane(std::string cheminFichierGraphe);
    ~Plane();
    void afficher() const;
};


#endif //CONTROLEAERIEN_GROUPE_1_B_PLANE_H
