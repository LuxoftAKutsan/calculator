#include <gtest/gtest.h>
#include "../calculator/CCalculatorHelper.hpp"


TEST(CalculatorHelperTest, CalculetePlusTestCase)
{
    EXPECT_DOUBLE_EQ(5, calculate("2 3 +").result);
}

TEST(CalculatorHelperTest, CalculeteMinusTestCase)
{
    EXPECT_DOUBLE_EQ(4, calculate("6 2 -").result);
}

TEST(CalculatorHelperTest, CalculeteDivideTestCase)
{
    EXPECT_DOUBLE_EQ(4, calculate("8 2 /").result);
}

TEST(CalculatorHelperTest, CalculeteMultipleTestCase)
{
    EXPECT_DOUBLE_EQ(6, calculate("2 3 *").result);
}

TEST(CalculatorHelperTest, CalculeteDivideByZeroTestCase)
{
    EXPECT_EQ(false, calculate("2 0 /").isValid) << "Divisio on null";
}

TEST(CalculatorHelperTest, CalculeteLongNotationTestCase)
{
    EXPECT_DOUBLE_EQ(10, calculate("2 3 + 5 +").result) << "Wrong +";
    EXPECT_DOUBLE_EQ(8, calculate("3 2 * 2 +").result) << "Wrong -";
    EXPECT_DOUBLE_EQ(4, calculate("4 2 / 2 +").result) << "Wrong /";
    EXPECT_DOUBLE_EQ(7, calculate("2 3 * 1 +").result) << "Wrong *";
}

TEST(CalculatorHelperTest, CalculeteOperationWithDoubleTestCase)
{
    EXPECT_DOUBLE_EQ(3.4, calculate("2.2 1.2 +").result);
}

TEST(CalculatorHelperTest, SplitTestCase)
{
    EXPECT_EQ(3, split("2 + 3", ' ').size()) << "Wrong spliting";
}

TEST(CalculatorHelperTest, CalculeteWrongOrderTestCase)
{
    EXPECT_DOUBLE_EQ(2, calculate("2 -").result);
}

TEST(CalculatorHelperTest, CalculeteWrongArgumentsTestCase)
{
    EXPECT_EQ(false, calculate("2 x ").isValid);
}

TEST(CalculatorHelperTest, CalculeteEmptyStringTestCase)
{
    EXPECT_DOUBLE_EQ(false, calculate("").isValid);
}

TEST(CalculatorHelperTest, CalculeteWrongOperationTestCase)
{
    EXPECT_DOUBLE_EQ(false, calculate("2.2 1.2 %").isValid);
}

// simple wrong operation
// Empty string
// wrong order
// randon string
