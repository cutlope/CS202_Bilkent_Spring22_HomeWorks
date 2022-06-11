/*
 * Title: Trees
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 2
 * Description: Binary Node Definition File
 */

#include "BinaryNode.h"
using namespace std;

BinaryNode::BinaryNode()
{
    // Default Constructor
    data = 0;
    size = 0;
    left = NULL;
    right = NULL;
    parent = NULL;
}

BinaryNode::BinaryNode(int data)
{
    // Constructor with data
    this->data = data;
    size = 1;
    left = NULL;
    right = NULL;
    parent = NULL;
}

BinaryNode::BinaryNode(const int &data, const int &size, BinaryNode *left, BinaryNode *right, BinaryNode *parent)
{
    // Overloaded Constructor
    this->data = data;
    this->size = size;
    this->left = left;
    this->right = right;
    this->parent = parent;
}

BinaryNode::~BinaryNode()
{
    // Destructor
}

void BinaryNode::setData(const int &data)
{
    // Setter for data
    this->data = data;
}

void BinaryNode::setSize(const int &size)
{
    // Setter for size
    this->size = size;
}

void BinaryNode::setLeft(BinaryNode *left)
{
    // Setter for left
    this->left = left;
}

void BinaryNode::setRight(BinaryNode *right)
{
    // Setter for right
    this->right = right;
}

void BinaryNode::setParent(BinaryNode *parent)
{
    // Setter for parent
    this->parent = parent;
}

int BinaryNode::getData() const
{
    // Getter for data
    return data;
}

int BinaryNode::getSize() const
{
    // Getter for size
    return size;
}

BinaryNode *BinaryNode::getLeft() const
{
    // Getter for left
    return left;
}

BinaryNode *BinaryNode::getRight() const
{
    // Getter for right
    return right;
}

BinaryNode *BinaryNode::getParent() const
{
    // Getter for parent
    return parent;
}
