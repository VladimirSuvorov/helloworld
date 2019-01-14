//#define BOOST_TEST_MODULE test_version

#include <gtest/gtest.h>
#include "lib.h"

TEST(VersionTest, VersionIsGreaterThan0) {
   ASSERT_GT(version(), 0)<<"version is greater than 0";
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
//#include <boost/test/unit_test.hpp>

//BOOST_AUTO_TEST_SUITE(test_version)

//BOOST_AUTO_TEST_CASE(test_valid_version)
//{
//    BOOST_CHECK(version() > 0);
//}

//}
