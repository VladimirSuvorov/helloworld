
#include <gtest/gtest.h>
#include "lib.h"

TEST(VersionTest, VersionIsGreaterThan0) {//version()
   ASSERT_GT(0, 0)<<"version is greater than 0";
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
