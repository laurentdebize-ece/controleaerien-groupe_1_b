#include "Flight.h"

#include <cmath>

Flight::Flight(std::vector<Airplane *> list_of_plane, std::vector<Airport *> list_of_airport, bool &enter_manual)
        : m_list_of_plane{list_of_plane}, m_list_of_airport{list_of_airport}, id_plane{0} {
//on recup direct les vecteur qu'on aura creer dans le main
    std::srand(std::time(nullptr));
    int choice(0), number(0);
    bool ok(false);
    int compteur;
    std::string tiret = "-";
    int letter1, letter2;

    //Put an random id to the flight
    do {
        number = rand() % 9999 + 1000;
        letter1 = rand() % 90 + 65;
        letter2 = rand() % 90 + 65;
    } while (!((number < 10000 && number > 999) && (letter1 < 89 && letter1 > 64) && (letter2 < 89 && letter2 > 64)));
    flight_id += (char) letter1;
    flight_id += (char) letter2;
    flight_id += tiret;
    flight_id += std::to_string(number);


    //Pick a random plane

    do {
        id_plane = rand() % m_list_of_plane.size();
        if (!m_list_of_plane[id_plane]->get_state()) {
            m_list_of_plane[id_plane]->put_state(true);
            ok = true;
        } else {
            ok = false;
        }
    } while (!ok);

    //1er tour
    if (!enter_manual) {
        Flight_manual();
        enter_manual = true;
    }
        //Tour suivant automatiques
    else {
        //Random between Airport List for choose a Departure
        //departure = "Sydney" ;
        do {
            choice = rand() % m_list_of_airport.size();

            if (m_list_of_airport[choice]->condition_landing()) {//condition pour le départ d'un vol
                departure = m_list_of_airport[choice]->get_AirportName();
                ok = true;
            } else {
                ok = false;
            }
        } while (!ok);


        //Random between Airport List for choose an Arrival
        ok = false;
        //arrival = "Martinique";
        do {

            choice = rand() % m_list_of_airport.size();
            if (m_list_of_airport[choice]->get_AirportName() != departure &&
                m_list_of_airport[choice]->condition_takeoff()) {//condition pour l'aterrissage d'un vol
                arrival = m_list_of_airport[choice]->get_AirportName();
                ok = true;
            } else {
                ok = false;
                //copie du vecteur qui sera egale a ma liste d'aeroport²
                //compteur++;
            }
        } while (!ok);
    }
}

std::string Flight::get_flight_id() const {
    return flight_id;
}

Airport *Flight::get_departure() const {
    int num1(0);
    for (int j(0); j < m_list_of_airport.size(); j++) {
        if (departure == m_list_of_airport[j]->get_AirportName()) {
            num1 = j;
        }
    }
    return m_list_of_airport[num1];
}

Airport *Flight::get_arrival() const {
    int num2(0);
    for (int j(0); j < m_list_of_airport.size(); j++) {
        if (arrival == m_list_of_airport[j]->get_AirportName()) {
            num2 = j;
        }
    }
    return m_list_of_airport[num2];
}

void Flight::afficher() const {

}

void Flight::put_departure() {
    bool find(false), ok(false);
    unsigned int choice(0);
    std::string airport;

    do {
        std::cout << "\n";
        for (int i = 0; i < 20; ++i) {
            std::cout << "*";
        }
        std::cout << " DEPARTURE SETUP ";
        for (int i = 0; i < 30; ++i) {
            std::cout << "*";
        }
        std::cout << "\n";
        std::cout << "                   1. SHOW AIRPORTS \n"
                     "                   2. GO TO THE CHOICE OF \n "
                     "                     THE AIRPORT OF DEPARTURE \n";
        for (int i = 0; i < 67; ++i) {
            std::cout << "*";
        }
        std::cout << "\n"
                     "ENTER YOUR CHOICE : ";
        std::cin >> choice;
        if (choice != 1 && choice != 2) {
            std::cout << "UNKNOWN CHOICE\n"
                         "PLEASE RE-TYPE\n";
            ok = false;
        } else {
            switch (choice) {
                case 1:
                    for (auto &i: m_list_of_airport) {
                        i->afficher();
                    }
                    break;
                case 2:
                    do {
                        std::cout << "\n";
                        for (int i = 0; i < 20; ++i) {
                            std::cout << "*";
                        }
                        std::cout << " DEPARTURE SETUP ";
                        for (int i = 0; i < 30; ++i) {
                            std::cout << "*";
                        }
                        std::cout << "\n"
                                     "ENTER THE AIRPORT OF DEPARTURE OF YOUR CHOICE : ";
                        std::cin >> airport;
                        for (int j(0); j < airport.size(); j++) {
                            if (airport != m_list_of_airport[j]->get_AirportName() && j == m_list_of_airport.size()) {
                                std::cout << "UNKNOWN CHOICE\n"
                                             "PLEASE RE-TYPE\n";
                                find = false;
                            } else {
                                find = true;
                                j = (int) m_list_of_airport.size();
                            }
                        }
                    } while (!find);
                    ok = true;
                    choice = 0;
                    break;
                default:
                    std::cout << "UNKNOWN CHOICE\n"
                                 "PLEASE RE-TYPE\n";
                    ok = false;
                    break;
            }
        }
    } while (!ok);
    departure = airport;
}

