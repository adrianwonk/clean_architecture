#pragma once
#include "ICompositor.hpp"
#include <string_view>

enum class DrawType {
    temp,
    bird,
    ui
};

struct IDraw2D{
    virtual void draw(point3&, std::string_view, DrawType) = 0;
    ~IDraw2D() = default;
};
