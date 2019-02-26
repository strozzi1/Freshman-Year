#include "game.h"
#include "location.h"
#include "pokestop.h"
#include "cave.h"
#include "rock.h"
#include "flying.h"
#include "psychic.h"
#include "event.h"
#include "nothing.h"
//#include "location.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>


using namespace std;


/******************************************************
** Function: constructor
** Description: sets values for class
** Parameters: none
** Pre-conditions: a member of this class doesn't exist'
** Post-conditions: a member of this class exists and it's values have been set'
*****************************************************/


game::game(){
    x=0;
    y=0;
    xpos=0;
    ypos=0;

    numpokemon=0;
    megastones=0;
    pokeballs=0;

    done=false;

    world=NULL;
    pokedex=NULL;
}



/******************************************************
** Function: destructor
** Description: deletes all allocated memory for game object
** Parameters: none
** Pre-conditions: possible memory leaks 
** Post-conditions: allocated memory freed
*****************************************************/

game::~game(){
    
    //for (int i=0; i<x; i++){
      //  delete [] world[i];
    //}
    //delete [] world;
    for(int i=0; i<numpokemon; i++){
        delete [] pokedex[i];
    }
    //delete[] pokedex;
}   



/*
void zero_out(){
    for (int i=0; i<x; i++){
        delete [] world[i];
    }
    delete [] world;
    delete [] pokedex;
    world=NULL;
    pokedex=NULL;
    numpokemon=0;
    megastones=0; 
    pokeballs=0;
    xpos=0;
    ypos=0;
    
}
*/
/******************************************************
** Function: play
** Description: runs the actual game
** Parameters: none
** Pre-conditions: no game being played
** Post-conditions: game has been played
*****************************************************/


void game::play(){
    //bool done;
    //while not all pokemon are caught and not all are leveled up
    while(done==false){
        #ifndef DEBUG
        display_board();
        #endif
    //tell user what is near them, tell them where they can move, get movement move();
        check_area();
        move();
    //run event at that spot//call_event();
        call_event();
    //make function that checks if there are x number of any one pokemon and if so, delete the others and level the highest level one up or just ones of the same level and deletes the others
    //return bool if all pokemon are caught and are max level
        cout<<"------------------------------------------------------------------------"<<endl;
        done=maxed_all();

    }


}


/******************************************************
** Function: have_all
** Description: check if all pokemon are caught
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


bool game::have_all(){
    int p;
    bool all=false, p1=false, p2=false, p3=false, p4=false, p5=false, p6=false;
    for(int i=0; i<numpokemon; i++){
        p=(*pokedex[i]).get_event_type();
        switch(p){
            case 3: p1=true;
                break;
            case 4: p2=true;
                break;
            case 5: p3=true;
                break;
            case 6: p4=true;
                break;
            case 7: p5=true;
                break;
            case 8: p6=true;
                break;
            default: all=false;
        }

    }
    if(p1==true && p2==true && p3==true && p4==true && p5==true && p6==true){
        cout<<"You have captured all pokemon!"<<endl;
        all=true;
    }

    return all;
}


/******************************************************
** Function: maxed_all
** Description: returns bool if one of each pokemon is both caught and max level
** Parameters: none
** Pre-conditions: game is being played
** Post-conditions: game either continues or ends
*****************************************************/


bool game::maxed_all(){
    int p;
    bool all=false, p1=false, p2=false, p3=false, p4=false, p5=false, p6=false;
    for(int i=0; i<numpokemon; i++){
        cout<<"line 162"<<endl;
        cout<<"event type: "<<(*pokedex[i]).get_level()<<endl;
        p=(*pokedex[i]).get_event_type();
        if((*pokedex[i]).get_level()==3){
            switch(p){
                case 3: p1=true;
                    break;
                case 4: p2=true;
                    break;
                case 5: p3=true;
                    break;
                case 6: p4=true;
                    break;
                case 7: p5=true;
                    break;
                case 8: p6=true;
                    break;
                default: all=false;
            }
        }
    }
    if(p1==true && p2==true && p3==true && p4==true && p5==true && p6==true){
        cout<<"You have captured all pokemon, and maxed out at least one of each!"<<endl;
        all=true;
    }

    return all;
}


