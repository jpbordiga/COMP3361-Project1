/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ShortestProcessFirst.hpp"
#include "SystemClock.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <float.h>
#include <cmath>

using std::cerr;

ShortestProcessFirst::ShortestProcessFirst(const ShortestProcessFirst &orig) {
	
    blockDuration = orig.blockDuration;
    predictionWeight = orig.predictionWeight;
	
}

ShortestProcessFirst::ShortestProcessFirst(ShortestProcessFirst &orig) {

    blockDuration = orig.blockDuration;
    predictionWeight = orig.predictionWeight;

}

ShortestProcessFirst ShortestProcessFirst::operator=(const ShortestProcessFirst &orig) {
	
    blockDuration = orig.blockDuration;
    predictionWeight = orig.predictionWeight;
    return *this;

}

ShortestProcessFirst ShortestProcessFirst::operator=(ShortestProcessFirst &orig) {
	
    blockDuration = orig.blockDuration;
    predictionWeight = orig.predictionWeight;
    return *this;

}

ShortestProcessFirst::ShortestProcessFirst(float bD, float pW, std::vector<Process> &processList) {

    blockDuration = bD;
    predictionWeight = pW;
    float currentPredictionValue = 0;
    std::vector<Process> runningProcess; // should only have the current process due to copy/move being forbidden
    std::vector<Process> blockedProcesses;
    SystemClock *sC = new SystemClock();
    
    blockedProcesses.reserve(processList.size());

    while (true) {

		// check for arrival of new jobs

		for (int i = 0; i < processList.size(); ++i) {

			if (sC->getTime() == processList[i].getArrivalTime()) {
				
                            if(runningProcess.size() == 0){
                            
                                runningProcess.push_back(processList[i]);
                                
                            } else {
                            
                                blockedProcesses.push_back(processList[i]);
				blockedProcesses.back().getRunTimes().push_back(processList[i].getRunTimes()[i]);
                                blockedProcesses.back().setBlocked(true);
                                
                            }
                            
				
			}

		}

		// choose next process

		currentPredictionValue = computePredictionValue(currentPredictionValue, predictionWeight, sC->getTime());
		chooseNextProcess(runningProcess, blockedProcesses, currentPredictionValue);
		
		runningProcess.front().getRunTimes()[runningProcess.front().getTimeSliceNumber()] -= sC->getTimeUnit();
		
		// progress time:
		
		std::cout << sC->getTime() << "\n";

		sC->progressSystemTime();

                // if current procces has reached the end of its time slice, pop it from the running process "container":

		if (runningProcess.front().getRunTimes()[runningProcess.front().getTimeSliceNumber()] == 0) { // stop/block process
                    
                    if(runningProcess.front().isIdle() == true){
                        std::cout << sC->getTime() << "\t" << "IDLE" << "\t" << processList[runningProcess.front().getProcessNumber()].getRunTimes()[runningProcess.front().getTimeSliceNumber()] << "\t" << "I" << "\n";
                    } else if(runningProcess.front().isBlocked() == true) {
                        std::cout << sC->getTime() << "\t" << runningProcess.front().getProcessName() << "\t" << processList[runningProcess.front().getProcessNumber()].getRunTimes()[runningProcess.front().getTimeSliceNumber()] << "\t" << "B" << "\n";
                    } else {
                        std::cout << sC->getTime() << "\t" << runningProcess.front().getProcessName() << "\t" << processList[runningProcess.front().getProcessNumber()].getRunTimes()[runningProcess.front().getTimeSliceNumber()] << "\t" << "T" << "\n";
                    }
                    
                    if(runningProcess.front().getTimeSliceNumber() == runningProcess.front().getRunTimes().size()){
                    
                        runningProcess.pop_back();
                        
                    } else {
                    
                        runningProcess.front().progressTimeSliceNumber();
                        blockedProcesses.push_back(runningProcess.front());
                        runningProcess.pop_back();
                        
                    } 
                    
		}

		// check if all jobs are done:

		if ((runningProcess.size() == 0) && (blockedProcesses.size() == 0)) {
                    break;
		}

	}


}

void ShortestProcessFirst::chooseNextProcess(std::vector<Process> &runningProcess, std::vector<Process> &blockedProcesses, float cPV) {

	float min = FLT_MAX;
	int index = 0;
	
	for (int i = 0; i < blockedProcesses.size(); ++i) {

		float compare = std::abs(blockedProcesses[i].getRunTimes()[blockedProcesses[i].getTimeSliceNumber()] - cPV);
		
		if (compare <= min) {
			min = compare;
			index = i;
		}

	}
	
	runningProcess.push_back(blockedProcesses[index]);
	runningProcess[0].setIdle(false);

}

float ShortestProcessFirst::computePredictionValue(float w, float a, float t) {

	float result = (a * w) + (t * (1 - a));

	if (result < 0) {
		cerr << "ERROR: negative prediction value\n";
	}
	
	return result;

}
