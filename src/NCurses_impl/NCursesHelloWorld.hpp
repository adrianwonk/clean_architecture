#pragma once
#include "ICompositor.hpp"
#include "IDraw2D.hpp"
#include "INCursesResxManager.hpp"
#include "ILog.hpp"
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

vec3<int> origin = get_scrn_middle();
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

    void draw_centered(point3<int>& pos, DrawnObject& obj){
        auto draw_pos {origin + pos};
        int x = draw_pos.x();
        int y = draw_pos.y();
        mvprintw(x,y,"%s\0",obj.str.data()); 
    }

    void draw(vec3<double>& pos, std::string_view str, DrawType type){
        if (type == DrawType::temp){
            DrawnObject res(str);
            draw_centered(static_cast<vec3 <int>>(pos), res);
        }
    }
};
