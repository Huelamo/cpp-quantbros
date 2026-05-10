#pragma once

#include "compounding_type.hpp"

struct DepositAttributes
{
    double tenor;
    double rate;
    CompoundingType compounding;
};

class Deposit
{
public:
    explicit Deposit(const DepositAttributes& attributes);

    double tenor() const;
    double rate() const;
    CompoundingType compounding() const;
    double discount_factor() const;
private:
    double tenor_;
    double rate_;
    CompoundingType compounding_;
};


