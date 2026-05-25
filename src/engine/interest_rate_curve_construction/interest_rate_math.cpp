//
// Created by Diego Huélamo Longás on 16/05/2026.
//

#include "interest_rate_math.h"
#include <stdexcept>
#include <cmath>

double InterestRateMath::compute_discount_factor(double tenor, double rate, const CompoundingType& compounding)
{
    if (tenor <= 0)
    {
        throw std::invalid_argument("Tenor must be greater than zero.");
    }

    switch (compounding)
    {
    case CompoundingType::Simple:
        return 1.0 / (1.0 + rate * tenor);
    case CompoundingType::Compounded:
        return std::pow(1.0 + rate, -tenor);
    case CompoundingType::Continuous:
        return std::exp(-rate * tenor);
    }

    throw std::invalid_argument("Unsupported compounding type");
}

double InterestRateMath::compute_zero_coupon_rate(double tenor, double discount_factor,
                                                  const CompoundingType& compounding)
{
    if (tenor <= 0)
    {
        throw std::invalid_argument("Tenor must be greater than zero.");
    }
    if (discount_factor <= 0)
    {
        throw std::invalid_argument("Discount factor must be greater than zero.");
    }

    switch (compounding)
    {
    case CompoundingType::Simple:
        return (1.0 / discount_factor - 1.0) / tenor;
    case CompoundingType::Compounded:
        return std::pow(discount_factor, -1.0 / tenor) - 1;
    case CompoundingType::Continuous:
        return -std::log(discount_factor) / tenor;
    }

    throw std::invalid_argument("Unsupported compounding type");
}

double InterestRateMath::linear_interpolation_flat_extrapolation(const std::vector<InterestRatePillar>& pillars,
                                                                 const double tenor_years)
{
    if (pillars.empty())
    {
        throw std::invalid_argument("No pillars found. Cannot interpolate on an empty curve");
    }
    const auto right = std::lower_bound(
        pillars.begin(),
        pillars.end(),
        tenor_years,
        [](const InterestRatePillar& pillar, const double tenor)
        {
            return pillar.tenor_years() < tenor;
        }
    );

    if (right == pillars.begin())
    {
        return pillars.front().discount_factor();
    }

    if (right == pillars.end())
    {
        return pillars.back().discount_factor();
    }

    if (right->tenor_years() == tenor_years)
    {
        return right->discount_factor();
    }

    const auto left = std::prev(right);
    const double t1 = left->tenor_years();
    const double t2 = right->tenor_years();
    const double df1 = left->discount_factor();
    const double df2 = right->discount_factor();

    return df1 * (t2 - tenor_years) / (t2 - t1) + df2 * (tenor_years - t1) / (t2 - t1);
}
