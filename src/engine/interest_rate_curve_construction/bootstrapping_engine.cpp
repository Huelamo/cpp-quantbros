//
// Created by Diego Huélamo Longás on 16/05/2026.
//

#include "bootstrapping_engine.h"
#include "interest_rate_pillar.hpp"
#include "interest_rate_curve.h"
#include "interest_rate_math.h"

InterestRateCurve BootstrappingEngine::bootstrap_curve(const InterestRateInstrumentQuote& market_quote)
{
    InterestRateCurve curve;
    bootstrap_curve(market_quote, curve);
    return curve;
}

void BootstrappingEngine::bootstrap_curve(const InterestRateInstrumentQuote& market_quote, InterestRateCurve& curve)
{
    switch (market_quote.instrument_type())
    {
    case InterestRateInstrumentType::Deposit:
        bootstrap_curve_from_deposit(market_quote, curve);
    case InterestRateInstrumentType::FRA:
        bootstrap_curve_from_fra(market_quote, curve);
    case InterestRateInstrumentType::Swap:
        bootstrap_curve_from_swap(market_quote, curve);
    }

    throw std::runtime_error("Unknown interest rate instrument type");
}

void BootstrappingEngine::bootstrap_curve_from_deposit(const InterestRateInstrumentQuote& market_quote, InterestRateCurve& curve)
{
    double df = InterestRateMath::compute_discount_factor(market_quote.tenor(), market_quote.quote(), market_quote.compounding_type());
    auto pillar = InterestRatePillar({
        .tenor = market_quote.tenor(),
        .discount_factor = df
    });
    curve.set_pillar(pillar);
}