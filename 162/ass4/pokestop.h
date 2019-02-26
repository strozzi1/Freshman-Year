#include "event.h"
#include <string>

#ifndef POKESTOP_H
#define POKESTOP_H

class pokestop : public event{
    private:

    public:
        pokestop();
        int get_pokeballs();
};
#endif