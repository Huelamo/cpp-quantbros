//
// Created by Diego Huélamo Longás on 10/05/2026.
//

#include "interest_rate_pillar.hpp"

#include <cmath>
#include <stdexcept>

#include "compounding_type.hpp"

InterestRatePillar::InterestRatePillar(const InterestRatePillarAttributes& attributes)
    : tenor_(attributes.tenor), rate_(attributes.rate)
{
};

double InterestRatePillar::tenor() const
{
    return tenor_;
};

double InterestRatePillar::rate() const
{
    return rate_;
};

double InterestRatePillar::discount_factor(const CompoundingType& compounding) const
{
    switch (compounding)
    {
    case CompoundingType::Simple:
        return 1.0 / (1.0 + rate_ * tenor_);
    case CompoundingType::Compounded:
        return std::pow(1.0 + rate_, - tenor_);
    case CompoundingType::Continuous:
        return std::exp(-rate_ * tenor_);
    }

    throw std::invalid_argument("Unsupported compounding type");
};
