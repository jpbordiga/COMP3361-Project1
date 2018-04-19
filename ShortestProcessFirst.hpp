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
	ShortestProcessFirst(); // params TBD

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

private:

	std::priority_queue<Process> blockedProcessList;
	std::priority_queue<Process> readyProcessList;

};

#endif

