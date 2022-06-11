/*
 * Title: Trees
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 2
 * Description: Binary Search Tree Definition File
 */

#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree()
{
    // Default Constructor
    root = NULL;
    numberOfNodes = 0;
}

BinarySearchTree::~BinarySearchTree()
{
    // Destructor
    destroyTree(root);
}

bool BinarySearchTree::isEmpty() const
{
    // Returns true if the tree is empty
    return root == NULL;
}

int BinarySearchTree::getHeight() const
{
    // Returns the height of the tree
    return getHeightHelper(root);
}

int BinarySearchTree::GetNumberOfNodes() const
{
    // Returns the number of nodes in the tree
    return numberOfNodes;
}

bool BinarySearchTree::add(int newEntrty)
{
    if (contains(newEntrty))
    {
        return false;
    }

    else if (newEntrty <= 0)
    {
        return false;
    }

    else
    {

        // Adds a new entry to the tree
        BinaryNode *newNode = new BinaryNode(newEntrty, 1);
        if (root == NULL)
        {
            root = newNode;
            numberOfNodes++;
            return true;
        }
        else
        {
            BinaryNode *current = root;
            BinaryNode *parent = NULL;
            while (current != NULL)
            {
                parent = current;
                if (newEntrty < current->getData())
                {
                    current = current->getLeft();
                }
                else
                {
                    current = current->getRight();
                }
            }
            if (newEntrty < parent->getData())
            {
                parent->setLeft(newNode);
            }
            else
            {
                parent->setRight(newNode);
            }
            newNode->setParent(parent);
            numberOfNodes++;
            return true;
        }
    }
}

bool BinarySearchTree::remove(int anEntry)
{
    if (contains(anEntry))
    {
        removeHelper(root, anEntry);
        return true;
    }
    else
    {
        return false;
    }
}

void BinarySearchTree::removeHelper(BinaryNode *node, int anEntry)
{
    if (node->getData() < anEntry)
    {
        removeHelper(node->getRight(), anEntry);
    }
    else if (node->getData() > anEntry)
    {
        removeHelper(node->getLeft(), anEntry);
    }

    else
    {
        // node is root
        if (node->getParent() == NULL)
        {
            if (node->getLeft() == NULL && node->getRight() == NULL)
            {
                delete node;
                root = NULL;
                numberOfNodes--;
            }
            else if (node->getLeft() == NULL)
            {
                BinaryNode *temp = node->getRight();
                while (temp->getLeft() != NULL)
                {
                    temp = temp->getLeft();
                }
                node->setData(temp->getData());
                removeHelper(node->getRight(), temp->getData());
            }
            else if (node->getRight() == NULL)
            {
                BinaryNode *temp = node->getLeft();
                while (temp->getRight() != NULL)
                {
                    temp = temp->getRight();
                }
                node->setData(temp->getData());
                removeHelper(node->getLeft(), temp->getData());
            }
            else
            {
                BinaryNode *temp = node->getRight();
                while (temp->getLeft() != NULL)
                {
                    temp = temp->getLeft();
                }
                node->setData(temp->getData());
                removeHelper(node->getRight(), temp->getData());
            }
        }

        // node is leaf
        else if (node->getLeft() == NULL && node->getRight() == NULL)
        {
            if (node->getParent()->getLeft() == node)
            {
                node->getParent()->setLeft(NULL);
            }
            else
            {
                node->getParent()->setRight(NULL);
            }
            delete node;
            numberOfNodes--;
        }

        // node has right child only
        else if (node->getLeft() == NULL)
        {
            if (node->getParent()->getLeft() == node)
            {
                node->getParent()->setLeft(node->getRight());
            }
            else
            {
                node->getParent()->setRight(node->getRight());
            }
            node->getRight()->setParent(node->getParent());
            delete node;
            numberOfNodes--;
        }

        // node has left child only
        else if (node->getRight() == NULL)
        {
            if (node->getParent()->getLeft() == node)
            {
                node->getParent()->setLeft(node->getLeft());
            }
            else
            {
                node->getParent()->setRight(node->getLeft());
            }
            node->getLeft()->setParent(node->getParent());
            delete node;
            numberOfNodes--;
        }

        // node has both children
        else
        {
            BinaryNode *temp = node->getRight();
            while (temp->getLeft() != NULL)
            {
                temp = temp->getLeft();
            }
            node->setData(temp->getData());
            removeHelper(temp, temp->getData());
        }
    }
}

