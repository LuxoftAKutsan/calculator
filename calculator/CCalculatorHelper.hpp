#ifndef CCALCULATOR_HELPER_HPP
#define CCALCULATOR_HELPER_HPP

#include <string>
#include <vector>


template<class RESULT_TYPE, class ERROR_TYPE = unsigned int>
struct FinishPackage
{
    RESULT_TYPE result;
    bool isValid;

    const ERROR_TYPE& getError() const
    {
        return error;
    }

    void setError(const ERROR_TYPE& value)
    {
        isValid = false;
        error = value;
    }

private:
    ERROR_TYPE error;

};

std::vector<std::string> split(const std::string& str, char separator);

FinishPackage<double> calculate(const std::string& eval);

#endif //CCALCULATOR_HELPER_HPP
