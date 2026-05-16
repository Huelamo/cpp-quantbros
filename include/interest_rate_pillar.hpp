#pragma once

#include "compounding_type.hpp"

struct InterestRatePillarAttributes
{
    double tenor;
    double rate;
};

class InterestRatePillar
{
public:
    explicit InterestRatePillar(const InterestRatePillarAttributes& attributes);

    double tenor() const;
    double rate() const;
    double discount_factor(const CompoundingType& compounding) const;
private:
    double tenor_;
    double rate_;
};

