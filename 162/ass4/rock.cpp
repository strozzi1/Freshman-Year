#include "rock.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <unistd.h>
#include <iostream>

using namespace std; 


/******************************************************
** Function: constructor
** Description: sets values for class
** Parameters: none
** Pre-conditions: a member of this class doesn't exist'
** Post-conditions: a member of this class exists and it's values have been set'
*****************************************************/


rock::rock(){
    type=1;
    name="Geodude";
    level=1;
    which=1;
    t=3;
}


/******************************************************
** Function: non-default constructor
** Description: sets values for class
** Parameters: none
** Pre-conditions: a member of this class doesn't exist
** Post-conditions: a member of this class exists and it's values have been set based on values passed to it
*****************************************************/


rock::rock(int a){
    which=a;
    type=1;
    level=1;
    if(which==1){
        name="Geodude";
        t=3;
    }
    else if(which==2){
        name="Onix";
        t=4;
    }
}


/******************************************************
** Function: catch_attempt
** Description: determines if the pokemon is caught and returns a bool
** Parameters: none
** Pre-conditions: user lands on space with this type pokemon
** Post-conditions: a pokemon either is or is not added to the pokedex
*****************************************************/


bool rock::catch_attempt(){
    bool caught=false;
    srand(time(NULL));
    int r=rand()%100;
    cout<<".";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<"."<<endl;
    sleep(1);
    if (r<76){
        cout<<"You caught the rock type pokemon"<<endl;
        caught=true;
        }
    else    
        cout<<"The rock type pokemon got away"<<endl;
    return caught;
}

