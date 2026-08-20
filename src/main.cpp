#include <iostream>
#include "INCurses.hpp"

#include "NCurses_v1.hpp"
#include "NewLineLog.hpp"
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

using namespace std;
void init() {
    std::cout<<"hello init"<< '\n';

    ColorfulLog logger {};
    logger.print_8_colours();
    NCurses_v1 ncur_setup{ logger }  ;
    INCurses& p = ncur_setup ;
    p.init()                 ;
}

int main(){
    cout << "hello main" << '\n';
    init();
}


