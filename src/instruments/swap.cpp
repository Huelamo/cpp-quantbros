//
// Created by Diego Huélamo Longás on 17/05/2026.
//

#include "swap.h"

Swap::Swap(const SwapAttributes& attributes)
    : InterestRateInstrumentQuote(
          {
              .instrument_type = InterestRateInstrumentType::Swap,
              .compounding = attributes.compounding,
              .market_quote = attributes.market_quote,
              .time_to_maturity_years = attributes.time_to_maturity_years
          }),
      tenor_start_years_(attributes.tenor_start_years),
      fixed_leg_period_(attributes.fixed_leg_period)
{
}

double Swap::tenor_start() const
{
    return tenor_start_years_;
}

double Swap::fixed_leg_period_years() const
{
    return fixed_leg_period_;
}

double Swap::implied_quote(const InterestRateCurve& curve) const
{
    return 0.0;
}
