/******************************************************
** Program: driver.cpp
** Author: Parker Choc
** Date: 04/25/2021
** Description: runs the entire game of crazy eights
** Input: player name
** Output: prompt if player wishes to play again
******************************************************/

#include "./card.h"
#include "./deck.h"
#include "./hand.h"
#include "./player.h"
#include "./game.h"

#include <string>

/*********************************************************************  
** Function: print_game_end()
** Description: prints who wins the game
** Parameters: int &game_end, string &player_name
** Pre-Conditions: the integer specifying who has won, the player name
** Post-Conditions: winner info printed to the screen
*********************************************************************/
void print_game_end(int &game_end, string &player_name)
{
    switch (game_end)
    {
        case 0 :
            cout << "Computer player win!\n";
            break;
        case 1 :
            cout << player_name << " win!\n";
            break;
        default :
            cout << "The game is a tie!\n";
    }
}

/*********************************************************************  
** Function: get_player_name()
** Description: gets the user's name
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the name the player has selected
*********************************************************************/
string get_player_name()
{
    int answer;
    string player_name;
    do
    {
        answer = 1;
        cout << "Enter player name: ";
        cin >> player_name;
        cout << "\n";
        if (player_name == "robot")
        {
            cout << "you chose robot. If you continue, 2 computers will play \n";
            cout << "against eachother. (1 - continue) (0 - select a new name)\n";
            cin >> answer;
        }
    } while (answer == 0);
    return player_name;
}

/*********************************************************************  
** Function: main()
** Description: runs the game of crazy 8s, promps the user if they wish
**      to play again after the game is done
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int main()
{    
    int answer = 0;  
    const int starting_hand = 7;
    int game_end;

    do
    {
        string player_name = get_player_name();

        //sets up the game
        Game crazy_8_s("robot", player_name, starting_hand);
        game_end = crazy_8_s.run_game();
    
        //prints out the game ending
        print_game_end(game_end, player_name);

        cout << "Do you want to play again? (1-yes) (0-no)\n";
        cin >> answer;
    } while (answer == 1);
    
    return 0;
}