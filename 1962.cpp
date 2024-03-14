#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int minStoneSum(vector<int>& piles, int k) {
    auto my_cmp = [](const int& a, const int& b) { return a < b; };
    priority_queue<int, vector<int>, decltype(my_cmp)> remove_piles(my_cmp,
                                                                    piles);
    for (int i = 0; i < k; ++i, remove_piles.pop()) {
      int biggest = remove_piles.top();
      biggest -= biggest / 2;
      remove_piles.push(biggest);
    }
    int sum = 0;
    for (; !remove_piles.empty(); remove_piles.pop()) sum += remove_piles.top();
    return sum;
  }
};