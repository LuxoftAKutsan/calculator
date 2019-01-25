#ifndef OPERATIONPLUS_H
#define OPERATIONPLUS_H

#include "IOperation.h"

class OperationPlus : public IOperation
{
    // IOperation interface
public:
    void operate(std::stack<double> &operationStack);
};

#endif
