#include "NCursesDraw2D.hpp"
#include "ICompositor.hpp"
void NCursesDraw2D::draw(point3<double>& pos, std::string_view str, DrawType type){
    if (type == DrawType::ui){
        DrawnObject res(str);
        compositor.draw_centered( pos, res );
    }
}
