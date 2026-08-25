#pragma once
#include "INCursesResxManager.hpp"
#include "ILog.hpp"
#include "IDraw2D.hpp"

class NCursesHelloWorld : public INCursesResxManager , public IDraw2D {
  private:
      ILog& logger;
  public:
    void init();
    void cleanup();
    void draw(int,int,std::string_view);
    explicit NCursesHelloWorld(ILog&);
};
