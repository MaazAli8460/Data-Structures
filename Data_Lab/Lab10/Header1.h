#include <iostream>
#include <queue>
using namespace std;

class BinaryTree
{
public:
    int *treeArray;
    int capacity;
    int root;
    int current_index;
    BinaryTree()
    {
        root=1;
        current_index=1;
        capacity=20;
        treeArray = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            treeArray[i]=-1;
        }
        
    }
    void insert(int val)
    {
        treeArray[current_index]=val;
        current_index++;
    }
    void inorderTraversal(int index)
    {
        if (treeArray[index]!=-1)
        {
            //cout<<"in recursion\n";
            inorderTraversal(2*index);
            cout<<treeArray[index]<<" ";
            inorderTraversal(2*index+1);
        }
        
    }
    void displayInorder()
    {
        //cout<<"indisplay\n";
        inorderTraversal(root);
    }
};
