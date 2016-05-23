
#include <cmath>
#include <gtkmm.h>
#include <iostream>
#include "Game.hpp"


int main() {
  int choix;
  bool gameOn = true;

  Game g;
  std::vector<int> coupslibres = g.getCoupsLibres();

  //Menu de démarrage avec options de jouabilité
  while (gameOn == true){
    std::cout << "Bienvenue dans le jeu du quinze vainc.\n";
    std::cout <<"1 - Jouer en mode graphique.\n";
    std::cout <<"2 - Jouer en mode console.\n";
    std::cout <<"3 - Quitter le jeu.\n";
    std::cout <<"Entrer votre choix et appuyer sur entrée : ";
    std::cin >> choix;
  

    switch (choix){
    case 1:
      std::cout << "Mode Graphique lancé.\n";
      //Rajouté code pour la partie graphique
      gameOn = false;
      break;

    case 2:
      std::cout << "Mode Console lancé\n";

      //Affichage de 10 nombres aléatoires
      for(int c : coupslibres){
	std::cout << c << " ";
      }
      std::cout << " " << std::endl;

      break;
    case 3:
      std::cout << "Arrêt du programme";
      gameOn = false;
      break;
    default:
      std::cout << "Choix invalide ! \n";
      std::cout << "Réessayer :\n";
      std::cin >> choix;
      break;
    }
  }
  

    return 0;
}

