#include <iostream>
#include <ostream>

#include "analytic_pricing_formulas.hpp"
#include "payoffs.hpp"

int main()
{
    double S_0 = 2.0;
    double K = 2.0;
    bool is_call = true;
    double r = 0.04;
    double tau = 1.0;
    double sigma = 0.15;
    double price = black_scholes_formula(S_0, K, r, sigma, tau, is_call);
    std::cout<<"price = "<<price<<std::endl;
    return 0;
}