#include <iostream>
#include <set>
#include <vector>
using namespace std;

int find_parent_and_update(vector<int>& graph, int n) {
  if (graph[n] == -1) return n;
  int ret = n;
  while (graph[ret] != -1 && graph[ret] != ret) ret = graph[ret];
  graph[n] = ret;  // to reduce time of finding
  return ret;
}

void merge_two(vector<int>& graph, int n1, int n2) {
  int p1 = find_parent_and_update(graph, n1),
      p2 = find_parent_and_update(graph, n2);
  graph[p1] = graph[p2] = min(p1, p2);
}

class Solution {
 public:
  bool validPath(int n, vector<vector<int>>& edges, int source,
                 int destination) {
    vector<int> graph(n, -1);
    for (const auto& edge : edges) merge_two(graph, edge[0], edge[1]);

    return find_parent_and_update(graph, source) ==
           find_parent_and_update(graph, destination);
  }
};