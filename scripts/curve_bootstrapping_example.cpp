#include <iostream>
#include "deposit.hpp"

int main()
{
    DepositAttributes deposit_attributes{
        .tenor = 1.0,
        .rate = 0.05,
        .compounding = CompoundingType::Compounded
    };
    Deposit deposit(deposit_attributes);

    std::cout << deposit.discount_factor() << std::endl;

};