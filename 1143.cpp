#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    const int l1 = text1.size(), l2 = text2.size(), MAX_ARR_SIZE = 1001;
    int dp[MAX_ARR_SIZE][MAX_ARR_SIZE];
    for (int i = 0; i < MAX_ARR_SIZE; i++) dp[0][i] = dp[i][0] = 0;
    for (int i = 0; i < l1; i++)
      for (int j = 0; j < l2; j++)
        if (text1[i] == text2[j])
          dp[i + 1][j + 1] = dp[i][j] + 1;
        else
          dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    return dp[l1][l2];
  }
};