void Flight::put_arrival() {
    bool find(false), ok(false);
    unsigned int choice(0);
    std::string airport;

    do {
        std::cout << "\n";
        for (int i = 0; i < 20; ++i) {
            std::cout << "*";
        }
        std::cout << " ARRIVAL SETUP ";
        for (int i = 0; i < 30; ++i) {
            std::cout << "*";
        }
        std::cout << "\n";
        std::cout << "                   1. SHOW AIRPORTS \n"
                     "                   2. GO TO THE CHOICE OF \n "
                     "                     THE AIRPORT OF ARRIVAL \n";
        for (int i = 0; i < 67; ++i) {
            std::cout << "*";
        }
        std::cout << "\n"
                     "ENTER YOUR CHOICE : ";
        std::cin >> choice;
        if (choice != 1 && choice != 2) {
            std::cout << "UNKNOWN CHOICE\n"
                         "PLEASE RE-TYPE\n";
            ok = false;
        } else {
            switch (choice) {
                case 1:
                    for (auto &i: m_list_of_airport) {
                        i->afficher();
                    }
                    break;
                case 2:
                    do {
                        std::cout << "\n";
                        for (int i = 0; i < 20; ++i) {
                            std::cout << "*";
                        }
                        std::cout << " ARRIVAL SETUP ";
                        for (int i = 0; i < 30; ++i) {
                            std::cout << "*";
                        }
                        std::cout << "\n"
                                     "ENTER THE AIRPORT OF ARRIVAL OF YOUR CHOICE : ";
                        std::cin >> airport;
                        for (int j(0); j < airport.size(); j++) {
                            if (airport != m_list_of_airport[j]->get_AirportName() && j == m_list_of_airport.size()) {
                                std::cout << "UNKNOWN CHOICE\n"
                                             "PLEASE RE-TYPE\n";
                                find = false;
                            } else {
                                find = true;
                                j = (int) m_list_of_airport.size();
                            }
                        }
                    } while (!find);
                    ok = true;
                    choice = 0;
                    break;
                default:
                    std::cout << "UNKNOWN CHOICE\n"
                                 "PLEASE RE-TYPE\n";
                    ok = false;
                    break;
            }
        }
    } while (!ok);
    arrival = airport;
}

void Flight::Flight_manual() {

    for (int i = 0; i < 20; ++i) {
        std::cout << "*";
    }
    std::cout << " FLIGHT SETUP ";
    for (int i = 0; i < 33; ++i) {
        std::cout << "*";
    }

    put_departure();
    put_arrival();
}

Flight::~Flight() {

}

Airplane *Flight::get_airplane() const {
    return m_list_of_plane[id_plane];
}


int Flight::get_departure_num() const {
    int num(0);
    for (size_t i(0); i < m_list_of_airport.size(); i++) {
        if (m_list_of_airport[i]->get_AirportName() == departure) {
            num = (int) i;
        }
    }
    return num;
}

int Flight::get_arrival_num() const {
    int num(0);
    for (size_t i(0); i < m_list_of_airport.size(); i++) {
        if (m_list_of_airport[i]->get_AirportName() == arrival) {
            num = (int) i;
        }
    }
    return num;
}

