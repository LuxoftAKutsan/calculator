#include "multiply.hpp"
#include <cmath>
#include <stdexcept>

const double CalculatorPolish::Multiply::perform(const double first, const double second) const
{
    auto result = first * second;
    if(!std::isfinite(result))
    {
        throw std::overflow_error("Double overflow");
    }
    return result;
}
