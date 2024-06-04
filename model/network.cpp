#ifndef network
#define network

#include <tuple>
#include <iostream>
#include "arc.h"

class Network {

private:
    Arc** adjMatrix;
    int* flowMatrix;

public:
    int nodeAmount = 0;
    int arcAmount = 0;
    std::pair<int,int> source, terminal; // <id,flow>

    Arc** getMatrix() const { return adjMatrix; }
    void setMatrix(Arc** matrix) {adjMatrix = matrix; } 

    int* getFlowMatrix() const {return flowMatrix; }
    void setFlowMatrix(int* flowMatrix) {this->flowMatrix = flowMatrix; }

    Arc addArc(int src, int dest, int min, int max, int cost) {
        return adjMatrix[src][dest] = Arc(1, min, max, cost);     
    }

    Arc getArc(int src, int dest) { return adjMatrix[src][dest]; }
    Arc setArc(int src, int dest, int flow, int min, int max, int cost) {
        return adjMatrix[src][dest] = Arc(1, flow, min, max, cost);
    }

    void printAdjMatrix() {
        std::cout << "[" << std::endl;
        for (size_t i = 0; i < nodeAmount; i++) {
            for (size_t j = 0; j < nodeAmount; j++) {
                std::cout << " ";
                std::cout << adjMatrix[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << "]" << std::endl;
    }

    Network operator=(const Network &net) {
        this->adjMatrix = net.getMatrix();
        this->nodeAmount = net.nodeAmount;
        this->arcAmount = net.arcAmount;
        this->source = net.source;
        this->terminal = net.terminal;

        return *this;
    }

    Network(int nodeAmount, int arcAmount) {
        this->nodeAmount = nodeAmount;
        this->arcAmount = arcAmount;

        flowMatrix = new int[nodeAmount];
        adjMatrix = new Arc*[nodeAmount];
        for (size_t i = 0; i < nodeAmount; i++) {
            adjMatrix[i] = new Arc[nodeAmount];
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