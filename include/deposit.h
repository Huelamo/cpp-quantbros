//
// Created by Diego Huélamo Longás on 17/05/2026.
//

#pragma once

#include "interest_rate_instrument_quote.h"

struct DepositAttributes
{
    double tenor;
    double quote;
    CompoundingType compounding;
};

class Deposit
{
    public:
        explicit Deposit(const DepositAttributes& attributes);
        double tenor() const;
        double quote() const;
        CompoundingType compounding() const;
    private:
        double tenor_;
        double quote_;
        CompoundingType compounding_;
};
