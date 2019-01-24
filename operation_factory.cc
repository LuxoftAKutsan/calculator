#include "operation_factory.hpp"
#include "plus.hpp"
#include "minus.hpp"
#include "multiply.hpp"
#include "divide.hpp"
#include <stdexcept>

const CalculatorPolish::Operation* CalculatorPolish::OperationFactory::defineOperation(char operation)
{
    switch(operation)
    {
    case '+':
        return new CalculatorPolish::Plus();
    case '-':
        return new Minus();
    case '*':
        return new Multiply();
    case '/':
        return new Divide();
    default:
        throw std::invalid_argument("Wrong operand");
    }
}
