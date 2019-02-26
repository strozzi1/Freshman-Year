#include "flying.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>
#include <unistd.h>

using namespace std; 

/******************************************************
** Function: constructor
** Description: sets values for class
** Parameters: none
** Pre-conditions: a member of this class doesn't exist'
** Post-conditions: a member of this class exists and it's values have been set'
*****************************************************/


flying::flying(){
    type=2;
    name="Charizard";
    level=1;
}


/******************************************************
** Function: non-default constructor
** Description: sets values for class
** Parameters: none
** Pre-conditions: a member of this class doesn't exist
** Post-conditions: a member of this class exists and it's values have been set based on values passed to it
*****************************************************/


flying::flying(int a){
    type=2;
    level=1;
    which=a;
    if(which==1){
        name="Charizard";
        t=5;
    }
    else if(which==2){
        name="Rayquaza";
        t=6;
    }    
}


/******************************************************
** Function: catch_attempt
** Description: determines if the pokemon is caught and returns a bool
** Parameters: none
** Pre-conditions: user lands on space with this type pokemon
** Post-conditions: a pokemon either is or is not added to the pokedex
*****************************************************/


bool flying::catch_attempt(){
    bool caught=false;
    srand(time(NULL));
    int r=rand()%100;
    cout<<".";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<"."<<endl;
    sleep(1);
    if(r<51){
        cout<<"You have caught the flying type pokemon!"<<endl;
        caught=true;
    }
    else    
        cout<<"The flying pokemon has run away!"<<endl;
    return caught;
}