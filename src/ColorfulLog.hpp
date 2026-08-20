#pragma once
#include "ILog.hpp"
#include <iostream>

class ColorfulLog : public ILog {
  private:
    void paint(std::string_view str, int color_code);

  public:
    void log(std::string_view str){
        paint(str, 96);
    }
    
    void print_8_colours();
};
