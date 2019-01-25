
#include"calculator.h"
#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

struct OneOf
{
   std::string chars;
   OneOf(const std::string& s) : chars(s) {}
   bool operator()(char c) const {
      return chars.find_first_of(c) != std::string::npos;
   }
};


std::pair <EResult, double> calculate(const std::string& str_)
{
   if (str_.empty())
   {
      return { EMPTY_STRING, 0 };
   }

   std::vector<std::string> stringVec = parsingStringToVector(str_);

   EResult analizedResult = analyzeStringForMistakes(stringVec);
   std::pair <EResult, double> result(SUCCESS, 0);

   if (SUCCESS != analizedResult)
   {
      return { analizedResult, 0 };
   }

   result = makeAllCalculationCycles(stringVec);

   return result;
}


EResult analyzeStringForMistakes(const std::vector<std::string>& stringList)
{
   if (stringList.size() < SIZE_OF_BLOCK)
   {
      return NO_MUCH_ARGUMENTS;
   }

   for (auto i = 0; i < stringList.size(); i++)
   {
      std::string tmpSubString = stringList[i];
      auto eraseAllValidSigns = [&tmpSubString](const std::string& validSigns)
      {
         tmpSubString.erase(remove_if(tmpSubString.begin(), tmpSubString.end(), OneOf(validSigns)), tmpSubString.end());
      };

      if (0 == i || 0 != i % 2) //DIGITS
      {
         eraseAllValidSigns(VALID_DIGITS);
         if (!tmpSubString.empty())
         {
            return INVALID_DIGIT;
         }
      }
      else //SIGN
      {
         eraseAllValidSigns(validSigns);
         if (!tmpSubString.empty())
         {
            return INVALID_SIGN;
         }
      }
   }
   return SUCCESS;
}

std::pair<EResult, double> makeAllCalculationCycles(std::vector<std::string>& vectorList)
{
   double iterationResult = 0;
   auto isEmpty = [&vectorList]() {return 0 == vectorList.size();};

   while (!isEmpty())
   {
      if (vectorList.size() < SIZE_OF_BLOCK)
      {
         return {NO_MUCH_ARGUMENTS, 0};
      }

      if ("/" == vectorList[OPERATOR_PLACE] && 0 == stod(vectorList[SECOND_ARGUMENT]))
      {
        return {DIVIATION_ON_ZERO, 0};
      }

      iterationResult = calculateOperation(stod(vectorList[FIRST_ARGUMENT]),
                                           stod(vectorList[SECOND_ARGUMENT]),
                                           vectorList[OPERATOR_PLACE]);

      vectorList.erase(vectorList.begin(), vectorList.begin() + SIZE_OF_BLOCK);

      if (!isEmpty())
      {
         vectorList.insert(vectorList.begin(), std::to_string(iterationResult));
      }
      iterationResult;
   }
   return {SUCCESS, iterationResult };
}


double calculateOperation(const double first, const double second, const std::string& element)
{
   double result = 0;

   if ("+" == element)
   {
      result = first + second;
   }
   else if ("-" == element)
   {
      result = first - second;
   }
   else if ("/" == element)
   {
      result = first / second;
   }
   else if ("*" == element)
   {
      result = first * second;
   }
   else
   {
   }

   return result;
}

std::vector<std::string> parsingStringToVector(const std::string& str_)
{
   std::vector<std::string> stringVec;
   size_t pos = 0;
   std::string token("");
   const std::string delimiter(" ");
   std::string str(str_);

   while (std::string::npos != (pos = str.find(delimiter)))
   {
      token = str.substr(0, pos);
      stringVec.push_back(token);
      str.erase(0, pos + delimiter.length());
   }

   stringVec.push_back(str);
   return stringVec;
}
