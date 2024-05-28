#ifndef graphs
#define graphs

#include <vector>
#include <tuple>


template <typename nodeType, typename structureType>
class Graphs {

private:
public:
    
    structureType graph;

    bool addNode(nodeType newNode) = 0;
    bool addEdge(nodeType node1, nodeType node2) = 0;
    bool removeNode(nodeType node) = 0;
    bool removeEdge(nodeType node1, nodeType node2) = 0;

    void createGraph(structureType graph) = 0;

    Graphs();
    ~Graphs();
};

#endif