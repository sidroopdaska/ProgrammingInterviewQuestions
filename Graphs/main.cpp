//
//  main.cpp
//  Graphs
//
//  Created by Siddharth Sharma on 03/12/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <list>
#include <queue>
#include <unordered_map>
#include <stack>

#define INF INT_MAX
// adjcency list
using namespace std;

typedef struct Node{
    int dest;
    Node *next;
}Node;

Node* createNewNode(int dest){
    Node *new_node = new Node;
    new_node->dest = dest;
    new_node->next = nullptr;
    return new_node;
}

typedef struct List{
    Node *start;
}List;

typedef struct Graph{
    List *adjList;
}Graph;

Graph* createNewGraph(int vertices){
    Graph *graph = new Graph;
    graph->adjList = new List[vertices];
    
    for(int i = 0; i < vertices; i++){
        graph->adjList[i].start = nullptr;
    }
    return graph;
}

void addEdge(Graph *g, int source, int dest){
    Node *new_node = createNewNode(dest);
    
    if (g->adjList[source].start == nullptr){
        g->adjList[source].start = new_node;
    } else{
        new_node->next = g->adjList[source].start;
        g->adjList[source].start = new_node;
    }
    
    new_node = createNewNode(source);
    if (g->adjList[dest].start == nullptr){
         g->adjList[dest].start = new_node;
    } else{
        new_node->next = g->adjList[dest].start;
        g->adjList[dest].start = new_node;
    }
}

void printEdgeForVertex(Graph *g, int vertices){
    for(int i = 0; i < vertices; i++){
        cout << "adjacent vertices for " <<i << " = " ;
        Node *current = g->adjList[i].start;
        while (current != nullptr) {
            cout <<current->dest << " ";
            current = current->next;
        }
        cout<< endl;
    }
}

// adjacency matrix

class adjMatrix{
    private:
        int **a;
        int vertices;
    public:
        adjMatrix(int vertices){
            this->vertices  = vertices;
            a = new int*[vertices];
            for(int i = 0 ; i < vertices; i++){
                a[i] = new int[vertices]();
            }
        }
        void addEdge(int i, int j){
            if((i >= 0 && i < vertices) && (j >= 0 && j < vertices)){
                a[i][j] = 1;
                a[j][i] = 1;
            } else
                return;
        }
        int isEdge(int i , int j){
            if((i >= 0 && i < vertices) && (j >= 0 && j < vertices)){
                return a[i][j];
            } else
                return 0;
        }
    
    void removeEdge(int i, int j){
        if((i >= 0 && i < vertices) && (j >= 0 && j < vertices)){
            a[i][j] = 0;
            a[j][i] = 0;
        } else
            return ;
    }
    
    ~adjMatrix(){
        for(int i =0; i< vertices; i++){
            delete[] a[i];
        }
        
        delete[] a;
        
    }
};

class adjList{
private:
    list<int> *array;
    int vertices;
public:
    adjList(int vertices){
        this->vertices = vertices;
        array = new list<int>[vertices];
    }
    
    void addEdge(int source, int destination){
        if(source >= 0 && source< vertices && destination >=0 && destination < vertices){
            array[source].push_back(destination);
            //array[destination].push_back(source);
        } else {
            return;
        }
    }
    
    void BFS(int source){
        if (source < 0 || source >vertices){
            return;
        }
        unordered_map<int, int> parent;
        unordered_map<int, int> level;
        parent[source] = 0;
        level[source] = 0;
        int i = 1;
        queue<int> q;
        q.push(source);
        cout << source  << endl;
        while(!q.empty()){
            int currentVertex = q.front();
            q.pop();
            list<int>::iterator itr;
            for( itr = array[currentVertex].begin(); itr != array[currentVertex].end(); itr++){
                if(!level.count(*itr)){
                    cout << *itr << " ";
                    parent[*itr] = currentVertex;
                    level[*itr] = i;
                    q.push(*itr);
                }
            }
            i+=1;
            cout << endl;
        }
    }
    
    void DFS_Visit(int source, unordered_map<int, int>& parent){
        
        list<int>:: iterator itr;
        
        cout << source << " ";
        for (itr = array[source].begin(); itr!= array[source].end(); itr++) {
            if(!parent.count(*itr)){
                parent[*itr] = source;
                DFS_Visit(*itr, parent);
            }
        }
    }
    
    void DFS(){
        unordered_map<int, int> parent;
        bool *recStack = new bool[vertices];
        for(int i = 0; i < vertices; i++){
            recStack[i] = false;
        }
        
        for (int i = 0 ; i < vertices; i++) {
            if(!parent.count(i)){
                parent[i] = INT_MIN;
                DFS_Visit(i, parent);
            }
        }
    }
    
    bool isCyclic_DFS_Visit(int source, unordered_map<int, int>& parent, bool recStack[]){
        
        list<int>:: iterator itr;
        for(itr = array[source].begin(); itr != array[source].end(); itr++){
            if(!parent.count(*itr)){
                parent[*itr] = source;
                recStack[*itr] = true;
                if(isCyclic_DFS_Visit(*itr, parent, recStack))
                    return true;
            } else {
                if(recStack[*itr])
                    return true;
            }
        }
        recStack[source] = false;
        return false;
    }
    
    bool isCyclic(){
        unordered_map<int, int> parent;
        bool *recStack = new bool[vertices];
        
        for(int i = 0; i < vertices; i++){
            recStack[i] = false;
        }
        
        for (int i = 0 ; i < 1; i++) {
            if(!parent.count(i)){
                recStack[i] = true;
                parent[i] = -1;
                if(isCyclic_DFS_Visit(i, parent, recStack))
                    return true;
            }
        }
        return false;
    }
    
