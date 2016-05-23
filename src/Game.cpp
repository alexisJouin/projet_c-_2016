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
    
}


//Gestion des noms de joueurs

void Game::affectedName(){
  
  std::string name1,name2;
  
  std::cout << "Entrez le nom du joueur 1: ";
  std::cin >> name1;
  _player1.setNom(name1);

  std::cout << "Entrez le nom du joueur 2: ";
  std::cin >> name2;
  _player2.setNom(name2); 
  
}

void Game::playMove(){
  int res1 = _player1.getResultPlayer(); //Somme actuelle du joueur 1
  int res2 = _player2.getResultPlayer(); //Somme actuelle du joueur 2
  int choicePlayer, p = 1;
  std::vector<int> j1Numbers = _player1.getNumbersPlayer();
  std::vector<int> j2Numbers = _player2.getNumbersPlayer();
  std::string j1,j2;
  j1 = _player1.getNom();
  j2 = _player2.getNom();
  
  //while( res1 < 42 || res2 < 42 ){

  //joueur 1
    //Affichage de 10 nombres aléatoires

  
    for(int c : _numbers){
      std::cout << "Nombres disponibles: "<< c << " " << std::endl;
    }
    for(int c1 : j1Numbers){
      std::cout << "Nombres de "<< j1 << " : "<< c1 << " " << std::endl;
    }    
    for(int c2 : j2Numbers){
      std::cout << "Nombres de "<< j2 << " : "<< c2 << " " << std::endl;
    }
    
    if( p == 1){
      std::cout << _player1.getNom()<< " entre un nombre disponible :  ";
      std::cin >> choicePlayer;
      for(int c : _numbers){
	if( c == choicePlayer){
	  _numbers.erase(choicePlayer);
	  j1Numbers.push_back(choicePlayer);
	}
	else{
	  std::cout << "La valeur n'existe pas" << std::endl;
	}	    
      }
      p = 2;    
      else{
	std::cout << _player2.getNom()<< " entre un nombre disponible :  ";
	std::cin >> choicePlayer;
	for(int c : _numbers){
	  if( c == choicePlayer){
	    _numbers.erase(choicePlayer);
	    j2Numbers.push_back(choicePlayer);
	  }
	  else{
	    std::cout << "La valeur n'existe pas" << std::endl;
	  }	    
	}
	p=1;
      }
    //}
}

void Game::play(){
  
  int choix;
  bool gameOn = true;
  std::string j1,j2;
  // std::vector<int> coupslibres = _numbers;

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

      //Gestion des noms de joueurs
      affectedName();
      j1 = _player1.getNom();
      j2 = _player2.getNom();
      std::cout << j1 << std::endl;
      std::cout << j2 << std::endl;
      

      playMove(); //Jouer un coup

     
      gameOn = false;      
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
}


/*Game::Game(View typeView, Player player1, Player player2) {}

  void displayGameStatus(){
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
