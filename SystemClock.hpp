#ifndef SYSTEMCLOCK_HPP
#define SYSTEMCLOCK_HPP

class SystemClock {

public:

	/**
	* Constructor - initialize System Clock to keep track of time
	*
	* @param 
	*/
	SystemClock(); // params TBD

	// Other constructors, assignment, disallow copy/move
	SystemClock(const SystemClock &orig) = delete;
	SystemClock(SystemClock &&orig) = delete;
	SystemClock operator=(const SystemClock &orig) = delete;
	SystemClock operator=(SystemClock &&orig) = delete;

	/**
	* Destructor - default
	*/
	virtual ~SystemClock() {
		//
	}

private:



};

#endif
