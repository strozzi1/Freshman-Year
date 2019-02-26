
#include <string>
#ifndef EVENT_H
#define EVENT_H

class event {
    protected:
        int t; //1-cave, 2-pokestop, 3-8 :pokemon


    public:
        event();
        int get_type();
        //virtual bool catch_attempt()=0;
        


};
#endif
