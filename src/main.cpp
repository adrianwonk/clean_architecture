#include <iostream>
#include <ncurses.h>
#include "INCursesResxManager.hpp"
#include "NCursesHelloWorld.hpp"

#include "ColorfulLog.hpp"

/* 
 * i would like to add a ncurses dependency.
 *  main -> ncurses
 * However, there are a lot of ncurses setup code.
 * Theses are VOLATILE CONCRETE components.
 * We want to avoid dependency to our ncurses setup, BECAUSE we change main to add changes, we change ncurses setup to configure ncurses.
 * Therefore, main -> INCurses. INCurses <- NCurses_v1.
     * main is protected from changes to NCurses_v1.
     * However, we still need to define implementation of INCurses.
     * Create in stack, keep constructor simple, and pass it into interface reference instantly.
 * */ 

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
    ColorfulLog colorful {std::cout};
    ILog& logger { colorful };
    NCursesHelloWorld hi{ logger };

    INCursesResxManager& p = hi;
    IDraw2D& draw = hi;
}

int main(){
    p.init();

    draw.draw(0,0,"hello world", DrawType::temp);
    
    p.cleanup();			/* End curses mode		  */
}


