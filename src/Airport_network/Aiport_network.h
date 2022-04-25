#ifndef CONTROLEAERIEN_GROUPE_1_B_AIPORT_NETWORK_H
#define CONTROLEAERIEN_GROUPE_1_B_AIPORT_NETWORK_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../Airport/Airport.h"
#include "../Airport_Connexion/Connexion.h"

class Connexion;
class Airport;
class Aiport_network {
private:
    std::vector<Airport*> m_airport;
    std::vector<Connexion*> m_connect;
public:
    Aiport_network(std::string FichieraiportNetwork);
    ~Aiport_network();
    void afficher() const;
    std::vector<Airport*> getListAirport() const;
    void show_network_airport_line_on_screen(sf::Event event, sf::RenderWindow &window, sf::Sprite &Sprite, sf::Font &font) ;
    void draw_line(sf::RenderWindow &window, const double &airport1_x_center, const double &airport1_y_center,
                   const double &airport2_x_center, const double &airport2_y_center, sf::Font &font, int i);
    std::vector<int> PCC (Airport* departure, Airport* arrival);
};
#endif //CONTROLEAERIEN_GROUPE_1_B_AIPORT_NETWORK_H
