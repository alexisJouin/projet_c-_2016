#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <vector>

class Player
{
private:
  std::string _nom, _type;
  std::vector <int> _numbersPlayer;
  int _resultPlayer = 0;
public:
  Player();
  virtual ~Player();
  std::string getNom();
  void setNom(std::string nom);
  int getResultPlayer();
  std::vector<int> getNumbersPlayer();
  void setResultPlayer(int currentResultPlayer);
};

#endif // PLAYER_H
