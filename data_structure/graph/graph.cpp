#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> createAdjacencyList(vector<vector<int> >& edges, int numVertices)
{
    // Initialize the adjacency list 
    vector<vector<int> > adjList(numVertices);

    // Fill the adjacency list based on the edges in the graph
    for (int i=0; i < edges.size(); i++) {
        int u = edges[i][0];
          int v = edges[i][1];
          // Since the graph is undirected, therefore we push the edges in both the directions
          adjList[u].push_back(v);
          adjList[v].push_back(u);
    }

    return adjList;
}

int main()
{
      // Undirected Graph of 4 nodes
      int numVertices = 4;
      vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 1}};
  
    // Create the adjacency List
    vector<vector<int>> adjList = createAdjacencyList(edges, numVertices);

    // Print the adjacency List
    for (int i = 0; i < numVertices; ++i) {
          cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); ++j) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}