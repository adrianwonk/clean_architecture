#pragma once
#include "ILog.hpp"
#include <iostream>
class NewLineLog : public ILog {
public: 
    void log(std::string_view input){
        std::cout << input << '\n';
    }
};
