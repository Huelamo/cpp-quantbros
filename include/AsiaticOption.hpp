#include "Option.hpp"
#include <algorithm>
#include <numeric>
#include <vector>

class AsiaticOption : public Option{
public:
    int omega = static_cast<int>(type);
    std::vector<double> observationDates;

    double calculatePayoff(const std::vector<double>& path) const override{
        double sum = std::accumulate(path.begin(), path.end(), 0.0);
        double payoff = std::max(omega * (sum / path.size() - strike), 0.0);
        return payoff;
    };
};