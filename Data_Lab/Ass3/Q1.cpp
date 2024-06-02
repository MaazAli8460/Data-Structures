// Name : Maaz Ali
// Section: A
// Roll Number: 22i-1042
#include <iostream>
#include <string>
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
};

template <typename T>
class Stack
{
public:
    Node<T> *top;
    int size;
    Stack()
    {
        top = NULL;
        size = 0;
    }
    void push(T var)
    {

        Node<T> *temp = new Node<T>;
        temp->data = var;
        temp->next = top;
        top = temp;
        size++;
    }
    T pop()
    {
        Node<T> *temp = top->next;
        T data1 = top->data;
        delete (top);
        top = temp;
        size--;
        return data1;
    }
    T peek()
    {
        if (size == 0)
        {
            return -1;
            /* code */
        }
        return top->data;
    }
    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    }
};
//coplextity of Q1 is O(n+k)
string largestString(string str, int k)
{
    string result = "";
    Stack<char> stack;
    int n = str.length();
    for (int i = n - 1; i >= 0; i--)//loop will push the string in the stack
    {
        stack.push(str[i]);
    }
    Stack<char> stacktemp;

    while (k > 0) //in worst case it will only run for n+k times
    {
        char temp = stack.peek();
        stack.pop();
        if (static_cast<int>(temp) > static_cast<int>(stack.peek()))
        {
            stacktemp.push(temp);
            continue;
        }

        if (static_cast<int>(temp) == static_cast<int>(stack.peek()))
        {
            stacktemp.push(temp);
            continue;
        }

        else
        {
            temp = stack.peek();
            k--;
            while (!stacktemp.isEmpty() && k != 0) //Loop will only run if k is greater than zero 
            {
                if (static_cast<int>(temp) > static_cast<int>(stacktemp.peek()))
                {
                    stacktemp.pop();
                    k--;
                }
                else
                {
                    break;
                }
            }
        }
    }
    int i = 0;
    while (!stacktemp.isEmpty()) //poping values in string
    {
        result = stacktemp.pop() + result;
        i++;
    }
    while (!stack.isEmpty()) //poping values in string
    {
        result = result + stack.pop();
        i++;
    }
    return result;
}
//Q2 complexity is O(n+k)
string solve(string number, int k)
{
    string result = "";
    Stack<char> stack;
    int n = number.length();
    for (int i = n - 1; i >= 0; i--)//loop will push the string in the stack
    {
        stack.push(number[i]);
    }
    Stack<char> stacktemp;
    while (static_cast<int>(stack.peek()) == 0)//will pop any leading zeros in string and decrement K
    {
        stack.pop();
        k--;
    }
    char bottom_of_stack;
    while (!stack.isEmpty()) //for worst case this loop will run for n+k
    {

        char temp = stack.peek();
        stack.pop();
        bool fl = false;
        //loop will run for max K times throughout the loop since the value of k is being decremented each time
        while (!stacktemp.isEmpty() && static_cast<int>(stacktemp.peek()) > static_cast<int>(temp) && k > 0)
        {

            char temp2 = stacktemp.pop();
            if (temp == '0' && stacktemp.isEmpty()) // to ensure that first digit is non zero
            {
                bottom_of_stack = temp2;
                stacktemp.push(temp2);
                stacktemp.push(temp);
                fl = true;
                break;
            }
            k--;
        }
        if (fl == true)
        {
            continue;
        }

        if (!stacktemp.isEmpty() && static_cast<int>(stacktemp.peek()) == 48 && static_cast<int>(temp) != 48 && k > 0)
        {
            if (static_cast<int>(bottom_of_stack) > static_cast<int>(temp) && k >= stacktemp.size)
            {
                while (!stacktemp.isEmpty() && k>=0)//loop will run for max K times throughout
                {
                    stacktemp.pop();
                    k--;
                }
                bottom_of_stack = temp;
                stacktemp.push(temp);
                continue;
            }
        }
        if (fl == false && !stacktemp.isEmpty() || static_cast<int>(temp) != 48) // to avoid leading zeros
        {
            if (stacktemp.isEmpty())
            {
                bottom_of_stack = temp;
                stacktemp.push(temp);
                continue;
            }
            stacktemp.push(temp);
        }
    }
    while (k > 0) // if still some values left then pop form the end
    {
        stacktemp.pop();
        k--;
    }
    int i = 0;
    while (!stacktemp.isEmpty()) // loop to copy the stack in string
    {
        result = stacktemp.pop() + result;
        i++;
    }
    cout << result << "\n";
    return result;
}

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
//Q3 time complexity = O(n) 
int *maxSubsequence(int nums[], int size, int k)
{
    int *arr=new int[k];
    CustomQueue<int> *q = new CustomQueue<int>;
    CustomQueue<int> *sums = new CustomQueue<int>;
    int sum=0;
    int pass=0;
    for (int i = 0; i < size; i++)//loop will run only for n times
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

    while (!sums->is_empty())// loop to get the highest sum from sums queue
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
    cout<<endl;
    for (int i = pass; i < k+pass; i++)// copiying the result in arr to return
    {
        arr[count]=nums[i];
        cout<<arr[count]<<",";
        count++;   
    }
    cout<<endl;
    return arr;
}
