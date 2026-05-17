//
// Created by Diego Huélamo Longás on 16/05/2026.
//
#include <optional>
#include <stdexcept>

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
        return;
    case InterestRateInstrumentType::FRA:
        bootstrap_curve_from_fra(market_quote, curve);
        return;
    case InterestRateInstrumentType::Swap:
        // bootstrap_curve_from_swap(market_quote, curve);
        return;
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

void BootstrappingEngine::bootstrap_curve_from_fra(const InterestRateInstrumentQuote& market_quote, InterestRateCurve& curve)
{
    std::optional<InterestRatePillar> previous_pillar = std::nullopt;
    for (const auto& pillar : curve.pillars())
    {
        if (pillar.tenor() <  market_quote.tenor() && ((!previous_pillar.has_value()) || (pillar.tenor() > previous_pillar->tenor())))
        {
            previous_pillar = pillar;
        }
    }
    if (!previous_pillar.has_value())
    {
        throw std::runtime_error("Cannot bootstrap FRA: no previous pillar found.");
    }
    double df_ini = previous_pillar->discount_factor();
    const double tau = market_quote.tenor() - previous_pillar->tenor();
    double df_end = df_ini / (1 + market_quote.quote() * tau);
    const auto new_pillar = InterestRatePillar({.tenor= market_quote.tenor(), .discount_factor= df_end});
    curve.set_pillar(new_pillar);
}
