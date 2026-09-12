#include "NCursesCompositor.hpp"
#include <ncurses.h>

namespace{
inline vec3<int> get_scrn(){
    int _width;
    int _height;
    getmaxyx(stdscr, _height, _width);
    return {_width, _height, 0 };
}

inline vec3<int> get_scrn_middle(){
    return get_scrn() / 2;
}
}

void NCursesCompositor::update(){
    refresh();

}
void NCursesCompositor::clear(){
    erase();
}
void NCursesCompositor::draw_centered( point3<double>& posd
        , DrawnObject& obj ){
        vec3<int> pos { posd };
        // vec3<int> draw_pos { origin + pos };
        vec3<int> origin = get_scrn_middle();
        vec3<int> draw_pos {};
        draw_pos = origin + pos;
        mvprintw( draw_pos.y(), draw_pos.x(), "%s", obj.str.data() ); 
}
