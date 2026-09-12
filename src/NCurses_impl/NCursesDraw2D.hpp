#pragma once
#include "IDraw2D.hpp"
#include "ICompositor.hpp"
class NCursesDraw2D : IDraw2D{
  private:
    ICompositor& compositor;
  public:
    void draw(point3<double>&, std::string_view, DrawType);
    NCursesDraw2D(ICompositor& compositor):
        compositor(compositor){};
};
