
#include <cmath>
#include <gtkmm.h>
#include <iostream>
#include "Game.hpp"


int main() {

  //Affichage de 10 nombres aléatoires
   Game g;
    std::vector<int> coupslibres = g.getCoupsLibres();
    for(int c : coupslibres){
      std::cout << c << " ";
    }
    std::cout << " " << std::endl;

    return 0;
}

