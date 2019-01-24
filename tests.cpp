#include <gtest/gtest.h>
#include "calc.hpp"

TEST(MyTest, SimplePlus) {
   std::pair<Calc::EReturnCodes, double> result = Calc("2 2 +").calculate();
   EXPECT_DOUBLE_EQ(result.second, 4);
}

TEST(MyTest, SimpleMinus) {
   std::pair<Calc::EReturnCodes, double> result = Calc("5 3 -").calculate();
   EXPECT_DOUBLE_EQ(result.second, 2);
}

TEST(MyTest, SimpleMultiply) {
   std::pair<Calc::EReturnCodes, double> result = Calc("2 3 *").calculate();
   EXPECT_DOUBLE_EQ(result.second, 6);
}

TEST(MyTest, SimpleDivide) {
   std::pair<Calc::EReturnCodes, double> result = Calc("8 2 /").calculate();
   EXPECT_DOUBLE_EQ(result.second, 4);
}

TEST(MyTest, LongNotation) {
   std::pair<Calc::EReturnCodes, double> result = Calc("15 7 1 1 + - / 3 * 2 1 1 + + -").calculate();
   EXPECT_DOUBLE_EQ(result.second, 5);
}

TEST(MyTest, SimpleDivideByZero) {
   std::pair<Calc::EReturnCodes, double> result = Calc("8 0 /").calculate();
   EXPECT_TRUE(Calc::EReturnCodes::DIVISION_BY_ZERO == result.first);
}

TEST(MyTest, WrongArgument) {
   std::pair<Calc::EReturnCodes, double> result = Calc("8 s /").calculate();
   EXPECT_TRUE(Calc::EReturnCodes::WRONG_ARGUMENT == result.first);
}

TEST(MyTest, WrongOperation) {
   std::pair<Calc::EReturnCodes, double> result = Calc("8 7 $").calculate();
   EXPECT_TRUE(Calc::EReturnCodes::WRONG_OPERATION == result.first);
}

TEST(MyTest, WrongOrder) {
   std::pair<Calc::EReturnCodes, double> result = Calc("* 8 7").calculate();
   std::cout << static_cast<int>(result.first);
   EXPECT_TRUE(Calc::EReturnCodes::WRONG_ORDER == result.first);
}

TEST(MyTest, EmptyString) {
   std::pair<Calc::EReturnCodes, double> result = Calc("").calculate();
   EXPECT_TRUE(Calc::EReturnCodes::EMPTY_STRING == result.first);
}
