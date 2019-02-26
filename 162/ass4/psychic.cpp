#include "psychic.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <unistd.h>


/******************************************************
** Function: constructor
** Description: sets values for class
** Parameters: none
** Pre-conditions: a member of this class doesn't exist'
** Post-conditions: a member of this class exists and it's values have been set'
*****************************************************/


psychic::psychic(){
    type=3;
    name="Mewtwo";
    level=1;
    which=1;
    t=7;
}

/******************************************************
** Function: non-default constructor
** Description: sets values for class
** Parameters: none
** Pre-conditions: a member of this class doesn't exist
** Post-conditions: a member of this class exists and it's values have been set based on values passed to it
*****************************************************/


psychic::psychic(int a){
    which=a;
    type=3;
    level=1;
    if(which==1){
        name="Mewtwo";
        t=7;
    }
    
    else if(which==2){
        name="Espeon";
        t=8;
    }
}

/******************************************************
** Function: catch_attempt
** Description: determines if the pokemon is caught and returns a bool
** Parameters: none
** Pre-conditions: user lands on space with this type pokemon
** Post-conditions: a pokemon either is or is not added to the pokedex
*****************************************************/


bool psychic::catch_attempt(){
    bool caught=false;
    srand (time(NULL));
    int r=rand()%100;
    cout<<".";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<"."<<endl;
    sleep(1);
    if(r<26){
        cout<<"You've caught the psychic type pokemon"<<endl;
        caught=true;    
    }
    else    
        cout<<"The psychic Pokemon got away"<<endl;
    return caught;
}