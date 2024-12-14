#include "UGraph.h"

UGraph::UGraph(){
    m_size = 0;
    m_adj = NULL;
}

UGraph::UGraph(unsigned int size){
    m_size = size;
    m_adj = new VertexID*[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_adj[i] = new VertexID[m_size];
        for (int j = 0; j < m_size; ++j) {
            m_adj[i][j] = 0U; // Just tells us to treat it as an unsigned int
        }
    }
}

UGraph::~UGraph(){
    for (int i = 0; i < m_size; ++i) {
        delete m_adj[i];
    }
    delete m_adj;
}

bool UGraph::areAdjacent(VertexID i, VertexID j) {
    bool ret = false;
    if (i < m_size && j < m_size) {
        ret = (m_adj[i][j] > 0);
    } 
    return false;
}

void UGraph::addEdge(VertexID i, VertexID j) {
    if (i < m_size && j < m_size) {
       m_adj[i][j] = 1U;
       m_adj[j][i] = 1U;
    } 
}

void UGraph::removeEdge(VertexID i, VertexID j){
    if (i < m_size && j < m_size) {
       m_adj[i][j] = 1U;
       m_adj[j][i] = 1U;
    } 
}

unsigned int UGraph::getSize() {
    return m_size;
}

// checks a vertex, then checks its adjecent ones, so on and so forth
// the farthest ones are traveresed too last but checked first
void UGraph::printDFS(VertexID i) {
    stack<VertexID> fringe;
    set<VertexID> visited;
    fringe.push(i);
    while(fringe.size()> 0 && visited.size() < m_size) {
        VertexID current = fringe.top();
        cout << current << endl;
        fringe.pop();
        visited.insert(current);
        for (unsigned int k = 0; k < m_size; ++k) {
            if (m_adj[current][k] > 0 && visited.count(k) == 0) {
                fringe.push(k);
            }
        }
    }
}

// same stuff as BSF but the closest are both traversed first and checked first
void UGraph::printBFS(VertexID i) {
    deque<VertexID> fringe;
    set<VertexID> visited;
    fringe.push_back(i);
    while(fringe.size()> 0 && visited.size() < m_size) {
        VertexID current = fringe.front();
        cout << current << endl;
        fringe.pop_front();
        visited.insert(current);
        for (unsigned int k = 0; k < m_size; ++k) {
            if (m_adj[current][k] > 0 && visited.count(k) == 0 && !contains(&fringe, k)) {
                fringe.push_front(k);
            }
        }
    }
}

bool UGraph::contains(deque<VertexID>* queue, VertexID vi) {
    for (int i = 0; i < queue->size(); ++i) {
        if (queue->at(i)==vi) {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    UGraph myGraph(4);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(0,0);
    return 0;
}
