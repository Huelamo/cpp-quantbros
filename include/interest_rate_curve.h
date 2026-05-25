//
// Created by Diego Huélamo Longás on 15/05/2026.
//

#pragma once
#include <vector>

#include "interest_rate_pillar.hpp"

class InterestRateCurve
{
    public:
        InterestRateCurve() = default;
        const std::vector<InterestRatePillar>& pillars() const;
        void set_pillar(const InterestRatePillar& pillar);
        std::vector<InterestRatePillar> get_previous_pillars(const double& tenor_years) const;
        double get_discount_factor(const double& tenor) const;
    private:
        std::vector<InterestRatePillar> pillars_;

};
