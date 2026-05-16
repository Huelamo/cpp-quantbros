#pragma once

#include <optional>

#include "compounding_type.hpp"

struct InterestRatePillarAttributes
{
    double tenor;
    std::optional<double> rate = std::nullopt;
    std::optional<double> discount_factor = std::nullopt;
};

class InterestRatePillar
{
public:
    explicit InterestRatePillar(const InterestRatePillarAttributes& attributes);

    double tenor() const;
    static constexpr CompoundingType DefaultCompoundingType = CompoundingType::Continuous;
    double rate(const CompoundingType& compounding = DefaultCompoundingType) const;
    double discount_factor(const CompoundingType& compounding = DefaultCompoundingType) const;
private:
    double tenor_;
    std::optional<double> rate_;
    std::optional<double> discount_factor_;
    double compute_discount_factor(const CompoundingType& compounding) const;
    double compute_zero_coupon_rate(const CompoundingType& compounding) const;

};

