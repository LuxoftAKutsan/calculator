#include "calculator.hpp"
#include <vector>
#include <cstring>
#include <cstdlib>
#include <stdexcept>
#include <cmath>
#include "expression.hpp"
#include "plus.hpp"
#include "minus.hpp"
#include "multiply.hpp"
#include "divide.hpp"
#include "operation_factory.hpp"

namespace CalculatorPolish
{


    bool Calculator::CheckNum(const std::string& token) {
        auto it = token.find_last_not_of("1234567890+-.");
        return it == std::string::npos;
    }

    double Calculator::calculate(const std::string& expression)
    {
        char* exp = new char[expression.length() + nullTerminatorLength];
        strcpy(exp, expression.c_str());
        char* token;
        Expression current;
        bool firstFilled = false;
        bool secondFilled = false;
        while(nullptr != (token = strtok(firstFilled ? nullptr : exp, " ")))
        {
            bool num = CheckNum(std::string(token));
            if(firstFilled && secondFilled)
            {
                current.setOperation(OperationFactory::defineOperation(token[firstChar]));
                secondFilled = false;
                current.setFirst(current.evaluate());
                continue;
            }
            if(num)
            {
                auto numtok = strtod(token, nullptr);
                if(!firstFilled)
                {
                    current.setFirst(numtok);
                    firstFilled = true;
                }
                else
                {
                    current.setSecond(numtok);
                    secondFilled = true;
                }
            }
            if(!num && !(firstFilled && secondFilled))
            {
                delete exp;
                throw std::invalid_argument("Wrong order");
            }
        }
        if(!firstFilled)
        {
            delete exp;
            throw std::invalid_argument("First argument not number");
        }
        if(secondFilled)
        {
            delete exp;
            throw std::invalid_argument("More operands than operations");
        }
        delete exp;
        return current.getResult();
    }

}
