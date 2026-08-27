#pragma once
#include "vec3.hpp"
struct ICompositor {
    virtual void update() = 0;
    virtual void clear() = 0;
    virtual point3 compose_pos(point3&) = 0; // optimise potential
    virtual ~ICompositor() = default;
};
