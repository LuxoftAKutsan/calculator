#include"calculator.h"

std::vector<std::__cxx11::string> split(const std::__cxx11::string &str, char delim)
{
        std::stringstream ss(str);
        std::string token;
        std::vector<std::string> container;
        while (std::getline(ss, token, delim)) {
            container.push_back(std::string(token));
        }
        return container;
}

Result<double> Calculator::calculate(const std::string &str)
{
    if(str.length() == 0)
    {
       return Result<double>(false,0);
    }
    if(!parseString(str))
    {
        return Result<double>(false,0);
    }
    double sum = first_value;
    for(size_t i = 0; i < op_vector.size(); i++)
    {
        std::tuple<double,Operation> token = op_vector[i];
        double value = std::get<0>(token);
        Operation operation = std::get<1>(token);
        Result<double> result = doOperation(sum,value,operation);
        if(!result)
        {
           return Result<double>(false,0);
        }
        sum = *result;
    }
    return Result<double>(true,sum);
}

bool Calculator::parseString(const std::string &str)
{
    //check unwanted symbols
    if(str.find_first_not_of("0123456789 /*+-.") != std::string::npos)//no point yet
    {
        return false;
    }
    std::vector<std::string> tokens = split( str );
    op_vector.clear();
    if(tokens.size() % 2 != 1)
    {
        return false;
    }
    Result<double> firstGet = getNumber(tokens[0]);
    if(!firstGet)
    {
        return false;
    }
    first_value = *firstGet;
    for(size_t i = 1; i < tokens.size(); i = i + 2 )
    {
        Result<double> number = getNumber(tokens[i]);
        Result<Operation> operation = getOperation(tokens[i+1]);
        if(!number || !operation)
        {
            return false;
        }
        op_vector.push_back(std::make_tuple(*number,*operation));
    }
    return true;
}

Result<double> Calculator::getNumber(const std::string &str)
{
    if(str.find_first_not_of("0123456789.") != std::string::npos)//no point yet
    {
        return Result<double>(false,0);
    }
    return Result<double>(true,std::stod(str));
}

Result<Operation> Calculator::getOperation(const std::string &str)
{
    if(str.length()!= 1)
    {
        return Result<Operation>(false,NONE);
    }
    char operation = str[0];
    switch (operation) {
    case '+':
        return Result<Operation>(true,ADD);
    case '-':
        return Result<Operation>(true,SUBTRACT);
    case '*':
        return Result<Operation>(true,MULTIPLY);
    case '/':
        return Result<Operation>(true,DIVIDE);
    default:
        return Result<Operation>(false,NONE);
    }
}

Result<double> Calculator::doOperation(double arg1, double arg2, Operation op)
{
    if(op == DIVIDE && arg2 == 0.0)
    {
        return Result<double>(false,0);
    }
    switch (op) {
    case ADD:
        return Result<double>(true,arg1+arg2);
    case SUBTRACT:
        return Result<double>(true,arg1-arg2);
    case MULTIPLY:
        return Result<double>(true,arg1*arg2);
    case DIVIDE:
        return Result<double>(true,arg1/arg2);
    default:
        return Result<double>(false,0);
    }
}
