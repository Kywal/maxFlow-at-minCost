#include <iostream>
#include "tests.cpp"

using namespace std;

int main() {

    Tests test;

    Network *graph = test.readGraphFile("test.txt");
    
    graph->printAdjMatrix();

    return 0;
}