#ifndef PLUS_HPP
#define PLUS_HPP

#include "operation.hpp"

namespace CalculatorPolish
{
    class Plus : public Operation
    {
    public:
        /**
         * @brief add operands
         * @param first summand
         * @param second summand
         * @return result of addition
         */
        virtual const double perform(const double first, const double second) const override;
    };
}

#endif
