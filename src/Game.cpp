#include "Game.hpp"
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

Game::Game(){
  
   //Créer un constructeur Number  qui génère un nombre aléatoire entre 1 et 30.

  for(int i=1;i<31;i++){
    
    _numbers.push_back(i);
  }
    std::random_device rd;
    std::mt19937 g(rd());
 
    std::shuffle(_numbers.begin(), _numbers.end(), g);
    _numbers.resize(10);

    /*for(int n : _numbers){
      std::cout << n << " ";
      }*/

    
}

std::vector<int> Game::getCoupsLibres(){
   return _numbers;
} 
/*Game::Game(View typeView, Player player1, Player player2) {}

 void displayGameStatus(){
    }

    void playMove(){

    }
    bool isValid(){

    }
    void nextPlayer(){

    }
    void endGame(){

    }
    void displayResult(){

    }
*/
