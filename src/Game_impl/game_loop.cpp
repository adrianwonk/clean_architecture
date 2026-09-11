#include "ICompositor.hpp"
#include "IDraw2D.hpp"
#include "DrawType.hpp"
#include "vec3.hpp"

namespace{
    vec3<double> pos {0,0,0};
}

void game(ICompositor& compositor
        , IDraw2D& drawer){
    compositor.clear();
    drawer.draw(pos, "hello world", DrawType::temp);
    compositor.update();
}
