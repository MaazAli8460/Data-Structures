#include<iostream>
using namespace std;

class Process
{
private:
    /* data */
public:
    int ID;
    int priority;
    int time;
    Process* next;
    Process()
    {
        ID=0;
        priority = 0;
        time=0;
        next=NULL;

    }

};
class CustomQueue
{
public:
Process* obj;
CustomQueue* Next;
int count=0;
    CustomQueue()
    {
        obj=NULL;
        Next=NULL;
    }
    bool isEmpty()
    {
        if(count==0)
        {
            return true;
        }
        return false;
    }
    void enqueue(Process* process1)
    {
        Process *temp=new Process;
        temp->ID = process1->ID;
        temp->priority = process1->priority;
        temp->time = process1->time;
        temp->next = process1->next;
        if (count == 0)
        {
            obj=temp;
        }
        else
        {
            obj->next = temp;
        }
        count++;
    }
    ~CustomQueue();
};

CustomQueue::CustomQueue(/* args */)
{
}

CustomQueue::~CustomQueue()
{
}

