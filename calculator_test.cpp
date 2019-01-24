#include <gtest/gtest.h>
#include "calculator.hpp"
#include <iostream>

TEST(CalculatorTest, TestOperatorPlus)
{
    auto result = calculateExpression("2 2 +");
    EXPECT_DOUBLE_EQ(4.0, result.value);
    EXPECT_EQ(Error::NoError, result.error);
}

TEST(CalculatorTest, TestOperatorMinus)
{
    auto result = calculateExpression("6 3 -");
    EXPECT_DOUBLE_EQ(3.0, result.value);
    EXPECT_EQ(Error::NoError, result.error);
}

TEST(CalculatorTest, TestOperatorMultiply)
{
    auto result = calculateExpression("6 3 *");
    EXPECT_DOUBLE_EQ(18.0, result.value);
    EXPECT_EQ(Error::NoError, result.error);
}

TEST(CalculatorTest, TestOperatorDivide)
{
    auto result = calculateExpression("10 2 /");
    EXPECT_DOUBLE_EQ(5.0, result.value);
    EXPECT_EQ(Error::NoError, result.error);
}

TEST(CalculatorTest, TestLongNotation)
{
    auto result = calculateExpression("5 3 + 7 * 2 /");
    EXPECT_DOUBLE_EQ(28.0, result.value);
    EXPECT_EQ(Error::NoError, result.error);
}


TEST(CalculatorTest, TestSimpleDivideByZero)
{
    auto result = calculateExpression("1 0 /");
    EXPECT_DOUBLE_EQ(0.0, result.value);
    EXPECT_EQ(Error::DivideByZero, result.error);
}

TEST(CalculatorTest, TestWrongOperation)
{
    auto result = calculateExpression("5 3 a");
    EXPECT_DOUBLE_EQ(0.0, result.value);
    EXPECT_EQ(Error::WrongOperation, result.error);
}


TEST(CalculatorTest, TestWrongArgument)
{
    auto result = calculateExpression("5 a +");
    EXPECT_DOUBLE_EQ(0.0, result.value);
    EXPECT_EQ(Error::WrongOperand, result.error);
}

TEST(CalculatorTest, TestEmptyString)
{
    auto result = calculateExpression("");
    EXPECT_DOUBLE_EQ(0.0, result.value);
    EXPECT_EQ(Error::EmptyString, result.error);
}

TEST(CalculatorTest, TestWrongOrder)
{
    auto result = calculateExpression("+ 2 2");
    EXPECT_DOUBLE_EQ(0.0, result.value);
    EXPECT_EQ(Error::WrongOperand, result.error);
}

TEST(CalculatorTest, TestWrongOperands)
{
    auto result = calculateExpression("2 2 + 2 2");
    EXPECT_DOUBLE_EQ(0.0, result.value);
    EXPECT_EQ(Error::WrongOperation, result.error);
}

TEST(CalculatorTest, TestRandomString)
{
    auto result = calculateExpression("abcde");
    EXPECT_DOUBLE_EQ(0.0, result.value);
    EXPECT_EQ(Error::WrongOperand, result.error);
}

TEST(CalculatorTest, TestWrongSymbolsInput)
{
    auto result = calculateExpression("2 2 - a");
    EXPECT_DOUBLE_EQ(0.0, result.value);
    EXPECT_EQ(Error::WrongOperand, result.error);
}

TEST(CalculatorTest, TestOpearionsWithDoubles)
{
    auto result = calculateExpression("2.0 2.0 +");
    EXPECT_DOUBLE_EQ(4.0, result.value);
    EXPECT_EQ(Error::NoError, result.error);
}

/*
TEST(CalculatorTest, TestNumericLimitsWithPlus)
{
    auto result = calculateExpression("250000000000.0 250000000000.0 +");
    EXPECT_DOUBLE_EQ(0.0, result.value);
    EXPECT_EQ(Error::OperandOverflow, result.error);
}

TEST(CalculatorTest, TestNumericLimitsWithMinus)
{
    auto result = calculateExpression("-250000000000 -250000000000 +");
    EXPECT_DOUBLE_EQ(28.0, result);
}

TEST(CalculatorTest, TestNumericLimitsWithMultiply)
{
    auto result = calculateExpression("250000000000 2 *");
    EXPECT_DOUBLE_EQ(28.0, result);
}

TEST(CalculatorTest, TestNumericLimitsWithDivide)
{
    auto result = calculateExpression("250000000000 0.5 /");
    EXPECT_DOUBLE_EQ(28.0, result);
}
*/









