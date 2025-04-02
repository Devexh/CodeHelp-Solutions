#include <bits/stdc++.h>
using namespace std;

// directed and weighted graph
class Graph {
public:
  unordered_map<int, list<pair<int, int>>> adj;

  void addEdge(int u, int v, int wt, bool direction) {
    if (direction == 1) {
      adj[u].push_back({v, wt});
    } else {
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }
  }

  void printAdjList() {
    for (auto i : adj) {
      cout << i.first << ": { ";
      for (auto j : i.second) {
        cout << "(" << j.first << ", " << j.second << "), ";
      }
      cout << "} " << endl;
    }
  }

  void topoOrderDFS(int src, stack<int> &topo,
                    unordered_map<int, bool> &visited) {
    visited[src] = true;

    for (auto nbrPair : adj[src]) {
      int nbrNode = nbrPair.first;
      //   int nbrDist = nbrPair.second;
      if (!visited[nbrNode]) {
        topoOrderDFS(nbrNode, topo, visited);
      }
    }
    topo.push(src);
  }

  void shortestPathDFS(stack<int> &topo, int n) {
    vector<int> dist(n, INT_MAX);
    // initially, maintain src
    int src = topo.top();
    topo.pop();
    dist[src] = 0;

    // update nbr distance for this src node
    for (auto nbrPair : adj[src]) {
      int nbrNode = nbrPair.first;
      int nbrDist = nbrPair.second;
      if (dist[src] + nbrDist < dist[nbrNode]) {
        dist[nbrNode] = dist[src] + nbrDist;
      }
    }
    // apply the same above concept for all the remaining node in the topo
    // ordering
    while (!topo.empty()) {
      int src = topo.top();
      topo.pop();

      for (auto nbrPair : adj[src]) {
        int nbrNode = nbrPair.first;
        int nbrDist = nbrPair.second;
        if (dist[src] + nbrDist < dist[nbrNode]) {
          dist[nbrNode] = dist[src] + nbrDist;
        }
      }
    }
    // ab mera distance array ikdam taiyaar hai
    cout << "Printing the distance array: " << endl;
    for (auto i : dist) {
      cout << i << " ";
    }
  }

  void dijkstraShortestDistance(int n, int src, int dest) {
    vector<int> dist(n + 1, INT_MAX);
    set<pair<int, int>> st;

    // Initial State -> (0, src)
    st.insert({0, src});
    dist[src] = 0;

    while (!st.empty()) {
      auto topElement = st.begin();
      pair<int, int> topPair = *topElement;
      int topDist = topPair.first;
      int topNode = topPair.second;
      // remove the topNode
      st.erase(st.begin());
      // update distance of nbr
      for (pair<int, int> nbrPair : adj[topNode]) {
        int nbrNode = nbrPair.first;
        int nbrDist = nbrPair.second;
        if (topDist + nbrDist < dist[nbrNode]) {
          // found a new shorter distance
          auto previousEntry = st.find({dist[nbrNode], nbrNode});
          if (previousEntry != st.end()) {
            // entry present in set
            st.erase(previousEntry);
          }
          // dist ka array
          dist[nbrNode] = topDist + nbrDist;
          st.insert({dist[nbrNode], nbrNode});
        }
      }
    }
    cout << "Shortest Distance from " << src << " Node to " << dest
         << " Node: " << dist[dest] << endl;
  }
};

int main() {
  Graph g;

  g.addEdge(1, 6, 14, 0);
  g.addEdge(1, 3, 9, 0);
  g.addEdge(1, 2, 7, 0);
  g.addEdge(2, 3, 10, 0);
  g.addEdge(2, 4, 15, 0);
  g.addEdge(3, 4, 11, 0);
  g.addEdge(6, 3, 2, 0);
  g.addEdge(6, 5, 9, 0);
  g.addEdge(5, 4, 6, 0);

  //   g.printAdjList();
  //   int src = 0;
  //   stack<int> topo;
  //   unordered_map<int, bool> visited;
  //   g.topoOrderDFS(src, topo, visited);
  //   int n = 5;
  //   g.shortestPathDFS(topo, n);
  int n = 6;
  int src = 6;
  int dest = 4;
  g.dijkstraShortestDistance(n, src, dest);

  return 0;
}