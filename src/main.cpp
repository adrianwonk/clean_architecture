#include <iostream>
#include <ncurses.h>
#include <csignal>
#include "NCursesHelloWorld.hpp"
#include "NCursesResxManager.hpp"
#include "IDraw2D.hpp"
#include "ICompositor.hpp"
#include "ColorfulLog.hpp"
#include "Game.hpp"

namespace{
    extern IVisualResx& ncur_resx;
    extern ILog& logger;

    ColorfulLog colorful_ { std::clog }; // dependency 
    NCursesResxManager ncur_resx_ { logger }; // dependency 
    NCursesHelloWorld hello_world{ logger, ncur_resx }; // monolithic dependency
    Game game {};

    ILog& logger { colorful_ };
    IVisualResx& ncur_resx { ncur_resx_ };
    ICompositor& compositor { hello_world };
    IDraw2D& drawer { hello_world };

    volatile std::sig_atomic_t running = 1;
}

void signal_handler(int signal){
    if (signal == SIGINT)
        running = 0;
}

int main(){
    std::signal(SIGINT, signal_handler);
    while(running == 1){
        game.loop(compositor, drawer);
    }
}


