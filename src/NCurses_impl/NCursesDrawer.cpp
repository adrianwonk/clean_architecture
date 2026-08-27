#include "NCursesDrawer.hpp"
#include "ICompositor.hpp"

NCursesDrawer::NCursesDrawer(ILog& log, ICompositor& com):
    logger(log),
    compositor(com)
{}

void NCursesDrawer::draw(int x, int y, std::string_view str, DrawType t){
    
}
