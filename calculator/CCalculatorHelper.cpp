#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include "CCalculatorHelper.hpp"

// possible encapsulate error code and error msg into class
/*
 * struct IError
 * {
 *   int getErrorCode() const = 0;
 *   const std::string getErrorMsg() const = 0;
 * }
 *
 */

namespace mErrorCode
{
    using tErrorType = unsigned int;

    const tErrorType INVALID_STRING = 0;
    const tErrorType DIVISION_WITH_ZERO = 1;
    const tErrorType ENDEFINED_OPERATION = 2;
    const tErrorType ENDEFINED = 3;
}

std::vector<std::string> split(const std::string &str, char separator)
{
    std::vector<std::string> tokens;

    if(false == str.empty())
    {
        std::string token;
        std::istringstream tokenStream(str);

        while (std::getline(tokenStream, token, separator))
        {
            tokens.emplace_back(token);
        }
    }

    return tokens;
}

bool isNumber( const std::string& value )
{
    return value[0] >= 48 && value[0] <= 57 ; // ascii(48) = '0', ascii(57) = '0'
}

double processOperation( const double& leftOperand, const double& rightOperand, const char oper )
{
    switch(oper)
    {
    case '+' : return leftOperand + rightOperand;
    case '-' : return leftOperand - rightOperand;
    case '*' : return leftOperand * rightOperand;
    case '/' :
    {
        if(0 == rightOperand || 0 == leftOperand)
        {
            throw mErrorCode::DIVISION_WITH_ZERO;
        }
        return leftOperand / rightOperand;
    }

    default : throw mErrorCode::ENDEFINED_OPERATION;
    }
}

bool isExpressionValid(const std::string& eval)
{
    if(true == eval.empty())
    {
        return false;
    }

    const auto EVAL_SIZE = eval.size();
    for(std::size_t i = 0; EVAL_SIZE > i; ++i)
    {
        if(std::isalpha(eval[i]))
        {
            return false;
        }
    }

    return true;
}

FinishPackage<double> calculate(const std::string& eval)
{
    FinishPackage<double> result;
    result.result = 0;
    result.isValid = true;

    if(false == isExpressionValid(eval))
    {
        result.isValid = false;
        result.error = mErrorCode::INVALID_STRING;
        return result;
    }

    std::vector<std::string> tokens(split(eval, ' '));


    std::stack< double > valueStack;
    for(const auto token : tokens)
    {
        if( true == isNumber(token) )
        {
            valueStack.push( std::atof(token.c_str()) );
        }
        else
        {
            if(2 <= valueStack.size())
            {
                const double rightOperand = valueStack.top();
                valueStack.pop();

                const double leftOpernd = valueStack.top();
                valueStack.pop();

                try
                {
                     valueStack.push( processOperation(leftOpernd, rightOperand, token[0]) ) ;
                }
                catch(mErrorCode::tErrorType errorCode)
                {
                    result.isValid = false;
                    result.error = errorCode;

                    return result;
                }
            }
        }
    }

    result.result = valueStack.top();

    return result;
}
