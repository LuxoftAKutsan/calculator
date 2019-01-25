
#include "OperationMinus.h"
#include "calculatorHelper.h"

void OperationMinus::operate(std::stack<double> &operationStack)
{
    double subtrahend = NCalculatorHelper::popFromStack(operationStack);
    double minuend = NCalculatorHelper::popFromStack(operationStack);
    double result = minuend - subtrahend;
    operationStack.push(result);
}
