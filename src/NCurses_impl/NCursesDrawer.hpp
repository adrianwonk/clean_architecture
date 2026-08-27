#pragma once
#include "IDraw2D.hpp"
#include "ILog.hpp"
#include "ICompositor.hpp"

class NCursesDrawer : public IDraw2D {
  private:
      ILog& logger;
      ICompositor& compositor;
  public:
    void draw(int, int, std::string_view, DrawType);
    explicit NCursesDrawer(ILog&, ICompositor&);
};
