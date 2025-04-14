#include <gtest/gtest.h>
#include <cstdint>

extern "C" int64_t max3(int64_t a, int64_t b, int64_t c);

TEST(Max3Test, AllZeros) {
    EXPECT_EQ(max3(0, 0, 0), 0);
}

TEST(Max3Test, AllPositiveDifferent) {
    EXPECT_EQ(max3(1, 2, 3), 3);
    EXPECT_EQ(max3(10, 5, 7), 10);
    EXPECT_EQ(max3(5, 15, 10), 15);
}

TEST(Max3Test, AllNegativeDifferent) {
    EXPECT_EQ(max3(-1, -2, -3), -1);
    EXPECT_EQ(max3(-10, -5, -7), -5);
}

TEST(Max3Test, MixedPositiveAndNegative) {
    EXPECT_EQ(max3(-1, 0, 1), 1);
    EXPECT_EQ(max3(-10, 20, -30), 20);
}

TEST(Max3Test, TwoMaxEqual) {
    EXPECT_EQ(max3(5, 5, 3), 5);
    EXPECT_EQ(max3(7, 3, 7), 7);
    EXPECT_EQ(max3(2, 2, 2), 2);
}

TEST(Max3Test, EdgeCases) {
    EXPECT_EQ(max3(INT64_MIN, 0, INT64_MAX), INT64_MAX);
    EXPECT_EQ(max3(INT64_MIN, INT64_MIN, INT64_MIN), INT64_MIN);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}