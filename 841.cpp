#include <queue>
#include <vector>
using namespace std;

queue<int> construct_queue_with_vec(const vector<int>& v) {
  queue<int> ret;
  for (const auto& n : v) ret.push(n);
  return ret;
}

class Solution {
  vector<bool> visited;

  void add_keys(queue<int>& keychain, const vector<int>& room) {
    for (const auto& key : room) {
      if (!visited[key]) keychain.push(key);
    }
  }

 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    visited = vector<bool>(rooms.size());
    queue<int> keychain({0});
    while (!keychain.empty()) {
      add_keys(keychain, rooms[keychain.front()]);
      visited[keychain.front()] = true;
      keychain.pop();
    }
    for (const auto& v : visited)
      if (!v) return false;
    return true;
  }
};