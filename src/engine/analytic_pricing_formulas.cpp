#include <cmath>
#include <utility>

std::pair<double, double> black_scholes_d_terms(double S_0, double K, double r, double sigma, double tau)
{
    double d1 = (std::log(S_0 / K) + (r + 0.5 * sigma * sigma) * tau) / (sigma * std::sqrt(tau));
    double d2 = d1 - sigma * std::sqrt(tau);
    return {d1, d2};
}

double standard_gaussian_cdf(double x)
{
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

double black_scholes_formula(double S_0, double K, double r, double sigma, double tau, bool is_call)
{
    auto [d1, d2] = black_scholes_d_terms(S_0, K, r, sigma, tau);
    double discount = std::exp(-r * tau);
    double omega = 2 * is_call -1;
    double N_d1 = standard_gaussian_cdf(d1 * omega);
    double N_d2 = standard_gaussian_cdf(d2 * omega);
    return omega * (S_0 * N_d1 - discount * N_d2 * K);
}