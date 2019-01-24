#include "expression.hpp"

CalculatorPolish::Expression::Expression()
    : first(0.)
    , second(0.)
    , op(nullptr)
    , result(0.)
{

}

void CalculatorPolish::Expression::setFirst(const double operand)
{
    first = operand;
}

void CalculatorPolish::Expression::setSecond(const double operand)
{
    second = operand;
}

void CalculatorPolish::Expression::setOperation(const Operation* operation)
{
    op = operation;
}

const double CalculatorPolish::Expression::getResult()
{
    return result;
}

const double CalculatorPolish::Expression::evaluate()
{
    if(nullptr != op)
    {
        result = op->perform(first, second);
    }
    return result;
}

CalculatorPolish::Expression::~Expression()
{
    //delete op;
}
