//
// Created by Diego Huélamo Longás on 10/05/2026.
//

#include "interest_rate_pillar.hpp"

#include <cmath>
#include <stdexcept>

#include "compounding_type.hpp"

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
    return compute_zero_coupon_rate(compounding);
}

double InterestRatePillar::discount_factor(const CompoundingType& compounding) const
{
    if (discount_factor_.has_value())
    {
        return discount_factor_.value();
    }
    return compute_discount_factor(compounding);
}

double InterestRatePillar::compute_discount_factor(const CompoundingType& compounding) const
{
    if (tenor_ <= 0)
    {
        throw std::invalid_argument("Tenor must be greater than zero.");
    }

    switch (compounding)
    {
    case CompoundingType::Simple:
        return 1.0 / (1.0 + rate_.value() * tenor_);
    case CompoundingType::Compounded:
        return std::pow(1.0 + rate_.value(), - tenor_);
    case CompoundingType::Continuous:
        return std::exp(-rate_.value() * tenor_);
    }

    throw std::invalid_argument("Unsupported compounding type");
}

double InterestRatePillar::compute_zero_coupon_rate(const CompoundingType& compounding) const
{
    if (tenor_ <= 0)
    {
        throw std::invalid_argument("Tenor must be greater than zero.");
    }
    const double df = discount_factor_.value();
    if (df <= 0)
    {
        throw std::invalid_argument("Discount factor must be greater than zero.");
    }

    switch (compounding)
    {
        case CompoundingType::Simple:
            return (1.0 / df - 1.0) / tenor_;
        case CompoundingType::Compounded:
            return std::pow(df, -1.0 / tenor_) - 1;
        case CompoundingType::Continuous:
            return -std::log(df) / tenor_;
    }

    throw std::invalid_argument("Unsupported compounding type");
}
