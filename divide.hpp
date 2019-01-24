#ifndef DIVIDE_HPP
#define DIVIDE_HPP

#include "operation.hpp"

namespace CalculatorPolish
{
    class Divide : public Operation
    {
    public:
        /**
         * @brief divide first operand by second
         * @param first - dividend
         * @param second - divisor
         * @return result of division
         */
        virtual const double perform(const double first, const double second) const override;
    };
}

#endif
