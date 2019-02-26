#include "world.h"
#include <cstdlib>
#include <iostream>


/******************************************************
** Function: world
** Description: constructor
** Parameters: none
** Pre-conditions: world variables not set
** Post-conditions: they are now set
*****************************************************/


world::world(){
    //creatures=NULL;
    balrogs=NULL;
    humans=NULL;
    elves=NULL;
    cyberdemons=NULL;
    
    money=100;
    num_human=0;
    num_elves=0;
    num_balrog=0;
    num_cyberdemon=0;
    num_creature=0;

    int opp1_type=0;
    int opp2_type=0;
    int opp1_pos=0;
    int opp2_pos=0;
}


/******************************************************
** Function: get_money
** Description: returns int of money
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


int world::get_money(){
    return money;
}

/******************************************************
** Function: get_num_humans
** Description: returns int of number of humans
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


int world::get_num_humans(){
    return num_human;
}

/******************************************************
** Function: get_num_cyberdemon
** Description: returns number of cyberdemons
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


int world::get_num_cyberdemon(){
    return num_cyberdemon;
}

/******************************************************
** Function: get_num_balrogs
** Description: returns number of balrogs in world
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/
int world::get_num_balrog(){
    return num_balrog;
}

/******************************************************
** Function: get_num_elves
** Description: returns number of elves
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


int world::get_num_elves(){
    return num_elves;
}

/******************************************************
** Function: get_creature_num
** Description: returns number of creatures in the world 
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


int world::get_creature_num(){
    return num_creature;
}

/******************************************************
** Function: battle
** Description: opponents take turns attacking til one has less than 1 health
** Parameters: none
** Pre-conditions: there are x number of creatures in world
** Post-conditions: there are now x-1 creatures in world
*****************************************************/


void world::battle(){
    int attack1, attack2;
    while(true){
        cout<<"Opponent one: ";
        attack1=get_dmg(opp1_type, opp1_pos);
        hit_creature(opp2_type, opp2_pos, attack1);
        view_opp(opp2_type, opp2_pos);
        if(get_HP(opp2_type, opp2_pos)<1){
            cout<<"The winner is: ";
            view_opp(opp1_type, opp1_pos);
            cout<<"\nThe loser is: ";
            view_opp(opp2_type, opp2_pos);
            cout<<"money before: "<<money<<endl;
            get_pay(opp2_type, opp2_pos);
            cout<<"money after: "<<money<<endl;
            remove_loser(opp2_type);
            break;
        }
        cout<<"opponent two: ";
        attack2=get_dmg(opp2_type, opp2_pos);
        hit_creature(opp1_type, opp1_pos, attack2);
        view_opp(opp1_type, opp1_pos);
    
        if(get_HP(opp1_type, opp1_pos)<1){
            cout<<"The winner is: ";
            view_opp(opp1_type, opp1_pos);
            cout<<"\nThe loser is: ";
            view_opp(opp1_type, opp1_pos);
            cout<<"money before:"<<money<<endl;
            get_pay(opp1_type, opp1_pos);
            cout<<"money after: "<<money<<endl;
            remove_loser(opp1_type);
            break;
        }

    }
}


/******************************************************
** Function: get_pay
** Description: returns payout to world money based on what creature it is
** Parameters: numbers corresponding to type of creature and creatures position in the array
** Pre-conditions: creature has been defeated
** Post-conditions: world has more money 
*****************************************************/


void world::get_pay(int type, int pos){
    switch(type){
        case 0:
            money+=humans[pos].get_payout();
            break;
        case 1:
            money+=cyberdemons[pos].get_payout();
            break;
        case 2:
            money+=balrogs[pos].get_payout();
            break;
        case 3:
            money+=elves[pos].get_payout();
            break;

    }
}

/******************************************************
** Function: remove_loser
** Description: calls remove dead based on which type is passed in
** Parameters: integer corres. to type
** Pre-conditions: a creature won and one lost
** Post-conditions: remove dead function called
*****************************************************/


void world::remove_loser(int type){
    switch(type){
        case 0:
            remove_dead_human(num_human);
            break;
        case 1:
            remove_dead_cyber(num_cyberdemon);
            break;
        case 2:
            remove_dead_balrog(num_balrog);
            break;
        case 3:
            remove_dead_elf(num_elves);
            break;

    }
}

/******************************************************
** Function:  set_opp1_type
** Description: gets number corres. to type and calls view avail creatures function
** Parameters: int of type
** Pre-conditions: there's no opponent one'
** Post-conditions: type of creature of opp1 is known
*****************************************************/

