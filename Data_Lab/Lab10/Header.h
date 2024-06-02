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
        while (temp->left != NULL && temp->right != NULL)
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
    void inorderTraversal()
    {

        inorderTraversal1(Root);
        cout << "\n";
    }
    void inorderTraversal1(Node *temp)
    {
        if (temp != NULL)
        {
            inorderTraversal1(temp->left);
            cout << temp->data << " ";
            inorderTraversal1(temp->right);
        }
    }
    void Display()
    {
        inorderTraversal1(Root);
        cout << "\n";
    }
};
bool hasPathSum(Node *root, int val)
{
    if (root == NULL)
    {
        return false;
    }
    val -= root->data;
    if (root->left == NULL && root->right == NULL)
    {
        if (val==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool left = hasPathSum(root->left, val);
    bool right = hasPathSum(root->right, val);
    if(left==true || right==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

