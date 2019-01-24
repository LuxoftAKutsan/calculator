#ifndef OPERATION_FACTORY_HPP
#define OPERATION_FACTORY_HPP

#include "operation.hpp"

namespace CalculatorPolish
{

    class OperationFactory
    {
    public:
        static const Operation* defineOperation(char operation);
    };

}

#endif
