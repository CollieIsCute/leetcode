/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

#include <vector>
using namespace std;

class MyQueue {
  vector<int> stk, stk_inv;

 public:
  MyQueue() {}

  void push(int x) { stk.push_back(x); }

  int pop() {
    peek();
    int ret = stk_inv.back();
    stk_inv.pop_back();
    return ret;
  }

  int peek() {
    if (stk_inv.empty()) {
      while (!stk.empty()) {
        stk_inv.push_back(stk.back());
        stk.pop_back();
      }
      stk.clear();
    }
    return stk_inv.back();
  }

  bool empty() { return !(stk.size() + stk_inv.size()); }
};