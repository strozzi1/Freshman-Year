#include "pokemon.h"
#include <string>
#ifndef PSYCHIC_H
#define PSYCHIC_H

class psychic : public pokemon {
    private:

    public:
        psychic();
        psychic(int);
        bool catch_attempt();
};
#endif
