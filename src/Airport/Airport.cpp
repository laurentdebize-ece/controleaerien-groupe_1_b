#include "Airport.h"


Airport::Airport(int &id, std::string &AirportName, int &Xmin, int &Xmax, int &Xcentre, int &Ymin, int &Ymax,
                 int &Ycentre, int &NbrRunways, int &Ground_seats, double &Ground_waiting_time,
                 double &acces_runway_time, double &anticollision_time, double &landing_time, double &takeoff_time,
                 double &in_flight_loop) :
        m_id{id}, m_AirportName{AirportName}, m_Xmin{Xmin}, m_Xmax{Xmax}, m_Xcentre{Xcentre}, m_Ymin{Ymin},
        m_Ymax{Ymax}, m_Ycentre{Ycentre}, m_NbrRunways{NbrRunways}, m_Ground_seats{Ground_seats},
        m_Ground_waiting_time{Ground_waiting_time}, m_acces_runway_time{acces_runway_time},
        m_anticollision_time{anticollision_time}, m_landing_time{landing_time},
        m_takeoff_time{takeoff_time}, m_in_flight_loop{in_flight_loop} {}

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

double Airport::getXcentre() const {
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

void show_airport_on_screen(sf::Event event, sf::RenderWindow &window, sf::Sprite &Sprite, Aiport_network &a,
                            sf::Font &font) {

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

    Sydney.loadFromFile("../Graphic_Content/Map/Sydney.png");
    Pekin.loadFromFile("../Graphic_Content/Map/Sydney.png");
    Moscou.loadFromFile("../Graphic_Content/Map/Sydney.png");
    Dubai.loadFromFile("../Graphic_Content/Map/Sydney.png");
    Londres.loadFromFile("../Graphic_Content/Map/Sydney.png");
    Pretoria.loadFromFile("../Graphic_Content/Map/Sydney.png");
    Algeria.loadFromFile("../Graphic_Content/Map/Sydney.png");
    Los_Angeles.loadFromFile("../Graphic_Content/Map/Sydney.png");
    New_York.loadFromFile("../Graphic_Content/Map/Sydney.png");
    Rio_De_Janeiro.loadFromFile("../Graphic_Content/Map/Sydney.png");
    Martinique.loadFromFile("../Graphic_Content/Map/Sydney.png");

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

    Sprite_Sydney.setPosition(sf::Vector2f(POS_X, POS_Y));
    Sprite_Pekin.setPosition(sf::Vector2f(POS_X, POS_Y));
    Sprite_Moscou.setPosition(sf::Vector2f(POS_X, POS_Y));
    Sprite_Dubai.setPosition(sf::Vector2f(POS_X, POS_Y));
    Sprite_Londres.setPosition(sf::Vector2f(POS_X, POS_Y));
    Sprite_Pretoria.setPosition(sf::Vector2f(POS_X, POS_Y));
    Sprite_Algeria.setPosition(sf::Vector2f(POS_X, POS_Y));
    Sprite_Los_Angeles.setPosition(sf::Vector2f(POS_X, POS_Y));
    Sprite_New_York.setPosition(sf::Vector2f(POS_X, POS_Y));
    Sprite_Rio_De_Janeiro.setPosition(sf::Vector2f(POS_X, POS_Y));
    Sprite_Martinique.setPosition(sf::Vector2f(POS_X, POS_Y));
    window.clear(sf::Color::Transparent);
    window.draw(Sprite);
    window.display();

        if (event.type == sf::Event::KeyPressed ||event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::I) {
                    window.draw(Sprite);
                    a.show_network_airport_line_on_screen(event, window, Sprite, font);
                    window.display();
                }
            if (event.key.code == sf::Keyboard::O) {
                window.draw(Sprite);
                window.display();
            }
        }
        while (window.pollEvent(event)) {
            // a.getListAirport()[3];
            for (int i(0); i < a.getListAirport().size(); i++) {
                if (event.mouseMove.x >= a.getListAirport()[i]->getXmin() &&
                    event.mouseMove.x <= a.getListAirport()[i]->getXmax() &&
                    event.mouseMove.y >= a.getListAirport()[i]->getYmin() &&
                    event.mouseMove.y <= a.getListAirport()[i]->getYmax()) {
                    if (i == 0) {
                        window.draw(Sprite_Sydney);
                    } else if (i == 1) {
                        window.draw(Sprite_Pekin);
                    } else if (i == 2) {
                        window.draw(Sprite_Moscou);
                    } else if (i == 3) {
                        window.draw(Sprite_Dubai);
                    } else if (i == 4) {
                        window.draw(Sprite_Londres);
                    } else if (i == 5) {
                        window.draw(Sprite_Pretoria);
                    } else if (i == 6) {
                        window.draw(Sprite_Algeria);
                    } else if (i == 7) {
                        window.draw(Sprite_Los_Angeles);
                    } else if (i == 8) {
                        window.draw(Sprite_New_York);
                    } else if (i == 9) {
                        window.draw(Sprite_Rio_De_Janeiro);
                    } else if (i == 10) {
                        window.draw(Sprite_Martinique);
                    }
                    window.display();
                }
            }
        }

    }



