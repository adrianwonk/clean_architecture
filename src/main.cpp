#include <iostream>
#include <ncurses.h>

#include "INCursesResxManager.hpp"
#include "NCursesHelloWorld.hpp"
#include "NCursesResxManager.hpp"

#include "IDraw2D.hpp"
#include "ICompositor.hpp"

#include "ColorfulLog.hpp"

#include <csignal>

int main();
void signal_handler(int);

/*
 * Responsibilities:
 *  - setting up ncurses
 *      - manage colors, window, terminal resx.
 *  - turning 0,0 relative coordinates into something ncurses understands.
 *      - printing text after understanding it. 
 */

using namespace std;
namespace{
    volatile std::sig_atomic_t running = 1;

    ColorfulLog colorful_ { std::clog }; // dependency 
    ILog& logger { colorful_ };
    NCursesResxManager ncur_resx_ { logger }; // dependency 
    INCursesResxManager& ncur_resx = ncur_resx_;

    // Hello world is the monolithic part of the codebase
    NCursesHelloWorld hello_world{ logger,ncur_resx };
}

void signal_handler(int signal){
    if (signal == SIGINT)
        running = 0;
}

int main(){
    std::signal(SIGINT, signal_handler);
    ICompositor& compositor = hello_world;
    IDraw2D& drawer = hello_world;
    vec3 pos {0,0,0};

    while(running == 1){
        compositor.clear();
        drawer.draw(pos, "hello world", DrawType::temp);
        compositor.update();
    }

}


