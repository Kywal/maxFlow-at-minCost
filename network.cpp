#ifndef network
#define network

#include <utility>

class Network {

typedef std::pair<int,int> cap_cost;

private:
    cap_cost** adjacencyMatrix;

public:
    int nodeAmount = 0;
    int arcAmount = 0;
    std::pair<int,int> source, terminal; // <id,flow>
        
    cap_cost addArc(int src, int dest, int capacity, int cost) {
        return adjacencyMatrix[src][dest] = {capacity, cost};     
    }

    Network(int nodeAmount, int arcAmount) {
        this->nodeAmount = nodeAmount;
        this->arcAmount = arcAmount;

        adjacencyMatrix = new cap_cost*[nodeAmount];
    }

    ~Network() {
        delete []* adjacencyMatrix;
    }

};

#endif