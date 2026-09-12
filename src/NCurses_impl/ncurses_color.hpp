// used by ncurses namespace
#ifndef NCURSES_COLOR_H
#define NCURSES_COLOR_H

#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include "vec3.hpp"

namespace color {

NCURSES_COLOR_T GRID_COLOR {COLOR_WHITE} ; // dedicate basic color to painting GRID (legacy code)
NCURSES_COLOR_T DEFAULT_BG_COLOR;
NCURSES_COLOR_T DEFAULT_FG_COLOR;

enum class col_pair : short {
    TERMINAL_DEFAULT, // cannot override
    DEFAULT,
    BIRD,
    WALL,
    GRID,
    SELECT
};


inline void override_color(NCURSES_COLOR_T CURSES_COLOR, vec3 color){
    if (can_change_color()) {
        init_color(CURSES_COLOR, color[0], color[1], color[2]);
    } else {
        std::cerr << "ERR: CANNOT REDEFINE COLOR " << CURSES_COLOR << " TO <" << color << '>' << '\n';
        std::exit(1);
    }
}

inline void get_default_colors(){
    if (pair_content(0,&DEFAULT_FG_COLOR, &DEFAULT_BG_COLOR) == ERR) {
        std::cerr << "ERR: CANNOT INITIALISE DEFAULT COLORS!" << '\n';
        std::exit(1);
    }
}

// 1. Color values override 2. color pair bitmask definition.
void _color_init(){
    // color definitions:
    get_default_colors(); // populate DEFAULT colors
    override_color(GRID_COLOR, {500,500,500} );
    //
    // pair definitions:
    init_pair(NCURSES_PAIRS_T(col_pair::DEFAULT), COLOR_CYAN, DEFAULT_BG_COLOR);
    init_pair(NCURSES_PAIRS_T(col_pair::BIRD), COLOR_GREEN, DEFAULT_BG_COLOR);
    init_pair(NCURSES_PAIRS_T(col_pair::WALL), COLOR_RED, DEFAULT_BG_COLOR);
    init_pair(NCURSES_PAIRS_T(col_pair::GRID), GRID_COLOR, DEFAULT_BG_COLOR);
    init_pair(NCURSES_PAIRS_T(col_pair::SELECT), COLOR_YELLOW, DEFAULT_BG_COLOR);

}

};


#endif
