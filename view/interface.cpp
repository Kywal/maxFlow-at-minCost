#include <iostream>
#include "TestsInput.cpp"
#include "model/network.cpp"

using namespace std;

int main() {

    TestsInput test;

    Network *graph = test.readGraphFile("test.txt",100);
    
    graph->printAdjMatrix();

    return 0;
}