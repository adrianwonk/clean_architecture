#include "NCursesCompositor.hpp"
#include <ncurses.h>

namespace{

inline vec3 get_scrn(){
    int _width;
    int _height;
    getmaxyx(stdscr, _height, _width);
    return {double(_width), double(_height), 0 };
}

inline vec3 get_scrn_middle_clamped(){
    vec3 middle_float = get_scrn() / 2;
    return { double(middle_float.clampx()), double(middle_float.clampy()), 0. };
}

vec3 origin = get_scrn_middle_clamped();
}

NCursesCompositor::NCursesCompositor(ILog& log):
    logger(log)
{}

void NCursesCompositor::update(){
    refresh();
}

void NCursesCompositor::clear(){
    erase();
}
point3 NCursesCompositor::compose_pos(point3& pos){
    //input pos is relative to 0,0.        

    // we add that to our origin
    return origin + pos;
}

