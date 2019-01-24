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

namespace CalculatorPolish
{

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
            bool num = true;
            for(int i = firstChar; '\0' != token[i]; ++i)
            {
                if((token[i] < '0' || token[i] > '9') && token[i] != '.' && token[i] != '+' && token[i] != '-' )
                {
                    num = false;
                    break;
                }
            }
            if(firstFilled && secondFilled)
            {
                switch(token[firstChar])
                {
                case '+':
                    current.setOperation(new Plus());
                    secondFilled = false;
                    break;
                case '-':
                    current.setOperation(new Minus());
                    secondFilled = false;
                    break;
                case '*':
                    current.setOperation(new Multiply());
                    secondFilled = false;
                    break;
                case '/':
                    current.setOperation(new Divide());
                    secondFilled = false;
                    break;
                default:
                    delete exp;
                    throw std::invalid_argument("Wrong operand");
                }

                current.setFirst(current.evaluate());
                continue;
            }
            if(num)
            {
                printf("%s\n", token);
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
