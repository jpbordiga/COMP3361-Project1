/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShortestProcessFirst.hpp
 * Author: jpbordiga
 *
 * Created on April 20, 2018, 4:31 PM
 */

#ifndef SHORTESTPROCESSFIRST_HPP
#define SHORTESTPROCESSFIRST_HPP

#include <queue>
#include <vector>
#include "Process.hpp"

class ShortestProcessFirst {

public:

	/**
	* Constructor - instantiate the algorithm
	*
	* @param 
	*/
	ShortestProcessFirst(float bD, float pW, std::vector<Process> &processList);

	// Other constructors
	ShortestProcessFirst(const ShortestProcessFirst &orig);
	ShortestProcessFirst(ShortestProcessFirst &orig);
	ShortestProcessFirst operator=(const ShortestProcessFirst &orig);
	ShortestProcessFirst operator=(ShortestProcessFirst &orig);

	/**
	* Destructor - default
	*/
	virtual ~ShortestProcessFirst() {
		//
	}
        
        /**
	* computePredictionValue - computes prediction value
	*
	* @param float w, float a, float t
	*/
	float computePredictionValue(float w, float a, float t);
        
        /**
	* chooseNextProcess - chooses new process to run
	*
	* @param std::vector<Process> &runningProcess, std::vector<Process> &blockedProcess, float cPV
	*/
	void chooseNextProcess(std::vector<Process> &runningProcess, std::vector<Process> &blockedProcess, float cPV);

private:

	float blockDuration;
	float predictionWeight;

};

#endif /* SHORTESTPROCESSFIRST_HPP */

