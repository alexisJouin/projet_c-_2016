#include "Player.hpp"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}


std::string Player::getNom(){
  return _nom;
}


void Player::setNom(std::string nom){
  _nom = nom;
}

int Player::getResultPlayer(){
  return _resultPlayer;
}

void Player::setResultPlayer(int currentResultPlayer){
  _resultPlayer = currentResultPlayer;
}

std::vector<int> Player::getNumbersPlayer(){
  return _numbersPlayer;
}
