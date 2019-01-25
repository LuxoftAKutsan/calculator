#include "OperationMultiply.h"

#include "calculatorHelper.h"

void OperationMultiply::operate(std::stack<double> &operationStack)
{
    double result = NCalculatorHelper::popFromStack(operationStack);
    result *= NCalculatorHelper::popFromStack(operationStack);
    operationStack.push(result);
}
