#include "Airport.h"




Airport::Airport(int id, std::string AirportName,int Xmin, int Xmax,int Xcentre, int Ymin, int Ymax,int Ycentre,int NbrRunways,
                 int Ground_seats,double Ground_waiting_time, double acces_runway_time, double anticollision_time, double landing_time,
                 double takeoff_time,double in_flight_loop ) : m_id{id}, m_AirportName{AirportName},  m_Xmin{Xmin}, m_Xmax{Xmax}, m_Ymin{Ymin},
                 m_Ymax{Ymax}, m_Ycentre{Ycentre}, m_NbrRunways{NbrRunways}, m_Ground_seats{Ground_seats}, m_Ground_waiting_time{Ground_waiting_time},
                 m_acces_runway_time{acces_runway_time}, m_anticollision_time{anticollision_time}, m_landing_time{landing_time}, m_takeoff_time{takeoff_time},
                 m_in_flight_loop {in_flight_loop} {}

void Airport::afficher() const {
    std::cout << "   Aéroport " << m_AirportName << " ";
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

void show_airport_on_screen(sf::Event event, sf::RenderWindow &window, sf::Sprite &Sprite){
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
    sf::Texture West_Indies;

    Sydney.loadFromFile("../Graphic_content/Map/Sydney.png");
    Pekin.loadFromFile("../Graphic_content/Map/Sydney.png");
    Moscou.loadFromFile("../Graphic_content/Map/Sydney.png");
    Dubai.loadFromFile("../Graphic_content/Map/Sydney.png");
    Londres.loadFromFile("../Graphic_content/Map/Sydney.png");
    Pretoria.loadFromFile("../Graphic_content/Map/Sydney.png");
    Algeria.loadFromFile("../Graphic_content/Map/Sydney.png");
    Los_Angeles.loadFromFile("../Graphic_content/Map/Sydney.png");
    New_York.loadFromFile("../Graphic_content/Map/Sydney.png");
    Rio_De_Janeiro.loadFromFile("../Graphic_content/Map/Sydney.png");
    West_Indies.loadFromFile("../Graphic_content/Map/Sydney.png");

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
    sf::Sprite Sprite_West_Indies(West_Indies);

        Sprite_Sydney.setPosition(sf::Vector2f(952,18));
        window.clear(sf::Color::Black);
        window.draw(Sprite);
        while (window.pollEvent(event)) {

            if (event.mouseMove.x >= 1140 && event.mouseMove.x <= 1185 &&
                event.mouseMove.y >= 570 && event.mouseMove.y <= 600) {
                window.draw(Sprite_Sydney);
            }
            else if (event.mouseMove.x >= 1005 && event.mouseMove.x <= 1065 &&
                event.mouseMove.y >= 300 && event.mouseMove.y <= 330) {
                window.draw(Sprite_Pekin);
            }
            else if (event.mouseMove.x >= 780 && event.mouseMove.x <= 840 &&
                event.mouseMove.y >= 195 && event.mouseMove.y <= 241) {
                window.draw(Sprite_Moscou);
            }
            else if (event.mouseMove.x >= 765 && event.mouseMove.x <= 840 &&
                event.mouseMove.y >= 360 && event.mouseMove.y <= 390) {
                window.draw(Sprite_Dubai);
            }
            else if (event.mouseMove.x >= 555 && event.mouseMove.x <= 615 &&
                event.mouseMove.y >= 225 && event.mouseMove.y <= 255) {
                window.draw(Sprite_Londres);
            }
            else if (event.mouseMove.x >= 675 && event.mouseMove.x <= 720 &&
                event.mouseMove.y >= 540 && event.mouseMove.y <= 570) {
                window.draw(Sprite_Pretoria);
            }
            else if (event.mouseMove.x >= 586 && event.mouseMove.x <= 630 &&
                event.mouseMove.y >= 315 && event.mouseMove.y <= 345) {
                window.draw(Sprite_Algeria);
            }
            else if (event.mouseMove.x >= 120 && event.mouseMove.x <= 180 &&
                event.mouseMove.y >= 285 && event.mouseMove.y <= 330) {
                window.draw(Sprite_Los_Angeles);
            }
            else if (event.mouseMove.x >= 300 && event.mouseMove.x <= 375 &&
                event.mouseMove.y >= 270 && event.mouseMove.y <= 300) {
                window.draw(Sprite_New_York);
            }
            else if (event.mouseMove.x >= 405 && event.mouseMove.x <= 465 &&
                event.mouseMove.y >= 510 && event.mouseMove.y <= 540) {
                window.draw(Sprite_Rio_De_Janeiro);
            }
            else if (event.mouseMove.x >= 330 && event.mouseMove.x <= 375 &&
                event.mouseMove.y >= 375 && event.mouseMove.y <= 405) {
                window.draw(Sprite_West_Indies);
            }
        }
    window.display();


}


