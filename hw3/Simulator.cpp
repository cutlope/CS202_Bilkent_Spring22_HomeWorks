/*
 * Title: Heaps, Priority Queues
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 3
 * Description: Simulator Definition File
 */

#include "Simulator.h"
#include "PriorityQueue.h"
#include "Computer.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

void findMinComp(string filename, double avgWaitingTime)
{
    string outputString = "";
    int compCount = 1;
    double simTime = simulateCase(filename, compCount, outputString);
    while (simTime > avgWaitingTime)
    {
        compCount++;
        simTime = simulateCase(filename, compCount, outputString);
    }
    cout << "Minimum number of computers required: " << compCount << endl;
    cout << endl;
    cout << "Simulation with " << compCount << " computers: " << endl;
    cout << endl;
    cout << outputString;
    cout << "Average waiting time: " << simTime << endl;
};

double simulateCase(string filename, int compCount, string &outputString)
{
    outputString = "";
    string requestsString;
    double waitingTime = 0;
    int requestsCount;
    int requestCountCopy;
    int time = 0;
    Computer *computer = new Computer[compCount];

    ifstream inputFile;
    inputFile.open(filename.c_str());
    getline(inputFile, requestsString);
    istringstream(requestsString) >> requestsCount;
    requestCountCopy = requestsCount;
    Request *requests = new Request[requestsCount];
    PriorityQueue pq;

    for (int i = 0; i < requestsCount; i++)
    {
        string requestString;
        int requestID, requestPriority, requestTime, processTime;
        getline(inputFile, requestString);
        istringstream(requestString) >> requestID >> requestPriority >> requestTime >> processTime;

        requests[i].setRequestID(requestID);
        requests[i].setRequestPriority(requestPriority);
        requests[i].setRequestTime(requestTime);
        requests[i].setProcessTime(processTime);
    }
    inputFile.close();

    while (requestCountCopy > 0)
    {

        for (int j = 0; j < requestsCount; j++)
        {
            if (requests[j].getRequestTime() == time && (requests[j].getRequestID() != -1))
            {
                pq.pqInsert(requests[j]);
                requests[j].setRequestID(-1);
            }
        }

        for (int i = 0; i < compCount; i++)
        {
            if (computer[i].isFree(time) && !pq.pqIsEmpty())
            {
                Request request;
                pq.pqDelete(request);
                requestCountCopy--;
                waitingTime = waitingTime + (time - request.getRequestTime());
                // cout << "Computer " << i << "take request " << request.getRequestID() << " at time " << time << endl;
                outputString = outputString + "Computer " + toString(i) + " takes request " + toString(request.getRequestID()) + " at ms " + toString(time) + " (wait:" + toString(time - request.getRequestTime()) + ")\n";
                computer[i].setTime(time + request.getProcessTime());
            }
        }
        time++;
    }
    delete[] requests;
    delete[] computer;
    return waitingTime / requestsCount;
};

string toString(int number)
{
    stringstream ss;
    ss << number;
    return ss.str();
};
