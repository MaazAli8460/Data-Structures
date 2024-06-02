#include <iostream>
#include <string>
#include <stack>
using namespace std;
string solve(const std::string& str, int k) {
    std::stack<char> result;

    for (char digit : str) {
        while (!result.empty() && k > 0 && digit < result.top()) {
            result.pop();
            k--;
        }
        result.push(digit);
    }

    // Pop remaining elements to meet the constraint of removing k digits
    while (k > 0 && !result.empty()) {
        result.pop();
        k--;
    }

    // Construct the final result string
    std::string ans;
    while (!result.empty()) {
        ans += result.top();
        result.pop();
    }

    // Remove leading zeros
    int i = 0;
    while (i < ans.size() && ans[i] == '0') {
        i++;
    }
    ans = ans.substr(i);

    // If the result is empty, return "0"
    if (ans.empty()) {
        return "0";
    }

    return ans;
}

int main() {
    // Test cases
    cout << "Test 1: " << solve("10142", 2) << endl; // Expected: "4"
    cout << "Test 2: " << solve("96", 1) << endl; // Expected: "6"
    cout << "Test 3: " << solve("6789", 0) << endl; // Expected: "6789"
    cout << "Test 4: " << solve("6", 0) << endl; // Expected: "6"
    cout << "Test 5: " << solve("2000000000000000", 10) << endl; // Expected: "287948768"
    cout << "Test 6: " << solve("53980517", 2) << endl; // Expected: "380517"
    cout << "Test 7: " << solve("37594852632", 10) << endl; // Expected: "2"
    cout << "Test 8: " << solve("739717549062896", 1) << endl; // Expected: "39717549062896"
    cout << "Test 9: " << solve("2233300000000000000", 3) << endl; // Expected: "2200000000000000"
    cout << "Test 10: " << solve("1766739498453158327826647316936982938316534805172218962557053186925224732", 2) << endl; // Expected: "16639498453158327826647316936982938316534805172218962557053186925224732"
    cout << "Test 11: " << solve("464038665066592229991395446868568141659015313318498114800229294263538051662670061878", 28) << endl; // Expected: "13445141659015313318498114800229294263538051662670061878"

    return 0;
}