void world::set_opp1_type(int type){
    opp1_type=type;
    view_avail_opp1(type);

}
/******************************************************
** Function: set_opp2_type
** Description: same as opp1 but for opp2 
** Parameters: int of type
** Pre-conditions: same
** Post-conditions: same
*****************************************************/
void world::set_opp2_type(int type){
    opp2_type=type;
    view_avail_opp2(type);

}
/******************************************************
** Function: set_opp1_pos
** Description: gets number for where in creatures array the opponent is
** Parameters: int for position
** Pre-conditions: theres no opponent 1 yet
** Post-conditions: there is now an opponent 1
*****************************************************/
void world::set_opp1_pos(int pos){
    opp1_pos=pos;
        cout<<"You chose ";
    view_opp(opp1_type,opp1_pos);
        //cout<<"line 128"<<endl;
}
/******************************************************
** Function: set_opp2_pos
** Description: same as set_opp1_pos but for opp2
** Parameters: int of position
** Pre-conditions: same
** Post-conditions: same
*****************************************************/
void world::set_opp2_pos(int pos){
    opp2_pos=pos;
        cout<<"You chose ";
    view_opp(opp2_type,opp2_pos);
}



//hi

/******************************************************
** Function: battle_start
** Description: calls set opp1 functions
** Parameters: none
** Pre-conditions: there are no opponents
** Post-conditions: there are opponents and battle functions were called
*****************************************************/

void world::battle_start(){
    int choice;
    bool player1=false,player2=false;
    cout<<"Which type would you like to add to battle?\n[1]Add Human\n[2]Add cyberdemon\n[3]Add Balrog\n[4]Add Elf\n[5]Quit\n";
    choice=return_choice(1,5);
    while(player1==false){
    switch(choice){
        case 1:
            
            if(num_human>0){
                set_opp1_type(0);
            player1=true;
            }
            break;
        case 2:
            if(num_cyberdemon>0){
                set_opp1_type(1);
            player1=true;
            }
            break;
        case 3:
            if(num_balrog>0){
                set_opp1_type(2);
            player1=true;
            }
            break;
        case 4:
            if(num_elves>0){
                set_opp1_type(3);
            player1=true;
            }
            break;
        case 5:
            break;
    }
    }
    cout<<"Time to choose player 2"<<endl;
    if(player1==true){
        battle_start_opp2();
        cout<<"Press enter to begin the fight"<<endl;
        cin.ignore();
        battle();
    }


}


/******************************************************
** Function:  battle_start_opp2
** Description: same as battle_start but for opp2
** Parameters: none
** Pre-conditions: same
** Post-conditions: we know the second opponent
*****************************************************/


void world::battle_start_opp2(){
    int choice;
    cout<<"Which type would you like to add to battle as opponent 2?\n[1]Add Human\n[2]Add Cyberdemon\n[3]Add Balrog\n[4]Add Elf\n[5]Quit\n";
    choice=return_choice(1,5);
    switch(choice){
        case 1:
            cout<<"# humans"<<num_human<<endl;
            if(num_human>0)
                set_opp2_type(0);
            break;
        case 2:
            cout<<"# of cybers:"<< num_cyberdemon<<endl;
            if(num_cyberdemon>0)
                set_opp2_type(1);
            break;
        case 3:
            cout<<"# balrogs: "<<num_balrog<<endl;
            if(num_balrog>0)
                set_opp2_type(2);
                break;
        case 4:
            cout<<"num elves "<<num_elves<<endl;
            if(num_elves>0)
                set_opp2_type(3);
            break;
        case 5:
            break;

    }
    //battle();


}


/******************************************************
** Function: view_avail_opp1
** Description: sees available opponents
** Parameters: integer of what type of creature
** Pre-conditions: user hasn't chosen an opponent '
** Post-conditions: we have opponent type and position in array
*****************************************************/


void world::view_avail_opp1(int type){
    cout<<"Available for battle: "<<endl;
    switch(type){
        case 0:
            for(int i=0; i<num_human; i++){
                cout<<"Human "<< i<<": "<< humans[i].get_name()<<" HP: "<<humans[i].get_HP()<<" STR: "<<humans[i].get_strength()<<endl;
            }
            cout<<"\nWhich would you like to add?\nInput corresponding position number: ";
            set_opp1_pos(return_choice(0, num_human-1));
            break;
        case 1:
            for(int i=0; i<num_cyberdemon; i++){
                cout<<"Cyberdemon "<< i<<": "<< cyberdemons[i].get_name()<<" HP: "<<cyberdemons[i].get_HP()<<" STR: "<<cyberdemons[i].get_strength()<<endl;
            }
            set_opp1_pos(return_choice(0, num_cyberdemon-1));
            break;
        case 2:
            for(int i=0; i<num_balrog; i++){
                cout<<"Balrog "<< i<<": "<< balrogs[i].get_name()<<" HP: "<<balrogs[i].get_HP()<<" STR: "<<balrogs[i].get_strength()<<endl;
            }
            set_opp1_pos(return_choice(0, num_balrog-1));
            break;
        case 3:
            for(int i=0; i<num_elves; i++){
                cout<<"Elf "<< i<<": "<< elves[i].get_name()<<" HP: "<<elves[i].get_HP()<<" STR: "<<elves[i].get_strength()<<endl;
            }
            set_opp1_pos(return_choice(0, num_elves-1));
            break;
        case 4:
            break;

    }

}


