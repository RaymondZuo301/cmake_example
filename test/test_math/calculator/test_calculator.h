#ifndef TEST_PROPERTY_H
#define TEST_PROPERTY_H

#include <gtest/gtest.h>
#include <ray/math/calculator/calculator.h>

TEST(test_calculator, HandlerTrueReturn)
{
    ray::math::Calculator cal;
    ASSERT_DOUBLE_EQ(cal(1.1, 2.2, ray::math::ADD), 3.3);
}

#endif // TEST_PROPERTY_H
