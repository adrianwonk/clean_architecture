#pragma once
#include "INCursesBaseInitialiser.hpp"
#include "ILog.hpp"

class NCursesBaseInitialiser : public INCursesBaseInitialiser {
  private:
      ILog& logger;
  public:
    void init();
    explicit NCursesBaseInitialiser(ILog&);
};
