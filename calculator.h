#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>
#include <stack>
#include "IOperation.h"
#include <memory>

//TODO: add functions' description

using OperationPtr = std::shared_ptr<IOperation>;

enum eCalculatorError
{
    ERROR_DIVISION_BY_ZERO,
    ERROR_EMPTY_INPUT,
    ERROR_NO_OPERANDS,
    ERROR_TOO_MUCH_OPERANDS
};

using stringVector = std::vector<std::string>;

double calculate(const std::string& eval);

void handleToken(std::stack<double>& stackToOperateOn, const std::string& token);

stringVector splitString(const std::string& input, const char divider);

OperationPtr getOperation(const std::string& typeOfOperation);

bool isNumber(const std::string& token);
bool isOperation(const std::string& token);
void throwExceptionIfInvalidStack(const std::stack<double> &operationStack);

#endif //CALCULATOR_H
