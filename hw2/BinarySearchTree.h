/*
 * Title: Trees
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 2
 * Description: Binary Search Tree Header File
 */

#include <iostream>
#include "NodeQueue.h"

class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    bool isEmpty() const;
    bool add(int newEntrty);
    bool remove(int anEntry);
    bool contains(int anEntry) const;
    void removeHelper(BinaryNode *node, int newEntry);
    int getHeight() const;
    int GetNumberOfNodes() const;
    int getWidth() const;
    int getWidthHelper(BinaryNode *node) const;
    int count(int a, int b) const;
    int countHelper(BinaryNode *node, int a, int b) const;
    int select(int anEntry) const;
    void selectHelper(BinaryNode *subTreePtr, int anEntry, NodeQueue *queue) const;
    int successor(int anEntry) const;
    int getHeightHelper(BinaryNode *subTreePtr) const;
    void inorderTraverse() const;
    void inorderTraverseHelper(BinaryNode *subTreePtr) const;
    void destroyTree(BinaryNode *subTreePtr);
    int getNumberOfNodes() const;

private:
    BinaryNode *root;
    int numberOfNodes;
};
