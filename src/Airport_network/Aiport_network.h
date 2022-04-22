#ifndef CONTROLEAERIEN_GROUPE_1_B_AIPORT_NETWORK_H
#define CONTROLEAERIEN_GROUPE_1_B_AIPORT_NETWORK_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../Airport/Airport.h"

class Aiport_network {
private:
    std::vector<Airport*> m_airport;
    //std::vector<Flight*> m_flight;
public:
    Aiport_network(std::string FichieraiportNetwork);
    ~Aiport_network();
    void afficher() const;
    void addVol(int num1, int num2, int poids);
    std::vector<Airport*> getListAirport() const;
    void show_airport_on_screen(sf::Event event, sf::RenderWindow &window, sf::Sprite &Sprite);
};


#endif //CONTROLEAERIEN_GROUPE_1_B_AIPORT_NETWORK_H
