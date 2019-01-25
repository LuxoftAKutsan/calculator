#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<string>
#include <deque>
#include <cfloat>

#define ERROR_CODE DBL_MAX

double calculate(const std::string input);
std::deque<std::string> split( const std::string& str, char delim = ' ');
struct sOperands extractItemsForOperation( std::deque<std::string>& container );
double calculate( const sOperands operands );
bool double_equals( double a, double b, double epsilon = 0.000001 );
double plus( const double a, const double b );
double minus( const double a, const double b );
double multiply( const double a, const double b );
double divide( const double a, const double b );

struct sOperands
{
    double first;
    double second;
    char operation;
};

#endif //CALCULATOR_H
