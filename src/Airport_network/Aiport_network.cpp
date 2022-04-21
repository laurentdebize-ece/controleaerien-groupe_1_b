//
// Created by Jojo on 4/13/22.
//

#include "Aiport_network.h"
#include <fstream>

Aiport_network::Aiport_network(std::string FichieraiportNetwork) {

    std::ifstream ifs{FichieraiportNetwork};
    if (!ifs) {
        throw std::runtime_error("Impossible d'ouvrir " + FichieraiportNetwork);
    }
    //aiport
    int nbrAirport;
    ifs >> nbrAirport;
    if (ifs.fail()) {
        throw std::runtime_error("Probleme de lecture du nombre d'aerport.");
    }

    std::string AirportName;
    int Xmin,  Xmax, Xcentre,  Ymin,  Ymax, Ycentre;
    int NbrRunways, Ground_seats;
    double Ground_waiting_time, acces_runway_time,  anticollision_time, landing_time,  takeoff_time,  in_flight_loop;

    for (int i = 0; i < nbrAirport; ++i) {
        ifs >> AirportName >> Xmin >> Xmax >> Xcentre >> Ymin >> Ymax >> Ycentre >> NbrRunways >> Ground_seats >> Ground_waiting_time >> acces_runway_time >> anticollision_time >> landing_time >> takeoff_time >> in_flight_loop ;
        if (ifs.fail()) {
            throw std::runtime_error("Probleme de lecture des donnees d'un aeroport.");
        }

        m_Airport.push_back(new Airport(i,AirportName, Xmin, Xmax, Xcentre, Ymin, Ymax, Ycentre, NbrRunways, Ground_seats, Ground_waiting_time,
                                        acces_runway_time,  anticollision_time, landing_time,  takeoff_time,  in_flight_loop));



    }










    //propre au graphe réseau d'aéroport
   /* int ordre;
    ifs >> ordre;
    if (ifs.fail()) {
        throw std::runtime_error("Probleme de lecture de l'ordre du graphe.");
    }*/
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


}

void Aiport_network::addVol(int num1, int num2, int poids) {
    Flight* flight = new Flight(m_flight[num1], m_flight[num2], poids);
    m_flight.push_back(flight);

}

void Aiport_network::afficher() const {

    std::cout <<"liste d'avions : ";


    for (auto addrAirport : m_Airport) {
        addrAirport->afficher();
    }
    std::cout << std::endl << "Liste d'arcs : " << std::endl;
    for(auto addrFlight : m_flight){
        addrFlight->afficher();// classe flight
        std::cout << std::endl;

    // rien vu qu'on affiche en graphique juste histoire de voir si ça lie bien le fichier txt

}


