//
// Created by Diego Huélamo Longás on 17/05/2026.
//

#pragma once

#include "interest_rate_instrument_quote.h"

struct DepositAttributes
{
    // Parent class attributes
    InterestRateInstrumentType instrument_type;
    CompoundingType compounding;
    double market_quote;
    double time_to_maturity_years;
};

class Deposit : public InterestRateInstrumentQuote
{
public:
    explicit Deposit(const DepositAttributes& attributes);
    void dont_know_yet() const override;
};
