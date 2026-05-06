#include <vector>

enum class OptionType{
    Call = 1,
    Put = -1
};

class Option { 
public:
    double strike;
    OptionType type;
    virtual double calculatePayoff(const std::vector<double>& path) = 0;
};