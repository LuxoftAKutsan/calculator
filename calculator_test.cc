#include <gtest/gtest.h>
#include <limits>
#include "calculator.hpp"

TEST(Calculator_Polish, Plus)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "8 2 +";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 10.);
}

TEST(Calculator_Polish, Minus)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "8 2 -";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 6.);
}

TEST(Calculator_Polish, Multiply)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "8 2 *";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 16.);
}

TEST(Calculator_Polish, Divide)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "8 2 /";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 4.);
}

TEST(Calculator_Polish, NegativePlus)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "-8 2 +";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, -6.);
}

TEST(Calculator_Polish, NegativeMinus)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "-8 2 -";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, -10.);
}

TEST(Calculator_Polish, NegativeMultiply)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "-8 2 *";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, -16.);
}

TEST(Calculator_Polish, NegativeDivide)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "-8 2 /";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, -4.);
}

TEST(Calculator_Polish, PlusToZero)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "0 0 +";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 0.);
}

TEST(Calculator_Polish, MinusToZero)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "5 5 -";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 0.);
}

TEST(Calculator_Polish, MultiplyToZero)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "5 0 *";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 0.);
}

TEST(Calculator_Polish, DivideToZero)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "0 2 /";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 0.);
}

TEST(Calculator_Polish, IntDivideToDouble)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "9 2 /";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 4.5);
}

TEST(Calculator_Polish, DoublePlus)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "8.17 2.01 +";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 10.18);
}

TEST(Calculator_Polish, DoubleMinus)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "8.17 2.01 -";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 6.16);
}

TEST(Calculator_Polish, DoubleMultiply)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "8.17 2.01 *";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 16.4217);
}

TEST(Calculator_Polish, DoubleDivide)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "8.17 2.01 /";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 4.064676616915423);
}

TEST(Calculator_Polish, DivideByZero)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "8 0 /";
    ASSERT_THROW(worker.calculate(expression), std::overflow_error);
}

TEST(Calculator_Polish, MultipleOperands)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "5 3 + 7 * 2 /";
    auto ret = worker.calculate(expression);
    EXPECT_DOUBLE_EQ(ret, 28.);
}

TEST(Calculator_Polish, WrongInput)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "qwerty";
    ASSERT_THROW(worker.calculate(expression), std::invalid_argument);
}

TEST(Calculator_Polish, EmptyInput)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "";
    ASSERT_THROW(worker.calculate(expression), std::invalid_argument);
}

TEST(Calculator_Polish, SimpleWrongOperation)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "5 3 %";
    ASSERT_THROW(worker.calculate(expression), std::invalid_argument);
}

TEST(Calculator_Polish, WrongOrder)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "+ 2 2";
    ASSERT_THROW(worker.calculate(expression), std::invalid_argument);
}

TEST(Calculator_Polish, WrongOperands)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "2 2 + 2 2";
    ASSERT_THROW(worker.calculate(expression), std::invalid_argument);
}

TEST(Calculator_Polish, WrongSymbols)
{
    CalculatorPolish::Calculator worker;
    std::string expression = "2q 2w +e";
    ASSERT_THROW(worker.calculate(expression), std::invalid_argument);
}

TEST(Calculator_Polish, NumericLimitsPlus)
{
    CalculatorPolish::Calculator worker;
    std::numeric_limits<double> limit;
    std::string expression = std::to_string(limit.max()) + " " + std::to_string(limit.max()) + " +";
    ASSERT_THROW(worker.calculate(expression), std::overflow_error);
}

TEST(Calculator_Polish, NumericLimitsMinus)
{
    CalculatorPolish::Calculator worker;
    std::numeric_limits<double> limit;
    std::string expression = std::to_string(limit.min()) + " " + std::to_string(limit.min()) + " -";
    ASSERT_THROW(worker.calculate(expression), std::overflow_error);
}

TEST(Calculator_Polish, NumericLimitsMultiply)
{
    CalculatorPolish::Calculator worker;
    std::numeric_limits<double> limit;
    std::string expression = std::to_string(limit.max()) + " " + std::to_string(limit.max()) + " *";
    ASSERT_THROW(worker.calculate(expression), std::overflow_error);
}

/*TEST(Calculator_Polish, NumericLimitsDivide)
{
    CalculatorPolish::Calculator worker;
    std::numeric_limits<double> limit;
    std::string expression = std::to_string(limit.epsilon()) + " " + std::to_string(limit.max()) + " /";
    printf("%s", expression.c_str());
    ASSERT_THROW(worker.calculate(expression), std::overflow_error);
}*/
