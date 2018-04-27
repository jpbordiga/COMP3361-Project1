/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jpbordiga
 *
 * Created on April 20, 2018, 4:26 PM
 */

using namespace std;
#include "ShortestProcessFirst.hpp"
#include "Process.hpp"
#include "SystemClock.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>

using std::cerr;
using std::cout;
using std::string;
using std::vector;

namespace {  // unnamed namespace
    // Convert bool to T/F
    static char BoolTF(bool x) { return x ? 'T' : 'F'; }
} // namespace

int main(int argc, char* argv[]) {
	
    std::fstream inputFile;
    float blockDuration = 5;
    float predictionWeight = 0.25;

    if (argc != 2) {
	std::cerr << "Usage: Program1 input_file\n";
	exit(1);
    }
        
    inputFile.open(argv[1], std::ios_base::in);

    if (!inputFile.is_open()) {
	std::cerr << "ERROR: failed to open input file: " << argv[1] << "\n";
	exit(2);
    }

    std::cout << argv[1] << " " << blockDuration << " " << predictionWeight << "\n";
    
	std::string currentLine;
	std::string processName;
	std::vector<Process> processList;
	float arrivalTime = 0;

	while (std::getline(inputFile, currentLine)) {

		std::istringstream sStream(currentLine);
		std::vector<float> runTimes;

		sStream >> processName;
		sStream >> arrivalTime;

		while (true) {

			if (sStream.eof()) {
				break;
			}
			else {

                            float runTime = 0;
                            sStream >> runTime;
                            runTimes.push_back(runTime);

			}

		}

		Process p(processName, arrivalTime, runTimes);
		processList.push_back(p);

	}

    ShortestProcessFirst sPF(blockDuration, predictionWeight, processList);
    
    return 0;
}

