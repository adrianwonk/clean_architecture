#pragma once
#include "ICompositor.hpp"
#include "IDraw2D.hpp"
#include "INCursesResxManager.hpp"
#include "ILog.hpp"
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

class NCursesHelloWorld : public ICompositor, public IDraw2D{
  private:
    INCursesResxManager& resx_manager;
    ILog& logger;
  public:
    // constructor and destructor
    NCursesHelloWorld(ILog& log, INCursesResxManager& resx):
        resx_manager(resx)
        ,logger(log)
    {
        resx_manager.init();
    }
    ~NCursesHelloWorld(){
        resx_manager.cleanup();
    }
    //

    void update(){
        refresh();
    }
    void clear(){
        erase();
    }

    void draw_centered(point3& pos, DrawnObject& obj){
        auto draw_pos {origin + pos};
        int x = draw_pos.x();
        int y = draw_pos.y();
        mvprintw(x,y,"%s\0",obj.str.data()); 
    }

    void draw(point3& pos, std::string_view str, DrawType type){
        if (type == DrawType::temp){
            DrawnObject res(str);
            draw_centered(pos, res);
        }
    }
};
