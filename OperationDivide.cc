#include "OperationDivide.h"
#include "calcExceptions.h"
#include "calculatorHelper.h"

void OperationDivide::operate(std::stack<double> &operationStack)
{
    double op1 = NCalculatorHelper::popFromStack(operationStack);
    double op2 = NCalculatorHelper::popFromStack(operationStack);

    if (op1 == 0)
    {
        //throw ERROR_DIVISION_BY_ZERO;
        throw DivisionByZeroException();
    }
    double result = op2 / op1;
    operationStack.push(result);
}
