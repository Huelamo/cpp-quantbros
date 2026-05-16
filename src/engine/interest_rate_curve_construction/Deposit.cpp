//
// Created by Diego Huélamo Longás on 10/05/2026.
//

#include "Deposit.hpp"

#include <cmath>

#include "CompoundingType.hpp"

Deposit::Deposit(const DepositAttributes& attributes)
    : tenor_(attributes.tenor), rate_(attributes.rate), compounding_(attributes.compounding)
{
}

double Deposit::tenor() const
{
    return tenor_;
}

double Deposit::rate() const
{
    return rate_;
}

CompoundingType Deposit::compounding() const
{
    return compounding_;
}

double Deposit::discount_factor() const
{
    switch (compounding_)
    {
    case CompoundingType::Simple:
        return 1.0 / (1.0 + rate_ * tenor_);
    case CompoundingType::Compounded:
        return std::pow(1.0 + rate_, - tenor_);
    case CompoundingType::Continuous:
        return std::exp(-rate_ * tenor_);
    }
}