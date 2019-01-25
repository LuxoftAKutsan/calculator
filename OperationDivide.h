#ifndef OPERATIONDIVIDE_H
#define OPERATIONDIVIDE_H

#include "IOperation.h"

class OperationDivide : public IOperation
{
    // IOperation interface
public:
    void operate(std::stack<double> &operationStack);
};

#endif
