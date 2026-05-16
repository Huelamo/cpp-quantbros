#include <iostream>
#include "Deposit.hpp"
#include "InterestRatePillar.h"
#include "InterestRateCurve.h"

int main()
{
    // Instantiate a 1-year deposit
    DepositAttributes deposit_attributes{
        .tenor = 1.0,
        .rate = 0.05,
        .compounding = CompoundingType::Compounded
    };
    Deposit deposit(deposit_attributes);

    std::cout << deposit.discount_factor() << std::endl;

    // Set IR pillar attributes from deposit
    InterestRatePillarAttributes pillar_1y_attributes{
    .tenor = deposit.tenor(),
    .discount_factor = deposit.discount_factor()
    };
    InterestRatePillar pillar_1y(pillar_1y_attributes);

    // Set the pillar in InterestRateCurve
    InterestRateCurve ir_curve;
    ir_curve.set_discount_factor(pillar_1y);

    // Create a vector of deposits
    std::vector<Deposit> deposits{
    deposit,
    Deposit(
    {.tenor = 2.0,
                .rate = 0.06,
                .compounding = CompoundingType::Compounded}
                ),
        Deposit(
    {.tenor = 5.0,
                .rate = 0.075,
                .compounding = CompoundingType::Compounded}
                )
    };

    // Build IR curve from the vector of Deposits
    ir_curve.build_discount_curve_from_deposits(deposits);
    return 0;

};