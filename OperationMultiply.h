#ifndef OPERATIONMULTIPLY_H
#define OPERATIONMULTIPLY_H

#include "IOperation.h"

class OperationMultiply : public IOperation
{
    // IOperation interface
public:
    void operate(std::stack<double> &operationStack);
};

#endif
