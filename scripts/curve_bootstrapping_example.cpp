#include <iostream>

#include "bootstrapping_engine.h"
#include "interest_rate_curve.h"
#include "deposit.h"
int main()
{
    CompoundingType compounding = CompoundingType::Continuous;

    // Initialize an empty interest rate curve
    InterestRateCurve ir_curve;

    // Initialize a market quote for a deposit
    auto deposit = InterestRateInstrumentQuote({
        .tenor = 0.5, // 6 months
        .quote = 0.02, // 2% interest rate
        .instrument_type = InterestRateInstrumentType::Deposit,
        .compounding_type = CompoundingType::Continuous
    });

    // Bootstrap the DF from the deposit quote
    ir_curve = BootstrappingEngine::bootstrap_curve(deposit);

    // Initialize a market quote for a FRA
    auto fra = InterestRateInstrumentQuote({
    .tenor = 1.0,
    .quote = 0.027,
    .instrument_type = InterestRateInstrumentType::FRA,
    .compounding_type = CompoundingType::Continuous});

    // Bootstrap the DF from the FRA quote
    BootstrappingEngine::bootstrap_curve(fra, ir_curve);

    // Initialize a market quote for a Swap
    auto swap = InterestRateInstrumentQuote({
    .tenor = 2.0,
    .quote = 0.032,
    .instrument_type = InterestRateInstrumentType::Swap,
    .compounding_type = CompoundingType::Continuous});

    // Bootstrap the DF from the Swap quote
    BootstrappingEngine::bootstrap_curve(swap, ir_curve);

    return 0;

};
