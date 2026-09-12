#pragma once
#include "IVisualResx.hpp"
#include "ILog.hpp"

class NCursesResxManager : public IVisualResx {
  private:
      ILog& logger;
  public:
    void init();
    void cleanup();
    explicit NCursesResxManager(ILog&);
};
