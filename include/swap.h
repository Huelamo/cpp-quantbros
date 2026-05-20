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
    double market_quote; // Forward swap rate
    double time_to_maturity_years;

    // Child class attributes
    double tenor_start_years; // T_\alpha in Brigo & Mercurio
    double fixed_leg_period; // TODO: now assuming floating leg has the same payment freq as fixed leg
};

class Swap : public InterestRateInstrumentQuote
{
public:
    explicit Swap(const SwapAttributes& attr);
    double tenor_start() const;
    double fixed_leg_period_years() const;
    void dont_know_yet() const override;

private:
    double tenor_start_years_;
    double fixed_leg_period_;
};
