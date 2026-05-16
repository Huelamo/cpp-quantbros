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
        return std::pow(1.0 + rate, - tenor);
    case CompoundingType::Continuous:
        return std::exp(-rate * tenor);
    }

    throw std::invalid_argument("Unsupported compounding type");
}

double InterestRateMath::compute_zero_coupon_rate(double tenor, double discount_factor, const CompoundingType& compounding)
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