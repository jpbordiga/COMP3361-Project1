#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <vector>
#include <iomanip>
#include "Process.hpp"

Process::Process() {

	processName = "NULL";
	arrivalTime = 0;
	std::vector<float> null;
	runTimes = null;

}

Process::Process(std::string pN, float aT, std::vector<float> rT) {

	processName = pN;
	arrivalTime = aT;
	runTimes = rT;

	std::cout << processName << "\n";
	std::cout << arrivalTime << "\n";

	for (int i = 0; i < this->getRunTimes().size(); ++i) {
		std::cout << this->getRunTimes().at(i) << " ";
	}

	std::cout << "\n";

}

std::string Process::getProcessName() {
	return this->processName;
}

float Process::getArrivalTime() {
	return this->arrivalTime;
}

std::vector<float> Process::getRunTimes() {
	return this->runTimes;
}

void Process::setIdle(bool i) {

	idle = i;

}

void Process::progressTimeSliceNumber() {
	this->currentTimeSlice++;
}

int Process::getTimeSliceNumber() {
	return this->currentTimeSlice;
}