#include <iostream>
#include <vector>
#include <utility>

#include "../tests/TestsInput.cpp"
#include "../tests/TestsOutput.cpp"
#include "../model/network.cpp"
#include "../algorithm/maxFlow_minCost.h"
// #include "../algorithm/maxFlow_minCost.cpp"

using namespace std;


int main() {

    string file = "tests/test_input.txt";

    TestsInput testIn;
    TestsOutput testOut;
    Algorithm algorithm;

    Network* net = testIn.readGraphFile(file, 100);

    pair<int,int> result = algorithm.minCostMaxFlow(*net,net->source.first,net->terminal.first);

    cout << "maxFlow: " << result.first << "\n";
    cout << "minCost: " << result.second << "\n";

    return 0;
}