#include <gtest/gtest.h>
#include "header.cpp"
TEST(q1, base) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T1.txt");
    string result  =  obj.GetPath(1, 6);
    string org = "1-1 -> 2-1 -> 3-1 -> 4-1 -> 4-2 -> 5-2 -> 6-2";
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}

TEST(q1, add_del) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T1.txt");
    obj.addNode(1,5);
    obj.DeleteNode(1,2);
    string result = obj.GetPath(1,6);
    string org = "1-1 -> 1-2 -> 2-2 -> 3-2 -> 3-1 -> 4-1 -> 5-1 -> 6-1";
    EXPECT_EQ(result, org);
}
TEST(q1, t2) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T2.txt");
    string result  =  obj.GetPath(4, 6);
    string org = "4-1 -> 3-1 -> 3-2 -> 3-3 -> 4-3 -> 5-3 -> 6-3";
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}


// TEST(q1, base) {
//     Transport_Layer_optimization obj;
//     obj.ReadFile("Q1T1.txt");
//     string result  =  obj.GetPath(1, 6);
//     string org = "1-1 -> 2-1 -> 3-1 -> 4-1 -> 4-2 -> 5-2 -> 6-2";
//     // for each pair the first value gives the location node id and the second value tells the current layer;
//     EXPECT_EQ(result, org);
// }
TEST(Q1, NotAgain)
{
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T5.txt");
    string result = obj.GetPath(1, 10);
    string org = "1-1 -> 2-1 -> 3-1 -> 3-2 -> 4-2 -> 5-2 -> 5-3 -> 6-3 -> 7-3 -> 8-3 -> 9-3 -> 10-3";
    EXPECT_EQ(result, org);
}


TEST(Q1, Nopes)
{
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T4.txt");
    string result = obj.GetPath(1, 9);
    string org = "1-3 -> 2-3 -> 3-3 -> 4-3 -> 5-3 -> 6-3 -> 7-3 -> 8-3 -> 8-2 -> 9-2";
    EXPECT_EQ(result, org);
}

TEST(Q1, Reverse)
{
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T7.txt");

    string result = obj.GetPath(8, 9);
    string org = "8-1 -> 7-1 -> 6-1 -> 5-1 -> 4-1 -> 3-1 -> 3-2 -> 3-3 -> 4-3 -> 5-3 -> 6-3 -> 7-3 -> 8-3 -> 9-3";
    EXPECT_EQ(result, org);
}
TEST(Q1, Ooops)
{
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result = obj.GetPath(1, 10);
    string org = "1-1 -> 2-1 -> 2-2 -> 2-3 -> 3-3 -> 4-3 -> 5-3 -> 6-3 -> 7-3 -> 7-2 -> 7-1 -> 8-1 -> 9-1 -> 10-1";
    EXPECT_EQ(result, org);
}

TEST(Q1, Crazy)
{
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result = obj.GetPath(1, 7);
    string org = "1-1 -> 2-1 -> 2-2 -> 2-3 -> 3-3 -> 4-3 -> 5-3 -> 6-3 -> 7-3";
    EXPECT_EQ(result, org);
}
TEST(Q1, BackForth)
{
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T6.txt");

    string result = obj.GetPath(1, 3);
    string org = "1-1 -> 1-2 -> 1-3 -> 2-3 -> 3-3";
    EXPECT_EQ(result, org);

    result = obj.GetPath(3, 1);
    org = "3-1 -> 4-1 -> 4-2 -> 4-3 -> 3-3 -> 2-3 -> 1-3";
    EXPECT_EQ(result, org);
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
