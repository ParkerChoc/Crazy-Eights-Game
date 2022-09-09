/******************************************************
** Program: deck.cpp
** Author: Parker Choc
** Date: 04/25/2021
** Description: all member functions of the Deck class
** Input: depends on function
** Output: depends on function
******************************************************/

#include "./card.h"
#include "./deck.h"

/*********************************************************************  
** Function: Deck()
** Description: Deck class constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: game class filled with default info
*********************************************************************/
    Deck::Deck()
    {
        cards_left = 51;
        for (int i = 0; i < 52; i++)
        {
            my_cards[i].set_rank(0);
            my_cards[i].set_suit('!');
        }
    }
 
/*********************************************************************  
** Function: ~Deck()
** Description: Deck class destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Game class deleted
*********************************************************************/
    Deck::~Deck()
    {
        //cout << "Deck Destructor Called\n";
    }

/*********************************************************************  
** Function: get_card()
** Description: returns the specific card in the deck
** Parameters: int index
** Pre-Conditions: the specific card number in the deck
** Post-Conditions: returns a card from the deck
*********************************************************************/
    Card Deck::get_card(int index)
    {
        return my_cards[index];
    }

/*********************************************************************  
** Function: get_cards_left()
** Description: returns the number of cards left in the deck
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: integer of how many cards are left in the deck
*********************************************************************/
    int Deck::get_cards_left()
    {
        return cards_left;
    }

/*********************************************************************  
** Function: set_card()
** Description: sets a card in the deck to be a given card at a given
**      index
** Parameters: int index, Card card
** Pre-Conditions: the index of the card and the card itself
** Post-Conditions: sets the card in the deck to be a new card
*********************************************************************/
    void Deck::set_card(int index, Card card)
    {
        my_cards[index] = card;
    }

/*********************************************************************  
** Function: swap()
** Description: switches the placement of two cards in the deck
** Parameters: Card *xp, Card *yp
** Pre-Conditions: two card pointers
** Post-Conditions: the two cards have swapped memory locations
*********************************************************************/  
    void Deck::swap(Card *xp, Card *yp)
    {
        Card temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

/*********************************************************************  
** Function: fill_deck()
** Description: fills the deck with all 52 cards
** Parameters: none
** Pre-Conditions: deck to fill
** Post-Conditions: returns the address of the deck that has been
**      filled up with cards (all suits and ranks --52)
*********************************************************************/
    Deck& Deck::fill_deck()  //all 52 cards (4 suits, 13 ranks)
    {
        char suits[] = { 'D', 'C', 'H', 'S', '\0' }; 
        int counter = 0;
        for(int j = 0; j < 4; j++)
        {
            for(int i = 0; i < 13; i++)
            {
                my_cards[counter].set_rank(i+1);
                my_cards[counter].set_suit(suits[j]);
                counter++;
            }
        }
        return *this;
    }

/*********************************************************************  
** Function: shuffle()
** Description: rearanges the order of cards in the deck randomly
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: shuffled deck
*********************************************************************/
    Deck& Deck::shuffle()
    {
	    srand(time(NULL));

	    for (int i = 0; i < 52; i++)
	    {
			//finds a random location to insert
            int placement = i + rand() % (52-i);
            swap(&my_cards[placement], &my_cards[i]);
            //inspired by simmilar shuffle code found on:
            // https://www.geeksforgeeks.org/shuffle-a-deck-of-cards-3/	    
	    }
        return *this;
    }

/*********************************************************************  
** Function: print_deck()
** Description: prints out the deck
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: deck printed to the screen
*********************************************************************/
    void Deck::print_deck()
    {
        int counter = 0;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 13; j++)
            {
                cout << "|";
                my_cards[counter].print_card();
                counter++;
            }
            cout << endl;
        }
    }

/*********************************************************************  
** Function: take_card()
** Description: returns a card from the deck and replaces it with a
**      null card
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the top card of the deck returned, replaced with
**      a null card
*********************************************************************/
    Card Deck::take_card()
    {  
        Card taken_card;
        
        //set up the taken card values
        taken_card.set_rank(my_cards[cards_left].get_rank());
        taken_card.set_suit(my_cards[cards_left].get_suit());

        //make a "null card" in the deck where the card used to be
        my_cards[cards_left].set_rank(0);
        my_cards[cards_left].set_suit('!');

        cards_left -= 1;
        return taken_card;
    }