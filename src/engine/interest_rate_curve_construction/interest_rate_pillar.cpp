//
// Created by Diego Huélamo Longás on 10/05/2026.
//

#include "interest_rate_pillar.hpp"
#include "compounding_type.hpp"
#include "interest_rate_math.h"

InterestRatePillar::InterestRatePillar(const InterestRatePillarAttributes& attributes)
    : tenor_years_(attributes.tenor_years), discount_factor_(attributes.discount_factor)
{
}
double InterestRatePillar::tenor_years() const
{
    return tenor_years_;
}

double InterestRatePillar::discount_factor() const
{
    return discount_factor_;
}

double InterestRatePillar::rate(const CompoundingType& compounding) const
{
    return InterestRateMath::compute_zero_coupon_rate(tenor_years_, discount_factor_, compounding);
}
