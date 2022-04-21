//
// Created by Jojo on 4/13/22.
//

#ifndef CONTROLEAERIEN_GROUPE_1_B_AIPORT_NETWORK_H
#define CONTROLEAERIEN_GROUPE_1_B_AIPORT_NETWORK_H
#include <iostream>
#include <vector>
#include <string>
#include "../Airport/Airport.h"
#include "../Flight/Flight.h"



class Aiport_network {

private:

    std::vector<Airport*> m_Airport;
    std::vector<Flight*> m_flight;
public:
    Aiport_network(std::string FichieraiportNetwork);
    ~Aiport_network();
    void afficher() const;
    void addVol(int num1, int num2, int poids);

};


#endif //CONTROLEAERIEN_GROUPE_1_B_AIPORT_NETWORK_H
