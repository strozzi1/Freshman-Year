#include "pokemon.h"
#include <string>
#ifndef ROCK_H
#define ROCK_H

class rock : public pokemon {
    private:

    public:
        rock();
        rock(int);
        bool catch_attempt();

};
#endif