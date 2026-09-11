#pragma once
template <typename T>
struct IMetrics {
    virtual void tick() = 0;
    virtual void tock() = 0;
    virtual T diff() = 0;
    ~IMetrics() = default;
};
