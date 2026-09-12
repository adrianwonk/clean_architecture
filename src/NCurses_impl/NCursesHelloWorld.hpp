#pragma once
#include "ICompositor.hpp"
#include "IVisualResx.hpp"
#include "IDraw2D.hpp"
#include "ILog.hpp"
#include "NCursesCompositor.hpp"
#include "vec3.hpp"
#include <ncurses.h>
#include "NCursesDraw2D.hpp"

namespace{
}

class NCursesHelloWorld : public ICompositor, public IDraw2D{
  private:
    IVisualResx& resx_manager;
    ILog& logger;
    NCursesDraw2D drawer;
    NCursesCompositor compositor;
  public:
    // constructor and destructor
    NCursesHelloWorld(ILog& log, IVisualResx& resx):
        resx_manager(resx)
        ,logger(log)
        ,drawer(logger,*this)
        ,compositor(logger)

    {
        logger.log("IMPL: NCursesHelloWorld created. (ICompositor, IDraw2D)");
        resx_manager.init();
    }

    ~NCursesHelloWorld(){
        resx_manager.cleanup();
    }

    inline void update(){
        compositor.update();
    }

    inline void clear(){
        compositor.clear();
    }

    inline void draw_centered(point3<double>& posd, DrawnObject& obj){
        compositor.draw_centered(posd,obj);
    }

    inline void draw(vec3<double>& pos, std::string_view str, DrawType type){
        drawer.draw(pos, str, type);
    }
};
