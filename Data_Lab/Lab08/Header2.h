#include <iostream>
using namespace std;

template <typename T>

class Node
{
public:
    T data;
    Node *next;
    Node(/* args */)
    {
        data=0;
        next=NULL;
    }
    //~Node();
};

template <typename T>
class CustomQueue
{
private:
    /* data */
public:
    Node<T> *front;
    Node<T> *rear;
    int count;
    CustomQueue()
    {
        front = NULL;
        rear = NULL;
        count = 0;
    }
    CustomQueue(CustomQueue * temp)
    {
        front=temp->front;
        rear=temp->rear;
        count=temp->count;
    }
    void enqueue(T num)
    {

        Node<T> *temp=new Node<T>;
        temp->data = num;
        temp->next = NULL;
        if (count == 0)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        count++;
    }
    T dequeue()
    {
        Node<T> *temp;
        T val;
        if (count==0)
        {
            front=NULL;
            rear=front;
            cout << "The queue is empty.\n";
        }
        else
        {
            val = front->data;
            temp = front->next;
            delete front;
            front = temp;
            count--;
        }

        return val;
    }
    T peek()
    {
        return front->data;
    }
    bool is_empty()
    {
        
        if(front == NULL)
        {
            return true;
        }
        return false;
    }
    int size()
    {
        return count;
    }
    void clear()
    {
        while (front!=NULL)
        {
            dequeue();
        }
        
    }
    
};
template<typename T>
class ZigzagIterator//: public CustomQueue
{
public:
    CustomQueue<T>* Q1;
    CustomQueue<T>* Q2;
    int val;
    int count=0;
    ZigzagIterator(CustomQueue<T>& q1, CustomQueue<T>& q2)
    {
        Q1=&q1;
        Q2=&q2;
        val=q1.size();
        val+=q2.size();
        
    }
    bool hasNext()
    {
        if(Q1->is_empty() && Q2->is_empty())
        {
            return false;
        }
        return true;
    }
    T next()
    {
        if(!hasNext())
        {
            return -1;
        }
        if(count==0 && !Q1->is_empty() && !Q2->is_empty())
        {
            T temp=Q1->dequeue();
            cout<<temp<<",";
            count=(count+1)%2;
            val--;
            return temp;
        }
        else if(count==1 && !Q1->is_empty() && !Q2->is_empty())
        {
            T temp=Q2->dequeue();
            cout<<temp<<",";

            count=(count+1)%2;
            val--;
            return temp;
        }
        else if(!Q1->is_empty() && Q2->is_empty())
        {
            T temp=Q1->dequeue();
            cout<<temp<<",";

            val--;
            return temp;
        }
        else if(Q1->is_empty() && !Q2->is_empty())
        {
            T temp=Q2->dequeue();
            cout<<temp<<",";

            val--;
            return temp;
        }
        return 0;
    }
    
};

