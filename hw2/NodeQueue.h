/*
 * Title: Trees
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 2
 * Description: Queue implementation for nodes header file
 */

#include "BinaryNode.h"
using namespace std;

class NodeQueue
{
private:
    NodeQueue();
    ~NodeQueue();
    void enqueue(BinaryNode *node);
    BinaryNode *dequeue();
    bool isEmpty() const;
    int getNoOfElements() const;
    int getPosition(BinaryNode *node) const;
    int getElement(int position) const;

    BinaryNode **queue;
    int size;
    int noOfElements;

    friend class BinarySearchTree;
};
