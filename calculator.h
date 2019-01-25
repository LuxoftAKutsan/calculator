#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>
#include <sstream>
#include <tuple>


enum Operation {
  NONE = 0,
  ADD = 1,
  SUBTRACT = 2,
  MULTIPLY = 3,
  DIVIDE = 4
};

std::vector<std::string> split(const std::string& str, char delim = ' ');

template <typename T>
struct Result{
    bool mSuccess;
    T mResult;
    Result(bool success, T result):
        mSuccess(success),
        mResult(result)
    {}
    operator bool() const
    {
        return mSuccess;
    }
    T operator* ()
    {
        return mResult;
    }
};

class Calculator
{
public:
    Calculator(){}
    std::vector<std::tuple<double,Operation>> op_vector;
    double first_value;
    Result<double> calculate(const std::string &str);
private:
    bool parseString(const std::string &str);
    Result<double> getNumber(const std::string &str);
    Result<Operation> getOperation(const std::string &str);
    Result<double> doOperation(double arg1, double arg2, Operation op);
};


#endif //CALCULATOR_H
