#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Menu/Menu.h"

#ifndef CONTROLEAERIEN_GROUPE_1_B_AIRPORT_H
#define CONTROLEAERIEN_GROUPE_1_B_AIRPORT_H

void show_airport_on_screen(sf::Event event, sf::RenderWindow &window, sf::Sprite &Sprite);

class Airport {
private:
    int m_id;
    std::string m_AirportName;// on met un id pour les aeroport ou on laisse le nom
    int m_NbrRunways, m_Ground_seats;
    double m_Ground_waiting_time, m_acces_runway_time, m_anticollision_time, m_landing_time, m_takeoff_time,m_in_flight_loop;
//coords

public:
    Airport(int id);
    void afficher() const;




};


#endif //CONTROLEAERIEN_GROUPE_1_B_AIRPORT_H
