//
// Created by Diego Huélamo Longás on 16/05/2026.
//

#pragma once
#include "interest_rate_curve.h"
#include "interest_rate_instrument_quote.h"

class BootstrappingEngine
{
    public:
        static InterestRateCurve bootstrap_curve(const InterestRateInstrumentQuote& market_quote);
        static void bootstrap_curve(const InterestRateInstrumentQuote& market_quote, InterestRateCurve& curve);
    private:
        static void bootstrap_curve_from_deposit(const InterestRateInstrumentQuote& market_quote, InterestRateCurve& curve);
        static void bootstrap_curve_from_fra(const InterestRateInstrumentQuote& market_quote, InterestRateCurve& curve);
        static void bootstrap_curve_from_swap(const InterestRateInstrumentQuote& market_quote, InterestRateCurve& curve);
};
