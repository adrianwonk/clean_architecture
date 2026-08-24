#include "ColorfulLog.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

ColorfulLog::ColorfulLog(ostream& out):
    out(out)
{}

ColorfulLog::ColorfulLog():
    out(clog)
{}

void ColorfulLog::print_8_colours(){
    out << "ColorfulLog color table:" << std::endl;

    for (int i = 0; i < 108; i++){
        if (i % 9 == 0 && i != 0)
            out << std::endl;
        out << "\033["
            <<
                i
            << "m " << setw(3) <<
                i
            << "\033[m"
        ;
    }

    out << std::endl;
}

void ColorfulLog::paint(std::string_view str, int color_code){
    out << "\033["
        <<
            color_code
        << "m " <<
            str
        << "\033[m" << '\n'
    ;
}
