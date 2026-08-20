#include "ColorfulLog.hpp"
void ColorfulLog::print_8_colours(){
    std::cout << "ColorfulLog color table:" << std::endl;

    for (int i = 0; i < 108; i++){
        if (i % 9 == 0 && i != 0)
            std::cout << std::endl;
        printf("\033[%dm %3d\033[m", i, i);
    }

    std::cout << std::endl;
}

void ColorfulLog::paint(std::string_view str, int color_code){
    std::cout << "\033["
        <<
            color_code
        << "m " <<
            str
        << "\033[m" << '\n'
    ;
}
