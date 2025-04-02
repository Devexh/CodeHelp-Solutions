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

  void shortestPathBFS(int src, int dest) {
    queue<int> q;
    map<int, bool> visited;
    map<int, int> parent;

    // initial state
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty()) {
      int frontNode = q.front();
      q.pop();

      for (auto nbr : adjList[frontNode]) {
        if (!visited[nbr]) {
          q.push(nbr);
          parent[nbr] = frontNode;
          visited[nbr] = true;
        }
      }
    }
    // parent array taiyaar hoga
    vector<int> ans;
    while (dest != -1) {
      ans.push_back(dest);
      dest = parent[dest];
    }
    reverse(ans.begin(), ans.end());
    // printing the shortest path
    for (auto i : ans) {
      cout << i << " ";
    }
  }
};

int main() {
  Graph g;

  g.addEdge(0, 5, 0);
  g.addEdge(5, 4, 0);
  g.addEdge(4, 3, 0);
  g.addEdge(0, 6, 0);
  g.addEdge(6, 3, 0);
  g.addEdge(0, 1, 0);
  g.addEdge(1, 2, 0);
  g.addEdge(2, 3, 0);

  //   g.printAdjList();
  int src = 0;
  int dest = 3;
  g.shortestPathBFS(src, dest);
  //   g.topoSortBFS(n);

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
