#include "IMetrics.hpp"
#include <x86intrin.h>
#include <cstdint>

class Metrics : public IMetrics<uint64_t> {
  private:
      uint64_t start;
      uint64_t end;

  public:
    Metrics():
        start (),
        end ()
    {}

    void tick(){
       uint64_t start = __rdtsc();
    }

    void tock(){
       uint64_t end = __rdtsc();
    }

    uint64_t read(){
        return end - start;
    }
};