/******************************************************
** Function: view_avail_opp2
** Description: same as view_avail_opp1 but for opp2
** Parameters: int for type of creature
** Pre-conditions: same
** Post-conditions: same
*****************************************************/


void world::view_avail_opp2(int type){
    cout<<"Available for battle: "<<endl;
    switch(type){
        case 0:
            for(int i=0; i<num_human; i++){
                if(type!=opp1_type || i!=opp1_pos)
                    cout<<"Human "<< i<<": "<< humans[i].get_name()<<" HP: "<<humans[i].get_HP()<<" STR: "<<humans[i].get_strength()<<endl;
            }
            cout<<"\nWhich would you like to add?\nInput corresponding position number: ";
            set_opp2_pos(return_choice(0, num_human-1));
            break;
        case 1:
            for(int i=0; i<num_cyberdemon; i++){
                if(type!=opp1_type || i!=opp1_pos)
                    cout<<"Cyberdemon "<< i<<": "<< cyberdemons[i].get_name()<<" HP: "<<cyberdemons[i].get_HP()<<" STR: "<<cyberdemons[i].get_strength()<<endl;
            }
            set_opp2_pos(return_choice(0, num_cyberdemon-1));
            break;
        case 2:
            for(int i=0; i<num_balrog; i++){
                if(type!=opp1_type || i!=opp1_pos)
                    cout<<"Balrog "<< i<<": "<< balrogs[i].get_name()<<" HP: "<<balrogs[i].get_HP()<<" STR: "<<balrogs[i].get_strength()<<endl;
            }
            set_opp2_pos(return_choice(0, num_balrog-1));
            break;
        case 3:
            for(int i=0; i<num_elves; i++){
                if(type!=opp1_type || i!=opp1_pos)
                     cout<<"Elf "<< i<<": "<< elves[i].get_name()<<" HP: "<<elves[i].get_HP()<<" STR: "<<elves[i].get_strength()<<endl;
            }
            set_opp2_pos(return_choice(0, num_elves-1));
            break;
        case 4:
            break;

    }

}


/******************************************************
** Function: return_choice
** Description: returns int for choice, repeats if loop is not satisfied
** Parameters: lower and upper lims of what number you want back
** Pre-conditions: none (all purpose)
** Post-conditions: none specific
*****************************************************/


int world::return_choice(int lowerlim, int upperlim){
    char choice[5];
    int u;
    do{
        cout<<"Choice:";
        cin>>choice;
    }while(atoi(choice) <lowerlim || atoi(choice) >upperlim);
    u=atoi(choice);
    return u;
}


/******************************************************
** Function: hit_creature
** Description: calls update_hp for whatever creature for whatever damage
** Parameters: type of creature and where in array that was damage and the amount of dmg
** Pre-conditions: creature hasn't lost HP from hit'
** Post-conditions: HP lost after a hit
*****************************************************/



void world::hit_creature(int type, int pos, int dmg){
    switch(type){
        case 0:
            humans[pos].update_HP(dmg);
            break;
        case 1:
            cyberdemons[pos].update_HP(dmg);
            break;
        case 2:
            balrogs[pos].update_HP(dmg);
            break;
        case 3:
            elves[pos].update_HP(dmg);
            break;
    }
}



/******************************************************
** Function: add_human
** Description: adds human to array and calls function to resize array and takes out money
** Parameters: none
** Pre-conditions: there x humans
** Post-conditions: theres x+1 humans in array
*****************************************************/



void world::add_human(){
    human h;
    string input;
    cout<<"What would your human's name be?: ";
    //cin.ignore();
    h.input_name();
    rez_human(num_human);
    humans[num_human-1]=h;
    num_creature++;
    money-=h.get_cost();


}


/******************************************************
** Function: rez_human
** Description: does resizing of array
** Parameters: number of humans
** Pre-conditions: there are x elements in human array
** Post-conditions: there are x+1 elements in human array
*****************************************************/


