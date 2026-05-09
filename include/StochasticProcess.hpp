#pragma once
#include <vector>

class StochasticProcess{
public:
    virtual ~StochasticProcess() = default;

    virtual std::vector<double> generatePath(double maturity, int steps) const = 0;
};