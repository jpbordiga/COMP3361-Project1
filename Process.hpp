#ifndef PROCESS_HPP
#define PROCESS_HPP

class Process {

public:

	/**
	* Constructor - create instance of a Process
	*
	* @param 
	*/
	Process(); // params TBD

	// Other constructors, assignment, disallow copy/move
	Process(const Process &orig) = delete;
	Process(Process &&orig) = delete;
	Process operator=(const Process &orig) = delete;
	Process operator=(Process &&orig) = delete;

	/**
	* Destructor - default
	*/
	virtual ~Process() {
		//
	}

private:



};

#endif
