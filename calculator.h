#ifndef CALCULATOR_H
#define CALCULATOR_H

#include<string>
#include<vector>

enum EResult {
   SUCCESS,
   DIVIATION_ON_ZERO,
   EMPTY_STRING,
   WRONG_ORDER,
   INVALID_DIGIT,
   INVALID_SIGN,
   NO_MUCH_ARGUMENTS,
   OUT_OF_LIMIT
};

enum ETypeofOperand {
   DIGIT,
   SIGN,
   PLUS,
   MINUS,
   DIV,
   MUL,
   INVALID
};

constexpr int SIZE_OF_BLOCK = 3;
constexpr int FIRST_ARGUMENT = 0;
constexpr int SECOND_ARGUMENT = 1;
constexpr int OPERATOR_PLACE = 2;
const std::string VALID_DIGITS = "1234567890.-";
const std::string validSigns = "+-*/";

//public
std::pair <EResult, double> calculate(const std::string&);
//privat
std::pair <EResult, double> calculateOperation(const double first, const double, const std::string&);
std::vector<std::string> parsingStringToVector(const std::string&);
EResult analyzeStringForMistakes(const std::vector<std::string>&);
std::pair <EResult, double> makeAllCalculationCycles(std::vector<std::string>&);



#endif //CALCULATOR_H
