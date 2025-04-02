#include <bits/stdc++.h>
using namespace std;

void topoSortBFS(int n, vector<int> topoOrder,
                 unordered_map<int, list<int>> adjList) {
  queue<int> q;
  unordered_map<int, int> indegree;
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

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
  unordered_map<int, list<int>> adjList;
  for (vector<int> i : prerequisites) {
    int u = i[0];
    int v = i[1];
    adjList[v].push_back(u);
  }

  vector<int> topoSort;
  topoSortBFS(numCourses, topoSort, adjList);
  // valid
  if (topoSort.size() == numCourses) {
    return topoSort;
  } else {
    // invalid
    return {};
  }
}

int main() { return 0; }
