#pragma once
#include "ICompositor.hpp"
#include "IVisualResx.hpp"
#include "IDraw2D.hpp"
#include "ILog.hpp"
#include "vec3.hpp"
#include <format>
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

class NCursesHelloWorld : public ICompositor, public IDraw2D{
  private:
    IVisualResx& resx_manager;
    ILog& logger;
  public:
    // constructor and destructor
    NCursesHelloWorld(ILog& log, IVisualResx& resx):
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

    void draw_centered(point3<double>& posd, DrawnObject& obj){
        vec3<int> pos { posd };
        
        // vec3<int> draw_pos { origin + pos };
        vec3<int> origin = get_scrn_middle();
        vec3<int> draw_pos {};
        draw_pos = origin + pos;

        mvprintw( draw_pos.y(), draw_pos.x(), "%s", obj.str.data() ); 
    }

    void draw(vec3<double>& pos, std::string_view str, DrawType type){
        if (type == DrawType::temp){
            logger.log(std::format("drawing {}.", str));
            DrawnObject res(str);
            logger.log(std::format("drawing {}.", res.str.data()));

            draw_centered( pos, res );
        }
    }
};
