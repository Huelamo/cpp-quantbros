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
            // const auto& swap = dynamic_cast<const Swap&>(instr);
            // bootstrap_curve_from_swap(swap, curve);
            return;
        }
    }

    throw std::runtime_error("Unknown interest rate instrument type");
}

void BootstrappingEngine::bootstrap_curve_from_deposit(const Deposit& instr,
                                                       InterestRateCurve& curve)
{
    double df = InterestRateMath::compute_discount_factor(instr.tenor_years(), instr.market_quote(),
                                                          instr.compounding_type());
    auto pillar = InterestRatePillar({
        .tenor = instr.tenor_years(),
        .discount_factor = df
    });
    curve.set_pillar(pillar);
}

void BootstrappingEngine::bootstrap_curve_from_fra(const ForwardRateAgreement& instr,
                                                   InterestRateCurve& curve)
{
    std::optional<InterestRatePillar> previous_pillar = std::nullopt;
    for (const auto& pillar : curve.pillars())
    {
        if (pillar.tenor() < instr.tenor_years() && ((!previous_pillar.has_value()) || (pillar.tenor() >
            previous_pillar->tenor())))
        {
            previous_pillar = pillar;
        }
    }
    if (!previous_pillar.has_value())
    {
        throw std::runtime_error("Cannot bootstrap FRA: no previous pillar found.");
    }
    double df_ini = previous_pillar->discount_factor();
    const double tau = instr.tenor_years() - previous_pillar->tenor();
    double df_end = df_ini / (1 + instr.market_quote() * tau);
    const auto new_pillar = InterestRatePillar({.tenor = instr.tenor_years(), .discount_factor = df_end});
    curve.set_pillar(new_pillar);
}


// void BootstrappingEngine::bootstrap_curve_from_swap(const InterestRateInstrumentQuote& market_quote,
//                                                     InterestRateCurve& curve)
// {
//     std::optional<std::vector<InterestRatePillar>> previous_pillars = std::nullopt;
//     int i = 0;
//     for (const auto& pillar : curve.pillars())
//     {
//         if (pillar.tenor() < market_quote.tenor() && ((!previous_pillars.has_value()) || (pillar.tenor() > (*
//             previous_pillars)[i].tenor())))
//         {
//             previous_pillars->push_back(pillar);
//             i++;
//         }
//     }
// }
