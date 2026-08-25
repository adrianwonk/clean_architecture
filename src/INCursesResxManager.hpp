#pragma once

struct INCursesResxManager {
    virtual void init() = 0;
    virtual void end() = 0;
    virtual ~INCursesResxManager() = default;
};

