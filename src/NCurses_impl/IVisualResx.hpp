#pragma once

struct IVisualResx {
    virtual void init() = 0;
    virtual void cleanup() = 0;
    virtual ~IVisualResx() = default;
};

