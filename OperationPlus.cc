#include "OperationPlus.h"
#include "calculatorHelper.h"

void OperationPlus::operate(std::stack<double> &operationStack)
{
    double result = NCalculatorHelper::popFromStack(operationStack);
    result += NCalculatorHelper::popFromStack(operationStack);
    operationStack.push(result);
}
