#ifndef maxFlow_minFlow
#define maxFLOW_minFLOW

#include <utility>
#include <vector>
#include <climits>

#include "../model/network.cpp"

using namespace std;

extern const int INF;

extern vector<int> distance;

class Algorithm {

    public:

    pair<int,int> minCostMaxFlow(Network &net, int source, int terminal);
    
    pair<vector<int>, vector<int>> bellmanFord(Network &net, int source);

    Network initializeResidualGraph(Network &net);
};

#endif