#ifndef H_Player
#define H_Player

#include "./card.h"
#include "./deck.h"
#include "./hand.h"

#include <string>

class Player 
{
    private:
        Hand my_hand;
        string name;
    public:
    //Constructors
        Player();
        Player(int&);
        Player(int&, string&);
    //Destructor
        ~Player();
    //Getters
        Hand* get_hand();
        string get_name();
    //Other
        void computer_plays_eight(int&, int&, char&);
        void get_selection(int&);
        Card print_info(int&, Card&);

};

#endif