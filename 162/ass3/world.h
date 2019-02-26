#include "creature.h"
#include "elf.h"
#include "balrog.h"
#include "human.h"
#include "cyberdemon.h"
#include "demon.h"

#ifndef WORLD_H
#define WORLD_H


class world {
    private:
        //creature *creatures;
        human* humans;
        balrog* balrogs;
        elf* elves;
        cyberdemon* cyberdemons;

        double money;
        int num_human;
        int num_elves;
        int num_balrog;
        int num_cyberdemon;
        int num_creature;

        int opp1_type;
        int opp1_pos;
        int opp2_type;
        int opp2_pos;
    public:
        world();
        void battle(int, int);
        int get_money();
        int get_num_humans();
        int get_num_balrog();
        int get_num_elves();
        int get_num_cyberdemon();
        int get_creature_num();

        void battle_start(); //sets opponents and calls battle
        void battle_start_opp2();

        void set_opp1_type(int);
        void set_opp2_type(int);
        void set_opp1_pos(int);
        void set_opp2_pos(int);
        void view_avail_opp2(int);
        void view_avail_opp1(int);
        
        int return_choice(int, int);
        
        void add_creatures_menu();
        void display_creatures();



        void battle();
        void hit_creature(int, int, int); //update hitpoints
        
        int get_dmg(int, int);
        int get_HP(int, int);
        void view_opp(int, int);
        void get_pay(int, int);
        
        void remove_loser(int);


        void add_human();
        void rez_human(int);
        void remove_dead_human(int);

        void add_elf();
        void rez_elf(int);
        void remove_dead_elf(int);

        void add_cyber();
        void rez_cyber(int);
        void remove_dead_cyber(int);

        void add_balrog();
        void rez_balrog(int);
        void remove_dead_balrog(int);
        



        //void add_creature(int );
        ~world();
};

#endif