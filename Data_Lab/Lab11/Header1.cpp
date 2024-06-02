#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T key;
    Node<T> *left;
    Node<T> *right;
    // Node()
    // {
    //     left = NULL;
    //     right = NULL;
    //     key=0;
    // }
    Node(T value)
    {
        key = value;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class BST
{
private:
    Node<T> *root;
    int size;

public:
    BST()
    {
        root = NULL;
        size = 0;
    }

    void insert(T insertItem)
    {
        Node<T> *temp = new Node<T>(insertItem);
        temp->key = insertItem;
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL)
        {
            root = temp;
            size++;
        }
        else
        {
            Node<T> *temp1 = root;
            while (temp1 != NULL)
            {
                if (insertItem < temp1->key)
                {
                    if (temp1->left != NULL)
                    {
                        temp1 = temp1->left;
                    }
                    else
                    {
                        temp1->left = temp;
                        break;
                    }
                }
                else if (insertItem > temp1->key)
                {
                    if (temp1->right != NULL)
                    {
                        temp1 = temp1->right;
                    }
                    else
                    {
                        temp1->right = temp;
                        break;
                    }
                }
                else
                {
                    cout << "\nDuplicate";
                }
            }
        }
    }
    bool search(T serachItem)
    {
        Node<T> *temp1 = root;
        bool fl = false;
        while (temp1 != NULL)
        {
            if (temp1->key == serachItem)
            {
                return true;
            }
            else if (temp1->key > serachItem)
            {

                temp1 = temp1->left;
            }
            else if (temp1->key < serachItem)
            {

                temp1 = temp1->right;
            }
        }
        return fl;
    }
    void inoderTraversal()
    {
        Node<T> *temp1 = root;
        inoderTraversalRecursive(temp1);
        cout << "\n";
    }
    void inoderTraversalRecursive(Node<T> *root1)
    {
        if (root1 != NULL)
        {
            inoderTraversalRecursive(root1->left);
            cout << root1->key << " ";
            inoderTraversalRecursive(root1->right);
        }
    }
    void preOrderTraversal()
    {
        Node<T> *temp1 = root;
        preOrderTraversalRecursive(temp1);
        cout << "\n";
    }
    void preOrderTraversalRecursive(Node<T> *root1)
    {
        if (root1 != NULL)
        {
            cout << root1->key << " ";
            preOrderTraversalRecursive(root1->left);
            preOrderTraversalRecursive(root1->right);
        }
    }
    void postOrderTraversal()
    {
        Node<T> *temp1 = root;
        postOrderTraversalRecursive(temp1);
        cout << "\n";
    }
    void postOrderTraversalRecursive(Node<T> *root1)
    {
        if (root1 != NULL)
        {
            postOrderTraversalRecursive(root1->left);
            postOrderTraversalRecursive(root1->right);
            cout << root1->key << " ";
        }
    }
    void remove(T k)
    {
        Node<T> *temp1 = root;
        deleteNode(temp1, NULL, k, 1, 1);
    }
    void deletetemp(Node<T> *root1, Node<T> *root2, T key, bool left, bool right)
    {
        if (root1->left == NULL && root1->right == NULL) // for leaf nodes
        {
            delete root1;
            root1 = NULL;
            if (left)
            {
                root2->left = NULL;
            }
            else
            {
                root2->right = NULL;
            }
        }
        else if (root1->left == NULL && root1->right != NULL)
        {
            Node<T> *temp = root1;
            root1 = root1->right;
            delete temp;
            return;
        }
        else if (root1->left != NULL && root1->right == NULL)
        {
            Node<T> *temp = root1;
            root1 = root1->left;
            delete temp;
            return;
        }
        else
        {
            Node<T> *temp = root1->right;
            Node<T> *temp2 = NULL;
            while (temp->left != NULL)
            {
                temp2 = temp;
                temp = temp->left;
            }
            root1->key = temp->key;
            delete temp;
            temp2->left = NULL;
        }
    }
    void deleteNode(Node<T> *root1, Node<T> *temp, T key, bool left, bool right)
    {

        if (root1 == NULL)
        {
            cout << "\nNOT FOUND";
        }
        else if (key < root1->key)
        {
            deleteNode(root1->left, root1, key, 1, 0);
        }
        else if (key > root1->key)
        {
            deleteNode(root1->right, root1, key, 0, 1);
        }
        else if (root1->key == key)
        {
            // deletetemp(root1,temp,key,left,right);
            if (root1->left == NULL && root1->right == NULL) // for leaf nodes
            {
                delete root1;
                root1 = NULL;
                if (left)
                {
                    temp->left = NULL;
                }
                else
                {
                    temp->right = NULL;
                }
            }
            else if (root1->left == NULL && root1->right != NULL)
            {
                Node<T> *temp1 = root1;
                root1 = root1->right;
                delete temp1;
                if (left)
                {
                    temp->left = root1;
                }
                else
                {
                    temp->right = root1;
                }
                return;
            }
            else if (root1->left != NULL && root1->right == NULL)
            {
                Node<T> *temp1 = root1;
                root1 = root1->left;
                delete temp1;
                if (left)
                {
                    temp->left = root1;
                }
                else
                {
                    temp->right = root1;
                }
                return;
            }
            else
            {
                Node<T> *temp = root1->right;
                Node<T> *temp2 = NULL;
                while (temp->left != NULL)
                {
                    temp2 = temp;
                    temp = temp->left;
                }
                root1->key = temp2->key;
                delete temp2;
                if (left)
                {
                    temp->left = root1;
                }
                else
                {
                    temp->right = root1;
                }
                return;
                //temp2->left = NULL;
            }
        }
    }
    int leafNodes()
    {
        return countLeafNodes(root);
    }
    int countLeafNodes(Node<T>* root)
    {
        if (root==NULL)
        {
            return 0;
            /* code */
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        int temp=countLeafNodes(root->left);
        int temp2=countLeafNodes(root->right);
        return temp+temp2;
    }
};

