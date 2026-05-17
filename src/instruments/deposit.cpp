//
// Created by Diego Huélamo Longás on 17/05/2026.
//

#include "deposit.h"
#include "compounding_type.hpp"

Deposit::Deposit(const DepositAttributes& attributes)
    : InterestRateInstrumentQuote(
          {
              .market_quote = attributes.market_quote,
              .instrument_type = InterestRateInstrumentType::Deposit,
              .compounding = attributes.compounding
          }),
      tenor_years_(attributes.tenor_years)
{
}

double Deposit::tenor_years() const
{
    return tenor_years_;
}

void Deposit::dont_know_yet() const
{
    return;
}
