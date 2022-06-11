class VertexList
{

public:
    VertexList();
    ~VertexList();

    void addVertex(int weight, int adjacentVertex);
    void print();

    int id;
    int count;

private:
    struct Node
    {
        int vertex;
        int weight;
        Node *next;
    };

    Node *head;
};
