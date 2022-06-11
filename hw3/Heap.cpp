/*
 * Title: Heaps, Priority Queues
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 3
 * Description: Heap Class Definition File
 */

#include <iostream>
#include "Heap.h"
using namespace std;

Heap::Heap() : heapSize(0)
{
}

bool Heap::heapIsEmpty() const
{
    return (heapSize == 0);
}

void Heap::heapInsert(const Request &request)
{
    requests[heapSize] = request;
    int place = heapSize;
    int parent = (place - 1) / 2;
    int sibling = (place % 2 == 0) ? (place - 1) : (place + 1);
    if (sibling < heapSize && sibling > 0 && requests[sibling].getRequestPriority() < requests[place].getRequestPriority())
    {
        Request temp = requests[sibling];
        requests[sibling] = requests[place];
        requests[place] = temp;
        place = sibling;
    }
    while ((place > 0) && (requests[place].getRequestPriority() >= requests[parent].getRequestPriority()))
    {
        if (requests[place].getRequestPriority() == requests[parent].getRequestPriority())
        {
            if (requests[parent].getRequestTime() <= requests[place].getRequestTime())
            {
                // break;
                // swap sibling
                if (requests[sibling].getRequestPriority() < requests[place].getRequestPriority() && (sibling < heapSize))
                {
                    Request temp = requests[place];
                    requests[place] = requests[sibling];
                    requests[sibling] = temp;
                    place = sibling;
                }
                else
                {
                    break;
                }
            }
        }
        Request temp = requests[parent];
        requests[parent] = requests[place];
        requests[place] = temp;

        place = parent;
        parent = (place - 1) / 2;
    }

    // swap siblings

    heapSize++;
}

void Heap::heapDelete(Request &request)
{
    if (heapIsEmpty())
    {
        return;
    }

    else
    {
        request = requests[0];
        requests[0] = requests[--heapSize];
        heapRebuild(0);
    }
}

void Heap::heapRebuild(int root)
{
    int child = 2 * root + 1; // index of root's left child, if any
    int sibling = (root % 2 == 0) ? (root - 1) : (root + 1);
    if (child < heapSize)
    {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1; // index of a right child, if any
        // If root has right child, find larger child
        if ((rightChild < heapSize) && (requests[rightChild].getRequestPriority() >= requests[child].getRequestPriority()))
        {
            if (requests[rightChild].getRequestPriority() == requests[child].getRequestPriority())
            {
                if (requests[rightChild].getRequestTime() <= requests[child].getRequestTime())
                {
                    if (requests[rightChild].getRequestTime() == requests[child].getRequestTime())
                    {
                        if (requests[rightChild].getRequestID() < requests[child].getRequestID())
                        {
                            // Request temp = requests[child];
                            // requests[child] = requests[rightChild];
                            // requests[rightChild] = temp;
                            child = rightChild;
                        }
                    }
                }
            }
        }
        // If root’s item is smaller than larger child, swap values
        if (requests[root].getRequestPriority() <= requests[child].getRequestPriority())
        {
            if (requests[root].getRequestPriority() == requests[child].getRequestPriority())

            {
                if (requests[root].getRequestTime() >= requests[child].getRequestTime())
                {
                    if (requests[root].getRequestTime() == requests[child].getRequestTime())
                    {
                        if (requests[root].getRequestID() > requests[child].getRequestID())

                        {
                            Request temp = requests[root];
                            requests[root] = requests[child];
                            requests[child] = temp;

                            // transform the new subtree into a heap
                            heapRebuild(child);
                        }
                    }

                    else
                    {
                        Request temp = requests[root];
                        requests[root] = requests[child];
                        requests[child] = temp;
                    }
                }
            }
            else
            {
                Request temp = requests[root];
                requests[root] = requests[child];
                requests[child] = temp;
            }
        }
    }
    else if (sibling < heapSize && sibling > 0)
    {
        // single child
        if (requests[root].getRequestPriority() <= requests[sibling].getRequestPriority())
        {
            if (requests[root].getRequestPriority() == requests[sibling].getRequestPriority())
            {
                if (requests[root].getRequestTime() >= requests[sibling].getRequestTime())
                {
                    if (requests[root].getRequestTime() == requests[sibling].getRequestTime())
                    {
                        if (requests[root].getRequestID() > requests[sibling].getRequestID())
                        {
                            Request temp = requests[root];
                            requests[root] = requests[sibling];
                            requests[sibling] = temp;
                        }
                    }
                    else
                    {
                        Request temp = requests[root];
                        requests[root] = requests[sibling];
                        requests[sibling] = temp;
                    }
                }
            }
        }
    }
}

void Heap::print()
{
    for (int i = 0; i < heapSize; i++)
    {
        cout << "Request ID: " << requests[i].getRequestID() << " Priority: " << requests[i].getRequestPriority() << endl;
    }
}

void Heap::heapSort()
{
    for (int i = heapSize - 1; i >= 0; i--)
    {
        Request temp = requests[0];
        requests[0] = requests[i];
        requests[i] = temp;
        heapRebuild(0);
    }
}