void world::rez_human(int size){
    human *temp;
    temp= new human[++size];
    for(int i=0; i<num_human; i++){
        temp[i]=humans[i];
    }
    if(humans != NULL)
        delete [] humans;

    humans=temp;
    num_human+=1;
    cout<<"There are "<<num_human<<" humans."<<endl;
}


/******************************************************
** Function: remove_dead_human
** Description: transfers alive humans to new array, deletes old array, sets old pointer to temp
** Parameters: number of humans before removing dead humna
** Pre-conditions: human array is size x
** Post-conditions: human array is size x-1
*****************************************************/


void world::remove_dead_human(int size){
    human *temp;
    temp= new human[--size];
    for(int i=0; i<num_human; i++){
        if(humans[i].get_HP()>1)    
            temp[i]=humans[i];
    
    }
    if(humans != NULL)
        delete [] humans;

    humans=temp;
    num_human-=1;
}


/******************************************************
** Function: add_elf
** Description:just like human but for elves
** Parameters: none
** Pre-conditions: same 
** Post-conditions: same
*****************************************************/


void world::add_elf(){
    elf e;
    string input;
    cout<<"What would your elf's name be?: ";
    //cin.ignore();
    e.input_name();
    rez_elf(num_elves);
    elves[num_elves-1]=e;
    num_creature++;
    money-=e.get_cost();


}


/******************************************************
** Function: rez_elf
** Description: see rez_human
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void world::rez_elf(int size){
    elf *temp;
    temp= new elf[++size];
    for(int i=0; i<num_elves; i++){
        temp[i]=elves[i];
    }
    if(elves != NULL)
        delete [] elves;

    elves=temp;
    num_elves+=1;
}


/******************************************************
** Function: remove_dead_elf
** Description: see remove_dead_human
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void world::remove_dead_elf(int size){
    elf *temp;
    temp= new elf[--size];
    for(int i=0; i<num_elves; i++){
        if(elves[i].get_HP()>1)
            temp[i]=elves[i];
    }
    if(elves != NULL)
        delete [] elves;

    elves=temp;
    num_elves-=1;
}

/******************************************************
** Function: add_cyber
** Description: see add_human
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void world::add_cyber(){
    cyberdemon c;
    string input;
    cout<<"What would your human's name be?: ";
    //cin.ignore();
    c.input_name();
    rez_cyber(num_cyberdemon);
    cyberdemons[num_cyberdemon-1]=c;
    num_creature++;
    money-=c.get_cost();


}


/******************************************************
** Function: rez_cyber
** Description: see rez_human
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void world::rez_cyber(int size){
    cyberdemon *temp;
    temp= new cyberdemon[++size];
    for(int i=0; i<num_cyberdemon; i++){
        temp[i]=cyberdemons[i];
    }
    if(cyberdemons != NULL)
        delete [] cyberdemons;

    cyberdemons=temp;
    num_cyberdemon+=1;
}


/******************************************************
** Function: remove_dead_cyber
** Description: see remove_dead_human
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void world::remove_dead_cyber(int size){
    cyberdemon *temp;
    temp= new cyberdemon[--size];
    for(int i=0; i<num_cyberdemon; i++){
        if(cyberdemons[i].get_HP()>1)
            temp[i]=cyberdemons[i];
    }
    if(cyberdemons != NULL)
        delete [] cyberdemons;

    cyberdemons=temp;
    num_cyberdemon-=1;
}


/******************************************************
** Function: add_balrog
** Description: same as add_human
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void world::add_balrog(){
    balrog b;
    string input;
    cout<<"What would your human's name be?: ";
    //cin.ignore();
    b.input_name();
    rez_balrog(num_balrog);
    balrogs[num_balrog-1]=b;
    num_creature++;
    money-=b.get_cost();


}


/******************************************************
** Function: rez_balrog
** Description: same as rez_human
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void world::rez_balrog(int size){
    balrog *temp;
    temp= new balrog[++size];
    for(int i=0; i<num_balrog; i++){
        temp[i]=balrogs[i];
    }
    if(balrogs != NULL)
        delete [] balrogs;

    balrogs=temp;
    num_balrog+=1;
}


/******************************************************
** Function: remove_dead_balrog
** Description: same as remove_dead_human
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void world::remove_dead_balrog(int size){
    balrog *temp;
    temp= new balrog[--size];
    for(int i=0; i<num_balrog; i++){
        if(balrogs[i].get_HP()>1)
            temp[i]=balrogs[i];
    }
    if(balrogs != NULL)
        delete [] balrogs;

    balrogs=temp;
    num_balrog-=1;
}

/*
void world::create_human(){
    //h = new human[1];
    //cout<<h[0].get_name();
}
*/

