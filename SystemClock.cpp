/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "SystemClock.hpp"

SystemClock::SystemClock() {

    timeUnit = 0.0000001;
    this->startTime();

}

SystemClock::SystemClock(const SystemClock &orig){

    current_time = orig.current_time;
    timeUnit = orig.timeUnit;
    
}

SystemClock::SystemClock(SystemClock &orig){

    current_time = orig.current_time;
    timeUnit = orig.timeUnit;
    
}

SystemClock SystemClock::operator=(const SystemClock &orig){

    current_time = orig.current_time;
    timeUnit = orig.timeUnit;
    return *this;
    
}

SystemClock SystemClock::operator=(SystemClock &orig){

    current_time = orig.current_time;
    timeUnit = orig.timeUnit;
    return *this;
    
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