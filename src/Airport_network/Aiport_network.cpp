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
                            NbrRunways, Ground_seats, Ground_waiting_time, acces_runway_time,
                            anticollision_time, landing_time, takeoff_time, in_flight_loop));

    }
    int taille;
    ifs >> taille;
    if (ifs.fail()) {
        throw std::runtime_error("Probleme de lecture de la taille du graphe.");
    }

    std::string airport1, airport2;
    int poids;
    for (int i = 0; i < taille; ++i) {
        ifs >> airport1 >> airport2 >> poids;
        if (ifs.fail()) {
            throw std::runtime_error("Probleme de lecture d'un.e arc/arete.");
        }
        addVol(airport1, airport2, poids);
    }

}

void Aiport_network::addVol(std::string &airport1, std::string &airport2, int &poids) {
    int num1(0), num2(0);
    for (int i(0); i < m_airport.size(); i++) {
        if (airport1 == m_airport[i]->get_AirportName()) {
            num1 = i;
        }
        if (airport2 == m_airport[i]->get_AirportName()) {
            num2 = i;
        }
    }

    Connexion *connect = new Connexion(m_airport[num1], m_airport[num2], poids);
    m_connect.push_back(connect);

}

void Aiport_network::afficher() const {

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

void Aiport_network::show_network_airport_line_on_screen(sf::Event event, sf::RenderWindow &window, sf::Sprite &Sprite,
                                                         sf::Font &font) {
    int counter(0);
    for (auto &i: m_connect) {
        draw_line(window, i->getPremier()->getXcentre(), i->getPremier()->getYcentre(),
                  i->getDeuxieme()->getXcentre(), i->getDeuxieme()->getYcentre(), font, counter);
    }
}

void
Aiport_network::draw_line(sf::RenderWindow &window, const double &airport1_x_center, const double &airport1_y_center,
                          const double &airport2_x_center, const double &airport2_y_center, sf::Font &font, int i) {

    sf::Text text;
    text.setFont(font);
    std::string poids;
    poids+=std::to_string(m_connect[i]->getPoids());
    text.setString(poids);
    text.setCharacterSize(10);
    text.setColor(sf::Color::White);
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::Vertex line[] =
            {
                    sf::Vertex(sf::Vector2f((float) airport1_x_center, (float) airport1_y_center)),
                    sf::Vertex(sf::Vector2f((float) airport2_x_center, (float) airport2_y_center))
            };

    window.draw(line, 2, sf::Lines);
    //text.setOrigin(line->position.x/2, line->position.y/2);
    //text.setPosition(line->position.x, line->position.y);
    //window.draw(text);
}


