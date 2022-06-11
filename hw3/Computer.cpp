/*
 * Title: Heaps, Priority Queues
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 3
 * Description: Computer Class Definition File
 */

#include "Computer.h"
using namespace std;

int Computer::nextId = 0;

Computer::Computer()
{
    // Default Constructor
    id = ++nextId;
    time = 0;
}

Computer::~Computer()
{
    // Destructor
}

int Computer::getID()
{
    // Returns the Computer ID
    return id;
}

void Computer::setTime(int time)
{
    // Sets the Computer Time
    this->time = time;
}

int Computer::getTime()
{
    // Returns the Computer Time
    return time;
}

bool Computer::isFree(int time)
{
    // Returns true if the Computer is free at the given time
    return (this->time <= time);
}
