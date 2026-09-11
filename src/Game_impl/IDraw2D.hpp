#pragma once
#include "ICompositor.hpp"
#include <string_view>
#include "DrawType.hpp"

struct IDraw2D{
    virtual void draw(point3<double>&, std::string_view, DrawType) = 0;
    ~IDraw2D() = default;
};
