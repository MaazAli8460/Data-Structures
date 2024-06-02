#include"gtest/gtest.h"
//#include "Header.h"
#include "Header2.h"


TEST(ZigzagIteratorTest, ZigzagIteration) {
    CustomQueue<int> q1, q2;

    // Populate the queues with test data
    q1.enqueue(1);
    q1.enqueue(2);
    q2.enqueue(3);
    q2.enqueue(4);
    q2.enqueue(5);
    q2.enqueue(6);

    ZigzagIterator<int> zigzag(q1, q2);

    int expected[] = { 1, 3, 2, 4, 5, 6 };

    int index = 0;
    while (zigzag.hasNext()) {
        int val = zigzag.next();
        if (val != -1) {
            EXPECT_EQ(val, expected[index]);
            index++;
        }
    }
}

TEST(ZigzagIteratorTest, EmptyQueues) {
    CustomQueue<int> q1, q2;

    ZigzagIterator<int> zigzag(q1, q2);

    // The queues are empty, so hasNext should return false
    EXPECT_FALSE(zigzag.hasNext());

    // Attempting to get the next element should return -1
    EXPECT_EQ(zigzag.next(), -1);
}

TEST(ZigzagIteratorTest, SingleQueue) {
    CustomQueue<int> q1;
    q1.enqueue(1);
    q1.enqueue(2);

    ZigzagIterator<int> zigzag(q1, q1);

    // The iterator should behave like a single queue
    int expected[] = { 1, 2 };

    int index = 0;
    while (zigzag.hasNext()) {
        int val = zigzag.next();
        if (val != -1) {
            EXPECT_EQ(val, expected[index]);
            index++;
        }
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
