#ifndef OPERATIONMINUS_H
#define OPERATIONMINUS_H

#include "IOperation.h"

class OperationMinus : public IOperation
{
    // IOperation interface
public:
    void operate(std::stack<double> &operationStack);
};

#endif
