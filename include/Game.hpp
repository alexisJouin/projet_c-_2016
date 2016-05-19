#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include "View.hpp"


class Game{
 private:
     Player player1;
     Player player2;

 public:
    Game(View typeView, Player player1, Player player2); // Constructeur
    void displayGameStatus() const; //Affiche l'état courant du jeu
    void playMove() const; //Jouer un coup
    bool isValid(); // Savoir si le coup est valide
    void nextPlayer() const; //void ou type Player dépend de ce qu'on en fait -> Permet de passer au joueur suivant
    void endGame() const ; // Permet d'arreter la partie si la partie est finie
    void displayResult() const;

};





#endif
