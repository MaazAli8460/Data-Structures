#include <iostream>
#include <queue>

using namespace std;

class graph
{
public:
    int V;
    bool **graph1;

    graph(int V)
    {
        this->V = V;
        graph1 = new bool *[V];
        for (int i = 0; i < V; i++)
        {
            graph1[i] = new bool[V];
            for (int j = 0; j < V; j++)
                graph1[i][j] = 0;
        }
    }
    void addEdge(int u, int v)
    {
        graph1[u][v] = 1;
    }
    void display()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << graph1[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    bool isEdge(int u, int v)
    {
        return graph1[u][v];
    }
    bool removeEdge(int u, int v)
    {
        graph1[u][v] = 0;
    }
};

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = -1;
        next = NULL;
    }
    Node(int d)
    {
        data = d;
        next = NULL;
    }
    Node(Node *d)
    {
        data = d->data;
        next = NULL;
    }
};

// Adjacency List: // it’s a linked list class called adjlist

class AdjList
{
public:
    Node *head;
    AdjList()
    {
        head = NULL;
    }
    void Insert(Node *NewNode)
    {
        Node *temp = new Node(NewNode);
        if (head == NULL)
        {
            head = temp;
            temp = NULL;
            /* code */
        }
        else
        {
            Node *last = head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = temp;
            temp = NULL;
        }
    }
    void Display()
    {
        Node *last = head;
        while (last != NULL)
        {
            cout << last->data;
            if (last->next!=NULL)
            {
                cout<<"->";
                /* code */
            }
            
            last = last->next;
        }
        cout<<"\n";
    }
};

// Graph:

class Graph
{
public:
    int maxVertices;  // max no of vertices in your graph
    int noOfVertices; // initially 0, increments with every call to createVertex
    AdjList *list = NULL;

    // function. So basically its kind of counter

    Graph(int maxVertices1)
    {
        maxVertices = maxVertices1;
        list = new AdjList[maxVertices];
        for (int i = 0; i < maxVertices; i++)
        {
            Node *temp = new Node(i + 1);
            list[i].Insert(temp);
            temp = NULL;
            noOfVertices++;
        }
        // noOfVertices = 0;
    }
    
    void insertEdge(int src, int dest)
    {
        for (int i = 0; i < maxVertices; i++)
        {
            if (list[i].head->data == src)
            {
                Node *temp = new Node(dest);
                list[i].Insert(temp);
                break;
            }
        }

        // Graph* temp=
    }
    
    void Graphdisplay()
    {
        for (int i = 0; i < maxVertices; i++)
        {
            
            list[i].Display();
            
        }
    }
    bool isConnected()
    {
        queue<int> visited;
        int last=0;
        int var;
        for (int i = 0; i < maxVertices; i++)
        {
            Node *temp=list[i].head;
            if (temp->next==NULL )
            {
                return false;
            }
            var=visited.front();
            if (var==last && i+1<maxVertices)
            {
                return false;
            }
            while (temp!=NULL)
            {
                visited.push(temp->data);
                last=temp->data;
                temp = temp->next;
            }
            
        }
        var=visited.front();
        if (var==last)
        {
            return true;
        }
        return false;
    }
};