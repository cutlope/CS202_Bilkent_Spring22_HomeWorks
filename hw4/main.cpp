#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "VertexList.h"
using namespace std;

int main(int argc, char **argv)
{
    string fileline;
    int noOfAirports;
    int nofOperations;

    string filename = argv[1];
    ifstream inputFile;
    inputFile.open(filename.c_str());
    getline(inputFile, fileline);
    istringstream(fileline) >> noOfAirports;
    getline(inputFile, fileline);
    istringstream(fileline) >> nofOperations;

    VertexList *airports = new VertexList[noOfAirports];
    for (int i = 0; i < noOfAirports; i++)
    {
        airports[i].id = i;
    }

    for (int i = 0; i < nofOperations; i++)
    {
        int airportID;
        int airportID2;
        int weight;
        string operation;
        string insr;
        getline(inputFile, insr);
        istringstream my_stream(insr);
        my_stream >> operation >> airportID >> airportID2 >> weight;
        if (operation == "I")
        {
            airports[airportID].addVertex(weight, airportID2);
            airports[airportID2].addVertex(weight, airportID);
            cout << "Inserted a new flight between " << airportID << " and " << airportID2 << endl;
            cout << "   The Number of flights from " << airportID << " is " << airports[airportID].count << endl;
        }
        else if (operation == "S")
        {
            cout << "No Path found from " << airportID << " to " << airportID2 << endl;
        }
        else if (operation == "L")
        {
            airports[airportID].print();
        }
        else if (operation == "M")
        {
        }
    }
}
