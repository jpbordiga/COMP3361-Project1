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
	Process(std::string processName, float arrivalTime, std::vector<float> runTimes);

	// Other constructors, assignment, disallow copy/move
	/*Process(const Process &orig) = delete;
	Process(Process &&orig) = delete;
	Process operator=(const Process &orig) = delete;
	Process operator=(Process &&orig) = delete;*/

	/**
	* Destructor - default
	*/
	virtual ~Process() {
		//
	}

	std::string getProcessName();
	float getArrivalTime();
	std::vector<float> getRunTimes();
	void setIdle(bool i);
	int getTimeSliceNumber();
	void progressTimeSliceNumber();

private:

	std::string processName;
	float arrivalTime = 0;
	std::vector<float> runTimes;
	bool idle;
	int currentTimeSlice;

};

#endif
