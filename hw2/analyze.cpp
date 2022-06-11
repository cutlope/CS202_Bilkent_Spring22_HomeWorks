/*
 * Title: Trees
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 2
 * Description: AnalyseBst File
 */

#include <iostream>
#include <stdlib.h>
#include "BinarySearchTree.h"
using namespace std;

void analyzeBST()
{
    // create random array with 10000 elements
    int array[10000];
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        array[i] = rand() % 10000;
    }
    // create BST
    BinarySearchTree BST;
    // add elements to BST in 100 increments

    cout << "Random BST size vs. height (Insertion)" << endl;
    cout << "------------------------------------------" << endl;
    for (int i = 0; i < 10000; i++)
    {
        BST.add(array[i]);
        if (i % 100 == 0 && i > 0)
        {
            cout << BST.getNumberOfNodes() << " " << BST.getHeight() << endl;
        }
    }
    // shuffle array
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        int temp = array[i];
        int random = rand() % 10000;
        array[i] = array[random];
        array[random] = temp;
    }

    // remove elements from BST in 100 increments
    cout << "Random BST size vs. height (Deletion)" << endl;
    cout << "------------------------------------------" << endl;
    srand(time(NULL));
    for (int i = 10000; i > -1; i--)
    {
        BST.remove(array[i]);
        if (i % 100 == 0)
        {
            cout << BST.getNumberOfNodes() << " " << BST.getHeight() << endl;
        }
    }
}

int main()
{
    analyzeBST();
    return 0;
}
