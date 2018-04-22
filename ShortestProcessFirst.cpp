#include "ShortestProcessFirst.hpp"
#include "SystemClock.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using std::cerr;


ShortestProcessFirst::ShortestProcessFirst(float bD, float pW, std::vector<Process> processList) {

	blockDuration = bD;
	predictionWeight = pW;
	float currentPredictionValue = 0;
	

	std::cout << blockDuration << "\n";
	std::cout << predictionWeight << "\n";
	
	SystemClock *sC = new SystemClock();

	std::vector<Process> runningProcesses; // should only have the current process due to copy/move being forbidden

	getReadyProcessList().reserve(processList.size());
	getReadyProcessList().resize(processList.size());

	while (true) {
	
		std::cout << processList.size() << " ***\n";

		// check for arrival of new jobs

		for (int i = 0; i < processList.size(); ++i) {
		
			if (sC->getTime() == processList.at(i).getArrivalTime()) {
				
				std::cout << processList[i].getProcessName() << "\n";

				getReadyProcessList().push_back(processList[i]);

				std::cout << getReadyProcessList().size() << "\n";
				getReadyProcessList().back().setIdle(true);

				std::cout << "reached end of for loop\n";
			}


		}

		// if multiple jobs arrived, block them

		

		// run job for x amount of cycles

		runningProcesses.front().getRunTimes().front() -= sC->getTimeUnit();

		// if current procces has reached the end of its time slice, pop it from the running process "container"

		if (runningProcesses.front().getRunTimes()[runningProcesses.front().getTimeSliceNumber()] == 0) { // stop/block process
		
			runningProcesses.front().progressTimeSliceNumber();
			runningProcesses.pop_back();

		}

		// choose next process

		currentPredictionValue = computePredictionValue(currentPredictionValue, predictionWeight, sC->getTime());
		chooseNextProcess(runningProcesses, getReadyProcessList(), getBlockedProcessList(), currentPredictionValue);

		// progress time

		std::cout << sC->getTime() << "\n";


		sC->progressSystemTime();


		break;

		// check if all kobs are done

		/*if ((this->getReadyProcessList().size() == 0) && (this->getBlockedProcessList().size() == 0)) {
			break;
		}*/

	}


}

void ShortestProcessFirst::chooseNextProcess(std::vector<Process> runningProcess, std::vector<Process> readyProcesses, std::vector<Process> blockedProcess, float cPV) {

	float min = FLT_MAX;
	int index = 0;

	for (int i = 0; i < readyProcesses.size(); ++i) {
	
		float compare = abs(readyProcesses[i].getRunTimes()[readyProcesses[i].getTimeSliceNumber()] - cPV);

		if (compare <= min) {
			min = compare;
			index = i;
		}

	}

	runningProcess.push_back(readyProcesses[index]);
	runningProcess[0].setIdle(false);

}

float ShortestProcessFirst::computePredictionValue(float w, float a, float t) {

	float result = (a * w) + (t * (1 - a));

	if (result < 0) {
		cerr << "ERROR: negative prediction value\n";
	}
	

	return result;

}

std::vector<Process> ShortestProcessFirst::getProcessList() {
	return processList;
}

std::vector<Process> ShortestProcessFirst::getBlockedProcessList() {
	return blockedProcessList;
}

std::vector<Process> ShortestProcessFirst::getReadyProcessList() {
	return readyProcessList;
}



