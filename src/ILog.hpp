#pragma once
#include <string_view>
struct ILog {
    virtual void log(std::string_view) = 0;
    virtual ~ILog() = default;
};
