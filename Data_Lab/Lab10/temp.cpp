#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
        data = -1;
        left = NULL;
        right = NULL;
    }
};
class BinaryTreeNode
{
public:
    Node *Root;
    queue<int> mQ;
    BinaryTreeNode() { Root = NULL; }
    void insertNode(int val)
    {
        if (Root == NULL)
        {
            Root = new Node;
            Root->data = val;
            // mQ.push(val);
            return;
        }

        Node *temp = Root;
        while (temp->left != NULL && temp->right!=NULL)
        {
            if (temp->left->left == NULL || temp->left->right == NULL)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (temp->left == NULL)
        {
            temp->left = new Node;
            temp->left->data = val;
            return;
        }
        if (temp->right == NULL)
        {
            temp->right = new Node;
            temp->right->data = val;
            return;
        }
        
    }
    void inorderTraversal(Node *temp)
    {
        if (temp != NULL)
        {
            inorderTraversal(temp->left);
            cout << temp->data << " ";
            inorderTraversal(temp->right);
        }
    }
};
int main()
{
    BinaryTreeNode tree;

    // Insert nodes into the binary tree
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);

    tree.inorderTraversal(tree.Root);
    return 0;
}