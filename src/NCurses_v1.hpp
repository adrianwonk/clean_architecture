#pragma once
#include "INCurses.hpp"
#include "NCursesConfig.hpp"
#include <iostream>

class NCurses_v1 : public INCurses {
  private:
    NCursesConfig config;

  public:
    NCurses_v1() : 
        config()
    { std::cout << "hello NCurses_v1 constructor" << x + var << '\n'; }

    void init() {
        std::cout<<"hello NCurses_v1 init"<< '\n';

    }
};
