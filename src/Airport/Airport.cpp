#include "Airport.h"



Airport::Airport(int &id, std::string &AirportName, int &Xmin, int &Xmax, int &Xcentre, int &Ymin, int &Ymax,
                 int &Ycentre, int &NbrRunways, int &Ground_seats, double &Ground_waiting_time,
                 double &acces_runway_time, double &anticollision_time, double &landing_time, double &takeoff_time,
                 double &in_flight_loop) :
        m_id{id}, m_AirportName{AirportName}, m_Xmin{Xmin}, m_Xmax{Xmax}, m_Xcentre{Xcentre}, m_Ymin{Ymin},
        m_Ymax{Ymax}, m_Ycentre{Ycentre}, m_NbrRunways{NbrRunways}, m_Ground_seats{Ground_seats},
        m_Ground_waiting_time{Ground_waiting_time}, m_acces_runway_time{acces_runway_time},
        m_anticollision_time{anticollision_time}, m_landing_time{landing_time},
        m_takeoff_time{takeoff_time}, m_in_flight_loop{in_flight_loop}
        {
            std::vector<bool> management_NbrRunways(m_NbrRunways, false);
            std::vector<bool> management_Ground_seats(m_Ground_seats, true);// ça c est true et pas false
            m_management_nbrRunways = management_NbrRunways;
            m_management_Ground_seats = management_Ground_seats;

            m_management_nbrRunways[2] = true;
            m_management_nbrRunways[3] = true;

            m_management_Ground_seats[2] = false;
            m_management_Ground_seats[3] = false;




}

void Airport::addSuccesseur(Airport *successeur, int poids) {
    m_successeurs.emplace_back(successeur, poids);
}

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

int Airport::getId() const {
    return m_id;
}

const std::vector<std::pair<Airport *const, int>> &Airport::getSuccesseurs() const {
    return m_successeurs;
}

void Airport::management_Landing(Airplane* airplane_which_landing) {
    for(size_t i(0); i<m_management_nbrRunways.size();++i){
        if(!m_management_nbrRunways[i] && m_acces_runway_time < m_anticollision_time){
            m_management_nbrRunways[i] = true;

            //m_management_Ground_seats[i] = false;
            airplane_which_landing->put_state(true);
        }
        else {
            m_waiting_airplane.push_back(airplane_which_landing);
            //ajouter à la boucle d'attente décollage
        }
    }
}

void Airport::management_takeoff(Airplane* airplane_which_takeoff) {

    for(size_t i(0); i<m_management_nbrRunways.size();++i){
        if(!m_management_nbrRunways[i] && /*!m_management_Ground_seats[i]*/  m_acces_runway_time < m_anticollision_time){
            m_management_nbrRunways[i] = true; //pendant 2ut
            airplane_which_takeoff->takeoff_or_not(true);

            //m_management_Ground_seats[i] = true;
            airplane_which_takeoff->put_state(false);// plus en vol mais ce sera apres 2ut faudra reflechir a ca pareil pr ground seats pariel pour decollage
        }
        else {
            m_waiting_airplane.push_back(airplane_which_takeoff);
        }
    }

}

void Airport::loop_management() {
    //TRIE DES AVIONS EN ATTENTES
    std::sort(m_waiting_airplane.begin(), m_waiting_airplane.end(), [](Airplane* s1, Airplane* s2)
    {
        return s1->get_fuel_capacity() > s2->get_fuel_capacity();
    });

    do {
        //priorité attérissage
        for(size_t i(0);i<m_waiting_airplane.size();++i){
            if(m_waiting_airplane[i]->get_if_takeoff()){
                management_takeoff(m_waiting_airplane[i]);
            }
        }
        //jsp si on peut simplifier ça en mode tous faire dans une boucle for
        for(size_t i(0);i<m_waiting_airplane.size();++i){
            if(!m_waiting_airplane[i]->get_if_takeoff()){
                management_Landing(m_waiting_airplane[i]);
            }
        }

    }while(!m_waiting_airplane.empty());
}

bool Airport::condition_landing() {
    int landing_compteur(0);
    bool landing_viability(false);

    for(size_t i(0); i<m_management_nbrRunways.size();++i){
        if(!m_management_nbrRunways[i] && m_acces_runway_time < m_anticollision_time){
            landing_compteur++;
        }
    }
    if(landing_compteur > 0){
        landing_viability = true;
    }
    else{landing_viability = false;}

    return landing_viability;
}

bool Airport::condition_takeoff() {
    int runways_available (0);
    int groundseats_available(0);
    bool takeoff_viability(false);

   for(size_t i(0); i<m_management_nbrRunways.size();++i){
        if( m_acces_runway_time < m_anticollision_time && !m_management_nbrRunways[i]){
            runways_available++;
        }
    }

    for(size_t i(0); i<m_management_Ground_seats.size();++i){
        if( m_acces_runway_time < m_anticollision_time && !m_management_Ground_seats[i]){
            groundseats_available++ ;
        }
        else{}
    }


    if(runways_available > 0 && groundseats_available > 0 ){
         takeoff_viability = true;
    }
    else {
         takeoff_viability = false;
    }

    return takeoff_viability;

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

        Sydney.loadFromFile("Graphic_Content/Map/Sydney.png");
        Pekin.loadFromFile("Graphic_Content/Map/Sydney.png");
        Moscou.loadFromFile("Graphic_Content/Map/Sydney.png");
        Dubai.loadFromFile("Graphic_Content/Map/Sydney.png");
        Londres.loadFromFile("Graphic_Content/Map/Sydney.png");
        Pretoria.loadFromFile("Graphic_Content/Map/Sydney.png");
        Algeria.loadFromFile("Graphic_Content/Map/Sydney.png");
        Los_Angeles.loadFromFile("Graphic_Content/Map/Sydney.png");
        New_York.loadFromFile("Graphic_Content/Map/Sydney.png");
        Rio_De_Janeiro.loadFromFile("Graphic_Content/Map/Sydney.png");
        Martinique.loadFromFile("Graphic_Content/Map/Sydney.png");

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

        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
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