std::vector<int> Flight::PCC() {

    // INITIALISATION
    int nbMarques = 0;
    std::vector<int> couleurs(m_list_of_airport.size(), 0); // tous les aéroports sont non marqués
    std::vector<int> distances(m_list_of_airport.size(), std::numeric_limits<int>::max());
    distances[get_departure_num()] = 0; // departure est à une distance de 0 de lui même.
    std::vector<int> predecesseurs(m_list_of_airport.size(), -1); // nous ne connaissons pas encore les prédécesseurs

    double rapport_consommation_carburant(0);// si on définit par exemple 300L/ut, pour la turbulence on définit 1000/ut
    std::vector<int> chemin_suivi;
    chemin_suivi.push_back(get_departure_num());

    do {
        int s = 0;
        int distanceMini = std::numeric_limits<int>::max();
        bool choix(false);
        do {


            s = 0;
            for (size_t i = 0; i < distances.size(); i++) {
                if (couleurs[i] == 0 && distances[i] < distanceMini) {
                    distanceMini = distances[i];
                    s = (int) i;
                }

            }
            //VERIFICATION DE LA VIABILITE DE L'AEROPORT QUI SE TROUVE A UNE DISTANCE MINIMALE
            if (s == get_arrival_num()  /* rapport_consommation_carburant <=
                       distances[s]*/) {
                couleurs[s] = 1;
                nbMarques = int(m_list_of_airport.size());
                choix = true;
                chemin_suivi.push_back(s);// push back dans le vecteur du chemin
            } else if (m_list_of_airport[s]->condition_takeoff() && m_list_of_airport[s]->condition_landing()
                /* rapport_consommation_carburant <=
                 distances[s]*/) {// on vérifie si le poids (nbre d'ut entre aéroport), est supérieur au nombre d'ut que peut réaliser l'avion
                couleurs[s] = 1;
                nbMarques++;
                choix = true;
                //chemin_suivi.push_back(s);// push back dans le vecteur du chemin

                //arrive_a_destination = true;

            } else {
                //refaire le calcul de distance mini sans s donc remettre la distance de s à l'infini pour que l'aeroport d'id s ne soit  plus prit en compte
                distances[s] = std::numeric_limits<int>::max();
            }
        } while (!choix);

        /*couleurs[s] = 1;
        nbMarques++;*/

        for (auto successeur: m_list_of_airport[s]->getSuccesseurs()) {
            if (couleurs[successeur.first->getId()] == 0) {
                if (distances[s] + successeur.second < distances[successeur.first->getId()]) {
                    distances[successeur.first->getId()] = distances[s] + successeur.second;
                    predecesseurs[successeur.first->getId()] = s;
                }
            }
        }
    } while (nbMarques < m_list_of_airport.size());

    //RECUPERATION DU CHEMIN JUSQU'A L'AEROPORT D'ARRIVE

    return chemin_suivi;
}










