#include <gtest/gtest.h>
#include <pthread.h>

#include "core/test_add.h"
#include "calculator/test_calculator.h"

int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
