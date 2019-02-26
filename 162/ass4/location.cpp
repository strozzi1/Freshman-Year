#include "location.h"
#include "pokestop.h"
#include "cave.h"
#include "rock.h"
#include "flying.h"
#include "psychic.h"
#include "nothing.h"
#include <iostream>
#include "pokemon.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


/******************************************************
** Function: constructor
** Description: sets values for class
** Parameters: none
** Pre-conditions: a member of this class doesn't exist'
** Post-conditions: a member of this class exists and it's values have been set'
*****************************************************/


location::location() {
    e = NULL;
    event_type=0;
}


/******************************************************
** Function: destructor
** Description: deletes event pointer in location object
** Parameters: none
** Pre-conditions: memory leaks
** Post-conditions: memory on heap freed
*****************************************************/


location::~location(){
    delete [] e;
}


/******************************************************
** Function: set_event
** Description: sets event pointer to whatever event is passed to it
** Parameters: and event pointer
** Pre-conditions: e=NULL
** Post-conditions: e gets event pointer passed to it
*****************************************************/


void location::set_event(event *v){
    e=v;
}


/******************************************************
** Function: get_event
** Description: returns pointer to the event pointer of the location object
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


event * location::get_event(){
    return e;
}


/******************************************************
** Function: which_event
** Description: returns pointer for whatever event the player is on
** Parameters: the number related to the event
** Pre-conditions: array not set up with event pointers
** Post-conditions: array has event pointers set up at specifc location (and eventually all)
*****************************************************/


event* location::which_event(int t){
    event *e1;
    switch (t){
        case  1: e1= new cave;
            break;
        case 2 : e1= new pokestop;
            break;
        case 3 : e1 =(new rock(1));
            break;
        case 4 : e1 = (new rock(2));
            break;
        case 5 : e1 = (new flying(1));
            break;
        case 6  : e1= (new flying(2));
            break;
        case 7: e1= (new psychic(1));
            break;
        case 8 : e1 = (new psychic(2));
            break;
        default: e1 = new nothing;
    }
    return e1;
}


/******************************************************
** Function: get_type_event
** Description: returns number related to the event (getter)
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


int location::get_type_event(){
    return (*e).get_type();
}


/******************************************************
** Function: call_catch
** Description: calls catch_attempt (virtual) fuction and returns a bool of if its caught
** Parameters: number related to event number of specifi pokemon
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


bool location::call_catch(int m){
    bool caught=false;
    srand(time(NULL));
    int r=rand()%100;
    cout<<"."<<flush;
    sleep(1);
    cout<<"."<<flush;
    sleep(1);
    cout<<"."<<flush;
    sleep(1);
    if(m==7 || m==8){
        if(r<26){
            cout<<"You've caught the psychic type pokemon"<<endl;
            caught=true;    
        }
        else    
            cout<<"The psychic Pokemon got away"<<endl;
    }
    else if(m==5 || m==6){
        if(r<51){
            cout<<"You have caught the flying type pokemon!"<<endl;
            caught=true;
        }
        else    
            cout<<"The flying pokemon has run away!"<<endl;
    }
    else if(m==3 || m==4){
        if (r<76){
            cout<<"You caught the rock type pokemon"<<endl;
            caught=true;
        }
        else    
            cout<<"The rock type pokemon got away"<<endl;
    }
    
    return caught;
    //return e.catch_attempt();
}



void location:: operator=(const location &other){
    e=other.e;
    event_type=other.event_type;
}

void location::clear_event(){
    delete[]e;
    e=NULL;
}

void location::set_event_type(int m){
    event_type=m;
}
