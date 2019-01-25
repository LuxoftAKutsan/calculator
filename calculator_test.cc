#include<gtest/gtest.h>
#include"calculator.hpp"

/*
Simple Plus
Simple Minus
Simple Multiply
Simple Divide
Long Notation (+ * /)
Simple Divide by zero
Simple Wrong operation
Simple Wrong argument
Empty String
Wrong order : + 2 2
Wrong operands : 2 2 + 2 2
Random String
Wrong symbols in input
operations with of doulbes
numeric limits with plus
numeric limits with munus
numeric limits with muliply
numeric limits with devide
*/

TEST( CalculatorTest, TestOperationPlus)
{
    auto result = calculate("3.5 2.0 +");
    EXPECT_DOUBLE_EQ( 5.5, result );
}

TEST( CalculatorTest, TestOperationMinus)
{
    auto result = calculate("7.0 6.0 -");
    EXPECT_DOUBLE_EQ( 1.0, result );
}

TEST( CalculatorTest, TestOperationDivide)
{
    auto result = calculate("8.0 2.0 /");
    EXPECT_DOUBLE_EQ( 4.0, result );
}

TEST( CalculatorTest, TestOperationMultiply)
{
    auto result = calculate("11.3 2.0 *");
    EXPECT_DOUBLE_EQ( 22.6, result );
}

TEST( CalculatorTest, TestMultipleOperations)
{
    auto result = calculate("10.0 2.0 * 7.0 + 5.0 -");
    EXPECT_DOUBLE_EQ( 22.0, result );
}

TEST( CalculatorTest, TestDivideByZero)
{
    auto result = calculate("10.0 0.0 /");
    EXPECT_DOUBLE_EQ( ERROR_CODE, result );
}

TEST( CalculatorTest, TestUndefinedOperation)
{
    auto result = calculate("10.0 7.0 ?");
    EXPECT_DOUBLE_EQ( ERROR_CODE, result );
}

TEST( CalculatorTest, TestWrongArgument)
{
    auto result = calculate("10.0 a +");
    EXPECT_DOUBLE_EQ( ERROR_CODE, result );
}

TEST( CalculatorTest, TestEmptyString)
{
    auto result = calculate("");
    EXPECT_DOUBLE_EQ( ERROR_CODE, result );
}

TEST( CalculatorTest, TestRandomString)
{
    auto result = calculate("jfvbsjkehq23 ergweurgh3 3gsi h3 38hegg n");
    EXPECT_DOUBLE_EQ( ERROR_CODE, result );
}

TEST( CalculatorTest, TestExtraSimbolInOperation)
{
    auto result = calculate("-248 2 /gd");
    EXPECT_DOUBLE_EQ( -124, result );
}

TEST( CalculatorTest, TestOperationWithNegativeNumbers)
{
    auto result = calculate("-3.5 -2.0 +");
    EXPECT_DOUBLE_EQ( -5.5, result );
}

TEST( CalculatorTest, TestTwoArguments)
{
    auto result = calculate("-3.5 -2.0");
    EXPECT_DOUBLE_EQ( ERROR_CODE, result );
}

TEST( CalculatorTest, TestOperationWithNumericLimitsPlus)
{
    auto result = calculate( std::to_string( DBL_MAX ) + " 547654.0 +" );
    EXPECT_DOUBLE_EQ( DBL_MAX, result );
}
TEST( CalculatorTest, TestOperationWithNumericLimitsMinusNegative)
{
    auto result = calculate("-2.0 " + std::to_string( DBL_MAX ) +  " -" );
    EXPECT_DOUBLE_EQ( -DBL_MAX, result );
}
TEST( CalculatorTest, TestOperationWithNumericLimitsMultiply)
{
    auto result = calculate("2.0 " + std::to_string( DBL_MAX ) +  " *" );
    EXPECT_DOUBLE_EQ( DBL_MAX, result );
}
TEST( CalculatorTest, TestOperationWithNumericLimitsDivide)
{
    auto result = calculate( std::to_string( DBL_MAX ) + " 0.1 /" );
    EXPECT_DOUBLE_EQ( DBL_MAX, result );
}
TEST( CalculatorTest, TestOperationWithNumericLimitsMultiplyNegatie)
{
    auto result = calculate("-1.0 " + std::to_string( DBL_MAX ) +  " *" );
    EXPECT_DOUBLE_EQ( -DBL_MAX, result );
}
TEST( CalculatorTest, TestOperationWithNumericLimitsPlusNegatie)
{
    auto result = calculate("0.0 " + std::to_string( -DBL_MAX ) +  " +" );
    EXPECT_DOUBLE_EQ( -DBL_MAX, result );
}
TEST( CalculatorTest, TestOperationWithNumericLimitsdivide2)
{
    auto result = calculate( std::to_string( DBL_MAX ) + " 2.0" +  " /" );
    EXPECT_DOUBLE_EQ( DBL_MAX/2, result );
}
