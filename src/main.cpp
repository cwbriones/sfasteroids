#include "Game.h"

#include <iostream>
#include <exception>

int main(int argc, const char *argv[])
{
    int retval = -1;

    try {
        Game game;
        retval = game.run();
    } catch (std::exception& e){
        std::cout << "\nERROR: " << e.what();
    }

    return retval;
}
