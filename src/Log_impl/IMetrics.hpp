#pragma once
template <typename out_t>
struct IMetrics {
    virtual void tick() = 0;
    virtual void tock() = 0;
    virtual out_t diff() = 0;
    ~IMetrics() = default;
};
