#pragma once

#include <string>
#include <stack>

struct Calc final
{
    enum class EReturnCodes
    {
        DIVISION_BY_ZERO,
        WRONG_OPERATION,
        WRONG_ARGUMENT,
        EMPTY_STRING,
        WRONG_ORDER,
        UNKNOWN_ERROR,
        RESULT_OK
    };

    explicit Calc(const char*);

    std::pair<EReturnCodes, double> calculate();

private:

    static const char DELIMITER = ' ';

    std::stack<double> mStack;
    std::string        mBuffer;
    const std::string  mInput;

    EReturnCodes processChar(const char input);
};