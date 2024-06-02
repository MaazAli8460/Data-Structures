#include <iostream>
#include <string>

using namespace std;

class AVLNode
{
public:
    int data;
    AVLNode *left;
    AVLNode *right;
    AVLNode *nextDuplicate; // Linked list for duplicates
    int height;
    int duplicateCount; // Counter for duplicate values
    AVLNode()
    {
        left = NULL;
        right = NULL;
        nextDuplicate = NULL;
        height = 0;
        duplicateCount = 0;
    }
    AVLNode(int value) : data(value), left(nullptr), right(nullptr), nextDuplicate(nullptr), height(0),
                         duplicateCount(0) {}
};
class AVLTree
{
public:
    AVLNode *root;
    AVLTree()
    {
        root = NULL;
    }
    int getHeight(AVLNode *t)
    {
        if (t == NULL)
        {
            return -1;
            /* code */
        }
        return t->height;
    }
    int balance(AVLNode *t)
    {
        if (t == NULL)
        {
            return 0;
        }
    }
    int max(AVLNode *a, AVLNode *b)
    {
        int ahight, bheight;
        if (a == NULL)
        {
            ahight = -1;
        }
        if (b == NULL)
        {
            bheight = -1;
        }

        return (ahight > bheight) ? ahight : bheight;
    }
    void insert(int d)
    {
        AVLNode *temp = root;
        root = inserthelper(temp, d);
    }
    AVLNode *rotateleft(AVLNode *temp)
    {
        AVLNode *x = temp->right;
        AVLNode *y = x->left;
        temp->right = y;
        x->left = temp;
        temp->height = max(temp->left, temp->right) + 1;
        x->height = max(x->left, x->right) + 1;
        return x;
    }
    AVLNode *rotateright(AVLNode *temp)
    {
        AVLNode *x = temp->left;
        AVLNode *y = x->right;
        temp->left = y;
        x->right = temp;
        temp->height = max(temp->left, temp->right) + 1;
        x->height = max(x->left, x->right) + 1;
        return x;
    }
    AVLNode *insertDuplicate(AVLNode *node, int data)
    {
        AVLNode *temp = node->nextDuplicate;
        if (temp == NULL)
        {
            temp = new AVLNode;
            temp->data = data;
            temp->duplicateCount++;
            // return temp;
            // node->nextDuplicate = temp;
        }
        else
        {
            while (temp != NULL)
            {
                temp = temp->nextDuplicate;
            }
            temp = new AVLNode;
            temp->data = data;
            temp->duplicateCount++;
        }
        return node->nextDuplicate;
    }
    AVLNode *inserthelper(AVLNode *node, int d)
    {
        if (node == NULL)
        {
            AVLNode *temp = new AVLNode;
            temp->data = d;
            return temp;
        }
        else if (d < node->data)
        {
            node->left = inserthelper(node->left, d);
            if (getHeight(node->left) - getHeight(node->right) == 2)
            {
                if (node->left->data > d)
                {
                    node = rotateleft(node);
                }
                node = rotateright(node);
            }
        }
        else if (d > node->data)
        {
            node->right = inserthelper(node->right, d);
            if (getHeight(node->right) - getHeight(node->left) == 2)
            {
                if (node->right->data < d)
                {
                    node = rotateright(node);
                }
                node = rotateleft(node);
            }
        }
        else if (node->data == d)
        {
            node->duplicateCount++;
            node->nextDuplicate = inserthelper(node->nextDuplicate, d);
        }

        node->height = max(node->left, node->right) + 1;
        return node;
    }
    void display()
    {
        cout << "In-order traversal: ";
        AVLNode *temp = root;
        inorder(temp);
        cout << "\n";
    }
    void checkDuplicate(AVLNode *temp)
    {
        if (temp->nextDuplicate == NULL)
        {
            return;
        }
        checkDuplicate(temp->nextDuplicate);
        cout << temp->duplicateCount << " ";
        // n
    }
    void inorder(AVLNode *temp)
    {
        if (temp != NULL)
        {
            inorder(temp->left);
            cout << temp->data << " ";
            checkDuplicate(temp);
            inorder(temp->right);
        }
    }
};
int main()
{
    AVLTree avlTree;
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
    avlTree.display();
    return 0;
}