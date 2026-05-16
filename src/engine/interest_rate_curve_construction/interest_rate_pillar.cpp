//
// Created by Diego Huélamo Longás on 10/05/2026.
//

#include "interest_rate_pillar.hpp"
#include "compounding_type.hpp"
#include "interest_rate_math.h"

InterestRatePillar::InterestRatePillar(const InterestRatePillarAttributes& attributes)
    : tenor_(attributes.tenor), discount_factor_(attributes.discount_factor)
{
}
double InterestRatePillar::tenor() const
{
    return tenor_;
}

double InterestRatePillar::discount_factor() const
{
    return discount_factor_.value();
}

double InterestRatePillar::rate(const CompoundingType& compounding) const
{
    return InterestRateMath::compute_zero_coupon_rate(tenor_, discount_factor_.value(), compounding);
}
