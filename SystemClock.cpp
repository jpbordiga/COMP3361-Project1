#include "SystemClock.hpp"

SystemClock::SystemClock() {

	this->startTime();




}

void SystemClock::startTime() {
	current_time = 0;
}

float SystemClock::getTime() {
	return current_time;
}

void SystemClock::setTime(float t) {
	current_time = t;
}

void SystemClock::progressSystemTime() {
	current_time += timeUnit;
}

float SystemClock::getTimeUnit() {
	return timeUnit;
}