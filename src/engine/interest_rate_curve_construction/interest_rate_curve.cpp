//
// Created by Diego Huélamo Longás on 15/05/2026.
//

#include "interest_rate_curve.h"
#include "interest_rate_pillar.hpp"

std::vector<InterestRatePillar> InterestRateCurve::pillars() const
{
    return pillars_;
}

void InterestRateCurve::set_pillar(const InterestRatePillar& pillar)
{
    pillars_.push_back(pillar);
}


