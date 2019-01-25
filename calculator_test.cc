#include<gtest/gtest.h>
#include"calculator.h"

TEST(MyFirstTest, MyFirstTestCase)
{
    int x = 1;
    int y = 1;

    EXPECT_EQ(x, y);
    EXPECT_TRUE(x == y);
}

TEST(CalculatorTest, TestOperatorPlus)
{
    std::pair <EResult, double> result = calculate("2 2 +");

    EXPECT_DOUBLE_EQ(4, result.second);
}

TEST(CalculatorTest, TestOperatorMinus)
{
    auto result = calculate("2 2 -");

    EXPECT_DOUBLE_EQ(0, result.second);
}

TEST(CalculatorTest, TestOperatorPlus2)
{
    auto result = calculate("-2 2 +");

    EXPECT_DOUBLE_EQ(0, result.second);
}

TEST(CalculatorTest, TestOperatorMul)
{
    auto result = calculate("2 2 *");

    EXPECT_EQ(4, result.second);
}


TEST(CalculatorTest, TestOperatorDiv)
{
    auto result = calculate("2 2 /");

    EXPECT_EQ(1, result.second);
}

TEST(CalculatorTest, TestOperatorNotation)
{
    auto result = calculate("5 3 + 7 * 2 /");

    EXPECT_EQ(28, result.second);
}


TEST(CalculatorTest, TestOperatorDivNyZero)
{
    auto result = calculate("4 0 /");

    EXPECT_EQ(DIVIATION_ON_ZERO, result.first);
}

TEST(CalculatorTest, TestWrongOperator)
{
    auto result = calculate("4 0 &");

    EXPECT_EQ(INVALID_SIGN, result.first);
}

TEST(CalculatorTest, TestWrongArgument)
{
    auto result = calculate("4 - +");

    EXPECT_EQ(INVALID_DIGIT, result.first);
}

TEST(CalculatorTest, TestEmptyString)
{
    auto result = calculate("");

    EXPECT_EQ(EMPTY_STRING, result.first);
}

TEST(CalculatorTest, TestWrongOrder)
{
    auto result = calculate("2 & 2");

    EXPECT_EQ(INVALID_DIGIT, result.first);
}

TEST(CalculatorTest, TestWrongOperand)
{
    auto result = calculate("2 2 + 2 2");

    EXPECT_EQ(INVALID_SIGN, result.first);
}

TEST(CalculatorTest, TestRandomString)
{
    auto result = calculate("sdsasd");

    EXPECT_EQ(NO_MUCH_ARGUMENTS, result.first);
}

TEST(CalculatorTest, TestWrongSymbol)
{
    auto result = calculate("2 C +");

    EXPECT_EQ(INVALID_DIGIT, result.first);
}

TEST(CalculatorTest, TestWrongBigNools)
{
    auto result = calculate("2 2.0000000000000000000000000001 +");

    EXPECT_EQ(INVALID_SIGN, result.first);
}

TEST(CalculatorTest, TestLimitMinus)
{
    auto result = calculate("-2147483647 -2147483647 -");

    EXPECT_EQ(OUT_OF_LIMIT, result.first);
}

TEST(CalculatorTest, TestLimitPlux)
{
    auto result = calculate("2147483647 2147483647 +");

    EXPECT_EQ(OUT_OF_LIMIT, result.first);
}

TEST(CalculatorTest, TestLimitMul)
{
    auto result = calculate("2147483647 2147483647 *");

    EXPECT_EQ(OUT_OF_LIMIT, result.first);
}



