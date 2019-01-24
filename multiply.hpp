#ifndef MULTIPLY_HPP
#define MULTIPLY_HPP

#include "operation.hpp"

namespace CalculatorPolish
{
    class Multiply : public Operation
    {
    public:
        /**
         * @brief multiply operands
         * @param first factor
         * @param second factor
         * @return result of multiplication
         */
        virtual const double perform(const double first, const double second) const override;
    };
}

#endif