/******************************************************
** Function: display_creatures
** Description: displays all creatures in the world
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


void world::display_creatures(){
    cout<<endl;
    cout<<"There are "<<get_creature_num()<<" creatures in the world:\n"<<endl;
    for(int i=0; i<num_elves; i++){
        cout<<"Elf "<< i<<": "<< elves[i].get_name()<<" HP: "<<elves[i].get_HP()<<" STR: "<<elves[i].get_strength()<<endl;
    }
    cout<<endl;
    for(int i=0; i<num_human; i++){
        cout<<"Human "<< i<<": "<< humans[i].get_name()<<" HP: "<<humans[i].get_HP()<<" STR: "<<humans[i].get_strength()<<endl;
    }
    cout<<endl;
    for(int i=0; i<num_balrog; i++){
        cout<<"Balrog "<< i<<": "<< balrogs[i].get_name()<<" HP: "<<balrogs[i].get_HP()<<" STR: "<< balrogs[i].get_strength()<<endl;
    }
    cout<<endl;
    for(int i=0; i<num_cyberdemon; i++){
        cout<<"Cyberdemon "<< i<<": "<< cyberdemons[i].get_name()<<" HP: "<<cyberdemons[i].get_HP()<<" STR: "<<cyberdemons[i].get_strength()<<endl;
    }
    cout<<endl;
}


/******************************************************
** Function: add_creatures_menu
** Description: choose what creature you want to add to world
** Parameters: none
** Pre-conditions: none
** Post-conditions: add creature function has been called
*****************************************************/


void world::add_creatures_menu(){
    char choice[5];
    int u;
    do{
        cout<<"What would you like to do?\n[1]Add Human\n[2]Add elf\n[3]Add Cyberdemon\n[4]Add Balrog\n[5]Nevermind\nChoice:";
        cin>>choice;
    }while(atoi(choice) <1 || atoi(choice) >5);
    u=atoi(choice);

    if(u==1){
        add_human();
    }
    else if(u==2){
        add_elf();
    }
    else if(u==3){
        add_cyber();
    }
    else if(u==4){
        add_balrog();
    }
    else
        cout<<"Add Creature function cancelled."<<endl;
}


/******************************************************
** Function: get_dmg
** Description: calls get_damage functions 
** Parameters: ints for type of creature and position in array
** Pre-conditions: creature has been attacked
** Post-conditions: HP has been updated
*****************************************************/


int world::get_dmg(int type, int pos){
    int dmg;
    switch(type){
        case 0:
            dmg=humans[pos].get_damage();
            break;
        case 1:
            dmg=cyberdemons[pos].get_damage();
            break;
        case 2:
            dmg=balrogs[pos].get_damage();
            break;
        case 3:
            dmg=elves[pos].get_damage();
            break;

    }
    return dmg;
}


/******************************************************
** Function: get_HP
** Description: returns HP int
** Parameters: int for type and position
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


int world::get_HP(int type, int pos){
    int HP;
    switch(type){
        case 0:
            HP=humans[pos].get_HP();
            break;
        case 1:
            HP=cyberdemons[pos].get_HP();
            break;
        case 2:
            HP=balrogs[pos].get_HP();
            break;
        case 3:
            HP=elves[pos].get_HP();
            break;

    }
    return HP;
}


/******************************************************
** Function: view_opp
** Description: displays opponent with stats
** Parameters: int type and position in array
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


void world::view_opp(int type, int pos){
    switch(type){
        case 0:
            cout<<"Human: "<<humans[pos].get_name() <<" has "<<humans[pos].get_HP()<< " Health"<<endl;
            break;
        case 1:
            cout<<"Cyberdemon: "<<cyberdemons[pos].get_name()<<" has "<<cyberdemons[pos].get_HP()<<" Health"<<endl;
            break;
        case 2:
            cout<<"Balrog: "<<balrogs[pos].get_name()<<" has "<<balrogs[pos].get_HP()<<" health"<<endl;
            break;
        case 3:
            cout<<"Elf "<<elves[pos].get_name()<<" has "<<elves[pos].get_HP()<<" health"<<endl;
            break;
    }
}






/******************************************************
** Function: ~world
** Description: deletes dynamic memory
** Parameters: none
** Pre-conditions: memory leaks potentially
** Post-conditions: no memory leaks
*****************************************************/

world::~world(){

    delete [] humans;
    delete [] balrogs;
    delete [] elves;
    delete [] cyberdemons;
}



