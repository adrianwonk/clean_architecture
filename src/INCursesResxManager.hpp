#pragma once

struct INCursesResxManager {
    virtual void init() = 0;
    virtual void cleanup() = 0;
    virtual ~INCursesResxManager() = default;
};

