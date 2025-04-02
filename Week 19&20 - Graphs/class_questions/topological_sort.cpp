#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
  unordered_map<int, list<int>> adjList;

  void addEdge(int u, int v, bool direction) {
    if (direction == 1) {
      adjList[u].push_back(v);
    } else {
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
  }

  void printAdjList() {
    for (auto i : adjList) {
      cout << i.first << ": {";
      for (auto j : i.second) {
        cout << j << ",";
      }
      cout << "}" << endl;
    }
  }

  void topoSortDFS(int src, map<int, bool> &visited, stack<int> &st) {
    visited[src] = true;

    for (auto nbr : adjList[src]) {
      if (!visited[nbr]) {
        topoSortDFS(nbr, visited, st);
      }
    }
    st.push(src);
  }

  void topoSortBFS(int n) {
    queue<int> q;
    map<int, int> indegree;
    // initialise kardi indegree
    for (auto i : adjList) {
      for (auto nbr : i.second) {
        indegree[nbr]++;
      }
    }
    // push all zero indegree wali node to queue
    for (int node = 0; node < n; node++) {
      if (indegree[node] == 0) {
        q.push(node);
      }
    }
    // BFS chalate hai
    while (!q.empty()) {
      int frontNode = q.front();
      q.pop();
      cout << frontNode << ", ";

      for (auto nbr : adjList[frontNode]) {
        indegree[nbr]--;

        // check for zero
        if (indegree[nbr] == 0) {
          q.push(nbr);
        }
      }
    }
  }
};

int main() {
  Graph g;

  g.addEdge(0, 1, 1);
  g.addEdge(1, 2, 1);
  g.addEdge(2, 3, 1);
  g.addEdge(2, 4, 1);
  g.addEdge(3, 5, 1);
  g.addEdge(4, 5, 1);
  g.addEdge(5, 6, 1);
  g.addEdge(5, 7, 1);

  g.printAdjList();
  int n = 8;
  g.topoSortBFS(n);

  //   int n = 8;

  //   map<int, bool> visited;
  //   stack<int> st;
  //   for (int node = 0; node < n; node++) {
  //     if (!visited[node]) {
  //       g.topoSortDFS(node, visited, st);
  //     }
  //   }
  //   cout << "Printing ht topo order: " << endl;
  //   while (!st.empty()) {
  //     cout << st.top() << " ";
  //     st.pop();
  //   }

  return 0;
}
