#include "Option.hpp"
#include <algorithm>

class AmericanOption : public Option{
public:
    
        double calculatePayoff(const std::vector<double>& path) const override{
            int omega = static_cast<int>(type);
            double payoff = std::max(omega * (path.back())-strike, 0.0);
            return payoff;
        };
};