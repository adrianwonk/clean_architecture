#pragma once
#include "ICompositor.hpp"
#include "ILog.hpp"
#include "vec3.hpp"

class NCursesCompositor: ICompositor{
  private:
      ILog& logger;
  public:
    NCursesCompositor(ILog& logger):
        logger(logger)
    {}
    void update();
    void clear();
    void draw_centered( point3<double>&, DrawnObject& );
};