    bool isCyclicUnDirectedDFS_Visit(int source, unordered_map<int, int>& parent){
        list<int>::iterator itr;
        for(itr = array[source].begin(); itr != array[source].end(); itr++){
            if(!parent.count(*itr)){
                parent[*itr] = source;
                if(isCyclicUnDirectedDFS_Visit(*itr, parent))
                    return true;
            } else {
                if(*itr != parent[source])
                    return true;
            }
        }
        return false;
    }
    
    bool isCyclicUnDirected(){
        unordered_map<int, int> parent;
        for(int i =0; i < vertices; i++){
            if(!parent.count(i)){
                parent[i] = -1;
                if(isCyclicUnDirectedDFS_Visit(i, parent))
                    return true;
            }
        }
        return false;
    }
    
    void topologicalDFSVisit(int source, bool visited[], stack<int>& s){
        
        list<int>::iterator itr;
        for(itr = array[source].begin(); itr != array[source].end(); itr++){
            if(!visited[*itr]){
                visited[*itr] = true;
                topologicalDFSVisit(*itr, visited, s);
            }
        }
        s.push(source);
    }
    
    void topologicalSort(){
        bool *visited = new bool[vertices];
        stack<int> s;
        
        for(int i = 0; i < vertices; i++){
            visited[i] = false;
        }
        
        for(int i = 0; i < vertices; i++){
            if(!visited[i]){
                visited[i] = true;
                topologicalDFSVisit(i, visited, s);
            }
        }
        
        cout << "priting" << endl;
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

// Graph is represented using adjacency list. Every node of adjacency list
// contains vertex number of the vertex to which edge connects. It also
// contains weight of the edge
class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};

// Class to represent a graph using adjacency list representation
class Graph1
{
    int V;    // No. of vertices'
    
    // Pointer to an array containing adjacency lists
    list<AdjListNode> *adj;
    
    // A function used by shortestPath
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph1(int V);   // Constructor
    
    // function to add an edge to graph
    void addEdge(int u, int v, int weight);
    
    // Finds shortest paths from given source vertex
    void shortestPath(int s);
};

Graph1::Graph1(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

void Graph1::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node); // Add v to u's list
}


void Graph1::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited
    visited[v] = true;
    
    // Recur for all the vertices adjacent to this vertex
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
    
    // Push current vertex to stack which stores topological sort
    Stack.push(v);
}

// The function to find shortest paths from given vertex. It uses recursive
// topologicalSortUtil() to get topological sorting of given graph.
void Graph1::shortestPath(int s)
{
    stack<int> Stack;
    int dist[V];
    
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
    
    // Initialize distances to all vertices as infinite and distance
    // to source as 0
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[s] = 0;
    
    // Process vertices in topological order
    while (Stack.empty() == false)
    {
        // Get the next vertex from topological order
        int u = Stack.top();
        Stack.pop();
        
        // Update distances of all adjacent vertices
        list<AdjListNode>::iterator i;
        if (dist[u] != INF)
        {
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
                if (dist[i->getV()] > dist[u] + i->getWeight())
                    dist[i->getV()] = dist[u] + i->getWeight();
        }
    }
    
    // Print the calculated shortest distances
    for (int i = 0; i < V; i++)
        (dist[i] == INF)? cout << "INF ": cout << dist[i] << " ";
}

// A C / C++ program for Bellman-Ford's single source
// shortest path algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
    
    // graph is represented as an array of edges.
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph =
    (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
    
    graph->edge =
    (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
    
    return graph;
}

// A utility function used to print the solution
void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm.  The function
// also detects negative weight cycle
void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    
    // Step 1: Initialize distances from src to all other vertices
    // as INFINITE
    for (int i = 0; i < V; i++)
        dist[i]   = INT_MAX;
    dist[src] = 0;
    
    // Step 2: Relax all edges |V| - 1 times. A simple shortest
    // path from src to any other vertex can have at-most |V| - 1
    // edges
    for (int i = 1; i <= V-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    
    // Step 3: check for negative-weight cycles.  The above step
    // guarantees shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }
    
    printArr(dist, V);
    
    return;
}
// instead of the unorderd_map, i could have an array called visited, pass it all the time. and initial haev a for loop that sets all tehvalues to false.

//REMEMBER to change the addEdge fuction when using....
int main(int argc, const char * argv[]) {
    
    adjList a(5);
    a.addEdge(0, 1);
    a.addEdge(0,2);
    a.addEdge(1,3);
    a.addEdge(2,3);
    a.addEdge(3,4);
    a.topologicalSort();
    
//    a.addEdge(1, 2);
//    a.addEdge(2, 1);
//
//    a.isCyclicUnDirected() ? cout << "true" : cout << "false";
    
    
//    a.addEdge(0, 1);
//    a.addEdge(1, 2);
//    a.addEdge(2, 3);
//    a.addEdge(3, 1);
//    a.addEdge(0, 4);
//    a.addEdge(5, 4);
//    a.addEdge(5, 3);
//    
//    a.DFS();
//    Graph *graph;
//    graph = createNewGraph(4);
//    addEdge(graph, 0, 1);
//    addEdge(graph, 0, 2);
//    addEdge(graph, 1, 3);
//    
//    printEdgeForVertex(graph, 4);

    return 0;
}
