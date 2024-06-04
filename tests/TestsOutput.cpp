#ifndef testsOut
#define testsOut

#include <iostream>
#include <fstream>
#include "../model/network.cpp"
#include "../model/arc.h"

class TestsOutput {

typedef std::string string;

private:
    /* data */
public:
    
    void writeNetworkFile(string fileName, Network &net) {
        string netFile;
        std::ofstream fileStream;
        fileStream.open(fileName);

        string c_Description = "c subgraph filtered from lemon database's graphs\n";
        string c_End_of_File = "c End of File\n";

        if(fileStream.is_open()) {

            fileStream << c_Description;
            writeProblem(fileStream, net);
            writeSourceAndTerminal(fileStream, net);
            writeArc(fileStream, net);
            fileStream << "c\n";
            fileStream << c_End_of_File;
            fileStream.close();
        } else {
            std::cout << "Não foi possivel abrir o arquivo :/\n";
        }     

    }

    void writeProblem(std::ofstream &stream, Network &net) {
        stream << "p min " << net.nodeAmount  << " " << net.arcAmount << "\n";
    }
    
    void writeSourceAndTerminal(std::ofstream &stream, Network &net){
        stream << "n " << net.source.first+1 << " " << net.source.second << "\n";
        stream << "n " << net.terminal.first+1 << " " << net.terminal.second << "\n";
    }

    void writeArc(std::ofstream &stream, Network &net) {
        Arc** adjMatrix = net.getMatrix();
        

        for (size_t src = 0; src < net.nodeAmount; src++) {
            for (size_t term = 0; term < net.nodeAmount; term++) {
                
                Arc arcNet = adjMatrix[src][term];
                
                if(arcNet.exists == 1) {
                    int minFlow = arcNet.minCap;
                    int maxFlow = arcNet.maxCap;
                    int cost = arcNet.cost;

                    stream << "a " << src+1 << " " << term+1 << " " << minFlow << " " << maxFlow << " " << cost << "\n"; 
                }
                
            }
        }
        
    }

    TestsOutput(/* args */){}
    ~TestsOutput(){}
};

#endif