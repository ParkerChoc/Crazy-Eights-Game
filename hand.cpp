/******************************************************
** Program: hand.cpp
** Author: Parker Choc
** Date: 04/25/2021
** Description: all member functions of the Hand class
** Input: depends on function
** Output: depends on function
******************************************************/

#include "./card.h"
#include "./hand.h"

/*********************************************************************  
** Functions: Deck() (header for 4 functions)
** Description: Deck class constructors
** Parameters: the old hand or the number of cards for a hand to be 
**      initialized with
** Pre-Conditions: none
** Post-Conditions: initializes the Hand class
*********************************************************************/
//Constructor
    Hand::Hand()
    {
        n_cards = 0;
        hand_of_cards = nullptr;
    }
//Constructor
    Hand::Hand(int n)
    {
        n_cards = n;
        hand_of_cards = new Card[n_cards];
    }
//Copy Constructor
    Hand::Hand(const Hand& old_hand)
    {
        n_cards = old_hand.n_cards;
        hand_of_cards = new Card[n_cards];
        for (int i = 0; i < n_cards; i++)
        {
            hand_of_cards[i] = old_hand.hand_of_cards[i];
        }
        //cout << "Copy Contructor\n";
    }
//Assignment Operator Overload
    Hand& Hand::operator=(const Hand& old_hand)
    {
        n_cards = old_hand.n_cards;
        delete[] hand_of_cards;
        hand_of_cards = new Card[n_cards];
        for (int i = 0; i < n_cards; i++)
        {
            hand_of_cards[i] = old_hand.hand_of_cards[i];
        }
        //cout << "Assignment operator\n";
        return *this;
    }

/*********************************************************************  
** Function: ~Hand()
** Description: Hand class destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: deletes the array of cards from the heap
*********************************************************************/
    Hand::~Hand()
    {
        //cout << "\nHand Destructor Called\n";
        delete [] hand_of_cards;
    }

/*********************************************************************  
** Function: get_n_cards()
** Description: returns the number of cards in the hand
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the number of cards in the hand
*********************************************************************/
    int Hand::get_n_cards()
    {
        return n_cards;
    }

/*********************************************************************  
** Function: get_card()
** Description: returns the address of the specified card
** Parameters: int &index
** Pre-Conditions: the index of the card in the hand
** Post-Conditions: the card in hand based on the index
*********************************************************************/
    Card& Hand::get_card(int &index)
    {
        return hand_of_cards[index];
    }

/*********************************************************************  
** Function: print_hand()
** Description: prints out the hand to the screen
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: hand printed to the screen
*********************************************************************/
    void Hand::print_hand()
    {
        //All the code below just prints out the hand to make it look pretty
        for (int i = 0; i < n_cards; i++)
        {
            cout << "Card " << i + 1 << ": |";
            hand_of_cards[i].print_card();
            cout << "|\n";
        }
        cout << "\n";
    }

/*********************************************************************  
** Function: any_plays()
** Description: returns a card that can be played
** Parameters: Card &pile
** Pre-Conditions: the card that is on top of the pile
** Post-Conditions: a card that can be played
*********************************************************************/
    Card Hand::any_plays(Card &pile)
    {
        for (int i = 0; i < n_cards; i++)
        {
            if (get_card(i).get_rank() == pile.get_rank())
                return get_card(i);
            if (get_card(i).get_suit() == pile.get_suit())
                return get_card(i);
            if (get_card(i).get_rank() == 8)
                return get_card(i);
        }
        Card no_card(0, '@');
        return no_card;
    }

/*********************************************************************  
** Function: any_plays()
** Description: returns a card that can be played and modifies the
**      index to reflect that card
** Parameters: Card &pile, int &index
** Pre-Conditions: the card on top of the pile and an index variable
**      to be filled in
** Post-Conditions: a card that can be played, modified index variable
*********************************************************************/
    int Hand::any_plays(Card &pile, int &index)
    {
        /*
        ** this function is called after cards have 
        ** been drawn ensuring there is a possible play
        */
        
        for (int i = 0; i < n_cards; i++)
        {
            //loop through once and see if there is a non-8 card to play
            if (get_card(i).get_rank() != 8)
            {
                index = i;
                if (get_card(i).get_rank() == pile.get_rank())
                    return i;
                if (get_card(i).get_suit() == pile.get_suit())
                    return i;
            }
        }
    
        //the only available play is an 8
        for (int i = 0; i < n_cards; i++)
        {
            index = i;
            if (get_card(i).get_rank() == 8)
                return i;
        }
    }

/*********************************************************************  
** Function: replace_card()
** Description: replaces a specific index card with another card
** Parameters: Card cared_to_replace, int index
** Pre-Conditions: the card to replace, where the card is in the array
** Post-Conditions: a hand with a single card replaced with a
**         different card
*********************************************************************/
    void Hand::replace_card(Card card_to_replace, int index)
    {
        hand_of_cards[index] = card_to_replace;
    }

/*********************************************************************  
** Function: add_card()
** Description: adds a card to the hand
** Parameters: Card card_to_add
** Pre-Conditions: the card that is being added to the hand
** Post-Conditions: the hand now contains an additional card
*********************************************************************/
    void Hand::add_card(Card card_to_add)
    {
        //temp hand holds 1 more card
        Card* temp = new Card[n_cards + 1];   

        int counter = 0;
        for (int i = 0; i < n_cards; i++)
        {
            temp[i] = hand_of_cards[i];
            counter++;
        }
        temp[counter] = card_to_add;    
        //temp hand is now what the new hand should be

        delete[] hand_of_cards;
        n_cards += 1;
        hand_of_cards = new Card[n_cards];

        //copy all of temp into the hand of cards
        for (int i = 0; i < n_cards; i++)
            hand_of_cards[i] = temp[i];
        delete[] temp;
    }

/*********************************************************************  
** Function: remove_card()
** Description: removes a specific card from the hand
** Parameters: int index
** Pre-Conditions: the card number that will be removed
** Post-Conditions: the hand now does not contain the specified
**      card to be removed.
*********************************************************************/
    Hand& Hand::remove_card(int index)
    {     
        int counter = 0;
        //temp hand holds 1 fewer cards
        Card* temp = new Card[n_cards - 1];   

        for (int i = 0; i < n_cards; i++)
        {
            if (i != index)
            {
                temp[counter] = hand_of_cards[i];
                counter++;
            } 
        }
        //temp hand is now what the new hand should be

        delete[] hand_of_cards;
        n_cards -= 1;
        hand_of_cards = new Card[n_cards];

        //copy all of temp into the hand of cards
        for (int i = 0; i < n_cards; i++)
            hand_of_cards[i] = temp[i];
        delete[] temp;

        return *this;
    }