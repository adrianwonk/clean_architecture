#pragma once
#include "ICompositor.hpp"
#include "ILog.hpp"
#include "vec3.hpp"

class NCursesCompositor : public ICompositor {
  private:
    ILog& logger;
  public:
    void update() = 0;
    void clear() = 0;
    point3 compose_pos(point3&); // optimise potential
    NCursesCompositor(ILog&);
};
