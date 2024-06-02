#include <gtest/gtest.h>

#include "22i-1042_A_A3.h"



// Test case
TEST(Question_1, Test1) {
	std::string str = "mytttiiifsdjjojsadhsadunefwefwefwefdshjyiohdgwrg";
	int k = 4;
	std::string ans = "ytttisdjjojsadhsadunefwefwefwefdshjyiohdgwrg";
    EXPECT_EQ(ans, largestString(str,k)); // This expectation will fail
}

TEST(Question_1, Test2) {
	std::string str = "codingisnofununtilyoudodsa";
	int k = 8;
	std::string ans = "sofununtilyoudodsa";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test3) {
	std::string str = "rebmasitohsui";
	int k = 3;
	std::string ans = "rmsitohsui";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test4) {
	std::string str = "farigballdamhadbj";
	int k = 5;
	std::string ans = "rilldamhadbj";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test5) {
	std::string str = "maajyutrrabcde";
	int k = 2;
	std::string ans = "mjyutrrabcde";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}
// Test case Question-2
TEST(Question_2, Test1) {
	std::string str = "45";
	int k = 1;
	std::string ans = "4";
	EXPECT_EQ(ans, solve(str, k)); 
}
TEST(Question_2, Test2) {
	std::string str = "96";
	int k = 1;
	std::string ans = "6";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test3) {
	std::string str = "6789";
	int k = 0;
	std::string ans = "6789";
	EXPECT_EQ(ans, solve(str, k)); 
}
TEST(Question_2, Test4) {
	std::string str = "6";
	int k = 0;
	std::string ans = "6";
	EXPECT_EQ(ans, solve(str, k)); 
}
TEST(Question_2, Test5) {
	std::string str = "287948768";
	int k = 0;
	std::string ans = "287948768";
	EXPECT_EQ(ans, solve(str, k)); 
}
TEST(Question_2, Test6) {
	std::string str = "53980517";
	int k = 2;
	std::string ans = "380517";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test7) {
	std::string str = "37594852632";
	int k = 10;
	std::string ans = "2";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test8) {
	std::string str = "739717549062896";
	int k = 1;
	std::string ans = "39717549062896";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test9) {
	std::string str = "2233300000000000000";
	int k = 3;
	std::string ans = "2200000000000000";
	EXPECT_EQ(ans, solve(str, k));
}

TEST(Question_2, Test10) {
	std::string str = "1766739498453158327826647316936982938316534805172218962557053186925224732";
	int k = 2;
	std::string ans = "16639498453158327826647316936982938316534805172218962557053186925224732";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test11) {
	std::string str = "464038665066592229991395446868568141659015313318498114800229294263538051662670061878";
	int k = 28;
	std::string ans = "13445141659015313318498114800229294263538051662670061878";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test12) {
	std::string str = "2910325986297865201398145278756";
	int k = 27;
	std::string ans = "1001";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test13) {
	std::string str = "930879762870164";
	int k = 10;
	std::string ans = "20164";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test14) {
	std::string str = "930879762870164";
	int k = 7;
	std::string ans = "30270164";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test15) {
	std::string str = "98270191379642239801000";
	int k = 17;
	std::string ans = "101000";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test16) {
	std::string str = "9130879762870164";
	int k = 6;
	std::string ans = "1062870164";
	EXPECT_EQ(ans, solve(str, k));
}
// Test case Question-3
TEST(Question_3, Test1) {
	int arr[5] = { 1,2,3,4,5 };
	int arr2[1] = { 5 };
	int k = 1;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test2) {
	int arr[10] = { 3, -1, -2, 4, 6, -2, 2, 4, 6, -1 };
	int arr2[5] = { 6, -2 , 2 , 4 , 6 };
	int k = 5;
	int size = 10;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test3) {
	int arr[5] = { 0, 0 , 0 , 0 , 0};
	int arr2[5] = { 0, 0 , 0 , 0 , 0 };
	int k = 5;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test4) {
	int arr[5] = { -5,-1,-1,-1,-1 };
	int arr2[2] = { -1, -1};
	int k = 2;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test5) {
	int arr[8] = { 10, -5, 7, -3, 5, 1, -2, -6 };
	int arr2[5] = { 7, -3, 5, 1 };
	int k = 4;
	int size = 8;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

int main(int argc, char ** argv) {
  testing::InitGoogleTest( & argc, argv);
  return RUN_ALL_TESTS();
}