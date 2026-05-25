//
// Created by Diego Huélamo Longás on 16/05/2026.
//
#include <optional>
#include <stdexcept>

#include "bootstrapping_engine.h"
#include "interest_rate_pillar.hpp"
#include "interest_rate_curve.h"
#include "interest_rate_math.h"
#include "deposit.h"
#include "forward_rate_agreement.h"
#include "swap.h"

InterestRateCurve BootstrappingEngine::bootstrap_curve(const InterestRateInstrumentQuote& market_quote)
{
    InterestRateCurve curve;
    bootstrap_curve(market_quote, curve);
    return curve;
}

void BootstrappingEngine::bootstrap_curve(const InterestRateInstrumentQuote& instr, InterestRateCurve& curve)
{
    switch (instr.instrument_type())
    {
    case InterestRateInstrumentType::Deposit:
        {
            const auto& deposit = dynamic_cast<const Deposit&>(instr);
            bootstrap_curve_from_deposit(deposit, curve);
            return;
        }
    case InterestRateInstrumentType::FRA:
        {
            const auto& fra = dynamic_cast<const ForwardRateAgreement&>(instr);
            bootstrap_curve_from_fra(fra, curve);
            return;
        }
    case InterestRateInstrumentType::Swap:
        {
            const auto& swap = dynamic_cast<const Swap&>(instr);
            return bootstrap_curve_from_swap(swap, curve);
        }
    }

    throw std::runtime_error("Unknown interest rate instrument type");
}

void BootstrappingEngine::bootstrap_curve_from_deposit(const Deposit& instr,
                                                       InterestRateCurve& curve)
{
    const double df = InterestRateMath::compute_discount_factor(instr.time_to_maturity_years(), instr.market_quote(),
                                                                instr.compounding_type());
    const auto pillar = InterestRatePillar({
        .tenor_years = instr.time_to_maturity_years(),
        .discount_factor = df
    });
    curve.set_pillar(pillar);
}

void BootstrappingEngine::bootstrap_curve_from_fra(const ForwardRateAgreement& instr,
                                                   InterestRateCurve& curve)
{
    const auto previous_pillars = curve.get_previous_pillars(instr.time_to_maturity_years());
    const auto& previous_pillar = previous_pillars.back();
    const double tau = instr.time_to_maturity_years() - previous_pillar.tenor_years();
    const double maturity_df = previous_pillar.discount_factor() / (1 + instr.market_quote() * tau);
    const auto new_pillar_df = InterestRatePillar({
        .tenor_years = instr.time_to_maturity_years(), .discount_factor = maturity_df
    });
    curve.set_pillar(new_pillar_df);
}


void BootstrappingEngine::bootstrap_curve_from_swap(const Swap& instr, InterestRateCurve& curve)
{
    const auto previous_pillars = curve.get_previous_pillars(instr.time_to_maturity_years());
    const auto day_count_fraction = instr.fixed_leg_period_years();
    const auto swap_rate = instr.market_quote();
    double annuity = 0.0;
    for (auto& pillar : previous_pillars)
    {
        annuity += pillar.discount_factor() * day_count_fraction;
    }
    const double maturity_df = (1.0 - swap_rate * annuity) / (1.0 + swap_rate * day_count_fraction);
    const auto new_pillar = InterestRatePillar({
        .tenor_years = instr.time_to_maturity_years(),
        .discount_factor = maturity_df
    });
    curve.set_pillar(new_pillar);
}
