#pragma once
#include <string_view>
#include <iostream>
struct ILog: public std::ostream {
    virtual void log(std::string_view) = 0;
    virtual ~ILog() = default;
};
