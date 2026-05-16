//
// Created by Diego Huélamo Longás on 15/05/2026.
//

#pragma once
#include <vector>

#include "interest_rate_pillar.hpp"
#include "compounding_type.hpp"
#include "interest_rate_instrument_quote.h"

class InterestRateCurve
{
    public:
        InterestRateCurve() = default;
        CompoundingType compounding_type() const;
        std::vector<InterestRatePillar> pillars() const;
        void set_pillar(const InterestRatePillar& pillar);
        void bootstrap_curve(const InterestRateInstrumentQuote& quote) const;

    private:
        std::vector<InterestRatePillar> pillars_;
        CompoundingType compounding_type_{CompoundingType::Continuous};
    void bootstrap_curve_from_deposit(const InterestRateInstrumentQuote& quote) const;
    void bootstrap_curve_from_fra(const InterestRateInstrumentQuote& quote) const;
    void bootstrap_curve_from_swap(const InterestRateInstrumentQuote& quote) const;

};
