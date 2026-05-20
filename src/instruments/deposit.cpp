//
// Created by Diego Huélamo Longás on 17/05/2026.
//

#include "deposit.h"
#include "compounding_type.hpp"

Deposit::Deposit(const DepositAttributes& attributes)
    : InterestRateInstrumentQuote(
        {
            .instrument_type = InterestRateInstrumentType::Deposit,
            .compounding = attributes.compounding,
            .market_quote = attributes.market_quote,
            .time_to_maturity_years = attributes.time_to_maturity_years
        })
{
}

void Deposit::dont_know_yet() const
{
    return;
}
