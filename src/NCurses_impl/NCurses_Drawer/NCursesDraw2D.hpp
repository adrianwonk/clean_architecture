#pragma once
#include "IDraw2D.hpp"
#include "ICompositor.hpp"
#include "ILog.hpp"
class NCursesDraw2D : IDraw2D{
  private:
    ICompositor& compositor;
    ILog& logger;
  public:
    void draw(point3<double>&, std::string_view, DrawType);
    NCursesDraw2D(ILog& logger, ICompositor& compositor):
        compositor(compositor),
        logger(logger)
    {};
};
