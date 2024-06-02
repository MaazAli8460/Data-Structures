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
    Node<T> *bottom;
    Node<T> *top;

    int size;
    Stack()
    {
        bottom = NULL;
        top = NULL;
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
            /* code */
        }
        return false;
    }
};
bool isPalindrome(string str)
{
    Stack<char> step;
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    if (i == 0 || i == 1)
    {
        return true;
    }
    // cout<<endl<<i;
    int mid = i / 2;
    // cout<<endl<<mid;

    int j = 0;
    for (; j < mid; j++)
    {
        step.push(str[j]);
    }
    if (i % 2 != 0)
    {
        j++;
    }
    // cout<<endl<<j;
    bool temp = false;
    while (j < i)
    {
        if (str[j] == step.peek())
        {
            temp = true;
            step.pop();
            j++;
            continue;
        }
        else
        {
            temp = false;
            break;
        }
    }
    return temp;
}
string cleanString(string str)
{
    string result;
    Stack<char> step;
    int length = str.length();
    int var = 0;
    char temp; // 32–47 / 58–64 / 91–96 / 123–126 range of special character
    int i = 0;
    int j = 0;
    while (str[i] != '\0')
    {
        var = static_cast<int>(str[i]);
        // cout<<var<<":"<<str[i]<<",";
        if (var >= 32 && var <= 47 || var >= 58 && var <= 64 || var >= 91 && var <= 96 || var >= 123 && var <= 126)
        {
            i++;
            continue;
        }
        if (var >= 65 && var <= 90)
        {
            var += 32;
            step.push(static_cast<char>(var));
            i++;
            continue;
        }
        step.push(static_cast<char>(var));

        // result+=str[i];
        i++;
    }
    cout << endl
         << result;
    while (!step.isEmpty())
    {
        /* code */
        result += step.pop();
    }
    str = result;
    cout << endl
         << str;
    return str;
}
template <typename T>

void sortStack(Stack<T> &step)
{
    if (!step.isEmpty())
    {
        int temp = step.pop();
        sortStack(step);
        insertsort(step, temp);
    }
}
void insertsort(Stack<int> &step, int item)
{
    if (step.isEmpty() || item <= step.peek())
    {
        step.push(item);
    }
    else
    {
        int temp = step.pop();
        insertsort(step, item);
        step.push(temp);
    }
}