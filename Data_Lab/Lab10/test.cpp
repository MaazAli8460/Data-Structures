#include "pch.h"
#include "Header1.h"
#include "Header.h"
  



//----------------Array Based Test Case----------------------
TEST(BinaryTreeTest, InOrderTraversal) {
    BinaryTree tree;

    // Insert elements into the binary tree
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    // Check if the in-order traversal is correct
    testing::internal::CaptureStdout();
    tree.displayInorder();
    std::string output = testing::internal::GetCapturedStdout();

    // The expected output based on in-order traversal
    std::string expected_output = "1 2 3 4 5 6 7 ";

    ASSERT_EQ(output, expected_output);
}


TEST(BinaryTreeTest, InsertionAndTraversal) {
    BinaryTreeNode tree;

    // Insert nodes into the binary tree
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);

    // Perform an in-order traversal and check the result
    testing::internal::CaptureStdout();
    tree.inorderTraversal();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "4 2 5 1 3 \n");
}


Node* newnode(int data)
{
    Node* NodeT = new Node();
    NodeT->data = data;
    NodeT->left = NULL;
    NodeT->right = NULL;

    return (NodeT);
}


TEST(PathSumTest, InvalidPathSum) {
    Node* root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);
    hasPathSum(root, 12);
    EXPECT_FALSE(hasPathSum(root, 12)); // Expecting no valid path with sum 12
    EXPECT_FALSE(hasPathSum(root, 20)); // Expecting no valid path with sum 20
}
TEST(PathSumTest, ValidPathSum) {
    Node* root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);
    hasPathSum(root, 21);
    EXPECT_TRUE(hasPathSum(root, 21)); // Expecting a valid path with sum 23
    EXPECT_TRUE(hasPathSum(root, 14)); // Expecting a valid path with sum 14
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}