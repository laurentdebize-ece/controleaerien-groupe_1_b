#include "Plane.h"

Plane::Plane(std::string cheminFichierGraphe) {
    int num(0);
    bool ok(false);
    std::ifstream ifs{cheminFichierGraphe};
    if (!ifs) {
        throw std::runtime_error("Impossible d'ouvrir " + cheminFichierGraphe);
    }
    std::string ligne;
    while (std::getline(ifs, ligne)) {
        int number = (rand() % 10) + 1;
        std::stringstream ss;
        size_t posit = ligne.find(" ");
        std::string nmodel = ligne.substr(0, posit);
        ss << ligne.substr(posit);
        std::string ntype;
        bool nstate;
        double ncomsuption, nspeed, nlanding_speed, ntakeoff_speed, nfuel_capacity;
        ss >> ntype >> nstate >> ncomsuption >> nspeed >> nlanding_speed >> ntakeoff_speed >> nfuel_capacity;
        for (int i = 0; i < number; ++i) {
            do {
                std::srand(std::time(nullptr));
                num = rand() % 9999 + 1000;
                    if (i!=0) {
                        for (int j(0); j < i; j++) {
                            if (num == m_airplane[j]->get_id()) {
                                ok = false;
                                j=i;
                            } else if (num != m_airplane[j]->get_id() && j == i) {
                                ok = true;
                                j=i;
                            }
                        }
                    }
                    else {
                        ok = true;
                    }
            } while (!ok);
            m_airplane.push_back(
                    new Airplane(nmodel, num, ntype, nstate, ncomsuption, nspeed, nlanding_speed, ntakeoff_speed,
                                 nfuel_capacity));
        }
    }
}

Plane::~Plane() {
    for (auto addrSommet: m_airplane) {
        delete addrSommet;
    }
}

void Plane::afficher() const {
    for (int i = 0; i < 20; ++i) {
        std::cout << "*";
    }
    std::cout << " AIRPLANE INFORMATION ";
    for (int i = 0; i < 25; ++i) {
        std::cout << "*";
    }
    std::cout << "\n";
    for (auto count_airplaine: m_airplane) {
        count_airplaine->afficher();
    }
    for (int j = 0; j < 67; ++j) {
        std::cout << "*";
    }
    std::cout << "\n";
}














