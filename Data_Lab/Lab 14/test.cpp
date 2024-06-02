#include "pch.h"
#include "header.h"
#include <gtest/gtest.h>
//#include "Header1.h"

//---------------------------------------------------------
//Test Case for Matrix Implementation of Graph 
//----------------------------------------------------------

TEST(GraphTest, TestAddEdge)
{
	graph g(3);
	g.addEdge(0, 1);
	g.addEdge(1, 2);

	ASSERT_TRUE(g.isEdge(0, 1));
	ASSERT_TRUE(g.isEdge(1, 2));
	ASSERT_FALSE(g.isEdge(0, 2));
}

TEST(GraphTest, TestRemoveEdge)
{
	graph g(3);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.removeEdge(0, 1);

	ASSERT_FALSE(g.isEdge(0, 1));
	ASSERT_TRUE(g.isEdge(1, 2));
	ASSERT_FALSE(g.isEdge(0, 2));
}

TEST(GraphTest, TestDisplay)
{
	graph g(3);
	g.addEdge(0, 1);
	g.addEdge(1, 2);

	testing::internal::CaptureStdout();
	g.display();
	std::string output = testing::internal::GetCapturedStdout();

	// check if the output matches the expected result
	ASSERT_EQ(output, "0 1 0 \n0 0 1 \n0 0 0 \n\n");
}

//---------------------------------------------------------
//Test Case for Adjacency List Implementation of Graph 
//----------------------------------------------------------


TEST(GraphTest, GraphdisplayEmpty) {
	Graph g(5);
	std::stringstream buffer;
	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
	g.Graphdisplay();
	std::string output = buffer.str();
	ASSERT_EQ(output, "1\n2\n3\n4\n5\n");
	std::cout.rdbuf(old);
}

TEST(GraphTest, GraphdisplayNonEmpty) {
	Graph g(5);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 4);
	g.insertEdge(3, 5);
	std::stringstream buffer;
	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
	g.Graphdisplay();
	std::string output = buffer.str();
	ASSERT_EQ(output, "1->2->3\n2->4\n3->5\n4\n5\n");
	std::cout.rdbuf(old);
}



TEST(GraphTest, GraphdisplaySingleVertex) {
	Graph g(1);
	std::stringstream buffer;
	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
	g.Graphdisplay();
	std::string output = buffer.str();
	ASSERT_EQ(output, "1\n");
	std::cout.rdbuf(old);
}

TEST(GraphTest, GraphdisplayMultipleVertices) {
	Graph g(3);
	std::stringstream buffer;
	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
	g.Graphdisplay();
	std::string output = buffer.str();
	ASSERT_EQ(output, "1\n2\n3\n");
	std::cout.rdbuf(old);
}

TEST(GraphTest, insertEdge) {
	Graph g(5);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 4);
	g.insertEdge(3, 5);
	std::stringstream buffer;
	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
	g.Graphdisplay();
	std::string output = buffer.str();
	ASSERT_EQ(output, "1->2->3\n2->4\n3->5\n4\n5\n");
	std::cout.rdbuf(old);
}

// //Task 3

TEST(GraphTest, ConnectedGraph) {
	Graph graph(4);
	graph.insertEdge(1, 2);
	graph.insertEdge(2, 3);
      graph.insertEdge(3, 4);
	graph.insertEdge(4, 1);

	EXPECT_TRUE(graph.isConnected());
}


TEST(GraphTest, NotConnectedGraph) {
	Graph graph(5);
	graph.insertEdge(1, 2);
	graph.insertEdge(2, 3);
	graph.insertEdge(4, 5);

	EXPECT_FALSE(graph.isConnected());
}

TEST(GraphTest, NConnectedGraph) {
	Graph graph(5);
	graph.insertEdge(1, 2);
	graph.insertEdge(2, 1);
	graph.insertEdge(3, 4);
	graph.insertEdge(4, 3);

	EXPECT_FALSE(graph.isConnected());
}



int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
