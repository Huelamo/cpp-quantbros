#pragma once

#include <optional>

#include "compounding_type.hpp"

struct InterestRatePillarAttributes
{
    double tenor_years;
    double discount_factor;
};

class InterestRatePillar
{
public:
    explicit InterestRatePillar(const InterestRatePillarAttributes& attributes);
    double tenor_years() const;
    static constexpr auto DefaultCompoundingType = CompoundingType::Continuous;
    double rate(const CompoundingType& compounding = DefaultCompoundingType) const;
    double discount_factor() const;
private:
    double tenor_years_;
    double discount_factor_;
};

