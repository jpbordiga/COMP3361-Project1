/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SystemClock.hpp
 * Author: jpbordiga
 *
 * Created on April 20, 2018, 4:33 PM
 */

#ifndef SYSTEMCLOCK_HPP
#define SYSTEMCLOCK_HPP

#include <iostream>

class SystemClock {

public:

	/**
	* Constructor - initialize System Clock to keep track of time
	*
	* @param 
	*/
	SystemClock();

	// Other constructors, assignment, disallow copy/move
	SystemClock(const SystemClock&);
	SystemClock(SystemClock &orig);
	SystemClock operator=(const SystemClock &orig);
	SystemClock operator=(SystemClock &orig);

	/**
	* Destructor - default
	*/
	virtual ~SystemClock() {
		//
	}

        /**
	* startTime - initialize System Clock to keep track of time
	*
	* @param 
	*/
	void startTime();
        
        /**
	* getTime - gets the current time
	*
	* @param 
	*/
	float getTime();
        
        /**
	* getTimeUnit - returns the time unit
	*
	* @param 
	*/
	float getTimeUnit();
        
        /**
	* setTime - sets the time
	*
	* @param float t
	*/
	void setTime(float t);
        
        /**
	* progressSystemTime - progresses the current time by timeUnit
	*
	* @param 
	*/
	void progressSystemTime();



private:

	float current_time;
	float timeUnit;

};

#endif /* SYSTEMCLOCK_HPP */

