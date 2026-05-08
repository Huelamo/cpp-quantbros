#pragma once
#include <vector>

enum class OptionType{
    Call = 1,
    Put = -1
};

class Option { 
public:
    double maturity;
    double strike;
    OptionType type;
    virtual double calculatePayoff(const std::vector<double>& path) const = 0;
};