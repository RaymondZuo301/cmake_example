#ifndef TEST_ADD_H
#define TEST_ADD_H

#include <gtest/gtest.h>
#include <ray/math/core/add.h>

TEST(test_add, HandlerTrueReturn)
{
    ray::math::Add add;
    ASSERT_DOUBLE_EQ(add(1.1,2.2), 3.3);
}

#endif // TEST_ADD_H
