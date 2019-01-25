#include "calculator.h"
#include <stack>
#include <stdexcept>
#include <assert.h>

#include "calcExceptions.h"
#include "OperationPlus.h"
#include "OperationMinus.h"
#include "OperationMultiply.h"
#include "OperationDivide.h"

#include "calculatorHelper.h"
#include "calculatorConstants.h"


double calculate(const std::string &eval)
{
    std::stack<double> operationStack;
    stringVector parsedValues = splitString(eval, NCalculatorConstats::DEFAULT_SEPARATOR);

    assert(parsedValues.size() >= NCalculatorConstats::MINIMUM_STACK_SIZE);

    for (const auto &c: parsedValues)
    {
       handleToken(operationStack, c);
    }

    throwExceptionIfInvalidStack(operationStack);

    return operationStack.top();
}


stringVector splitString(const std::string& input, const char divider)
{
    stringVector result;
    std::string part;
    auto pushPart = [&part, &result]
    {
        result.push_back(part);
        part.clear();
    };

    for (auto c: input)
    {
        c == divider ? pushPart() : part.push_back(c);
    }
    result.push_back(part);

    if (result.size() == 1 && result[0].empty())
    {
        throw ERROR_EMPTY_INPUT;
    }

    return result;
}


void handleToken(std::stack<double> &stackToOperateOn, const std::string &token)
{
    if (isOperation(token) && stackToOperateOn.size() >= NCalculatorConstats::MINIMUM_STACK_SIZE)
    {
        auto operation = getOperation(token);
        operation->operate(stackToOperateOn);
    }
    if (isNumber(token))
    {
        double operand = std::stod(token);
        stackToOperateOn.push(operand);
    }
}

OperationPtr getOperation(const std::string &typeOfOperation)
{
    switch (typeOfOperation[0])
    {
        case '+': return std::make_shared<OperationPlus>();
        case '-': return std::make_shared<OperationMinus>();
        case '*': return std::make_shared<OperationMultiply>();
        case '/': return std::make_shared<OperationDivide>();
        default: throw "Invalid operation";
    }
}

bool isNumber(const std::string& token)
{
    try
    {
        std::stod(token);
        return true;
    }
    catch (std::exception)
    {
        return false;
    }
}

bool isOperation(const std::string &token)
{
    return token.find_last_not_of("+-*/") == std::string::npos;
}

void throwExceptionIfInvalidStack(const std::stack<double>& operationStack)
{
    if (operationStack.empty())
    {
        throw ERROR_NO_OPERANDS;
    }
    if(operationStack.size() > 1)
    {
        throw ERROR_TOO_MUCH_OPERANDS;
    }
}
