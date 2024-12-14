#ifndef UGRAPH_H
#define UGRAPH_H

#include <cstdlib>
#include <iostream>
#include <deque>
#include <stack>
#include <set>

using namespace std;

typedef unsigned int VertexID; //just syntax stuff so we don't have to retype 

class UGraph
{
private:
    VertexID** m_adj; // adjecency matrix
    unsigned int m_size;
    bool contains(deque<VertexID>* queue, VertexID vi);
public:
    UGraph();
    UGraph(unsigned int size);
    virtual ~UGraph();
    bool areAdjacent(VertexID i, VertexID j);
    void addEdge(VertexID i, VertexID j);
    void removeEdge(VertexID i, VertexID j);
    unsigned int getSize();
    void printDFS(VertexID i);
    void printBFS(VertexID i);

};



#endif