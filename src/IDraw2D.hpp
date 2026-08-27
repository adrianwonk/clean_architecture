#pragma once
#include <string_view>

enum class DrawType {
    temp,
    bird,
    ui
};

struct IDraw2D{
    virtual void draw(int, int, std::string_view, DrawType) = 0;
    ~IDraw2D() = default;
};
