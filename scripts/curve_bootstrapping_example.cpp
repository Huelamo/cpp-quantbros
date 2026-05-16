#include <iostream>
#include "interest_rate_pillar.hpp"
#include "interest_rate_curve.h"

int main()
{
    CompoundingType compounding = CompoundingType::Continuous;
    InterestRatePillarAttributes pillar_attributes{
        .tenor = 1.0,
        .rate = 0.05
    };
    InterestRatePillar pillar(pillar_attributes);

    std::cout << pillar.compute_discount_factor(compounding) << std::endl;

    // Set the pillar in InterestRateCurve
    InterestRateCurve ir_curve;
    ir_curve.set_pillar(pillar);

    // Create a vector of pillars
    std::vector<InterestRatePillar> pillars{
        pillar,
        InterestRatePillar(
            {.tenor = 2.0,
                .rate = 0.06}
        ),
        InterestRatePillar(
            {.tenor = 5.0,
                .rate = 0.075}
        )
    };

    // Build IR curve from the vector of pillars
    ir_curve.build_curve_from_pillars(pillars);
    return 0;

};
