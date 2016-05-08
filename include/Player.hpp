#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>

class Player
{
    public:
        Player();
        virtual ~Player();
    protected:
    private:
        int id;
        std::string nom;
        std::string type;
};

#endif // PLAYER_H
