/*
 * Title: Heaps, Priority Queues
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 3
 * Description: Request Definition File
 */

#include "Request.h"
#include <iostream>
using namespace std;

Request::Request()
{
    // Default Constructor
    requestID = 0;
    requestPriority = 0;
    requestTime = 0;
    processTime = 0;
}

Request::Request(int requestID, int requestPriority, int requestTime, int processTime)
{
    // Overloaded Constructor
    this->requestID = requestID;
    this->requestPriority = requestPriority;
    this->requestTime = requestTime;
    this->processTime = processTime;
}

Request::Request(const Request &request)
{
    // Copy Constructor
    requestID = request.requestID;
    requestPriority = request.requestPriority;
    requestTime = request.requestTime;
    processTime = request.processTime;
}

Request::~Request()
{
    // Destructor
}

int Request::getRequestID() const
{
    // Returns the Request ID
    return requestID;
}

int Request::getRequestPriority() const
{
    // Returns the Request Priority
    return requestPriority;
}

int Request::getRequestTime() const
{
    // Returns the Request Time
    return requestTime;
}

int Request::getProcessTime() const
{
    // Returns the Process Time
    return processTime;
}

void Request::setRequestID(int requestID)
{
    // Sets the Request ID
    this->requestID = requestID;
}

void Request::setRequestPriority(int requestPriority)
{
    // Sets the Request Priority
    this->requestPriority = requestPriority;
}

void Request::setRequestTime(int requestTime)
{
    // Sets the Request Time
    this->requestTime = requestTime;
}

void Request::setProcessTime(int processTime)
{
    // Sets the Process Time
    this->processTime = processTime;
}

void Request::setNull()
{
    // Sets the Request ID to 0
    requestID = 0;
}

void Request::printRequest()
{
    // Prints the Request
    cout << "Request ID: " << requestID << " "
         << "Request Priority: " << requestPriority << " "
         << "Request Time: " << requestTime << " "
         << "Process Time: " << processTime << endl;
}
