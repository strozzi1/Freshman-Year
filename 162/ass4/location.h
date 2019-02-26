#include <iostream>
#include "event.h"
#include <string>

#ifndef LOCATION_H
#define LOCATION_H


class location{
    private:
        event *e;
        //bool thing;
        int event_type;

    public:
        void set_event(event*);
        event * which_event(int);

        event * get_event();
        int get_type_event();
        void move();
        void set_event_type(int);
        void clear_event();
        
        bool call_catch(int);

        void operator=(const location&);
        //  getters/setters
        location();
        ~location();

};

#endif
