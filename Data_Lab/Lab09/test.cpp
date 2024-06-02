#include "pch.h"
#include "Header1.h"

  


TEST(StackTest, EmptyStack) {
    Stack<int> intStack;
    EXPECT_TRUE(intStack.isEmpty());
}

TEST(StackTest, PushAndPop) {
    Stack<int> intStack;
    intStack.push(42);
    EXPECT_FALSE(intStack.isEmpty());
    EXPECT_EQ(intStack.peek(), 42);

    intStack.pop();
    EXPECT_TRUE(intStack.isEmpty());
}

TEST(StackTest, ClearStack) {
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    intStack.clear();
    EXPECT_TRUE(intStack.isEmpty());
}



// Test case to check an empty string
TEST(PalindromeTest, EmptyString) {
    std::string inputStr = "";
  
    EXPECT_TRUE(isPalindrome(inputStr));
}

TEST(CleanStringTest, CleansString) {
    std::string input1 = "M A%! DAm#";
    std::string input2 = "Univ#ersi ty";
    isPalindrome(input1);
    EXPECT_TRUE(isPalindrome(cleanString(input1)));
    cout<<endl<<"THIs"<<endl;
    EXPECT_FALSE(isPalindrome(cleanString(input2)));
 }

// Test case to check a palindrome with letters and numbers
TEST(IsPalindromeTest, DetectsPalindrome) {
    std::string palindrome1 = "racecar";
    std::string nonPalindrome1 = "hello";
    std::string palindrome2 = "A man, a plan, a canal, Panama!";
    std::string nonPalindrome2 = "not a palindrome";

    EXPECT_TRUE(isPalindrome(palindrome1));
    EXPECT_FALSE(isPalindrome(nonPalindrome1));
    EXPECT_TRUE(isPalindrome(cleanString(palindrome2)));
    EXPECT_FALSE(isPalindrome(nonPalindrome2));
}


// Test case to check a non-palindrome with special characters
TEST(PalindromeTest, NonPalindromeWithSpecialCharacters) {
    std::string inputStr = "Race@Car";
    EXPECT_FALSE(isPalindrome(inputStr));
}

// Test case to check a non-palindrome with letters and numbers
TEST(PalindromeTest, NonPalindromeWithLettersAndNumbers) {
    std::string inputStr = "hello123";
    EXPECT_FALSE(isPalindrome(inputStr));
}

// Test case to check a single-character palindrome
TEST(PalindromeTest, SingleCharacterPalindrome) {
    std::string inputStr = "A";
    
    EXPECT_TRUE(isPalindrome(inputStr));
}

TEST(StackSortTest, SortsInAscendingOrder) {
    Stack<int> stack;
    stack.push(5);
    stack.push(2);
    stack.push(4);
    stack.push(1);
    stack.push(3);

    sortStack(stack);

    // Check if the stack is sorted in ascending order.
    EXPECT_EQ(stack.peek(), 1);
    stack.pop();
    EXPECT_EQ(stack.peek(), 2);
    stack.pop();
    EXPECT_EQ(stack.peek(), 3);
    stack.pop();
    EXPECT_EQ(stack.peek(), 4);
    stack.pop();
    EXPECT_EQ(stack.peek(), 5);
    stack.pop();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}