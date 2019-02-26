#include <iostream>
#include "game.h"
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;




/******************************************************
** Program: Pokemon Go
** Author: Joshua Strozzi
** Date: 05/26/2017
** Description: Runs an augmented version of pokemon go for terminal
** Input: size of game world
** Output: game
******************************************************/

int main (int argc, char *argv[]){
    game g;
    srand (time(NULL));
    if(argc==3){
        if((atoi(argv[1])>2 && atoi(argv[2])>2) && (atoi(argv[1])<101 && atoi(argv[2])<101)){

            int x=atoi(argv[1]), y=atoi(argv[2]);
            g.set_up_world(x,y);
            
            cout<<"You'd you like to play again?"<<endl;
        }
        else
            cout<<"You're parameters are too small, please try again with numbers greater than 3"<<endl;
    }
    else{
        cout<<"Too few or too many arguments. You must have just 3."<<endl;
        g.set_up_world(4,4);
        //g.play();
    }
    return 0;
}