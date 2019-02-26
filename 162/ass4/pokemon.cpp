#include "pokemon.h"
#include <string>
#include <iostream>
using namespace std;


/******************************************************
** Function: constructor
** Description: sets values for class
** Parameters: none
** Pre-conditions: a member of this class doesn't exist'
** Post-conditions: a member of this class exists and it's values have been set'
*****************************************************/


pokemon::pokemon(){
    type=0; //1-rock, 2-flying 3-psychic
    t=0;
    name="unknown";
    level=1;
    which=0;
    //t=2;
}


/******************************************************
** Function: non-default constructor
** Description: sets values for class according to values in parameters
** Parameters: none
** Pre-conditions: a member of this class doesn't exist'
** Post-conditions: a member of this class exists and it's values have been set'
*****************************************************/


pokemon::pokemon(int a, int b){
    type=a;
    which=b;
    level=1;
    name="unknown";
    t=3;
}


/******************************************************
** Function: get_event_type
** Description: returns int value for type of event
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


int pokemon::get_event_type(){
    return t;
}


/******************************************************
** Function: get_level
** Description: returns integer of level of pokemon
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


int pokemon::get_level(){
    return level;
}


/******************************************************
** Function: get_name
** Description: returns string of name of pokemon
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


string pokemon::get_name(){
    return name;
}


void pokemon::level_up(){
    if (level <3)
        level+=1;
}
