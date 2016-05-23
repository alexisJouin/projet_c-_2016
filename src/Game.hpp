#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include "View.hpp"
#include <vector>


class Game{
 private:
  Player _player1, _player2;
  std::vector<int> _numbers;

 public:
  Game();
  void affectedName();
  void playMove();
  void play();
  
  /*  Game(View typeView, Player player1, Player player2); // Constructeur
    void displayGameStatus() const; //Affiche l'état courant du jeu
    bool isValid(); // Savoir si le coup est valide
    void nextPlayer() const; //void ou type Player dépend de ce qu'on en fait -> Permet de passer au joueur suivant
    void endGame() const ; // Permet d'arreter la partie si la partie est finie
    void displayResult() const;*/

};





#endif
