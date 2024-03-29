// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    long long hi = n, lo = 1, mid = (hi + lo) / 2;
    for (; !(isBadVersion(mid) && !isBadVersion(mid - 1)); mid = (hi + lo) / 2)
      if (isBadVersion(mid))
        hi = mid;
      else
        lo = mid + 1;
    return mid;
  }
};
