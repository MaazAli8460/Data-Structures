#include "pch.h"
#include "Header.h"
#include"gtest/gtest.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
// Test AVL tree insertion
TEST(AVLTreeTest, Insertion)
{
    AVLTree avlTree;
    
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);
    avlTree.insert(25);

    // Display the AVL tree after insertion
    testing::internal::CaptureStdout();
    avlTree.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "In-order traversal: 10 20 25 30 40 50 \n");
}

TEST(AVLTreeTest1, Insertion1)
{
    AVLTree avlTree;

    // Insert elements
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);
    avlTree.insert(25);
    avlTree.insert(25);
    avlTree.insert(25);
    avlTree.insert(25);
    avlTree.insert(25);
    // Display the AVL tree after insertion
    testing::internal::CaptureStdout();
    avlTree.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "In-order traversal: 10 20 25 1 2 3 4 30 40 50 \n");
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// Test AVL tree deletion



// Helper function to check if a tree is sorted



