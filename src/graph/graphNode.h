#include <string>
#include <unordered_map>

#include "./graphEdge.h"

#ifndef GRAPHNODE_H
#define GRAPHNODE_H

class GraphNode
{
public:
  std::string id;
  int value;
  /* Edges that start with current node and end with another node */
  std::unordered_map<std::string, GraphEdge *> edgesTo;

  /* Edges that start at another node and end with current node */
  std::unordered_map<std::string, GraphEdge *> edgesFrom;

  GraphNode(std::string id, int value);
  ~GraphNode();
  GraphEdge *getEdgeTo(std::string id);
  GraphEdge *getEdgeFrom(std::string id);
  void addEdgeTo(GraphNode *to);
  void addEdgeTo(GraphNode *to, int weight);
  void addEdgeFrom(GraphNode *from);
  void addEdgeFrom(GraphNode *from, int weight);
  void removeEdgeTo(GraphNode *to);
  void removeEdgeFrom(GraphNode *from);
};

#endif