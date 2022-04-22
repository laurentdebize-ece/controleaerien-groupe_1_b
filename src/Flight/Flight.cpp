#include "Flight.h"

Flight::Flight() {
    std::srand(std::time(nullptr));
    int choice(0), number(0);
    bool ok(false);
    std::string tiret = "-";
    int letter1, letter2;

    //Put an random id to the flight
    do {
        number = rand() % 9999 + 1000;
        letter1 = rand() % 90 + 65;
        letter2 = rand() % 90 + 65;
    } while (number < 10000 && number > 999 && letter1 < 91 && letter1 > 64 && letter2 < 91 && letter2 > 64);
    flight_id.push_back((char) letter1);
    flight_id.push_back((char) letter2);
    flight_id += tiret;
    flight_id += std::to_string(number);

    //Pick a plane
    do {
        choice = rand() % list_of_plane.size();
        if (!airplane_flight[choice].get_state()) {
            airplane_flight = list_of_plane[choice];
            airplane_flight[choice].put_state(true);
            ok = true;
        } else {
            ok = false;
        }
    } while (!ok);


    //Random between Airport List for choose a Departure


    //Random between Airport List for choose an Arrival
}

std::string Flight::get_flight_id() const {
    return flight_id;
}

std::string Flight::get_departure() const {
    return departure;
}

std::string Flight::get_arrival() const {
    return arrival;
}

void Flight::afficher() const {

}

void Flight::put_departure() {
    bool find(false), ok(false);
    int choice(0);
    std::string airport;

    do {
        std::cout << "\n";
        for (int i = 0; i < 20; ++i) {
            std::cout << "*";
        }
        std::cout << " DEPARTURE SETUP ";
        for (int i = 0; i < 25; ++i) {
            std::cout << "*";
        }
        std::cout << "\n";
        std::cout << "                   1. SHOW AIRPORTS \n"
                     "                   2. GO TO THE CHOICE OF THE AIRPORT OF DEPARTURE \n";
        for (int i = 0; i < 67; ++i) {
            std::cout << "*";
        }
        std::cin >> choice;
        if (choice != 1 && choice != 2) {
            std::cout << "Choix inconnu\n"
                         "Veuillez retaper\n";
                         ok= false;
        } else {
            ok = true;
            switch (choice) {
                case 1:
                    //list airport
                    break;
                case 2:
                    do {
                        std::cout << "\n";
                        for (int i = 0; i < 20; ++i) {
                            std::cout << "*";
                        }
                        std::cout << " DEPARTURE SETUP ";
                        for (int i = 0; i < 25; ++i) {
                            std::cout << "*";
                        }
                        std::cout << "\n"
                                     "ENTER THE AIRPORT OF DEPARTURE OF YOUR CHOICE : ";
                        std::cin >> airport;
                        for(int j(0);j<airport.size();j++) {
                            if(airport!=m_airport[j].get_AirportName() && j==list_of_airport.size()){
                                std::cout << "UNKNOWN CHOICE\n"
                                             "PLEASE RE-TYPE\n";
                                find= false;
                            }
                            else{
                                find=true;
                                j=list_of_airport.size();
                            }
                        }
                    } while (!find);
                    choice = 0;
                    break;
                default:
                    break;
            }
        }
    } while (!ok);
    departure=airport;
}

void Flight::put_arrival() {
    bool find(false), ok(false);
    int choice(0);
    std::string airport;

    do {
        std::cout << "\n";
        for (int i = 0; i < 20; ++i) {
            std::cout << "*";
        }
        std::cout << " ARRIVAL SETUP ";
        for (int i = 0; i < 25; ++i) {
            std::cout << "*";
        }
        std::cout << "\n";
        std::cout << "                   1. SHOW AIRPORTS \n"
                     "                   2. GO TO THE CHOICE OF THE AIRPORT OF ARRIVAL \n";
        for (int i = 0; i < 67; ++i) {
            std::cout << "*";
        }
        std::cin >> choice;
        if (choice != 1 && choice != 2) {
            std::cout << "UNKNOWN CHOICE\n"
                            "PLEASE RE-TYPE\n";
            ok= false;
        } else {
            ok = true;
            switch (choice) {
                case 1:
                    //list airport
                    break;
                case 2:
                    do {
                        std::cout << "\n";
                        for (int i = 0; i < 20; ++i) {
                            std::cout << "*";
                        }
                        std::cout << " ARRIVAL SETUP ";
                        for (int i = 0; i < 25; ++i) {
                            std::cout << "*";
                        }
                        std::cout << "\n"
                                     "ENTER THE AIRPORT OF ARRIVAL OF YOUR CHOICE : ";
                        std::cin >> airport;
                        for(int j(0);j<airport.size();j++) {
                            if(airport!=m_airport[j].get_AirportName() && j==list_of_airport.size()){
                                std::cout << "UNKNOWN CHOICE\n"
                                             "PLEASE RE-TYPE\n";
                                find= false;
                            }
                            else{
                                find=true;
                                j=list_of_airport.size();
                            }
                        }
                    } while (!find);
                    choice = 0;
                    break;
                default:
                    break;
            }
        }
    } while (!ok);
    arrival=airport;
}

void Flight::Flight_manual() {
    std::srand(std::time(nullptr));
    int choice(0), number(0);
    bool ok(false);
    std::string tiret = "-";
    int letter1, letter2;

    for (int i = 0; i < 20; ++i) {
        std::cout << "*";
    }
    std::cout << " FLIGHT SETUP ";
    for (int i = 0; i < 20; ++i) {
        std::cout << "*";
    }

    //Put an random id to the flight
    do {
        number = rand() % 9999 + 1000;
        letter1 = rand() % 90 + 65;
        letter2 = rand() % 90 + 65;
    } while (number < 10000 && number > 999 && letter1 < 91 && letter1 > 64 && letter2 < 91 && letter2 > 64);
    flight_id.push_back((char) letter1);
    flight_id.push_back((char) letter2);
    flight_id += tiret;
    flight_id += std::to_string(number);

    put_departure();
    put_arrival();
}

Flight::~Flight() {

}
