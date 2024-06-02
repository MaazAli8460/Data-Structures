
#include <iostream>
#include <queue>
using namespace std;
template <typename T>

class Node
{
public:
    T data;
    Node *next;
    Node(/* args */)
    {
        data = 0;
        next = NULL;
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
    CustomQueue(CustomQueue *temp)
    {
        front = temp->front;
        rear = temp->rear;
        count = temp->count;
    }
    void enqueue(T num)
    {

        Node<T> *temp = new Node<T>;
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
        if (count == 0)
        {
            front = NULL;
            rear = front;
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

        if (front == NULL)
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
        while (front != NULL)
        {
            dequeue();
        }
    }
};
int *maxSubsequence(int nums[], int size, int k)
{
    int *arr=new int[k];
    CustomQueue<int> *q = new CustomQueue<int>;
    CustomQueue<int> *sums = new CustomQueue<int>;
    int sum=0;
    int pass=0;
    for (int i = 0; i < size; i++)
    {
        if (q->size() < k)
        {
            q->enqueue(nums[i]);
            sum+=nums[i];
        }
        else
        {
            sums->enqueue(sum);
            int var=q->dequeue();
            sum-=var; 
            q->enqueue(nums[i]);
            sum+=nums[i];  
        }
    }
    sums->enqueue(sum);
    int largest=sums->peek();
    int count=0;

    while (!sums->is_empty())
    {
        int var=sums->dequeue();
        if (var>largest)
        {
            largest=var;
            pass=count;
        }
        count++;
    }
    count=0;
    for (int i = pass; i < k+pass; i++)
    {
        arr[count]=nums[i];
        cout<<arr[count]<<",";
        count++;   
    }
    return arr;
}
int* maxSubsequence1(int nums[], int size, int k) {
    if (size <= k) {
        return nums;
    }

    queue<int> maxQueue;
    queue<int> currentQueue;
    int maxSum = 0;
    int maxStart = 0;

    for (int i = 0; i < size; i++) {
        currentQueue.push(i);

        while (!currentQueue.empty() && currentQueue.front() <= i - k) 
            currentQueue.pop();
        
        int currentElement = nums[i];
        if (!maxQueue.empty()) 
            currentElement += nums[maxQueue.front()];
        
        if (currentElement > maxSum) {
            maxSum = currentElement;
            maxStart = currentQueue.front();
        }

        while (!maxQueue.empty() && currentElement >= nums[maxQueue.back()]) 
            maxQueue.pop();
        

        maxQueue.push(currentQueue.front());
    }
    
    cout << "THE ARRAY" << endl;
    for (int i = 0; i < (sizeof(*nums) / sizeof(nums[0])); i++) {
       cout << nums[i] << "\t";
    }
    cout << endl;

    return &nums[maxStart];
}
int main()
{
    int arr[8] = { 10, -5, 7, -3, 5, 1, -2, -6 };
	int arr2[5] = { 7, -3, 5, 1 };
	int k = 4;
	int size = 8;
	int* result = maxSubsequence(arr, size, k);
    //cout << "The result is: "<<*result;
    return 0;
}