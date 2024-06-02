#include <gtest/gtest.h>
#include "hash.cpp"
// Include the HashMap and HashEntry classes here...

TEST(HashMapTest, InsertAndSearch)
{
    HashMap hashMap;
    hashMap.Insert(1, 42);
    hashMap.Insert(2, 69);

    EXPECT_EQ(hashMap.Search(1), 42);
    EXPECT_EQ(hashMap.Search(2), 69);
    EXPECT_EQ(hashMap.Search(3), -1); // Key 3 is not inserted, so it should return -1
}

TEST(HashMapTest, InsertWithRandomProbe)
{
    HashMap hashMap;

    // Insert elements with random probing
    hashMap.Insert2(1, 42);
    hashMap.Insert2(2, 69);
    hashMap.Insert2(3, 99);

    // Check that the inserted elements can be found
    EXPECT_EQ(hashMap.Search(1), 42);
    EXPECT_EQ(hashMap.Search(2), 69);
    EXPECT_EQ(hashMap.Search(3), 99);

    // Insert an element with the same key, should update the value
    hashMap.Insert2(1, 55);
    EXPECT_EQ(hashMap.Search(1), 55);

    // Attempting to insert more elements should not trigger an error message
    ::testing::internal::CaptureStderr();
    hashMap.Insert2(4, 77);
    std::string errorMessage = ::testing::internal::GetCapturedStderr();
    EXPECT_EQ(errorMessage, "");  // No error message expected
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
