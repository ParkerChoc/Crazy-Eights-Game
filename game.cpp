/******************************************************
** Program: game.cpp
** Author: Parker Choc
** Date: 04/25/2021
** Description: all member functions of the Game class
** Input: depends on function
** Output: depends on function
******************************************************/

#include "./card.h"
#include "./deck.h"
#include "./hand.h"
#include "./player.h"
#include "./game.h"

#include <string>
#include <iostream>

/*********************************************************************  
** Function: Game()
** Description: constructor for the game class
** Parameters: string p1_name, string p2_name, int starting_cards
** Pre-Conditions: the two player names, the starting number of cards
** Post-Conditions: a constructed game
*********************************************************************/
Game::Game(string p1_name, string p2_name, int starting_cards)
{
    //Set up deck of cards
    Deck d1;
    deck_of_cards = d1;
    deck_of_cards.fill_deck().shuffle();

    //set up turn count
    turn_count = 0;

    //set up both players
    Player p1(starting_cards, p1_name);
    Player p2(starting_cards, p2_name);
    players[0] = p1;
    players[1] = p2;
    
    //fill both player hands
    for (int i = 0; i < starting_cards; i++)
    {
        players[0].get_hand()->replace_card(deck_of_cards.take_card(), i);
        players[1].get_hand()->replace_card(deck_of_cards.take_card(), i);
    }
    
    //set up the pile of cards to be played off of
    pile = deck_of_cards.take_card();
}

/*********************************************************************  
** Function: ~Game()
** Description: destructor for the game class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: destoys the game class
*********************************************************************/
Game::~Game()
{
    //cout << "Game Destructor Called\n";
}

/*********************************************************************  
** Function: turn()
** Description: returns the player whose turn it is
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the player whose turn it is (as a pointer)
*********************************************************************/
Player* Game::turn()
{
    //returns the player whose turn it is
    return &players[turn_count % 2];
}

/*********************************************************************  
** Function: draw_card()
** Description: has the player who's turn it is draw a card
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: player has drawn a card
*********************************************************************/
void Game::draw_card()
{
    //takes a card from the deck and gives it to the player who's turn it is
    turn()->get_hand()->add_card(deck_of_cards.take_card());
}

/*********************************************************************  
** Function: check_game_end()
** Description: returns an integer based on if the game is over or not
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: 0:player 0 win, 1:player 1 win, 2:tie, 3:nothing
*********************************************************************/
int Game::check_game_end()
{
    /*
    ** return a 0 if player 0 won (the computer)
    ** return a 1 if player 1 won (the human user)
    ** return a 2 if the game is a tie (deck runs out and both have same # cards)
    ** return a 3 if the game is not yet over
    */

    if (players[0].get_hand()->get_n_cards() == 0)
        return 0;   //the computer won (no cards in hand)
    if (players[1].get_hand()->get_n_cards() == 0)
        return 1;   //the user won (no cards in hand)

    //if the deck is out of cards, then the player with the fewest cards in hand wins
    if (deck_of_cards.get_cards_left() == 0)
    {
        cout << "The deck is empty!\n";
        if (players[0].get_hand()->get_n_cards() > players[1].get_hand()->get_n_cards())
            return 1;   //The computer has more cards in hand (user wins)
        if (players[0].get_hand()->get_n_cards() < players[1].get_hand()->get_n_cards())
            return 0;   //The user has more cards in hand (computer wins)
        if (players[0].get_hand()->get_n_cards() == players[1].get_hand()->get_n_cards())
            return 2;   //The game is a tie
    }
    
    return 3;   //the game is not over yet
}

/*********************************************************************  
** Function: legal_play()
** Description: tells if a given card is a legal play
** Parameters: Card& c1
** Pre-Conditions: card reference
** Post-Conditions: yes or no (1 or 0) if the card can be played
*********************************************************************/
bool Game::legal_play(Card& c1)
{
    if (c1.get_rank() == pile.get_rank())
        return true;
    if (c1.get_suit() == pile.get_suit())
        return true;
    if (c1.get_rank() == 8) //wild card
        return true;
    return false;   //the card is not legal
}

/*********************************************************************  
** Function: fill_hand()
** Description: has the player draw cards unitl they have a card they
**      can play
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: updated player hand
*********************************************************************/
void Game::fill_hand()
{
    Card no_card(0, '@');
    while (turn()->get_hand()->any_plays(pile).get_suit() == no_card.get_suit())
    {
        cout << turn()->get_name() << ": drawing a card (no legal plays)\n";
        draw_card();

        //if the deck runs out of cards
        if (deck_of_cards.get_cards_left() == 0)
            return;
    } 
}

/*********************************************************************  
** Function: run_game()
** Description: alternates between the turns of the players and allows
**      them to actually play cards
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: number corresponding to who won the game
*********************************************************************/
int Game::run_game()
{
    do 
    {      
        turn_count++;
        Card want_to_play;
        int card_index = 0;
        do
        {
            //draw cards until there is an available play
            fill_hand();
            if (deck_of_cards.get_cards_left() == 0)
                return check_game_end();

            //display the pile
            cout << "\n\tThe pile: ";
            pile.print_card();
            cout << "\n\n";
            
            //obtain the card/index the user wants to play
            want_to_play = turn()->print_info(card_index, pile);

            //user selected a card they cannot play
            if (legal_play(want_to_play) == 0)
                cout << "Error! You cannot play this card\n\n";

        } while (legal_play(want_to_play) == 0);

        //set the pile to the played card
        pile = turn()->get_hand()->get_card(card_index);
            
        //remove the card from the player's hand
        turn()->get_hand()->remove_card(card_index);

    } while (check_game_end() == 3);

    return check_game_end();
}