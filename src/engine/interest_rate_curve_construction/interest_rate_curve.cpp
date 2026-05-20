//
// Created by Diego Huélamo Longás on 15/05/2026.
//

#include "interest_rate_curve.h"
#include "interest_rate_pillar.hpp"
#include <algorithm>

const std::vector<InterestRatePillar>& InterestRateCurve::pillars() const
{
    return pillars_;
}

void InterestRateCurve::set_pillar(const InterestRatePillar& pillar)
{
    pillars_.push_back(pillar);
    std::sort(pillars_.begin(), pillars_.end(), [](const auto& p1, const auto& p2)
    {
        return p1.tenor_years() < p2.tenor_years();
    });
}
