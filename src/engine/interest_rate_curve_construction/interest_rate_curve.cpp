//
// Created by Diego Huélamo Longás on 15/05/2026.
//

#include "interest_rate_curve.h"


std::vector<InterestRatePillar> InterestRateCurve::pillars() const
{
    return pillars_;
}

CompoundingType InterestRateCurve::compounding_type() const
{
    return compounding_type_;
}

void InterestRateCurve::set_pillar(const InterestRatePillar& pillar)
{
    pillars_.push_back(pillar);
}

void InterestRateCurve::build_curve_from_pillars(const std::vector<InterestRatePillar>& pillars, bool)
{
    for (const auto& pillar: pillars)
    {
        set_pillar(pillar);
    }
}
