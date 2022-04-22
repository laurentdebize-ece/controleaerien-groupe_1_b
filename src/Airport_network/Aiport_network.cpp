#include "Aiport_network.h"


Aiport_network::Aiport_network(std::string FichieraiportNetwork) {

    std::ifstream ifs{FichieraiportNetwork};
    if (!ifs) {
        throw std::runtime_error("Impossible d'ouvrir " + FichieraiportNetwork);
    }
    //Airport
    int nbrAirport;
    ifs >> nbrAirport;
    if (ifs.fail()) {
        throw std::runtime_error("Probleme de lecture du nombre d'aeroport.");
    }

    std::string AirportName;
    int Xmin, Xmax, Xcentre, Ymin, Ymax, Ycentre;
    int NbrRunways, Ground_seats;
    double Ground_waiting_time, acces_runway_time, anticollision_time, landing_time, takeoff_time, in_flight_loop;

    for (int i = 0; i < nbrAirport; ++i) {
        ifs >> AirportName >> Xmin >> Xmax >> Xcentre >> Ymin >> Ymax >> Ycentre >> NbrRunways >> Ground_seats
            >> Ground_waiting_time >> acces_runway_time >> anticollision_time >> landing_time >> takeoff_time
            >> in_flight_loop;
        if (ifs.fail()) {
            throw std::runtime_error("Probleme de lecture des donnees d'un aeroport.");
        }

        m_airport.push_back(
                new Airport(i, AirportName, Xmin, Xmax, Xcentre, Ymin, Ymax, Ycentre,
                            NbrRunways, Ground_seats,Ground_waiting_time,acces_runway_time,
                            anticollision_time, landing_time, takeoff_time, in_flight_loop));

    }










    //propre au graphe réseau d'aéroport
    /* int ordre;
     ifs >> ordre;
     if (ifs.fail()) {
         throw std::runtime_error("Probleme de lecture de l'ordre du graphe.");
     }
     int taille;
     ifs >> taille;
     if (ifs.fail()) {
         throw std::runtime_error("Probleme de lecture de la taille du graphe.");
     }
     for (int i = 0; i < nbrAirport; ++i) {
         m_Airport.push_back(new Airport(i));
     }
     int num1, num2, poids;//remplacer par string si on change l'id
     for (int i = 0; i < taille; ++i) {
         ifs >> num1 >> num2 >> poids;
         if (ifs.fail()) {
             throw std::runtime_error("Probleme de lecture d'un.e arc/arete.");
         }
         addVol(num1, num2, poids);
     }
 */

}

void Aiport_network::addVol(int num1, int num2, int poids) {
    //Flight* flight = new Flight(m_flight[num1], m_flight[num2], poids);
    //m_flight.push_back(flight);

}

void Aiport_network::afficher() const {

    //std::cout <<"liste d'avions : ";

    for (int i = 0; i < 20; ++i) {
        std::cout << "*";
    }
    std::cout << " AIRPLANE INFORMATION ";
    for (int i = 0; i < 25; ++i) {
        std::cout << "*";
    }
    std::cout << "\n";
    for (auto addrAirport: m_airport) {
        addrAirport->afficher();
    }

    for (int j = 0; j < 67; ++j) {
        std::cout << "*";
    }
    std::cout << "\n";

    /*std::cout << std::endl << "Liste d'arcs : " << std::endl;
    for(auto addrFlight : m_flight){
        addrFlight->afficher();// classe flight
        std::cout << std::endl;
*/
    // rien vu qu'on affiche en graphique juste histoire de voir si ça lie bien le fichier txt

}

Aiport_network::~Aiport_network() {
    for (auto addrAirport_network: m_airport) {
        delete addrAirport_network;
    }
}

std::vector<Airport *> Aiport_network::getListAirport() const {
    return m_airport;
}

void Aiport_network::show_airport_on_screen(sf::Event event, sf::RenderWindow &window, sf::Sprite &Sprite) {


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


