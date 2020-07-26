#include <stdio.h>

#include "./graphEdge.h"

GraphEdge::GraphEdge(GraphNode *node, int weight)
{
  this->node = node;
  this->weight = weight;
}