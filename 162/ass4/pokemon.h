#include <string>
#include "event.h"
using namespace std;
#ifndef POKEMON_H
#define POKEMON_H

class pokemon : public event{
    protected:
        int type;
        string name;
        int level; //up to 2
        int which;
        


    public:
        pokemon();
        pokemon(int, int);//type, which of the type
        int get_event_type();//3geodude 4onyx 5charizard 6rayquaza 7mewtwo 8-Espeon
        int get_level();
        string get_name();
        void level_up();
        virtual bool catch_attempt()=0;

        
};
#endif

