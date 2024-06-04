
buildTestFilter: utils/testFilter.cpp model/network.cpp tests/TestsInput.cpp tests/TestsOutput.cpp model/arc.cpp
	g++ utils/testFilter.cpp model/network.cpp tests/TestsInput.cpp tests/TestsOutput.cpp model/arc.cpp -o testFilter.exe

execTestFilter:
	./testFilter.exe

clearTestCases:
	rm testCases/*.txt

buildMaxMin: view/interface.cpp model/network.cpp tests/TestsInput.cpp tests/TestsOutput.cpp algorithm/maxFlow_minCost.cpp model/arc.cpp
	g++ view/interface.cpp model/network.cpp tests/TestsInput.cpp tests/TestsOutput.cpp algorithm/maxFlow_minCost.cpp model/arc.cpp -o ui.exe

execMaxMin:
	./ui.exe