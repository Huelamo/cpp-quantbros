//
// Created by Diego Huélamo Longás on 15/05/2026.
//

#include "../../../include/InterestRatePillar.h"

InterestRatePillar::InterestRatePillar(const InterestRatePillarAttributes& attributes):
    tenor_(attributes.tenor), discount_factor_(attributes.discount_factor)
{
}

double InterestRatePillar::tenor() const
{
    return tenor_;
}

double InterestRatePillar::discount_factor() const
{
    return discount_factor_;
}