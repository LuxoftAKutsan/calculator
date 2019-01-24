#include "calc.hpp"

Calc::Calc(const char* input) 
    : mInput(input)
{

}

std::pair<Calc::EReturnCodes, double> Calc::calculate()
{
    if(mInput.empty())
        return std::make_pair(EReturnCodes::EMPTY_STRING, 0);
    for(const auto c : mInput)
    {
        const auto result = processChar(c);
        if(EReturnCodes::RESULT_OK != result)
        {
            return std::make_pair(result, 0);
        }
    }
    return std::make_pair(EReturnCodes::RESULT_OK, mStack.top());
}

Calc::EReturnCodes Calc::processChar(const char input)
{
    if(input > '9')
        return EReturnCodes::WRONG_ARGUMENT;
    if(input == DELIMITER)
    {
        if(!mBuffer.empty())
        {
            mStack.emplace(std::stoi(mBuffer));
            mBuffer.clear();
        }
        return EReturnCodes::RESULT_OK;
    }
    if(input >= '0' and input <='9')
    {
        mBuffer += input;
        return EReturnCodes::RESULT_OK;
    }
    if(mStack.size() < 2)
        return EReturnCodes::WRONG_ORDER;
    const double& op2 = mStack.top(); mStack.pop();
    const double& op1 = mStack.top(); mStack.pop();
    long double result;
    switch(input)
    {
        case '+':
            result = (op1 + op2);
            break;
        case '-':
            result = (op1 - op2);
            break;
        case '*':
            result = (op1 * op2);
            break;
        case '/':
            if(0 == op2)
                return EReturnCodes::DIVISION_BY_ZERO;
            result = (op1 / op2);
            break;
        default:
            return EReturnCodes::WRONG_OPERATION;
    }
    mStack.emplace(result);
    mBuffer.clear();
    return EReturnCodes::RESULT_OK;
}
