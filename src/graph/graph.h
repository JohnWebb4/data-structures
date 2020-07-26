#include <stdio.h>
#include <string>
#include <unordered_map>

#include "./graphEdge.h"
#include "./graphNode.h"

#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
public:
  Graph();
  Graph(bool isDirectional);
  ~Graph();
  GraphNode *getNode(std::string id);
  GraphNode *addNode(std::string id, int value);
  void removeNode(std::string id);
  void removeNode(GraphNode *node);
  void addEdge(std::string from, std::string to);
  void addEdge(std::string from, std::string to, int weight);
  void addEdge(GraphNode *fromNode, GraphNode *toNode, int weight);
  void removeEdge(std::string from, std::string to);
  void removeEdge(GraphNode *fromNode, GraphNode *toNode);

private:
  bool isDirectional;
  std::unordered_map<std::string, GraphNode *> nodes;
};

#endif