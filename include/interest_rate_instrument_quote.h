//
// Created by Diego Huélamo Longás on 16/05/2026.
//

#pragma once

#include "compounding_type.hpp"
#include "interest_rate_instrument_type.h"

struct InterestRateInstrumentQuoteAttributes
{
    InterestRateInstrumentType instrument_type;
    CompoundingType compounding;
    double market_quote;
};

class InterestRateInstrumentQuote
{
public:
    virtual ~InterestRateInstrumentQuote() = default;
    double market_quote() const;
    InterestRateInstrumentType instrument_type() const;
    CompoundingType compounding_type() const;
    virtual void dont_know_yet() const = 0;
    // TODO: this is just to make the class abstract, will be removed when we have a common interface for all instruments
protected:
    explicit InterestRateInstrumentQuote(const InterestRateInstrumentQuoteAttributes& attr);

private:
    const double market_quote_;
    InterestRateInstrumentType instrument_type_;
    CompoundingType compounding_type_;
};
