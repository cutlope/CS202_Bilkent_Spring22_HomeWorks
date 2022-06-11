/*
 * Title: Trees
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 2
 * Description: Binary Node Header File
 */

#include <cstddef>

class BinaryNode
{
private:
    // Methods
    BinaryNode();
    BinaryNode(int data);
    BinaryNode(const int &data, const int &size, BinaryNode *left = NULL, BinaryNode *right = NULL, BinaryNode *parent = NULL);
    ~BinaryNode();

    void setData(const int &data);
    void setSize(const int &size);
    void setLeft(BinaryNode *left);
    void setRight(BinaryNode *right);
    void setParent(BinaryNode *parent);
    int getData() const;
    int getSize() const;
    BinaryNode *getLeft() const;
    BinaryNode *getRight() const;
    BinaryNode *getParent() const;

    // Data Members
    int data;
    int size;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode *parent;

    friend class BinarySearchTree;
    friend class NodeQueue;
};
