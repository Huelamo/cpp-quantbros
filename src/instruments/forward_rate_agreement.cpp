//
// Created by Diego Huélamo Longás on 17/05/2026.
//

#include "forward_rate_agreement.h"

ForwardRateAgreement::ForwardRateAgreement(const ForwardRateAgreementAttributes& attributes)
    : InterestRateInstrumentQuote(
          {
              .instrument_type = InterestRateInstrumentType::FRA,
              .compounding = attributes.compounding,
              .market_quote = attributes.market_quote,
              .time_to_maturity_years = attributes.time_to_maturity_years
          })
{
}

double ForwardRateAgreement::implied_quote(const InterestRateCurve& curve) const
{
    return 0.0;
}
