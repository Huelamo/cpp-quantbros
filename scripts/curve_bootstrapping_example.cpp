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
        .time_to_maturity_years = 0.5 // 6 months
    });

    // Bootstrap the DF from the deposit quote
    auto ir_curve = BootstrappingEngine::bootstrap_curve(deposit);

    // Check that we can get back the market quote from the bootstrapped curve
    auto implied_quote_deposit = deposit.implied_quote(ir_curve);

    // Initialize a market quote for a FRA
    auto fra = ForwardRateAgreement({
        .compounding = compounding,
        .market_quote = 0.027,
        .time_to_maturity_years = 1.0
    });

    // Bootstrap the DF from the FRA quote
    BootstrappingEngine::bootstrap_curve(fra, ir_curve);

    // Initialize a market quote for a Swap
    auto swap = Swap({
        .compounding = compounding,
        .market_quote = 0.032,
        .time_to_maturity_years = 2.0,
        .tenor_start_years = 0.0,
        .fixed_leg_period = 1.0
    });

    // Bootstrap the DF from the Swap quote
    BootstrappingEngine::bootstrap_curve(swap, ir_curve);

    // Now test extrapolation
    double df = ir_curve.get_discount_factor(0.75);

    return 0;
};
