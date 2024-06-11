class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    const unordered_set<int> toBeSorted(arr2.begin(), arr2.end());
    unordered_multiset<int> target_found;
    for (auto& num : arr1) {
      if (toBeSorted.contains(num)) {
        target_found.insert(num);
        num = -1;
      }
    }
    vector<int> ret;
    for (const auto& num : arr2) {
      for (auto times = 0; times < target_found.count(num); times++) {
        ret.emplace_back(num);
      }
    }
    std::sort(arr1.begin(), arr1.end());
    for (const auto& num : arr1) {
      if (num == -1) continue;
      ret.push_back(num);
    }
    return ret;
  }
};
