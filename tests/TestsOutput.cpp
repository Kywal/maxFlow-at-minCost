#include <iostream>
#include <fstream>
#include "../model/network.cpp"


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
        std::tuple<int,int,int>** adjMatrix = net.getMatrix();
        

        for (size_t src = 0; src < net.nodeAmount; src++) {
            for (size_t term = 0; term < net.nodeAmount; term++) {
                
                std::tuple<int,int,int> arc = adjMatrix[src][term];
                
                // if max flow is different of 0, add the arc
                if (std::get<1>(arc) != 0) {
                    int minFlow = std::get<0>(arc);
                    int maxFlow = std::get<1>(arc);
                    int cost = std::get<2>(arc);

                    stream << "a " << src+1 << " " << term+1 << " " << minFlow << " " << maxFlow << " " << cost << "\n"; 
                }
                
            }
        }
        
    }

    TestsOutput(/* args */){}
    ~TestsOutput(){}
};
