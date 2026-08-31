#pragma once
#include "vec3.hpp"

class DrawnObject {
public:
    std::string_view str;
    DrawnObject(std::string_view s):
        str(s)
    {}
};

struct ICompositor {
    virtual void update() = 0;
    virtual void clear() = 0;
    virtual void draw_centered( point3&, DrawnObject& ) = 0; // optimise potential
    virtual ~ICompositor() = default;
};
