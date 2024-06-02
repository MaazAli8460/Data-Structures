#include <iostream>
#include <string>
#include <time.h>

using namespace std;
class Node
{
    public:
    int key;
    int value;
    Node *next;
    Node()
    {
        key = -1;
        value = -1;
        next = NULL;
    }
    Node(int k, int v)
    {
        key = k;
        value = v;
        next = NULL;
    }
};
class HashMap
{
    public:
    int capacity;
    Node **arr_of_linkedlist;
    HashMap()
    {
        capacity = 5;
        arr_of_linkedlist = new Node *[5];
        for (int i = 0; i < 5; i++)
        {
            arr_of_linkedlist[i]=NULL;
            /* code */
        }
    }
    int HashFunction(int key)
    {
        return key % capacity;
    }
    void insert(int key, int val)
    {
        int hash = HashFunction(key);
        bool found = false;
        if (arr_of_linkedlist[hash]==NULL)
        {
            arr_of_linkedlist[hash]=new Node(key,val);
        }
        else
        {
            Node* current=new Node(key,val);
            current->next=arr_of_linkedlist[hash];
            arr_of_linkedlist[hash]=current;
            current=NULL;
        }
    }
    int search(int key)
    {
        int hash = HashFunction(key);
        if (arr_of_linkedlist[hash]!=NULL)
        {
            Node* temp=arr_of_linkedlist[hash];
            while (temp != NULL)
            {
                if (temp->key==key)
                {
                    return temp->value;
                    
                }
                temp=temp->next;
                
            }
        }
        return -1;
    }
    void remove(int key)
    {
        int hash = HashFunction(key);
        if (arr_of_linkedlist[hash]==NULL)
        {
            return;
            /* code */
        }
        
        if (arr_of_linkedlist[hash]->key==key)
        {
            Node* temp=arr_of_linkedlist[hash];
            arr_of_linkedlist[hash]=arr_of_linkedlist[hash]->next;
            delete temp;
            return;
        }

        else
        {
            Node*current=arr_of_linkedlist[hash];
            Node* priv=NULL;
            while (current!=NULL)
            {
                if (current==NULL)
                {
                    return;
                    /* code */
                }
                
                if (current->key == key)
                {
                    priv->next=current->next;
                    delete current;
                }
                priv=current;
                current=current->next;
            }
            

        }
        
    }
    bool insert1(int key, int val)
    {
        int hash = HashFunction(key);
        bool found = false;
        if (arr_of_linkedlist[hash]==NULL)
        {
            arr_of_linkedlist[hash]=new Node(key,val);
        }
        else
        {
            Node* current=new Node(key,val);
            if (key==arr_of_linkedlist[hash]->key && val==arr_of_linkedlist[hash]->value)
            {
                return false;
            }
            
            current->next=arr_of_linkedlist[hash];
            arr_of_linkedlist[hash]=current;
            current=NULL;
        }
        return true;
    }
};
bool hasLoop(Node* temp)
{
	HashMap findloop;
    while (temp!=NULL)
    {
        bool flag=findloop.insert1(temp->key,temp->value);
        if (flag==false)
        {
            return true;
        }
        temp=temp->next;
    }
    
	
	return false;
}