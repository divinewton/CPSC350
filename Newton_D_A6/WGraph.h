/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA6 - Spanning the Gamut (Kruskal’s Algorithm)
*/

#ifndef WGraph_H
#define WGraph_H

#include <cstdlib>
#include <set>
#include <iostream>
#include <queue>
#include <utility>
#include "PQueue.h"

typedef unsigned int VertexID;

// defines the WGraph class for a weighted, undirected, fixed size graph implemented with an adjacency matrix
// initial code from CPSC350 class, additional methods included
// class includes default and overloaded constructors, destructor, addEdge, removeEdge, areAdjacent, cheapestCost, computeMST and printMST public methods
// also includes private m_adj, m_conn, m_size variables and getEdges, findSet, and unionSets methods
class WGraph {
public:
  WGraph();
  WGraph(unsigned int sz);
  ~WGraph();
  void addEdge(VertexID i, VertexID j, double w);
  void removeEdge(VertexID i, VertexID j);
  bool areAdjacent(VertexID i, VertexID j);
  double cheapestCost(VertexID i, VertexID j);
  double computeMST();
  void printMST();

private:
  double** m_adj; // adjacency matrix for the graph
  double** m_conn; // connection matrix for the MST
  unsigned int m_size; // number of nodes in the graph

  PQueue<std::vector<double>> getEdges(); // get all edges in the graph
  unsigned int findSet(unsigned int v, unsigned int* parent); // find the set of vertex v
  void unionSets(unsigned int u, unsigned int v, unsigned int* parent, unsigned int* rank); // union the sets of vertices u and v
};

#endif