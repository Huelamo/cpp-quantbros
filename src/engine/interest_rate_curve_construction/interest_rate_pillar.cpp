//
// Created by Diego Huélamo Longás on 10/05/2026.
//

#include "interest_rate_pillar.hpp"

#include <cmath>
#include <stdexcept>

#include "compounding_type.hpp"
#include "interest_rate_math.h"

InterestRatePillar::InterestRatePillar(const InterestRatePillarAttributes& attributes)
    : tenor_(attributes.tenor), rate_(attributes.rate), discount_factor_(attributes.discount_factor)
{
    if (!rate_.has_value() && !discount_factor_.has_value())
    {
        throw std::invalid_argument("InterestRatePillar requires either rate or discount factor.");
    }
}

double InterestRatePillar::tenor() const
{
    return tenor_;
}

double InterestRatePillar::rate(const CompoundingType& compounding) const
{
    if (rate_.has_value())
    {
        return rate_.value();
    }
    return InterestRateMath::compute_zero_coupon_rate(tenor_, discount_factor_.value(), compounding);
}

double InterestRatePillar::discount_factor(const CompoundingType& compounding) const
{
    if (discount_factor_.has_value())
    {
        return discount_factor_.value();
    }
    return InterestRateMath::compute_discount_factor(tenor_, rate_.value(), compounding);
}
