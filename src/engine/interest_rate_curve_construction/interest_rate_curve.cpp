//
// Created by Diego Huélamo Longás on 15/05/2026.
//

#include "interest_rate_curve.h"
#include "interest_rate_pillar.h"


std::vector<InterestRatePillar> InterestRateCurve::pillars() const
{
    return discount_curve_;
}

void InterestRateCurve::set_discount_factor(const InterestRatePillar& pillar)
{
    discount_curve_.push_back(pillar);
}

void InterestRateCurve::set_interest_rate_curve_pillar(const Deposit& deposit)
{
    interest_rate_curve_.push_back(deposit);
}

void InterestRateCurve::build_discount_curve_from_deposits(const std::vector<Deposit>& deposits)
{
    for (const auto& deposit : deposits)
    {
        InterestRatePillar pillar({.tenor = deposit.tenor(), .discount_factor = deposit.discount_factor()});
        set_discount_factor(pillar);
    }
}

void InterestRateCurve::build_discount_curve_from_discount_factors(const std::vector<InterestRatePillar>& pillars)
{
    for (const auto& pillar: pillars)
    {
        set_discount_factor(pillar);
    }
}

void InterestRateCurve::build_interest_rate_curve_from_deposits(const std::vector<Deposit>& deposits)
{
    for (const auto& deposit : deposits)
    {
        set_interest_rate_curve_pillar(deposit);
    }
}