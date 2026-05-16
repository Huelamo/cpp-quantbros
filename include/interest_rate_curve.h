//
// Created by Diego Huélamo Longás on 15/05/2026.
//

#pragma once
#include <vector>

#include "Deposit.hpp"
#include "interest_rate_pillar.h"

class InterestRateCurve
{
    public:
        InterestRateCurve() = default;
        std::vector<InterestRatePillar> pillars() const;
        void set_discount_factor(const InterestRatePillar& pillar);
        void set_interest_rate_curve_pillar(const Deposit& deposit);
        void build_discount_curve_from_deposits(const std::vector<Deposit>& deposits);
        void build_discount_curve_from_discount_factors(const std::vector<InterestRatePillar>& pillars);
        void build_interest_rate_curve_from_deposits(const std::vector<Deposit>& deposits);

    private:
        std::vector<InterestRatePillar> discount_curve_;
        std::vector<Deposit> interest_rate_curve_;

};

