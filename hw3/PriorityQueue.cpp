/*
 * Title: Heaps, Priority Queues
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 3
 * Description: PriorityQueue Definition File
 */

#include "PriorityQueue.h"
using namespace std;

bool PriorityQueue::pqIsEmpty() const
{
    return h.heapIsEmpty();
}

void PriorityQueue::pqInsert(const Request &newItem)
{
    h.heapInsert(newItem);
}

void PriorityQueue::pqDelete(Request &priorityItem)
{

    h.heapDelete(priorityItem);
}

void PriorityQueue::print()
{
    h.print();
}
