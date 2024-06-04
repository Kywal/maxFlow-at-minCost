
#include "arc.h"

Arc::Arc(int exists, int flow, int minCap, int maxCap, int cost) {
    this->exists = exists;
    this->flow = flow;
    this->minCap = minCap;
    this->maxCap = maxCap;
    this->cost = cost;
}

Arc::Arc(int exists, int minCap, int maxCap, int cost) {
    this->exists = exists;
    this->flow = 0;
    this->minCap = minCap;
    this->maxCap = maxCap;
    this->cost = cost;
}

Arc::Arc(){}
Arc::~Arc(){}


ostream& operator<<(ostream& os, const Arc& a){
    os << "{" << a.exists << "," << a.flow << "," << a.minCap << "," << a.maxCap << "," << a.cost << "}";
    return os;
}
