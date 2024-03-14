#include <vector>
using namespace std;

class Solution {
  int fab[46];

 public:
  Solution() {
    fab[0] = fab[1] = 1;
    for (int i = 2; i <= 45; i++) fab[i] = fab[i - 1] + fab[i - 2];
  }
  int climbStairs(int n) { return fab[n]; }
};