/******************************************************
** Function: set_up_world
** Description: allocates memory and defines size of array
** Parameters: the x and y values from command line prompts declaring array size
** Pre-conditions: no world array
** Post-conditions: array is made and pointers are set, and array is randomized
*****************************************************/


void game::set_up_world(int i, int j){
    x=i;
    y=j;
    location l;
    world=new location*[x];
    for(int i=0; i<x; i++){
        world[i]=new location[y];
    }
    int count=0;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            world[i][j].set_event(l.which_event(count++));
        }
    }
    display_board();
    swap_board();
    play();
    //display_board();
}


/******************************************************
** Function: display_board
** Description: read the name
** Parameters: none
** Pre-conditions: none
** Post-conditions: world displayed
*****************************************************/


void game::display_board(){
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(world[j][i].get_type_event()==1)
                cout<<"c";
            else if(world[j][i].get_type_event()==2)   
                cout<<"s";
            else if(world[j][i].get_type_event()>2 && world[i][j].get_type_event()<9)
                cout<<"p";
            else
                cout<<"0";
            
        }
        cout<<endl;
    }
}


/******************************************************
** Function: swap_board
** Description: randomizes the arrays event pointers
** Parameters: none
** Pre-conditions: array has events in non random order
** Post-conditions: events are randomly spread across the board
*****************************************************/


void game::swap_board(){
    srand(time(NULL));
    int randox, randoy, count=0;
    location temp;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){

            randox=rand()%(x-1);
            randoy=rand()%(y-1);

            temp=world[i][j];
            //cout<<i<<" "<<j<<" "<<randox<<" "<<randoy<<endl;
            world[i][j]=world[randox][randoy];
            world[randox][randoy]=temp;

        }
    }
    cout<<endl;
}


/******************************************************
** Function: move
** Description: displays where the user can move according to where they are in the array
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


void game::move(){
    cout<<"You are at position "<< xpos<< " from the left and "<< ypos<< " from the top"<<endl;
    if(xpos==0){
        if(ypos==0){cout<<"You can move Right or Down"<<endl; }
        else if(ypos>0 && ypos<(y-1)){cout<<"You can move Up, Down, or Right"<<endl;}
        else if(ypos==(y-1)){cout<<"You can move Right, or Up"<<endl;}
    }
    else if(xpos>0 && xpos<(x-1)){
        if(ypos==0){cout<<"You can move Right, left, or Down"<<endl;}
        else if(ypos>0 && ypos<(y-1)){cout<<"You can move Up, Down, Left,or Right"<<endl;}
        else if(ypos==(y-1)){cout<<"You can move Right, Left, or Up"<<endl;}
    }
    else if(xpos==(x-1)){
        if(ypos==0){cout<<"You can move left, or Down"<<endl;}
        else if(ypos>0 && ypos<(y-1)){cout<<"You can move Up, Down, or Left"<<endl;}
        else if(ypos==(y-1)){ cout<<"You can move Left, or Up"<<endl;}    
    }

    cout<<"What is your choice, use wasd keys to move up, left, down, or right, repsectively "<<endl;
    cout<<endl;
    actually_move();
}


/******************************************************
** Function: actually_move
** Description: changes the players position values 
** Parameters: none
** Pre-conditions: player is at position x and y
** Post-conditions: player is in a position 1 over, or up, or down from previous position
*****************************************************/


void game::actually_move(){
    char choice=get_move();
    if(choice=='w')
        ypos-=1;
    else if(choice=='a')
        xpos-=1;
    else if(choice=='d')
        xpos+=1;
    else if(choice=='s')
        ypos+=1;
}


