#include <gtest/gtest.h>

#include "./graph.h"

TEST(GraphTest, CreateUndirected)
{
  Graph graph;

  GraphNode *node1 = graph.addNode("1", 1);
  ASSERT_EQ(node1->value, 1);

  GraphNode *node2 = graph.addNode("2", 2);
  ASSERT_EQ(node2->value, 2);

  graph.addEdge("1", "2");

  GraphEdge *edge1To2 = node1->getEdgeTo("2");
  ASSERT_EQ(edge1To2->node, node2);
  ASSERT_EQ(edge1To2->weight, 1);

  GraphEdge *edge2From1 = node2->getEdgeFrom("1");
  ASSERT_EQ(edge2From1->node, node1);
  ASSERT_EQ(edge2From1->weight, 1);

  GraphEdge *edge2To1 = node2->getEdgeTo("1");
  ASSERT_EQ(edge2To1->node, node1);
  ASSERT_EQ(edge2To1->weight, 1);

  GraphEdge *edge1From2 = node1->getEdgeFrom("2");
  ASSERT_EQ(edge1From2->node, node2);
  ASSERT_EQ(edge1From2->weight, 1);
}

TEST(GraphTest, RemoveUndirected)
{
  Graph graph;

  GraphNode *node1 = graph.addNode("1", 1);
  GraphNode *node2 = graph.addNode("2", 2);
  GraphNode *node3 = graph.addNode("3", 3);

  ASSERT_EQ(node1->value, 1);
  ASSERT_EQ(node2->value, 2);

  graph.addEdge("1", "2");
  GraphEdge *edge1To2 = node1->getEdgeTo("2");
  ASSERT_EQ(edge1To2->node, node2);

  graph.addEdge("1", "3");
  GraphEdge *edge1To3 = node1->getEdgeTo("3");
  ASSERT_EQ(edge1To3->node, node3);

  graph.removeEdge(node1, node2);
  ASSERT_THROW((void)node1->getEdgeTo("2"), std::out_of_range);

  graph.removeNode("2");
  ASSERT_THROW((void)graph.getNode("2"), std::out_of_range);

  ASSERT_THROW((void)node1->getEdgeTo("2"), std::out_of_range);
  ASSERT_EQ(node1->getEdgeTo("3"), edge1To3);

  graph.removeNode("1");
  ASSERT_THROW((void)graph.getNode("1"), std::out_of_range);

  ASSERT_THROW(graph.getNode("1"), std::out_of_range);

  ASSERT_EQ(graph.getNode("3"), node3);

  ASSERT_THROW((void)node3->getEdgeFrom("1"), std::out_of_range);
}
