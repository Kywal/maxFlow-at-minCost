#ifndef tests
#define tests

#include <string>
#include <fstream>
#include <iostream>
#include "../model/network.cpp"

class TestsInput {

typedef std::string string;

private:

public:

    Network* readGraphFile(string filePath, int maxNodeAmount) {
        char character;
        string line;
        Network* graph;

        std::ifstream testCase(filePath);

        if (testCase.is_open()) {
            
            while ( testCase ) {
                character = testCase.get();
            
                switch(character) {
                    
                    // Comment Lines
                    case 'c':
                        readComment(testCase);
                        break;
                    
                    // Problem line
                    case  'p':
                        graph = readProblem(testCase, graph, maxNodeAmount);
                        break;
                    
                    // Node Descriptors
                    case 'n':
                        readSourceAndTerminal(testCase, graph, maxNodeAmount);
                        break;

                    // Arc Descriptors
                    case 'a':
                        readArc(testCase, graph, maxNodeAmount);
                        break;
            
                    default:
                        if(testCase.eof()) {
                            std::cout << "End-Of-File reached" << std::endl;
                        } else {
                            std::cout << "Character not recognized by the DIMACs standard" << std::endl;                        
                        }
                        break;
                }    
            }

        }

        return graph;
    }

    void readComment(std::ifstream &stream){
        string comment;
        captureBlankSpace(stream);
        
        std::getline(stream, comment);

        std::cout << comment << std::endl;
    }

    Network* readProblem(std::ifstream &stream, Network* graph, int maxNodeAmount){
        string problemTitle,nodeAmount, arcAmount;
        captureBlankSpace(stream);
        std::getline(stream, problemTitle, ' ');

        std::getline(stream, nodeAmount, ' ');
        std::getline(stream, arcAmount, '\n');

        int safeNodeAmount = stoi(nodeAmount) > maxNodeAmount ? maxNodeAmount : stoi(nodeAmount); 

        return graph = new Network(safeNodeAmount,stoi(arcAmount));
    }

    void readSourceAndTerminal(std::ifstream &stream, Network* graph, int maxNodeAmount){
        string sourceID, sourceFlow, terminalID, terminalFlow;
        captureBlankSpace(stream);

        // source
        std::getline(stream, sourceID, ' ');
        graph->source.first = stoi(sourceID)-1;
        if(graph->source.first > maxNodeAmount) throw 101;

        std::getline(stream, sourceFlow, '\n');
        graph->source.second =  stoi(sourceFlow);        

        // terminal
        captureBlankSpace(stream);
        captureBlankSpace(stream);    

        std::getline(stream, terminalID, ' ');
        graph->terminal.first = stoi(terminalID)-1;
        if(graph->terminal.first > maxNodeAmount) throw 101;

        std::getline(stream, sourceFlow, '\n');
        graph->terminal.second =  stoi(sourceFlow);
    }

    void readArc(std::ifstream &stream, Network* graph, int maxNodeAmount){
        string src, term, min, max, cost;
        captureBlankSpace(stream);

        std::getline(stream, src, ' ');
        std::getline(stream, term, ' ');
        std::getline(stream, min, ' ');
        std::getline(stream, max, ' ');
        std::getline(stream, cost, '\n');

        int sourceId = stoi(src);
        int terminalId = stoi(term);

        if(sourceId <= maxNodeAmount && terminalId <= maxNodeAmount) {
            graph->addArc(sourceId-1,terminalId-1,stoi(min),stoi(max),stoi(cost));
        }
    }

    void captureBlankSpace(std::ifstream &stream){
        stream.get();
    }

    TestsInput(){};
    ~TestsInput(){};
};

#endif