/******************************************************
** Function: get_move
** Description: gets choice from user on where to move in array
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


char game::get_move(){
    char choice[5];
    char c;
    while(true){
        cout<<"choice:";
        cin>>choice;
        if(choice[0]=='w' || choice[0]=='a' || choice[0]=='s' || choice[0]=='d'){
            c=choice[0];
            break;
        }
    }
    return c;
}


/******************************************************
** Function: check_area
** Description: tells user what events are directly next to them
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


void game::check_area(){//displays all that is around you
    if(xpos==0){
        if(ypos==0){cout<<check_right(world[xpos+1][ypos].get_type_event())<<"\n"<<check_down(world[xpos][ypos+1].get_type_event())<<endl; }
        else if(ypos>0 && ypos<(y-1)){cout<<check_up(world[xpos][ypos-1].get_type_event())<<"\n"<<check_down(world[xpos][ypos-1].get_type_event())<<"\n"<<check_right(world[xpos+1][ypos].get_type_event())<<endl;}
        else if(ypos==(y-1)){cout<<check_right(world[xpos+1][ypos].get_type_event())<<"\n"<<check_up(world[xpos][ypos-1].get_type_event())<<endl;}
    }
    else if(xpos>0 && xpos<(x-1)){
        if(ypos==0){cout<<check_right(world[xpos+1][ypos].get_type_event())<<"\n"<<check_left(world[xpos-1][ypos].get_type_event())<<"\n"<<check_down(world[xpos][ypos+1].get_type_event())<<endl;}//rld
        else if(ypos>0 && ypos<(y-1)){cout<<check_up(world[xpos][ypos-1].get_type_event())<<"\n"<<check_down(world[xpos][ypos+1].get_type_event())<<"\n"<<check_left(world[xpos-1][ypos].get_type_event())<<"\n"<<check_right(world[xpos+1][ypos].get_type_event())<<endl;}//udlr
        else if(ypos==(y-1)){cout<<check_right(world[xpos+1][ypos].get_type_event())<<"\n"<<check_left(world[xpos-1][ypos].get_type_event())<<"\n"<<check_up(world[xpos][ypos-1].get_type_event())<<endl;}//rlu
    }
    else if(xpos==(x-1)){
        if(ypos==0){cout<<check_left(world[xpos-1][ypos].get_type_event())<<"\n"<<check_down(world[xpos][ypos+1].get_type_event())<<endl;} //ld
        else if(ypos>0 && ypos<(y-1)){cout<<check_up(world[xpos][ypos-1].get_type_event())<<"\n"<<check_down(world[xpos][ypos+1].get_type_event())<<"\n"<<check_left(world[xpos-1][ypos].get_type_event())<<endl;}//udl
        else if(ypos==(y-1)){ cout<<check_left(world[xpos-1][ypos].get_type_event())<<"\n"<<check_up(world[xpos][ypos-1].get_type_event())<<endl;}    //lu
    }
}


/******************************************************
** Function: check_left
** Description: displays what event pointer is left of the users current position
** Parameters: the integer value correlating to the event of the target event
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


string game::check_left(int t){
    string left;
    switch (t){
        case  1: left="There is a Cave to your left";
            break;
        case 2 : left="There is a pokestop to your left";
            break;
        case 3 : left ="There is a Geodude to your left";
            break;
        case 4 : left = "There is an Onyx to your left";
            break;
        case 5 : left="There is a Charizard to your left";
            break;
        case 6  : left= "There is a Rayquaza to your left";
            break;
        case 7: left= "There is a Mewtwo to your left";
            break;
        case 8 : left = "There is a Espeon to your left";
            break;
        default: left = " ";
    }
    return left;

}


/******************************************************
** Function: check_right
** Description: displays what event pointer is right of the users current position
** Parameters: the integer value correlating to the event of the target event
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


string game::check_right(int t){
    string right;
    switch (t){
        case  1: right="There is a Cave to your right";
            break;
        case 2 : right="There is a pokestop to your right";
            break;
        case 3 : right ="There is a Geodude to your right";
            break;
        case 4 : right = "There is an Onyx to your right";
            break;
        case 5 : right="There is a Charizard to your right";
            break;
        case 6  : right= "There is a Rayquaza to your right";
            break;
        case 7: right= "There is a Mewtwo to your right";
            break;
        case 8 : right = "There is a Espeon to your right";
            break;
        default: right = " ";
    }
    return right;

}


/******************************************************
** Function: check_up
** Description: displays what event pointer is above the users current position
** Parameters: the integer value correlating to the event of the target event
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


string game::check_up(int t){
    string up;
    switch (t){
        case  1: up="There is a Cave upwards";
            break;
        case 2 : up="There is a pokestop upwards";
            break;
        case 3 : up ="There is a Geodude upwards";
            break;
        case 4 : up = "There is an Onyx upwards";
            break;
        case 5 : up="There is a Charizard upwards";
            break;
        case 6  : up= "There is a Rayquaza upwards";
            break;
        case 7: up= "There is a Mewtwo upwards";
            break;
        case 8 : up = "There is a Espeon upwards";
            break;
        default: up = " ";
    }
    return up;

}


/******************************************************
** Function: check_down
** Description: displays what event pointer is below the users current position
** Parameters: the integer value correlating to the event of the target event
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


string game::check_down(int t){
    string down;
    switch (t){
        case  1: down="There is a Cave downwards";
            break;
        case 2 : down="There is a pokestop downwards";
            break;
        case 3 : down ="There is a Geodude downwards";
            break;
        case 4 : down = "There is an Onyx downwards";
            break;
        case 5 : down="There is a Charizard downwards";
            break;
        case 6  : down= "There is a Rayquaza downwards";
            break;
        case 7: down= "There is a Mewtwo downwards";
            break;
        case 8 : down = "There is a Espeon downwards";
            break;
        default: down = " ";
    }
    return down;

}


/******************************************************
** Function: call_event
** Description: calls necessary function of the event pointer at the target position in the array
** Parameters: none
** Pre-conditions: player is in position x,y
** Post-conditions: event at x,y is called
*****************************************************/


