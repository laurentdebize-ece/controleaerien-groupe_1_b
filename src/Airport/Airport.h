#ifndef CONTROLEAERIEN_GROUPE_1_B_AIRPORT_H
#define CONTROLEAERIEN_GROUPE_1_B_AIRPORT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#define POS_X 952
#define POS_Y 18

class Airport {
private:
    int m_id, m_Xmin, m_Xmax,m_Xcentre, m_Ymin, m_Ymax,m_Ycentre ;
    std::string m_AirportName;// on met un id pour les aeroport ou on laisse le nom
    int m_NbrRunways, m_Ground_seats;
    double m_Ground_waiting_time, m_acces_runway_time, m_anticollision_time, m_landing_time, m_takeoff_time,m_in_flight_loop;

public:
    Airport(int &id, std::string &AirportName, int &Xmin, int &Xmax, int &Xcentre, int &Ymin, int &Ymax,
            int &Ycentre,int &NbrRunways,int &Ground_seats, double &Ground_waiting_time,
            double &acces_runway_time, double &anticollision_time,double &landing_time,double &takeoff_time,
            double &in_flight_loop);
    void afficher() const;
    int getXmin() const;
    int getXmax() const;
    int getXcentre() const;
    int getYmin() const;
    int getYmax() const;
    int getYcentre() const;
    std::string get_AirportName() const;
};

void show_airport_on_screen(sf::Event event, sf::RenderWindow &window, sf::Sprite &Sprite, std::vector<Airport*> &m_airport);

#endif //CONTROLEAERIEN_GROUPE_1_B_AIRPORT_H
