#ifndef OPERATION_HPP
#define OPERATION_HPP

namespace CalculatorPolish
{
    class Operation
    {
    public:
        /**
         * @brief perform simple operation on operands
         * @param first operand
         * @param second operand
         * @return result of simple operation
         */
        virtual const double perform(const double first, const double second) const = 0;
    };
}

#endif
