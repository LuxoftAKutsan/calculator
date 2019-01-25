#include"calculator.hpp"
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
/*
 * Calculator by MK
*/

bool double_equals( double a, double b, double epsilon )
{
    return std::abs( a - b ) < epsilon;
}

std::deque<std::string> split( const std::string& str, char delim )
{
    std::deque<std::string> returnContainer;
    std::stringstream streamFromString ( str );
    std::string element;
    while ( std::getline( streamFromString, element, delim ) )
    {
        returnContainer.push_back( element );
    }
    return returnContainer;
}

inline bool isContainerValidForNextStep(const std::deque<std::string>& container )
{
    return ( ! container.empty() ) && ( 2 < container.size() );
}

double calculate( const std::string input )
{
    auto container = split( input );
    sOperands operands;
    double result{ DBL_MAX };
    while ( true == isContainerValidForNextStep(container) )
    {
        try
        {
            operands = extractItemsForOperation( container );
        }
        catch( int i )
        {
            return ERROR_CODE;
        }
        result = calculate( operands );
        container.push_front( std::to_string( result ) );
    }
    return result;
}

struct sOperands extractItemsForOperation( std::deque<std::string>& container )
{
    sOperands returnOperands;
    if ( true == isContainerValidForNextStep(container) )
    {
        try
        {
            returnOperands.first = std::stod( container[0] );
            returnOperands.second = std::stod( container[1] );
        }
        catch( std::exception e )
        {
            throw -1;
        }
        returnOperands.operation = container[2][0];
        container.pop_front();
        container.pop_front();
        container.pop_front();
    }
    return returnOperands;
}

double calculate( const sOperands operands )
{
    switch ( operands.operation )
    {
    case '+': return plus( operands.first, operands.second );
    case '-': return minus( operands.first, operands.second );
    case '*': return multiply( operands.first, operands.second );
    case '/': return divide( operands.first, operands.second );
    default: return ERROR_CODE;
    }
}

double plus( const double a, const double b )
{
    return a + b;
}
double minus( const double a, const double b )
{
    return a - b;
}
double multiply( const double a, const double b )
{
    return a * b;
}
double divide( const double a, const double b )
{
    if ( 0.0 == b )
    {
        return ERROR_CODE;
    }
    return a / b;
}

