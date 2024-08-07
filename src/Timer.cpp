//////////////////////////////////////////////////////////////////////////////
// Timer.cpp
// =========
// High Resolution Timer.
// This timer is able to measure the elapsed time with 1 micro-second accuracy
// using chrono STL (C++11) in both Windows, Linux and Unix system
//
//  AUTHOR: Song Ho Ahn (song.ahn@gmail.com)
// CREATED: 2003-01-13
// UPDATED: 2024-04-17
//
// Copyright (c) 2003 Song Ho Ahn
//////////////////////////////////////////////////////////////////////////////

#include "Timer.h"

///////////////////////////////////////////////////////////////////////////////
// constructor
///////////////////////////////////////////////////////////////////////////////
Timer::Timer()
{
    startPoint = std::chrono::high_resolution_clock::now();
    endPoint = startPoint;
    stopped = 0;
}



///////////////////////////////////////////////////////////////////////////////
// distructor
///////////////////////////////////////////////////////////////////////////////
Timer::~Timer()
{
}



///////////////////////////////////////////////////////////////////////////////
// start timer.
// startPoint will be set at this point.
///////////////////////////////////////////////////////////////////////////////
void Timer::start()
{
    stopped = 0; // reset stop flag
    startPoint = std::chrono::high_resolution_clock::now();
}



///////////////////////////////////////////////////////////////////////////////
// stop the timer.
// endPoint will be set at this point.
///////////////////////////////////////////////////////////////////////////////
void Timer::stop()
{
    stopped = 1; // set timer stopped flag
    endPoint = std::chrono::high_resolution_clock::now();
}



///////////////////////////////////////////////////////////////////////////////
// compute elapsed time in nano-second resolution.
// other getElapsedTime will call this first, then convert to correspond resolution
///////////////////////////////////////////////////////////////////////////////
double Timer::getElapsedTimeInNanoSec()
{
    if(!stopped)
        endPoint = std::chrono::high_resolution_clock::now();

    // time interval (nanosec) as double
    return std::chrono::duration<double, std::nano>{endPoint - startPoint}.count();
}



///////////////////////////////////////////////////////////////////////////////
// divide elapsedTimeInNanoSec by 1000
///////////////////////////////////////////////////////////////////////////////
double Timer::getElapsedTimeInMicroSec()
{
    return this->getElapsedTimeInNanoSec() * 0.001;
}



///////////////////////////////////////////////////////////////////////////////
// divide elapsedTimeInNanoSec by 1000000
///////////////////////////////////////////////////////////////////////////////
double Timer::getElapsedTimeInMilliSec()
{
    return this->getElapsedTimeInNanoSec() * 0.000001;
}



///////////////////////////////////////////////////////////////////////////////
// divide elapsedTimeInNanoSec by 1000000000
///////////////////////////////////////////////////////////////////////////////
double Timer::getElapsedTimeInSec()
{
    return this->getElapsedTimeInNanoSec() * 0.000000001;
}



///////////////////////////////////////////////////////////////////////////////
// same as getElapsedTimeInSec()
///////////////////////////////////////////////////////////////////////////////
double Timer::getElapsedTime()
{
    return this->getElapsedTimeInSec();
}