void BinarySearchTree::inorderTraverse() const
{
    // Traverses the tree inorder
    inorderTraverseHelper(root);
}

void BinarySearchTree::inorderTraverseHelper(BinaryNode *subTreePtr) const
{
    if (subTreePtr != NULL)
    {
        inorderTraverseHelper(subTreePtr->getLeft());
        cout << subTreePtr->getData() << " ";
        inorderTraverseHelper(subTreePtr->getRight());
    }
}

int BinarySearchTree::getWidth() const
{
    // Returns the width of the tree
    NodeQueue *queue = new NodeQueue();
    int width = 0;
    queue->enqueue(root);
    while (!queue->isEmpty())
    {
        int size = queue->getNoOfElements();
        width = max(width, size);
        for (int i = 0; i < size; i++)
        {
            BinaryNode *node = queue->dequeue();
            if (node->getLeft() != NULL)
            {
                queue->enqueue(node->getLeft());
            }
            if (node->getRight() != NULL)
            {
                queue->enqueue(node->getRight());
            }
        }
    }
    delete queue;
    return width;
}

bool BinarySearchTree::contains(int anEntry) const
{
    // Returns true if the tree contains anEntry
    BinaryNode *current = root;
    while (current != NULL)
    {
        if (anEntry == current->getData())
        {
            return true;
        }
        else if (anEntry < current->getData())
        {
            current = current->getLeft();
        }
        else
        {
            current = current->getRight();
        }
    }
    return false;
}

int BinarySearchTree::count(int a, int b) const
{
    return countHelper(root, a, b);
}

int BinarySearchTree::countHelper(BinaryNode *node, int a, int b) const
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        if (node->getData() >= a && node->getData() <= b)
        {
            return 1 + countHelper(node->getLeft(), a, b) + countHelper(node->getRight(), a, b);
        }
        else
        {
            return countHelper(node->getLeft(), a, b) + countHelper(node->getRight(), a, b);
        }
    }
}

int BinarySearchTree::select(int anEntry) const
{
    NodeQueue *queue = new NodeQueue();
    BinaryNode *current = new BinaryNode(anEntry);
    int ans;
    if (contains(anEntry))
    {
        selectHelper(root, anEntry, queue);
        ans = queue->getPosition(current);
    }
    else
    {

        ans = -1;
    }
    delete queue;
    delete current;
    return ans;
}

void BinarySearchTree::selectHelper(BinaryNode *subTreePtr, int anEntry, NodeQueue *queue) const
{
    if (subTreePtr != NULL)
    {
        selectHelper(subTreePtr->getLeft(), anEntry, queue);
        queue->enqueue(subTreePtr);
        selectHelper(subTreePtr->getRight(), anEntry, queue);
    }
}

int BinarySearchTree::successor(int anEntry) const
{

    // Returns the smallest entry that is larger than anEntry
    int index;
    int ans;
    NodeQueue *queue = new NodeQueue();
    BinaryNode *current = new BinaryNode(anEntry);
    if (contains(anEntry))
    {
        selectHelper(root, anEntry, queue);
        index = queue->getPosition(current);
        if (index == queue->getNoOfElements() - 1)
        {
            ans = -2;
        }
        else
        {
            ans = queue->getElement(index + 1);
        }
    }
    else
    {
        ans = -1;
    }
    delete queue;
    delete current;
    return ans;
}

int BinarySearchTree::getHeightHelper(BinaryNode *subTreePtr) const
{
    // Returns the height of the tree. Height in our program starts from 1
    if (subTreePtr == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(getHeightHelper(subTreePtr->getLeft()), getHeightHelper(subTreePtr->getRight()));
    }
}

void BinarySearchTree::destroyTree(BinaryNode *subTreePtr)
{
    // Destructor helper
    if (subTreePtr != NULL)
    {
        destroyTree(subTreePtr->getLeft());
        destroyTree(subTreePtr->getRight());
        delete subTreePtr;
    }
}

int BinarySearchTree::getNumberOfNodes() const
{
    return numberOfNodes;
}
