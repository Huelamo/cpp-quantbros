//
// Created by Diego Huélamo Longás on 16/05/2026.
//

#pragma once

#include "compounding_type.hpp"
#include "interest_rate_instrument_type.h"
#include "interest_rate_curve.h"

struct InterestRateInstrumentQuoteAttributes
{
    InterestRateInstrumentType instrument_type;
    CompoundingType compounding;
    double market_quote;
    double time_to_maturity_years;
};

class InterestRateInstrumentQuote
{
public:
    virtual ~InterestRateInstrumentQuote() = default;
    double market_quote() const;
    double time_to_maturity_years() const;
    InterestRateInstrumentType instrument_type() const;
    CompoundingType compounding_type() const;
    virtual double implied_quote(const InterestRateCurve& curve) const = 0;
protected:
    explicit InterestRateInstrumentQuote(const InterestRateInstrumentQuoteAttributes& attr);

private:
    const double market_quote_;
    const double time_to_maturity_years_;
    InterestRateInstrumentType instrument_type_;
    CompoundingType compounding_type_;
};
