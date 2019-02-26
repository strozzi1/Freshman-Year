#include "world.h"
#include <iostream>
#include <cstdlib>

using namespace std;
/******************************************************
** Program: Creature.cpp
** Author: Joshua Michael Strozzi
** Date: 11 May, 2017
** Description: create creatures and battle them for money
** Input: names of creatures and whatnot
** Output: stats of creatures and battles
*****************************************************/
int main(){
    world w;
    char choice[5];
    int u;
    bool quit=false;
    do{
        do{
             cout<<"What would you like to do?\n[1] BATTLE!\n[2] View Creatures in world\n[3] Add Creatures to world\n[4] Quit \nChoice: ";
             cin>>choice;
             
        }while(atoi(choice) <1 || atoi(choice)>4 );
        u=atoi(choice);
       
        if(u==1){
            cout<<w.get_creature_num()<<endl;
            if(w.get_creature_num()>1){
                w.battle_start();
            }
            else
                cout<<"There are not enough creatures in your world"<<endl;
        }
        else if(u==2){
            w.display_creatures();
        }
        else if(u==3){
            w.add_creatures_menu();
        }
        else if(u==4){
            quit=true;
        }
    }while (quit==false);
   
    //w.add_human();
    //w.display_creatures();
    //w.create_human();
    //cout<<w.get_num_balrog()<<endl;
    return 0;
}
