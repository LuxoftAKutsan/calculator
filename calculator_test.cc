#include<gtest/gtest.h>
#include"calculator.h"

TEST(CalculatorTest, TestOperatorPlus)
{
    Calculator c;

    Result<double> result = c.calculate("3 2 +");

    EXPECT_EQ(true, result);
    EXPECT_DOUBLE_EQ(5, *result);
}

TEST(CalculatorTest, TestOperatorMinus)
{
    Calculator c;

    Result<double> result = c.calculate("6 2 -");

    EXPECT_EQ(true, result);
    EXPECT_DOUBLE_EQ(4, *result);
}

TEST(CalculatorTest, TestOperatorMultiply)
{
    Calculator c;

    Result<double> result = c.calculate("6 3 *");

    EXPECT_EQ(true, result);
    EXPECT_DOUBLE_EQ(18, *result);
}

TEST(CalculatorTest, TestOperatorDivide)
{
    Calculator c;

    Result<double> result = c.calculate("10 2 /");

    EXPECT_EQ(true, result);
    EXPECT_DOUBLE_EQ(5, *result);
}

TEST(CalculatorTest, LongNotationTest)
{
    Calculator c;

    Result<double> result = c.calculate("1 7 + 2 - 2 / 3 *");

    EXPECT_EQ(true, result);
    EXPECT_DOUBLE_EQ(9, *result);
}

TEST(CalculatorTest, DivideByZeroTest)
{
    Calculator c;

    Result<double> result = c.calculate("1 0 /");

    EXPECT_EQ(false, result);
}

TEST(CalculatorTest, EmptyStringTest)
{
    Calculator c;

    Result<double> result = c.calculate("");

    EXPECT_EQ(false, result);
}

TEST(CalculatorTest, WrongOrderTest)
{
    Calculator c;

    Result<double> result = c.calculate("+ 2 2");

    EXPECT_EQ(false, result);
}

TEST(CalculatorTest, WrongOperandsTest)
{
    Calculator c;

    Result<double> result = c.calculate("2 2 + 2 2");

    EXPECT_EQ(false, result);
}

TEST(CalculatorTest, DoubleOperationsTest)
{
    Calculator c;

    Result<double> result = c.calculate("2.0 0.5 /");

    EXPECT_EQ(true, result);
    EXPECT_DOUBLE_EQ(4, *result);
}

TEST(CalculatorTest, WrongArgumentTest)
{
    Calculator c;

    Result<double> result = c.calculate("2 a +");

    EXPECT_EQ(false, result);
}

TEST(CalculatorTest, WrongOperationTest)
{
    Calculator c;

    Result<double> result = c.calculate("2 2 :");

    EXPECT_EQ(false, result);
}

TEST(CalculatorTest, RandomString)
{
    Calculator c;

    Result<double> result = c.calculate("asdfghjkl;'");

    EXPECT_EQ(false, result);
}

TEST(CalculatorTest, WrongSymbolsInInput)
{
    Calculator c;

    Result<double> result = c.calculate("2 2 + qwerty");

    EXPECT_EQ(false, result);
}

//Simple Plus
//Simple Minus
//Simple Multiply
//Simple Divide
//Long Notation (+ * /)
//Simple Divide by zero
//Empty String
//Wrong order : + 2 2
//Wrong operands : 2 2 + 2 2
//operations with of doulbes
//Simple Wrong argument
//Simple Wrong operation
//Random String
//Wrong symbosl in input

//numeric limits with plus
//numeric limits with munus
//numeric limits with muliply
//numeric limits with devide
