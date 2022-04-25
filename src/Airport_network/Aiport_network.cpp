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
        //addConnexion(airport1, airport2, poids);
        int num1(0), num2(0);
        for (int j(0); j < m_airport.size(); j++) {
            if (airport1 == m_airport[j]->get_AirportName()) {
                num1 = j;
            }
            if (airport2 == m_airport[j]->get_AirportName()) {
                num2 = j;
            }
        }
        m_airport[num1]->addSuccesseur(m_airport[num2], poids);
    }

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

std::vector<int> Aiport_network::PCC(Airport* departure, Airport* arrival) {

    // INITIALISATION
    int nbMarques = 0;
    std::vector<int> couleurs(m_airport.size(), 0); // tous les aéroports sont non marqués
    std::vector<int> distances(m_airport.size(), std::numeric_limits<int>::max());
    distances[departure->getId()] = 0; // departure est à une distance de 0 de lui même.
    std::vector<int> predecesseurs(m_airport.size(), -1); // nous ne connaissons pas encore les prédécesseurs
    predecesseurs[departure->getId()] = 0; // on pourrait laisser -1, departure n'a pas vraiment de prédécesseur car il s'agit de l'aeroport initial

    do {
        int s(0);
        int distanceMini(0);

        do {
            //CHOIX SOMMET QUI EST A UNE DISTANCE MINI
            s = 0;
            distanceMini = std::numeric_limits<int>::max();
            std::cout << std::endl << std::endl;
            for (size_t i = 0; i < distances.size(); i++) {
                std::cout << couleurs[i] << " "
                          << ((distances[i] == std::numeric_limits<int>::max()) ? "Inf" : std::to_string(
                                  distances[i])) << " "
                          << (predecesseurs[i] == -1 ? "?" : std::to_string(
                                  predecesseurs[i])) << "    ";
                if (couleurs[i] == 0 && distances[i] < distanceMini) {
                    distanceMini = distances[i];
                    s = int(i);
                }
            }
            std::cout << std::endl << std::endl;

            //VERIFICATION DE LA VIABILITE DE L'AEROPORT QUI SE TROUVE A UNE DISTANCE MINIMALE
            if (s == arrival->getId()) {
                nbMarques = int(m_airport.size());
            } else if (/*gestions arrivé gesiton depart sur s*/) {
                couleurs[s] = 1;
                nbMarques++;

            } else {
                //refaire le calcul de distance mini sans s donc remettre la distance de s à l'infini pour que l'aeroport d'id s ne soit  plus prit en compte
                distances[s] = std::numeric_limits<int>::max();
            }


        }while(couleurs[s] == 1);//condition d'arret si sommet valide trouvé

        std::cout << "aéroport choisi : " << s << " (plus petite distance depuis le aeroport " << departure->getId() << " (" << distanceMini
                  << ")"
                  << "). Ses successeurs non marqués sont :" << std::endl;
        for (auto successeur: m_airport[s]->getSuccesseurs()) {
            if (couleurs[successeur.first->getId()] == 0) {
                std::cout << "    - " << successeur.first->getId() << " : "
                          << "Si considéré, la distance deviendrait " << distances[s] << " + "
                          << successeur.second << " = " << distances[s] + successeur.second
                          << ". Ce qui est "
                          << ((distances[s] + successeur.second < distances[successeur.first->getId()]) ? "inférieur"
                                                                                                        : "supérieur")
                          << " à sa distance actuelle de "
                          << distances[successeur.first->getId()] << ". Donc : "
                          << ((distances[s] + successeur.second < distances[successeur.first->getId()]) ? "MAJ"
                                                                                                        : "NON MAJ")
                          << std::endl;
                //on va pas gardé les affichages j'ai laissé psk je trouve ça peut vous aider a comprendre
                if (distances[s] + successeur.second < distances[successeur.first->getId()]) {
                    distances[successeur.first->getId()] = distances[s] + successeur.second;
                    predecesseurs[successeur.first->getId()] = s;
                }
            }
        }
    } while (nbMarques < m_airport.size());

    std::cout << std::endl << "FIN DE DIJKSTRA." << std::endl;


    return predecesseurs;
}


