#pragma once
#include "INCursesResxManager.hpp"
#include "ILog.hpp"
#include "IDraw2D.hpp"

class NCursesResxManager : public INCursesResxManager {
  private:
      ILog& logger;
  public:
    void init();
    void cleanup();
    explicit NCursesResxManager(ILog&);
};
