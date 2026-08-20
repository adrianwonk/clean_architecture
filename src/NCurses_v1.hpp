#pragma once
#include "INCurses.hpp"
#include "ILog.hpp"

#include "NCursesConfig.hpp"
#include <iostream>

class NCurses_v1 : public INCurses {
  private:
    NCursesConfig config;
    ILog& logger;

  public:
    NCurses_v1( ILog& log_obj ) : 
        config()
        ,logger( log_obj )
    { logger.log("hello NCurses_v1 constructor"); }

    void init() {
        logger.log("hello NCurses_v1 init");
    }
};

