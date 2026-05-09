#pragma once

#include <vector>
#include <random>
#include <cmath>

#include "Environment.hpp"
#include "StochasticProcess.hpp"

class Gbm : public StochasticProcess{
private:
    double spot;
    double vol;
    const Environment& env;

public:
    std::vector<double> generatePath(double maturity, int steps){
        double dt = maturity / static_cast<double> (steps);
        double drift = (env.r - 1.0/2.0 * vol*vol) * dt;
        double st_d = vol * std::sqrt(dt);
        std::vector<double> paths;
        paths.reserve(steps + 1);
        paths.push_back(spot);
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::normal_distribution<double> dist(0,1);
        std::vector<double> shocks;
        shocks.reserve(steps);
        for (size_t i = 0; i < steps ; ++i){
            shocks.push_back(dist(gen));
            paths.push_back(paths[i] * std::exp(drift + st_d * shocks[i]));
        }

        return paths;
    }

    

};