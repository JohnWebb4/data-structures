#include <stdio.h>
#include <string>
#include <vector>

#ifndef GRAPHEDGE_H
#define GRAPHEDGE_H

class GraphNode;

class GraphEdge
{
public:
  GraphNode *node;
  int weight;

  GraphEdge(GraphNode *node, int weight);
};

#endif