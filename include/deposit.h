//
// Created by Diego Huélamo Longás on 17/05/2026.
//

#pragma once

#include "interest_rate_instrument_quote.h"
#include "interest_rate_curve.h"

struct DepositAttributes
{
    // Parent class attributes
    CompoundingType compounding;
    double market_quote;
    double time_to_maturity_years;
};

class Deposit : public InterestRateInstrumentQuote
{
public:
    explicit Deposit(const DepositAttributes& attributes);
    double implied_quote(const InterestRateCurve& curve) const override;
};
