#include "ICompositor.hpp"
#include "IDraw2D.hpp"
#include "DrawType.hpp"
#include "vec3.hpp"
#include "Game.hpp"

namespace{
    vec3<double> pos {-5,0,0};
}

void Game::loop(ICompositor& compositor
        , IDraw2D& drawer){
    compositor.clear();
    drawer.draw(pos, "hello world", DrawType::ui);
    compositor.update();
}
