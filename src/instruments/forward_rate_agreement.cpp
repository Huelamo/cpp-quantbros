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
          }),
      tenor_years_(attributes.tenor_years)
{
}

double ForwardRateAgreement::tenor_years() const
{
    return tenor_years_;
}

void ForwardRateAgreement::dont_know_yet() const
{
    return;
}