void game::call_event(){
    int r=world[xpos][ypos].get_type_event();
        switch (r){
        case  1: cout<<"You came across a cave and found a megastone! All your pokemon have been leveled up by 1"<<endl;
            level_up_poke();
            break;
        case 2 : cout<<"You found a pokestop!"<<endl;
            add_pokeballs();
            break;
        case 3 : if (pokeballs>0){ catch_poke(r);}
            break;
        case 4 : if (pokeballs>0){ catch_poke(r);}
            break;
        case 5 : if (pokeballs>0){ catch_poke(r);}
            break;
        case 6  : if (pokeballs>0){ catch_poke(r);}
            break;
        case 7: if (pokeballs>0){ catch_poke(r);}
            break;
        case 8 : if (pokeballs>0) { catch_poke(r);}
            break;
        default: cout<<"";
    }
}


/******************************************************
** Function: catch_poke
** Description: calls functions that lead to the functions that catch the pokemon, then adds it to the pokedex
** Parameters: the integer connected to the event type 
** Pre-conditions: player landed on pokemon event pointer
** Post-conditions: player may have pokemon added to pokedex
*****************************************************/


void game::catch_poke(int m){
    bool caught;
    if(m==3 || m==4){
        cout<<"You've come across a rock type pokemon, and are attempting to catch it"<<endl;
        caught=world[xpos][ypos].call_catch(m);
    }
    else if(m==5 || m==6){
        cout<<"You've come across a flying type pokemon, and are attempting to catch it"<<endl;
        caught=world[xpos][ypos].call_catch(m);
    }
    else if(m==7 || m==8){
        cout<<"You've come across a psychic type pokemon, and are attempting to catch it"<<endl;    
        caught=world[xpos][ypos].call_catch(m);
    }
    else cout<<"The program is broken here at line 275 in game.cpp"<<endl;

    if(caught==true){
        add_poke();//addpokemon to 
        //move_poke();
    }
    else{
        //move_poke();//move pokemon
        
    }
    pokeballs-=1;
    cout<<"You now have "<<pokeballs<<" pokeballs"<<endl;
}


/******************************************************
** Function: add_poke
** Description: adds pokemon to pokemon type array (pokedex)
** Parameters: none
** Pre-conditions: pokemon was caught
** Post-conditions: pokemon array grew by one
*****************************************************/


