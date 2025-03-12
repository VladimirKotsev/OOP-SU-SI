#pragma once
#include <iostream>

class insufficient_fuel_error : public std::logic_error
{
public:
    explicit insufficient_fuel_error(const std::string& message)
        : std::logic_error(message) {}
};

