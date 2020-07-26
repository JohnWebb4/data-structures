#include <stdio.h>
#include <vector>

#include "./graphNode.h"

GraphNode::GraphNode(std::string id, int value)
{
  this->id = id;
  this->value = value;
}

GraphNode::~GraphNode()
{
  for (auto pair : this->edgesFrom)
  {
    delete pair.second;
  }

  for (auto pair : this->edgesTo)
  {
    delete pair.second;
  }
}

GraphEdge *GraphNode::getEdgeTo(std::string id)
{
  return this->edgesTo.at(id);
}

GraphEdge *GraphNode::getEdgeFrom(std::string id)
{
  return this->edgesFrom.at(id);
}

void GraphNode::addEdgeTo(GraphNode *to)
{
  return this->addEdgeTo(to, 1);
}

void GraphNode::addEdgeTo(GraphNode *to, int weight)
{
  GraphEdge *edge = new GraphEdge(to, weight);
  this->edgesTo.emplace(to->id, edge);
}

void GraphNode::addEdgeFrom(GraphNode *from)
{
  return this->addEdgeFrom(from, 1);
}

void GraphNode::addEdgeFrom(GraphNode *from, int weight)
{
  GraphEdge *edge = new GraphEdge(from, weight);
  this->edgesFrom.emplace(from->id, edge);
}

void GraphNode::removeEdgeTo(GraphNode *to)
{
  this->edgesTo.erase(to->id);
}

void GraphNode::removeEdgeFrom(GraphNode *from)
{
  this->edgesFrom.erase(from->id);
}