void game::add_poke(){
        cout<<numpokemon<<endl;
        pokemon **temp=new pokemon*[numpokemon+1];
        //cout<<"line 409, add_poke() "<<numpokemon<<endl;
        if(numpokemon>0){
            for(int i=0; i<numpokemon; i++){
                //cout<<"line 412, add_poke()"<<endl;
                temp[i]=pokedex[i];
            }
        }
        //cout<<"line 416, add_poke()"<<endl;
        temp[numpokemon++]=which_poke();
        //cout<<"line 418, add_poke()"<<endl;
        //pokedex=temp;
        delete [] pokedex;
        pokedex=temp;
        cout<<"You now have "<<numpokemon<< " in your pokedex:"<<endl;
            for(int i=0; i<numpokemon; i++){
                cout<<(*pokedex[i]).get_name()<<"   lv: "<<(*pokedex[i]).get_level()<<endl;
            }
        cout<<endl;
        //move_poke();
    



}


/******************************************************
** Function: which_pokemon
** Description: returns a pokemon pointer 
** Parameters: none
** Pre-conditions: event pointer for pokemon event in array doesn't have pokemon event
** Post-conditions: event pointer at x,y location has pokemon pointer
*****************************************************/


pokemon * game::which_poke(){
    pokemon * pm;
    switch (world[xpos][ypos].get_type_event()){
        case 3 : pm =(new rock(1));
            break;
        case 4 : pm = (new rock(2));
            break;
        case 5 : pm = (new flying(1));
            break;
        case 6  :pm = (new flying(2));
            break;
        case 7: pm = (new psychic(1));
            break;
        case 8 : pm = (new psychic(2));
            break;

    }
    return pm;
}


/******************************************************
** Function: move_poke
** Description: moves pokemon somewhere else in array if pokemon escapes
** Parameters: none
** Pre-conditions: pokemon is at location of user
** Post-conditions: pokemon is displaced to some random other position
*****************************************************/

void game::move_poke(){
    srand(time(NULL));
    int randox, randoy, count=0;
    event* e1=new nothing;
    location temp;
    while(true){
            randox=rand()%(x-1);
            randoy=rand()%(y-1);
        if(world[randox][randoy].get_type_event()==0){
            world[randox][randoy].clear_event();
            
            world[randox][randoy].set_event(which_event(world[x][y].get_type_event()));
            
            world[randox][randoy].set_event_type(world[x][y].get_type_event());
            world[xpos][ypos].set_event(e1);
            world[xpos][ypos].set_event_type(0);

            break;
        }
    }

    cout<<endl;

}
/*
void game::move_poke(){
    srand(time(NULL));
    int randox, randoy, count=0;
    location temp;
    while(true){
            randox=rand()%(x-1);
            randoy=rand()%(y-1);
        if(world[randox][randoy].get_type_event()==0){
            temp=world[xpos][ypos];
            world[xpos][ypos]=world[randox][randoy];
            world[randox][randoy]=temp;
            break;
        }
    }

    cout<<endl;

}*/
/******************************************************
** Function: which_event
** Description: I don't use this anymore'
** Parameters: the event number
** Pre-conditions: whatever
** Post-conditions: whatever
*****************************************************/
event* game::which_event(int t){
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
** Function: level_up_poke
** Description: levels up all pokemon in pokedex array
** Parameters: none
** Pre-conditions: all pokemons are level x
** Post-conditions: now are level x+1
*****************************************************/
void game::level_up_poke(){
    for(int i=0; i<numpokemon; i++){
        if((*pokedex[i]).get_level()<3)
        (*pokedex[i]).level_up();
    }
}

/******************************************************
** Function: add_pokeballs
** Description: adds pokeballs to user
** Parameters: none
** Pre-conditions: has x pokeballs
** Post-conditions: has x+r pokeballs
*****************************************************/
void game::add_pokeballs(){
    int r=rand()%7+3;
    pokeballs+=r;
    cout<<"You currently have "<<pokeballs<<" pokeballs"<<endl;
}