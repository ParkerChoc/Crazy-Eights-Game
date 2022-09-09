/******************************************************
** Program: card.cpp
** Author: Parker Choc
** Date: 04/25/2021
** Description: all member functions of the Card class
** Input: depends on function
** Output: depends on function
******************************************************/

#include "card.h"

/*********************************************************************  
** Functions: Card() (next 2 functions)
** Description: Card class constructors
** Parameters: int r, char s or none
** Pre-Conditions: the rank and suit or nothing
** Post-Conditions: Card class filled up with default info (0 H) or 
**      filled up with specific info
*********************************************************************/
    Card::Card()
    {
        rank = 0;
        suit = 'H';
    }

    Card::Card(int r, char s)
    {
        rank = r;
        suit = s;
    }

/*********************************************************************  
** Function: ~Card()
** Description: Card class destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Card class deleted
*********************************************************************/
    Card::~Card()
    {
        //cout << "Card Destructor Called\n";
    }
    
/*********************************************************************  
** Function: get_rank()
** Description: returns the rank of the card
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the rank of the card
*********************************************************************/
    int Card::get_rank()
    {
        return rank;
    }

/*********************************************************************  
** Function: get_suit()
** Description: returns the suit of the card
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the suit to the card
*********************************************************************/
    char Card::get_suit()
    {
        return suit;
    }

/*********************************************************************  
** Function: set_rank()
** Description: sets the rank of the card to a specific integer
** Parameters: int r
** Pre-Conditions: the rank I want to set the card to
** Post-Conditions: the card now has the rank I have given it
*********************************************************************/
    void Card::set_rank(int r)
    {
        rank = r;
    }

/*********************************************************************  
** Function: set_suit()
** Description: sets the suit of the card to a specific char
** Parameters: char s
** Pre-Conditions: the char I want to set the suit of the card to
** Post-Conditions: the card now has the suit I have given it
*********************************************************************/
    void Card::set_suit(char s)
    {
        suit = s;
    }

/*********************************************************************  
** Function: print_suit()
** Description: prints the suit of the card in a user - friendly format
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the suit of the card is printed to the screen
*********************************************************************/
    void Card::print_suit()
    {
        switch(suit)
        {
            case 'C' :
                cout << "Clubs";
                break;
            case 'D' :
                cout << "Diamonds";
                break;
            case 'H' :
                cout << "Hearts";
                break;
            case 'S' :
                cout << "Spades";
                break;
            default :
                cout << "Error!";
        }
    }

/*********************************************************************  
** Function: print_rank()
** Description: prints the rank of the card in a user - friendly format
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the rank of the card is printed to the screen
*********************************************************************/
    void Card::print_rank()
    {
        switch(rank)
        {
            case 11 :
                cout << "Jack";
                break;
            case 12 :
                cout << "Queen";
                break;
            case 13 :
                cout << "King";
                break;
            case 1 :
                cout << "Ace";
                break;
            default :
                cout << rank;
        }
    }

/*********************************************************************  
** Function: print_card()
** Description: prints the card in a user frindly format
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the card printed to the screen 
*********************************************************************/
    void Card::print_card()
    {
        print_rank();
        cout << " ";
        print_suit();
    }