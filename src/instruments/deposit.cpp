//
// Created by Diego Huélamo Longás on 17/05/2026.
//

#include "deposit.h"
#include "compounding_type.hpp"
#include "interest_rate_math.h"

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

double Deposit::implied_quote(const InterestRateCurve& curve) const
{
    double df = curve.get_discount_factor(time_to_maturity_years());
    return InterestRateMath::compute_zero_coupon_rate(time_to_maturity_years(), df, compounding_type());
}
