#include <queue>
#include <utility>
using namespace std;

class MedianFinder {
  priority_queue<int> max;
  priority_queue<int, vector<int>, std::greater<int>> min;

 public:
  MedianFinder() {}

  void addNum(int num) {
    max.push(num);
    min.push(move(max.top()));
    max.pop();
    while (min.size() > max.size() + 1) {
      max.push(move(min.top()));
      min.pop();
    }
  }

  double findMedian() {
    if (min.size() > max.size()) return min.top();
    return ((double)max.top() + min.top()) / 2.0;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */