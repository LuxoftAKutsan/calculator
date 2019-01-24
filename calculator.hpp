#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <string>

namespace CalculatorPolish
{

    class Calculator
    {
    public:
        /**
         * @brief calculate expression read from given string
         * @param expression to calculate
         * @return value of calculated expression
         */
        double calculate(const std::string& expression);

    private:
        const static int nullTerminatorLength = 1;
        const static int firstChar = 0;
    };

}

#endif
