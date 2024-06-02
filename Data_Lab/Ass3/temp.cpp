#include <string>
#include <iostream>
#include <stack>
using namespace std;

std::string largestString(const std::string& str, int k) {
    std::stack<char> stack;
    int n = str.size();

    for (int i = 0; i < n; i++) {
        while (!stack.empty() && k > 0 && stack.top() < str[i]) {
            cout << stack.top()<<","<<str[i] <<":"<< k << endl;
            cout<<i<<endl;
            stack.pop();
            k--;
        }
        stack.push(str[i]);
    }

    // If there are still characters left to remove, pop them from the end
    while (k > 0) {
        stack.pop();
        cout<<"fuck";
        k--;
    }

    std::string result;
    while (!stack.empty()) {
        result = stack.top() + result;
        stack.pop();
    }

    return result;
}
int main()
{
    string str = "maajyutrrabcde";
	int k = 2;
    //ytttisdjjojsadhsadunefwefwefwefdshjyiohdgwrg
    //ytttisdjjojsadhsadunefwefwefwefdshjyiohdgwrg
    str = largestString(str, k);
    cout << str;
    return 0;
}







//sofununtilyoudodsa