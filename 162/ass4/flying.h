#include "pokemon.h"
#include <string>


#ifndef FLYING_H
#define FLYING_H

class flying : public pokemon {
        
    public:
        flying();
        flying(int);
        bool catch_attempt();
};
#endif
