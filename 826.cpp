class Solution {
 public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                          vector<int>& worker) {
    std::sort(worker.begin(), worker.end());
    vector<int> indices(difficulty.size());
    for (auto i = 0; i < indices.size(); i++) {
      indices[i] = i;
    }
    std::sort(indices.begin(), indices.end(),
              [&profit](int a, int b) { return profit[a] < profit[b]; });
    vector<int> sortedDiff(indices.size());
    vector<int> sortedProf(indices.size());
    for (auto i = 0; i < indices.size(); i++) {
      sortedDiff[i] = difficulty[indices[i]];
      sortedProf[i] = profit[indices[i]];
    }
    for (auto i = 0; i < sortedDiff.size() - 1; i++) {
      if (sortedDiff[i] >= sortedDiff[i + 1]) {
        sortedDiff.erase(sortedDiff.begin() + i);
        sortedProf.erase(sortedProf.begin() + i);
        i = max(i - 2, 0);
      }
    }
    auto sum = 0;
    auto curIndex = 0;
    for (auto i = 0; i < worker.size(); i++) {
      while (curIndex + 1 < sortedDiff.size() &&
             worker[i] >= sortedDiff[curIndex + 1]) {
        curIndex++;
      }
      if (worker[i] >= sortedDiff[curIndex]) {
        sum += sortedProf[curIndex];
      }
    }
    return sum;
  }
};
