#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
  unordered_map<int, list<int>> adjList;
  void addEdge(int u, int v, bool direction) {
    // direction -> 0 -> undirected
    // direction -> 1 -> directed
    if (direction == 1) {
      // u se v ki taraf ek edge hai
      // u -> v
      adjList[u].push_back(v);
    } else {
      // direction = 0;
      // u -- v
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    cout << endl << "Printing AdjList: " << endl;
    printAdjList();
    cout << endl;
  }

  void printAdjList() {
    for (auto i : adjList) {
      cout << i.first << "-> {";
      for (auto neighbour : i.second) {
        cout << neighbour << ", ";
      }
      cout << "}" << endl;
    }
  }

  bool checkCycleUndirectedBFS(int src) {
    queue<int> q;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    // initial state
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty()) {
      int frontNode = q.front();
      q.pop();

      for (auto nbr : adjList[frontNode]) {
        if (nbr == parent[frontNode]) {
          continue;
        }
        if (!visited[nbr]) {
          q.push(nbr);
          visited[nbr] = true;
          parent[nbr] = frontNode;
        } else if (visited[nbr] == true) {
          // cycle present
          return true;
        }
      }
    }
    return false;
  }
};

//! DFS for directed Graphs
bool checkCyclic(int src, unordered_map<int, bool> &vis,
                 unordered_map<int, bool> &dfsTrack, vector<int> adj[]) {
  vis[src] = true;
  dfsTrack[src] = true;

  for (auto nbr : adj[src]) {
    if (!vis[nbr]) {
      bool ans = checkCyclic(nbr, vis, dfsTrack, adj);
      if (ans == true) {
        return true;
      }
    }
    if (vis[nbr] == 1 && dfsTrack[nbr] == 1) {
      // cycle present
      return true;
    }
  }

  // backtrack
  dfsTrack[src] = false;
  return false;
}

bool isCyclic(int V, vector<int> adj[]) {
  unordered_map<int, bool> vis;
  unordered_map<int, bool> dfsTrack;

  for (int node = 0; node <= V; node++) {
    if (!vis[node]) {
      bool isCyclic = checkCyclic(node, vis, dfsTrack, adj);
      if (isCyclic) {
        return true;
      }
    }
  }
  return false;
}

int main() {

  Graph g;

  g.addEdge(0, 1, 0);
  g.addEdge(1, 2, 0);
  g.addEdge(1, 3, 0);
  g.addEdge(2, 4, 0);
  g.addEdge(3, 4, 0);
  g.addEdge(2, 5, 0);

  int src = 0;

  bool isCyclic = g.checkCycleUndirectedBFS(src);
  if (isCyclic) {
    cout << "Cycle present" << endl;
  } else {
    cout << "Cycle absent" << endl;
  }

  //   g.addEdge('a', 'b', 0);
  //   g.addEdge('a', 'c', 0);
  //   g.addEdge('c', 'd', 0);
  //   g.addEdge('c', 'e', 0);
  //   g.addEdge('d', 'e', 0);
  //   g.addEdge('e', 'f', 0);

  return 0;
}
