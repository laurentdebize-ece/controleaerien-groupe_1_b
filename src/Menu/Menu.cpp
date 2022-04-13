#include "Menu.h"
//Affichage du Menu avec le style d'affichage
void Game_Menu(unsigned int &choix){
    for (int i = 0; i < 20; ++i) {
        printf("*");
    }
    std::cout<< " AIRPORT CONTROL SIMULATOR " ;
    for (int i = 0; i < 20; ++i) {
        std::cout<<"*";
    }
    std::cout<<"\n";
    std::cout<<"                   1. START A SIMULATION \n";
    std::cout<<"                   2. INFORMATIONS ABOUT AIRPORTS \n";
    std::cout<<"                   3. INFORMATIONS ABOUT AIRPLANE \n";
    std::cout<<"                   4. CREDITS \n";
    std::cout<<"                   5. QUIT \n" ;
    for (int i = 0; i < 67; ++i) {
        printf("*");
    }
    std::cout<<"\n"
               "ENTER YOUR CHOICE : ";

    std::cin >> choix;
}

void airplane_information(unsigned int &choix){
    for (int i = 0; i < 20; ++i) {
        printf("*");
    }
    std::cout<< " AIRPLANE INFORMATION " ;
    for (int i = 0; i < 20; ++i) {
        std::cout<<"*";
    }
    std::cout<<"\n";
    std::cout<<"                   1. BACK TO PRINCIPAL MENU \n";
    for (int i = 0; i < 67; ++i) {
        printf("*");
    }
    std::cout<<"\n"
               "ENTER YOUR CHOICE : ";

    std::cin >> choix;
}


