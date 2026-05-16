cmake_minimum_required(VERSION 3.20)
project(cpp_quantbros)

set(CMAKE_CXX_STANDARD 20)

add_executable(pricing_examples
        scripts/pricing_examples.cpp
        src/engine/analytic_pricing_formulas.cpp
        src/engine/payoffs.cpp
)

add_executable(curve_bootstrapping
        scripts/curve_bootstrapping_example.cpp
        include/compounding_type.hpp
        include/interest_rate_instrument_type.h
        src/engine/interest_rate_curve_construction/interest_rate_curve.cpp
        src/engine/interest_rate_curve_construction/interest_rate_pillar.cpp
        include/interest_rate_curve.h
        include/interest_rate_pillar.hpp
        include/interest_rate_instrument_quote.h
        src/engine/interest_rate_curve_construction/interest_rate_instrument_quote.cpp
        include/interest_rate_math.h
        src/engine/interest_rate_curve_construction/interest_rate_math.cpp
        include/bootstrapping_engine.h
        src/engine/interest_rate_curve_construction/bootstrapping_engine.cpp
)

target_include_directories(pricing_examples PRIVATE include)

target_include_directories(curve_bootstrapping PRIVATE include)
