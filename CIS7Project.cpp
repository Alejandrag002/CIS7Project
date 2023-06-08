#include <bits/stdc++.h>
using namespace std;

//user can choose
//choice1: possible routes
//choice2: shortest path
//choice3: adjacencies
//choice4: matrix

//1riverside
//2morenovalley
//3hemet
//4perris

// 1 riverside to 3 hemet = 33
// 1 riverside to 2 moreno = 16
// 1 riverside to 4 perris = 24
// 3 hemet to 4 perris = 30
// 3 hemet to 2 moreno = 26
// 4 perris to 2 moreno = 18

//for choice2 and choice3
//a utility function to add an edge in an undirected graph
//Ex1CIS7Lab10
void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

//for choice3
//A utility funciton to print the adjacent list represent of graph 
//Ex1CIS7Lab10
void printGraph(vector<int> adj[], int V)
{
  for (int v = 1; v < V; ++v)
    {
      cout << "\n The shortest round trip is: " << v;
      for (auto x: adj[v])
        cout << " -> " << x;
      printf("\n");
    }
}
//for choice2
//A utility funciton to print the adjacent list represent of graph 
void printGraph1(vector<int> adj[], int V)
{
  for (int v = 1; v < V; ++v)
    {
      cout << "\n The conections to the other cities: " << v;
      for (auto x: adj[v])
        cout << " -> " << x;
      printf("\n");
    }
}

//Data structure to store Adjacency list nodes
//Ex2CIS7Lab10
struct Node 
{
  int value;
  int cost;
  Node* next;
};

//Data structure to store graph edges
//Ex2CIS7Lab10
struct Edge
{
  int source;
  int destination;
  int weight;
};

//Ex2CIS7Lab10
class Graph
{
  // Function to allocate new node of Adjacency List
  Node* getAdjListNode(int value, int weight, Node* head)
  {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->cost = weight;
    // point new node to current head
    newNode->next = head;

    return newNode;
  }
  int N; //nodes in graph

public:
//an array of pointers to Node to represent adjacency list
Node **head;
//Constructor
Graph(Edge edges[], int n, int N)
{
  //allocate memory
  head = new Node* [N]();
  this->N = N;
  //initialize head pointer for all vertices
  for (int i = 0; i < N; i++)
    {
  head[i] = nullptr;
    } 
  //add edges to the directed graph
  for (unsigned i = 0; i < n; i++)
    {
      int source = edges[i].source;
      int destination = edges[i].destination;
      int weight = edges[i].weight;
      //insert in the beginning
      Node* newNode = getAdjListNode(destination, weight, head[source]);
      //point head pointer to new node
      head[source] = newNode;

      //makes the graph undirected
      newNode = getAdjListNode(source, weight, head[destination]);
      head[destination] = newNode;
    }
}
//destructor
//Ex2CIS7Lab10
Graph()
{
  for (int i = 0; i < N; i++)
    delete[] head[i];

    delete[] head;
}
};
//choice2
//print all neighboring vertices of given vertex
//Ex2CIS7Lab10
void printList(Node* ptr)
{
  while (ptr != nullptr)
    {
      cout << " -> " << ptr -> value <<"";
      ptr = ptr ->next;
    }
  cout << endl;
}

//for choice4
//Ex2CIS7Lab10
void printList (Node* ptr, int i)
{
  while (ptr != nullptr)
    {
      cout << "(" << i << ", " << ptr -> value
        << ", " << ptr->cost << "miles) ";

      ptr = ptr->next;
    }
  cout << endl;
}

//driver code
int main ()
{
  int userchoice;
  
  cout << "Hi! Welcome to Inland Empire Solar Sales Travel Program!, select an option form below " << endl;
  cout << "Option 1: Possible Routes " << endl;
  cout << "Option 2: Shortest Path " << endl;
  cout << "Option 3: Adjacencies " << endl;
  cout << "Option 4: Matrix " << endl;
  cin >> userchoice;
  
//if for choice1
    if(userchoice == 1)
  {
    cout << "The possible routes are: 1.Riverside, 2.Moreno, 3.Hemet, 4.Perris " << endl;
    //array of graph edges as per above diagram.
    //Ex2CIS7Lab10
    Edge edges[] = 
    {
      //pair (x, y) represents edge from x to y
      {1,2}, {1,3},{1,4},{3,4},{3,2},{4,2}
    };
    
    //number of vertices in the graph
    int N = 5;
    //calculate number of edges
    int n = sizeof(edges)/sizeof(edges[0]);
    //construct graph
    Graph graph(edges, n, N);
    //print adjacency list representation of graph
    for (int i = 1; i < N; i++)
      {
        //print given vertex
        cout << i << "--";
        //print all its neighboring vertices
        printList(graph.head[i]);
      }
    cin >> userchoice;
  }

  //if choice2
  //Ex1CIS7Lab10
  if (userchoice == 2)
  {
    cout << "The Locations are: " << endl;
    cout << "1.Riverside, 2.Moreno = 32 Miles, 3.Hemet = 66 Miles, 4.Perris = 48 Miles " << endl;
    //Ex1CIS7Lab10
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 2);
    printGraph1(adj, V);
    cin >> userchoice;
  }

  //if userchoice3
  //Ex1CIS7Lab10
  if (userchoice == 3)
  {
    cout << "1.Riverside, 2.Moreno, 3.Hemet, 4.Perris " << endl;
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 2);
    printGraph(adj, V);
    cin >> userchoice;

  }
  
  //is userchoice4
  //Ex3CIS7Lab10
  if (userchoice == 4)
  {
    cout << "The Cities are: " << endl << "1.Riverside, 2.Moreno, 3.Hemet, 4.Perris" << endl;
    //array of graph edges as per above diagram.
    Edge edges[] =
    {
        //(x, y, w) -> edge from x to y having weight w
        { 1, 2, 16 }, { 1, 3, 33 }, { 1, 4, 24 }, { 2, 3, 26 },
        { 3, 4, 30 }, { 4, 2, 18 }
    };

    //number of vertices in the graph
    int N = 5;

    //calculate the number of edges
    int n = sizeof(edges)/sizeof(edges[0]);
    //construct graph
    Graph graph(edges, n, N);
    //print adjacency list representation of graph
    for (int i = 1; i < N; i++)
    {
        //print all neighboring vertices of vertex i
        printList(graph.head[i], i);
    }
    cin >> userchoice;
  }
  

 //invalid userinput
    if (userchoice <=0 || userchoice >=5)
  {
    cout << "input invalid, please choose 1-4." << endl;
    cin >> userchoice;
  }
      return 0;
}
