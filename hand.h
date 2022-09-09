#ifndef H_Hand
#define H_Hand

#include "./card.h"
#include "./deck.h"

class Hand
{
    private:
        int n_cards;
        Card* hand_of_cards;
    public:
    //Constructors
        Hand();
        Hand(int);
        Hand(const Hand&);
    //Assignment Operator Overload
        Hand& operator=(const Hand&);
    //Destructor 
        ~Hand();
    //Getters
        int get_n_cards();
        Card& get_card(int&);
    //Other
        void print_hand();
        Card any_plays(Card&);
        int any_plays(Card&, int&);
        void add_card(Card);
        void replace_card(Card, int);
        Hand& remove_card(int);
};


#endif