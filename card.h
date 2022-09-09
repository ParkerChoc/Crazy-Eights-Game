#ifndef H_Card
#define H_Card

using namespace std;

#include <iostream>

class Card
{
    private:
        int rank;
        char suit;
    
    public:
    //Constructor & Destructor
        Card();
        Card(int, char);
        ~Card();
    //Getters
        int get_rank();
        char get_suit();
    //Setters
        void set_rank(int);
        void set_suit(char);
    //Other
        void print_suit();
        void print_rank();
        void print_card();
};

#endif