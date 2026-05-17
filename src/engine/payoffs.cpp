#include <algorithm>
#include "../../include/payoffs.hpp"

double european_option( double S , double K, bool is_call)
{
    int omega = 2 * is_call - 1;
    return std::max( omega * (S - K), 0.0);
}