#include <iostream>
#include <sstream>
#include <fstream>
#include "Simulator.h"
using namespace std;

int main(int argc, char **argv)
{
    string filename = argv[1];
    string avgtime = argv[2];

    double avgWaitingTime;
    istringstream(avgtime) >> avgWaitingTime;
    findMinComp(filename, avgWaitingTime);

    return 0;
};
