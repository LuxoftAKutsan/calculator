#include "divide.hpp"
#include <stdexcept>
#include <cmath>

const double CalculatorPolish::Divide::perform(const double first, const double second) const
{
    if(0 == static_cast<int>(second))
    {
        throw std::overflow_error("Division by zero");
    }
    auto result = first / second;
    if(!std::isnormal(result) && 0. != first)
    {
        throw std::overflow_error("Double overflow");
    }
    return result;
}
