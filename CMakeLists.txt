cmake_minimum_required(VERSION 3.20)
project(cpp_quantbros)

set(CMAKE_CXX_STANDARD 20)

add_executable(pricing_examples
        scripts/pricing_examples.cpp
        src/engine/analytic_pricing_formulas.cpp
        src/engine/payoffs.cpp
)

target_include_directories(pricing_examples PRIVATE include)