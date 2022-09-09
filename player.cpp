/******************************************************
** Program: player.cpp
** Author: Parker Choc
** Date: 04/25/2021
** Description: all member functions of the Player class
** Input: depends on function
** Output: depends on function
******************************************************/

#include "./card.h"
#include "./deck.h"
#include "./hand.h"
#include "./player.h"

#include <iostream>
#include <cctype>

/*********************************************************************  
** Functions: Player() (the next 3 functions)
** Description: Player class constructors
** Parameters: int &i, string &n (some or none) 
** Pre-Conditions: the starting number of cards, the name (some or none)
** Post-Conditions: Player class filled with default info
*********************************************************************/
Player::Player()
{
    Hand hand;
    my_hand = hand;
    name = "no_name";
}

Player::Player(int &n)
{
    Hand hand(n);
    my_hand = hand;
    name = "no_name";
}

Player::Player(int &i, string &n)
{
    Hand hand(i);
    my_hand = hand;
    name = n;
}

/*********************************************************************  
** Function: ~Player()
** Description: Player class destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Player class destroyed
*********************************************************************/
Player::~Player()
{
    //cout << "Player Destructor Called\n";
}

/*********************************************************************  
** Function: get_hand()
** Description: returns the player's hand
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the player's hand
*********************************************************************/
Hand* Player::get_hand()
{
    return &my_hand;
}

/*********************************************************************  
** Function: get_name()
** Description: returns the player's name
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the player's name
*********************************************************************/
string Player::get_name()
{
    return name;
}

/*********************************************************************  
** Function: computer_plays_eight()
** Description: figures out what the computer should chose if it choses
**      to play an eight. Also displays their choice
** Parameters: int &index, int &selection, char &suit_choice
** Pre-Conditions: the index, the index of the card to be selected, the
**      suit choice the computer choses
** Post-Conditions: the index, selection, and suit choice variables
**      modified to reflect the computer's choice
*********************************************************************/
void Player::computer_plays_eight(int &index, int &selection, char &suit_choice)
{
    int zero = 0;   //function passes by reference so this is a dummy variable
    
    //the computer choses the suit of their first card in hand if they play an 8
    suit_choice = my_hand.get_card(zero).get_suit();
    get_hand()->get_card(selection).set_suit(suit_choice);
    cout << "\nWild Card! It chose ";
    my_hand.get_card(zero).print_suit();
}

/*********************************************************************  
** Function: get_selection()
** Description: returns the player's choice of what card they want to 
**      play as well as does some error trapping
** Parameters: int &selection
** Pre-Conditions: the selection variable address to be assigned
** Post-Conditions: the selection variable changed to match the 
**      user's choice
*********************************************************************/
void Player::get_selection(int &selection)
{
    do
    {
        my_hand.print_hand();
        cout << "Enter the card number you wish to play: ";
        cin >> selection;
        
        //make sure the user enters in a card # they actually have
        if ((selection > get_hand()->get_n_cards()) || (selection <= 0))
            cout << "Error! you must select a card number you have\n\n";

    } while ((selection > get_hand()->get_n_cards()) || (selection <= 0));
    
    selection --;
}

/*********************************************************************  
** Function: print_info()
** Description: prints information and returns the card that the user
**      wishes to play
** Parameters: int &index, Card &pile
** Pre-Conditions: the index variable to be modified and the pile card
** Post-Conditions: returned card that the user is going to play and 
**      a modified index variable to reflect that
*********************************************************************/
Card Player::print_info(int &index, Card &pile)
{
    int selection = 0;
    char suit_choice;
    cout << name << "'s turn\n\n";

    //if it is the computer's turn
    if (name == "robot")
    {
        //the computer chooses the first legal card that it can play in its hand
        selection = get_hand()->any_plays(pile, index);
        cout << "The computer played: ";
        get_hand()->get_card(selection).print_card();
        
        //The computer played an 8
        if (get_hand()->get_card(selection).get_rank() == 8)
            computer_plays_eight(index, selection, suit_choice);

        cout << "\nIt now has " << get_hand()->get_n_cards() - 1 << " total cards.\n\n";
    }
    else
    {
        //display the user hand and get their selection of card
        get_selection(selection);
        
        //The user played an 8
        if (get_hand()->get_card(selection).get_rank() == 8)
        {
            cout << "Wild Card! Enter a suit you wish to select (C, D, H, S): ";
            cin >> suit_choice;
            suit_choice = toupper(suit_choice); //converts suit choice to a capitol
            get_hand()->get_card(selection).set_suit(suit_choice);
        }
        index = selection;
    }
    return get_hand()->get_card(selection);
}