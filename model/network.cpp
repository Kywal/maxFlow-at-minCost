#ifndef network
#define network

#include <tuple>
#include <iostream>

class Network {

typedef std::tuple<int,int,int,int> flow_min_max_cost;

private:
    flow_min_max_cost** adjMatrix;
    int* flowMatrix;

public:
    int nodeAmount = 0;
    int arcAmount = 0;
    std::pair<int,int> source, terminal; // <id,flow>

    flow_min_max_cost** getMatrix() const { return adjMatrix; }
    void setMatrix(flow_min_max_cost** matrix) {adjMatrix = matrix; } 

    int* getFlowMatrix() const {return flowMatrix; }
    void setFlowMatrix(int* flowMatrix) {this->flowMatrix = flowMatrix; }

    flow_min_max_cost addArc(int src, int dest, int min, int max, int cost) {
        return adjMatrix[src][dest] = {0, min, max, cost};     
    }

    flow_min_max_cost getArc(int src, int dest) { return adjMatrix[src][dest]; }

    void printAdjMatrix() {
        std::cout << "[" << std::endl;
        for (size_t i = 0; i < nodeAmount; i++) {
            for (size_t j = 0; j < nodeAmount; j++) {
                std::cout << "{" << std::get<0>(adjMatrix[i][j]) << "," << std::get<1>(adjMatrix[i][j]) << "," << std::get<2>(adjMatrix[i][j]) << "} ";
            }
            std::cout << std::endl;
        }
        std::cout << "]" << std::endl;
    }

    Network operator=(const Network &net) {
        this->adjMatrix = net.getMatrix();
        return *this;
    }

    Network(int nodeAmount, int arcAmount) {
        this->nodeAmount = nodeAmount;
        this->arcAmount = arcAmount;

        flowMatrix = new int[nodeAmount];
        adjMatrix = new flow_min_max_cost*[nodeAmount];
        for (size_t i = 0; i < nodeAmount; i++) {
            adjMatrix[i] = new flow_min_max_cost[nodeAmount];
            flowMatrix[i] = 0;
        }
        
    }

    ~Network() {
        for (size_t i = 0; i < nodeAmount; i++) {
            delete[] adjMatrix[i];
        }

        delete[] adjMatrix;
        delete[] flowMatrix;
    }

};

#endif