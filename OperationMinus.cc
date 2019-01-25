
#include "OperationMinus.h"
#include "calculatorHelper.h"

void OperationMinus::operate(std::stack<double> &operationStack)
{
    double op1 = NCalculatorHelper::popFromStack(operationStack);
    double op2 = NCalculatorHelper::popFromStack(operationStack);
    double result = op2 - op1;
    operationStack.push(result);
}
