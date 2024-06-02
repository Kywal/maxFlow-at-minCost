
buildTestFilter: utils/testFilter.cpp model/network.cpp tests/TestsInput.cpp tests/TestsOutput.cpp
	g++ utils/testFilter.cpp model/network.cpp tests/TestsInput.cpp tests/TestsOutput.cpp -o testFilter.exe

execTestFilter:
	./testFilter.exe

clearTestCases:
	rm testCases/*.txt