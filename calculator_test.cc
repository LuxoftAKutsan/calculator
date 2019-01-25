#include <gtest/gtest.h>
#include "calculator.h"
#include <vector>
#include <string>

#include "calcExceptions.h"

TEST(CalculatorTest, TestOperatorPlus)
{
    auto result = calculate("2 7 +");
    EXPECT_DOUBLE_EQ(9.0, result);
}

TEST(CalculatorTest, TestOperatorMinus)
{
    auto result = calculate("6 2 -");
    EXPECT_DOUBLE_EQ(4.0, result);
}

TEST(CalculatorTest, TestOperatorMultiply)
{
    auto result = calculate("6 3 *");
    EXPECT_DOUBLE_EQ(18.0, result);
}

TEST(CalculatorTest, TestOperatorDivide)
{
    auto result = calculate("11 2 /");
    EXPECT_DOUBLE_EQ(5.5, result);
}

TEST(CalculatorTest, TestSimpleExpression)
{
    auto result = calculate("5 3 + 7 * 2 /");
    EXPECT_DOUBLE_EQ(28.0, result);
}

TEST(CalculatorTest, TestExpressionWithDoubles)
{
    auto result = calculate("53.1 3.0 + 7.454 * 2.11 /");
    auto compareVal = ((53.1 + 3.0)*7.454)/2.11;
    EXPECT_DOUBLE_EQ(compareVal, result);
}

TEST(CalculatorTest, TestNegativeResult)
{
    auto result = calculate("-2.0 1 +");
    EXPECT_DOUBLE_EQ(-1.0, result);
}

TEST(CalculatorTest, TestDivisionByZero)
{
    EXPECT_THROW(calculate("1 0 /"), DivisionByZeroException);
}

TEST(CalculatorTest, TestStringSplitString)
{
    std::string input = "1 4 * 7.3 + 11.11 /";
    std::vector<std::string> compareVector{"1", "4", "*", "7.3", "+", "11.11", "/"};
    char divider = ' ';

    EXPECT_EQ(compareVector, splitString(input, divider));

}

TEST(CalculatorTest, TestStringOperatorSplitString)
{
    std::string input = "+ - * /";
    std::vector<std::string> compareVector{"+", "-", "*", "/"};
    char divider = ' ';

    EXPECT_EQ(compareVector, splitString(input, divider));

}

TEST(CalculatorTest, TestEmptyInputValue)
{
    EXPECT_THROW(calculate(""), eCalculatorError);
}

TEST(CalculatorTest, TestNoOperands)
{
    EXPECT_THROW(calculate("+ - * /"), eCalculatorError);
}

TEST(CalculatorTest, TestTooMuchOperands)
{
    EXPECT_THROW(calculate("1 4 6 8 -"), eCalculatorError);
}

TEST(CalculatorTest, TestWrongOrder)
{
    EXPECT_THROW(calculate("+ 2 2"), eCalculatorError);
}

/*TEST(CalculatorTest, TestWrongInput)
{
    EXPECT_THROW(calculate("fdfdfd"), eCalculatorError);
}*/
