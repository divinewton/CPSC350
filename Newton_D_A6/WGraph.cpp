/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA6 - Spanning the Gamut (Kruskal’s Algorithm)
*/

#include "WGraph.h"
#include <set>
#include <queue>
#include <limits>
#include "PQueue.h"

// default constructor initializes variables to default values
WGraph::WGraph() {
  m_size = 0;
  m_adj = NULL;
}

// overloaded constructor initializes adjacency matrix and connectivity matrix
// takes in the size of the graph
WGraph::WGraph(unsigned int sz) {
  m_size = sz;
  // allocate sz * sz adjacency matrix
  m_adj = new double*[sz];
  m_conn = new double*[sz];
  for (int i = 0; i < m_size; ++i) {
    m_adj[i] = new double[sz]; // memory for each row
    m_conn[i] = new double[sz]; // memory for each row
  }
  // initialize each edge with maximum value (double)
  for (int i = 0; i < m_size; ++i) {
    for (int j = 0; j < m_size; ++j) {
      m_adj[i][j] = std::numeric_limits<double>::max(); // set edge weights to max
      m_conn[i][j] = std::numeric_limits<double>::max(); // set connectivity weights to max
    }
  }
}

// destructor
WGraph::~WGraph() {
  for (int i = 0; i < m_size; ++i) { // delete each row
    delete[] m_adj[i];
    delete[] m_conn[i];
  }
  delete[] m_adj; // delete array of pointers
  delete[] m_conn;
}

// addEdge method takes in the vertices and width of an edge and adds it to the graph
void WGraph::addEdge(VertexID i, VertexID j, double w) {
  if (i < m_size && j < m_size) { // Check if vertices are in bounds
    m_adj[i][j] = w; // set the edge weight
    m_adj[j][i] = w;
  }
}

// removeEdge method takes vertices of edge and removes it from the graph
void WGraph::removeEdge(VertexID i, VertexID j) {
  if (i < m_size && j < m_size) { // check if vertices are in bounds
    m_adj[i][j] = std::numeric_limits<double>::max(); // remove edge by setting weight to max value
    m_adj[j][i] = std::numeric_limits<double>::max();
  }
}

// areAdjacent method takes in two vertices and checks if they are adjacent (edge between them)
// returns true or false boolean
bool WGraph::areAdjacent(VertexID i, VertexID j) {
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}

// cheapestCost method takes in two vertices and find the cheapest cost betwen then
// returns a double representing that cost
double WGraph::cheapestCost(VertexID i, VertexID j) {
  return m_conn[i][j];
}

// getEdges method uses a priority queue to store the edges of the graph
// method returns the priority queue of vectors representing the edges of the graph
PQueue<std::vector<double>> WGraph::getEdges() {
  PQueue<std::vector<double>> edges(false);
  for (int i = 0; i < m_size; ++i) {
    for (int j = i + 1; j < m_size; ++j) {
      if (i < m_size && j < m_size && areAdjacent(i, j)) { // check if vertices are in bounds and if they are adjacent
        edges.add({-m_adj[i][j], static_cast<double>(i), static_cast<double>(j)}); // use negative weight for min-heap
      }
    }
  }
  return edges; // return the priority queue of edges
}

// findSet method takes in v and parent variables
// returns an unsigned int representing the root of the set
unsigned int WGraph::findSet(unsigned int v, unsigned int* parent) {
  if (v != parent[v]) { // check if v is not the root
    parent[v] = findSet(parent[v], parent);
  }
  return parent[v];
}

// unionSets method unions the sets of u and v
// method takes in u, v, parent, and rank variables
// calls findSet method to assist with finding the roots
void WGraph::unionSets(unsigned int u, unsigned int v, unsigned int* parent, unsigned int* rank) {
  u = findSet(u, parent);
  v = findSet(v, parent);
  if (u != v) { // if u and v are in different sets
    if (rank[u] < rank[v]) {
      std::swap(u, v); // ensure that u has higher rank
    }
    parent[v] = u; // make u the parent of v
    if (rank[u] == rank[v]) { // if the ranks are equal
      ++rank[u];
    }
  }
}

// compute MST method returns a double representing the MST of the graph
// the method calls getEdges and then uses a set to store computed MST
double WGraph::computeMST() {
  double mstCost = 0.0; // tnitialize MST cost to 0.0
  PQueue<std::vector<double>> edges = getEdges(); // calls getEdges to get all edges in the graph

  unsigned int* parent = new unsigned int[m_size]; // array to store parent of each vertex
  unsigned int* rank = new unsigned int[m_size](); // array to store rank of each vertex
  for (int i = 0; i < m_size; ++i) {
    parent[i] = i; // initialize each vertex as its own parent
  }
  std::set<std::vector<VertexID>> mstEdges; // set used to store MST edges

  while (!edges.isEmpty()) {
    auto edge = edges.peek(); // get first edge from min queue
    edges.remove();
    double weight = -edge[0]; // convert back to positive weight
    VertexID u = static_cast<VertexID>(edge[1]); // first vertex of the edge
    VertexID v = static_cast<VertexID>(edge[2]); // second vertex of the edge
    if (findSet(u, parent) != findSet(v, parent)) { // check if u and v are in different sets
      mstCost += weight; // add the weight to the MST cost variable
      unionSets(u, v, parent, rank); // union the sets of u and v
      mstEdges.insert({u, v}); // add the edge to the MST
      mstEdges.insert({v, u});
      m_conn[u][v] = weight; // update the connectivity matrix for the MST
      m_conn[v][u] = weight;
    }
  }
  delete[] parent;
  delete[] rank;
  return mstCost; // return the cost of the MST
}

// printMST method prints the connectivity matrix to the console
void WGraph::printMST() {
  for (int i = 0; i < m_size; ++i) {
    for (int j = 0; j < m_size; ++j) {
      if (m_conn[i][j] == std::numeric_limits<double>::max()) { // if there is no edge prints 0.0
        std::cout << "0.0 ";
      } else { // if there is an edge prints its weight
        std::cout << cheapestCost(i, j) << ".0 ";
      }
    }
    std::cout << std::endl;
  }
}