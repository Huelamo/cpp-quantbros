//
// Created by Diego Huélamo Longás on 15/05/2026.
//

#include "interest_rate_curve.h"
#include "interest_rate_pillar.hpp"
#include <algorithm>

#include "interest_rate_math.h"

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

std::vector<InterestRatePillar> InterestRateCurve::get_previous_pillars(const double& tenor_years) const
{
    const auto it = std::lower_bound(
        pillars_.begin(),
        pillars_.end(),
        tenor_years,
        [](const InterestRatePillar& pillar, const double tenor)
        {
            return pillar.tenor_years() < tenor;
        }
    );
    if (it == pillars_.begin())
    {
        throw std::runtime_error("No previous pillar found.");
    }
    return {pillars_.begin(), it};
}

double InterestRateCurve::get_discount_factor(const double& tenor) const
{
    return InterestRateMath::linear_interpolation_flat_extrapolation(pillars_, tenor);
}