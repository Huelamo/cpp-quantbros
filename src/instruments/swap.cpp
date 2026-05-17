//
// Created by Diego Huélamo Longás on 17/05/2026.
//

#include "swap.h"

Swap::Swap(const SwapAttributes& attributes)
    : InterestRateInstrumentQuote(
          {
              .instrument_type = InterestRateInstrumentType::Swap,
              .compounding = attributes.compounding,
              .market_quote = attributes.market_quote
          }),
      tenor_start_(attributes.tenor_start),
      tenor_maturity_(attributes.tenor_maturity),
      fixed_leg_period_(attributes.fixed_leg_period)
{
}

double Swap::tenor_start() const
{
    return tenor_start_;
}

double Swap::tenor_maturity() const
{
    return tenor_maturity_;
}

double Swap::fixed_leg_period() const
{
    return fixed_leg_period_;
}


void Swap::dont_know_yet() const
{
    return;
}
