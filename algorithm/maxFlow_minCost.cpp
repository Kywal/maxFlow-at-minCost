

#include <tuple>
#include <climits>
#include <vector>

#include "maxFlow_minCost.h"
#include "../model/network.cpp"
#include "../model/arc.h"

using namespace std;

const int INF = (INT_MAX-1)/2;

pair<int,int> Algorithm::minCostMaxFlow(Network &net, int source, int terminal) {
    int maxFlow = 0, minCost = 0;

    Network residualGraph = initializeResidualGraph(net);
    
    for (int i = 0; i < net.nodeAmount - 1; i++) {
        pair<vector<int>, vector<int>> pair_dist_pred = bellmanFord(residualGraph, residualGraph.source.first);
        
        vector<int> distance = pair_dist_pred.first;
        vector<int> predecessor = pair_dist_pred.second;

        int flow = INF;
        int v = terminal;

        while (v != source) {
            int u = predecessor[v];
            
            Arc u_To_v = residualGraph.getArc(u,v);

            flow = min(flow, u_To_v.maxCap);
            v = u;
        }

        v = terminal;
        while (v != source) {
            int u = predecessor[v];

            Arc u_To_v = residualGraph.getArc(u,v);
            residualGraph.setArc(u, v, u_To_v.flow, u_To_v.minCap, u_To_v.maxCap - flow, u_To_v.cost);            

            Arc v_To_u = residualGraph.getArc(v,u);
            residualGraph.setArc(v, u, v_To_u.flow, v_To_u.minCap, v_To_u.maxCap + flow, v_To_u.cost);

            v = u;
        }

        
        maxFlow += flow;
        minCost += flow * distance[terminal];
    }

    return {maxFlow, minCost};
}

pair<vector<int>, vector<int>> Algorithm::bellmanFord(Network &net, int source) {
    int sourceID = net.source.first;
    int terminalID = net.terminal.first;
    
    vector<int> distance(net.nodeAmount, INF);
    vector<int> predecessor(net.nodeAmount, -1);

    distance[sourceID] = 0;

    for (int k = 0; k < net.nodeAmount - 1; k++) {

        for (int u = 0; u < net.nodeAmount; u++) {
            for (int v = 0; v < net.nodeAmount; v++) {
                Arc u_To_v = net.getArc(u,v);

                if (u_To_v.exists == 1) {
                    
                    if(distance[u] + u_To_v.cost < distance[v]) {
                        distance[v] = distance[u] + u_To_v.cost;
                        predecessor[v] = u;
                    }
                }
            }
        }

    }
    
     for (int u = 0; u < net.nodeAmount; u++) {
            for (int v = 0; v < net.nodeAmount; v++) {
                Arc u_To_v = net.getArc(u,v);

                if(u_To_v.exists) {
                    if(distance[u] + u_To_v.cost < distance[v])
                        throw "Network contains a negative cost cycle!\n";
                }   
            }
     }

        
    return {distance, predecessor};
}

Network Algorithm::initializeResidualGraph(Network &net) {
    Network residualGraph = net;
    for (int i = 0; i < residualGraph.nodeAmount; i++) {
        for (int j = 0; j < residualGraph.nodeAmount; j++) {
            
            Arc directArc = residualGraph.getArc(i,j);
            Arc invArc = residualGraph.getArc(j,i);
    
            if(invArc.exists == 1) {
                // set invArc cap to 0 and cost to -cost of direct arc 
                residualGraph.setArc(j, i,invArc.flow, invArc.minCap, 0, -directArc.cost);
            }
        }   
    }
    
    return residualGraph;
}