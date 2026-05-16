//
// Created by Diego Huélamo Longás on 16/05/2026.
//

#pragma once

#include "interest_rate_instrument_type.h"

struct InterestRateInstrumentQuoteAttributes
{
    double tenor;
    double quote;
    InterestRateInstrumentType instrument_type;
};

class InterestRateInstrumentQuote
{
    public:
        explicit InterestRateInstrumentQuote(const InterestRateInstrumentQuoteAttributes& attr);
        double tenor() const;
        double quote() const;
        InterestRateInstrumentType instrument_type() const;
    private:
        double tenor_;
        double quote_;
        InterestRateInstrumentType instrument_type_;
};
