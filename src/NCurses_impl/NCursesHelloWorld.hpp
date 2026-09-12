#pragma once
#include "ICompositor.hpp"
#include "IVisualResx.hpp"
#include "IDraw2D.hpp"
#include "ILog.hpp"
#include "vec3.hpp"
#include <ncurses.h>
#include "NCursesDraw2D.hpp"

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

class NCursesHelloWorld : public ICompositor, public IDraw2D{
  private:
    IVisualResx& resx_manager;
    ILog& logger;
    NCursesDraw2D drawer;
  public:
    // constructor and destructor
    NCursesHelloWorld(ILog& log, IVisualResx& resx):
        resx_manager(resx)
        ,logger(log)
        ,drawer(*this)
    {
        logger.log("IMPL: NCursesHelloWorld created. (ICompositor, IDraw2D)");
        resx_manager.init();
    }
    ~NCursesHelloWorld(){
        resx_manager.cleanup();
    }

    void update(){
        refresh();
    }
    void clear(){
        erase();
    }

    void draw_centered(point3<double>& posd, DrawnObject& obj){
        vec3<int> pos { posd };
        
        // vec3<int> draw_pos { origin + pos };
        vec3<int> origin = get_scrn_middle();
        vec3<int> draw_pos {};
        draw_pos = origin + pos;

        mvprintw( draw_pos.y(), draw_pos.x(), "%s", obj.str.data() ); 
    }

    inline void draw(vec3<double>& pos, std::string_view str, DrawType type){
        drawer.draw(pos, str, type);
    }
};
