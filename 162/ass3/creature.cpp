
#include "creature.h"
#include <cstdlib>
#include <string>
#include <iostream>


/******************************************************
** Function: creature()
** Description: constructor
** Parameters:none
** Pre-conditions: creature variables have no values
** Post-conditions: they have values
*****************************************************/


creature::creature(){
    type=0;
    strength=10;
    hitpoints=10;
    name="unknown";
    payoff=50.00;
    cost=payoff;
 //   getSpecies();

}


/******************************************************
** Function: creature()
** Description: non default constructor
** Parameters: int newtype newstrength and newhit
** Pre-conditions: creature variable has default values
** Post-conditions: have non default values
*****************************************************/


creature::creature(int newType, int newStrength, int newHit){
    type=newType;
    strength=newStrength;
    hitpoints=newHit;
}


/******************************************************
** Function: getSpecies
** Description: returns species string
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/

string creature::getSpecies(){
    switch (type){
        case 0:
            return "Human";
        case 1:
            return "Cyberdemon";
        case 2:
            return "Balrog";
        case 3: 
            return "Elf";
    }
    return "Unknown";
}

/******************************************************
** Function: get_damage
** Description: returns damage value for whatever creature attacked
** Parameters: none
** Pre-conditions: creature has begun to attack
** Post-conditions: damage has been returned
*****************************************************/


int creature::get_damage( ) {
    int damage;// All creatures inflict damage, which is a

    damage = ( rand( ) % strength) + 1; // random number up to their strength
    cout << getSpecies( ) << " attacks for "<< damage << " points!" << endl; // Demons can inflict damage of 50 with a 5% chance
    if (( type == 2) || ( type == 1)){
        if (( rand( ) % 100) < 5) {
            damage = damage + 50;
            cout << " Demonic attack inflicts 50 "<< " additional damage points!" << endl;
        }// Elves inflict double magical damage with a 10% chance
    }
    
    if ( type == 3) {
        if (( rand( ) % 10)== 0) {
            cout << " Magical attack inflicts " << damage<< " additional damage points!" << endl;
            damage = damage * 2;
        }
    }// Balrogs are so fast they get to attack twice
    
    if ( type == 2) {
        int damage2 = ( rand() % strength) + 1;
        cout << " Balrog speed attack inflicts " << damage2<< " additional damage points!" << endl;
        damage = damage + damage2;
    }
    
    return damage;
}


/******************************************************
** Function: input_name
** Description: gets name for creature
** Parameters: none
** Pre-conditions: no name
** Post-conditions: now has a name
*****************************************************/


void creature::input_name(){
    string input;
    cin.clear();
    cin.ignore();
    getline(cin, input);
    name=input;
    //return name;
    
}


/******************************************************
** Function: get_cost
** Description: returns cost of creature
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/

int creature::get_cost(){
    return cost;
}

/******************************************************
** Function: get_HP
** Description: returns hitpoints of a creature
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


int creature::get_HP(){
    return hitpoints;
}


/******************************************************
** Function: get_strength
** Description: returns strength of creature
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


int creature::get_strength(){
    return strength;
}

/******************************************************
** Function: get_name
** Description: returns name of creature
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/

string creature::get_name(){
    return name;
}


/******************************************************
** Function: update_HP
** Description: removes amount of damage done from a creatures HP
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void creature::update_HP(int dmg){
    hitpoints-=dmg;
}


/******************************************************
** Function: get_payout
** Description: returns payoff amount
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


double creature::get_payout(){
    return payoff;
}



