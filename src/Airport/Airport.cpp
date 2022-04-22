#include "Airport.h"


Airport::Airport(int &id, std::string &AirportName, int &Xmin, int &Xmax, int &Xcentre, int &Ymin, int &Ymax,
                 int &Ycentre,int &NbrRunways,int &Ground_seats, double &Ground_waiting_time,
                 double &acces_runway_time, double &anticollision_time,double &landing_time,double &takeoff_time,
                 double &in_flight_loop) :
                 m_id{id}, m_AirportName{AirportName}, m_Xmin{Xmin},m_Xmax{Xmax}, m_Xcentre{Xcentre}, m_Ymin{Ymin},
                 m_Ymax{Ymax}, m_Ycentre{Ycentre},m_NbrRunways{NbrRunways}, m_Ground_seats{Ground_seats},
                 m_Ground_waiting_time{Ground_waiting_time},m_acces_runway_time{acces_runway_time},
                 m_anticollision_time{anticollision_time},m_landing_time{landing_time},
                 m_takeoff_time{takeoff_time},m_in_flight_loop{in_flight_loop} {}

void Airport::afficher() const {
    std::cout << "                   Id : " << m_id << std::endl
              << "                   Name : " << m_AirportName << std::endl
              << "                   Number of Runways : " << m_NbrRunways << std::endl
              << "                   Number of Ground Seats : " << m_Ground_seats << std::endl
              << "                   Ground Waiting Time : " << m_Ground_waiting_time << std::endl
              << "                   Acces Runway Time : " << m_acces_runway_time << std::endl
              << "                   Anticollision Time : " << m_anticollision_time << std::endl
              << "                   Landing Time : " << m_landing_time << std::endl
              << "                   Takeoff Time : " << m_takeoff_time << std::endl
              << "                   In Flight Loop Time : " << m_in_flight_loop << "\n" << std::endl;
}

int Airport::getXmin() const {
    return m_Xmin;
}

int Airport::getXmax() const {
    return m_Xmax;
}

int Airport::getXcentre() const {
    return m_Xcentre;
}

int Airport::getYmin() const {
    return m_Ymin;
}

int Airport::getYmax() const {
    return m_Ymax;
}

int Airport::getYcentre() const {
    return m_Ycentre;
}

std::string Airport::get_AirportName() const {
    return m_AirportName;
}

