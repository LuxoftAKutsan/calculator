#include "calculatorHelper.h"
#include <assert.h>

double NCalculatorHelper::popFromStack(std::stack<double> &input)
{
    assert(false == input.empty());

    double result = input.top();
    input.pop();

    return result;
}
