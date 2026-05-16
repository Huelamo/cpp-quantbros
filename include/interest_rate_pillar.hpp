#pragma once

#include <optional>

#include "compounding_type.hpp"

struct InterestRatePillarAttributes
{
    double tenor;
    double discount_factor;
};

class InterestRatePillar
{
public:
    explicit InterestRatePillar(const InterestRatePillarAttributes& attributes);
    double tenor() const;
    static constexpr auto DefaultCompoundingType = CompoundingType::Continuous;
    double rate(const CompoundingType& compounding = DefaultCompoundingType) const;
    double discount_factor() const;
private:
    double tenor_;
    double discount_factor_;
};

