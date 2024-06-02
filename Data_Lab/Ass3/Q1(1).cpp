#include <iostream>
#include <string>
#include <cassert>
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
string largestString(string str, int k)
{
    string result = "";
    Stack<char> stack;
    int n = str.length();
    for (int i = n - 1; i >= 0; i--)
    {
        stack.push(str[i]);
    }
    Stack<char> stacktemp;

    while (k > 0)
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
            while (!stacktemp.isEmpty() && k != 0)
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
    while (!stacktemp.isEmpty())
    {
        result = stacktemp.pop() + result;
        i++;
    }
    while (!stack.isEmpty())
    {
        result = result + stack.pop();
        i++;
    }
    return result;
}
string solve(string number, int k)
{
    string result = "";
    Stack<char> stack;
    int n = number.length();
    for (int i = n - 1; i >= 0; i--)
    {
        stack.push(number[i]);
    }
    Stack<char> stacktemp;
    while (static_cast<int>(stack.peek()) == 0)
    {
        stack.pop();
        k--;
    }
    char bottom_of_stack;
    while (!stack.isEmpty())
    {

        char temp = stack.peek();
        stack.pop();
        bool fl = false;
        while (!stacktemp.isEmpty() && static_cast<int>(stacktemp.peek()) > static_cast<int>(temp) && k > 0)
        {

            char temp2 = stacktemp.pop();
            if (temp == '0' && stacktemp.isEmpty())
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
                while (!stacktemp.isEmpty())
                {
                    stacktemp.pop();
                    k--;
                }
                bottom_of_stack = temp;
                stacktemp.push(temp);
                continue;
            }
        }
        if (fl == false && !stacktemp.isEmpty() || static_cast<int>(temp) != 48) // && fl2==false) // to avoid leading zeros
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
    while (k > 0)
    {
        stacktemp.pop();
        k--;
    }
    int i = 0;
    while (!stacktemp.isEmpty())
    {
        result = stacktemp.pop() + result;
        i++;
    }
    cout << result << "\n";
    return result;
}
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

