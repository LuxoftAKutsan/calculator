#include "calculator.h"

#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <unordered_map>
#include <functional>
#include <stack>
#include <cassert>
#include <algorithm>

constexpr int OPERANDS_MIN_NUM = 2;

auto invalidResult = []() -> std::pair<tResultType, double>
{
    return std::make_pair(false, 0.0);
};

const std::unordered_map<std::string, std::function<double(double,double)>> OPERATIONS_MAP
{
    { "+", std::plus<double>() },
    { "-", std::minus<double>() },
    { "*", std::multiplies<double>() },
    { "/", std::divides<double>() }
};

bool containsAnyLetter(const std::string& str)
{
    assert(!str.empty());
    return std::any_of(str.cbegin(),
                       str.cend(),
                       [](char c) { return ::isalpha(c); });
}

bool containsOnlyNumber(const std::string& str)
{
    assert(!str.empty());
    auto begin = str.begin();

    if (*begin == '-') {
       begin = std::next(begin);
    }

    const bool all_digits = std::all_of(begin, str.end(), ::isdigit);
    return begin == str.end() ? false : all_digits;
}

std::pair<tResultType, double> evaluatePolishNotation(const std::vector<std::string>& tokens)
{
    std::stack<double> stack;

    for (const auto& token : tokens)
    {
        if (containsOnlyNumber(token))
        {
           stack.push(std::stoi(token));
           continue;
        }

        const auto& it = OPERATIONS_MAP.find(token);
        if (it != OPERATIONS_MAP.end())
        {
          const auto& operation = it->second;

          if(stack. size() < OPERANDS_MIN_NUM)
          {
              return invalidResult();
          }

          double rhs = stack.top(); stack.pop();
          double lhs = stack.top(); stack.pop();

          if(token == "/" && rhs == 0.0)
          {
              return invalidResult();
          }
          stack.push(operation(lhs, rhs));
          continue;
        }
        return invalidResult();
    }

    assert(!stack.empty());
    return std::make_pair(true, stack.top());
}

std::pair<tResultType,double> calculate(const std::string& evals)
{
    if (evals.empty() || containsAnyLetter(evals))
    {
        return invalidResult();
    }

    std::istringstream iss{evals};
    std::vector<std::string> strippedString(std::istream_iterator<std::string>{iss},
                                            std::istream_iterator<std::string>{});
    return evaluatePolishNotation(strippedString);
}
