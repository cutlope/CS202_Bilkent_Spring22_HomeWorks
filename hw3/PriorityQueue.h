/*
 * Title: Heaps, Priority Queues
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 3
 * Description: PriorityQueue Declaration File
 */

#include "Heap.h"

class PriorityQueue
{
public:
    // default constructor, copy constructor, and destructor
    // are supplied by the compiler

    // priority-queue operations:
    bool pqIsEmpty() const;
    void pqInsert(const Request &newItem);
    void pqDelete(Request &priorityItem);
    void print();

private:
    Heap h;
};
