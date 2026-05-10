cmake_minimum_required(VERSION 3.20)
project(cpp_quantbros)

set(CMAKE_CXX_STANDARD 20)

add_executable(pricing_examples
        scripts/pricing_examples.cpp
        src/engine/analytic_pricing_formulas.cpp
        src/engine/payoffs.cpp
        src/engine/interest_rate_curve_construction/deposit.cpp
        include/deposit.hpp
)

add_executable(curve_bootstrapping
        scripts/curve_bootstrapping_example.cpp
        src/engine/interest_rate_curve_construction/deposit.cpp
        include/deposit.hpp
        include/compounding_type.hpp
)

target_include_directories(pricing_examples PRIVATE include)

target_include_directories(curve_bootstrapping PRIVATE include)