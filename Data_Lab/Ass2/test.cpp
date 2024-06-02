// #include <gtest/gtest.h>

// #include "header.cpp"

// TEST(q2, t3) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(19, obj.GetMinCost(23, 17));
//   /* 23-3 -> 22-3 -> 21-3 -> 20-3 -> 19-3 -> 18-3 -> 17-3*/
// }
// TEST(q2, t4) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(1, obj.GetMinCost(1, 2));
//   /* 1-1 -> 2-1*/
// }
// TEST(q2, t5) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(33, obj.GetMinCost(23, 12));
//   /* 23-3 -> 22-3 -> 21-3 -> 20-3 -> 19-3 -> 18-3 -> 17-3 -> 16-3 -> 15-3 -> 14-3 -> 13-3 -> 12-3*/
// }
// TEST(q2, t6) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(14, obj.GetMinCost(12, 17));
//   /* 12-3 -> 13-3 -> 14-3 -> 15-3 -> 16-3 -> 17-3*/
// }
// TEST(q2, t7) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(1, obj.GetMinCost(11, 10));
//   /* 11-1 -> 10-1*/
// }
// TEST(q2, t8) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(45, obj.GetMinCost(7, 20));
//   /* 7-2 -> 8-2 -> 9-2 -> 10-2 -> 11-2 -> 12-2 -> 13-2 -> 13-3 -> 14-3 -> 15-3 -> 16-3 -> 17-3 -> 18-3 -> 18-2 -> 19-2 -> 20-2*/
// }
// TEST(q2, t9) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(70, obj.GetMinCost(26, 7));
//   /* 26-2 -> 25-2 -> 24-2 -> 23-2 -> 22-2 -> 21-2 -> 20-2 -> 19-2 -> 18-2 -> 18-3 -> 17-3 -> 16-3 -> 15-3 -> 14-3 -> 13-3 -> 13-2 -> 12-2 -> 11-2 -> 10-2 -> 9-2 -> 8-2 -> 7-2*/
// }
// TEST(q2, t10) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(76, obj.GetMinCost(1, 22));
//   /* 1-1 -> 2-1 -> 3-1 -> 3-2 -> 4-2 -> 5-2 -> 6-2 -> 7-2 -> 8-2 -> 9-2 -> 10-2 -> 11-2 -> 12-2 -> 13-2 -> 13-3 -> 14-3 -> 15-3 -> 16-3 -> 17-3 -> 18-3 -> 19-3 -> 20-3 -> 21-3 -> 22-3*/
// }
// TEST(q2, t11) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(10, obj.GetMinCost(13, 10));
//   /* 13-2 -> 12-2 -> 12-1 -> 11-1 -> 10-1*/
// }
// TEST(q2, t12) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(38, obj.GetMinCost(11, 22));
//   /* 11-3 -> 12-3 -> 13-3 -> 14-3 -> 15-3 -> 16-3 -> 17-3 -> 18-3 -> 19-3 -> 20-3 -> 21-3 -> 22-3*/
// }
// TEST(q2, t13) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(15, obj.GetMinCost(22, 17));
//   /* 22-3 -> 21-3 -> 20-3 -> 19-3 -> 18-3 -> 17-3*/
// }
// TEST(q2, t14) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(35, obj.GetMinCost(16, 25));
//   /* 16-3 -> 17-3 -> 18-3 -> 18-2 -> 19-2 -> 20-2 -> 21-2 -> 22-2 -> 23-2 -> 24-2 -> 25-2*/
// }
// TEST(q2, t15) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(14, obj.GetMinCost(19, 14));
//   /* 19-2 -> 18-2 -> 18-3 -> 17-3 -> 16-3 -> 15-3 -> 14-3*/
// }
// TEST(q2, t16) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(10, obj.GetMinCost(1, 4));
//   /* 1-1 -> 2-1 -> 3-1 -> 4-1*/
// }
// TEST(q2, t17) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(2, obj.GetMinCost(3, 2));
//   /* 3-1 -> 2-1*/
// }
// TEST(q2, t18) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(58, obj.GetMinCost(1, 16));
//   /* 1-1 -> 2-1 -> 3-1 -> 3-2 -> 4-2 -> 5-2 -> 6-2 -> 7-2 -> 8-2 -> 9-2 -> 10-2 -> 11-2 -> 12-2 -> 13-2 -> 13-3 -> 14-3 -> 15-3 -> 16-3*/
// }
// TEST(q2, t19) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(49, obj.GetMinCost(19, 6));
//   /* 19-2 -> 18-2 -> 18-3 -> 17-3 -> 16-3 -> 15-3 -> 14-3 -> 13-3 -> 13-2 -> 12-2 -> 11-2 -> 10-2 -> 9-2 -> 8-2 -> 7-2 -> 6-2*/
// }
// TEST(q2, t20) {
//   Transport_Cost_Calculator obj;
//   obj.ReadFile("Q2T2.txt");
//   EXPECT_EQ(58, obj.GetMinCost(4, 20));
//   /* 4-2 -> 5-2 -> 6-2 -> 7-2 -> 8-2 -> 9-2 -> 10-2 -> 11-2 -> 12-2 -> 13-2 -> 13-3 -> 14-3 -> 15-3 -> 16-3 -> 17-3 -> 18-3 -> 18-2 -> 19-2 -> 20-2*/
// }
// int main(int argc, char ** argv) {
//   testing::InitGoogleTest( & argc, argv);
//   return RUN_ALL_TESTS();
// }