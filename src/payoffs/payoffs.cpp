#include <algorithm>
#include "payoffs.h"

double european_option( double S , double K, bool is_call)
{
    return std::max( w * (S - K), 0)
}