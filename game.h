#ifndef H_Game
#define H_Game

#include "./card.h"
#include "./deck.h"
#include "./hand.h"
#include "./player.h"

#include <string>

class Game
{
    private:
        Deck deck_of_cards;
        Player players[2];
        Card pile;
        int turn_count;
    public:
    //Constructors
        Game(string, string, int);
    //Destructor
        ~Game();
    //Other
        int check_game_end();
        void draw_card();
        Player* turn();
        bool legal_play(Card&);
        void fill_hand();
        int run_game();
};

#endif