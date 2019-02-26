#include "location.h"
#include "pokemon.h"
#include <string>

#ifndef GAME_H
#define GAME_H

class game{
    private:
        location ** world;
        int x, y; //size of array
        int xpos, ypos; //position in array
        pokemon **pokedex;
        int numpokemon, megastones, pokeballs;
        bool done;
    public:
        game();
        
        void play();
        
        void set_up_world(int, int);
        void display_board();
        void swap_board();
        
        void move();  
        void actually_move();//called by move();
        char get_move();  //called by actually move();
        
        string check_left(int ); //called by check area
        string check_right(int ); //called by check area
        string check_up(int ); //called by check area
        string check_down(int); //called by check area
        void check_area();
        //big three
        void call_event(); //calls event that you are on
        
        bool have_all();
        bool maxed_all();
        
        void level_up_poke(); //checks if all are caught and at least one of each is fully maxed out
        void add_pokeballs();

        void catch_poke(int);
        void add_poke();
        pokemon * which_poke();
         //returns pokemon pointer to pokedex
        void move_poke();

        void zero_out();

        event * which_event(int);
        
        ~game();
};
#endif