#include "VertexList.h"
#include <iostream>
using namespace std;

VertexList::VertexList()
{
    head = NULL;
    count = 0;
}

VertexList::~VertexList()
{
    Node *p = head;
    while (p != NULL)
    {
        Node *q = p;
        p = p->next;
        delete q;
    }
}

void VertexList::addVertex(int weight, int adjacentVertex)
{
    count += 1;
    if (head == NULL)
    {
        head = new Node;
        head->vertex = adjacentVertex;
        head->weight = weight;
        head->next = NULL;
    }
    else
    {
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = new Node;
        p->next->vertex = adjacentVertex;
        p->next->weight = weight;
        p->next->next = NULL;
    }
}

void VertexList::print()
{
    int count = 0;
    Node *p = head;
    if (p != NULL)
    {
        cout << "List of flights from: " << id << endl;
    }
    while (p != NULL)
    {
        count += 1;
        cout << "    " << id << " to " << p->vertex << " with duration " << p->weight << endl;
        p = p->next;
    }
    cout << "   The number of flights is " << count << endl;
}
