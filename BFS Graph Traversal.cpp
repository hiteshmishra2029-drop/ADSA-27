#include <iostream>
using namespace std;

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int visited[MAX];

// Enqueue function
void enqueue(int vertex)
{
    if (rear == MAX - 1)
    {
        cout << "Queue Overflow\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = vertex;
}

// Dequeue function
int dequeue()
{
    if (front == -1 || front > rear)
        return -1;

    return queue[front++];
}

// BFS function
void BFS(int graph[MAX][MAX], int n, int start)
{
    // Mark starting vertex as visited
    visited[start] = 1;

    // Insert starting vertex into queue
    enqueue(start);

    while (front != -1 && front <= rear)
    {
        int vertex = dequeue();

        cout << vertex << " ";

        // Check all adjacent vertices
        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main()
{
    int n, graph[MAX][MAX];
    int start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "BFS Traversal: ";
    BFS(graph, n, start);

    return 0;
}
