#ifndef SHORTESTPROCESSFIRST_HPP
#define SHORTESTPROCESSFIRST_HPP

#include <queue>
#include "Process.hpp"

class ShortestProcessFirst {

public:

	/**
	* Constructor - instantiate the algorithm
	*
	* @param 
	*/
	ShortestProcessFirst(float bD, float pW, std::vector<Process> processList);

	// Other constructors, assignment, disallow copy/move
	ShortestProcessFirst(const ShortestProcessFirst &orig) = delete;
	ShortestProcessFirst(ShortestProcessFirst &&orig) = delete;
	ShortestProcessFirst operator=(const ShortestProcessFirst &orig) = delete;
	ShortestProcessFirst operator=(ShortestProcessFirst &&orig) = delete;

	/**
	* Destructor - default
	*/
	virtual ~ShortestProcessFirst() {
		//
	}

	std::vector<Process> getProcessList();
	std::vector<Process> getBlockedProcessList();
	std::vector<Process> getReadyProcessList();
	float computePredictionValue(float w, float a, float t);
	void chooseNextProcess(std::vector<Process> runningProcess, std::vector<Process> readyProcesses, std::vector<Process> blockedProcess, float cPV);

private:

	float blockDuration = 0;
	float predictionWeight = 0;
	std::vector<Process> processList;
	//std::priority_queue<Process> blockedProcessList;
	//std::priority_queue<Process> readyProcessList;
	std::vector<Process> blockedProcessList;
	std::vector<Process> readyProcessList;

};

#endif

