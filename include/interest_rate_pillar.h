//
// Created by Diego Huélamo Longás on 15/05/2026.
//

#pragma once
#include "CompoundingType.hpp"

struct InterestRatePillarAttributes
{
    double tenor;
    double discount_factor;
    CompoundingType compounding_type;
};

class InterestRatePillar
{
    public:
        explicit InterestRatePillar(const InterestRatePillarAttributes& attributes);
        double tenor() const;
        double discount_factor() const;
    private:
        double tenor_;
        double discount_factor_;
};
