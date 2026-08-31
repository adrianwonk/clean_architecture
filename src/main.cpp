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
 *  - painting our first hello world:
     *  - tracking where each paintable object is
     *  - painting each paintable object
 */

/* I would also like to add a logger to each component. setup would be a component, live ncurses calls would be a component, game engine would be a component.
 * 1. Logger
 * 2. setup
 * 3. NCurses_caller
 * 4. Game_engine
 * 5. main compositor (this)
 * */

using namespace std;
namespace{
    ColorfulLog colorful { std::clog }; // dependency 
    ILog& logger { colorful };
    NCursesResxManager resx{ logger }; // dependency 
    INCursesResxManager& iresx = resx;
    NCursesHelloWorld hello_world{ logger,iresx };

    volatile std::sig_atomic_t running = 1;
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


