#include "OperationDivide.h"
#include "calcExceptions.h"
#include "calculatorHelper.h"

void OperationDivide::operate(std::stack<double> &operationStack)
{
    double divisor = NCalculatorHelper::popFromStack(operationStack);
    double dividend = NCalculatorHelper::popFromStack(operationStack);

    if (divisor == 0)
    {
        throw DivisionByZeroException();
    }
    double result = dividend / divisor;
    operationStack.push(result);
}