std::vector<int> Flight::redirection_turbulence_A() {
    // INITIALISATION
    int nbMarques(0);
    std::vector<int> couleurs(m_list_of_airport.size(), 0); // tous les aéroports sont non marqués
    std::vector<float> distances(m_list_of_airport.size(), std::numeric_limits<float>::max());
    float distance_plane_airport(0.0f);
    distances[get_departure_num()] = 0; // departure est à une distance de 0 de lui même.
    std::vector<int> predecesseurs(m_list_of_airport.size(), -1); // nous ne connaissons pas encore les prédécesseurs
    // predecesseurs[f->get_departure()->getId()] = 0; // on pourrait laisser -1, departure n'a pas vraiment de prédécesseur car il s'agit de l'aeroport initial
    double rapport_consommation_carburant(0);// si on définit par exemple 300L/ut
    std::vector<int> new_way;
    new_way.push_back(get_departure_num());

    do {
        int s = 0;
        int distanceMini = std::numeric_limits<int>::max();
        bool choix(false);
        do {

            if(false){//avion dans la zone de turbulence ?
                rapport_consommation_carburant = this->get_airplane()->get_plane_comsuption() / 1000;// la on obtient le nbre d'ut que l'on peut faire avec le carburant de l'avion
            }
            else{rapport_consommation_carburant = this->get_airplane()->get_plane_comsuption() / 300; }

            //CALCUL DU SOMMET 1 LA PLUS COURTE DISTANCE DE L'AVION, distance minimale sera la distance entre l'avion et l'aeroport

            for(size_t i(0);i<m_list_of_airport.size();++i){
                //distance_plane_airport = perimetre2pts(this->get_airplane()->get_plane_x(),this->get_airplane()->get_plane_y(),m_list_of_airport[i]->getXcentre(),m_list_of_airport[i]->getYcentre());
                distances.push_back(perimetre2pts(this->get_airplane()->get_plane_x(),this->get_airplane()->get_plane_y(),m_list_of_airport[i]->getXcentre(),m_list_of_airport[i]->getYcentre()));
            }















            s = 0;
            for (size_t i = 0; i < distances.size(); i++) {
                if (couleurs[i] == 0 && distances[i] < distanceMini) {
                    distanceMini = distances[i];
                    s = (int) i;
                }
                //  rapport_consommation_carburant = f->get_airplane()->get_plane_comsuption() / 300); la on obtient le nbre d'ut que l'on peut faire avec le carburant de l'avion
            }
            //std::cout << std::endl << std::endl;

            //VERIFICATION DE LA VIABILITE DE L'AEROPORT QUI SE TROUVE A UNE DISTANCE MINIMALE
            if (s == get_arrival_num()  /* rapport_consommation_carburant <=
                       distances[s]*/) {
                couleurs[s] = 1;
                nbMarques = int(m_list_of_airport.size());
                choix = true;
                new_way.push_back(s);// push back dans le vecteur du chemin
            } else if (m_list_of_airport[s]->condition_takeoff() && m_list_of_airport[s]->condition_landing()
                /* rapport_consommation_carburant <=
                 distances[s]*/) {// on vérifie si le poids (nbre d'ut entre aéroport), est supérieur au nombre d'ut que peut réaliser l'avion
                couleurs[s] = 1;
                nbMarques++;
                choix = true;
                new_way.push_back(s);// push back dans le vecteur du chemin

                //arrive_a_destination = true;

            } else {
                //refaire le calcul de distance mini sans s donc remettre la distance de s à l'infini pour que l'aeroport d'id s ne soit  plus prit en compte
                distances[s] = std::numeric_limits<int>::max();
            }
        } while (!choix);

        /*couleurs[s] = 1;
        nbMarques++;*/

        for (auto successeur: m_list_of_airport[s]->getSuccesseurs()) {
            if (couleurs[successeur.first->getId()] == 0) {
                if (distances[s] + successeur.second < distances[successeur.first->getId()]) {
                    distances[successeur.first->getId()] = distances[s] + successeur.second;
                    predecesseurs[successeur.first->getId()] = s;
                }
            }
        }
    } while (nbMarques < m_list_of_airport.size());

    //RECUPERATION DU NOUVEAU CHEMIN JUSQU'A L'AEROPORT D'ARRIVE

    return new_way;
}

std::vector<Airplane *> Flight::get_list_Airplane() const {
    return m_list_of_plane;
}

int Flight::get_id_plane() const {
    return id_plane;
}

void draw_line_test(sf::RenderWindow &window, const double &airport1_x_center, const double &airport1_y_center,
                            const double &airport2_x_center, const double &airport2_y_center) {
    sf::Vector2f mid = sf::Vector2f((float)( airport1_x_center + airport2_x_center) / 2, (float)(airport1_y_center + airport2_y_center) / 2);
    sf::Vertex line[] =
            {
                    sf::Vertex(sf::Vector2f((float) airport1_x_center, (float) airport1_y_center)),
                    sf::Vertex(sf::Vector2f((float) airport2_x_center, (float) airport2_y_center))
            };

    window.draw(line, 2, sf::Lines);

}









sf::Vector2f (Interpolate(const sf::Vector2f (&pointA), const sf::Vector2f (&pointB), float factor)) {
    if (factor > 1.f) {
        factor = 1.f;
    } else if (factor < 0.f) {
        factor = 0.f;
    }
    return pointA + (pointB - pointA) * factor;
}

double angle(float airport1X, float airport1Y, float airport2X, float airport2Y) {

    float opp = std::abs(airport2X) - std::abs(airport1X);//valeur absolue du opposé
    float adj = std::abs(airport1Y) - std::abs(airport2Y);//valeur absolue du adjacent
    //std::cout << std::to_string(std::abs(airport2X) - std::abs(airport1X));
    float angle = std::atan (opp/adj);

    if(airport2Y > airport1Y ){

        return (angle*180)/PI ; //angle en degré

    }else {
        return (angle * 180) / PI+ 180.0; //angle en degré
         }

}

float perimetre2pts(float x, float y, float x2, float y2) {
    return (float)std::sqrt((x-x2)*(x-x2) +( y-y2) * (y-y2));
}



