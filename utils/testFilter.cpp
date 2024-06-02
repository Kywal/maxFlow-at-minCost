#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "../model/network.cpp"
#include "../tests/TestsInput.cpp"
#include "../tests/TestsOutput.cpp"

using directory = std::filesystem::recursive_directory_iterator;
using namespace std;

int main() {

    TestsInput testIn;
    TestsOutput testOut;
    string folderPath = "Lemon_Dataset/";

    for(const auto& file : directory(folderPath)) {
        
        for (size_t i = 20; i <= 100; i = i + 20) {

            Network* graph = testIn.readGraphFile(file.path(), i);
            
            string filePath(file.path().filename());
            string graphFileName = "testCases/" + filePath + to_string(i) + ".txt";
            testOut.writeNetworkFile(graphFileName,*graph);
            graph = nullptr;
        }
     
    }

    return 0;
}