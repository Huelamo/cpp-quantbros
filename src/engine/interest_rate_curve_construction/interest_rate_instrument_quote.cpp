//
// Created by Diego Huélamo Longás on 16/05/2026.
//

#include "interest_rate_instrument_quote.h"
#include "interest_rate_instrument_type.h"

InterestRateInstrumentQuote::InterestRateInstrumentQuote(const InterestRateInstrumentQuoteAttributes& attr):
    tenor_(attr.tenor), quote_(attr.quote), instrument_type_(attr.instrument_type)
{
}

double InterestRateInstrumentQuote::tenor() const
{
    return tenor_;
}

double InterestRateInstrumentQuote::quote() const
{
    return quote_;
}

InterestRateInstrumentType InterestRateInstrumentQuote::instrument_type() const
{
    return instrument_type_;
}