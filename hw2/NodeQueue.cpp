/*
 * Title: Trees
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 2
 * Description: Queue implementation for nodes definition file
 */

#include "NodeQueue.h"
#include <iostream>
using namespace std;

NodeQueue::NodeQueue()
{
    // Default Constructor
    size = 100;
    queue = new BinaryNode *[size];
    noOfElements = 0;
}

NodeQueue::~NodeQueue()
{
    // Destructor
    delete[] queue;
}

void NodeQueue::enqueue(BinaryNode *node)
{
    // Adds a new node to the queue
    if (noOfElements == size)
    {
        cout << "Queue is full" << endl;
        return;
    }
    queue[noOfElements] = node;
    noOfElements++;
}

BinaryNode *NodeQueue::dequeue()
{
    // Removes and returns the first node in the queue
    if (noOfElements == 0)
    {
        cout << "Queue is empty" << endl;
        return NULL;
    }
    noOfElements--;
    return queue[noOfElements];
}

bool NodeQueue::isEmpty() const
{
    // Returns true if the queue is empty
    return noOfElements == 0;
}

int NodeQueue::getNoOfElements() const
{
    // Returns the size of the queue
    return noOfElements;
}

int NodeQueue::getPosition(BinaryNode *node) const
{
    // Returns the position of the node in the queue
    for (int i = 0; i < noOfElements; i++)
    {
        if (queue[i]->getData() == node->getData())
        {
            return i;
        }
    }
    return -1;
}

int NodeQueue::getElement(int position) const
{
    return queue[position]->getData();
}
