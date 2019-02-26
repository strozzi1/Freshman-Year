#include <string>

#ifndef CREATURE_H
#define CREATURE_H

using namespace std;


class creature {
    protected:
        int type;
        int strength;
        int hitpoints;
        string name;
        double payoff;
        double cost;
        string getSpecies(); //Returns species type
    public:
        creature();//initialize to human, 10 strength, 10 hp
        creature(int newType, int newStrength, int newHit);//initialize creature to new type, strength, and hp
        int get_damage();//returns amount of damage this creature inflicts in one round of combat
        void input_name();

        void update_HP(int dmg);

        int get_cost();
        int get_HP();
        int get_strength();
        double get_payout();
        string get_name();
        

    };

#endif 
