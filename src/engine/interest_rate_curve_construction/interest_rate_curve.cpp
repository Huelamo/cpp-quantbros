//
// Created by Diego Huélamo Longás on 15/05/2026.
//

#include "interest_rate_curve.h"
#include "interest_rate_pillar.hpp"
#include "interest_rate_instrument_quote.h"

std::vector<InterestRatePillar> InterestRateCurve::pillars() const
{
    return pillars_;
}

CompoundingType InterestRateCurve::compounding_type() const
{
    return compounding_type_;
}

void InterestRateCurve::set_pillar(const InterestRatePillar& pillar)
{
    pillars_.push_back(pillar);
}

void InterestRateCurve::bootstrap_curve(const InterestRateInstrumentQuote& quote) const
{
    switch (quote.instrument_type())
    {
    case InterestRateInstrumentType::Deposit:
        return bootstrap_curve_from_deposit(quote);
    case InterestRateInstrumentType::FRA:
        return bootstrap_curve_from_fra(quote);
    case InterestRateInstrumentType::Swap:
        return bootstrap_curve_from_swap(quote);
    }

    throw std::runtime_error("Unknown interest rate instrument type");
}

void InterestRateCurve::bootstrap_curve_from_deposit(const InterestRateInstrumentQuote& quote) const
{
    InterestRatePillar pillar = InterestRatePillar({
        .tenor = quote.tenor(),
        .discount_factor = quote.quote(),
    });
}
