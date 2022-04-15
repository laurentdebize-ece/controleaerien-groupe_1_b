#include <SFML/Graphics.hpp>
#include "src/Menu/Menu.h"


 int main() {
     unsigned int choix(0);
     bool fin(false), back_menu(true);

     //Initialisation Cartes Fenetre
     sf::RenderWindow window(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "AIRPORT CONTROL SIMULATOR");

     //Initialisation Cartes Map
     sf::Texture Menu_principal;

     Menu_principal.loadFromFile("Sim_Map.png");

     sf::Sprite Sprite(Menu_principal);
     sf::Vector2f targetSize(LARGEUR_FENETRE, HAUTEUR_FENETRE);

         do {
             if(choix >= 6){
                 std::cout<<"Choix inconnu\n"
                            "Veuillez retaper\n";
                 choix=0;
             }
             Game_Menu(choix);
             switch (choix) {
                 case 1 :
                     Sprite.setScale(
                             targetSize.x / Sprite.getLocalBounds().width,
                             targetSize.y / Sprite.getLocalBounds().height);
                     window.clear(sf::Color::Black);
                     window.draw(Sprite);
                     window.display();
                     while (!fin) {
                         sf::Event event{};
                         while (window.pollEvent(event)) {
                             if (event.type == sf::Event::Closed) {
                                 fin = true;
                                 window.close();
                                 choix = 0;
                             }
                         }
                     }
                     //toutes les fonctions du simulateur
                     break;
                 case 2 :
                     //toutes les fonctions du simulateur
                     airplane_information(choix);
                     if(choix==1){
                         choix=0;
                     }
                     break;
                 case 3:
                     //toutes les fonctions du simulateur
                     std::cout <<"Info avion";
                     break;
                 case 4 :
                     back_menu= false;
                     //Credits
                     std::cout <<"Credit";
                     break;
                 case 5 :
                     std::cout <<"Good bye HAVE A NICE DAY";
                     break;
             }

         }while (choix < 5 && back_menu);
     return 0;
}


