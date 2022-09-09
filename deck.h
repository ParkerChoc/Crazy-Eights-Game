#ifndef H_DECK
#define H_DECK

#include "./card.h"
#include <stdlib.h> // Used for rand

class Deck
{
    private:
        int cards_left;
        Card my_cards[52];
    
    public:
    //Constructor & Destructor
        Deck();
        ~Deck();
    //Getters
        Card get_card(int);
        int get_cards_left();
    //Setters
        void set_card(int, Card);
        void swap(Card*, Card*);
    //Other
        Deck& fill_deck();
        Deck& shuffle();
        void print_deck();
        Card take_card();
};

#endif

