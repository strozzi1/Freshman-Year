#include "event.h"
#include <string>


/******************************************************
** Function: constructor
** Description: sets values for class
** Parameters: none
** Pre-conditions: a member of this class doesn't exist'
** Post-conditions: a member of this class exists and it's values have been set'
*****************************************************/


event::event(){
    t=0;
}


/******************************************************
** Function: get_type
** Description: returns int value correlated to the type of event at that position in the array
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


int event::get_type(){
    return t;
}
