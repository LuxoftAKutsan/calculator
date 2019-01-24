#include "minus.hpp"
#include <cmath>
#include <limits>
#include <stdexcept>

const double CalculatorPolish::Minus::perform(const double first, const double second) const
{
    auto result = first - second;
    std::numeric_limits<double> limit;
    if(!std::isnormal(result) && (first != second || first < limit.min() / 2))
    {
        throw std::overflow_error("Double overflow");
    }
    return result;
}
