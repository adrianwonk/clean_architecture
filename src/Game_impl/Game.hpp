#pragma once
#include "ICompositor.hpp"
#include "IDraw2D.hpp"
class Game {
  public:
    Game(){};
    void loop(ICompositor& compositor
            , IDraw2D& drawer);
};
