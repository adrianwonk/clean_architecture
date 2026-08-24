#pragma once
#include "ILog.hpp"
#include <iostream>

class ColorfulLog : public ILog {
  private:
    std::ostream& out;
    void paint(std::string_view str, int color_code);

  public:
    explicit ColorfulLog(std::ostream&);
    ColorfulLog();

    void log(std::string_view str){
        paint(str, 96);
    }
    
    void print_8_colours();
};
