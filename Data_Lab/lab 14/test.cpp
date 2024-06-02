#include "pch.h"
#include <gtest/gtest.h>
#include "Header.h"


TEST(HashMapTest, InsertAndSearch) {
    HashMap mp;

    // Insert key-value pairs
    mp.insert(1, 101);
    mp.insert(2, 202);
    mp.insert(3, 303);
    mp.insert(23, 103);

    // Search for inserted values
    EXPECT_EQ(mp.search(1), 101);
    EXPECT_EQ(mp.search(2), 202);
    EXPECT_EQ(mp.search(3), 303);
    EXPECT_EQ(mp.search(23), 103);
}

TEST(HashMapTest, RemoveAndSearch) {
    HashMap mp;

    // Insert key-value pairs
    mp.insert(1, 101);
    mp.insert(2, 202);
    mp.insert(3, 303);

    // Remove a key and search for it
    mp.remove(2);
    EXPECT_EQ(mp.search(2), -1);  // Key 2 should not be found after removal
    EXPECT_EQ(mp.search(1), 101);  // Other keys should still be present
    EXPECT_EQ(mp.search(3), 303);
}

TEST(HashMapTest, SearchNonExistentKey) {
    HashMap mp;

    // Searching for a key that has not been inserted
    EXPECT_EQ(mp.search(1), -1);
}



// Test case for hasLoop function with a linked list that has a loop
TEST(HashMapTest, HasLoopWithLoop) {
    Node* head = new Node(1, 10);
    head->next = new Node(2, 20);
    head->next->next = new Node(3, 30);
    head->next->next->next = head->next;

    ASSERT_TRUE(hasLoop(head));

    // Clean up
    delete head->next->next;
    delete head->next;
    delete head;
}

// Test case for hasLoop function with a linked list that does not have a loop
TEST(HashMapTest, HasLoopWithoutLoop) {
    Node* head = new Node(1, 10);
    head->next = new Node(2, 20);
    head->next->next = new Node(3, 30);
    ASSERT_FALSE(hasLoop(head));

    // Clean up
    delete head->next->next;
    delete head->next;
    delete head;
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}