void show_airport_on_screen(sf::Event event, sf::RenderWindow &window, sf::Sprite &Sprite, std::vector<Airport*> &m_airport) {
    sf::Texture Sydney;
    sf::Texture Pekin;
    sf::Texture Moscou;
    sf::Texture Dubai;
    sf::Texture Londres;
    sf::Texture Pretoria;
    sf::Texture Algeria;
    sf::Texture Los_Angeles;
    sf::Texture New_York;
    sf::Texture Rio_De_Janeiro;
    sf::Texture Martinique;

    Sydney.loadFromFile("Graphic_content/Map/Sydney.png");
    Pekin.loadFromFile("Graphic_content/Map/Sydney.png");
    Moscou.loadFromFile("Graphic_content/Map/Sydney.png");
    Dubai.loadFromFile("Graphic_content/Map/Sydney.png");
    Londres.loadFromFile("Graphic_content/Map/Sydney.png");
    Pretoria.loadFromFile("Graphic_content/Map/Sydney.png");
    Algeria.loadFromFile("Graphic_content/Map/Sydney.png");
    Los_Angeles.loadFromFile("Graphic_content/Map/Sydney.png");
    New_York.loadFromFile("Graphic_content/Map/Sydney.png");
    Rio_De_Janeiro.loadFromFile("Graphic_content/Map/Sydney.png");
    Martinique.loadFromFile("Graphic_content/Map/Sydney.png");

    sf::Sprite Sprite_Sydney(Sydney);
    sf::Sprite Sprite_Pekin(Pekin);
    sf::Sprite Sprite_Moscou(Moscou);
    sf::Sprite Sprite_Dubai(Dubai);
    sf::Sprite Sprite_Londres(Londres);
    sf::Sprite Sprite_Pretoria(Pretoria);
    sf::Sprite Sprite_Algeria(Algeria);
    sf::Sprite Sprite_Los_Angeles(Los_Angeles);
    sf::Sprite Sprite_New_York(New_York);
    sf::Sprite Sprite_Rio_De_Janeiro(Rio_De_Janeiro);
    sf::Sprite Sprite_Martinique(Martinique);

    Sprite_Sydney.setPosition(sf::Vector2f(952, 18));
    window.clear(sf::Color::Black);
    window.draw(Sprite);
    while (window.pollEvent(event)) {
        for (int i(0); i < m_airport.size(); i++) {
                if (event.mouseMove.x >= m_airport[0]->getXmin() && event.mouseMove.x <= m_airport[0]->getXmax() &&
                    event.mouseMove.y >= m_airport[0]->getYmin() && event.mouseMove.y <= m_airport[0]->getYmax()) {
                    window.draw(Sprite_Sydney);
                } else if (event.mouseMove.x >= m_airport[1]->getXmin() && event.mouseMove.x <= m_airport[1]->getXmax() &&
                           event.mouseMove.y >= m_airport[1]->getYmin() && event.mouseMove.y <= m_airport[1]->getYmax()) {
                    window.draw(Sprite_Pekin);
                } else if (event.mouseMove.x >= m_airport[2]->getXmin() && event.mouseMove.x <= m_airport[2]->getXmax() &&
                           event.mouseMove.y >= m_airport[2]->getYmin() && event.mouseMove.y <= m_airport[2]->getYmax()) {
                    window.draw(Sprite_Moscou);
                } else if (event.mouseMove.x >= m_airport[3]->getXmin() && event.mouseMove.x <= m_airport[3]->getXmax() &&
                           event.mouseMove.y >= m_airport[3]->getYmin() && event.mouseMove.y <= m_airport[3]->getYmax()) {
                    window.draw(Sprite_Dubai);
                } else if (event.mouseMove.x >= m_airport[4]->getXmin() && event.mouseMove.x <= m_airport[4]->getXmax() &&
                           event.mouseMove.y >= m_airport[4]->getYmin() && event.mouseMove.y <= m_airport[4]->getYmax()) {
                    window.draw(Sprite_Londres);
                } else if (event.mouseMove.x >= m_airport[5]->getXmin() && event.mouseMove.x <= m_airport[5]->getXmax() &&
                           event.mouseMove.y >= m_airport[5]->getYmin() && event.mouseMove.y <= m_airport[5]->getYmax()) {
                    window.draw(Sprite_Pretoria);
                } else if (event.mouseMove.x >= m_airport[6]->getXmin() && event.mouseMove.x <= m_airport[6]->getXmax() &&
                           event.mouseMove.y >= m_airport[6]->getYmin() && event.mouseMove.y <= m_airport[6]->getYmax()) {
                    window.draw(Sprite_Algeria);
                } else if (event.mouseMove.x >= m_airport[7]->getXmin() && event.mouseMove.x <= m_airport[7]->getXmax() &&
                           event.mouseMove.y >= m_airport[7]->getYmin() && event.mouseMove.y <= m_airport[7]->getYmax()) {
                    window.draw(Sprite_Los_Angeles);
                } else if (event.mouseMove.x >= m_airport[8]->getXmin() && event.mouseMove.x <= m_airport[8]->getXmax() &&
                           event.mouseMove.y >= m_airport[8]->getYmin() && event.mouseMove.y <= m_airport[8]->getYmax()) {
                    window.draw(Sprite_New_York);
                } else if (event.mouseMove.x >= m_airport[9]->getXmin() && event.mouseMove.x <= m_airport[9]->getXmax() &&
                           event.mouseMove.y >= m_airport[9]->getYmin() && event.mouseMove.y <= m_airport[9]->getYmax()) {
                    window.draw(Sprite_Rio_De_Janeiro);
                } else if(event.mouseMove.x >= m_airport[10]->getXmin() && event.mouseMove.x <= m_airport[10]->getXmax() &&
                          event.mouseMove.y >= m_airport[10]->getYmin() && event.mouseMove.y <= m_airport[10]->getYmax()) {
                    window.draw(Sprite_Martinique);
                }
        }
        window.display();
    }
}


