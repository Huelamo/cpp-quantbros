//
// Created by Diego Huélamo Longás on 15/05/2026.
//

#pragma once
#include <vector>

#include "interest_rate_pillar.hpp"
#include "compounding_type.hpp"

class InterestRateCurve
{
    public:
        InterestRateCurve() = default;
        CompoundingType compounding_type() const;
        std::vector<InterestRatePillar> pillars() const;
        void set_pillar(const InterestRatePillar& pillar);
        void build_curve_from_pillars(const std::vector<InterestRatePillar>& pillars, bool coerce_compounding_type = true);

    private:
        std::vector<InterestRatePillar> pillars_;
        CompoundingType compounding_type_{CompoundingType::Continuous};

};
