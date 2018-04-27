/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
	runTimes = getRunTimes();
        processNumber = 0;
        
}

Process::Process(const Process &orig) {

	processName = orig.processName;
	arrivalTime = orig.arrivalTime;
	runTimes = orig.runTimes;
	idle = orig.idle;
	currentTimeSlice = orig.currentTimeSlice;
        processNumber = orig.processNumber;

}

Process::Process(Process &orig) {

	processName = orig.processName;
	arrivalTime = orig.arrivalTime;
	runTimes = orig.runTimes;
	idle = orig.idle;
	currentTimeSlice = orig.currentTimeSlice;
        processNumber = orig.processNumber;

}

Process Process::operator=(const Process &orig) {
	
	processName = orig.processName;
	arrivalTime = orig.arrivalTime;
	runTimes = orig.runTimes;
	idle = orig.idle;
	currentTimeSlice = orig.currentTimeSlice;
        processNumber = orig.processNumber;
	return *this;

}

Process Process::operator=(Process &orig) {
	
	processName = orig.processName;
	arrivalTime = orig.arrivalTime;
	runTimes = orig.runTimes;
	idle = orig.idle;
	currentTimeSlice = orig.currentTimeSlice;
        processNumber = orig.processNumber;
	return *this;

}


Process::Process(std::string pN, float aT, std::vector<float> &rT) {
	
	processName = pN;
	arrivalTime = aT;

	for (int i = 0; i < rT.size(); ++i) {
		runTimes.push_back(rT[i]);
	}

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

void Process::setBlocked(bool i) {
	blocked = i;
}

void Process::progressTimeSliceNumber() {
	this->currentTimeSlice++;
}

int Process::getTimeSliceNumber() {
	return this->currentTimeSlice;
}

int Process::getProcessNumber() {
    return this->processNumber;
}

bool Process::isIdle(){
    return this->idle;
}

bool Process::isBlocked(){
    return this->blocked;
}

