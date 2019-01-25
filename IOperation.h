#ifndef IOPERATION_H
#define IOPERATION_H

#include <stack>

class IOperation
{
public:
    virtual void operate(std::stack<double>& operationStack) = 0;

    virtual ~IOperation(){}
};

#endif
