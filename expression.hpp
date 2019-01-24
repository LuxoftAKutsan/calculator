#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <string>
#include "operation.hpp"

namespace CalculatorPolish
{

    class Expression
    {
    public:
        Expression();
        /**
         * @brief set first operand of the expression
         * @param operand - number to set
         */
        void setFirst(const double operand);
        /**
         * @brief set second operand of the expression
         * @param operand - number to send
         */
        void setSecond(const double operand);
        /**
         * @brief set type of operation to be performed
         * @param operation desired
         */
        void setOperation(const Operation *operation);
        /**
         * @brief get result of the evaluated expression
         * @return result of the expression
         */
        const double getResult();
        /**
         * @brief evaluate the expression
         * @return result of the expression
         */
        const double evaluate();
        ~Expression();
    private:
        double first;
        double second;
        const Operation* op;

        double result;
    };

}

#endif
