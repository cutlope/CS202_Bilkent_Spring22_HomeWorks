/*
 * Title: Heaps, Priority Queues
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 3
 * Description: Heap Declaration File
 */


#include "Request.h"

class Heap
{
public:
    Heap();

    bool heapIsEmpty() const;
    void heapInsert(const Request &request);
    void heapDelete(Request &request);
    void print();
    void heapSort();

protected:
    void heapRebuild(int root);

private:
    int heapSize;
    Request requests[50000];
};
