//
// Created by Diego Huélamo Longás on 16/05/2026.
//

#pragma once
#include "compounding_type.hpp"

class InterestRateMath
{
    public:
        static double compute_discount_factor(double tenor, double rate, const CompoundingType& compounding);
        static double compute_zero_coupon_rate(double tenor, double discount_factor, const CompoundingType& compounding);

};


