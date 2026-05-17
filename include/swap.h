//
// Created by Diego Huélamo Longás on 17/05/2026.
//

#pragma once
#include "compounding_type.hpp"
#include "interest_rate_instrument_quote.h"
#include "interest_rate_instrument_type.h"

struct SwapAttributes
{
    // Parent class attributes
    InterestRateInstrumentType instrument_type;
    CompoundingType compounding;
    double market_quote;

    // Child class attributes
    double tenor_start;
    double tenor_maturity;
    double fixed_leg_period; // TODO: now assuming floating leg has the same payment freq as fixed leg
};

class Swap : public InterestRateInstrumentQuote
{
public:
    explicit Swap(const SwapAttributes& attr);
    double tenor_start() const;
    double tenor_maturity() const;
    double fixed_leg_period() const;
    void dont_know_yet() const override;

private:
    double tenor_start_;
    double tenor_maturity_;
    double fixed_leg_period_;
};
