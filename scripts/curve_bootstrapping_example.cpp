#include <iostream>

#include "bootstrapping_engine.h"
#include "interest_rate_curve.h"
#include "deposit.h"
#include "forward_rate_agreement.h"
#include "swap.h"

int main()
{
    CompoundingType compounding = CompoundingType::Continuous;

    // Initialize a market quote for a deposit
    auto deposit = Deposit({
        .compounding = compounding,
        .market_quote = 0.02, // 2% interest rate
        .tenor_years = 0.5 // 6 months
    });

    // Bootstrap the DF from the deposit quote
    auto ir_curve = BootstrappingEngine::bootstrap_curve(deposit);

    // Initialize a market quote for a FRA
    auto fra = ForwardRateAgreement({
        .compounding = compounding,
        .market_quote = 0.027,
        .tenor_years = 1.0
    });

    // Bootstrap the DF from the FRA quote
    BootstrappingEngine::bootstrap_curve(fra, ir_curve);

    // Initialize a market quote for a Swap
    auto swap = Swap({
        .compounding = compounding,
        .market_quote = 0.032,
        .tenor_start = 0.0,
        .tenor_maturity = 5.0,
        .fixed_leg_period = 1.0
    });

    // Bootstrap the DF from the Swap quote
    // BootstrappingEngine::bootstrap_curve(swap, ir_curve);

    return 0;
};
