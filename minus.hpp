#ifndef MINUS_HPP
#define MINUS_HPP

#include "operation.hpp"

namespace CalculatorPolish
{
    class Minus : public Operation
    {
    public:
        /**
         * @brief subtract second operand from first
         * @param first - minuend
         * @param second - subtrahend
         * @return result of subtraction
         */
        virtual const double perform(const double first, const double second) const override;
    };
}

#endif
