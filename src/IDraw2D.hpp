#pragma once
#include <string_view>

enum class DrawType {
    temp,
    bird,
    ui
};

struct IDraw2D{
    void draw(int, int, std::string_view, DrawType);
    ~IDraw2D() = default;
};
