//
// Created by Diego Huélamo Longás on 16/05/2026.
//

#include "interest_rate_instrument_quote.h"
#include "interest_rate_instrument_type.h"

InterestRateInstrumentQuote::InterestRateInstrumentQuote(const InterestRateInstrumentQuoteAttributes& attr) :
    market_quote_(attr.market_quote), instrument_type_(attr.instrument_type), compounding_type_(attr.compounding),
    time_to_maturity_years_(attr.time_to_maturity_years)
{
}

double InterestRateInstrumentQuote::market_quote() const
{
    return market_quote_;
}

double InterestRateInstrumentQuote::time_to_maturity_years() const
{
    return time_to_maturity_years_;
}

InterestRateInstrumentType InterestRateInstrumentQuote::instrument_type() const
{
    return instrument_type_;
}

CompoundingType InterestRateInstrumentQuote::compounding_type() const
{
    return compounding_type_;
}
