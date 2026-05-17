//
// Created by Diego Huélamo Longás on 17/05/2026.
//

#include "deposit.h"
#include "compounding_type.hpp"

Deposit::Deposit(const DepositAttributes& attributes)
    : tenor_(attributes.tenor), quote_(attributes.quote), compounding_(attributes.compounding)
{
}

double Deposit::tenor() const
{
    return tenor_;
}

double Deposit::quote() const
{
    return quote_;
}

CompoundingType Deposit::compounding() const
{
    return compounding_;
}
