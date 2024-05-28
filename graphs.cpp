#ifndef graphs
#define graphs

#include <vector>
#include <tuple>
#include <initializer_list>

template <typename nodeType, typename structureType>
class Graphs {

public:

    virtual bool addNode(nodeType newNode) = 0;
    virtual bool addEdge(nodeType node1, nodeType node2) = 0;
    virtual bool removeNode(nodeType node) = 0;
    virtual bool removeEdge(nodeType node1, nodeType node2) = 0;

    virtual nodeType find(nodeType node) = 0;

    virtual void createGraph(structureType graph) = 0;

    Graphs(structureType graphStructure);
    Graphs(std::initializer_list<std::initializer_list<nodeType>> graphList);
    Graphs();
    ~Graphs();
};

#endif