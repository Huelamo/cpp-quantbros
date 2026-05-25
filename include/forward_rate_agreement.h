//
// Created by Diego Huélamo Longás on 17/05/2026.
//

#pragma once
#include "interest_rate_instrument_quote.h"

struct ForwardRateAgreementAttributes
{
    // Parent class attributes
    InterestRateInstrumentType instrument_type;
    CompoundingType compounding;
    double market_quote;
    double time_to_maturity_years;
};

class ForwardRateAgreement : public InterestRateInstrumentQuote
{
public:
    explicit ForwardRateAgreement(const ForwardRateAgreementAttributes& attributes);
    double implied_quote(const InterestRateCurve& curve) const override;

};
