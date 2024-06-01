#ifndef tests
#define tests

#include <string>
#include <fstream>
#include <iostream>
#include "network.cpp"

class Tests {

typedef std::string string;

private:

public:

    Network* readGraphFile(string filePath) {
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
                        graph = readProblem(testCase, graph);
                        break;
                    
                    // Node Descriptors
                    case 'n':
                        readSourceAndTerminal(testCase, graph);
                        break;

                    // Arc Descriptors
                    case 'a':
                        readArc(testCase, graph);
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

    Network* readProblem(std::ifstream &stream, Network* graph){
        string problemTitle,nodeAmount, arcAmount;
        captureBlankSpace(stream);
        std::getline(stream, problemTitle, ' ');

        std::getline(stream, nodeAmount, ' ');
        std::getline(stream, arcAmount, '\n');

        return graph = new Network(stoi(nodeAmount),stoi(arcAmount));
    }

    void readSourceAndTerminal(std::ifstream &stream, Network* graph){
        string sourceID, sourceFlow, terminalID, terminalFlow;
        captureBlankSpace(stream);

        // source
        std::getline(stream, sourceID, ' ');
        graph->source.first = stoi(sourceID)-1;


        std::getline(stream, sourceFlow, '\n');
        graph->source.second =  stoi(sourceFlow);        

        // terminal
        captureBlankSpace(stream);
        captureBlankSpace(stream);    

        std::getline(stream, terminalID, ' ');
        graph->terminal.first = stoi(terminalID)-1;

        std::getline(stream, sourceFlow, '\n');
        graph->terminal.second =  stoi(sourceFlow);
    }

    void readArc(std::ifstream &stream, Network* graph){
        string src, term, min, max, cost;
        captureBlankSpace(stream);

        std::getline(stream, src, ' ');
        std::getline(stream, term, ' ');
        std::getline(stream, min, ' ');
        std::getline(stream, max, ' ');
        std::getline(stream, cost, '\n');

        graph->addArc(stoi(src)-1,stoi(term)-1,stoi(min),stoi(max),stoi(cost));
    }

    void captureBlankSpace(std::ifstream &stream){
        stream.get();
    }

    Tests(){};
    ~Tests(){};
};

#endif