#include <stdio.h>
#include <vector>

#include "./graph.h"

Graph::Graph() : Graph(false)
{
}

Graph::Graph(bool isDirectional)
{
  this->isDirectional = isDirectional;
}

Graph::~Graph()
{
  for (auto pair : this->nodes)
  {
    delete pair.second;
  }
}

GraphNode *Graph::getNode(std::string id)
{
  return this->nodes.at(id);
}

GraphNode *Graph::addNode(std::string id, int value)
{
  GraphNode *node = new GraphNode(id, value);
  this->nodes.emplace(id, node);
  return node;
}

void Graph::removeNode(std::string id)
{
  GraphNode *node = this->getNode(id);
  this->removeNode(node);
}

void Graph::removeNode(GraphNode *node)
{
  if (node != nullptr)
  {
    for (auto pair : node->edgesTo)
    {
      pair.second->node->removeEdgeFrom(node);
    }

    this->nodes.erase(node->id);
    delete node;
  }
  else
  {
    throw std::invalid_argument("Cannot remove node");
  }
}

void Graph::addEdge(std::string from, std::string to)
{
  return this->addEdge(from, to, 1);
}

void Graph::addEdge(std::string from, std::string to, int weight)
{
  GraphNode *fromNode = this->getNode(from);
  GraphNode *toNode = this->getNode(to);

  return this->addEdge(fromNode, toNode, weight);
}

void Graph::addEdge(GraphNode *fromNode, GraphNode *toNode, int weight)
{
  if (fromNode != nullptr && toNode != nullptr)
  {
    fromNode->addEdgeTo(toNode, weight);
    toNode->addEdgeFrom(fromNode, weight);

    if (!this->isDirectional)
    {
      fromNode->addEdgeFrom(toNode, weight);
      toNode->addEdgeTo(fromNode, weight);
    }
  }
  else
  {
    if (fromNode == nullptr)
    {
      throw std::invalid_argument("Cannot add edge with invalid from node");
    }
    else if (toNode == nullptr)
    {
      throw std::invalid_argument("Cannot add edge with invalid to node");
    }
  }
}

void Graph::removeEdge(std::string from, std::string to)
{
  GraphNode *fromNode = this->getNode(from);
  GraphNode *toNode = this->getNode(to);

  this->removeEdge(fromNode, toNode);
}

void Graph::removeEdge(GraphNode *fromNode, GraphNode *toNode)
{
  if (fromNode != nullptr && toNode != nullptr)
  {
    fromNode->removeEdgeTo(toNode);
    toNode->removeEdgeFrom(fromNode);

    if (this->isDirectional)
    {
      fromNode->removeEdgeFrom(toNode);
      toNode->removeEdgeTo(fromNode);
    }
  }
  else
  {
    if (fromNode == nullptr)
    {
      throw std::invalid_argument("Cannot remove edge with invalid from node");
    }
    else if (toNode == nullptr)
    {
      throw std::invalid_argument("Cannot remove edge with invalid to node");
    }
  }
}