int main()
{
    cout << "Test 1: " << solve("30142", 2) << endl;                                                                                 // Expected: "101"
    cout << "Test 2: " << solve("96", 1) << endl;                                                                                     // Expected: "6"
    cout << "Test 3: " << solve("6789", 0) << endl;                                                                                   // Expected: "6789"
    cout << "Test 4: " << solve("6", 0) << endl;                                                                                      // Expected: "6"
    cout << "Test 5: " << solve("20000000000", 10) << endl;                                                                           // Expected: "287948768"
    cout << "Test 6: " << solve("53980517", 2) << endl;                                                                               // Expected: "380517"->check
    cout << "Test 7: " << solve("37594852632", 10) << endl;                                                                           // Expected: "2"
    cout << "Test 8: " << solve("739717549062896", 1) << endl;                                                                        // Expected: "39717549062896"->check39717549062896
    cout << "Test 9: " << solve("2233300000000000000", 3) << endl;                                                                    // Expected: "2200000000000000"->check
    cout << "Test 10: " << solve("1766739498453158327826647316936982938316534805172218962557053186925224732", 2) << endl;             // Expected: "16639498453158327826647316936982938316534805172218962557053186925224732"
    cout << "Test 11: " << solve("464038665066592229991395446868568141659015313318498114800229294263538051662670061878", 28) << endl; // Expected: "13445141659015313318498114800229294263538051662670061878"
    std::string str1 = "45";
    int k1 = 1;
    std::string ans1 = "4";
    std::string result1 = solve(str1, k1);
    if (result1 == ans1)
    {
        std::cout << "Test 1 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 1 failed. Expected: " << ans1 << ", Got: " << result1 << std::endl;
    }

    // Test 2
    std::string str2 = "96";
    int k2 = 1;
    std::string ans2 = "6";
    std::string result2 = solve(str2, k2);
    if (result2 == ans2)
    {
        std::cout << "Test 2 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 2 failed. Expected: " << ans2 << ", Got: " << result2 << std::endl;
    }

    // Test 3
    std::string str3 = "6789";
    int k3 = 0;
    std::string ans3 = "6789";
    std::string result3 = solve(str3, k3);
    if (result3 == ans3)
    {
        std::cout << "Test 3 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 3 failed. Expected: " << ans3 << ", Got: " << result3 << std::endl;
    }

    // Test 4
    std::string str4 = "6";
    int k4 = 0;
    std::string ans4 = "6";
    std::string result4 = solve(str4, k4);
    if (result4 == ans4)
    {
        std::cout << "Test 4 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 4 failed. Expected: " << ans4 << ", Got: " << result4 << std::endl;
    }

    // Test 5
    std::string str5 = "287948768";
    int k5 = 0;
    std::string ans5 = "287948768";
    std::string result5 = solve(str5, k5);
    if (result5 == ans5)
    {
        std::cout << "Test 5 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 5 failed. Expected: " << ans5 << ", Got: " << result5 << std::endl;
    }

    // Test 6
    std::string str6 = "53980517";
    int k6 = 2;
    std::string ans6 = "380517";
    std::string result6 = solve(str6, k6);
    if (result6 == ans6)
    {
        std::cout << "Test 6 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 6 failed. Expected: " << ans6 << ", Got: " << result6 << std::endl;
    }

    // Test 7
    std::string str7 = "37594852632";
    int k7 = 10;
    std::string ans7 = "2";
    std::string result7 = solve(str7, k7);
    if (result7 == ans7)
    {
        std::cout << "Test 7 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 7 failed. Expected: " << ans7 << ", Got: " << result7 << std::endl;
    }

    // Test 8
    std::string str8 = "739717549062896";
    int k8 = 1;
    std::string ans8 = "39717549062896";
    std::string result8 = solve(str8, k8);
    if (result8 == ans8)
    {
        std::cout << "Test 8 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 8 failed. Expected: " << ans8 << ", Got: " << result8 << std::endl;
    }

    // Test 9
    std::string str9 = "2233300000000000000";
    int k9 = 3;
    std::string ans9 = "2200000000000000";
    std::string result9 = solve(str9, k9);
    if (result9 == ans9)
    {
        std::cout << "Test 9 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 9 failed. Expected: " << ans9 << ", Got: " << result9 << std::endl;
    }

    // Test 10
    std::string str10 = "1766739498453158327826647316936982938316534805172218962557053186925224732";
    // 1766739498453158327826647316936982938316534805172218962557053186925224732
    int k10 = 2;
    std::string ans10 = "16639498453158327826647316936982938316534805172218962557053186925224732";
    // 16639498453158327826647316936982938316534805172218962557053186925224732
    std::string result10 = solve(str10, k10);
    if (result10 == ans10)
    {
        std::cout << "Test 10 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 10 failed. Expected: " << ans10 << ", Got: " << result10 << std::endl;
    }

    // Test 11
    std::string str11 = "464038665066592229991395446868568141659015313318498114800229294263538051662670061878";
    int k11 = 28;
    std::string ans11 = "13445141659015313318498114800229294263538051662670061878";
    std::string result11 = solve(str11, k11);
    if (result11 == ans11)
    {
        std::cout << "Test 11 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 11 failed. Expected: " << ans11 << ", Got: " << result11 << std::endl;
    }

    // Test 12
    std::string str12 = "2910325986297865201398145278756";
    int k12 = 27;
    std::string ans12 = "1001";
    std::string result12 = solve(str12, k12);
    if (result12 == ans12)
    {
        std::cout << "Test 12 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 12 failed. Expected: " << ans12 << ", Got: " << result12 << std::endl;
    }

    // Test 13
    std::string str13 = "930879762870164";
    int k13 = 10;
    std::string ans13 = "20164";
    std::string result13 = solve(str13, k13);
    if (result13 == ans13)
    {
        std::cout << "Test 13 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 13 failed. Expected: " << ans13 << ", Got: " << result13 << std::endl;
    }

    // Test 14
    std::string str14 = "930879762870164";
    int k14 = 7;
    std::string ans14 = "30270164";
    std::string result14 = solve(str14, k14);
    if (result14 == ans14)
    {
        std::cout << "Test 14 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 14 failed. Expected: " << ans14 << ", Got: " << result14 << std::endl;
    }

    // Test 15
    std::string str15 = "98270191379642239801000";
    int k15 = 17;
    std::string ans15 = "101000";
    std::string result15 = solve(str15, k15);
    if (result15 == ans15)
    {
        std::cout << "Test 15 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 15 failed. Expected: " << ans15 << ", Got: " << result15 << std::endl;
    }

    // Test 16
    std::string str16 = "9130879762870164";
    int k16 = 6;
    std::string ans16 = "1062870164";
    std::string result16 = solve(str16, k16);
    if (result16 == ans16)
    {
        std::cout << "Test 16 passed." << std::endl;
    }
    else
    {
        std::cout << "Test 16 failed. Expected: " << ans16 << ", Got: " << result16 << std::endl;
    }
    std::string str = "45";
    int k = 1;
    std::string ans = "4";
    assert(solve(str, k) == ans);
    str = "96";
    k = 1;
    ans = "6";
    assert(solve(str, k) == ans);

    str = "6789";
    k = 0;
    ans = "6789";
    assert(solve(str, k) == ans);

    str = "6";
    k = 0;
    ans = "6";
    assert(solve(str, k) == ans);

    str = "287948768";
    k = 0;
    ans = "287948768";
    assert(solve(str, k) == ans);

    str = "53980517";
    k = 2;
    ans = "380517";
    assert(solve(str, k) == ans);

    str = "37594852632";
    k = 10;
    ans = "2";
    assert(solve(str, k) == ans);

    str = "739717549062896";
    k = 1;
    ans = "39717549062896";
    assert(solve(str, k) == ans);

    str = "2233300000000000000";
    k = 3;
    ans = "2200000000000000";
    assert(solve(str, k) == ans);

    str = "1766739498453158327826647316936982938316534805172218962557053186925224732";
    k = 2;
    ans = "16639498453158327826647316936982938316534805172218962557053186925224732";
    assert(solve(str, k) == ans);

    str = "464038665066592229991395446868568141659015313318498114800229294263538051662670061878";
    k = 28;
    ans = "13445141659015313318498114800229294263538051662670061878";
    assert(solve(str, k) == ans);

    str = "2910325986297865201398145278756";
    k = 27;
    ans = "1001";
    assert(solve(str, k) == ans);

    str = "930879762870164";
    k = 10;
    ans = "20164";
    assert(solve(str, k) == ans);

    str = "930879762870164";
    k = 7;
    ans = "30270164";
    assert(solve(str, k) == ans);

    str = "98270191379642239801000";
    k = 17;
    ans = "101000";
    assert(solve(str, k) == ans);

    str = "9130879762870164";
    k = 6;
    ans = "1062870164";
    assert(solve(str, k) == ans);
    std::cout << "All test cases passed." << std::endl;
    return 0;
}

// mjyutrrabcde