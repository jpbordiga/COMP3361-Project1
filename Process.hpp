/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Process.hpp
 * Author: jpbordiga
 *
 * Created on April 20, 2018, 4:32 PM
 */

#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <string>
#include <vector>
#include <fstream>

class Process {

public:

	/**
	* Constructor - create instance of a Process
	*
	* @param 
	*/
	Process();
	Process(std::string processName, float arrivalTime, std::vector<float> &runTimes);

	// Other constructors
	Process(const Process &orig); // define
	Process(Process &orig);
	Process operator=(const Process &orig);
	Process operator=(Process &orig);

	/**
	* Destructor - default
	*/
	virtual ~Process() {
		//
	}

        /**
	* getProcessName - gets the name of a Process
	*
	* @param 
	*/
	std::string getProcessName();
        
        /**
	* getArrivalTime - gets the arrival time of a Process
	*
	* @param 
	*/
	float getArrivalTime();
        
        /**
	* getRunTimes - gets the runtime vector of a Process
	*
	* @param 
	*/
	std::vector<float> getRunTimes();
        
        /**
	* setIdle - sets a Process to idle mode
	*
	* @param bool i
	*/
	void setIdle(bool i);
        
        /**
	* isIdle - checks if a Process is idle
	*
	* @param 
	*/
        bool isIdle();
        
        /**
	* isBlocked - checks if a Process is blocked
	*
	* @param 
	*/
        bool isBlocked();
        
        /**
	* getTimeSliceNumber - gets a Process's time slice number
	*
	* @param 
	*/
	int getTimeSliceNumber();
        
        /**
	* progressTimeSliceNumber - progresses the time slice number
	*
	* @param 
	*/
	void progressTimeSliceNumber();
        
        /**
	* getProcessNumber - gets the Process number
	*
	* @param 
	*/
        int getProcessNumber();
        
        /**
	* setBlocked - sets the Process to blocked mode
	*
	* @param bool i
	*/
        void setBlocked(bool i);

private:

	std::string processName;
	float arrivalTime;
	std::vector<float> runTimes;
	bool idle;
        bool blocked;
        int processNumber;
	int currentTimeSlice;

};

#endif /* PROCESS_HPP */

